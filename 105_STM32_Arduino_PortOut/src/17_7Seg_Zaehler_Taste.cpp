#if 1
#include <Arduino.h>

#define LED_PORTC GPIOC
#define LED_PORTB GPIOB

int bcd_7seg[] = {
    ~0x3F, 
    ~0x06, 
    ~0x5B, 
    ~0x4F, 
    ~0x66, 
    ~0x6D, 
    ~0x7D, 
    ~0x07, 
    ~0x7F,
    ~0x6F};

void ausgebenEiner(int zahl) {LED_PORTC -> ODR = bcd_7seg[zahl];}

void setup() {
    RCC->AHBENR |= (1<<2); // Enable the GPIOC clock
    RCC->AHBENR |= (1<<1); // Enable the GPIOC clock

    LED_PORTC->MODER &= 0xFFFF0000; 
    LED_PORTC->MODER |= 0x00005555; 
    
    //pinMode(PB0, INPUT_PULLDOWN);
    LED_PORTB->MODER &= 0xFFFFFFF0;
    LED_PORTB->MODER &= 0x00000000;

    LED_PORTC->ODR = 0x00000000; 
}

void loop() {
    int pressed = digitalRead(PB0);
    if(pressed) {
        for (int i = 0; i < 10; i++) {
            ausgebenEiner(i);
            delay(1000);
        }
    } else {
        for (int i = 9; i >= 0; i--) {
            ausgebenEiner(i);
            delay(1000);
        }
    }
    

}

#endif