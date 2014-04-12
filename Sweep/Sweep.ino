/*
  Ajay Jain
  December 30, 2013
  Sweep
  
  Servo white wire to pin 9
  Servo red wire to 5V
  Servo black wire to GND
*/  


#include <Servo.h> 
 
int servoPin = 9;
int wait = 10;
 
Servo servo;  
 
int angle = 0;   // servo position in degrees 
 
void setup() 
{
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(0);
  Serial.println("Enter an integer delay in ms");
}

void loop() 
{
  // scan from 0 to 180 degrees
  for(angle = 0; angle < 180; angle++)  
  {
    checkWait();
    printAngle();
    
    servo.write(angle);
    delay(wait);                   
  }
  
  delay(1000);
  
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--)    
  {
    checkWait();
    printAngle();
    
    servo.write(angle);           
    delay(wait);       
  }
  
  delay(1000);
} 

void checkWait()
{
  if (Serial.available())
    wait = Serial.parseInt();
}

void printAngle()
{
  if (angle % 10 == 1 || angle == 180 || angle == 0)
  {
    Serial.print(angle);
    Serial.print("  ");
  }
  
  if (angle % 180 == 0)
  {
    Serial.println(); 
  }
}
