#include <stdint.h>
#include "system_stm32f10x.h"

int main(void)
{
    SystemInit();

    volatile int fake = 0;
    while (fake)
    {
        fake += 1;
        fake -=1;
    }

    return (-1);
}
