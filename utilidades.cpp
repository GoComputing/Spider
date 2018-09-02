#include "utilidades.h"

int Modulo(int numerador, int denominador) {
  int modulo = numerador%denominador;
  if(modulo < 0)
    modulo = modulo+denominador;
  return modulo;
}

int ValorEntero(int centenas, int decenas, int unidades) {
  centenas -= '0';
  decenas -= '0';
  unidades -= '0';
  return centenas*100 + decenas*10 + unidades;
}
