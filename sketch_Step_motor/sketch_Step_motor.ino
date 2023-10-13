#include <Stepper.h>
 
#define STEPS 2048

Stepper stepper(STEPS, 8, 10, 9, 11);
 
void setup() 
{
  stepper.setSpeed(12);
}
 
void loop() {
  stepper.step(STEPS);
//  delay(1000);
}