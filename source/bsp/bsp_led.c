#include "RTE_Components.h"
#include CMSIS_device_header

#include "bsp_led.h"
#include "bsp_time.h"


///
void bsp_led_init(void)
{
    // PC13
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    GPIO_InitTypeDef PC13;
    PC13.GPIO_Pin   = GPIO_Pin_13;
    PC13.GPIO_Mode  = GPIO_Mode_Out_PP;
    PC13.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOC, &PC13);
}

/// 
void bsp_led_tick(void)
{
    static uint32_t prev_tick = 0;
    if ((bsp_time() - prev_tick) < 500)
    {
        return;
    }
    prev_tick = bsp_time();

    static bool is_cmd_ON = false;
    is_cmd_ON = !is_cmd_ON;
    if (is_cmd_ON)
    {
        GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);
    } else {
        GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);
    }
}
