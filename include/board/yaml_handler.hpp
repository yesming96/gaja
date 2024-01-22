/**
 * @file yaml_handler.hpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-08-24
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */

#pragma once
#include <yaml-cpp/yaml.h>

#include <fstream>
#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <stdexcept>
#include <string>

#include "../../external/spdlog/spdlog.h"
#include "../utility/log.hpp"
#include "../utility/thread.hpp"
#include "parameter_board.hpp"

namespace gaja {
class YamlHandler {
public:
  YamlHandler(const std::string& file_name);
  ~YamlHandler() = default;

  void update_data();

  void load_data();

private:
  std::string source_file_path_;
  YAML::Node config_;
};
}  // namespace gaja