/**
 * @file car.cpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @date 2023-09-30
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */

#include "../../../include/module/system_model/bicycle.hpp"
namespace gaja {

bool Bicycle::init() {
  spdlog::info("system model: Car is ready");
  system_.join();
  is_initialize_ = true;
  simulation_time_.reset();
  set_status(Status::INIT);
  double velocity = 0.0;
  bicycle_model_param_ = data_board_.get_bicycle_model_param();
  // A_ = Eigen::Matrix4d::Zero(4, 4);
  // A_(1, 3) = 1;
  // A_(2, 2) = (bicycle_model_param_.c_f + bicycle_model_param_.c_r) / (bicycle_model_param_.mass * velocity);
  // A_(2, 3) = (bicycle_model_param_.a * bicycle_model_param_.c_f - bicycle_model_param_.b * bicycle_model_param_.c_r)
  // /
  //                (bicycle_model_param_.mass * velocity * velocity) -
  //            1.0;
  // A_(3, 2) = (bicycle_model_param_.a * bicycle_model_param_.c_f - bicycle_model_param_.b * bicycle_model_param_.c_r)
  // /
  //            (bicycle_model_param_.i_z);
  // A_(3, 3) = (std::pow(bicycle_model_param_.a, 2) * bicycle_model_param_.c_f +
  //             std::pow(bicycle_model_param_.b, 2) * bicycle_model_param_.c_r) /
  //            (bicycle_model_param_.i_z * velocity);

  // TODO: velocity가 0이면 inf인 요소가 있음
  return true;
}
void Bicycle::run() {
  Status status = get_status();
  if (status != Status::INIT) {
    spdlog::error("The status of Bicycle model is not INIT.");
    spdlog::error("Please Initialize first.");
    return;
  }
  set_status(Status::RUN);

  system_.create(std::bind(&Bicycle::run_model, this), 1ms);
  spdlog::info("system model: Car is running");
}
void Bicycle::pause() {
  set_status(Status::PAUSE);
  spdlog::info("simulation is paused");
}
void Bicycle::exit() {
  spdlog::info("total simulation time: {:.2f} sec", simulation_time_.elapsed_ms() * 1e3);
  set_status(Status::STOP);
  system_.join();
}
void Bicycle::show_current_time() {
  spdlog::info("current simulation time: {:.2f} sec", simulation_time_.elapsed_ms() * 1e3);
}

void Bicycle::set_status(const Status& status) {
  std::unique_lock<std::shared_mutex> wlock(status_mutex_);
  status_ = status;
}
SystemModelInterface::Status Bicycle::get_status() {
  return status_;
}

void Bicycle::run_model() {
  int data = data_board_.get_data();  // temp input

  /*
   * x[k+1] = a_d*x[k] + b_d*u + w_d
   */
  /*
    const double vel = std::max(m_velocity, 0.01);


    a_d = Eigen::MatrixXd::Zero(m_dim_x, m_dim_x);
    a_d(0, 1) = 1.0;
    a_d(1, 1) = -(m_cf + m_cr) / (m_mass * vel);
    a_d(1, 2) = (m_cf + m_cr) / m_mass;
    a_d(1, 3) = (m_lr * m_cr - m_lf * m_cf) / (m_mass * vel);
    a_d(2, 3) = 1.0;
    a_d(3, 1) = (m_lr * m_cr - m_lf * m_cf) / (m_iz * vel);
    a_d(3, 2) = (m_lf * m_cf - m_lr * m_cr) / m_iz;
    a_d(3, 3) = -(m_lf * m_lf * m_cf + m_lr * m_lr * m_cr) / (m_iz * vel);

    Eigen::MatrixXd I = Eigen::MatrixXd::Identity(m_dim_x, m_dim_x);
    Eigen::MatrixXd a_d_inverse = (I - dt * 0.5 * a_d).inverse();

    a_d = a_d_inverse * (I + dt * 0.5 * a_d);  // bilinear discretization

    b_d = Eigen::MatrixXd::Zero(m_dim_x, m_dim_u);
    b_d(0, 0) = 0.0;
    b_d(1, 0) = m_cf / m_mass;
    b_d(2, 0) = 0.0;
    b_d(3, 0) = m_lf * m_cf / m_iz;

    w_d = Eigen::MatrixXd::Zero(m_dim_x, 1);
    w_d(0, 0) = 0.0;
    w_d(1, 0) = (m_lr * m_cr - m_lf * m_cf) / (m_mass * vel) - vel;
    w_d(2, 0) = 0.0;
    w_d(3, 0) = -(m_lf * m_lf * m_cf + m_lr * m_lr * m_cr) / (m_iz * vel);

    b_d = (a_d_inverse * dt) * b_d;
    w_d = (a_d_inverse * dt * m_curvature * vel) * w_d;

    c_d = Eigen::MatrixXd::Zero(m_dim_y, m_dim_x);
    c_d(0, 0) = 1.0;
    c_d(1, 2) = 1.0;
    */
}

}  // namespace gaja
