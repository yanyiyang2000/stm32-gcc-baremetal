/* Standard library API */
#include <stdint.h>

/* Device API */
#include "stm32l476xx.h"

/* Application API */
#include "demo_common_config.h"
#include "demo_1_config.h"


/**
 * This function is the entry point of demo 1.
 */
void demo_1_enter() {
    // Configure MSI to around 48 MHz
    MSI_config();

    // Configure SysTick interrupt to be triggered every 1 ms
    SysTick_config();

    // Configure GPIO PA5 to power LED
    GPIO_PA5_config();

    while (1) {}
}
