#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm=Adafruit_PWMServoDriver();

void setup() {
  pwm.begin();
  pwm.setPWMFreq(50); //오작동 한다면 50Hz에서 조금씩 바꿔보기 
}

void loop() {
  for(int i = 200; i < 380; i++){
    //pwm.setPWM(0, 0, i); // 0번 핀
    //pwm.setPWM(1, 0, i); // 1번 핀
    pwm.setPWM(2, 0, i); // 2번 핀
    //pwm.setPWM(3, 0, i); // 3번 핀
    //pwm.setPWM(4, 0, i); // 4번 핀
    delay(10); 
  }
    for(int i = 380; i > 200; i--){
    //pwm.setPWM(0, 0, i); // 0번 핀
    //pwm.setPWM(1, 0, i); // 1번 핀
    pwm.setPWM(2, 0, i); // 2번 핀
    //pwm.setPWM(3, 0, i); // 3번 핀
    //pwm.setPWM(4, 0, i); // 4번 핀
    delay(10); 
  }
}