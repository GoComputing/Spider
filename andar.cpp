#include "andar.h"

EstadoBrazos ModoAndar::posiciones_andar[] = {
  {0.4, 0.5,   0.2, 0.5,   0.2, 0.5,   0.0, 0.5},
  
  {0.4, 0.7,   0.2, 0.5,   0.2, 0.5,   0.0, 0.5}, 
  {0.0, 0.7,   0.2, 0.5,   0.2, 0.5,   0.0, 0.5}, 
  {0.0, 0.5,   0.2, 0.5,   0.2, 0.5,   0.4, 0.5}, 
  
  {0.0, 0.5,   0.2, 0.5,   0.2, 0.7,   0.4, 0.5}, 
  {0.0, 0.5,   0.2, 0.5,   0.6, 0.7,   0.4, 0.5}, 
  {0.0, 0.4,   0.2, 0.5,   0.6, 0.4,   0.4, 0.5}, 
  
  {0.4, 0.4,   0.2, 0.5,   0.2, 0.4,   0.4, 0.5},
  
  {0.4, 0.5,   0.2, 0.8,   0.2, 0.5,   0.4, 0.5}, 
  {0.4, 0.5,   0.6, 0.8,   0.2, 0.5,   0.4, 0.5}, 
  {0.4, 0.5,   0.6, 0.5,   0.2, 0.5,   0.4, 0.5},
  
  {0.4, 0.5,   0.6, 0.5,   0.2, 0.5,   0.4, 0.7}, 
  {0.4, 0.5,   0.6, 0.5,   0.2, 0.5,   0.0, 0.7}, 
  {0.4, 0.5,   0.6, 0.5,   0.2, 0.5,   0.0, 0.5}
};
int ModoAndar::num_elementos = sizeof(ModoAndar::posiciones_andar) / sizeof(EstadoBrazos);

ModoAndar::ModoAndar() 
  : secuencia_andar (100, posiciones_andar, num_elementos)
{
  estado_actual = posiciones_andar[0];  
}

EstadoBrazos ModoAndar::SiguientePaso(ProcesadorComandos &procesador_comandos) {
  unsigned long long int max_tiempo = 400;
  unsigned long long int min_tiempo = 100;
  int min_eje_y = 10;
  int max_eje_y = 100;
  bool avanzar;
  
  avanzar = abs(procesador_comandos.UltimoEjeY()) > min_eje_y && procesador_comandos.TipoUltimoComando() == JOYSTICK;
  
  if(avanzar) {
    double porcentaje = (double)(abs(procesador_comandos.UltimoEjeY()) - min_eje_y) / (double)(max_eje_y - min_eje_y);
    //Serial.println(porcentaje + String("") + procesador_comandos.UltimoEjeY());
    unsigned long long int tiempo_minimo = max_tiempo - (max_tiempo-min_tiempo)*porcentaje;
    secuencia_andar.SetTiempoMinimo(tiempo_minimo);
    secuencia_andar.SetSecuenciaInvertida(procesador_comandos.UltimoEjeY() < 0);
    estado_actual = secuencia_andar.SiguienteElemento();
  }
  return estado_actual;
}
