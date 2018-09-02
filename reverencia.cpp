#include "reverencia.h"

EstadoBrazos ModoReverencia::SiguientePaso(ProcesadorComandos &procesador_comandos) {
  double giro = 0.2;
  double altura;
  EstadoBrazos estado;
  int eje_y = procesador_comandos.UltimoEjeY();
  Serial.println(procesador_comandos.ValorJoystickValido());
  if(procesador_comandos.ValorJoystickValido())
    altura = (eje_y + 100) / 200.0;
  else
    altura = 0.5;
  estado.estado[0] = giro;
  estado.estado[1] = altura;
  estado.estado[2] = giro;
  estado.estado[3] = 1.0-altura;
  estado.estado[4] = giro;
  estado.estado[5] = 1.0-altura;
  estado.estado[6] = giro;
  estado.estado[7] = altura;
  return estado;
}
