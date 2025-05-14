#include <Arduino.h>
#include <Car.hpp>

#define LEFT_MOTOR_PIN1 33
#define LEFT_MOTOR_PIN2 32
#define RIGHT_MOTOR_PIN1 26
#define RIGHT_MOTOR_PIN2 25
#define LEFT_SENSOR_PIN 24
#define MIDDLE_SENSOR_PIN 14
#define RIGHT_SENSOR_PIN 12

DCMotor leftMotor(LEFT_MOTOR_PIN1, LEFT_MOTOR_PIN2);
DCMotor rightMotor(RIGHT_MOTOR_PIN1, RIGHT_MOTOR_PIN2);
LDR leftSensor(LEFT_SENSOR_PIN, "Esquerda");
LDR middleSensor(MIDDLE_SENSOR_PIN, "Meio");
LDR rightSensor(RIGHT_SENSOR_PIN, "Direita");
Car car(leftMotor, rightMotor, leftSensor, rightSensor, middleSensor);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t leftSpeed = car.leftSensor.read() / car.frontSensor.read();
  uint8_t rightSpeed = car.rightSensor.read() / car.frontSensor.read();

  car.on(leftSpeed, rightSpeed);

  delay(100);
}