#ifndef DEMO_COMMON_CONFIG_H
#define DEMO_COMMON_CONFIG_H

/**********************************************************/
/*           MSI Oscillator Clock Configuration           */

void MSI_config();
/**********************************************************/


/**********************************************************/
/*               System Clock Configuration               */

void SysTick_config();
/**********************************************************/


/**********************************************************/
/*            GPIO Configurations (for UART2)             */

void GPIO_PA2_config();
void GPIO_PA3_config();
/**********************************************************/


/**********************************************************/
/*                  UART2 Configurations                  */

void UART2_config();
/**********************************************************/


/**********************************************************/
/*                   Interrupt Handlers                   */

void USART2_IRQHandler();
/**********************************************************/

#endif /* DEMO_COMMON_CONFIG_H */