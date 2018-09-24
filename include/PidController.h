/** @file PidController.h
 *  @brief Interface for a simple PID Controller
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

#ifndef INCLUDE_PIDCONTROLLER_H_
#define INCLUDE_PIDCONTROLLER_H_

class PidController {
 public:
  /**
   * Contstruct a new PID controller with the given tuning parameters
   * @param kp Proportianl constant
   * @param ki Integral constant
   * @param kd Derivative constant
   */
  PidController(double kp, double ki, double kd);

  /**
   * Calculate a new velocity given the current value and set point
   * @param current_velocity The current value of the process variable
   * @param set_point The target value for the process variable
   * @param dt The time delta since the last calculation iteration
   * @return The new value of the process variable (velocity)
   */
  double calculate(double current_velocity, double set_point, double dt);

  /**
   * Getter for proportional constant
   * @return The value of Kp configured for the PID controller
   */
  double getKp() const;

  /**
   * Getter for integral constant
   * @return The value of Ki configured for the PID controller
   */
  double getKi() const;

  /**
   * Getter for derivative constant
   * @return The value of Kd configured for the PID controller
   */
  double getKd() const;

 private:
  const double k_p_;
  const double k_i_;
  const double k_d_;
  double previous_error_ = 0;
  double integral_ = 0;
  double err_ = 0;
  double velocity_ = 0;
  double current_state_ = 0;
  double previous_err_ = 0;
};

#endif  // INCLUDE_PIDCONTROLLER_H_
