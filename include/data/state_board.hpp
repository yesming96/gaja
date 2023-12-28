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

  void set_control_inputs(const std::vector<ControlInput>& control_inputs) {
    std::unique_lock<std::shared_mutex> wlock(control_inputs_mutex_);
    control_inputs_ = control_inputs;
  }

  std::vector<ControlInput> get_control_inputs() {
    std::shared_lock<std::shared_mutex> rlock(control_inputs_mutex_);
    return control_inputs_;
  }

private:
  StateBoard() {
  }

  // mutexes
  mutable std::shared_mutex pose_mutex_;
  mutable std::shared_mutex control_inputs_mutex_;

  Pose current_pose_;
  std::vector<ControlInput> control_inputs_;
};
}  // namespace gaja