#define trigPin 13
#define echoPin 12
#define ledPin 11

#define START_CMD_CHAR '*'
#define END_CMD_CHAR '#'
#define DIV_CMD_CHAR '|'
#define CMD_DIGITALWRITE 10
#define CMD_ANALOGWRITE 11
#define CMD_TEXT 12
#define CMD_READ_ARDUDROID 13
#define MAX_COMMAND 20  // max command number code. used for error checking.
#define MIN_COMMAND 10  // minimum command number code. used for error checking. 
#define IN_STRING_LENGHT 40
#define MAX_ANALOGWRITE 255
#define PIN_HIGH 3
#define PIN_LOW 2

long duration, distance;
int ledLevel = 0;

String inText;

int ard_command = 0;
int pin_num = 0;
int pin_value = 0;

char get_char = ' ';  //read serial

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(ledPin, OUTPUT);
  
  Serial.flush();
}

void loop() {
  updateDurationDistance();
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 30 || distance <= 0)
    ledLevel = 0;
  else
    ledLevel = 255 - (int) (distance/(float)30 * 255);
  analogWrite(ledPin, ledLevel);
  
  delay(500);
  return;
  
  Serial.flush();
  if (Serial.available() < 1) return; // if serial empty, return to loop().
  
  // parse incoming command start flag 
  get_char = Serial.read();
  if (get_char != START_CMD_CHAR) return; // if no command start flag, return to loop().
  
  // parse incoming command type
  ard_command = Serial.parseInt(); // read the command
  
  // parse incoming pin# and value  
  pin_num = Serial.parseInt(); // read the pin
  pin_value = Serial.parseInt();  // read the value

  // 1) GET TEXT COMMAND FROM ARDUDROID
  if (ard_command == CMD_TEXT)
    getData(); // sets inText
    
  // 2) GET digitalWrite DATA FROM ARDUDROID
  /*if (ard_command == CMD_DIGITALWRITE) {
    if (pin_value == PIN_LOW) pin_value = LOW;
    else if (pin_value == PIN_HIGH) pin_value = HIGH;
    else return; // error in pin value. return. 
    set_digitalwrite( pin_num,  pin_value);  // Uncomment this function if you wish to use 
    return;  // return from start of loop()
  }*/
  
  // 3) GET analogWrite DATA FROM ARDUDROID
  /*if (ard_command == CMD_ANALOGWRITE) {  
    analogWrite(  pin_num, pin_value ); 
    // add your code here
    return;  // Done. return to loop();
  }*/
  
  // 4) SEND DATA TO ARDUDROID
  if (ard_command == CMD_READ_ARDUDROID)
    sendData();
}

void updateDurationDistance() {
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
}

// 1a) Updates inText from Serial data recieved by module
void getData() {
  inText =""; //clears variable for new input   
  while (Serial.available())  {
    char c = Serial.read();  //gets one byte from serial buffer
    delay(5);
    if (c == END_CMD_CHAR) { // if we the complete string has been read
      // add your code here
      break;
    }              
    else {
      if (c !=  DIV_CMD_CHAR) {
        inText += c; 
        delay(5);
      }
    }
  }
}

// 2a) select the requested pin# for DigitalWrite action
void set_digitalwrite(int pin_num, int pin_value)
{
  switch (pin_num) {
  case 13:
    pinMode(13, OUTPUT);
    digitalWrite(13, pin_value);  
    // add your code here      
    break;
  case 12:
    pinMode(12, OUTPUT);
    digitalWrite(12, pin_value);   
    // add your code here       
    break;
  case 11:
    pinMode(11, OUTPUT);
    digitalWrite(11, pin_value);         
    // add your code here 
    break;
  case 10:
    pinMode(10, OUTPUT);
    digitalWrite(10, pin_value);         
    // add your code here 
    break;
  case 9:
    pinMode(9, OUTPUT);
    digitalWrite(9, pin_value);         
    // add your code here 
    break;
  case 8:
    pinMode(8, OUTPUT);
    digitalWrite(8, pin_value);         
    // add your code here 
    break;
  case 7:
    pinMode(7, OUTPUT);
    digitalWrite(7, pin_value);         
    // add your code here 
    break;
  case 6:
    pinMode(6, OUTPUT);
    digitalWrite(6, pin_value);         
    // add your code here 
    break;
  case 5:
    pinMode(5, OUTPUT);
    digitalWrite(5, pin_value); 
    // add your code here       
    break;
  case 4:
    pinMode(4, OUTPUT);
    digitalWrite(4, pin_value);         
    // add your code here 
    break;
  case 3:
    pinMode(3, OUTPUT);
    digitalWrite(3, pin_value);         
    // add your code here 
    break;
  case 2:
    pinMode(2, OUTPUT);
    digitalWrite(2, pin_value); 
    // add your code here       
    break;      
    // default: 
    // if nothing else matches, do the default
    // default is optional
  } 
}

// 4a)
void sendData() {
  //updateDurationDistance();
  if (distance >= 200 || distance <= 0)
    Serial.println("Out of range");
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  return;  // Done. return to loop();
}
