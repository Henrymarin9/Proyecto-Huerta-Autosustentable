#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#include <Arduino.h>
#include <pt.h> // Libreria para ejecutar varias acciones en simultaneo
#include "globales.h"
#include <DHT.h> //Libreria para sensor DHT11
#include <pt.h> // Libreria para ejecutar varias acciones en simultaneo

#include <Keypad.h>

const byte FILAS = 4;
const byte COLUMNAS = 4;
char keys [FILAS][COLUMNAS] = {

  {'A','B','C','D'},
  {'E','F','G','H'},
  {'I','J','K','L'},
  {'M','N','O','P'}
  
};

byte pinesFilas[FILAS] = {9,8,7,6};
byte pinesColumnas[COLUMNAS] = {10,11,12,13};

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);

char TECLA;


int temperatura_min;
int temperatura_max;
String cultivo;

void setup_Funcionalidades(){
  pinMode(Bomba_Agua, OUTPUT); //Inicializamos bomba de agua
  pinMode(Sensor_LDR, INPUT); //Inicializamos sensor LDR
  dht.begin(); // Comenzamos el sensor DHT

}

void setup_lcd(){
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(1,0);
  lcd.print("SOY TU HUERTA");
  delay (1500);
  lcd.clear();
  
  lcd.setCursor(2,1);
  lcd.print("INTELIGENTE");
  delay (1500);
  lcd.clear();

  lcd.setCursor(2,0);
  lcd.print("CUIDEMOS EL");
  lcd.setCursor(4,1);
  lcd.print("PLANETA");
  delay (2000);
  lcd.clear();

  while(TECLA != 'A' and TECLA != 'B' and TECLA != 'C' and TECLA != 'D' and TECLA != 'F' and TECLA != 'G' and TECLA != 'H' and TECLA != 'I' and TECLA != 'J' and TECLA != 'K' and TECLA != 'M' and TECLA != 'N' and TECLA != 'O' and TECLA != 'P'){
      lcd.setCursor(2,0);
      lcd.print("Elige que");
      lcd.setCursor(2,1);
      lcd.print("Cultivar");

      TECLA = teclado.getKey();
    }
  lcd.clear();
  if(TECLA == 'A'){
    // A = Romero
    cultivo = "Romero";
    lcd.setCursor(0,0);
    lcd.print(cultivo);
    delay(2000);
    lcd.clear();
    
    temperatura_min = 20;
    temperatura_max = 30;

    return cultivo;
    }
    
  if(TECLA == 'B'){
    // B = Albahaca
    cultivo = "Albahaca";
    lcd.setCursor(0,0);
    lcd.print(cultivo);
    delay(2000);
    lcd.clear();
    
    temperatura_min = 20;
    temperatura_max = 25;

    return cultivo;
    }

  if(TECLA == 'C'){
    // C = Cilantro
    cultivo = "Cilantro";
    lcd.setCursor(0,0);
    lcd.print(cultivo);
    delay(2000);
    lcd.clear();
    
    temperatura_min = 25;
    temperatura_max = 30;
    
    return cultivo;
    }

  if(TECLA == 'D'){
    // D = Oregano
    cultivo = "Oregano";
    lcd.setCursor(0,0);
    lcd.print(cultivo);
    delay(2000);
    lcd.clear();
    
    temperatura_min = 20;
    temperatura_max = 25;

    return cultivo;
    }

  if(TECLA == 'E'){
    // E = Perejil
    cultivo = "Perejil";
    lcd.setCursor(0,0);
    lcd.print(cultivo);
    delay(2000);
    lcd.clear();
    
    temperatura_min = 20;
    temperatura_max = 25;

    return cultivo;
    }

  if(TECLA == 'F'){
    // F = Tomillo
    cultivo = "Tomillo";
    lcd.setCursor(0,0);
    lcd.print(cultivo);
    delay(2000);
    lcd.clear();
    
    temperatura_min = 20;
    temperatura_max = 30;

    return cultivo;
    }

  if(TECLA == 'G'){
    // G = Ciboulett
    cultivo = "Ciboulett";
    lcd.setCursor(0,0);
    lcd.print("Ciboulett");
    delay(2000);
    lcd.clear();
    
    temperatura_min = 13;
    temperatura_max = 23;

    return cultivo;
    }

  if(TECLA == 'H'){
    // H = Menta
    cultivo = "Menta";
    lcd.setCursor(0,0);
    lcd.print(cultivo);
    delay(2000);
    lcd.clear();
    
    temperatura_min = 13;
    temperatura_max = 21;
    return cultivo;
    }

  if(TECLA == 'I'){
    // I = Setas
    cultivo = "setas";
    lcd.setCursor(0,0);
    lcd.print(cultivo);
    delay(2000);
    lcd.clear();
    
    temperatura_min = 12;
    temperatura_max = 14;

    return cultivo;
    }

  if(TECLA == 'J'){
    // J = Esparragos
    cultivo = "Esparragos";
    lcd.setCursor(0,0);
    lcd.print(cultivo);
    delay(2000);
    lcd.clear();
    
    temperatura_min = 20;
    temperatura_max = 25;

    return cultivo;
    }

  if(TECLA == 'K'){
    // K = Puerro
    cultivo = "Puerro";
    lcd.setCursor(0,0);
    lcd.print(cultivo);
    delay(2000);
    lcd.clear();
    
    temperatura_min = 16;
    temperatura_max = 25;

    return cultivo;
    }
    
  if(TECLA == 'L'){
    // L = Tomate
    cultivo = "Tomate";
    lcd.setCursor(0,0);
    lcd.print(cultivo);
    delay(2000);
    lcd.clear();
    
    temperatura_min = 25;
    temperatura_max = 30;
    return cultivo;
    }
    
  if(TECLA == 'M'){
    // M = Lechuga
    cultivo = "Lechuga";
    lcd.setCursor(0,0);
    lcd.print(cultivo);
    delay(2000);
    lcd.clear();
    
    temperatura_min = 15;
    temperatura_max = 20;

    return cultivo;
    }

  if(TECLA == 'N'){
    // N = Cebolla
    cultivo = "Cebolla";
    lcd.setCursor(0,0);
    lcd.print(cultivo);
    delay(2000);
    lcd.clear();
    
    temperatura_min = 20;
    temperatura_max = 25;

    return cultivo;
    }
    
  if(TECLA == 'O'){
    // O = Papa
    cultivo = "Papa";
    lcd.setCursor(0,0);
    lcd.print(cultivo);
    delay(2000);
    lcd.clear();
    
    temperatura_min = 17;
    temperatura_max = 23;
    return cultivo;
    }
    
  if(TECLA == 'P'){
    // P = RESET
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("RESET");
    delay(2000);
    
    }

}
void loop_lcd(){
    lcd.setCursor(0,0);
    lcd.print(cultivo);

    lcd.setCursor(12,0);
    if (Valor_SMSt_Porcentaje < 0){
      lcd.print("0");
      lcd.setCursor(15,0);
      lcd.print("%");
      }else if (Valor_SMSt_Porcentaje > 100){
        lcd.print("100%");
      }else {
         lcd.print(Valor_SMSt_Porcentaje);
         lcd.setCursor(15,0);
         lcd.print("%");
      }
    
    lcd.setCursor(9,1);
    lcd.print(t);
    lcd.print(" C");
  }

