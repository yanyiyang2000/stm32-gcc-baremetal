/* Device API */
#include "stm32l476xx.h"

/* Application API */
#include "demo_2_config.h"


volatile uint64_t SysTick_ms = 0;

void SysTick_Handler() {
	SysTick_ms += 1;
}
