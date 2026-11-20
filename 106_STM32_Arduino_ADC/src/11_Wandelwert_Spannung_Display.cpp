#if 0
#include <Arduino.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);
const int potiPA0_P = PA0;

void setup() {
    Serial.begin(115200); 
    analogReadResolution(12); // ADC mit 12 Bit Auflösung

    lcd.begin(16, 2);
}
void loop() {
    int rohwandelwert = analogRead(potiPA0_P); // Potiwert lesen 2^12= 0...4095
    lcd.setBacklight(255);
    lcd.setCursor(0, 0);
    lcd.print("Rww: ");
    lcd.print(rohwandelwert);
    lcd.setCursor(0, 1);
    lcd.print("Spannung: ");
    lcd.print((rohwandelwert*3.3)/4095);
    delay(50);
    lcd.clear();
}
#endif