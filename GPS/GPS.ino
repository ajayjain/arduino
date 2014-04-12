/*
  Ajay Jain
  December 30, 2013
  GPS
*/

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#define RXPIN 3
#define TXPIN 2

SoftwareSerial ss(RXPIN, TXPIN);
TinyGPSPlus gps;

void setup()
{
  ss.begin(4800);
  Serial.begin(4800);
}

void loop()
{
  Serial.println(ss.read());
  while (ss.available() > 0)
  {
    Serial.print(ss.read());
  }
}
