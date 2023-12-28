/**
 * @file road.cpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @date 2023-09-01
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */

#include "../../include/type/road.hpp"
namespace gaja {
Road::Road(int id, double length, double speed_limit) : id_(id), length_(length), speed_limit_(speed_limit){};

int Road::id() {
  return id_;
}

double Road::length() {
  return length_;
}

double Road::speed_limit() {
  return speed_limit_;
}

void Road::set_node_info(int from_node, int to_node) {
  from_node_ = from_node;
  to_node_ = to_node;
}

}  // namespace gaja