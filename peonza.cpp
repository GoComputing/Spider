#include "peonza.h"

EstadoBrazos ModoPeonza::SiguientePaso(ProcesadorComandos &procesador_comandos) {
  EstadoBrazos estado;
  double giro = 0.2;
  double altura_defecto = 0.5;
  estado.estado[0] = giro;
  estado.estado[2] = giro;
  estado.estado[4] = giro;
  estado.estado[6] = giro;
  if(procesador_comandos.ValorJoystickValido()) {
    int eje_x = procesador_comandos.UltimoEjeX();
    int eje_y = procesador_comandos.UltimoEjeY();
    double angulo = atan2(eje_x, eje_y);
    double modulo = sqrt(eje_x*eje_x + eje_y*eje_y) / 100.0;
    int i;
    Serial.println(angulo);
    for(i = 0; i < 4; ++i)
      estado.estado[2*i+1] = cos(angulo - PI/4.0 - i*PI/2.0) * modulo/2.0 + 0.5;
  } else {
    estado.estado[1] = altura_defecto;
    estado.estado[3] = altura_defecto;
    estado.estado[5] = altura_defecto;
    estado.estado[7] = altura_defecto;
  }
  return estado;
}
