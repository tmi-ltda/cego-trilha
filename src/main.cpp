#include <Arduino.h>
#include <Car.hpp>

// denfinição da pinagem dos dispositivos de I/O
#define LEFT_MOTOR_PIN1 33
#define LEFT_MOTOR_PIN2 32
#define RIGHT_MOTOR_PIN1 26
#define RIGHT_MOTOR_PIN2 25
#define LEFT_SENSOR_PIN 24
#define MIDDLE_SENSOR_PIN 14
#define RIGHT_SENSOR_PIN 12

// instanciamento dos objetos que compõem o carro
DCMotor leftMotor(LEFT_MOTOR_PIN1, LEFT_MOTOR_PIN2); // motor esquerdo
DCMotor rightMotor(RIGHT_MOTOR_PIN1, RIGHT_MOTOR_PIN2); // motor direito
IRSensor leftSensor(LEFT_SENSOR_PIN, "Esquerda"); // sensor da esquerda
IRSensor frontSensor(MIDDLE_SENSOR_PIN, "Meio"); // sensor frontal
IRSensor rightSensor(RIGHT_SENSOR_PIN, "Direita"); // sensor da direita

// instanciamento do carro
Car car(leftMotor, rightMotor, leftSensor, rightSensor, frontSensor);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);   // inicialização da comunicação serial
                          // (apenas para monitorar registros dos sensores)
}

void loop() {
  // put your main code here, to run repeatedly:
  // leitura dos sensores
  bool left = car.leftSensor.read();
  bool right = car.rightSensor.read();
  bool front = car.frontSensor.read();

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