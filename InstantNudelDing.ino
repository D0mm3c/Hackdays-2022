#include <Servo.h>

Servo nudelServo;
Servo pulverServo;
Servo wasserServo;


const int wasser_button = 2;
const int pulver_button = 3;
const int nudel_button = 4;
const int nudel_servo1 = 8;
const int pulver_servo = 7;
const int wasser_servo = 6;

int wasserButtonPressed;
int pulverButtonPressed;
int nudelButtonPressed;
int whichButtonPressed;

int posN = 0;
int posW = 0;
int posP = 0;

void setup()  {
  pinMode(wasser_button, INPUT);
  pinMode(pulver_button, INPUT);
  pinMode(nudel_button, INPUT);
  nudelServo.attach(nudel_servo1);
  pulverServo.attach(pulver_servo);
  wasserServo.attach(wasser_servo);

}

void loop()  {
  nudel_output();
  pulver_output();
  wasser_output();
}

void wasser_output() {
  wasserButtonPressed = digitalRead(wasser_button);
  if (wasserButtonPressed == HIGH) {

    for (posW = 0; posW <= 180; posW += 1) {
      wasserServo.write(posW);
      delay(15);
    }

    for (posW = 180; posW >= 0; posW -= 1) {
      wasserServo.write(posW);
      delay(15);
    }

  }
  else {
    wasserServo.write(15);
  }
}




void pulver_output() {
  pulverButtonPressed = digitalRead(pulver_button);
  if (pulverButtonPressed == HIGH) {

    for (posP = 0; posP <= 180; posP += 1) {
      pulverServo.write(posP);
      delay(15);
    }

    for (posP = 180; posP >= 0; posP -= 1) {
      pulverServo.write(posP);
      delay(15);
    }

  }
  else {
    pulverServo.write(15);
  }
}

void nudel_output() {
  nudelButtonPressed = digitalRead(nudel_button);
  if (nudelButtonPressed == HIGH) {

    for (posN = 0; posN <= 180; posN += 1) {
      nudelServo.write(posN);
      delay(15);
    }

    for (posN = 180; posN >= 0; posN -= 1) {
      nudelServo.write(posN);
      delay(15);
    }

  }

  else {
    nudelServo.write(15);

  }
}

