/**
 * @file stopwatch.hpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @date 2023-09-05
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */

#pragma once
#include <chrono>
namespace gaja {
class Stopwatch {
  using clock = std::chrono::steady_clock;

public:
  Stopwatch() : start_time_point_{clock::now()} {};

  std::chrono::seconds elapsed_sec() const {
    return std::chrono::duration_cast<std::chrono::seconds>(clock::now() - start_time_point_);
  }
  std::chrono::milliseconds elapsed_ms() const {
    return std::chrono::duration_cast<std::chrono::milliseconds>(clock::now() - start_time_point_);
  }
  std::chrono::nanoseconds elapsed_ns() const {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(clock::now() - start_time_point_);
  }
  void reset() {
    start_time_point_ = clock::now();
  }

private:
  std::chrono::time_point<clock> start_time_point_;
};
}  // namespace gaja