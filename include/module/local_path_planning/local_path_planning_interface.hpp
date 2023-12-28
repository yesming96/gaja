/**
 * @file local_path_planning_interface.hpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @date 2023-08-31
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */
#pragma once
#include <iostream>

namespace gaja {
class local_path_planning_interface {
public:
  local_path_planning_interface() = default;
  virtual ~local_path_planning_interface() = 0;
  enum class Status {
    NONE = 0,
    IDLE = 1,
    RUN = 2,
    COMPELETE = 3,
    ERROR = 4
  };
  /**
   * @brief initialize to prepare global path planning. (Load map, parameter, etc.)
   *
   * @return true: sucess
   * @return false: fail
   */
  virtual bool init() = 0;
  virtual bool check_health_status() = 0;
  virtual void plan() = 0;
  virtual bool exit() = 0;

private:
  Status status_ = Status::NONE;
};
}  // namespace gaja
