#include <Ultrasonic.h>

Ultrasonic SensorUltrassonico1(9, 10);

long Microsegundos = 0;
float DistanciaemCM = 0;

#define MotorLadoEsquerdo1 7
#define MotorLadoEsquerdo2 8
#define MotorLadoDireito1 4
#define MotorLadoDireito2 5
#define VelocidadeMotorLadoEsquerdo 6
#define VelocidadeMotorLadoDireito 3

int ValorVelocidadeMotorLadoEsquerdo = 100;
int ValorVelocidadeMotorLadoDireito = 140;

void setup() {
  pinMode(MotorLadoEsquerdo1, OUTPUT);
  pinMode(MotorLadoEsquerdo2, OUTPUT);
  pinMode(MotorLadoDireito1, OUTPUT);
  pinMode(MotorLadoDireito2, OUTPUT);
  Serial.begin(115200);// Inicia a comunicação seria com velocidade de 115200 bits por segundo
  delay(3000);// Tempo de espera para inicialização (para dar tempo de por o robô no chão)
}

void loop() {
  DistanciaemCM = SensorUltrassonico1.convert(SensorUltrassonico1.timing(), Ultrasonic::CM);
  Serial.print(DistanciaemCM);
  Serial.println(" cm");
  if (DistanciaemCM <= 40) {
    analogWrite(VelocidadeMotorLadoEsquerdo, ValorVelocidadeMotorLadoEsquerdo);
    analogWrite(VelocidadeMotorLadoDireito, ValorVelocidadeMotorLadoDireito);
    digitalWrite(MotorLadoEsquerdo1, HIGH);
    digitalWrite(MotorLadoEsquerdo2, LOW);
    digitalWrite(MotorLadoDireito1, HIGH);
    digitalWrite(MotorLadoDireito2, LOW);
    delay(700);
    digitalWrite(MotorLadoEsquerdo1, HIGH);
    digitalWrite(MotorLadoEsquerdo2, LOW);
    digitalWrite(MotorLadoDireito1, HIGH);
    digitalWrite(MotorLadoDireito2, LOW);
    delay(200);
  } else {
    analogWrite(VelocidadeMotorLadoEsquerdo, ValorVelocidadeMotorLadoEsquerdo);
    analogWrite(VelocidadeMotorLadoDireito, ValorVelocidadeMotorLadoDireito);
    digitalWrite(MotorLadoEsquerdo1, LOW);
    digitalWrite(MotorLadoEsquerdo2, HIGH);
    digitalWrite(MotorLadoDireito1, LOW);
    digitalWrite(MotorLadoDireito2, HIGH);
  }
}
