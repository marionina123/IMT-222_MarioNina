#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <Arduino.h>
#include <Wire.h>
#include <BH1750.h>

// -------------------------------
// Parámetros generales
// -------------------------------
#define BAUDRATE                9600
#define BH1750_ADDR             0x23
#define BH1750_MODE             BH1750::CONTINUOUS_HIGH_RES_MODE

// -------------------------------
// Rango estándar de direcciones I2C
// -------------------------------
#define I2C_MIN_ADDR            1       // 0 = "General Call", no se usa
#define I2C_MAX_ADDR            126     // 127 = reservada

// -------------------------------
// Valores especiales del sensor
// -------------------------------
#define LUX_INVALIDO_RAW        65535
#define LUX_ERROR_VAL           -1.0f
#define LUX_MIN_VALIDO          0.01f

// -------------------------------
// Tiempos (ms)
// -------------------------------
#define TIEMPO_INICIO_BUS       1000
#define TIEMPO_ENTRE_LECTURAS   500
#define TIEMPO_ENTRE_DIRECCION  10
#define TIEMPO_TEST_INICIAL     100
#define TIEMPO_ERROR_RESET      2000

// -------------------------------
// Mensajes del Serial
// -------------------------------
#define MSG_SCAN_START          "Escaneando dispositivos I2C..."
#define MSG_SCAN_FOUND          "I2C encontrado: 0x"
#define MSG_SCAN_NONE           "No se encontraron dispositivos I2C."
#define MSG_SCAN_DONE           "Escaneo finalizado."
#define MSG_SENSOR_INIT_OK      "BH1750 iniciado correctamente."
#define MSG_SENSOR_INIT_FAIL    "ERROR: BH1750 no responde."
#define MSG_LUX_LABEL           "Luz (lux): "
#define MSG_ERROR_STATE         "Entrando en estado ERROR..."

// -------------------------------
// Máquina de Estados (FSM)
// -------------------------------
enum EstadoFSM {
    ESTADO_CONFIGURACION,
    ESTADO_LECTURA,
    ESTADO_VISUALIZACION,
    ESTADO_ERROR
};

// Variables externas
extern BH1750 sensor;
extern EstadoFSM estadoActual;

// Prototipos
bool scanI2C(void);
bool initSensor(void);
float leerLux(void);
void imprimirLux(float lux);
void fsmUpdate(void);

#endif
