#include <Servo.h>
#define LCR A5
Servo serv1;
Servo serv2;
Servo serv3;
int values[10];
int pos1[10];
int pos2[10];

void setup() {
  Serial.begin(9600);
  serv1.attach(10);
  serv2.attach(9);
  serv3.attach(2);
  serv1.write(90);
  serv2.write(90);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    pos1[i] = getPos1();
    pos2[i] = getPos2();
    values[i] = scan();
    Serial.print("Værdi af LCR er: ");
    Serial.println(values[i]);
    Serial.print("Værdi af servo 1 er: ");
    Serial.println(pos1[i]);
    Serial.print("Værdi af servo 2 er: ");
    Serial.println(pos2[i]);
    Serial.println();
    delay(3000);
  }
  int maks = findMax(values);
  serv1.write(pos1[maks]);
  serv2.write(pos2[maks]);
  Serial.print("største værdi index er: ");
  Serial.println(maks);
  Serial.print("Servo1 position er: ");
  Serial.println(pos1[maks]);
  Serial.print("Servo2 position er: ");
  Serial.println(pos2[maks]);
  delay(10000);

}

int scan() {
  int lys = analogRead(LCR);
  return lys;
}

int getPos1() {
  int pos = random(0, 170);
  serv1.write(pos);
  return pos;
}

int getPos2() {
  int pos = random(0, 180);
  serv2.write(pos);
  return pos;
}

int findMax(int values[]){
  int maks = values[0];
  int maksIndex;
  for (int i = 0; i < 10; i++) {
    if (values[i] > maks) {
      maks = values[i];
      maksIndex = i;
    }
  }
  return maksIndex;
}
