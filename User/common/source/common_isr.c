/* Standard library API */
#include <stdint.h>

/* Device API */
#include "stm32l476xx.h"

/* Application API */
#include "common_config.h"


volatile uint8_t fifo[20] = {0};
volatile uint8_t rx_cnt = 0;
volatile uint8_t tx_cnt = 0;

void USART2_IRQHandler() {
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
