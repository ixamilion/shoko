#include "RTE_Components.h"
#include CMSIS_device_header

#include <stdint.h>

int main(void)
{
    // PC13
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    GPIO_InitTypeDef PC13;
    PC13.GPIO_Pin   = GPIO_Pin_13;
    PC13.GPIO_Mode  = GPIO_Mode_Out_PP;
    PC13.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOC, &PC13);
    
    volatile int fake = 1;
    while (fake)
    {
        GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);
        fake += 1;
        fake -=1;
        GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);
    }

    return (-1);
}
