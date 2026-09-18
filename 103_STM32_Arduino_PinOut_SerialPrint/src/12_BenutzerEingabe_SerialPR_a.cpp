#if 0
#include <Arduino.h>

void setup() {
    Serial.begin(115200);

    while (!Serial) {
        ;//nichts tun
    }
}

void loop() {
    if (Serial.available() > 0) {
        char inputChar = Serial.read();

        if(inputChar == 'A' || inputChar == 'a') {
            Serial.println("Auswahl A: Sie haben A gewählt");
        }

        else if(inputChar == 'B' || inputChar == 'b') {
            Serial.println("Auswahl B: Sie haben B gewählt");
        }

        else if(inputChar == 'C' || inputChar == 'c') {
            Serial.println("Auswahl C: Sie haben C gewählt");
        }

        else if(inputChar == 'D' || inputChar == 'd') {
            Serial.println("Auswahl D: Sie haben D gewählt");
        }
    }
}

#endif