/**
 * @file data_board.hpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-08-23
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
#include <string>

#include "vehicle_model_param.hpp"
namespace gaja {
class ParameterBoard {
public:
  static ParameterBoard& get_instance() {
    static ParameterBoard instance;
    return instance;
  }

  // delete copy and substitute
  ParameterBoard(const ParameterBoard&) = delete;
  ParameterBoard& operator=(const ParameterBoard&) = delete;

  void load_file(const std::string& path) {
    try {
      std::unique_lock<std::shared_mutex> wlock(whole_data_mutex);

      std::ifstream yaml_file;

      yaml_file.open(path);

      if (yaml_file.is_open()) {
        std::stringstream ss;
        ss << yaml_file.rdbuf();

        YAML::Node param_content_ = YAML::Load(ss.str());
        bool loaded_ = true;

      } else {
      }
    } catch (YAML::Exception& e) {
    }
  }
  void set_data(int val) {
    std::unique_lock<std::shared_mutex> wlock(data_mutex);
    data_ = val;
  }

  int get_data() {
    std::shared_lock<std::shared_mutex> rlock(data_mutex);
    return data_;
  }

  void set_test(int val) {
    std::unique_lock<std::shared_mutex> wlock(test_mutex);
    test_ = val;
  }

  int get_test() {
    std::shared_lock<std::shared_mutex> rlock(test_mutex);
    return test_;
  }

  BicycleModelParameter get_bicycle_model_param() {
    std::shared_lock<std::shared_mutex> rlock(bicycle_model_param_mutex_);
    return bicycle_model_;
  }

private:
  ParameterBoard() {
  }

  // datas
  int data_{0};
  double test_{0.0};

  // mutexes
  // TODO: template으로 mutex의 lock unlock이 자동으로 되도록 ...?
  mutable std::shared_mutex whole_data_mutex;
  mutable std::shared_mutex data_mutex;
  mutable std::shared_mutex test_mutex;

  mutable std::shared_mutex bicycle_model_param_mutex_;
  BicycleModelParameter bicycle_model_;
};
}  // namespace gaja