/* CMSIS API */
#include "cmsis_gcc.h"

/* Application API */
#include "demo_4_config.h"

/**
 *  @note The reason this function has attribute "naked" is because the 
 *        operating system must perform the context switch before saving any
 *        caller-saved registers onto the stack.
 */
void __attribute__ ((naked)) SysTick_Handler() {
    // Save Task 1's PSP
    __ASM volatile ("mrs   r0, psp");               // r0 <- psp
    __ASM volatile ("ldr   r1, =demo_4_task_1");    // r1 <- addr(demo_4_task_1)
    __ASM volatile ("str   r1, [r0], #4");          // mem[r0, 4] <- r1
                                                    // r0 <- r0 + 4

    // Save Task 1's R4 - R11
    __ASM volatile ("stmia r1, {r4-r11}");          // mem[r1, 4] <- r4
                                                    // r1 <- r1 + 4
                                                    // mem[r1, 4] <- r5
                                                    // r1 <- r1 + 4
                                                    // ...
                                                    // mem[r1, 4] <- r11
                                                    // r1 <- r1 + 4

    // Restore Task 2's PSP
    __ASM volatile ("ldr   r1, =demo_4_task_2");    // r1 <- addr(demo_4_task_2)
    __ASM volatile ("ldr   r0, [r1]");              // r0 <- mem[r1, 4]
    __ASM volatile ("msr   psp, r0");               // psp <- r0

    // Prologue (MSP is used)
    // __ASM volatile ("push  {r7, lr}");
    // __ASM volatile ("add   r7, sp, #0");

    // Some code here

    // Epilogue
    // __ASM volatile ("mov   sp, r7");
    // __ASM volatile ("pop   {r7, pc}");

    __ASM volatile ("bx    lr");
}

void __attribute__ ((naked)) SVC_Handler() {
    extern struct demo_4_task demo_4_task_1;

    // Set Task's PSP (TODO: pick the first task (instead of task 1) from the task list)
    __set_PSP(demo_4_task_1.stack_top);

    // TODO: Restore r4-r11 manually

    // TODO: Enable SysTick to perform task switch

    __ASM volatile ("ldr    lr, =0xFFFFFFFD");
    __ASM volatile ("bx     lr");

    /**
     * Upon the return of the SVC exception, the following will take place:
     * 
     * fp   <- psp
     * r0   <- mem[fp,      4]
     * r1   <- mem[fp + 4,  4]
     * r2   <- mem[fp + 8,  4]
     * r3   <- mem[fp + 12, 4]
     * r12  <- mem[fp + 16, 4]
     * lr   <- mem[fp + 20, 4]
     * pc   <- mem[fp + 24, 4] (instruction at pc will be executed next)
     * xpsr <- mem[fp + 28, 4]
     * 
     * See Armv7-M Architecture Reference Manual B1.5.8 (page B1-542)
     */
}
