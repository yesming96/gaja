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

#include <mutex>
#include <shared_mutex>

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
  mutable std::shared_mutex data_mutex;
  mutable std::shared_mutex test_mutex;

  mutable std::shared_mutex bicycle_model_param_mutex_;
  BicycleModelParameter bicycle_model_;
};
}  // namespace gaja