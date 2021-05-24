
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

```

## Documentação das interfaces, protocolos e módulos de comunicação.

Neste projeto, será possível manipular a Lâmpada através do MQTT. O MQTT (Message Queuing Telemetry Transport), é um protocolo que permite a comunicação entre dispositivos através do protocolo de internet TCP/IP.

### Como funcionará detalhadamente neste Projeto? 

Através do NodeMCU (Ou qualquer outra placa de desenvolvimento que esteja dentro dos Requisitos estabelecidos) que possui o Módulo ESP2866, estabeleceremos, primeiramente, a conexão com o Wifi.
Este por sua vez,possibilitará que, possamos conectar nosso subscriber (A Placa NodeMCU) com o Broker.

O Broker é o responsável em gerir as publicações feitas ao Tópico definido, e as subscrições. Nesse caso, usaremos os Serviços do <a href = "https://www.cloudmqtt.com/"> MQTTCloud </a>. Este, possui como seu plano mais em conta, a opção Humble Hudgehog por cerga de $4.70.

<img src = "Aplicativos Mobile MQTT/MQTTCloud.png">

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
