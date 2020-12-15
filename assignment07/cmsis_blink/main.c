#include "delay.h"
#include "stm32l475xx.h"

#define SYS_CLOCK_HZ 4000000u   // Default clock after startup
                                // Section 3.11 in STM32L475 datasheet DS10969
#define SYS_CLOCK_MS_HZ (SYS_CLOCK_HZ / 1000u)

extern volatile unsigned int count;

void SysTick_Initialize(void);

void main()
{
    // 1. Enable clock to Peripheral  
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

    // Set bit[29:28] to 0x01  so --> 0x400 // To enable PB14 as output
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;

    SysTick_Initialize();
    // Set bit[5] to 1 // Turn LED ON
    // Set bit[5] to 0 // Turn LED OFF

    while(1) {
        GPIOA->ODR ^= GPIO_ODR_OD5;
        delay(1000);
    } 
}

void SysTick_Initialize(void)
{
    SysTick->LOAD = SYS_CLOCK_MS_HZ - 1;       // 0xE000E014 - Counts down to 0.
    SysTick->VAL = 0x0;                     // 0xE000E018 - Clears initial value
    SysTick->CTRL = 0x7;                    // 0xE000E010 - Enable interrupts
}

void SysTick_Handler(void)
{
    __disable_irq();
    count++;
    __enable_irq();
}