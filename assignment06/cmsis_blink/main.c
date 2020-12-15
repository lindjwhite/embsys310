#include "delay.h"
#include "stm32l475xx.h"

void main()
{
    // 1. Enable clock to Peripheral  
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

    // Set bit[29:28] to 0x01  so --> 0x400 // To enable PB14 as output
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;

    // Set bit[5] to 1 // Turn LED ON
    // Set bit[5] to 0 // Turn LED OFF

    while(1) {
        GPIOA->ODR |= GPIO_ODR_OD5;
        delay(100000);
        
        GPIOA->ODR &= ~GPIO_ODR_OD5;
        delay(100000);
    } 
}
