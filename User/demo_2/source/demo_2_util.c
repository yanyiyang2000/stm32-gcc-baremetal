/* Standard library API */
#include <stdint.h>

/* User API */
#include "demo_2_config.h"


/**
 * This global variable contains waveform data to be transferred into DHR12R2 
 * register of DAC1 channel 2.
 */
volatile uint16_t demo_2_wave_data[40];

/**
 * This helper function populates `demo_2_wave_data` with waveform data.
 */
void demo_2_util_populate_wave_data() {
    // Generate triangle wave data
    for (int i = 0; i < 21; i++) {
        demo_2_wave_data[i] = 2000 + 100*i;
    }

    for (int i = 21; i < 40; i++) {
        demo_2_wave_data[i] = 4000 - 100*(i - 20);
    }
}
