#include <DHT.h> //Libreria para sensor DHT11

int Humedad_Tierra_min = 60;
int Humedad_Tierra_max = 80;

#define DHTPIN 5 // Definimos el pin digital donde se conecta el sensor
#define DHTTYPE DHT11 // Dependiendo del tipo de sensor en este cado es el DHT11
DHT dht(DHTPIN, DHTTYPE); // Inicializamos el sensor DHT11

float h = 0; // Humedad relativa
float t = 0; // Temperatura en grados centígrados
float f = 0; // Temperatura en grados Fahreheit
float hif = 0; // Indice de calor en Fahreheit
float hic = 0; // Indice de calor en grados centígrados

//Variable bomba de agua
#define Bomba_Agua 4 // Definimos bomba de agua
int i = 0;

#define Sensor_LDR A2 // Difinimos sensor LDR
int Valor_LDR = 0; // Variable en la que se gauardara el valor que lea el sensor
int Valor_LDR_Porcentaje = 0; // Variable que guarda el valor que arroja el sensor en porcentaje

//Variables sensor de humedad tierra
const int Valor_SMSt_Aire = 588; // Variable constante Max valor del sensor en contacto con el aire
const int Valor_SMSt_Agua = 308; // Variable constante Min volor del sensor en contacto con el agua
int Valor_SMSt = 0; // Variable que guarda el valor que arroja el sensor en la lectura
int Valor_SMSt_Porcentaje = 0; // Variable que guarda el valor que arroja el sensor en porcentaje
