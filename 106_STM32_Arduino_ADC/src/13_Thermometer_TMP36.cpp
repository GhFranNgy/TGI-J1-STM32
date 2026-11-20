#if 0
#include <Arduino.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);
const int potiPA0_P = PA4;

void setup() {
    Serial.begin(115200); 
    analogReadResolution(12); // ADC mit 12 Bit Auflösung

    lcd.begin(16, 2);
}
void loop() {
    int rohwandelwert = analogRead(potiPA0_P); // Potiwert lesen 2^12= 0...4095
    lcd.setBacklight(255);
    lcd.print(rohwandelwert);
    delay(200);
    lcd.clear();
}
#endif