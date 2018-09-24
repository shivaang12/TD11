// copyrigt 2018 Royneal Rayess , Shivang Patel
/*
 * @file main.cpp
 * @author Royneal Rayess , Shivang Patel
 * @version 1.0.0.0
 *
 * @brief An implementation of PID controller
 *        for 808x assignment Week4 PartB
 */

#include <iostream>
#include <PidController.h>

using std::cout;
using std::endl;

int main() {
  double velocity = 5;
  double set_point = 10;
  double dt = 0.01;
  int i = 0;
  double th = 0.01;

  PidController controller(0.015, 0.0055, 0.02);

  while (velocity < set_point - th || velocity > set_point + th) {
    velocity += controller.calculate(velocity, set_point, dt);
    cout << "current velocity is : " << velocity << endl;
    cout << "current iteration is: " << i << endl;
    i++;

    if (i > 1300) {
      cout << "not converging fast enough, exiting " << endl;
      break;
    }

  }
  return 0;
}
