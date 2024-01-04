#include "stm32l476xx.h"

#include "interrupt.h"

volatile uint64_t SysTick_ms = 0;

void SysTick_Handler() {
	if (SysTick_ms == 1000) {
		// Toggle GPIO port A pin 5 output
		if ((GPIOA->ODR & GPIO_ODR_OD5_Msk) == 0) {
			GPIOA->ODR |= 1 << GPIO_ODR_OD5_Pos;
		} else {
			GPIOA->ODR &= 0 << GPIO_ODR_OD5_Pos;
		}
		SysTick_ms = 0;
	} else {
		SysTick_ms++;
	}
	
	//SysTick_ms == 1000 ? SysTick_ms = 0 : SysTick_ms++;
}

volatile uint8_t msg[100] = {0};
volatile uint8_t tx_cnt = 0;
volatile uint8_t rx_cnt = 0;

void USART2_IRQHandler() {
	/* A byte is received */
	if ( (USART2->ISR & USART_ISR_RXNE_Msk) == USART_ISR_RXNE_Msk ) {
		msg[rx_cnt++] = USART2->RDR; /* This clears RXNE flag */

		// Enable USART IDLE flag
    	USART2->CR1 |= 1 << USART_CR1_IDLEIE_Pos;
	}

	/* All bytes are received, prepare for echoing */
	if ( (USART2->ISR & USART_ISR_IDLE_Msk) == USART_ISR_IDLE_Msk ) {
		// Disable USART2 receiver
		USART2->CR1 &= ~USART_CR1_RE_Msk;

		// Disable USART2 IDLE interrupt
		USART2->CR1 &= ~USART_CR1_IDLEIE_Msk;

		// Clear IDLE flag
		USART2->ICR |= 1 << USART_ICR_IDLECF_Pos;

		// Enable USART2 transmitter
		USART2->CR1 |= 1 << USART_CR1_TE_Pos;

		// Enable USART2 TXE interrupt
		USART2->CR1 |= 1 << USART_CR1_TXEIE_Pos;
	}

	/* A byte can be transmitted */
	if ( (USART2->ISR & USART_ISR_TXE_Msk) == USART_ISR_TXE_Msk ) {
		if (tx_cnt < rx_cnt) {
			USART2->TDR = msg[tx_cnt++]; /* This clears TXE flag */
		} else {
			/* All bytes are transmitted, preparing for listening */

			// Reset byte counter
			tx_cnt = 0;
			rx_cnt = 0;

			// Disable USART2 transmitter
			USART2->CR1 &= ~USART_CR1_TE_Msk;

			// Disable USART2 TXE interrupt
			USART2->CR1 &= ~USART_CR1_TXEIE_Msk;

			// Enable USART2 receiver
			USART2->CR1 |= 1 << USART_CR1_RE_Pos;
		}
	}
}