#include "funciones.h"

void setup()
{
    Serial.begin(BAUDRATE);
    Wire.begin();
    delay(TIEMPO_INICIO_BUS);
}

void loop()
{
    fsmUpdate();
}
