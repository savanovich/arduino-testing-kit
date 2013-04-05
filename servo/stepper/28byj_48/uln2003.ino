/*
 * This Arduino example demonstrates bidirectional operation of a
 * 28BYJ-48, using a ULN2003 interface board to drive the stepper.
 * The 28BYJ-48 motor is a 4-phase, 8-beat motor, geared down by
 * a factor of 68. One bipolar winding is on motor pins 1 & 3 and
 * the other on motor pins 2 & 4. The step angle is 5.625/64 and the
 * operating Frequency is 100pps. Current draw is 92mA.
*/

const unsigned int MOTOR_PIN1 = 8;   // Blue   - 28BYJ48 pin 1
const unsigned int MOTOR_PIN2 = 9;   // Pink   - 28BYJ48 pin 2
const unsigned int MOTOR_PIN3 = 10;  // Yellow - 28BYJ48 pin 3
const unsigned int MOTOR_PIN4 = 11;  // Orange - 28BYJ48 pin 4
                                     // Red    - 28BYJ48 pin 5 (VCC)

const unsigned int MOTOR_SPEED = 1200;  // variable to set stepper speed
const unsigned int STEPS_PER_REVOLUTION = 512; // number of steps per full revolution

unsigned int count = 0;          // count of steps made
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

void setup() {
    pinMode(MOTOR_PIN1, OUTPUT);
    pinMode(MOTOR_PIN2, OUTPUT);
    pinMode(MOTOR_PIN3, OUTPUT);
    pinMode(MOTOR_PIN4, OUTPUT);
}

void setOutput(int out) {
    digitalWrite(MOTOR_PIN1, bitRead(lookup[out], 0));
    digitalWrite(MOTOR_PIN2, bitRead(lookup[out], 1));
    digitalWrite(MOTOR_PIN3, bitRead(lookup[out], 2));
    digitalWrite(MOTOR_PIN4, bitRead(lookup[out], 3));
}

// set pins to ULN2003 high in sequence from 1 to 4
// delay "MOTOR_SPEED" between each pin setting (to determine speed)
void anticlockwise() {
    for(int i = 0; i < 8; i++) {
        setOutput(i);
        delayMicroseconds(MOTOR_SPEED);
    }
}

void clockwise() {
    for(int i = 7; i >= 0; i--) {
        setOutput(i);
        delayMicroseconds(MOTOR_SPEED);
    }
}

void loop() {
    if(count < STEPS_PER_REVOLUTION)
        clockwise();
    else if (count == STEPS_PER_REVOLUTION * 2)
        count = 0;
    else
        anticlockwise();
    count++;
}
