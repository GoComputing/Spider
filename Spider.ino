#include "brazo.h"
#include "bluetooth.h"
#include "modo.h"
#include "andar.h"
#include "peonza.h"
#include "reverencia.h"
#include "utilidades.h"

Brazo brazo_TR = Brazo(0, 1, 137, 344, 137, 322, false, true);
Brazo brazo_BR = Brazo(4, 5, 137, 344, 104, 256, false, true);
Brazo brazo_BL = Brazo(8, 9, 202, 409, 268, 453, true, false);
Brazo brazo_TL = Brazo(10, 11, 248, 453, 355, 562, true, false);
ProcesadorComandos procesador_comandos;
Modo *modos[] = {
  new ModoAndar(), 
  new ModoReverencia(), 
  new ModoPeonza()
};
const int num_modos = sizeof(modos) / sizeof(Modo*);
int id_modo_actual = 0;

void setup() {
  // Comunicación Serial con el ordenador
  Serial.begin(115200);
  delay(500);
  // Controlador de servomotores, es decir, de los brazos
  controlador = Adafruit_PWMServoDriver(0x40);
  controlador.begin();
  controlador.setPWMFreq(60);
  // Comunicación con la transmisora
  bluetooth.begin(9600);
  delay(500);
  while(bluetooth.available())
    bluetooth.read();
}

void loop() {
  EstadoBrazos estado_actual;
  procesador_comandos.ActualizarComando();
  
  if(procesador_comandos.TipoUltimoComando() == BOTON && procesador_comandos.HayNuevoComando()) {
    int boton = procesador_comandos.UltimoBoton();
    if(boton == 65 || boton == 66)
      id_modo_actual = (id_modo_actual+1) % num_modos;
    else if(boton == 67 || boton == 68)
      id_modo_actual = Modulo(id_modo_actual-1, num_modos);
  }
  
  estado_actual = modos[id_modo_actual]->SiguientePaso(procesador_comandos);
  
  //for(int i = 0; i < 8; ++i)
  //  Serial.print(estado_actual.estado[i] + String(" "));
  //Serial.println();
  
  // Movimiento
  // Top-Right
  brazo_TR.Girar(estado_actual.estado[0]);
  brazo_TR.Estirar(estado_actual.estado[1]);
  // Bottom-Right
  brazo_BR.Girar(estado_actual.estado[2]);
  brazo_BR.Estirar(estado_actual.estado[3]);
  // Bottom-Left
  brazo_BL.Girar(estado_actual.estado[4]);
  brazo_BL.Estirar(estado_actual.estado[5]);
  // Top-Left
  brazo_TL.Girar(estado_actual.estado[6]);
  brazo_TL.Estirar(estado_actual.estado[7]);
  
  delay(1);
}
















