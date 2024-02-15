#include <Stepper.h>

#define TRIGGER_PIN 12 // ultra sonic //
#define ECHO_PIN 13   // ultra sonic //
const int stepsPerRevolution = 30;
const int stepsInRev = 200;
const int num_of_steps = 1;
const int stopMotor = 0;
const int hallSensorPin = 10;  // hall effect sensor //
int buttonState = HIGH; // Initial state (not pressed)

Stepper myStepper1(stepsInRev, 2, 3, 4, 5); // define motor 1 //
Stepper myStepper2(stepsInRev, 6, 7, 8, 9); // define motor 2 //
Stepper myStepper3(stepsInRev, A2, A3, A4, A5); // define motor 3 //

char val; // for serial //

float duration, distance; // calculations for ultra sonic 
 

////////////// setup the function of movment  //////////////

void rotate(int steps) {
  unsigned long startTime = millis();
  int buttonState = digitalRead(hallSensorPin); // Read the button state
  while (millis() - startTime < 1000 && buttonState == HIGH) { // Run for 0.8 seconds or until buttonState becomes LOW
    myStepper3.step(1);
    delay(10);
    buttonState = digitalRead(hallSensorPin); // Update button state
  }
}


       
  






void forwardStep(int steps) {
  unsigned long startTime = millis();
  while (millis() - startTime < 800) { // Run for 0.8 seconds
    myStepper1.step(1);
    myStepper2.step(-1);
    delay(10);
  }
}

void forwardStep2(int steps) {
    unsigned long startTime = millis();
  while (millis() - startTime < 2000) { // Run for 0.8 seconds
  myStepper1.step(1);
  myStepper2.step(-1);
  delay(10);
}
}
void backwardStep(int steps) {
  myStepper1.step(-1);
  myStepper2.step(1);
  delay(10);
}

void leftStep(int steps) {
  
  myStepper3.step(-stepsPerRevolution);
  forwardStep(steps); // Use the 'steps' parameter instead of 'int steps'
  myStepper3.step(stepsPerRevolution);
}

void rightStep(int steps) {

 myStepper3.step(stepsPerRevolution);
  forwardStep(steps); // Use the 'steps' parameter instead of 'int steps'
  myStepper3.step(-stepsPerRevolution);
}



void setup() {
  Serial.begin(9600);
  /////// setup the motors ////////
  myStepper1.setSpeed(60);
  myStepper2.setSpeed(60);
  myStepper3.setSpeed(40);
  ////////// Set the trigger pin as an output //////////
  pinMode(TRIGGER_PIN, OUTPUT);
  //////////// Set the echo pin as an input //////////
  pinMode(ECHO_PIN, INPUT);
  /////// set the hall effect sensor as as input_pullup //////////
  pinMode(hallSensorPin, INPUT_PULLUP); // Set the Hall sensor pin as input
}



void loop() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Measure the duration of the echo pulse
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance in centimeters
  float distance_cm = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  delay (500);


  while (Serial.available() > 0) {
    val = Serial.read();
    Serial.println(val);
  }

  




//////////////// order of movment to the motors /////////////////

  if (val == 'X') { // Forward
    rotate(num_of_steps);
  }
  if (val == 'F') { // Forward
    forwardStep2(num_of_steps);
  } else if (val == 'B') { // Backward
    backwardStep(num_of_steps);
  } else if (val == 'R'  && distance <= 100) { // Right
    rightStep(num_of_steps);
    forwardStep(num_of_steps);
  } else if (val == 'L'  && distance <= 100) { // Left
    leftStep(num_of_steps);
    forwardStep(num_of_steps);
  }
     else if (val == 'R'  && distance > 100) { // Right
    forwardStep(num_of_steps);
  }
   else if (val == 'L'  && distance > 100) { // Left
    forwardStep(num_of_steps);
  }
     
     



  
}
