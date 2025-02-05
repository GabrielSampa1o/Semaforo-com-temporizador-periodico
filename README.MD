# 🚦 Semáforo com Temporizador Periódico

## 📌 Descrição do Projeto
Este projeto implementa um **semáforo simples** utilizando a **Raspberry Pi Pico** e um temporizador periódico para alternar entre as cores **vermelho, amarelo e verde** a cada 3 segundos. A mudança de estados ocorre automaticamente, simulando o funcionamento real de um semáforo de trânsito.

## 📋 Funcionalidades
- Alternância entre os estados **vermelho**, **amarelo** e **verde** automaticamente.
- Controle do semáforo utilizando **temporizadores periódicos**.
- Impressão de mensagens no **console serial** para monitoramento.

## 🛠️ Componentes Utilizados
- **Raspberry Pi Pico**
- **3 LEDs** (Vermelho, Amarelo e Verde)
- **3 Resistores (330Ω - 1KΩ)**
- **Jumpers e Protoboard**

## ⚙️ Pinos Utilizados
| LED       | GPIO na Pico |
|-----------|-------------|
| Vermelho  | GPIO13      |
| Amarelo   | GPIO12      |
| Verde     | GPIO11      |

## 🖥️ Estrutura do Código

### 1️⃣ **main.c** (Código Principal)
O código principal configura os pinos dos LEDs como saída e inicia um **timer periódico** que alterna as cores do semáforo a cada **3 segundos**.

### 🔄 **Funcionamento do Temporizador**
A função `semaforo_callback()` é chamada a cada 3 segundos e alterna os LEDs de acordo com o seguinte ciclo:

1. **Vermelho Ligado** (3s)
2. **Amarelo Ligado** (3s)
3. **Verde Ligado** (3s)

No loop principal, uma mensagem é impressa a cada **1 segundo** para indicar que o semáforo está em operação.

## 🚀 Como Compilar e Executar

### 🔧 **Pré-requisitos**
- **Raspberry Pi Pico SDK** instalado ([Guia Oficial](https://github.com/raspberrypi/pico-sdk))
- **CMake e Ninja** configurados
- **Compilador ARM GCC**

## Como Compilar e Rodar
### **1. Instale o Raspberry Pi Pico SDK**
Siga as instruções oficiais do SDK:
https://github.com/raspberrypi/pico-sdk

### **2. Clone este repositório**
```sh
    git clone https://github.com/GabrielSampa1o/Controle-de-Interrup-es-e-LEDs-WS2812-na-Raspberry-Pi-Pico-W.git
    cd Controle-de-Interrup-es-e-LEDs-WS2812-na-Raspberry
```

### **3. Abra o VS Code** e **importe o projeto**:
   - Vá até a **Extensão Raspberry Pi Pico**.
   - Selecione **Import Project**.
   - Escolha a pasta do repositório clonado.
   - Clique em **Import**.

### **4. Compilar o código**:
   - Utilize a opção de **Build** da extensão.

### **5. Carregue o binário na Pico**
1. Pressione e segure o **botão BOOTSEL** da Raspberry Pi Pico W.
2. Conecte-a ao PC via **USB**.
3. Copie o arquivo `.uf2` gerado para a unidade montada.

## 🎮 Demonstração do Funcionamento
Após carregar o código na **Raspberry Pi Pico**, o semáforo alternará automaticamente entre **vermelho, amarelo e verde** a cada **3 segundos**.

## 👤 Autor
- [Gabriel Silva Sampaio]

