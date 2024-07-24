/* Standard library API */
#include <stdint.h>

/* Device API */
#include "stm32l476xx.h"
#include "core_cm4.h"

/* Application API */
#include "demo_3_config.h"


/**
 * This function configures USART2 as 115200-8-N-1, namely:
 *   - Baud rate : 115200
 *   - Data bits : 8
 *   - Parity bit: None
 *   - Stop bits : 1
 */
void USART2_config() {
    // Disable USART2
    USART2->CR1 &= ~USART_CR1_UE_Msk;

    // Enable USART2 interrupt
    NVIC_EnableIRQ(USART2_IRQn);

    // Enable USART2 APB1 interface clock
    RCC->APB1ENR1 |= 1 << RCC_APB1ENR1_USART2EN_Pos;

    // Set USART2 baud rate to 115200
    USART2->BRR = (uint16_t)(SystemCoreClock / 115200);

    // Set USART2 data bits to 8 (M1 = 0, M0 = 0)
    USART2->CR1 &= ~USART_CR1_M1_Msk;
    USART2->CR1 &= ~USART_CR1_M0_Msk;

    // Set USART2 stop bits to 1 (0b00)
    USART2->CR2 &= ~USART_CR2_STOP_Msk;

    // Enable USART2 receiver
    USART2->CR1 |= 1 << USART_CR1_RE_Pos;

    // Enable USART2 transmitter
    USART2->CR1 |= 1 << USART_CR1_TE_Pos;

    // Enable RXNE (receiver not empty) interrupt
    // USART2->CR1 |= 1 << USART_CR1_RXNEIE_Pos;

    // Enable USART2
    USART2->CR1 |= 1 << USART_CR1_UE_Pos;
}
