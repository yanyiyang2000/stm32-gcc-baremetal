/* Device API */
#include "stm32l476xx.h"

/* Application API */
#include "demo_common_config.h"
#include "demo_2_config.h"


/**
 * This function is the entry point of demo 2.
 */
void demo_2_enter() {
    // Configure MSI to around 48 MHz
    MSI_config();

    // Configure system timer
    SysTick_config();

    // Configure GPIO PA5 to power the LED
    GPIO_PA5_config();

    // Generate wave data
    demo_2_util_populate_wave_data();

    // Configure DMA1 channel 4
    DMA1_CH4_config();

    // Configure TIM6
    TIM6_config();

    // Configure DAC1 channel 2
    DAC1_CH2_config();

    while (1) {}
}
