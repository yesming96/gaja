/**
 * @file thread.hpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief Refer to https://github.com/MorganCaron/CppUtils/tree/master/Thread
 * @version 0.1
 * @date 2023-08-21
 * 	const auto loopThread = CppUtils::Thread::LoopThread{&loop, 5s};
 *
 * @copyright Copyright (c) 2023. Eunmin Hwang all rights reserved.
 *
 */

#pragma once

#include <atomic>
#include <chrono>
#include <functional>
#include <iostream>
#include <memory>
#include <thread>
#include <utility>

#include "../base.hpp"
namespace gaja {
class Thread {
public:
  Thread() = default;
  Thread(std::function<void()> func, std::chrono::milliseconds interval)
      : func_(func), interval_(interval), running_(true), pause_(true) {
    worker_ = std::make_unique<std::thread>(&Thread::run, this);
  }

  ~Thread() {
    stop();
  }

  void create(std::function<void()> func, std::chrono::milliseconds interval) {
    func_ = func;
    interval_ = interval;
    running_ = true;
    pause_ = true;
    if (worker_ == nullptr) {
      worker_ = std::make_unique<std::thread>(&Thread::run, this);
    } else {
      spdlog::info("This thread is already occupied");
      resume();
    }
  }

  void join() {
    if (worker_ && worker_->joinable()) {
      worker_->join();
    }
    if (worker_ != nullptr) worker_.reset();
  }

  void start() {
    running_ = true;
    pause_ = false;
  }

  void pause() {
    pause_ = true;
  }

  void resume() {
    pause_ = false;
  }

  void stop() {
    running_ = false;
    pause_ = true;
    if (worker_ && worker_->joinable()) {
      worker_->join();
    }
    worker_.reset();
  }

private:
  void run() {
    while (running_ && gaja::is_program_running()) {
      if (pause_) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        spdlog::info("This thread is paused");
        continue;
      }

      auto start = std::chrono::high_resolution_clock::now();
      func_();
      auto end = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
      auto sleep_time = interval_ - duration;
      if (sleep_time > std::chrono::milliseconds(0)) {
        std::this_thread::sleep_for(sleep_time);
      }
    }
  }

  std::function<void()> func_;
  std::chrono::milliseconds interval_;
  std::atomic<bool> running_;
  std::atomic<bool> pause_;
  std::unique_ptr<std::thread> worker_;
};
}  // namespace gaja