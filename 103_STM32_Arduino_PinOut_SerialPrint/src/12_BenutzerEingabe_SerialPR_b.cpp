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

        switch (inputChar){
            case 'A':
            case 'a':
                Serial.println("Auswahl A: Sie haben A gewählt");
            break;
            case 'B':
            case 'b':
                Serial.println("Auswahl B: Sie haben B gewählt");
            break;
            case 'C':
            case 'c':
                Serial.println("Auswahl C: Sie haben C gewählt");
            break;
            case 'D':
            case 'd':
                Serial.println("Auswahl D: Sie haben D gewählt");
            break;
        }
    }
}

#endif