# Reploids

Este projeto implementa uma série de funcionalidades utilizando o **M5Stack AtomS3R**, incluindo leitura de sensores, controle de servomotores e captura de áudio. O código está estruturado em múltiplas telas que podem ser alternadas com o botão do dispositivo.


## Funções Implementadas

- Tela 1: Renderização 3D do cubo com perspectiva baseada no IMU.
- Tela 2: Malha inferior com efeito de profundidade.
- Tela 3: Controle de servos baseado no IMU.
- Tela 4: Captura de áudio e visualização do nível de som.
- Tela Debug: Exibe dados gerais dos sensores e verifica o funcionamento dos módulos.


## Melhorias Futuras
- Melhorar a suavização dos dados do giroscópio/acelerômetro.
- Testar integração com APIs externas para reconhecimento de fala.
- Otimizações no renderizador 3D para melhorar performance.
- Implementação de filtros para suavizar em um efeito "easeing" mesmo em altas velocidades os valores dos servos
- Expandir o debug para testar Wi-Fi e comunicação serial.

---
.

.

**Mantenha o repositório atualizado e compartilhe melhorias!**

**Desenvolvido com 🤖 e café ☕**

.

.

# Lista de Componentes Eletrônicos

| **Categoria**       | **Descrição** |
|---------------------|--------------|
| **Microcontroladores** | ESP32-S3-WROOM-1 N16R8 |
| **Placas & Shields** | M5Stack AtomS3R, M5Stack Atomic Echo Base |
| **Sensores & Entradas** | 3x Encoder Rotativo (KY-040), Sensor de Câmera Seeed Studio XIAO OV2640 |
| **Áudio** | Microfone MEMS MSM381A3729H9BPC, Codec de áudio ES8311, Amplificador NS4150B, Alto-falante 1W@8Ω |
| **Atuadores** | 9x Servomotores MG90S, Driver PCA9685 (16 canais), 4x Mini N20 Gear Motor, 4x Motor TT duplo DC 3-6V (200rpm) |
| **Displays** | LCD Tensar Robots (240x240), e-paper Waveshare (296x160), Tela OLED 1.3'' com Knob EC11, Tela LCD TFT 1.47'' IPS ST7789 |
| **Energia & Alimentação** | Fonte de bancada Wanptek GA3010B (30V, 10A), 10x módulos TP4056 USB-C, 2x Baterias 500mAh (602040) |
| **Conectores & Protótipos** | Placa de expansão 44 pinos para ESP32, 840 jumpers, 100 plugs Dupont, Kit de conectores U-crimp 100 peças, 50 conjuntos de terminais de crimpagem 4.0mm |
| **Fios & Cabos** | 5 cores mix kit fio de silicone 22AWG, 10m fio 22AWG transparente, 127 peças de tubo termo retrátil 2:1 |
| **Sensores Especiais** | Módulo ultrassônico JSN-SR04T (à prova d'água), Grove Vision AI v2 Kit |
| **Módulos & Comunicação** | NRF24L01+ PA+LNA (2.4GHz, longo alcance 1100m) |
| **Bomba de Água** | Bomba submersível mini DC 3V/5V, Bomba USB 5V 2.4W ultra silenciosa |
| **Componentes Passivos** | **Ver tabela abaixo** |

## **Kit de Componentes Eletrônicos (1818 pcs)**

| **Categoria** | **Valores & Quantidade** |
|--------------|--------------------------|
| **Resistores (1000 pcs)** | 50 valores diferentes (20 unidades por valor), de **0Ω a 10MΩ** |
| **Capacitores (310 pcs)** | 31 valores diferentes (10 unidades por valor), de **1pF a 0.1uF (104)** |
| **Transistores (170 pcs)** | 16 tipos diferentes (10 unidades por valor) incluindo **S9012, S9013, C945, 2N3904, A1015** |
| **Eletrolíticos (120 pcs)** | 16V-50V, de **0.22uF a 470uF** |
| **LEDs (200 pcs)** | 5 cores (Vermelho, Verde, Azul, Amarelo, Branco), **5mm & 3mm (20 unidades cada)** |
| **Diodos (102 pcs)** | **1N4148, 1N4007, FR107, 1N5819** e outros |
| **Circuitos Integrados (ICs)** | **LM358, NE555, JRC4558** (2 unidades cada) |
| **Potenciômetros** | 12 valores diferentes (100Ω a 1MΩ) |
| **PCBs & Conectores** | 4 placas protótipo (2*8, 4*6, 5*7, 7*9 cm), **Jack DC 5.5x2.1mm**, Mini alto-falante 0.25W 8Ω |

---

Se precisar adicionar mais componentes no futuro, basta atualizar a tabela! 🚀🔧.

.

# 🔧 Configuração e Instalação

A organização do projeto segue a seguinte estrutura de diretórios:

```html
Reploids/
│-- src/
│   │-- main.cpp           # Arquivo principal
│   │-- tela1.cpp          # Renderização 3D do cubo e fundo
│   │-- tela2.cpp          # Renderização da malha inferior
│   │-- tela3.cpp          # Simulação de servos motores
│   │-- tela4.cpp          # Captura de áudio e análise
│   │-- tela_debug.cpp     # Tela de debug para checagem de sensores
│   │-- utils/
│   │   │-- utils_3d.cpp   # Funções auxiliares para renderização 3D
│   │   │-- utils_servos.cpp # Funções auxiliares para controle de servos
│   │   │-- utils_audio.cpp  # Funções auxiliares para captura de áudio
│   │-- headers/
│   │   │-- utils_3d.h      # Definições das funções 3D
│   │   │-- utils_servos.h  # Definições das funções de servo
│   │   │-- utils_audio.h   # Definições das funções de áudio
│-- .pio/                  # Diretório do PlatformIO (gerado automaticamente)
│-- platformio.ini         # Configurações do PlatformIO
│-- README.md
```


### Requisitos

- **M5Stack AtomS3R**
- **PlatformIO instalado no VSCode**
- **Bibliotecas necessárias** (instaladas automaticamente pelo `platformio.ini`)


## Dependências
Caso esteja utilizando o **M5Stack AtomS3R**, certifique-se de que a biblioteca **M5Unified** esteja disponível:
- 🔗 [M5Unified no PlatformIO](https://registry.platformio.org/libraries/m5stack/M5Unified)




## Autores

- [@hericdk](https://www.github.com/hericdk)

