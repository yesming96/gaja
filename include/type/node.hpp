/**
 * @file node.hpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @date 2023-09-01
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */
#pragma once

#include <vector>
namespace gaja {
class Node {
public:
  Node() = delete;
  Node(int id, );
  ~Node() = default;

private:
  int id_;
};
}  // namespace gaja