#ifndef _LDR_H_
#define _LDR_H_

#include <Arduino.h>
#include "pwm.h"

class LDR {
  private:
    uint8_t _pin;
    const char* _name;
  
  public:
    LDR(uint8_t pin, const char* name) : _pin(pin), _name(name) {}
    uint16_t read() {
      uint16_t value = analogRead(_pin);

      Serial.print("Leitura do sensor - ");
      Serial.print(_name);
      Serial.print(": ");
      Serial.println(value);

      return value;
    }
};

#endif