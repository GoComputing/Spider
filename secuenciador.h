#ifndef __SECUENCIADOR_H__
#define __SECUENCIADOR_H__

#include "utilidades.h"

template<typename T>
class Secuencia {
private:
  unsigned long long int tiempo_minimo;
  unsigned long long int ultimo_tiempo;
  unsigned long long int tiempo_minimo_actualizado;
  int num_elementos;
  const T *secuencia;
  int pos_actual;
  bool secuencia_invertida;
  
public:
  Secuencia(unsigned long long int tiempo_minimo, const T *secuencia, int num_elementos);
  
  T SiguienteElemento();
  void ReiniciarSecuencia();
  void SetTiempoMinimo(unsigned long long int tiempo);
  void SetSecuenciaInvertida(bool invertida);
};









////////////////////////////////////////////////////////////////////////////////
// Implementación
////////////////////////////////////////////////////////////////////////////////

template<typename T>
Secuencia<T>::Secuencia(unsigned long long int tiempo_minimo, const T *secuencia, int num_elementos) {
  this->tiempo_minimo = tiempo_minimo;
  this->secuencia = secuencia;
  this->num_elementos = num_elementos;
  pos_actual = 0;
  ultimo_tiempo = 0;
}

template<typename T>
T Secuencia<T>::SiguienteElemento() {
  unsigned long long int tiempo_espera = millis() - ultimo_tiempo;
  T elemento = secuencia[pos_actual];
  if(tiempo_espera >= tiempo_minimo) {
    int incremento;
    if(secuencia_invertida)
      incremento = -1;
    else
      incremento = 1;
    pos_actual = Modulo(pos_actual+incremento, num_elementos);
    ultimo_tiempo = millis();
  }
  tiempo_minimo = tiempo_minimo_actualizado;
  return elemento;
}

template<typename T>
void Secuencia<T>::ReiniciarSecuencia() {
  pos_actual = 0;
}

template<typename T>
void Secuencia<T>::SetTiempoMinimo(unsigned long long int tiempo) {
  tiempo_minimo_actualizado = tiempo;
}

template<typename T>
void Secuencia<T>::SetSecuenciaInvertida(bool invertida) {
  secuencia_invertida = invertida;
}

#endif
