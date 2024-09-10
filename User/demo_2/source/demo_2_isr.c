/* CMSIS Device API */
#include "stm32l476xx.h"

/* User API */
#include "demo_2_config.h"

/**
 * This global variable indicates current time since boot up in milliseconds.
 * 
 * Note: This variable is incremented by SysTick interrupt handler.
 */
volatile uint64_t demo_2_systick_ms = 0;

void SysTick_Handler() {
    demo_2_systick_ms += 1;
}
