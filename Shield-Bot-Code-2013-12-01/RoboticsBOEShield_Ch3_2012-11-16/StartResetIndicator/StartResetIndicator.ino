/*
 * Robotics with the BOE Shield - StartResetIndicator
 * Test the piezospeaker circuit.
 */ 

#include <BotUtils.h>

void setup()                                 // Built in initialization block
{ 
  Serial.begin(9600);
  Serial.println("Beep!");  
  
  BotUtils::start_tone(4);
}  
 
void loop()                                  // Main loop auto-repeats
{         
  Serial.println("Waiting for reset...");
  delay(1000);
}
