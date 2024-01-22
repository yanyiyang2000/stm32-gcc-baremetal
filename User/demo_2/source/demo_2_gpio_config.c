/* Device API */
#include "stm32l476xx.h"

/* Application API */
#include "demo_2_config.h"

/**
 * This function configures GPIO PA5 as follows:
 *   - Analog mode                      (default)
 *   - No pull-up or pull-down resistor (default)
 *   - Additional function is DAC1_OUT2 (default)
 *
 * Note: GPIO PA5 is used as the output of DAC1 channel 2. [DS1098, p.74]
 * 
 * Reference: DS1098, p.74
 */
void GPIO_PA5_config() {
	// Enable GPIO port A AHB2 interface clock
	RCC->AHB2ENR |= 1 << RCC_AHB2ENR_GPIOAEN_Pos;
}
