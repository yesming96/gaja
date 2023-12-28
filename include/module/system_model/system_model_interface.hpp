/**
 * @file system_model_interface.hpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @date 2023-09-30
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */
#pragma once
#include <vector>

#include "../../base.hpp"
#include "../../utility/log.hpp"
#include "../../utility/thread.hpp"

namespace gaja {
class SystemModelInterface {
public:
  SystemModelInterface(int dimension_x, int dimension_u, int dimension_y)
      : dimension_x_{dimension_x}, dimension_u_{dimension_u}, dimension_y_{dimension_y} {};
  virtual ~SystemModelInterface() = default;

  enum class Type {
    BICYCLE_CAR = 0,
    ACKERMAN_CAR = 1
  };

  enum class Status {
    NONE = 0,
    INIT = 1,
    RUN = 2,
    PAUSE = 3,
    STOP = 4,
  };

  virtual bool init() = 0;
  virtual void run() = 0;
  virtual void pause() = 0;
  virtual void exit() = 0;
  virtual void show_current_time() = 0;

private:
  int dimension_x_ = 0;
  int dimension_u_ = 0;
  int dimension_y_ = 0;
};
}  // namespace gaja