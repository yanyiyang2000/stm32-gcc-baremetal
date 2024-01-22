Demo 2 utilizes the following components:
- DMA1 channel 4
- DAC1 channel 2
- TIM6

`wave` is an array of 40 16-bit unsigned integers representing waveform data for the DAC to convert.

The following is the workflow:
1. **TIM6** generates an update event when its counter overflows (every 50 ms).
2. The update event will trigger the data to be transferred from **DAC1 channel 2** *12-bit right-aligned data holding register* (`DAC_DHR12R2`) to **DAC1 channel 2** *data output register* (`DAC_DOR2`).
3. A DMA request is generated and a 16-bit data is transferred from `wave` to `DAC_DHR12R2` via **DMA1 channel 4**.