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
    x_ = x;
    y_ = y;
    yaw_ = yaw;
  };
  ~Pose() = default;

  double x_{0.};
  double y_{0.};
  double yaw_{0.};
};
}  // namespace gaja