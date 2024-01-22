#ifndef DEMO_1_CONFIG_H
#define DEMO_1_CONFIG_H

#include <stdint.h>

/******************************************************************************/
/*                       GPIO Configurations (for LED)                        */

void GPIO_PA5_config();
/******************************************************************************/


/******************************************************************************/
/*                             Interrupt Handlers                             */

/**
 * @brief Global variable indicating current system tick in milliseconds.
 * 
 * @note This variable is incremented within system tick interrupt handler and 
 *       is reset after reaching 1000.
 */
extern volatile uint64_t SysTick_ms;

void SysTick_Handler();
/******************************************************************************/


/******************************************************************************/
/*                                Demo 1 Entry                                */

void demo_1_enter();
/******************************************************************************/

#endif /* DEMO_1_CONFIG_H */