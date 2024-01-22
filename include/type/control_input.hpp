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
  ControlInput(double vel_x, double vel_y, double acceleration, double steer_angle) {
    this->vel_x = vel_x;
    this->vel_y = vel_y;
    this->acceleration = acceleration;
    this->steer_angle = steer_angle;
  }

  ~ControlInput() = default;

  double vel_x{0.};
  double vel_y{0.};
  double acceleration{0.};
  double steer_angle{0.};
};
}  // namespace gaja