
#define RCC_AHB2NR          (*((unsigned int*)0x4002104C))
#define RCC_GPIOA_ENABLE    0x1

#define GPIOA_MODER         (*((unsigned int*)0x48000000))
#define GPIOA5_MODER_OFFSET 10

#define GPIOA_ODR           (*((unsigned int*)0x48000014))
#define GPIOA5_ODR_OFFSET   5

#define GPIOA5_ENABLE       0x1
#define GPIOA5_CLEAR        0x3

#define COUNTER_MAX         100000 

void main(void)
{
    int counter = 0;

    // enable clock
    RCC_AHB2NR |= RCC_GPIOA_ENABLE;
    
    // set gpio to output mode 
    GPIOA_MODER &= ~(GPIOA5_CLEAR << GPIOA5_MODER_OFFSET);
    GPIOA_MODER |= (GPIOA5_ENABLE << GPIOA5_MODER_OFFSET);
    
    while(1){
        // write to data register for toggling
        GPIOA_ODR ^= (GPIOA5_ENABLE << GPIOA5_ODR_OFFSET);
        
        while (counter < COUNTER_MAX) {
            counter++;
        }
        
        counter = 0;
    }
}
