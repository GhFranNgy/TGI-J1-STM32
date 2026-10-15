#if 1
#include <Arduino.h>
// * Taster-Entprellung für den STM32L152RE mit Arduino Framework
// * Für Taster TB0_P (active high mit internem Pull-Down)
// Pin-Definition für den Taster TB0_P
const int tB0_P = PB0; // Bitte durch den tatsächlichen Pin ersetzen, an dem TB0_P angeschlossen ist
// Parameter für die Entprellung
const unsigned long ENTPRELL_ZEIT = 50; // Entprellungszeit in Millisekunden
// Variablen für den Tasterstatus
volatile bool tasterStatus = false; // Aktueller Status des Tasters (entprellt)
volatile bool letzterStatus = false; // Letzter Status des Tasters
volatile unsigned long letzteAenderung = 0; // Zeitpunkt der letzten Änderung
void setup() {
    // Serielle Kommunikation initialisieren
    Serial.begin(115200);
    Serial.println("Taster-Entprellung Programm gestartet");
    // Taster-Pin konfigurieren mit internem Pull-Down-Widerstand
    pinMode(tB0_P, INPUT_PULLDOWN);
}
// Funktion, die aufgerufen wird, wenn der Taster gedrückt wird
void tasterAktionGedrueckt() {
    // Hier Ihre Aktion einfügen
    // Beispiel: LED einschalten oder andere Aktionen ausführen
}
// Funktion, die aufgerufen wird, wenn der Taster losgelassen wird
void tasterAktionLosgelassen() {
    // Hier Ihre Aktion einfügen
    // Beispiel: LED ausschalten oder andere Aktionen ausführen
}
void loop() {
        // Aktuellen Zustand des Tasters lesen
        bool aktuellerZustand = digitalRead(tB0_P);
        // Aktuelle Zeit speichern
        unsigned long jetzt = millis();
        // Prüfen, ob sich der Zustand geändert hat
        if (aktuellerZustand != letzterStatus) {
                // Neuen Status speichern
                letzterStatus = aktuellerZustand;
                // Zeitpunkt der Änderung speichern
                letzteAenderung = jetzt;
            }

            // Entprellung: Nur wenn der Status lange genug stabil ist, wird er übernommen
            if ((jetzt - letzteAenderung) > ENTPRELL_ZEIT) {
                // Wenn sich der entprellte Status ändert
                if (aktuellerZustand != tasterStatus) {
                tasterStatus = aktuellerZustand;
            // Status-Änderung ausgeben

            if (tasterStatus) {
                Serial.println("Taster TB0_P gedrückt (entprellt)");
                // Hier können Sie Aktionen ausführen, wenn der Taster gedrückt wird
                tasterAktionGedrueckt();
            } else {
                Serial.println("Taster TB0_P losgelassen (entprellt)");
                // Hier können Sie Aktionen ausführen, wenn der Taster losgelassen wird
                tasterAktionLosgelassen();
            }
        }
    }
    // Kurze Verzögerung zur CPU-Entlastung
    delay(1);
}
#endif