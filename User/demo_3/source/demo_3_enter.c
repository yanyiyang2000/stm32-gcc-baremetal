/* Device API */
#include "stm32l476xx.h"

/* Application API */
#include "demo_common_config.h"
#include "demo_3_config.h"


/**
 * This function is the entry point of demo 3.
 */
void demo_3_enter() {
	// Configure MSI to around 48 MHz
	MSI_config();

	// Configure system timer
	SysTick_config();

	// Configure GPIO PA2 and PA3 as UART receiver and transmitter
	GPIO_PA2_config();
	GPIO_PA3_config();

	// Configure UART2 transmitter and receiver
	USART2_config();

	while (1) {}
}
