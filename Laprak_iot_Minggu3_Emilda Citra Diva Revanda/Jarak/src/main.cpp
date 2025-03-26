#include <Arduino.h>

const int trigPin = 5;
const int echoPin = 18;

#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

void setup() {
    Serial.begin(115200); // Memulai komunikasi serial
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    // Membersihkan trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    // Mengaktifkan trigPin selama 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Membaca echoPin, mendapatkan waktu perjalanan gelombang suara dalam microseconds
    duration = pulseIn(echoPin, HIGH);
    
    // Menghitung jarak dalam cm
    distanceCm = duration * SOUND_SPEED / 2;
    
    // Menghitung jarak dalam inci
    distanceInch = distanceCm * CM_TO_INCH;
    
    // Menampilkan hasil ke Serial Monitor
    Serial.print("Distance (cm): ");
    Serial.println(distanceCm);
    
    delay(1000);
}