/*
  BoeBotTest.h
  Created by Ajay Jain, April 12, 2014
*/

#include <Servo.h>
#include <BoeBot.h>

BoeBot bot;
Servo servoLeft;                             // Declare left and right servos
Servo servoRight;

void setup()
{
  bot.start_tone(4);
  /*servoLeft.attach(13);
  servoRight.attach(12);
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
  delay(2000);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  servoLeft.detach();
  servoRight.detach();*/
  
//  delay(1000);
//  bot.start_tone(4);
  bot.set_speed(200);
  delay(1000);
  bot.set_speed(0);
  delay(3000);
//  bot.shutdown();
}

void loop()
{
  //bot.set_speed(-100);
  //delay(1000);
}
