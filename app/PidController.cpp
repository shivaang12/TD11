/** @file PidController.cpp
 *  @brief Implementation for a simple PID Controller
 *
 *  This contains a PID controller that supports
 *  a controller with proportional, integral, and
 *  derivative constants.  The class can be used
 *  to calculate a new value given the current value,
 *  a set point and time delta.
 *
 *  @author Robert Dumont
 *  @copyright Copyright [2018] <Robert Dumont>
 */

#include "PidController.h"


PidController::PidController(double kp, double ki, double kd)
    : k_p_(kp),
      k_i_(ki),
      k_d_(kd) {
}

double PidController::calculate(double current_velocity, double set_point,
                                double dt) {
  previous_err_ = err_;  //should be written at the end and read in the beginning before err gets recalcuated
  err_ = set_point - current_velocity;
  integral_ += err_;

  velocity_ = (k_p_ * err_) + (k_i_ * integral_ * dt)
      + (k_d_ * (err_ - previous_err_));

  return velocity_;
}

double PidController::getKp() const {
  return k_p_;
}

double PidController::getKi() const {
  return k_i_;
}

double PidController::getKd() const {
  return k_d_;
}
