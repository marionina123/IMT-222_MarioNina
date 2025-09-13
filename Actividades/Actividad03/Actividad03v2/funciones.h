#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <Arduino.h>
#include <EEPROM.h>

#define BAUDRATE  115200
#define DELAY   30 

#define BTN1   2
#define BTN2   3
#define BTN3   4
#define BTN4   5

#define VOLMAX 100
#define VOLMIN 0
#define VOLINICIAL 20
#define EEPROM_VOL 0

#define CANMAX 9
#define CANMIN 1
#define CANINICIAL 1
#define EEPROM_CAN 1

extern uint8_t vol;
extern uint8_t can;

void conf(void);

void subirVol(void);
void bajarVol(void);

void subirCan(void);
void bajarCan(void);

#endif
