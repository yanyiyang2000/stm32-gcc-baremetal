/* Device API */
#include "stm32l476xx.h"

/* Application API */
#include "demo_common_config.h"
#include "demo_2_config.h"


/**
 * This function configures DAC1 channel 2 as follows:
 *   - Calibration disabled            (default)
 *   - DMA underrun interrupt disabled (default)
 *   - DMA enabled
 *   - Wave generation disabled        (default)
 *   - Trigger source is TIM6_TRGO     (default)
 *   - Trigger enabled
 * 
 * Note: Every 50 ms, DAC1 channel 4 is loaded with a new value via 
 *       DMA1 channel 2. The interval can be configured by modifying 
 *       TIM6 auto-reload value in demo_2_timer_config.c.
 * 
 * Reference: RM0351, p.626; p.639-640
 */
void DAC1_CH2_Config() {
    // Enable DAC1 APB1 interface clock
    RCC->APB1ENR1 |= 1 << RCC_APB1ENR1_DAC1EN_Pos;

    // Enable DMA
    DAC1->CR |= 1 << DAC_CR_DMAEN2_Pos;

    // Select TIM6_TRGO as trigger source (0b000) [RM0351, p.626]
    DAC1->CR &= ~DAC_CR_TSEL2_Msk;
    DAC1->CR |= 0b000 << DAC_CR_TSEL2_Pos;

    // Enable trigger
    DAC1->CR |= 1 << DAC_CR_TEN2_Pos;

    // Enable DAC1 channel 2
    DAC1->CR |= 1 << DAC_CR_EN2_Pos;
}
