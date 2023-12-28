/**
 * @file yaml_handler.cpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-08-24
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */

#include "../../include/data/yaml_handler.hpp"

namespace gaja {
YamlHandler::YamlHandler(const std::string& file_name) : source_file_path_{file_name}, config_{YAML::Node()} {
}

void YamlHandler::load_data() {
  try {
    std::ifstream yaml_file;
    yaml_file.open(source_file_path_);
    if (yaml_file.is_open()) {
      config_ = YAML::LoadFile(source_file_path_);

      SPDLOG_INFO("parameter file is ready");
    }

  } catch (YAML::Exception& e) {
    throw std::runtime_error("unable to load yaml file: " + source_file_path_ + "err msg: " + e.msg);
    // throw std::runtime_error("unable to load yaml file: {}" + source_file_path_ + "err msg: " + e.msg);
  }
}

void YamlHandler::update_data() {
  DataBoard& db = DataBoard::get_instance();
  if (config_["test"]) {
    db.set_test(config_["test"].as<double>());
  }
  // ...
}
}  // namespace gaja