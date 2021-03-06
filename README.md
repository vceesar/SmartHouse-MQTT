
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]





<!-- PROJECT LOGO -->
<br />
<p align="center">


  <h3 align="center">SmartHouse-MQTT</h3>

  <p align="center">
    Projeto OIC Mackenzie. Controle de Bulb através de Sensor de Som e/ou via MQTT pelos apps MQTT Tool e/ou MQTT Dash
    <br />
    <a href="https://github.com/vceesar/SmartHouse-MQTT/tree/main/Schemas"><strong>EXPLORAR IMAGENS»</strong></a><br>
     <a href="Código.md"><strong>EXPLORAR CÓDIGO»</strong></a>
    <br />
    <br />
    ·
    <a href="https://github.com/vceesar/SmartHouse-MQTT/issues">Reportar Erros :beetle: </a>
    ·
    <a href="https://github.com/vceesar/SmartHouse-MQTT/issues">Indicações e Dicas :+1: </a>
    ·
  </p>
</p>

<details open="open">
  <summary> Sumário (clique para abrir as opções) </summary>
  <ol>
    <li><a href="#licença">Licença</a></li>
    <li><a href="#contatos">Contatos</a></li>
    <li><a href="#Agradecimentos">Agradecimentos</a></li>
    <li><a href="#funcionamento-e-descrição">Funcionamento e Descrição</a></li>
    <li><a href="#software-e-documentação">Software e Documentação</a></li>
    <li><a href="#hardware-utilizado">Hardware Utilizado</a></li>
    <ul><a href="#Funções-dos-Componentes-de-Hardware"> Funções dos Componentes de Hardware </ul>
    <li><a href="#Documentação-das-interfaces-protocolos-e-módulos-de-comunicação">Software e Documentação</a></li>
    <ul><a href="#Configuração-e-Aplicação-no-MQTT-Tool">Configuração e Aplicação no MQTT Tool</a></ul>
    <ul><a href="#Configuração-e-Aplicação-no-MQTT-Dash">Configuração e Aplicação no MQTT Dash</a></ul>
    <li><a href="#Youtube-">Youtube</a></li>
    
  </ol>
</details>

## Funcionamento e Descrição

Nosso Projeto busca imergir no conceito das SmartHouses, tópico que vem crescendo absurdamente conforme o passar dos ultimos anos.
Através das Conexões Wifi MQTT, será possivel através deste, controlar sua Lâmpada 💡. Tambem será possivel, caso preferir, controla-lá localmente, ou seja, através apenas,
das detecções do som ambiente (palmas e estalos de dedo), onde via sensor de som, o sinal do Módulo Relé se alternará.

## Software e Documentação

O Software usado para programar o código necessário para o Projeto foi o proprio software do <a href="https://www.arduino.cc/en/software"> Arduino IDE </a> .

Para visualizar o Código totalmente documentado e explicado, basta <a href="Código.md"> Clicar Aqui. </a>

## Hardware Utilizado
```
1x Placa NodeMCU V3 - ESP8266
1x Arduino Uno R3
1x Módulo Relé 5V
1x Jumper Macho-Macho / Macho-Fêmea / Fêmea-Fêmea
1x Protoboard 400 Pontos (O tamanho da protoboard é opcional, quanto maior, mais possibilidade de organização).
1x Sensor de Som KY-038
1x Soquete para Lâmpada
1x Lâmpada 110W
1x Cabo Elétrico (Tamanho do cabo depende do tamanho da extensão que queira fazer).
1x Plug Macho

```
### Funções dos Componentes de Hardware

O NodeMCU ficará responsável por controlar as saídas de sinais dos sensores e atuadores e através do Arduino IDE, terá a programacao gravada em sua memória. <br>
O Arduino Uno R3 ficará responsável por controlar as tensões de 5V dos sensores e atuadores, assim como todas os GND. <br>
O Módulo Relé atuará como um interruptor, tendo os cabos elétricos conectados tanto nos sinais Comum e Normalmente aberto, onde conforme o Sinal do Sensor, irá intercalar entre eles. <br>
Todas as Conexões serão realizadas através dos Jumpers definidos no escopo. <br>
O Sensor irá atuar medindo as frequências sonoras do ambiente, e caso algum som seja detectado, irá mudar o sinal do Relé. <br>
O Soquete irá sustentar e dar energia a Lâmpada, e terá suas saídas conectadas tanto no Módulo Relé, quanto no Plug Macho conectado a Energia (*** CUIDADO ****). <br>
As ligações do Soquete no Relé, e do Soquete no Plug Macho, serão estabelecidas através do Cabo Elétrico. 

## Documentação das interfaces, protocolos e módulos de comunicação.

Neste projeto, será possível manipular a Lâmpada através do MQTT. O MQTT (Message Queuing Telemetry Transport), é um protocolo que permite a comunicação entre dispositivos através do protocolo de internet TCP/IP.

