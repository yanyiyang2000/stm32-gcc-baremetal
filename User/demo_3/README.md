## Demo 3 Components:
- USART2
- GPIO port A pin 2
- GPIO port A pin 3

## Demo 3 Workflow:
1. **USART2** transmits data through **GPIO port A pin 2** and receives data through **GPIO port A pin 3**.

>[!NOTE]
> **USART2**, **GPIO port A pin 2** and **GPIO port A pin 3** are chosen because they are connected to the STM32 Nucleo-64 Board's ST-LINK MCU which supports virtual COM port so that we can see the transmission on PC. [^1]

[^1]: STM32 Nucleo-64 Boards User Manual (UM1724), p.25