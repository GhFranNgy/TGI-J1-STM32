#if 0
#include <Arduino.h>

const int potiPA0_P = PA0;

void setup() {
    Serial.begin(9600); 
    analogReadResolution(12); // ADC mit 12 Bit Auflösung
}

void loop() {
    int rohwandelwert = analogRead(potiPA0_P); // Potiwert lesen 2^12= 0...4095
    Serial.print("Rohwandelwert: ");
    Serial.print(rohwandelwert); 
    Serial.println();
    delay(50);
}
#endif