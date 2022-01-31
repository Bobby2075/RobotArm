#include <math.h>
#include <Servo.h>
#define LCR A5
int LCRRead;
Servo serv1;
Servo serv2;
Servo serv3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  serv1.attach(10);
  serv2.attach(9);
  serv3.attach(2);
  start();
}

void loop() {
  // put your main code here, to run repeatedly:
  //LCRRead = analogRead(LCR);
  //Serial.println(LCRRead);
  //delay(1000);
  int prevValue = scan();
  delay(60000);
}

int scan() {
  int minValue, temp;
  int maxValue = 0;
  float Randnum = random(0, 180);
  Serial.print("Random value is: ");
  Serial.println(Randnum);
  temp = analogRead(LCR);
  temp = minValue;
  
  while(true) {
    int serv1v, serv2v;
    serv1v = random(0, 180);
    serv2v = random(90, 180);
   
    Serial.println(serv1v);
    Serial.println(serv2v);
    serv1.write(serv1v);
    serv2.write(serv2v);
    delay(10000);
    temp = analogRead(LCR);
    
    if (temp > minValue) {
      maxValue = temp;
      minValue = temp;
      Serial.print("Temp is: ");
      Serial.println( temp);
      Serial.print("Max is: ");
      Serial.println( maxValue);
    } else {
      temp = minValue;
      Serial.print("min is: ");
      Serial.println(minValue);
    }
  }
  Serial.println("Loop is broken");
  return(maxValue);
  
}

void start(){
  serv1.write(90);
  serv2.write(90);
}
