/**
 * @file state_board.hpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-12-28
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */
#pragma once

#include <mutex>
#include <shared_mutex>

namespace gaja {
class StateBoard {
public:
  static StateBoard& get_instance() {
    static StateBoard instance;
    return instance;
  }

  // delete copy and substitute
  StateBoard(const StateBoard&) = delete;
  StateBoard& operator=(const StateBoard&) = delete;


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

private:
  StateBoard() {
  }

  // datas
  int data_{0};
  double test_{0.0};

  // mutexes
  mutable std::shared_mutex data_mutex;
  mutable std::shared_mutex test_mutex;

  
};
}  // namespace gaja