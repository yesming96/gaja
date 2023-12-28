/**
 * @file main.cpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-08-21
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */
#include <functional>
#include <iostream>
#include <memory>
#include <string>

#include "include/base.hpp"
#include "include/module/navigation.hpp"
#include "include/utility/thread.hpp"

using namespace gaja;
void print() {
  std::cout << "I'm in test\n";
}

class test {
public:
};

int main() {
  using namespace std::chrono_literals;
  gaja::program_running_ = true;
  // load yaml file

  // loop test
  auto loopThread = gaja::Thread(&print, 100ms);
  loopThread.start();

  // navigation module
  auto navigation = std::make_unique<Navigation>();
  // Navigation navigation;
  navigation->init();
  navigation->run();
  // gui interaction

  while (true) {
    if (gaja::is_program_running() == false) {
      std::cout << "I'm in running\n";
      break;
    } else {
      std::cout << "The program is running\n";
    }

    std::this_thread::sleep_for(1s);
  }

  // hold
  // get parameter
  // node?
  return 0;
}
