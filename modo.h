#ifndef __MODO_H__
#define __MODO_H__

#include "brazo.h"
#include "bluetooth.h"

class Modo {
public:
  virtual EstadoBrazos SiguientePaso(ProcesadorComandos &procesador_comandos);
};

#endif
