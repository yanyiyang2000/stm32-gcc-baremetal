/* Standard library API */
#include <stdint.h>

/* CMSIS Device API */
#include "stm32l476xx.h"

/* User API */
#include "demo_1_config.h"


/**
 * This global variable is incremented by SysTick interrupt handler and is reset
 * after reaching 1000.
 */
volatile uint64_t demo_1_systick_ms = 0;

void SysTick_Handler() {
    switch (demo_1_systick_ms) {
        case 1000: {
            // Toggle GPIO port A pin 5 output
            GPIOA->ODR ^= GPIO_ODR_OD5_Msk;

            demo_1_systick_ms = 0;
            break;
        }

        default:
            demo_1_systick_ms++;
            break;
    }
}
