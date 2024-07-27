/* Device API */
#include "stm32l476xx.h"

/* Application API */
#include "demo_3_config.h"


/**
 * This function configures GPIO PA2 as USART2 transmitter (output):
 *   - Alternate function mode          (alternate function 7)
 *   - Output push-pull                 (default)
 *   - Output speed high
 *   - No pull-up or pull-down resistor (default)
 *
 * Reference: DS10198, p.92
 */
void GPIO_PA2_config() {
    // Enable the GPIO port A AHB2 interface clock
    RCC->AHB2ENR |= 1 << RCC_AHB2ENR_GPIOAEN_Pos;
    
    // Configure GPIO port A pin 2 as alternate function mode (0b10)
    GPIOA->MODER &= ~GPIO_MODER_MODE2_Msk;
    GPIOA->MODER |= 0b10 << GPIO_MODER_MODE2_Pos;
    
    // Select alternate function 7 (0b0111) [DS10198, p.92]
    GPIOA->AFR[0] &= ~GPIO_AFRL_AFSEL2_Msk;
    GPIOA->AFR[0] |= 0b0111 << GPIO_AFRL_AFSEL2_Pos;
    
    // Set output speed to high (0b10)
    GPIOA->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED2_Msk;
    GPIOA->OSPEEDR |= 0b10 << GPIO_OSPEEDR_OSPEED2_Pos;
}


/**
 * This function configures GPIO PA3 as USART2 receiver (input):
 *   - Alternate function mode (alternate function 7)
 *   - Don't care about the rest since this is an input
 *
 * Reference: DS10198, p.92
 */
void GPIO_PA3_config() {
    // Enable the GPIO port A AHB2 interface clock
    RCC->AHB2ENR |= 1 << RCC_AHB2ENR_GPIOAEN_Pos;
    
    // Configure GPIO port A pin 3 as alternate function mode (0b10)
    GPIOA->MODER &= ~GPIO_MODER_MODE3_Msk;
    GPIOA->MODER |= 0b10 << GPIO_MODER_MODE3_Pos;
    
    // Select alternate function 7 (0b0111) [DS10198, p.92]
    GPIOA->AFR[0] &= ~GPIO_AFRL_AFSEL3_Msk;
    GPIOA->AFR[0] |= 0b0111 << GPIO_AFRL_AFSEL3_Pos;
}
