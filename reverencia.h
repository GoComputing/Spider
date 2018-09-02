#ifndef __REVERENCIA_H__
#define __REVERENCIA_H__

#include "modo.h"

class ModoReverencia : public Modo {
  EstadoBrazos SiguientePaso(ProcesadorComandos &procesador_comandos);
};

#endif
