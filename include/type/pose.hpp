/**
 * @file pose.hpp
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
class Pose {
public:
  Pose() = default;
  Pose(double x, double y, double yaw) {
    this->x = x;
    this->y = y;
    this->yaw = yaw;
  };
  ~Pose() = default;

  double x{0.};
  double y{0.};
  double yaw{0.};
};
}  // namespace gaja