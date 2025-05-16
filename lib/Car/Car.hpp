#ifndef _CAR_H_
#define _CAR_H_

#include <Arduino.h>
#include <DCMotor.hpp>
#include <IRSensor.hpp>

class Car {
  private:
    DCMotor& _leftMotor, _rightMotor;
  
  public:
    IRSensor& leftSensor, rightSensor, frontSensor;
    Car(DCMotor& leftMotor, DCMotor& rightMotor, IRSensor& leftSensor, IRSensor& rightSensor, IRSensor& frontSensor)
      :
      _leftMotor(leftMotor),
      _rightMotor(rightMotor),
      leftSensor(leftSensor),
      rightSensor(rightSensor),
      frontSensor(frontSensor) {}

    void on(uint8_t leftSpeed, uint8_t rightSpeed) {
      _leftMotor.setSpeed(leftSpeed);
      _rightMotor.setSpeed(rightSpeed);
      _leftMotor.on();
      _rightMotor.on();
    }

    void off() {
      _leftMotor.off();
      _rightMotor.off();
    }
};

#endif