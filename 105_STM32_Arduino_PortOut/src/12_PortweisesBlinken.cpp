#if 0
#include <Arduino.h>

#define LED_PORTC GPIOC
#define LED_PORTB GPIOB
#define LED_PORTA GPIOA
int Port = 0xFFFF;


void setup() {
    // Aktiviere den Takt für Port C
    RCC->AHBENR |= (1<<2); // Enable the GPIOC clock
    RCC->AHBENR |= (1<<1); // Enable the GPIOB clock
    RCC->AHBENR |= (1<<0); // Enable the GPIOA clock
    // Setze PA0 bis PA7 als Output (00 für jede Pin-Gruppe)
    LED_PORTC->MODER &= ~0xFFFFFFFF; // lösche die Bits
    LED_PORTC->MODER |= 0x55555555; // setze PC0 bis PC7 auf Output
    LED_PORTB->MODER &= ~0xFFFFFFFF; // lösche die Bits
    LED_PORTB->MODER |= 0x55555555; // setze PB0 bis PB7 auf Output
    LED_PORTA->MODER &= ~0xFFFFFFFF; // lösche die Bits
    LED_PORTA->MODER |= 0x55555555; // setze PA0 bis PA7 auf Output
    // Setze alle LEDs auf LOW (aus)
    LED_PORTC->ODR = 0x00000000; // Output Data Register
    LED_PORTB->ODR = 0x00000000; // Output Data Register
    LED_PORTA->ODR = 0x00000000; // Output Data Register
}

void loop() {
    LED_PORTC -> ODR = (Port);
    LED_PORTB -> ODR = (Port);
    LED_PORTA -> ODR = (Port);
    delay(200);
    LED_PORTC -> ODR = (0x0);
    LED_PORTB -> ODR = (0x0);
    LED_PORTA -> ODR = (0x0);
    delay(200);
}

#endif