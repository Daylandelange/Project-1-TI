// Include Arduino Wire library for I2C
#include <Wire.h>

// Define Slave I2C Address
#define SLAVE_ADDR 9
// Define Slave answer size
#define ANSWERSIZE 20
// Array for receiving inputs
char inTraffic[32] = {};
int i;

void setup() {

  // Initialize I2C communications as Master
  Wire.begin();

  // Setup serial monitor
  Serial.begin(9600);
  Serial.println("Lift Master");
}

void loop() {

  delay(500);
  Serial.println("Write data to slave");

  // Write a charatre to the Slave
  Wire.beginTransmission(SLAVE_ADDR);

  Wire.write(" ping", 5);

  Wire.endTransmission();

  Serial.println("Receive data:");

  // Read response from Slave
  // Read back 7 characters
  Wire.requestFrom(SLAVE_ADDR, ANSWERSIZE);

  // Add characters to string
  i = 0;
  while (Wire.available()) {
    inTraffic[i] = Wire.read();
    i++;
    // Print to Serial Monitor
    Serial.println(inTraffic[i]);
  }
}