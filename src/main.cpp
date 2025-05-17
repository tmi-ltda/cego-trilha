#include <Arduino.h>
#include <Car.hpp>
#include <IRSensor.hpp>

// denfinição da pinagem dos dispositivos de I/O
#define LEFT_MOTOR_PIN1 33
#define LEFT_MOTOR_PIN2 32
#define RIGHT_MOTOR_PIN1 26
#define RIGHT_MOTOR_PIN2 25
#define LEFT_SENSOR_PIN 24
#define MIDDLE_SENSOR_PIN 14
#define RIGHT_SENSOR_PIN 12

// Instanciamento dos sensores
IRSensor leftSensor(LEFT_SENSOR_PIN, "Esquerda"); // sensor da esquerda
IRSensor frontSensor(MIDDLE_SENSOR_PIN, "Meio"); // sensor frontal
IRSensor rightSensor(RIGHT_SENSOR_PIN, "Direita"); // sensor da direita

// Configuração do carro
static car_config_t config = {
  .left_pin1 = LEFT_MOTOR_PIN1,
  .left_pin2 = LEFT_MOTOR_PIN2,
  .right_pin1 = RIGHT_MOTOR_PIN1,
  .right_pin2 = RIGHT_MOTOR_PIN2
};

// instanciamento do carro
Car car(config);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);   // inicialização da comunicação serial
                          // (apenas para monitorar registros dos sensores)
}

void loop() {
  // put your main code here, to run repeatedly:
  // leitura dos sensores
  bool left = leftSensor.read();
  bool right = rightSensor.read();
  bool front = frontSensor.read();

  // lógica de movimento
  if (!front) {
    if (!left) car.right(); // correção para a esquerda
    else if (!right) car.left(); // correção para a direita
    else car.forward(); // frontal
  }
  else car.stop(); // para o carro caso ele esteja fora da trilha

  delay(100);   // delay de leitura
                // remover após a fase de testes
}