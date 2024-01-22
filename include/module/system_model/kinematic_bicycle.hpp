/**
 * @file bicycle.hpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @date 2023-09-30
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */
#pragma once

#include <algorithm>
#include <cmath>
#include <mutex>
#include <shared_mutex>

#include "../../../external/Eigen/Core"
#include "../../board/parameter_board.hpp"
#include "../../board/state_board.hpp"
#include "../../type/control_input.hpp"
#include "../../type/stopwatch.hpp"
#include "../../utility/log.hpp"
#include "../../utility/thread.hpp"
#include "system_model_interface.hpp"

namespace gaja {
class KinematicBicycle : public SystemModelInterface {
public:
  KinematicBicycle() = default;
  ~KinematicBicycle() = default;

  virtual bool init() final;
  virtual void run() final;
  virtual void pause() final;
  virtual void resume() final;
  virtual void exit() final;
  virtual void show_current_time() final;

  void set_status(const Status& status);
  Status get_status();

  // TODO: design interface to get initialize pose.
  void run_model();

private:
  bool is_initialize_{false};
  Stopwatch simulation_time_;
  bool is_pause();
  Thread system_;

  // time step
  std::chrono::milliseconds time_step_ = 10ms;  // ms

  std::shared_mutex status_mutex_;
  Status status_ = Status::NONE;

  ParameterBoard parameter_board_;
  StateBoard state_board_;
  BicycleModelParameter bicycle_model_param_;

  // model parameters
  double wheel_base_ = 0.;
  double max_steer_angle_;
  double max_velocity_;

  // model state
  double vx_{0.};
  double vy_{0.};
  double yaw{0.};
};
}  // namespace gaja
