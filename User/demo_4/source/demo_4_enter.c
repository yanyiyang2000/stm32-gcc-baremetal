/* Standard library API */
#include <stdint.h>

/* Device API */
#include "stm32l476xx.h"

/* Application API */
#include "demo_common_config.h"
#include "demo_4_config.h"


uint32_t demo_4_task_1_stack[] = {
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x10101010,                         // R0
    0x11111111,                         // R1
    0x12121212,                         // R2
    0x13131313,                         // R3
    0x1C1C1C1C,                         // R12
    0xFFFFFFFD,                         // LR (R14), Use PSP after returning from exception [DDI 0403E, B1.5.8]
    (uint32_t)&(demo_4_task_1_enter),   // PC (R15)
    0x01000000                          // xSPR, ESPR's bit 0 (T bit) should be set to indicate Thumb mode
};

uint32_t demo_4_task_2_stack[] = {
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x20202020,
    0x21212121,
    0x22222222,
    0x23232323,
    0x2C2C2C2C,
    0xFFFFFFFD,
    (uint32_t)&(demo_4_task_2_enter),
    0x01000000
};

struct demo_4_task demo_4_task_1 = {
    .stack_top = (uint32_t)(demo_4_task_1_stack + 8),
    .r4   = 0xF4F4F4F4,
    .r5   = 0xF5F5F5F5,
    .r6   = 0xF6F6F6F6,
    .r7   = 0xF7F7F7F7,
    .r8   = 0xF8F8F8F8,
    .r9   = 0xF9F9F9F9,
    .r10  = 0xFAFAFAFA,
    .r11  = 0xFBFBFBFB
};

struct demo_4_task demo_4_task_2 = {
    .stack_top = (uint32_t)(demo_4_task_2_stack + 8),
    .r4   = 0xF4F4F4F4,
    .r5   = 0xF5F5F5F5,
    .r6   = 0xF6F6F6F6,
    .r7   = 0xF7F7F7F7,
    .r8   = 0xF8F8F8F8,
    .r9   = 0xF9F9F9F9,
    .r10  = 0xFAFAFAFA,
    .r11  = 0xFBFBFBFB
};

/**
 * This function is the entry point of demo 4.
 */
void demo_4_enter() {
    // Configure MSI to around 48 MHz
    MSI_config();

    // Configure system timer
    SysTick_config();

    // Configure GPIO PA2 and PA3 as UART receiver and transmitter
    // GPIO_PA2_config();
    // GPIO_PA3_config();

    // Configure USART2 transmitter and receiver
    // USART2_config();

    // Start executing tasks
    __ASM volatile ("svc 0");

    while (1);
}

void demo_4_task_1_enter() {
    while (1) {
        __ASM volatile ("mov r4, 0x14141414");
        __ASM volatile ("mov r5, 0x15151515");
        __ASM volatile ("mov r6, 0x16161616");
    }
}

void demo_4_task_2_enter() {
    while (1) {
        __ASM volatile ("mov r4, 0x24242424");
        __ASM volatile ("mov r5, 0x25252525");
        __ASM volatile ("mov r6, 0x26262626");
    }
}
