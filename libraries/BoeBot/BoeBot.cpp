/*
	BoeBot.cpp - Helpers for programs for the Boe Bot with
	the Arduino
	Created by Ajay Jain, April 12, 2014
*/

#include "Arduino.h"
#include "BoeBot.h"
#include "Servo.h"
// #include "Assert.h"

BoeBot::BoeBot()
{
	// _left();
	// _right();
	_left.attach(13);
	_right.attach(12);
	// start_tone(4)z;
}

// speed: min -200, max 200
// negative speed: back, pos: forward, 0: stop
void BoeBot::set_speed(int speed)
{
	// assert (speed >= -200 && speed <= 200);
	// _left.attach(13);
	// _right.attach(12);
	_left.writeMicroseconds(1500 + speed);
	_right.writeMicroseconds(1500 - speed);
	// delay(3000);
}

/*void BoeBot::stop()
{
	set_speed(0);
}*/

void BoeBot::start_tone(int pin)
{
	tone(pin, 2600, 240);     // Play tone for 240 msec
	delay(250);               // Delay to finish tone
	tone(pin, 2200, 240);
	delay(250);               // Delay to finish tone
	tone(pin, 3000, 240);
	delay(250);               // Delay to finish tone
}

void BoeBot::shutdown()
{
	set_speed(0);
	_left.detach();
	_right.detach();
}