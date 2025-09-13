#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <Arduino.h>
#include <EEPROM.h>

#define BTN1   2
#define BTN2   3
#define BAUDRATE  115200
#define DELAY   20
#define VOLMAX 10
#define VOLMIN 0
#define VOLINICIAL 5

#define PRIMERACELDA 0

extern uint8_t vol;

void conf(void);
void subirVol(void);
void bajarVol(void);

#endif
