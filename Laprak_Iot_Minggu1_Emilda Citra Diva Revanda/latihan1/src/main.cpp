#include <Arduino.h>

int merah = 26;
int kuning = 27;
int hijau = 33;

void setup() {
    Serial.begin(115200);  
    Serial.println("ESP32 Traffic Light");

    
    pinMode(merah, OUTPUT);
    pinMode(kuning, OUTPUT);
    pinMode(hijau, OUTPUT);
}

void loop() {
    
    digitalWrite(merah, HIGH);
    Serial.println("Lampu Merah ON");
    delay(5000);
    digitalWrite(merah, LOW);
    Serial.println("Lampu Merah OFF");

    
    digitalWrite(kuning, HIGH);
    Serial.println("Lampu Kuning ON");
    delay(2000);
    digitalWrite(kuning, LOW);
    Serial.println("Lampu Kuning OFF");

    
    digitalWrite(hijau, HIGH);
    Serial.println("Lampu Hijau ON");
    delay(5000);
    digitalWrite(hijau, LOW);
    Serial.println("Lampu Hijau OFF");
}
