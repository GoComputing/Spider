#ifndef __ANDAR_H__
#define __ANDAR_H__

#include "modo.h"
#include "secuenciador.h"
#include "brazo.h"

class ModoAndar : public Modo {
private:
  static EstadoBrazos posiciones_andar[];
  static int num_elementos;
  Secuencia<EstadoBrazos> secuencia_andar;
  EstadoBrazos estado_actual;
  
public:
  ModoAndar();
  
  EstadoBrazos SiguientePaso(ProcesadorComandos &procesador_comandos);
};

#endif
