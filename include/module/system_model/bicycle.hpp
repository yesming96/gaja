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

#include <mutex>
#include <shared_mutex>

#include "../../../external/Eigen/Core"
#include "../../data/data_board.hpp"
#include "../../type/stopwatch.hpp"
#include "../../utility/log.hpp"
#include "../../utility/thread.hpp"
#include "system_model_interface.hpp"

namespace gaja {
class Bicycle : public SystemModelInterface {
public:
  Bicycle() = default;
  ~Bicycle() = default;

  bool init();
  void run();
  void pause();
  void exit();
  void show_current_time();

  void set_status(const Status& status);
  Status get_status();

  // TODO: design interface to get initialize pose.
  void run_model();

private:
  bool is_initialize_{false};
  Stopwatch simulation_time_;
  bool is_pause();
  Thread system_;

  std::shared_mutex status_mutex_;
  Status status_ = Status::NONE;
  DataBoard data_board_;
  BicycleModelParameter bicycle_model_param_;

  Eigen::Vector4d state_;
  Eigen::Matrix4d A_;
};
}  // namespace gaja
