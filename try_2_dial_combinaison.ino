#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

const int triggerPin1 = 13;   // Trigger pin for sensor 1
const int echoPin1 = 11;      // Echo pin for sensor 1
const int triggerPin2 = 12;   // Trigger pin for sensor 2
const int echoPin2 = 10;      // Echo pin for sensor 2
const int redLedPin1 = 4;     // Red LED pin for sensor 1
const int greenLedPin1 = 7;   // Green LED pin for sensor 1
const int redLedPin2 = 8;     // Red LED pin for sensor 2
const int greenLedPin2 = 9;   // Green LED pin for sensor 2

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(3);  // attaches the servo on pin 3 to the servo object
  pinMode(triggerPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(triggerPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(redLedPin1, OUTPUT);
  pinMode(greenLedPin1, OUTPUT);
  pinMode(redLedPin2, OUTPUT);
  pinMode(greenLedPin2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  myservo.write(500);      // Set servo to open position
  delay(100);                // Wait for 5 seconds
  myservo.write(-500);     // Set servo to closed position
  //delay(100);              // Delay for stability

  // Read sensor 1
  float distance1 = getDistance(triggerPin1, echoPin1);
  if (distance1 < 10.0) {
    digitalWrite(redLedPin1, HIGH);     // Turn on the red LED for sensor 1
    digitalWrite(greenLedPin1, LOW);    // Turn off the green LED for sensor 1
    Serial.println("sensor1:occupied");
  } else {
    digitalWrite(redLedPin1, LOW);      // Turn off the red LED for sensor 1
    digitalWrite(greenLedPin1, HIGH);   // Turn on the green LED for sensor 1
    Serial.println("sensor1:free");
  }

  // Read sensor 2
  float distance2 = getDistance(triggerPin2, echoPin2);
  if (distance2 < 10.0) {
    digitalWrite(redLedPin2, HIGH);     // Turn on the red LED for sensor 2
    digitalWrite(greenLedPin2, LOW);    // Turn off the green LED for sensor 2
    Serial.println("sensor2:occupied");
  } 
  else {
    digitalWrite(redLedPin2, LOW);      // Turn off the red LED for sensor 2
    digitalWrite(greenLedPin2, HIGH);   // Turn on the green LED for sensor 2
    Serial.println("sensor2:free");
  }

  delay(50);  // Wait for a short period before reading the sensors again
}

// Function to measure the distance using HC-SR04 sensor
float getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.034) / 2;  // Calculate distance in centimeters

  return distance;
}

