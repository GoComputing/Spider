#include "bluetooth.h"
#include "utilidades.h"
#include "Arduino.h"

SoftwareSerial bluetooth = SoftwareSerial(10, 11);

ProcesadorComandos::ProcesadorComandos() {
  tipo_ultimo_comando = INVALIDO;
  eje_x = 0;
  eje_y = 0;
  boton = -1;
  hay_nuevo_comando = false;
}

void ProcesadorComandos::ActualizarComando() {
  byte comando[8];
  bool comando_valido;
  bool comando_leido;
  TipoComando tipo_comando;
  int nuevo_eje_x;
  int nuevo_eje_y;
  int i;
  if(bluetooth.available()) {
    comando[0] = bluetooth.read();
    if(STX == comando[0]) {
      tipo_comando = INVALIDO;
      comando_valido = true;
      comando_leido = false;
      i = 1;
      while(comando_valido && !comando_leido) {
        if(bluetooth.available()) {
          comando[i] = bluetooth.read();
          comando_leido  = comando[i] == ETX;
          if(comando_leido) {
            comando_valido = i == 2 || i == 7;
          } else {
            comando_valido = i < 7;
          }
          if(i == 2)
            tipo_comando = BOTON;
          else if(i == 7)
            tipo_comando = JOYSTICK;
          i++;
        }
        delay(1);
      }
      if(comando_valido) {
        if(tipo_comando == JOYSTICK) {
          nuevo_eje_x = ValorEntero(comando[1], comando[2], comando[3]);
          nuevo_eje_y = ValorEntero(comando[4], comando[5], comando[6]);
        } else {
          boton = comando[1];
          hay_nuevo_comando = true;
        }
        tipo_ultimo_comando = tipo_comando;
        if(tipo_comando == JOYSTICK && (nuevo_eje_x != eje_x || nuevo_eje_y != eje_y)) {
          hay_nuevo_comando = true;
          eje_x = nuevo_eje_x;
          eje_y = nuevo_eje_y;
        }
      }
    }
  }
}

TipoComando ProcesadorComandos::TipoUltimoComando() {
  return tipo_ultimo_comando;
}

bool ProcesadorComandos::HayNuevoComando() {
  return hay_nuevo_comando;
}

void ProcesadorComandos::LimpiarBuffer() {
  while(bluetooth.available())
    bluetooth.read();
}

int ProcesadorComandos::UltimoEjeX() {
  if(tipo_ultimo_comando == JOYSTICK)
    hay_nuevo_comando = false;
  return eje_x - 200;
}

int ProcesadorComandos::UltimoEjeY() {
  if(tipo_ultimo_comando == JOYSTICK)
    hay_nuevo_comando = false;
  return eje_y - 200;
}

int ProcesadorComandos::UltimoBoton() {
  if(tipo_ultimo_comando == BOTON)
    hay_nuevo_comando = false;
  return boton;
}

bool ProcesadorComandos::ValorJoystickValido() {
  return eje_x >= 100 && eje_x <= 300 && eje_y >= 100 && eje_y <= 300 && tipo_ultimo_comando != INVALIDO;
}
