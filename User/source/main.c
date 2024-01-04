#include <stdint.h>

#include "stm32l476xx.h"

#include "interrupt.h"
#include "clock_config.h"
#include "gpio_config.h"
#include "uart_config.h"


int main() {
	/* Configure MSI to around 48 MHz */
	MSI_config();

	/* Configure SysTick interrupt to be triggered every 1 ms */
	SysTick_config();

	/* Update the SystemCoreClock variable */
	SystemCoreClockUpdate();

	/* Configure GPIO PA5 to control LED */
	GPIO_PA5_config();

	/* Configure GPIO PA2 and PA3 as UART receiver and transmitter */
	GPIO_PA2_config();
	GPIO_PA3_config();

	/* Configure UART2 transmitter and receiver */
	UART2_config();

	while (1) {}
}
