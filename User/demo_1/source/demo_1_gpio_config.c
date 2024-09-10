/* CMSIS Device API */
#include "stm32l476xx.h"

/* User API */
#include "demo_1_config.h"


/**
 * This function configures GPIO PA5 as follows:
 *   - Output mode
 *   - Output push-pull                 (default)
 *   - Output speed low                 (default)
 *   - No pull-up or pull-down resistor (default)
 *
 * @note GPIO PA5 is used to toggle the LED.
 */
void GPIO_PA5_config() {
    // Enable GPIO port A AHB2 interface clock
    RCC->AHB2ENR |= 1 << RCC_AHB2ENR_GPIOAEN_Pos;
    
    // Set mode to output mode (0b01)
    GPIOA->MODER &= ~GPIO_MODER_MODE5_Msk;
    GPIOA->MODER |= 0b01 << GPIO_MODER_MODE5_Pos;
}
