#ifndef _IRSENSOR_H_
#define _IRSENSOR_H_

#include <Arduino.h>

class IRSensor {
  private:
    uint8_t _pin;
    const char* _name;

  public:
    IRSensor(uint8_t pin, const char* name) : _pin(pin), _name(name) {
      pinMode(_pin, INPUT);
    }

    bool read() {
      bool value = digitalRead(_pin);

      Serial.print("Leitura do sensor - ");
      Serial.print(_name);
      Serial.print(": ");
      Serial.println(value);

      return value;
    }
};

#endif