void Sensor_H_Tierra(struct pt *pt){
  PT_BEGIN(pt); // Inicia ProtoThreads
  // void setup(){
  static long tiempo = 0; // Inicializo variable tiempo
  //}

  do{
    // void loop(){
    tiempo = millis();  // Defino variable tiempo
    
    // SENSOR Soil Moisture v2.O
 
    Valor_SMSt = analogRead(A0);  //Lectura del sensor de humedad tierra
    Valor_SMSt_Porcentaje = map(Valor_SMSt, Valor_SMSt_Aire, Valor_SMSt_Agua, 0, 100); // Pasaje de valor analogo a porcentual


  //Serial.println(Valor_Sensor);   

  if (Valor_SMSt_Porcentaje >= 100) {
      
      Serial.print("Porcentaje de humedad de la tierra: ");
      Serial.println("100 %");
      

      
  } else if (Valor_SMSt_Porcentaje <=0) {
    
      Serial.print("Porcentaje de humedad de la tierra: ");
      Serial.println("0 %");

     
  } else if (Valor_SMSt_Porcentaje >0 and Valor_SMSt_Porcentaje < 100) {
    
      Serial.print("Porcentaje de humedad de la tierra: ");
      Serial.print(Valor_SMSt_Porcentaje);
      Serial.println("%");

  }
  PT_WAIT_WHILE(pt, (millis()-tiempo)<5000); // = delay(5000); pero con la libreria <pt.h>
  lcd.clear();
    //}
    }while(true);
    PT_END(pt); // Finaliza ProtoThreads
  
}

