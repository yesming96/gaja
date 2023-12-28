/**
 * @file time.cpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @date 2023-09-05
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */

#include "../../include/type/time.hpp"
namespace gaja {

Time::Time(int64_t time_ns) noexcept {
  ns_ = time_ns;
}
Time::Time(const std::chrono::nanoseconds& time_ns) noexcept {
  ns_ = time_ns.count();
}

double Time::to_sec() const noexcept {
  return static_cast<double>(ns_) / 1e9;
}
double Time::to_ms() const noexcept {
  return static_cast<double>(ns_) / 1e6;
}
int64_t Time::to_ns() const noexcept {
  return ns_;
}

Time Time::now() noexcept {
  return Time(std::chrono::system_clock::now().time_since_epoch().count());
}

void Time::sleep_for(const std::chrono::nanoseconds& time_ns) {
  std::this_thread::sleep_for(time_ns);
}
void Time::sleep_for(const Time& time) {
  std::this_thread::sleep_for(std::chrono::nanoseconds(time.to_ns()));
}

// operators
Time& Time::operator+=(const Time& rhs) {
  ns_ += rhs.to_ns();
  return *this;
}
Time& Time::operator-=(const Time& rhs) {
  ns_ -= rhs.to_ns();
  return *this;
}
const Time Time::operator+(const Time& rhs) const {
  return Time(*this) += rhs;
}
const Time Time::operator-(const Time& rhs) const {
  return Time(*this) -= rhs;
}
bool Time::operator==(const Time& other) const noexcept {
  return (ns_ == other.ns_);
}
bool Time::operator!=(const Time& other) const noexcept {
  return !(*this == other);
}
bool Time::operator>(const Time& time) const noexcept {
  if (ns_ > time.ns_) return true;

  return false;
}
bool Time::operator<(const Time& time) const noexcept {
  if (ns_ < time.ns_) return true;

  return false;
}
}  // namespace gaja