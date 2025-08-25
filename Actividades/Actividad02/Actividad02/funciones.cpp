#include "funciones.h"

void configurarPines(int led1, int led2, int led3, int led4, int boton) 
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(boton, INPUT);
}

void secuenciaLeds(int led1, int led2, int led3, int led4) 
{
  digitalWrite(led1, HIGH);
  delay(1000);

  digitalWrite(led2, HIGH);
  delay(1000);

  digitalWrite(led3, HIGH);
  delay(1000);

  digitalWrite(led4, HIGH);
  delay(1000);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}