void Sensor_DHT11(struct pt *pt){
  PT_BEGIN(pt); // Inicia ProtoThreads

  // void setup(){
  
  static long tiempo = 0; // Inicializo variable tiempo
  //}

  do{
    // void loop(){
    tiempo = millis(); // Defino variable tiempo 
    
    //SENSOR HUMEDAD TEMPERATURA AMBIENTE DHT11
  
  h = dht.readHumidity(); // Leemos la humedad relativa
  t = dht.readTemperature(); // Leemos la temperatura en grados centígrados (por defecto)
  f = dht.readTemperature(true); // Leemos la temperatura en grados Fahreheit
  hif = dht.computeHeatIndex(f, h); // Calcular el índice de calor en Fahreheit
  hic = dht.computeHeatIndex(t, h, false); // Calcular el índice de calor en grados centígrados
  
  

  // Comprobamos si ha habido algún error en la lectura 
  if (isnan(h) || isnan(t) || isnan(f)) {
    
    //el isnan se utiliza para comprobar que sea correcto el dato obtenido
    Serial.println("Error obteniendo los datos del sensor DHT11");
    
  } else {

    
    // Se imprime en el Serial los datos obtenidos del sensor DHT11
    Serial.println("-----------------------------------------------"); // Salto de linea
    
    Serial.print("Humedad del ambiente: ");
    Serial.print(h);
    Serial.println("%");
  
    Serial.print("Temperatura en °C: ");
    Serial.print(t);
    Serial.println("°C");
  
    Serial.print("Temperatura en °F: ");
    Serial.print(f);
    Serial.println("°F");
  
    Serial.print("Índice de calor en °C: ");
    Serial.print(hic);
    Serial.println("°C");
  
    Serial.print("Índice de calor en °F: ");
    Serial.print(hif);
    Serial.println("°F");
    }
    PT_WAIT_WHILE(pt, (millis()-tiempo)<5000); // = delay(5000); pero con la libreria <pt.h>
    //}
    
  }while(true);
   PT_END(pt);// Finaliza ProtoThreads
}

void Sensor_LDR_funcion(struct pt *pt){
  PT_BEGIN(pt); // Inicia ProtoThreads

  // void setup(){
  static long tiempo = 0; // Inicializo variable tiempo
  //}

  do{
    // void setup(){
    tiempo = millis(); // Defino variable tiempo
    
    // SENSOR LDR 
    Valor_LDR = analogRead(A2);  //Lectura del sensor LDR
    Valor_LDR_Porcentaje = map(Valor_LDR, 0, 1023, 0, 100); // Pasaje de valor analogo a porcentual
    
  if (Valor_LDR_Porcentaje >= 100) {
    
      Serial.print("Porcentaje de luz: ");
      Serial.println("100 %");
      
  } else if (Valor_LDR_Porcentaje <=0) {
    
      Serial.print("Porcentaje de luz: ");
      Serial.println("0 %");
     
  } else if (Valor_LDR_Porcentaje >0 and Valor_LDR_Porcentaje < 100) {
    
      Serial.print("Porcentaje de luz: ");
      Serial.print(Valor_LDR_Porcentaje);
      Serial.println("%");
  }
  PT_WAIT_WHILE(pt, (millis()-tiempo)<5000); // = delay(5000); pero con la libreria <pt.h>

    //}
    }while(true);
    PT_END(pt); // Finaliza ProtoThreads
}

void Secuencias(struct pt *pt) {
  PT_BEGIN(pt); // Inicia ProtoThreads
  
  // void setup() {
  static long tiempo = 0; // Inicializo variable tiempo
  
  // }

  do{
    // void loop(){
    tiempo = millis(); // Defino variable tiempo
    
      if (Valor_SMSt_Porcentaje >= Humedad_Tierra_min and Valor_SMSt_Porcentaje <= Humedad_Tierra_max) {
        digitalWrite(Bomba_Agua, LOW);
        Serial.println("HUMEDAD EN TIERRA CORRECTA PARA EL CRECIMIENTO");

         PT_WAIT_WHILE(pt, (millis()-tiempo)<5000); // = delay(5000); pero con la libreria <pt.h>   
      }

      else if (Valor_SMSt_Porcentaje < Humedad_Tierra_min) {
         Serial.println("HUMEDAD EN TIERRA BAJA");
    
         
              for (i = 0; i <= 10; i ++) {
                digitalWrite(Bomba_Agua, HIGH);
                Serial.print("Regando: ");
                Serial.print(10 - i);
                Serial.println("s");
                delay(1000); 
              }
       
        PT_WAIT_WHILE(pt, (millis()-tiempo)<10000); // = delay(5000); pero con la libreria <pt.h>
       
        
        Serial.println("Finalizacion de riego");
        digitalWrite(Bomba_Agua, LOW);
        PT_WAIT_WHILE(pt, (millis()-tiempo)<86400000); // = delay(600000); pero con la libreria <pt.h> es = a 24h
              
           

      PT_WAIT_WHILE(pt, (millis()-tiempo)<5000); // = delay(5000); pero con la libreria <pt.h>
      }
  
      else if (Valor_SMSt_Porcentaje > Humedad_Tierra_max) {
      
         Serial.println("HUMEDAD EN TIERRA ELEVADA");

      PT_WAIT_WHILE(pt, (millis()-tiempo)<5000); // = delay(5000); pero con la libreria <pt.h>
      }

    
    // }
  }while(true);
  PT_END(pt); // Finaliza ProtoThreads
}
