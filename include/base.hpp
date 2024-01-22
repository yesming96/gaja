/**
 * @file base.hpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-08-22
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */

#pragma once

#include <atomic>

#include "../external/spdlog/common.h"
#include "../external/spdlog/sinks/daily_file_sink.h"
#include "../external/spdlog/sinks/stdout_color_sinks.h"
#include "../external/spdlog/spdlog.h"
#include "Eigen/Core"
#include "spdlog/spdlog.h"
namespace gaja {
inline std::atomic_bool program_running_{true};

[[nodiscard]] inline bool is_program_running() {
  return program_running_;
};
inline void exit() {
  program_running_ = false;
};
using namespace std::chrono_literals;

}  // namespace gaja