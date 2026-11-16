/* TME 441
*  Milestone 3 - Object manipulation
*
*  This template includes example code to test your stepper and servo motors.
*  Once you are done testing, you should create your own Arduino sketch and
*  import the rest of your reusable code (motor_control.h and other *.ino files).
*
*  @author Matthew Ford
*  @version 2026
*/
#include <Stepper.h>
#include <Servo.h>

// Initialize stepper motor with 2048 steps per revolution
// Replace In1, In2, In3, In4 with the pin numbers connected to the stepper motor driver
Stepper stm(2048, In1, In3, In2, In4);

// Initialize servo motor
Servo svm;

int main() {
  init();

  // Initialize communication interfaces
  Serial.begin(115200);  // USB serial for debugging

  /* Initialize the servo motor
  Replace PIN with the pin number connected to the servo motor control signal.
  The second and third parameters specify the minimum and maximum pulse widths
  corresponding to 0 and 180 degrees. If your servo motor does not turn far
  enough, try adjusting these values.
   */
  svm.attach(PIN, 500, 2500);

  // Testing functions. Uncomment the one you want to test.
  testStepperMotor();
  //testServoMotor();

}

// Test the stepper motor by rotating it 1 revolution clockwise and counterclockwise
void testStepperMotor() {
  while (true) {
    stm.step(2048);  // Rotate 1 revolution clockwise
    delay(1000);     // Wait for 1 second
    stm.step(-2048); // Rotate 1 revolution counterclockwise
    delay(1000);     // Wait for 1 second
  }
}

// Test the servo motor by moving it between 0 and 180 degrees
void testServoMotor() {
  while (true) {
    svm.write(0);    // Move servo to 0 degrees
    delay(1000);     // Wait for servo to finish moving
    svm.write(180);  // Move servo to 180 degrees
    delay(1000);
  }
}