/**
 * @file time.hpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @date 2023-09-05
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */
#pragma once
#include <stdint.h>

#include <chrono>
#include <iostream>
#include <thread>
namespace gaja {

class Time {
public:
  Time() = delete;
  Time(int64_t time_ns) noexcept;
  Time(const std::chrono::nanoseconds& time_ns) noexcept;
  ~Time() = default;

  double to_sec() const noexcept;
  double to_ms() const noexcept;
  int64_t to_ns() const noexcept;

  static Time now() noexcept;
  static void sleep_for(const std::chrono::nanoseconds& time_ns);
  static void sleep_for(const Time& time);

  Time& operator+=(const Time& rhs);
  Time& operator-=(const Time& rhs);
  const Time operator+(const Time& rhs) const;
  const Time operator-(const Time& rhs) const;
  bool operator==(const Time& other) const noexcept;
  bool operator!=(const Time& other) const noexcept;
  bool operator>(const Time& time) const noexcept;
  bool operator<(const Time& time) const noexcept;

  friend std::ostream& operator<<(std::ostream& os, const Time& time) noexcept {
    os << time.ns_;
    return os;
  }

private:
  int64_t ns_{0ul};
  std::chrono::time_point<std::chrono::steady_clock> start_time_;
};
using namespace std::chrono_literals;

}  // namespace gaja