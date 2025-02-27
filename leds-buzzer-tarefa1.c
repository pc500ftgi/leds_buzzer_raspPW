/*
    Tarefa 1 Unidade 4 - Aula Síncrona 14/01
    Grupo 7
    Subgrupo 6
    Hebert Costa Vaz Santana - TIC370101235
    Welton Almeida de Matos - TIC370100649
    Maria Valentina da Luz Mattos Baracat Habib - TIC370101020
    Gustavo Ferreira Santos - TIC370101484
*/

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "controle_buzzer.h"
#include "controle_leds.h"
#include "ler_tecla.h"

// Definições dos pinos dos LEDs e do buzzer
#define LED_VERDE_PIN 11
#define LED_AZUL_PIN 12
#define LED_VERMELHO_PIN 13
#define BUZZER_PIN 21

// Pinos do teclado matricial
#define ROW1 2
#define ROW2 3
#define ROW3 4
#define ROW4 5
#define COL1 6
#define COL2 7
#define COL3 8
#define COL4 9

// Definições das teclas
#define TECLA_A 'A'
#define TECLA_B 'B'
#define TECLA_C 'C'
#define TECLA_D 'D'
#define TECLA_HASH '#'
#define TECLA_ESTRELA '*'

// Função de inicialização do teclado matricial
void teclado_init() {
    gpio_init(ROW1); gpio_set_dir(ROW1, GPIO_IN);
    gpio_init(ROW2); gpio_set_dir(ROW2, GPIO_IN);
    gpio_init(ROW3); gpio_set_dir(ROW3, GPIO_IN);
    gpio_init(ROW4); gpio_set_dir(ROW4, GPIO_IN);
    gpio_init(COL1); gpio_set_dir(COL1, GPIO_OUT);
    gpio_init(COL2); gpio_set_dir(COL2, GPIO_OUT);
    gpio_init(COL3); gpio_set_dir(COL3, GPIO_OUT);
    gpio_init(COL4); gpio_set_dir(COL4, GPIO_OUT);
}

int main() {
    // Configura os pinos dos LEDs e do buzzer como saída
    gpio_init(LED_VERDE_PIN); gpio_set_dir(LED_VERDE_PIN, GPIO_OUT);
    gpio_init(LED_AZUL_PIN); gpio_set_dir(LED_AZUL_PIN, GPIO_OUT);
    gpio_init(LED_VERMELHO_PIN); gpio_set_dir(LED_VERMELHO_PIN, GPIO_OUT);
    gpio_init(BUZZER_PIN); gpio_set_dir(BUZZER_PIN, GPIO_OUT);

    // Inicializa o teclado
    teclado_init();

    // Desliga tudo no início
    gpio_put(LED_VERDE_PIN, 0);
    gpio_put(LED_AZUL_PIN, 0);
    gpio_put(LED_VERMELHO_PIN, 0);
    gpio_put(BUZZER_PIN, 0);

    // Loop principal
    while (true) {
        char tecla = ler_tecla();  // Lê a tecla pressionada

        if (tecla) {  // Se uma tecla foi pressionada
            controle_leds(tecla);  // Controla os LEDs
            controle_buzzer(tecla);  // Controla o buzzer
        }

        sleep_ms(100);  // Aguarda um pouco antes de ler a próxima tecla
    }

    return 0;
}