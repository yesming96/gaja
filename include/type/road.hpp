/**
 * @file road.hpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @date 2023-09-01
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */
#pragma once

namespace gaja {
class Road {
public:
  Road() = delete;
  Road(int id, double length, double speed_limit = 10);
  ~Road() = default;

  int id();

  double length();

  double speed_limit();

  void set_node_info(int from_node, int to_node);

  int from;

private:
  int id_;
  double length_;
  // unit: [m/s]
  double speed_limit_;

  int from_node_{-1};
  int to_node_{-1};
};
}  // namespace gaja