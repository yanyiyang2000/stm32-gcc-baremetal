/* Standard library API */
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/* Device API */
#include "stm32l476xx.h"

/* Application API */
#include "demo_common_config.h"
#include "demo_3_config.h"

extern const uint32_t __StackTop;
extern const uint32_t __StackLimit;
extern const uint32_t __HeapLimit;
extern const uint32_t __end__;
extern const uint32_t __bss_end__;
extern const uint32_t __bss_start__;
extern const uint32_t __data_end__;
extern const uint32_t __data_start__;

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

	// Configure USART2 transmitter and receiver
	USART2_config();

	// Send strings through USART2
	printf("%-20s: 0x%.8"PRIX32"\n", "Stack Max Addr", (uint32_t)&__StackTop);
	printf("%-20s: 0x%.8"PRIX32"\n", "Stack Min Addr", (uint32_t)&__StackLimit);
	printf("%-20s: 0x%.8"PRIX32"\n", "Heap Max Addr",  (uint32_t)&__HeapLimit);
	printf("%-20s: 0x%.8"PRIX32"\n", "Heap Min Addr",  (uint32_t)&__end__);
	printf("%-20s: 0x%.8"PRIX32"\n", ".bss Max Addr",  (uint32_t)&__bss_end__);
	printf("%-20s: 0x%.8"PRIX32"\n", ".bss Min Addr",  (uint32_t)&__bss_start__);
	printf("%-20s: 0x%.8"PRIX32"\n", ".data Max Addr", (uint32_t)&__data_end__);
	printf("%-20s: 0x%.8"PRIX32"\n", ".data Min Addr", (uint32_t)&__data_start__);

	while (1) {}
}
