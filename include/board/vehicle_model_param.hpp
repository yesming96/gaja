/**
 * @file vehicle_model_param.hpp
 * @author Eunmin Hwang (yesming.em@gmail.com)
 * @brief
 * @date 2023-10-15
 *
 * @copyright Copyright (c) 2023 Eunmin Hwang all rights reserved.
 *
 */

#pragma once

namespace gaja {
class BicycleModelParameter {
public:
  // ref: https://doi.org/10.1016/j.ymssp.2018.08.028
  // cornering stiffnesses of front and rear tires
  double c_f = -87594;  // [N/rad]
  double c_r = -87594;  // [N/rad]

  // distances from the CoG to the front and rear axles
  double l_f = 1.25;  // [m]
  double l_r = 1.32;  // [m]

  // moment of inertia around z axis
  double i_z = 3411.52;  // [kg m^2]

  // mass
  double mass = 2160;  // [kg]

  // distances from CoG to front, end, side
  double d_f = 1.35;
  double d_r = 1.5;
  double d_s = 0.8;

  double acc_limit = 9.26;       // [m/s^2]
  double brake_limit = -6;       // [m/s^2]
  double brake_emergency = -10;  // [m/s^2]

  double max_steer_angle = 45;  // [rad]
  double max_velocity = 30;     // [m/s]
};
}  // namespace gaja