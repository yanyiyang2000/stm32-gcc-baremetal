#ifndef DEMO_4_CONFIG_H
#define DEMO_4_CONFIG_H

/* Standard library API */
#include <stdint.h>

/* Device API */
#include "stm32l476xx.h"
#include "core_cm4.h"

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
/*                        Core Register Configurations                        */

void Reg_config();
/******************************************************************************/


/******************************************************************************/
/*                             Interrupt Handlers                             */

void SysTick_Handler() __attribute__ ((naked));

void SVC_Handler() __attribute__ ((naked));
/******************************************************************************/


/******************************************************************************/
/*                                Demo 4 Entry                                */

void demo_4_enter();
/******************************************************************************/

void demo_4_task_1_enter();
void demo_4_task_2_enter();

struct __attribute__((packed)) demo_4_task {
    uint32_t stack_top;
    uint32_t r4;
    uint32_t r5;
    uint32_t r6;
    uint32_t r7;
    uint32_t r8;
    uint32_t r9;
    uint32_t r10;
    uint32_t r11;
};

#endif /* DEMO_4_CONFIG_H */
