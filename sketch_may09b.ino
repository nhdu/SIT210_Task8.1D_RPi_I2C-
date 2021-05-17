#include <Wire.h>

const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  // Join I2C bus as slave with address 8
  Wire.begin(0x8);

  // Call receiveEvent when data received
  Wire.onReceive(receiveEvent);

  // Setup pin 13 as output and turn LED off
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

// Function that executes whenever data is received from master
void receiveEvent(int howMany)
{
  while (Wire.available())
  {
    char c = Wire.read();
    digitalWrite(ledPin, c);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);  
}
