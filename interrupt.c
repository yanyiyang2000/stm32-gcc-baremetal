#include "stm32l476xx.h"

#include "interrupt.h"

volatile uint64_t SysTick_ms = 0;

void SysTick_Handler() {
	if (SysTick_ms == 1000) {
		// Toggle GPIO port A pin 5 output
		if ((GPIOA->ODR &= GPIO_ODR_OD5_Msk) == 0) {
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