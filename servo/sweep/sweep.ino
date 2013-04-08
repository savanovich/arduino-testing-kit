/*
 * Controlling a servo position using a potentiometer (variable resistor)
 * by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>
 */

#include <Servo.h>

const unsigned int SERVO_PIN = 9;

Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position 


void setup() {
    myservo.attach(SERVO_PIN);  // attaches the servo on pin 9 to the servo object
}

void loop() {
    for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(15);                       // waits 15ms for the servo to reach the position 
    } 
    for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
    {                                
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(15);                       // waits 15ms for the servo to reach the position 
    } 
}
