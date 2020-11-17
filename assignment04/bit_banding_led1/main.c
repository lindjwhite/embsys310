
#define BIT_BAND_BASE       0x42000000
#define RCC_AHB2NR_OFFSET   0x2104C
#define RCC_GPIOA_BIT_NUM   0
#define RCC_GPIOA_BB_ADDR   (BIT_BAND_BASE + (RCC_AHB2NR_OFFSET * 32) + (RCC_GPIOA_BIT_NUM * 4))
#define RCC_GPIOA_BIT_BAND  (*((unsigned int*)RCC_GPIOA_BB_ADDR))
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
    unsigned int* address = (unsigned int*)RCC_GPIOA_BB_ADDR;
    // enable clock
    RCC_GPIOA_BIT_BAND = RCC_GPIOA_ENABLE;
    
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
