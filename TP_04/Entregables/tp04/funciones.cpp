#include "funciones.h"

BH1750 sensor;
EstadoFSM estadoActual = ESTADO_CONFIGURACION;

// -----------------------------------------------------
// Escaneo del bus I2C
// -----------------------------------------------------
bool scanI2C(void)
{
    Serial.println(MSG_SCAN_START);

    bool encontrado = false;

    for (uint8_t dir = I2C_MIN_ADDR; dir <= I2C_MAX_ADDR; dir++)
    {
        Wire.beginTransmission(dir);
        uint8_t error = Wire.endTransmission();

        if (error == 0)
        {
            Serial.print(MSG_SCAN_FOUND);
            Serial.println(dir, HEX);

            if (dir == BH1750_ADDR)
                encontrado = true;

            delay(TIEMPO_ENTRE_DIRECCION);
        }
    }

    if (!encontrado)
        Serial.println(MSG_SCAN_NONE);

    Serial.println(MSG_SCAN_DONE);
    Serial.println();

    return encontrado;
}


// -----------------------------------------------------
// Inicialización del sensor
// -----------------------------------------------------
bool initSensor(void)
{
    sensor.begin(BH1750_MODE, BH1750_ADDR);

    delay(TIEMPO_TEST_INICIAL);

    float lectura = sensor.readLightLevel();

    if (lectura == LUX_INVALIDO_RAW || lectura < LUX_MIN_VALIDO)
    {
        Serial.println(MSG_SENSOR_INIT_FAIL);
        return false;
    }

    Serial.println(MSG_SENSOR_INIT_OK);
    return true;
}


// -----------------------------------------------------
// Lectura de lux
// -----------------------------------------------------
float leerLux(void)
{
    float lux = sensor.readLightLevel();

    if (lux == LUX_INVALIDO_RAW || lux < LUX_MIN_VALIDO)
        return LUX_ERROR_VAL;

    return lux;
}


// -----------------------------------------------------
// Mostrar valor en Serial
// -----------------------------------------------------
void imprimirLux(float lux)
{
    Serial.print(MSG_LUX_LABEL);
    Serial.println(lux);
}


// -----------------------------------------------------
// Máquina de estados
// -----------------------------------------------------
void fsmUpdate(void)
{
    switch (estadoActual)
    {
        // -------------------------------
        // CONFIGURACIÓN
        // -------------------------------
        case ESTADO_CONFIGURACION:
            if (!scanI2C()) {
                estadoActual = ESTADO_ERROR;
                break;
            }

            if (!initSensor()) {
                estadoActual = ESTADO_ERROR;
                break;
            }

            estadoActual = ESTADO_LECTURA;
            break;

        // -------------------------------
        // LECTURA
        // -------------------------------
        case ESTADO_LECTURA:
        {
            float lux = leerLux();

            if (lux == LUX_ERROR_VAL) {
                estadoActual = ESTADO_ERROR;
                break;
            }

            estadoActual = ESTADO_VISUALIZACION;
            break;
        }

        // -------------------------------
        // VISUALIZACIÓN
        // -------------------------------
        case ESTADO_VISUALIZACION:
        {
            float lux = leerLux();

            if (lux == LUX_ERROR_VAL) {
                estadoActual = ESTADO_ERROR;
                break;
            }

            imprimirLux(lux);

            estadoActual = ESTADO_LECTURA;
            delay(TIEMPO_ENTRE_LECTURAS);
            break;
        }

        // -------------------------------
        // ERROR
        // -------------------------------
        case ESTADO_ERROR:
            Serial.println(MSG_ERROR_STATE);
            delay(TIEMPO_ERROR_RESET);
            estadoActual = ESTADO_CONFIGURACION;
            break;
    }
}
