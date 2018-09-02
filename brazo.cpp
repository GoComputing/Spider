#include "brazo.h"

 Adafruit_PWMServoDriver controlador;

void Brazo::GirarServo(int id, int minimo, int maximo, bool invertido, double porcentage) {
  int ancho;
  if(invertido)
    porcentage = 1.0-porcentage;
  ancho = minimo + (maximo-minimo) * porcentage;
  controlador.setPWM(id, 0, ancho);
}

Brazo::Brazo(int id_brazo, int id_antebrazo, int min_brazo, int max_brazo, int min_antebrazo, int max_antebrazo, bool brazo_invertido, bool antebrazo_invertido) {
  this->id_brazo = id_brazo;
  this->id_antebrazo = id_antebrazo;
  this->min_brazo = min_brazo;
  this->max_brazo = max_brazo;
  this->min_antebrazo = min_antebrazo;
  this->max_antebrazo = max_antebrazo;
  this->brazo_invertido = brazo_invertido;
  this->antebrazo_invertido = antebrazo_invertido;
}

void Brazo::Girar(double porcentage) {
  GirarServo(id_brazo, min_brazo, max_brazo, brazo_invertido, porcentage);
}

void Brazo::Estirar(double porcentage) {
  GirarServo(id_antebrazo, min_antebrazo, max_antebrazo, antebrazo_invertido, porcentage);
}
