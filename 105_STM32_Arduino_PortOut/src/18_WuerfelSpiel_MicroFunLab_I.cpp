#if 1
#include <Arduino.h>

#define LED_PORTB GPIOB

int dice1[] = {
    0b0000000000000001,
    0b0000000000000100,
    0b0000000000000101,
    0b0000000000000110,
    0b0000000000000111,
    0b0000000000001110
};
int dice2[] = {
    0b0000000000010000,
    0b0000000001000000,
    0b0000000001010000,
    0b0000000001100000,
    0b0000000001110000,
    0b0000000011100000
};
int dice3[] = {
    0b0000000100000000,
    0b0000010000000000,
    0b0000010100000000,
    0b0000011000000000,
    0b0000011100000000,
    0b0000111000000000
};
int dice4[] = {
    0b0001000000000000,
    0b0100000000000000,
    0b0101000000000000,
    0b0110000000000000,
    0b0111000000000000,
    0b1110000000000000
};

void setup() {
    RCC->AHBENR |= (1 << 1);

    LED_PORTB->MODER &= 0x00000000; 
    LED_PORTB->MODER |= 0x55555555; 

    LED_PORTB->ODR = 0x00000000;

    randomSeed(analogRead(A0)); 
}

void loop() {
    int d1Rand = random(0, 6);
    int d2Rand = random(0, 6);
    int d3Rand = random(0, 6);
    int d4Rand = random(0, 6);

    LED_PORTB->ODR = 0;

    LED_PORTB->ODR |= dice1[d1Rand];
    LED_PORTB->ODR |= dice2[d2Rand];
    LED_PORTB->ODR |= dice3[d3Rand];
    LED_PORTB->ODR |= dice4[d4Rand];

    delay(1000); 
}

#endif