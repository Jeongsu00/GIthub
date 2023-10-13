int ENA=2;
int IN1=3;
int IN2=4;
int ENB=5;
int IN3=6;
int IN4=7;

int infrared  = 8; // 적외선 장애물 감지 센서는 디지털 3번 핀으로 설정합니다.

void setup()
{
 pinMode(ENA,OUTPUT);
 pinMode(ENB,OUTPUT);
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 digitalWrite(ENA,HIGH);
 digitalWrite(ENB,HIGH);

 Serial.begin(9600);         // 적외선 장애물 감지 센서의 상태를 확인하기 위하여 시리얼 통신의 속도를 설정합니다.
 pinMode(infrared, INPUT);   // 적외선 장애물 감지 센서 핀을 INPUT으로 설정합니다.
}

void loop()
{
  int state = digitalRead(infrared); // 적외선 감지 센서 부터 센서값을 읽습니다 (감지되면 0, 감지되지 않으면 1)

  Serial.print("Infrared = ");       // 측정된 센서값을 시리얼 모니터에 출력합니다.
  Serial.println(state);

  if(state == 0){
  Serial.println("Warning");       // 경보 메세지를 시리얼 모니터에 출력합니다.
  }

  else{
  Serial.println("Safe");
  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(10);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(10);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(10);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(10);
  }
}