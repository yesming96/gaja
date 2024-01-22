/**
 * @file navigation.cpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-08-25
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */

#include "../../include/module/navigation.hpp"

namespace gaja {
bool Navigation::init() {
  spdlog::info("[CHECKING] navigation module is initializing!");

  system_model_.create(std::bind(&Navigation::system_model, this), 1s);
  system_model_.start();
  spdlog::info("[OK] navigation module is initialized!");
  return true;
}

bool Navigation::setup() {
  spdlog::info("[CHECKING] navigation module is setup!");

  spdlog::info("[OK] navigation module is setup!");
  return true;
}

void Navigation::run() {
  spdlog::info("[CHECKING] navigation module is running!");

  test_model_1_.create(std::bind(&Navigation::system_model, this), 100ms);
  test_model_2_.create(std::bind(&Navigation::system_model2, this), 200ms);
  test_model_1_.start();
  test_model_2_.start();
}

void Navigation::system_model() {
  spdlog::info("system model is running");
  ParameterBoard::get_instance().set_data(10);
  int data = ParameterBoard::get_instance().get_data();
  spdlog::info("data: {}", data);
}

void Navigation::system_model2() {
  spdlog::info("system model is running2");
  ParameterBoard::get_instance().set_data(20);

  int data = ParameterBoard::get_instance().get_data();
  spdlog::info("data 2: {}", data);
}
}  // namespace gaja