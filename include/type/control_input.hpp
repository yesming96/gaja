/**
 * @file control_input.hpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @date 2023-12-28
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */
#pragma once

#include <vector>

namespace gaja {
class ControlInput {
public:
  ControlInput() = default;
  ControlInput(double vel_x, double vel_y) {
    vel_x_ = vel_x;
    vel_y_ = vel_y;
  }

  ~ControlInput() = default;

  double vel_x_{0.};
  double vel_y_{0.};
};
}  // namespace gaja