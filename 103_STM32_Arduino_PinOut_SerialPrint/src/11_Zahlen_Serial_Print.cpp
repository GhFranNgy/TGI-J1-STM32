#if 0
#include <Arduino.h>

int durchgang = 0;

void setup(){
    Serial.begin(115200);
}

void loop() {
    durchgang++;
    Serial.print("Druchgang: ");
    Serial.println(durchgang);

    for(int i = 1; i < 10; i++) {
        Serial.println(i);
        delay(500);
        
    }
}
#endif


