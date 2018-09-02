#ifndef __BRAZO_H__
#define __BRAZO_H__

#include <Adafruit_PWMServoDriver.h>

extern Adafruit_PWMServoDriver controlador;

struct EstadoBrazos {
  double estado[8];
};

class Brazo {
private:
  int id_brazo;
  int id_antebrazo;
  int min_brazo;
  int max_brazo;
  int min_antebrazo;
  int max_antebrazo;
  bool brazo_invertido;
  bool antebrazo_invertido;

protected:
  void GirarServo(int id, int minimo, int maximo, bool invertido, double porcentage);

public:
  Brazo(int id_brazo, int id_antebrazo, int min_brazo, int max_brazo, int min_antebrazo, int max_antebrazo, bool brazo_invertido, bool antebrazo_invertido);
  
  void Girar(double porcentage);
  void Estirar(double porcentage);
};

#endif
