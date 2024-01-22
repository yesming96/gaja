/**
 * @file navigation.hpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-08-24
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */
#pragma once

#include <functional>
#include <memory>
#include <shared_mutex>

#include "../board/parameter_board.hpp"
#include "../utility/log.hpp"
#include "global_path_planning/global_path_planning_interface.hpp"
#include "local_path_planning/local_path_planning_interface.hpp"
#include "module.hpp"
#include "utility/thread.hpp"
namespace gaja {
class Navigation {
public:
  Navigation() = default;
  ~Navigation() = default;

  bool init();
  bool setup();
  void run();
  void update_parameter();

  void system_model();
  void system_model2();

private:
  Thread system_model_;
  Thread test_model_1_;
  Thread test_model_2_;

  std::unique_ptr<local_path_planning_interface> local_path_planner_;
};

}  // namespace gaja