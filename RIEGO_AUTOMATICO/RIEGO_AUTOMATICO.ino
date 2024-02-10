
#include <pt.h> // Libreria para ejecutar varias acciones en simultaneo

#include "Funcionalidades.h"

struct pt hilo1; // Accion 1 lectura del DHT11
struct pt hilo2; // Accion 2 lectura sensor de humedad suelo
struct pt hilo3; // Accion 3 lecura sensor LDR
struct pt hilo4; // Accion 4 lectura sensor nivel del agua
struct pt hilo5; // Accion 5 controlador nivel del agua




void setup() {
  Serial.begin(9600); // Inicializamos comunicación serie
  
  
  setup_Funcionalidades();
  setup_lcd();
  
  PT_INIT(&hilo1); // Inicializacion de Accion 1
  PT_INIT(&hilo2); // Inicializacion de Accion 2
  PT_INIT(&hilo3); // Inicializacion de Accion 3
  PT_INIT(&hilo4); // Inicializacion de Accion 4
  PT_INIT(&hilo5); // Inicializacion de Accion 5

  
  
}

void loop() {
    loop_lcd();
    Sensor_DHT11(&hilo1);
    Sensor_H_Tierra(&hilo2); // Llamo a la funcion Sensor_H_Tierra
    Sensor_LDR_funcion(&hilo3); // Llamo a la funcion Sensor_LDR_funcion
    Secuencias(&hilo5); // Llama a la funcion que se encarga de las posibles secuencias
    
    


}
