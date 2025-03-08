# Reploids - Projeto com M5Stack AtomS3R

Este projeto implementa uma série de funcionalidades utilizando o **M5Stack AtomS3R**, incluindo leitura de sensores, controle de servomotores e captura de áudio. O código está estruturado em múltiplas telas que podem ser alternadas com o botão do dispositivo.

## 📁 Estrutura do Projeto

A organização do projeto segue a seguinte estrutura de diretórios:

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

## 🔧 Configuração e Instalação

### Requisitos

- **M5Stack AtomS3R**
- **PlatformIO instalado no VSCode**
- **Bibliotecas necessárias** (instaladas automaticamente pelo `platformio.ini`)

### Como Rodar

**Abra no VSCode e compile usando PlatformIO**
- No VSCode, abra a pasta do projeto e clique em **Build & Upload** para compilar e enviar o código para o M5Stack.

## 📜 Funcionalidades

### 🟢 Tela 0 - Menu Inicial
- Permite selecionar qualquer uma das telas disponíveis ao pressionar o botão.

### 🔵 Tela 1 - Visualização 3D da Inclinação
- Utiliza acelerômetro e giroscópio para exibir um cubo 3D rotacionando conforme o movimento do dispositivo.

### 🔴 Tela 2 - Outra Perspectiva 3D
- Renderiza um plano inclinado e um cubo 3D em perspectiva com movimento suave.

### 🟡 Tela 3 - Controle de Servos
- Controla um servo motor baseado nos dados do IMU.

### 🟣 Tela 4 - Captura de Áudio
- Captura áudio do microfone MEMS e exibe um medidor de volume na tela.

### ⚙️ Tela Debug
- Exibe informações sobre sensores, microfone, bateria e botões.

## 📌 Dependências
Caso esteja utilizando o **M5Stack AtomS3R**, certifique-se de que a biblioteca **M5Unified** esteja disponível:
- 🔗 [M5Unified no PlatformIO](https://registry.platformio.org/libraries/m5stack/M5Unified)

## 📌 Melhorias Futuras
- Implementação de filtros para estabilizar os valores do IMU.
- Adição de reconhecimento de voz via áudio capturado.
- Otimizações no renderizador 3D para melhorar performance.
- Implementação de filtros para suavizar em um efeito "easeing" mesmo em altas velocidades os valores dos servos

---

**Desenvolvido com 🤖 e café ☕**
