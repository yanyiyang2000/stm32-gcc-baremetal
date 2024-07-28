/* Standard library API */
#include <stdint.h>

/* Device API */
#include "stm32l476xx.h"

/* Application API */
#include "demo_4_config.h"


/**
 * This global variable indicates current time since boot up in milliseconds.
 * 
 * Note: This variable is incremented by SysTick interrupt handler.
 */
volatile uint64_t demo_4_systick_ms = 0;

void SysTick_Handler() {
    demo_4_systick_ms += 1;
}
