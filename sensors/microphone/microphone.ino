#include <SegmentsDisplay.h>

const byte LATCH_PIN = 8;
const byte CLOCK_PIN = 12;
const byte DATA_PIN = 11;

const byte Y1_PIN = 14;
const byte Y2_PIN = 15;
const byte Y3_PIN = 16;
const byte Y4_PIN = 17;

const byte MIC_A0_PIN = A5;
const byte MIC_D0_PIN = 2;

FourDigitsBinaryCounterDisplay display;


const unsigned int BOUND_RATE = 9600;


const int ledPin = 13; 

const int middleValue = 512; //the code will flash the LED in pin 13
const int numberOfSamples = 128; //the middle of the range of analog values
                                //how many readings will be taken each time
int sample; //the value read from microphone each time
long signal; //the reading once you have removed DC offset
long averageReading; //the average of that loop of readings
long runningAverage=0; //the running average of calculated values
const int averagedOver= 16; //how quickly new values affect running average
                           //bigger numbers mean slower
const int threshold=400; //at what level the light turns on

void setup() {
    display.setup(
            LATCH_PIN, CLOCK_PIN, DATA_PIN,
            Y1_PIN, Y2_PIN, Y3_PIN, Y4_PIN);

    /* pinMode(MIC_A0_PIN, INPUT); */
    pinMode(MIC_D0_PIN, INPUT);

    Serial.begin(BOUND_RATE);
}

void loop() {
    /* long sumOfSquares = 0; */
    /* for (int i=0; i<numberOfSamples; i++) { //take many readings and average them */
        /* sample = analogRead(A5); */
        //take a reading
        /* signal = (sample - middleValue); */
        /* //work out its offset from the center */
        /* signal *= signal; */
        /* //square it to make all values positive */
        /* sumOfSquares += signal; */
        /* //add to the total */
    /* } */

    /* averageReading = sumOfSquares/numberOfSamples; */
    /* //calculate running average */
    /* runningAverage=(((averagedOver-1)*runningAverage)+averageReading)/averagedOver; */


    /* if (runningAverage>threshold){ */
    /*     digitalWrite(ledPin, HIGH); */
    /* }else{ */
    /*     digitalWrite(ledPin, LOW); */
    /* } */
    Serial.println(analogRead(A5));
    Serial.println(digitalRead(2));

    //is average more than the threshold ?
    //if it is turn on the LED
    //if it isn't turn the LED off
    //print the value so you can check it

    /* display.showInt(runningAverage); */
    /* delay(1000); */
    /* display.showInt(analogRead(MIC_A0_PIN)); */
}

