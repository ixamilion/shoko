#include "RTE_Components.h"
#include CMSIS_device_header

#include "bsp.h"

int main(void)
{
    bsp_time_init();
    bsp_led_init();
    
    //bsp_btn_init();
    //bsp_adc_init();

    while (1)
    {
        __WFI();
        bsp_led_tick();
        
        //bsp_btn_tick();
        //bsp_adc_tick();
    }

    return (-1);
}