### Como funcionará detalhadamente neste Projeto? 

Através do NodeMCU (Ou qualquer outra placa de desenvolvimento que esteja dentro dos Requisitos estabelecidos) que possui o Módulo ESP2866, estabeleceremos, primeiramente, a conexão com o Wifi.
Este por sua vez,possibilitará que, possamos conectar nosso subscriber (A Placa NodeMCU) com o Broker.

O Broker é o responsável em gerir as publicações feitas ao Tópico definido, e as subscrições. Nesse caso, usaremos os Serviços do <a href = "https://www.cloudmqtt.com/"> MQTTCloud </a>. Este, possui como seu plano mais em conta, a opção Humble Hudgehog por cerga de $4.70.

<p align= "center">
<img src = "Aplicativos Mobile MQTT/MQTTCloud.png">
<p>
  
** Outra opção seria utilizar o <a href="https://io.adafruit.com/"> Adafruit </a> , que possui um plano totalmente FREE. 
Após criar a Instância e ter todos os dados necessários vindos do MQTTCloud como Host, Port, username e password, basta inserir esses dados corretamente no Código disponibilizado e carrega-lo para a respectiva Placa.

### Agora com o Broker e Código configurado, qual a proxima etapa?

A Proxima Etapa agora, é configurar o aplicativo que você irá utilizar para manipular o Atuador.  Caso você possua IOS, recomendamos o App MQTT Tool, segue o link para a App Store <a href="https://apps.apple.com/us/app/mqttool/id1085976398"> aqui. </a> </br>
Caso possua Android, utilize o <a href="https://play.google.com/store/apps/details?id=net.routix.mqttdash&hl=pt_BR&gl=US"> MQTT Dash. </a>

<hr>
<br>

### Configuração e Aplicação no MQTT Tool

Para configurar o MQTT Tool, logo na página principal do app, você deve inserir os dados fornecidos pelo Broker para estabelecer Conexão.
Após isso, basta ir na aba de Publish, inserir o Tópico definido, e a Mensagem. Em nosso caso, definimos o Tópico "controlar-lampada" e a mensagem "ligar", fazendo com que a Lâmpada acendesse. 

<p align="center">
<img src = "Aplicativos Mobile MQTT/MQTTTool_1.PNG" width=30%  height=30%> 
</p>

<p align="center">
  <img src = "Aplicativos Mobile MQTT/MQTTTool_3.PNG" width=30%  height=30%> 
</p>

<hr>
<br>

### Configuração e Aplicação no MQTT Dash

No MQTT Dash, primeiramente você deve criar um "perfil" com todos os dados fornecidos pelo Broker.
Após isso, deve-se criar um Dashboard do tipo Switch/Button, e nele inserir o Tópico, relacionar os dashboards com as mensagens (ON/OFF), definir o Quality of Service (QoS 1), etc..

<p align="center">
  <img src="Aplicativos Mobile MQTT/MQTTDash_1.jpg">
 </p>
 
 <p align="center">
  <img src="Aplicativos Mobile MQTT/MQTTDash_5.jpeg">
 </p>


## Youtube 🎥

Caso queira assistir mais sobre o Projeto, temos um vídeo que imergimos mais a fundo. <br> <a href="https://www.youtube.com/watch?v=8e-DSVdG8SU"> Clique aqui <a/> para ser redirecionado


<!-- LICENSE -->
## Licença

Distribuido sobre a Licença MIT. Veja a `LICENÇA` para mais informações.


<!-- CONTACT -->
## Contatos

Victor Cesar - 41814983           ->  41814983@mackenzista.com.br <br>
Augusto Rosasco - 31905811              ->  31905811@mackenzista.com.br    




<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/badge/CONTRIBUTORS-2-red?style=for-the-badge
[contributors-url]: #
[forks-shield]: https://img.shields.io/badge/FORKS-0.0K-red?style=for-the-badge
[forks-url]: #
[stars-shield]: https://img.shields.io/badge/STARS-0.0K-blue?style=for-the-badge
[stars-url]: https://github.com/vceesar/cortinas/stargazers
[issues-shield]: https://img.shields.io/badge/ISSUES-0%20OPEN-green?style=for-the-badge
[issues-url]: #
[license-shield]: https://img.shields.io/badge/LICENSE-MIT-red?style=for-the-badge
[license-url]: https://github.com/vceesar/cortinas/blob/master/LICENSE
[product-screenshot]: images/screenshot.png

<br>
<hr>

## Agradecimentos

Agradecimentos para o <a href="https://github.com/othneildrew/Best-README-Template/blob/master/README.md"> othneildrew repositório  </a> por compartilhar este template de layout do README para github.

Outra plataforma usada para personalização do github foi o <a href="https://shields.io/"> Shield.io </a>
