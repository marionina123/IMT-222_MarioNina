#include "funciones.h"

void setup() 
{
  confVol();
  confCan();
}

void loop() 
{
  if(!digitalRead(BTN1))
  {
    subirVol();
    while (!digitalRead(BTN1)){}
    delay(DELAY);
  }
  
  if(!digitalRead(BTN2))
  {
    bajarVol();
    while (!digitalRead(BTN2)){}
    delay(DELAY);
  }
}
