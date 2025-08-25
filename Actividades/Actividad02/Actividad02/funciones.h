#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <Arduino.h>
#define   DELAY   1000
#define   LED1    2
#define   LED2    3
#define   LED3    4
#define   LED4    5
#define   BTN     6
#define   BAUDRATE  9600

bool flag = false;
//unit8_t flag = 0;

void configuracion();
void espera();
void secuencia();

#endif
