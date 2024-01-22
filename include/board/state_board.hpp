/**
 * @file state_board.hpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-28
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */
#pragma once

#include <mutex>
#include <shared_mutex>

#include "../type/control_input.hpp"
#include "../type/pose.hpp"

namespace gaja {
class StateBoard {
public:
  static StateBoard& get_instance() {
    static StateBoard instance;
    return instance;
  }

  // delete copy and substitute
  StateBoard(const StateBoard&) = delete;
  StateBoard& operator=(const StateBoard&) = delete;

  void set_pose(const Pose& pose) {
    std::unique_lock<std::shared_mutex> wlock(pose_mutex_);
    current_pose_ = pose;
  }

  Pose get_pose() {
    std::shared_lock<std::shared_mutex> rlock(pose_mutex_);
    return current_pose_;
  }

  void set_control_input(const ControlInput& control_input) {
    std::unique_lock<std::shared_mutex> wlock(control_input_mutex_);
    control_input_ = control_input;
  }

  ControlInput get_control_input() {
    std::shared_lock<std::shared_mutex> rlock(control_input_mutex_);
    return control_input_;
  }

  void set_velocity(double velocity) {
    std::unique_lock<std::shared_mutex> wlock(velocity_mutex_);
    velocity_ = velocity;
  }
  double get_velocity() {
    std::shared_lock<std::shared_mutex> rlock(velocity_mutex_);
    return velocity_;
  }

  void set_steering_velocity(double steering_velocity) {
    std::unique_lock<std::shared_mutex> wlock(steering_velocity_mutex_);
    steering_velocity_ = steering_velocity;
  }
  double get_steering_velocity() {
    std::shared_lock<std::shared_mutex> rlock(steering_velocity_mutex_);
    return steering_velocity_;
  }

  void set_steering_angle(double steering_angle) {
    std::unique_lock<std::shared_mutex> wlock(steering_angle_mutex_);
    steering_angle_ = steering_angle;
  }
  double get_steering_angle() {
    std::shared_lock<std::shared_mutex> rlock(steering_angle_mutex_);
    return steering_angle_;
  }

  void set_acceleration(double acceleration) {
    std::unique_lock<std::shared_mutex> wlock(acceleration_mutex_);
    acceleration_ = acceleration;
  }
  double get_acceleration() {
    std::shared_lock<std::shared_mutex> rlock(acceleration_mutex_);
    return acceleration_;
  }

private:
  StateBoard() {
  }

  Pose current_pose_;
  ControlInput control_input_;
  double velocity_;
  double acceleration_;
  double steering_angle_;
  double steering_velocity_;

  // mutexes
  mutable std::shared_mutex pose_mutex_;
  mutable std::shared_mutex control_input_mutex_;
  mutable std::shared_mutex velocity_mutex_;
  mutable std::shared_mutex acceleration_mutex_;
  mutable std::shared_mutex steering_angle_mutex_;
  mutable std::shared_mutex steering_velocity_mutex_;
};
}  // namespace gaja