/**
 * @file dynamics.hpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @date 2023-10-15
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */

#pragma once

#include "../../external/Eigen/Core"

namespace gaja {
class Dynamics {
public:
  Dynamics() = default;
  ~Dynamics() = default;

private:
  Eigen::Vector3d pose_;
};
}  // namespace gaja