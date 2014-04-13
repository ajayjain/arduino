/*
 * Robotics with the BOE Shield - StartResetIndicator
 * Test the piezospeaker circuit.
 */ 

#include <BoeBot.h>

BoeBot bot;

void setup()                                 // Built in initialization block
{ 
  Serial.begin(9600);
  Serial.println("Beep!");  
  
  bot.start_tone(4);
}  
 
void loop()                                  // Main loop auto-repeats
{         
  Serial.println("Waiting for reset...");
  delay(1000);
}
