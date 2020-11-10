
#define RCC_AHB2NR          (*((unsigned int*)0x4002104C))
#define RCC_GPIOA_ENABLE    0x1

#define GPIOA_MODER         (*((unsigned int*)0x48000000))
#define GPIOA5_MODER_OFFSET 10

#define GPIOA_ODR           (*((unsigned int*)0x48000014))
#define GPIOA5_ODR_OFFSET   5

#define GPIOA5_ENABLE       0x1
#define GPIOA5_CLEAR        0x3

#define ONE_UNIT            100000 
#define TWO_UNITS           (2 * ONE_UNIT)

int counter = 0;

void set() {
    GPIOA_ODR |= (GPIOA5_ENABLE << GPIOA5_ODR_OFFSET);
}

void clear() {
    GPIOA_ODR &= ~(GPIOA5_ENABLE << GPIOA5_ODR_OFFSET);
}

void space() {
    while (counter < ONE_UNIT) {counter++;}
    counter = 0;
}

void letter_space() {
    // its three units for the space if including the 
    // space at the end of the dot or dash
    while (counter < TWO_UNITS) {counter++;}
    counter = 0;
}

void init() {
    // enable clock
    RCC_AHB2NR |= RCC_GPIOA_ENABLE;
    
    // set gpio to output mode 
    GPIOA_MODER &= ~(GPIOA5_CLEAR << GPIOA5_MODER_OFFSET);
    GPIOA_MODER |= (GPIOA5_ENABLE << GPIOA5_MODER_OFFSET);
    
    clear();
}

void dot() {
    set();
    space();
    clear();
    space();
}

void dash() {
    set();
    space();
    letter_space(); // these two add up to 3 unit spaces
    clear();
    space();
}

void main(void)
{
    init();
    
    // L
    dot();
    dash();
    dot();
    dot();
    
    letter_space();
    
    // I
    dot();
    dot();
    
    letter_space();
    
    // N
    dash();
    dot();
    
    letter_space();
    
    // D
    dash();
    dot();
    dot();
    
    letter_space();
    
    // S
    dot();
    dot();
    dot();
    
    letter_space();
    
    // A
    dot();
    dash();
    
    letter_space();
    
    // Y
    dash();
    dot();
    dash();
    dash();
}
