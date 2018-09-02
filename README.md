# Araña robot

Esta es una pequeña implementación para una controladora de una araña robot.
La controladora se basa en un Arduino nano.

El hardware requerido para poder usar este código es el siguiente:
   * Un arduino nano
   * Un receptor bluetooth. Valen tanto un HC-05 o un HC-06
   * Un controlador de servos. Concretamente, usamos el PCA9685
   * Opcionalmente, se requerirán unos reguladores de tensión para alimentar
     el circuito.

Las siguientes librerías han sido usadas para controlar el hardware:
   * Adafruit PWM servo driver. Se puede descargar de GitHub
   * SoftwareSerial. Viene incluída en el software de Arduino

Para compilar el código, abra el archivo Spider.ino con el software del arduino
oficial. Compile el código, y súbalo. Versión probada: 1.6.1

El diagrama de cables del arduino es el siguiente:
   * RX del receptor bluetooth: pin digital 10
   * TX del receptor bluetooth: pin digital 11
   * SDA del controlador de servos: pin analógico A4
   * SCL del controlador de servos: pin analógico A5
   
Si quieres crear la araña, podéis descargar los modelos de la siguiente página:
   https://www.thingiverse.com/thing:2755973
Modelos no creados por mí.