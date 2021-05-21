#include <ESP8266WiFi.h>
#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient client(espClient);

#define sensor_som    5 
#define modulo_rele    4 
boolean sinal_rele = LOW;

const char* nome_rede_wireless = "quartovictor2.4"; 
const char* senha_rede_wireless =  "victor1104"; 
const char* ServidorMQTT = "hairdresser.cloudmqtt.com"; 
const int PortaMQTT =  18306;
const char* UsuarioMQTT = "jejyanfm";
const char* SenhaMQTT = "NiYHva8hJhwH"; 
const char* TopicoSubscriberMQTT ="controlar-lampada";

void setup() {
  Serial.begin(115200); // Compátivel com o Upload Speed.
  pinMode(sensor_som, INPUT); 
  pinMode(modulo_rele, OUTPUT);
  digitalWrite(modulo_rele, sinal_rele);
  
  WiFi.begin(nome_rede_wireless, senha_rede_wireless);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    #ifdef DEBUG
    Serial.println("Tentando Estabelecer Conexão via WIFI..");
    #endif
  }
  #ifdef DEBUG
  Serial.println("Boa! Conexão foi estabelecida com sucesso ! :) ");
  #endif
 
  client.setServer(ServidorMQTT, PortaMQTT);
  client.setCallback(callback);
 
  while (!client.connected()) {
    #ifdef DEBUG
    Serial.println("Tentando Estabelecer Conexão ao Broker MQTT...");
    #endif
 
    if (client.connect("ESP32Client", UsuarioMQTT, SenhaMQTT )) {
      #ifdef DEBUG
      Serial.println("Boa! Conexão com o Broker foi estabelecida! ");  
      #endif
 
    } else {
      #ifdef DEBUG 
      Serial.print("Ocorreu algum problema .... :( ");
      Serial.print(client.state());
      #endif
      delay(2000);
 
    }
  }

  
  client.subscribe(TopicoSubscriberMQTT);
 
} 
void loop() {
  int verificasinal = digitalRead(sensor_som); 
   if(verificasinal){ 
    sinal_rele = !sinal_rele; 
    digitalWrite(modulo_rele, sinal_rele); 
    delay(1000); 
   }
    if (!client.connected()) {
    reconnect();
  }
  client.loop();

}

void reconnect() {
 
  while (!client.connected()) {
    #ifdef DEBUG
    Serial.print("Tentando conectar ao servidor MQTT");
    #endif
     
    bool conectado = strlen(UsuarioMQTT) > 0 ?
                     client.connect("ESP32Client", UsuarioMQTT, SenhaMQTT) :
                     client.connect("ESP32Client");

    if(conectado) {
      #ifdef DEBUG
      Serial.println("Conectado!");
      #endif
      
      client.subscribe(TopicoSubscriberMQTT, 1); 
    } else {
      #ifdef DEBUG
      Serial.println("Falha durante a conexão.Code: ");
      Serial.println( String(client.state()).c_str());
      Serial.println("Tentando novamente em 10 s");
      #endif
      
      delay(10000);
    }
  }
}
void callback(char* topico, byte* payload, unsigned int length) {
  payload[length] = '\0';
  String mensagemtopico = String((char*)payload);

  #ifdef DEBUG
  Serial.print("Uma mensagem acabou de ser recebida pelo Tópico: ");
  Serial.println(topico);
  Serial.print("Mensagem:");
  Serial.print(mensagemtopico);
  Serial.println();
  Serial.println("-----------------------");
  #endif

  
  if (mensagemtopico == "ligar"){ 
     sinal_rele = HIGH;  
     digitalWrite(modulo_rele, sinal_rele);  
  }
  else if (mensagemtopico = "desligar") {
     sinal_rele = LOW;
     digitalWrite(modulo_rele, sinal_rele); 
    }
}
