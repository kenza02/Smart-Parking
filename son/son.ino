// Arduino code to read data from HC-SR04

#include <NewPing.h>

#define TRIGGER_PIN 2
#define ECHO_PIN 3

NewPing sonar(TRIGGER_PIN, ECHO_PIN);
int distance;

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(2000); // Add delay for stability
  distance = sonar.ping_cm(); // Get distance in cm
  Serial.println(distance); // Send distance data to Raspberry Pi via Serial
}
