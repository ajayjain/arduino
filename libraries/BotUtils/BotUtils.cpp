/*
	BotUtils.cpp - Helpers for programs for the Boe Bot with
	the Arduino
	Created by Ajay Jain, April 12, 2014
*/

#include "Arduino.h"
#include "BotUtils.h"

/*BotUtils::BotUtils()
{
	
}*/

void BotUtils::start_tone(int pin)
{
	tone(pin, 2600, 240);     // Play tone for 240 msec
	delay(250);               // Delay to finish tone
	tone(pin, 2800, 240);
	delay(250);               // Delay to finish tone
	tone(pin, 3000, 240);
	delay(250);               // Delay to finish tone
}