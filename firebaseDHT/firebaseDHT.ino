  // ********************************************
  // Programa: Sensor de Temperatura e Umidade
  // Versao: 1.0.1
  // Developer: Neiberth Lucena
  // Data: 12/02/2020
  // ********************************************
  
  // **** BIBLIOTECAS ****
  #include <FirebaseArduino.h>                            //  biblioteca usada para comunicacao com firebase
  #include "DHT.h"                                        //  biblioteca usada pra ler o sensor DHT11
  #include <ESP8266WiFi.h>                                //  biblioteca usada para fazer a comunicacao com o WIFI

  // **** CONSTANTES ****
  #define FIREBASE_HOST "nodemcuauto.firebaseio.com"      //  endereco do firebase
  #define WIFI_SSID "2G_NetVirtua_119"                    //  nome da rede WIFI
  #define WIFI_PASSWORD "0148735840"                      //  senha da rede WIFI

  // **** DEFINI O TIPO DO SENSOR
  #define DHTTYPE DHT11                                   //  modelo do sensor DHT11

  // **** DECLARACAO DOS PINOS USADOS ****
  #define DHTPIN D3                                       //  declaracao do pino D3 para o DHT
  
  float h;
  float t;

  DHT dht(DHTPIN, DHTTYPE);
  
  void setup() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while(WiFi.status() != WL_CONNECTED){
      delay(500);
      Serial.print(".");  
    }
    dht.begin();

    Serial.println("");
    Serial.println("WiFi Conectado!");
    Firebase.begin(FIREBASE_HOST);
  
  }
  
  void loop() {
    h = dht.readHumidity();
    t = dht.readTemperature();

    Firebase.setFloat ("Sensores/Temperatura",t);
    Firebase.setFloat ("Sensores/Umidade",h);
    
    delay(200);  
  }
