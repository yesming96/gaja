/**
 * @file car.cpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @date 2023-09-30
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */

#include "../../../include/module/system_model/kinematic_bicycle.hpp"
namespace gaja {

bool KinematicBicycle::init() {
  spdlog::info("system model: Car is ready");
  system_.join();
  is_initialize_ = true;
  simulation_time_.reset();
  double velocity = 0.0;
  bicycle_model_param_ = parameter_board_.get_bicycle_model_param();

  wheel_base_ = bicycle_model_param_.l_f + bicycle_model_param_.l_r;
  max_steer_angle_ = bicycle_model_param_.max_steer_angle;
  max_velocity_ = bicycle_model_param_.max_velocity;

  // re-define
  time_step_ = 10ms;  // ms

  system_.create(std::bind(&KinematicBicycle::run_model, this), time_step_);
  set_status(Status::IDLE);
  return true;
}

void KinematicBicycle::run_model() {
  if (get_status() != Status::RUN) {
    return;
  }
  ControlInput control_inputs = state_board_.get_control_input();
  Pose ego_pose = state_board_.get_pose();
  double steer_angle = state_board_.get_steering_angle();
  double acceleration = state_board_.get_acceleration();
  double vx = state_board_.get_velocity();
  double Lf = parameter_board_.get_bicycle_model_param().l_f;
  double Lr = parameter_board_.get_bicycle_model_param().l_r;
  double Cf = parameter_board_.get_bicycle_model_param().c_f;
  double Cr = parameter_board_.get_bicycle_model_param().c_r;

  steer_angle = std::clamp(steer_angle, -max_steer_angle_, max_steer_angle_);

  // Update state
  ego_pose.x += vx_ * std::cos(yaw) * dt - vy * std::sin(yaw) * dt;
  ego_pose.y += vx_ * std::sin(yaw) * dt + vy * std::cos(yaw) * dt;
  yaw += omega * dt;
  yaw = normalize_angle(yaw);  // Assuming normalize_angle is defined elsewhere

  // Calculate forces
  double Ffy = -Cf * std::atan2(((vy + Lf * omega) / vx - steer_angle), 1.0);
  double Fry = -Cr * std::atan2((vy - Lr * omega) / vx, 1.0);
  double R_x = c_r1 * vx;
  double F_aero = c_a * std::pow(vx, 2);
  double F_load = F_aero + R_x;

  // Update velocities
  vx_ += (acceleration - Ffy * std::sin(steer_angle) / m - F_load / m + vy * omega) * dt;
  vy += (Fry / m + Ffy * std::cos(steer_angle) / m - vx * omega) * dt;
  omega += (Ffy * Lf * std::cos(steer_angle) - Fry * Lr) / Iz * dt;
}

void KinematicBicycle::run() {
  const Status status = get_status();
  if (status == Status::IDLE) {
  } else if (status == Status::NONE) {
    spdlog::error("The status of Bicycle model is None.");
    spdlog::error("Please Initialize first.");
    return;
  } else if (status == Status::PAUSE) {
    spdlog::error("The status of Bicycle model is PAUSE. Please RESUME");
    return;
  } else if (status == Status::RUN) {
    spdlog::warn("The status of Bicycle model is already RUN");
  } else if (status == Status::STOP) {
    spdlog::warn("The status of Bicycle model is STOP");
  }
  set_status(Status::RUN);
  spdlog::info("system model: Car is running");
}

void KinematicBicycle::resume() {
  set_status(Status::RUN);
  spdlog::info("simulation status is RESUME to RUN");
}
void KinematicBicycle::pause() {
  set_status(Status::PAUSE);
  spdlog::info("simulation status is paused");
}
void KinematicBicycle::exit() {
  spdlog::info("total simulation time: {:.2f} sec", simulation_time_.elapsed_ms() * 1e3);
  set_status(Status::STOP);
  system_.join();
}
void KinematicBicycle::show_current_time() {
  spdlog::info("current simulation time: {:.2f} sec", simulation_time_.elapsed_ms() * 1e3);
}

void KinematicBicycle::set_status(const Status& status) {
  std::unique_lock<std::shared_mutex> wlock(status_mutex_);
  status_ = status;
}
SystemModelInterface::Status KinematicBicycle::get_status() {
  return status_;
}

}  // namespace gaja
