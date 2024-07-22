/* Device API */
#include "stm32l476xx.h"

/* Application API */
#include "demo_common_config.h"
#include "demo_2_config.h"


/**
 * This function is the entry point of demo 2.
 */
void demo_2_enter() {
	// Configure MSI to around 48 MHz
	MSI_config();

	// Configure system timer
	SysTick_config();

	// Configure GPIO PA5 to power the LED
	GPIO_PA5_config();

	// Generate wave data
	util_generate_wave_data();

	// Configure DMA1 channel 4
	DMA1_CH4_Config();

	// Configure TIM6
	TIM6_Config();

	// Configure DAC1 channel 2
	DAC1_CH2_Config();

	while (1) {}
}
