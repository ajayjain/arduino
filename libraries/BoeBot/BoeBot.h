/*
	BoeBot.h - Helpers for programs for the BoeBot with
	the Arduino
	Created by Ajay Jain, April 12, 2014
*/

#include "Servo.h"

#ifndef BoeBot_h
#define BoeBot_h

class BoeBot
{
public:
	BoeBot();
	void set_speed(int speed);
	// void stop(); // just calls set_speed(0)
	void start_tone(int pin);
	void shutdown();
private:
	Servo _left;
	Servo _right;
};

#endif