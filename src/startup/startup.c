#include <stdint.h>

extern uint32_t _estack, _sidata, _sdata, _edata, _sbss, _ebss;
int main(void);



void Reset_Handler(void);
void Default_Handler(void) { for (;;) { } }

void NMI_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)    __attribute__((weak, alias("Default_Handler")));






typedef void (*vector_t)(void);

__attribute__((section(".isr_vector"), used))
const vector_t vectors[] = {
    (vector_t)&_estack,   /*  0  initial stack pointer          */
    Reset_Handler,        /*  1  reset                          */
    NMI_Handler,          /*  2                                 */
    HardFault_Handler,    /*  3                                 */
    MemManage_Handler,    /*  4                                 */
    BusFault_Handler,     /*  5                                 */
    UsageFault_Handler,   /*  6                                 */
    0, 0, 0, 0,           /*  7-10 reserved                     */
    SVC_Handler,          /* 11  starts the first task (Stage 6) */
    DebugMon_Handler,     /* 12                                 */
    0,                    /* 13  reserved                       */
    PendSV_Handler,       /* 14  context switch (Stage 6)       */
    SysTick_Handler,      /* 15  kernel tick (Stage 4)          */
    /* 16+: peripheral IRQs, added when a stage needs one */
};


void Reset_Handler(void) {
    /* 1. copy .data's initial values from flash (LMA) to RAM (VMA) */
    uint32_t *src = &_sidata;
    for (uint32_t *dst = &_sdata; dst < &_edata; ) {
        *dst++ = *src++;
    }

    /* 2. zero .bss: your turn */
    

    /* 3. call main, and stop if it ever returns: your turn */
}
