/** @file testPidController.cpp
 *  @brief Test cases for a simple PID Controller
 *
 *  This contains two tests for the simple PID controller.
 *  The first makes sure that the object can be successfully
 *  created and the tuning constants accessed.  The second test
 *  calculates that the calculate method is able to reach a steady
 *  state after enough iterations.  The PID constants were chosen
 *  using http://www.rentanadviser.com/en/pid-fuzzy-logic/pid-fuzzy-logic.aspx
 *  to make sure that the response was stable.
 *
 *  @author Robert Dumont
 *  @copyright Copyright [2018] <Robert Dumont>
 */
#include <gtest/gtest.h>
#include "PidController.h"

TEST(PidController, testPidControllerConstruction) {
  PidController pid(0.1, 0.5, 0.01);

  /*
   * Test that the values we input the controller
   * were properly recorded for use.
   */
  ASSERT_FLOAT_EQ(0.1, pid.getKp());
  ASSERT_FLOAT_EQ(0.5, pid.getKi());
  ASSERT_FLOAT_EQ(0.01, pid.getKd());
}

TEST(PidController, testPidControllerCalculate) {
  PidController pid(0.1, 0.5, 0.01);

  double velocity = 0;
  const double dt = 0.1;
  const double set_point = 50;

  /*
   * A working PID controller should reach a steady state
   * after 1000 iterations.  Let it run this many times with
   * a fixed interval and track the updated value after each
   * iteration.
   */
  for (int i = 0; i < 1000; i++) {
    velocity = pid.calculate(velocity, set_point, dt);
  }

  // Did we reach the set point after an adaquete dealy?
  ASSERT_FLOAT_EQ(set_point, velocity);
}
