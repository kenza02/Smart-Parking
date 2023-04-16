#include <Servo.h>

// Define the pins for the ultrasonic sensor
const int trig = 12;
const int echo = 13;
// Define the pin for the servo motor
const int servoPin = 10;

// Create a Servo object to control the motor
Servo myservo;

// Define variables to store the distance and angle
long duration;
int distance;
int angle;

void setup() {
  // Initialize the serial port for debugging
  Serial.begin(9600);

  // Initialize the pins for the ultrasonic sensor
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  // Attach the servo motor to the pin
  myservo.attach(servoPin);
}

void loop() {
  // Send a pulse to the ultrasonic sensor to trigger a measurement
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Measure the duration of the echo
  duration = pulseIn(echo, HIGH);

  // Calculate the distance based on the speed of sound
  distance = duration / 58;

  // Check if a car is detected
  if (distance <= 5) {
    myservo.write(180); // set the angle to 90 degrees
    delay(5000); // wait for 5 seconds
    myservo.write(0); // set the angle back to 0 degrees to close the barrier
  }

  // Print the distance for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Wait for a short period before taking the next measurement
  delay(100);
}













































































































































































































































































































































































