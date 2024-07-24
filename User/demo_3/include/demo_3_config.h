#ifndef DEMO_3_CONFIG_H
#define DEMO_3_CONFIG_H

#include <stdint.h>


/******************************************************************************/
/*                      GPIO Configurations (for USART2)                      */

void GPIO_PA2_config();
void GPIO_PA3_config();
/******************************************************************************/


/******************************************************************************/
/*                           USART2 Configurations                            */

void USART2_config();
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
// void USART2_IRQHandler();
/******************************************************************************/


/******************************************************************************/
/*                                Demo 3 Entry                                */

void demo_3_enter();
/******************************************************************************/

#endif /* DEMO_3_CONFIG_H */
