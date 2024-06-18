#include <ESP8266WiFi.h>

// Define connections to sensor
#define TRIGPIN D0 // Replace D0 with the GPIO pin connected to the TRIG pin of your sensor
#define ECHOPIN D1 // Replace D1 with the GPIO pin connected to the ECHO pin of your sensor

// Floats to calculate distance
float duration, distance;

void setup() {
  // Set up serial monitor
  Serial.begin(115200);

  // Set pinmodes for sensor connections
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
}

void loop() {

  // Set the trigger pin LOW for 2uS
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);

  // Set the trigger pin HIGH for 20us to send pulse
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(20);

  // Return the trigger pin to LOW
  digitalWrite(TRIGPIN, LOW);

  // Measure the width of the incoming pulse
  duration = pulseIn(ECHOPIN, HIGH);

  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  // Divide by 1000 as we want millimeters

  distance = (duration / 2) * 0.343;

  // Print result to serial monitor
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println(" mm");

  // Delay before repeating measurement
  delay(100);
}

