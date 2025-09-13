#include "funciones.h"

uint8_t vol = VOLMIN;

void conf(void)
{
  Serial.begin(BAUDRATE);

  pinMode(BTN1, INPUT_PULLUP); //pullup es para usar una resistencia interna, no todas las placas tienen una resistencia interna
  pinMode(BTN2, INPUT_PULLUP);

  vol = EEPROM.read(PRIMERACELDA);

  if(vol > VOLMAX || vol < VOLMIN)
  {
    vol = VOLINICIAL;

    EEPROM.write(PRIMERACELDA, vol);
  }

  Serial.print("Volumen inicial: ");
  Serial.println(vol);
}

void subirVol(void)
{
  if(vol < VOLMAX)
  {
    vol++;
    EEPROM.update(PRIMERACELDA, vol);

    Serial.println(vol);
  }
}

void bajarVol(void)
{
  if (vol > VOLMIN) 
  {
    vol--;
    EEPROM.update(PRIMERACELDA, vol);

    Serial.println(vol);
  }
}