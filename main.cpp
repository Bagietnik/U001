#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/watchdog.h"
#include "hardware/uart.h"
#include "hardware/clocks.h"
#include "hardware/gpio.h"

#define UART_TX_PIN 0
#define UART_RX_PIN 1
#define WATCHDOG_SEC_RESET 5
#define LED_YL 16
#define LED_RD 17
#define BUTTON 20

volatile bool button_pressed = false;

void button_irq_handler(uint gpio, uint32_t events) {
    button_pressed = true;
}

int main() {
    uart_init(uart0, 115200);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    gpio_init(LED_YL);
    gpio_set_dir(LED_YL, GPIO_OUT);

    gpio_init(LED_RD);
    gpio_set_dir(LED_RD, GPIO_OUT);

    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);

    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &button_irq_handler);

    stdio_init_all();

    uint32_t system_clock_frequency = clock_get_hz(clk_sys);

    watchdog_enable(WATCHDOG_SEC_RESET * 1000000, 1);

    gpio_put(LED_YL, true);
    gpio_put(LED_RD, false);

    bool trigger = false;

    while (true) {
        if (watchdog_caused_reboot()) {
            printf("Rebooted by Watchdog!\n");
        } else {
            printf("Clean boot\n");
        }

        if (button_pressed) {
            printf("Button pressed!\n");
            gpio_put(LED_RD, true);
            trigger = true;
            button_pressed = false;
        }

            printf("\nBlinking!\r\n");
            gpio_put(LED_YL, true);
            sleep_ms(1000);
            gpio_put(LED_YL, false);
            sleep_ms(1000);

        if (!trigger) {
            watchdog_update();
        }
        
    }

    return 0;
}
