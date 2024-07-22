/* Standard library API */
#include <stdint.h>

/* Device API */
#include "stm32l476xx.h"

/* Application API */
#include "demo_common_config.h"
#include "demo_2_config.h"


/**
 * This function configures DMA1 channel 4 as follows:
 *   - Memory to memory mode disabled       (default)
 *   - Very high priority level
 *   - Memory size is 16 bits
 *   - Peripheral size is 16 bits
 *   - Memory increment mode enabled 
 *   - Peripheral increment mode disabled   (default)
 *   - Circular mode enabled
 *   - Read from memory
 *   - Transfer error interrupt disabled    (default)
 *   - Half transfer interrupt disabled     (default)
 *   - Transfer complete interrupt disabled (default)
 * 
 *   - 32 data to transfer
 *   - Memory address is the address of an array defined in demo_2_config.h
 *   - Peripheral address is DHR12R2 register of DAC1
 *   - DMA request source is DAC1 channel 2
 * 
 * Note: DMA1 channel 4 is chosen since DAC1 channel 2 is used to generate
 *       analog signal and it is connected to DMA1 channel 4. [RM0351, p.338]
 * 
 * Reference: RM0351, p.338; p.340-353
 */
void DMA1_CH4_Config() {
    // Enable DMA1 interface clock
    RCC->AHB1ENR |= 1 << RCC_AHB1ENR_DMA1EN_Pos;

    // Set priority level to very high (0b11) [RM0351, p.353]
    DMA1_Channel4->CCR &= ~DMA_CCR_PL_Msk;
    DMA1_Channel4->CCR |= 0b11 << DMA_CCR_PL_Pos;

    // Set memory size to 16 bits (0b01) [RM0351, p.353]
    DMA1_Channel4->CCR &= ~DMA_CCR_MSIZE_Msk;
    DMA1_Channel4->CCR |= 0b01 << DMA_CCR_MSIZE_Pos;

    // Set peripheral size to 16 bits (0b01) [RM0351, p.353]
    DMA1_Channel4->CCR &= ~DMA_CCR_PSIZE_Msk;
    DMA1_Channel4->CCR |= 0b01 << DMA_CCR_PSIZE_Pos;

    // Enable memory increment mode
    DMA1_Channel4->CCR |= 1 << DMA_CCR_MINC_Pos;

    // Enable circular mode
    DMA1_Channel4->CCR |= 1 << DMA_CCR_CIRC_Pos;

    // Set data transfer direction to read from memory
    DMA1_Channel4->CCR |= 1 << DMA_CCR_DIR_Pos;

    // Set number of data to transfer to 40
    DMA1_Channel4->CNDTR = (uint16_t)40;

    // Set memory address
    DMA1_Channel4->CMAR = (uint32_t)(&wave);

    // Set peripheral address to DHR12R2 register of DAC1
    DMA1_Channel4->CPAR = (uint32_t)(&DAC1->DHR12R2);

    // Set DMA request source to DAC1 channel 2 (0b0101) [RM0351, p.340]
    DMA1_CSELR->CSELR &= ~DMA_CSELR_C4S_Msk;
    DMA1_CSELR->CSELR |= 0b0101 << DMA_CSELR_C4S_Pos;

    // Enable DMA channel 4
    DMA1_Channel4->CCR |= 1 << DMA_CCR_EN_Pos;
}
