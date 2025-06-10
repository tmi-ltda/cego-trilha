#include <Arduino.h>
#include <BTDebug.hpp>

// Inicialização do debuger
BluetoothSerial bt;
BTDebug debbuger(Serial, bt);

#define Serial debbuger
#define SENSOR_N 3

#include <Car.hpp>
#include <IRStrip.hpp>
#include <BluetoothSerial.h>

// denfinição da pinagem dos dispositivos de I/O
#define LEFT1 21
#define LEFT2 19
#define RIGHT1 18
#define RIGHT2 5
#define D1 14
#define D2 27
#define D3 26

// Configuração do carro
car_config_t c_car = {
  .left_pin1 = LEFT1,
  .left_pin2 = LEFT2,
  .right_pin1 = RIGHT1,
  .right_pin2 = RIGHT2
};
// instanciamento do carro
Car car(c_car);

// Configuração dos sensores
ir_sensor_config_t c_sensor[SENSOR_N] = {
  {D1, "Esquerda", -1},
  {D2, "Centro", 0},
  {D3, "Direita", 1},
};
IRStrip strip(c_sensor);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  debbuger.btBegin("ESP32_Debug");
}

void loop() {
  // put your main code here, to run repeatedly:
  // Controle dos sensores
  strip.read(IR_MODES::DIGITAL_SENSOR);
  int8_t error = strip.getError();
  if (error < 0) {
    car.axialRight();
  } else if (error > 0) {
    car.axialLeft();
  } else {
    car.forward();
  }
}