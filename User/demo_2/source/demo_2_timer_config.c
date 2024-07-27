/* Standard library API */
#include <stdint.h>

/* Device API */
#include "system_stm32l4xx.h"
#include "stm32l476xx.h"

/* Application API */
#include "demo_common_config.h"
#include "demo_2_config.h"


/**
 * This function configures TIM6 as follows:
 *   - Auto-reload preload disabled        (default)
 *   - One-pulse mode disabled             (default)
 *   - Update event (UEV) enabled          (default)
 *   - Trigger output is the update evenet
 *   - Update interrupt (UI) disabled      (default)
 *   - Prescaled to 1 kHz
 *   - Overflows every 50 ms
 * 
 * Reference: RM0351, p.1180-1184
 */
void TIM6_config() {
    // Enable TIM6 APB1 interface clock
    RCC->APB1ENR1 |= 1 << RCC_APB1ENR1_TIM6EN_Pos;

    // Select update evenet as trigger output (0b010) [RM0351, p.1182]
    TIM6->CR2 &= ~TIM_CR2_MMS_Msk;
    TIM6->CR2 |= 0b010 << TIM_CR2_MMS_Pos;

    // Set prescaler value
    TIM6->PSC = (uint16_t)(SystemCoreClock/1000 - 1);

    // Set auto-reload value
    TIM6->ARR = (uint16_t)50;

    // Enable TIM6 counter
    TIM6->CR1 |= 1 << TIM_CR1_CEN_Pos;
}
