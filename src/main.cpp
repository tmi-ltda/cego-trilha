#include <Arduino.h>
#include <Car.hpp>
#include <IRStrip.hpp>
#include <OTA.hpp>

// denfinição da pinagem dos dispositivos de I/O
#define LEFT1 32
#define LEFT2 33
#define RIGHT1 25
#define RIGHT2 26
#define D0 8
#define D1 9
#define D2 10
#define D3 11
#define D4 12
#define D5 13
#define D6 15
#define D7 17

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
ir_sensor_config_t c_sensor[SIZE] = {
  {D0, "Esquerda3", -3},
  {D1, "Esquerda2", -2},
  {D2, "Esquerda1", -1},
  {D3, "Centro1", 0},
  {D4, "Centro2", 0},
  {D5, "Direita1", 1},
  {D6, "Direita2", 2},
  {D7, "Direita3", 3},
};
IRStrip strip(c_sensor);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);   // inicialização da comunicação serial
                          // (apenas para monitorar registros dos sensores)

  ota_begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  // Atualiza o loop do OTA
  ArduinoOTA.handle();

  // Controle dos sensores
  strip.read();
  int8_t error = strip.getError();
  if (error < 0) {
    car.axialRight();
  } else if (error > 0) {
    car.axialRight();
  } else {
    car.forward();
  }
}