#if 1
#include <Arduino.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);
const int potiPA0_PA0 = PA0;

void setup() {
    Serial.begin(115200); 
    analogReadResolution(12); // ADC mit 12 Bit Auflösung
    analogWriteResolution(12);
    pinMode(PC0, OUTPUT);

    lcd.begin(16, 2);
}
void loop() {
    float rohwandelwertPA4 = (analogRead(potiPA0_PA0)*3.3)/4095; // Potiwert lesen 2^12= 0...4095
    int lux = analogRead(PA4);
    float lichtwert = (lux*3.3) / 4095 + 0.2;
    lcd.setBacklight(255);
    lcd.setCursor(0, 0);
    lcd.print("U PA0: ");
    lcd.print(rohwandelwertPA4);
    lcd.setCursor(0, 1);
    lcd.print("U PA4: ");
    lcd.print(lichtwert);
    delay(50);
    if(rohwandelwertPA4 < lichtwert) {
        digitalWrite(PC0, HIGH);
    } else {
        digitalWrite(PC0, LOW);
    }
}
#endif