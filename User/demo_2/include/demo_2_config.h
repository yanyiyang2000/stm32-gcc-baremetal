#ifndef DEMO_2_CONFIG_H
#define DEMO_2_CONFIG_H

#include <stdint.h>

/**
 * Global array containing data to be transferred into DHR12R2 register of DAC1 
 * channel 2.
 */
extern volatile uint16_t wave[40];

void util_generate_wave_data();


/******************************************************************************/
/*                       GPIO Configurations (for LED)                        */

void GPIO_PA5_config();
/******************************************************************************/


/******************************************************************************/
/*                            DMA Configurations                              */

void DMA1_CH4_Config();
/******************************************************************************/


/******************************************************************************/
/*                            DAC Configurations                              */

void DAC1_CH2_Config();
/******************************************************************************/


/******************************************************************************/
/*                            TIM6 Configurations                             */

void TIM6_Config();
/******************************************************************************/


/******************************************************************************/
/*                             Interrupt Handlers                             */

/**
 * @brief Global variable indicating current time since boot up in milliseconds.
 * 
 * @note This variable is incremented within system tick interrupt handler.
 */
extern volatile uint64_t SysTick_ms;

void SysTick_Handler();
/******************************************************************************/


/******************************************************************************/
/*                                Demo 2 Entry                                */

void demo_2_enter();
/******************************************************************************/

#endif /* DEMO_2_CONFIG_H */