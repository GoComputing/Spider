#ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__

#include <SoftwareSerial.h>

extern SoftwareSerial bluetooth;

enum TipoComando {INVALIDO, JOYSTICK, BOTON};

class ProcesadorComandos {
private:
  static const int STX = 0x02;
  static const int ETX = 0x03;
  
  TipoComando tipo_ultimo_comando;
  int eje_x;
  int eje_y;
  int boton;
  bool hay_nuevo_comando;
  
public:
  ProcesadorComandos();
  
  void ActualizarComando();
  TipoComando TipoUltimoComando();
  bool HayNuevoComando();
  void LimpiarBuffer();
  int UltimoEjeX();
  int UltimoEjeY();
  int UltimoBoton();
  bool ValorJoystickValido();
};

#endif
