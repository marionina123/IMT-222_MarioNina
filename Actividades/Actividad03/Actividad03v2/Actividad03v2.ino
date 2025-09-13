#include "funciones.h"

void setup() 
{
  conf();
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

  if(!digitalRead(BTN3))
  {
    subirCan();
    while (!digitalRead(BTN3)){}
    delay(DELAY);
  }

  if(!digitalRead(BTN4))
  {
    bajarCan();
    while (!digitalRead(BTN4)){}
    delay(DELAY);
  }
}
