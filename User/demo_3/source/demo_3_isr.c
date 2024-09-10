/* Standard library API */
#include <stdint.h>

/* CMSIS Device API */
#include "stm32l476xx.h"

/* User API */
#include "demo_3_config.h"


/**
 * This global variable indicates current time since boot up in milliseconds.
 * 
 * Note: This variable is incremented by SysTick interrupt handler.
 */
volatile uint64_t demo_3_systick_ms = 0;

// volatile uint8_t demo_3_fifo[20] = {0};
// volatile uint8_t demo_3_rx_cnt = 0;
// volatile uint8_t demo_3_tx_cnt = 0;

void USART2_IRQHandler() {
	// /* A byte is received */
	// if ( (USART2->ISR & USART_ISR_RXNE_Msk) == USART_ISR_RXNE_Msk ) {
	// 	// Read RX data, this clears RXNE flag
	// 	demo_3_fifo[demo_3_rx_cnt % 20] = (uint8_t)USART2->RDR;
	// 	demo_3_rx_cnt++;
	// }

	// /* A byte can be transmitted */
	// if ( (USART2->ISR & USART_ISR_TXE_Msk) == USART_ISR_TXE_Msk ) {
	// 	// Write TX data, this clears TXE flag
	// 	USART2->TDR = demo_3_fifo[demo_3_tx_cnt % 20];
	// 	demo_3_tx_cnt++;
	// }
}


void SysTick_Handler() {
    demo_3_systick_ms += 1;
}
