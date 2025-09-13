#include "funciones.h"

uint8_t vol = VOLMIN;
uint8_t can = CANMIN;

void conf(void)
{
  Serial.begin(BAUDRATE);

  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);

  pinMode(BTN3, INPUT_PULLUP);
  pinMode(BTN4, INPUT_PULLUP);

  vol = EEPROM.read(EEPROM_VOL);
  can = EEPROM.read(EEPROM_CAN);

  if (vol > VOLMAX || vol < VOLMIN) vol = VOLINICIAL;
  if (can < CANMIN || can > CANMAX) can = CANINICIAL;

  Serial.print("Volumen: ");
  Serial.print(vol);

  Serial.print("Canal: ");
  Serial.println(can);
}

void subirVol(void)
{
  if(vol < VOLMAX)
  {
    vol++;
    Serial.print("Volumen: ");
    Serial.println(vol);
    EEPROM.update(EEPROM_VOL, vol);
  }
}

void bajarVol(void)
{
  if(vol > VOLMIN) 
  {
    vol--;
    Serial.print("Volumen: ");
    Serial.println(vol);
    EEPROM.update(EEPROM_VOL, vol);
  }
}

void subirCan(void)
{
  if(can >= CANMAX) can = CANMIN;
  else can++;
  Serial.print("Canal: ");
  Serial.println(can);
  EEPROM.update(EEPROM_CAN, can);
}

void bajarCan(void)
{
  if(can <= CANMIN) can = CANMAX;
  else can--;
  Serial.print("Canal: ");
  Serial.println(can);
  EEPROM.update(EEPROM_CAN, can);
}
