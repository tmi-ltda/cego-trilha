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

    void forward() {
      _leftMotor.forward();
      _rightMotor.forward();
    }

    void left() {
      _leftMotor.backward();
      _rightMotor.forward();
    }

    void right() {
      _leftMotor.forward();
      _rightMotor.backward();
    }

    void stop() {
      _leftMotor.stop();
      _rightMotor.stop();
    }
};

#endif