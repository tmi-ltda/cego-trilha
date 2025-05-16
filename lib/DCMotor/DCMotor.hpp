#ifndef _DCMOTOR_H_
#define _DCMOTOR_H_

#include <Arduino.h>
#include "pwm.h"

class DCMotor {
  private:
    uint16_t _speed;
    uint8_t _pin1, _pin2;
  
  public:
    DCMotor(uint8_t _pin1, uint8_t _pin2) : _speed(255) {
      pinMode(_pin1, OUTPUT);
      pinMode(_pin2, OUTPUT);
      analogWriteFrequency(_pin1, PWM_FREQUENCY);
      analogWriteResolution(_pin1, PWM_RESOLUTION);
      analogWriteFrequency(_pin2, PWM_FREQUENCY);
      analogWriteResolution(_pin2, PWM_RESOLUTION);
      stop();
    }

    void forward() {
      analogWrite(_pin1, _speed);
      digitalWrite(_pin2, LOW);
    }

    void backward() {
      digitalWrite(_pin1, LOW);
      analogWrite(_pin2, _speed);
    }

    void stop() {
      digitalWrite(_pin1, LOW);
      digitalWrite(_pin2, LOW);
    }

    void setSpeed(uint16_t speed) {
      _speed = speed;
    }
};

#endif