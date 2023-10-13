#include <Stepper.h>
 
#define STEPS 2048            // 스텝모터 작동 각도 2048 = 360도

int infrared  = 3;            // 적외선 장애물 감지 센서는 디지털 3번 핀으로 설정합니다.
Stepper stepper(STEPS, 8, 10, 9, 11);
 
void setup() 
{
  pinMode(infrared, INPUT);   // 적외선 장애물 감지 센서 핀을 INPUT으로 설정합니다.
  stepper.setSpeed(10);       // 스텝 모터 스피드       
  Serial.begin(9600);         // 적외선 장애물 감지 센서의 상태를 확인하기 위하여 시리얼 통신의 속도를 설정합니다.
}
 
void loop() {
  int state = digitalRead(infrared); // 적외선 감지 센서 부터 센서값을 읽습니다 (감지되면 0, 감지되지 않으면 1)

  Serial.print("Infrared = ");       // 측정된 센서값을 시리얼 모니터에 출력합니다.
  Serial.println(state);

  if(state == 0)                     // 측정된 센서값이 0(감지)면 아래 블록을 실행합니다.
  {
    Serial.println("Warning");       // 경보 메세지를 시리얼 모니터에 출력합니다.
  }

  else                               // 측정된 센서값이 0 이외(감지되지 않음) 이면 아래 블록을 실행합니다.
  {
    Serial.println("Safe");          // 안전 메세지를 시리얼 모니터에 출력합니다.
    stepper.step(100);               // 스텝모터 작동 시간 
  }
}