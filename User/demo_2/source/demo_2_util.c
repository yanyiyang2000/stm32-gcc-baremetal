/* Standard library API */
#include <stdint.h>

/* Application API */
#include "demo_2_config.h"


volatile uint16_t wave[40];

/**
 * This helper function populates the wave array with waveform data. 
 */
void util_generate_wave_data() {
    // Generate triangle wave data
    for (int i = 0; i < 21; i++) {
        wave[i] = 2000 + 100*i;
    }

    for (int i = 21; i < 40; i++) {
        wave[i] = 4000 - 100*(i - 20);
    }
}
