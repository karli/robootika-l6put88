#include <MeMCore.h>

MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
MeUltrasonicSensor sonar(PORT_3);
uint8_t leftMotorSpeed = 85;
uint8_t rightMotorSpeed = 100;
boolean findObstacleMode = true;
boolean goAroundObstacleMode = true;
boolean goInCircleMode = true;
int lightSensorPin = A6;
int lightUpThreshold = 400;
MeRGBLed led1(PORT7);
int lightningCounter = 0;

void setup() {
  delay(500);
  Serial.begin(9600);
  pinMode(lightSensorPin, INPUT);
}

void loop() {
  lightUpWhenDark();
  mainProgram();
}

void mainProgram() {
  float distance = sonar.distanceCm();
  Serial.println(distance);

  if (distance > 10 && findObstacleMode) {
    goStraight(1);
  }
  else if (goAroundObstacleMode){
    findObstacleMode = false;
    goStraight(-1);
    turnAround();
    goAroundObstacleMode = false;
    goInCircleMode = true;
  }
  else if (goInCircleMode) {
    goInCircle();
    if (sonar.distanceCm() < 10) {
      stopMoving();
      goInCircleMode = false;
      goAroundObstacleMode = true;
    }
  }
}

void turnAround() {
  turnRight();
  turnRight();
}


void goStraight(int units) {
  int directionMultiplier = units > 0 ? 1 : -1;
  motor1.run(directionMultiplier * -1 * leftMotorSpeed);
  motor2.run(directionMultiplier * rightMotorSpeed);
  delay(200);
}

void goInCircle() {
    motor1.run(-40);
    motor2.run(130);
}

void turnRight() {
  turn(true);
}

void turnLeft() {
  turn(false);
}

void turn(boolean turnRight) {
  int turnDirection = turnRight ? -1 : 1;
  motor1.run(turnDirection * leftMotorSpeed);
  motor2.run(turnDirection * rightMotorSpeed);
  delay(600);
  stopMoving();
}

void stopMoving() {
  motor1.stop();
  motor2.stop();
}

void lightUpWhenDark() {
  lightningCounter++;
  // shut down led before reading light sensor
  if (lightningCounter % 2 == 1) {
    led1.setColor(0, 0, 0);
    led1.show();
  }

  if (lightningCounter % 2 == 0) {
    // read light sensor value
    int lightSensorValue = analogRead(lightSensorPin);
    // assuming that it can be max 1000
    Serial.print("Sensor value = ");
    Serial.println(lightSensorValue);

    if (lightSensorValue < lightUpThreshold) {
      float litUpPercentage = lightSensorValue / (lightUpThreshold * 1.0);
      Serial.print("Light up percentage = ");
      Serial.println(litUpPercentage);
      int colorIntensity = 255 - (int)(255 * litUpPercentage);
      Serial.print("Color intensity = ");
      Serial.println(colorIntensity);
      led1.setColor(colorIntensity, colorIntensity, colorIntensity);
      led1.show();
    }
  }
}
