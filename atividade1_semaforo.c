#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/watchdog.h"
#include "hardware/clocks.h"
#include "hardware/uart.h"

// Definição dos GPIOs para os LEDs
#define LED_RED     13
#define LED_YELLOW  12
#define LED_GREEN   11

// Variável para indicar qual LED está ativo
static int current_light = 0; 

// Função de callback do timer periódico
bool semaforo_callback(struct repeating_timer *t) {
    switch (current_light) {
        case 0: // Vermelho ligado, demais desligados
            gpio_put(LED_RED, 1);
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 0);
            current_light = 1;
            break;
        case 1: // Amarelo ligado, demais desligados
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 1);
            gpio_put(LED_GREEN, 0);
            current_light = 2;
            break;
        case 2: // Verde ligado, demais desligados
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 1);
            current_light = 0;
            break;
    }
    return true; // Retorna 'true' para manter o timer repetindo
}

int main() {
    stdio_init_all();

    // Inicializa pinos como saída
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_YELLOW);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // Configura timer periódico de 3 segundos
    struct repeating_timer semaforo_timer;
    add_repeating_timer_ms(3000, semaforo_callback, NULL, &semaforo_timer);

    // Loop principal: imprime mensagem a cada 1 segundo
    while (true) {
        printf("Semáforo em funcionamento...\n");
        sleep_ms(1000);
    }

    return 0;
}
