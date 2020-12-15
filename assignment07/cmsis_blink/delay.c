#include "delay.h"

volatile unsigned int count;

void delay(unsigned int max_count)
{
    while (max_count != count) { }
    count = 0;
}