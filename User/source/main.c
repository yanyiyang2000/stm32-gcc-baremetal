#include <stdint.h>

#include "stm32l476xx.h"

#include "clock_config.h"
#include "gpio_config.h"
#include "interrupt.h"


int main() {
	MSI_config();
	SysTick_config();
	GPIO_PA5_config();
	GPIO_PA2_config();
	GPIO_PA3_config();
}
