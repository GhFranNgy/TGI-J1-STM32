#if 0
#include <Arduino.h>

// Tonfrequenzen in Hz (4. und 5. Oktave)
const int f_toneE4 = 330;  // E4
const int f_toneB4 = 494;  // B4 (H4)
const int f_toneC5 = 523;  // C5
const int f_toneD5 = 587;  // D5
const int f_toneE5 = 659;  // E5
const int f_toneF5 = 698;  // F5
const int f_toneG5 = 784;  // G5
const int f_toneA5 = 880;  // A5
const int f_toneGS4= 415;  // G#4
const int f_toneA4 = 440;  // A4
const int REST     = 0;

const int BUZZER_PIN = PA4;
const int ledPins[8] = {PC0, PC1, PC2, PC3, PC4, PC5, PC6, PC7};

// Timing-Einstellungen (schnelles Tetris-Tempo ~150 BPM)
const int QUARTER = 400; // Viertelnote in ms
const int EIGHTH  = 200; // Achtelnote in ms
const int D_EIGHTH= 300; // Punktierte Achtelnote in ms
const int SIXTH   = 100; // Sechzehntelnote in ms
const int HALF    = 800; // Halbe Note in ms

struct Note {
    int frequency;
    int duration;
    int ledIndex; // Welches LED leuchtet (0 bis 7)
};

// "Tetris" Hauptmelodie (Korobeiniki)
Note melody[] = {
    // Teil 1
    {f_toneE5, QUARTER, 4}, {f_toneB4, EIGHTH, 1}, {f_toneC5, EIGHTH, 2}, {f_toneD5, QUARTER, 3},
    {f_toneC5, EIGHTH, 2},  {f_toneB4, EIGHTH, 1}, {f_toneA4, QUARTER, 0}, {f_toneA4, EIGHTH, 0},
    {f_toneC5, EIGHTH, 2},  {f_toneE5, QUARTER, 4}, {f_toneD5, EIGHTH, 3}, {f_toneC5, EIGHTH, 2},
    {f_toneB4, D_EIGHTH, 1},{f_toneC5, SIXTH, 2},  {f_toneD5, QUARTER, 3}, {f_toneE5, QUARTER, 4},
    {f_toneC5, QUARTER, 2}, {f_toneA4, QUARTER, 0}, {f_toneA4, HALF, 0},

    // Teil 2
    {f_toneD5, D_EIGHTH, 3},{f_toneF5, SIXTH, 5},  {f_toneA5, QUARTER, 7}, {f_toneG5, EIGHTH, 6},
    {f_toneF5, EIGHTH, 5},  {f_toneE5, D_EIGHTH, 4},{f_toneC5, SIXTH, 2},  {f_toneE5, QUARTER, 4},
    {f_toneD5, EIGHTH, 3},  {f_toneC5, EIGHTH, 2},  {f_toneB4, D_EIGHTH, 1},{f_toneC5, SIXTH, 2},
    {f_toneD5, QUARTER, 3}, {f_toneE5, QUARTER, 4}, {f_toneC5, QUARTER, 2}, {f_toneA4, QUARTER, 0},
    {f_toneA4, HALF, 0},

    {REST, 400, -1} // Pause vor Wiederholung
};

const int totalNotes = sizeof(melody) / sizeof(melody[0]);

void clearLeds() {
    for (int i = 0; i < 8; i++) {
        digitalWrite(ledPins[i], LOW);
    }
}

void activateLed(int index) {
    clearLeds();
    if (index >= 0 && index < 8) {
        digitalWrite(ledPins[index], HIGH);
    }
}

void playTone(int pin, int frequency, int durationMs, int ledIndex) {
    activateLed(ledIndex);

    if (frequency <= 0) {
        delay(durationMs);
        return;
    }

    long period = 1000000 / frequency;
    long durationUs = (long)durationMs * 1000;

    for (long i = 0; i < durationUs; i += period) {
        digitalWrite(pin, HIGH);
        delayMicroseconds(period / 2);
        digitalWrite(pin, LOW);
        delayMicroseconds(period / 2);
    }
}

void setup() {
    for (int i = 0; i < 8; i++) {
        pinMode(ledPins[i], OUTPUT);
        digitalWrite(ledPins[i], LOW);
    }
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
    for (int i = 0; i < totalNotes; i++) {
        playTone(BUZZER_PIN, melody[i].frequency, melody[i].duration, melody[i].ledIndex);
        clearLeds();
        delay(20); // Kurze Trennung zwischen den Tönen
    }
}
#endif