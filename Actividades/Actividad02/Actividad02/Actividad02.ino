#include "funciones.h"

const int LED1 = 3;
const int LED2 = 4;
const int LED3 = 5;
const int LED4 = 6;
const int BOTON = 2;

int estadoBoton = HIGH;

void setup() 
{
  configurarPines(LED1, LED2, LED3, LED4, BOTON);
}

void loop() 
{
  estadoBoton = digitalRead(BOTON);
  if (estadoBoton == LOW) 
  {
    secuenciaLeds(LED1, LED2, LED3, LED4);
  }
}
