#ifndef __PEONZA_H__
#define __PEONZA_H__

#include "modo.h"

class ModoPeonza : public Modo {
  EstadoBrazos SiguientePaso(ProcesadorComandos &procesador_comandos);
};

#endif
