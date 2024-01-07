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

volatile uint8_t fifo[20] = {0};
volatile uint8_t rx_cnt = 0;
volatile uint8_t tx_cnt = 0;

void USART2_IRQHandler(void) {
	/* A byte is received */
	if ( (USART2->ISR & USART_ISR_RXNE_Msk) == USART_ISR_RXNE_Msk ) {
		// Read RX data, this clears RXNE flag
		fifo[rx_cnt % 20] = (uint8_t) USART2->RDR;
		rx_cnt++;
	}

	/* A byte can be transmitted */
	if ( (USART2->ISR & USART_ISR_TXE_Msk) == USART_ISR_TXE_Msk ) {
		// Write TX data, this clears TXE flag
		USART2->TDR = fifo[tx_cnt % 20];
		tx_cnt++;
	}
}
