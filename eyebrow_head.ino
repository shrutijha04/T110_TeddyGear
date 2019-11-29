#include <Servo.h>
Servo myservo;
Servo myservo1;
Servo myservo2;// create servo object to control a servo
// twelve servo objects can be created on most boards
int sensor=4;
int pos = 0;
int sensor1=3;
int sensor2=5;
int pos1 = 60;



void setup() {
  myservo.attach(9);
  myservo1.attach(10);
  myservo2.attach(11);
  pinMode(sensor,INPUT);
  pinMode(sensor1,INPUT);// attaches the servo on pin 9 to the servo object
  pinMode(sensor2,INPUT);
  
}

void loop() {
  //eyebrow
  while( digitalRead(sensor)==HIGH){
  for (pos = 0; pos <= 40; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);
    myservo2.write(40-pos);// tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  delay(2000);
  for (pos = 40; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos); 
    myservo2.write(40-pos); // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  }

  //headmove
  while( digitalRead(sensor1)==HIGH && digitalRead(sensor2)==LOW ){
  for (pos1 = 60; pos1 <= 120; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos1);
    
   // tell servo to go to position in variable 'pos'
    delay(10);  }
    delay(2000);// waits 15ms for the servo to reach the position
    for (pos1 = 120; pos1 >= 60; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos1);
    
    // tell servo to go to position in variable 'pos'
    delay(10);  }         
  
  }
  while(digitalRead(sensor2)==HIGH && digitalRead(sensor1)==LOW){
  for (pos1 = 60; pos1 >= 0; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos1); 
     
    // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }delay(2000);
   for (pos1 = 0; pos1 <= 60; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos1);
    
   // tell servo to go to position in variable 'pos'
    delay(10);  }
  }
    
}
