```
// Projeto SmartHouse OIC
// Grupo:  Victor Cesar   e   Augusto Rosasco
// Créditos : Projeto baseado no artigo da Plataforma Embarcados que disponibilizou a documentação do projeto e código. Ambos bem explicados.

#include <ESP8266WiFi.h>        // Definição da Biblioteca ESP8266 
#include <PubSubClient.h>       // Definição da Biblioteca PubSubClient que permite a comunicação (receber e enviar) com o protocolo MQTT.

WiFiClient espClient;
PubSubClient client(espClient);
                                            // Definição das Variaveis usadas para conexão com o WIFI e MQTT Cloud
#define sensor_som    5                     // Definição das Variaveis para guardar as pinagens e sinal do sensor e modulo relé
#define modulo_rele    4 
boolean sinal_rele = LOW;

const char* nome_rede_wireless = "quartovictor2.4"; 
const char* senha_rede_wireless =  "victor1104";                         // Definição dos dados necessarios para conexão WIFI (nome da rede e senha)
const char* ServidorMQTT = "hairdresser.cloudmqtt.com";                 // Definição dos dados necessarios para conexão com o Broker.
const int PortaMQTT =  18306;
const char* UsuarioMQTT = "jejyanfm";
const char* SenhaMQTT = "NiYHva8hJhwH"; 
const char* TopicoSubscriberMQTT ="controlar-lampada";

void setup() {
  Serial.begin(115200);                                              // Definição do Serial, e pinagens de saída e entrada.
  pinMode(sensor_som, INPUT);                                                        
  pinMode(modulo_rele, OUTPUT);
  digitalWrite(modulo_rele, sinal_rele);
  
  WiFi.begin(nome_rede_wireless, senha_rede_wireless);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    #ifdef DEBUG
    Serial.println("Tentando Estabelecer Conexão via WIFI..");                         // Tenta Estabelecer Conexão com o Wifi
    #endif
  }
  #ifdef DEBUG
  Serial.println("Boa! Conexão foi estabelecida com sucesso ! :) ");
  #endif
 
  client.setServer(ServidorMQTT, PortaMQTT);                          // Estabelece Conexão com o Broker e chama a função de CallBack.
  client.setCallback(callback);
 
  while (!client.connected()) {
    #ifdef DEBUG
    Serial.println("Tentando Estabelecer Conexão ao Broker MQTT...");                    // Estrutura de Repetição responsável por verificar se está conectado, e               
    #endif                                                                               // caso não esteja, tenta estabelecer a conexão com o Broker.
 
    if (client.connect("ESP32Client", UsuarioMQTT, SenhaMQTT )) {
      #ifdef DEBUG
      Serial.println("Boa! Conexão com o Broker foi estabelecida! ");  
      #endif
 
    } else {
      #ifdef DEBUG 
      Serial.print("Ocorreu algum problema .... :( ");                                // Mensagem de erro e printa o estado.
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
    sinal_rele = !sinal_rele;                                          // Funcao Loop responsavél por verificar através do sensor, mudanças de sinais e respectivamente,
    digitalWrite(modulo_rele, sinal_rele);                             // alternar o sinal do Relé, fazendo assim, com que a Lâmpada apague ou acenda. 
    delay(1000); 
   }
    if (!client.connected()) {
    reconnect();                                    // Caso não esteja conectado, chama a função reconnect definida abaixo.
  }
  client.loop();

}

void reconnect() {
 
  while (!client.connected()) {                                         // Função reconnect responsavel por estabelecer reconexão com o Broker caso ocorra alguma Falha.
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
      
      client.subscribe(TopicoSubscriberMQTT, 1);                             // Caso a conexão seja reestabelecida, estabelece inscrição no tópico definido no Escopo.
    } else {
      #ifdef DEBUG
      Serial.println("Falha durante a conexão.Code: ");
      Serial.println( String(client.state()).c_str());                       // Caso ocorra uma Falha, Tenta estabelecer conexão novamente.
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
  Serial.print("Uma mensagem acabou de ser recebida pelo Tópico: ");                 // Printa o respectivo tópico e a mensagem recebida (ligar ou desligar).
  Serial.println(topico);
  Serial.print("Mensagem:");
  Serial.print(mensagemtopico);
  Serial.println();
  Serial.println("-----------------------");
  #endif

  
  if (mensagemtopico == "ligar"){ 
     sinal_rele = HIGH;  
     digitalWrite(modulo_rele, sinal_rele);                            // Caso a mensagens recebida no Tópico seja compátivel tanto com ligar ou desligar, o sinal do relé irá mudar de
  }                                                                    // acordo com a respectiva variável.
  else if (mensagemtopico = "desligar") {
     sinal_rele = LOW;
     digitalWrite(modulo_rele, sinal_rele); 
    }
}
```