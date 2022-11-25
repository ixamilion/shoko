#include "RTE_Components.h"
#include CMSIS_device_header

#include "bsp_time.h"

static volatile uint32_t _tick = 0;
void SysTick_Handler(void)
{
    _tick++;
}

///
void bsp_time_init(void)
{
    NVIC_EnableIRQ(SysTick_IRQn);
    SysTick_Config(1000);
}

///
uint32_t bsp_time(void)
{
    return _tick;
}
