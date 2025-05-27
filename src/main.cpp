#include <Arduino.h>
#include <Car.hpp>
#include <IRStrip.hpp>
#include <OTA.hpp>
// #include <BluetoothSerial.h>
// #include <BTDebug.hpp>

// denfinição da pinagem dos dispositivos de I/O
#define LEFT1 21
#define LEFT2 19
#define RIGHT1 18
#define RIGHT2 5
#define D1 12
#define D2 14
#define D3 27
#define D4 26
#define D5 25
#define D6 33
#define D7 32
#define D8 35

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
  {D1, "Esquerda3", -3},
  {D2, "Esquerda2", -2},
  {D3, "Esquerda1", -1},
  {D4, "Centro1", 0},
  {D5, "Centro2", 0},
  {D6, "Direita1", 1},
  {D7, "Direita2", 2},
  {D8, "Direita3", 3},
};
IRStrip strip(c_sensor);

// instanciamento do Bluetooth
// BluetoothSerial bt;
// Instanciamento do Debugger
// BTDebug Debug(Serial, bt);

// Substituição de macro Serial
// #define Serial Debugs

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