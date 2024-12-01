Projeto: Sistema de Monitoramento e Controle de Nível de Água com MQTT


1. Funcionamento e Uso:

Este projeto implementa um sistema de monitoramento e controle automatizado do nível de água em um reservatório. Ele utiliza um sensor ultrassônico para medir o nível da água, um relé para acionar uma bomba d'água, e a comunicação via protocolo MQTT para transmitir os dados e controlar o sistema remotamente. O sistema é escalável e pode ser adaptado para diversos contextos, como gestão industrial ou doméstica.

Como Usar:
Conecte os componentes conforme o diagrama fornecido.
Suba o código no Arduino Nano e no ESP32.
Configure o broker MQTT para receber e publicar mensagens no tópico configurado (sensor/agua).
Utilize um cliente MQTT para monitorar ou enviar comandos.


2. Software Desenvolvido e Documentação

O projeto inclui dois códigos:
Arduino: Responsável pela leitura do sensor ultrassônico (HC-SR04) e envio dos dados para o ESP32 via comunicação serial.
ESP32: Gerencia a comunicação com o broker MQTT e o acionamento do relé.

Principais Funcionalidades:
Leitura contínua do sensor ultrassônico.
Envio dos dados via protocolo MQTT.
Controle remoto do relé para ativar/desativar a bomba.
Estrutura de Pastas no Repositório:

/arduino/: Código para o Arduino Nano.
/esp32/: Código para o ESP32, incluindo configuração do MQTT.


3. Hardware Utilizado

Plataformas de Desenvolvimento:
Arduino Nano: Processa as leituras do sensor HC-SR04.
ESP32: Gerencia a comunicação MQTT e controla o relé.

Sensores:
HC-SR04: Sensor ultrassônico para medição de distância.

Atuadores:
Relé JQC3F-05VDC-C: Controla a bomba d'água (5V).
Bomba d'água: Alimentada com 5V para o controle do nível de água.

Outros Componentes:
Divisor de tensão: Reduz o sinal de 5V do Arduino para 3.3V no RX do ESP32.
Protoboard e jumpers: Para conexões temporárias.
Fonte de alimentação: 5V, compartilhada entre os componentes.

4. Documentação das Interfaces, Protocolos e Módulos de Comunicação

Protocolo MQTT:
Tópico de publicação: sensor/agua.
Dados publicados: Nível de água em centímetros.
Controle do relé via comandos no MQTT (ex.: ligar_bomba ou desligar_bomba).

Interfaces:
Comunicação Serial: Entre Arduino Nano e ESP32 (pinos TX/RX).
Comunicação Wi-Fi: O ESP32 conecta-se ao broker MQTT pela rede local.

Requisitos de Configuração:
Broker MQTT rodando na rede local (no projeto utilizado Mosquitto).
Configuração de SSID e senha da rede Wi-Fi no código do ESP32.


5. Comunicação e Controle via Internet

O projeto utiliza o protocolo MQTT, que opera sobre TCP/IP, permitindo a transmissão de dados de forma leve e eficiente. Isso possibilita:
Monitoramento remoto do nível de água.
Controle remoto do relé para ativar/desativar a bomba.
O sistema é compatível com qualquer broker MQTT (ex.: Mosquitto, HiveMQ) e pode ser integrado a dashboards ou sistemas IoT para visualização gráfica.
