/**
 * @file module.hpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-08-24
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */
#pragma once

#include "../base.hpp"
#include "../utility/thread.hpp"
namespace gaja {
class Module {
public:
  Module() = default;
  virtual ~Module() = default;

  virtual bool init();
  virtual bool setup();
  virtual void run();
  virtual void update_parameter();
private:
  
};
}  // namespace gaja