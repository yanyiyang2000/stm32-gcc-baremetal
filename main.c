#include <stdint.h>

#include "stm32l476xx.h"	// has to be included before core_cm4.h
//#include "stm32l4xx_it.h"

#include "clock_config.h"
#include "gpio_config.h"
#include "interrupt.h"


//static volatile uint64_t SysTick_ms = 0;


int main() {
	MSI_config();
	SysTick_config();
	GPIO_PA5_config();
	GPIO_PA2_config();
	GPIO_PA3_config();
}


//void SysTick_Handler(void) {
//	if (SysTick_ms == 1000) {
//		// Toggle GPIO port A pin 5 output
//		if ((GPIOA->ODR &= GPIO_ODR_OD5_Msk) == 0) {
//			GPIOA->ODR |= 1 << GPIO_ODR_OD5_Pos;
//		} else {
//			GPIOA->ODR &= 0 << GPIO_ODR_OD5_Pos;
//		}
//		SysTick_ms = 0;
//	} else {
//		SysTick_ms++;
//	}
//	//SysTick_ms == 1000 ? SysTick_ms = 0 : SysTick_ms++;
//}
