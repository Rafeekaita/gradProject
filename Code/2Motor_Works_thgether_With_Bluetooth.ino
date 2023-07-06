
#include <Stepper.h>
const int stepsPerRevolution = 200; 

char val;

//enter the steps per rev for your motors here
int stepsInRev = 200;

//this sets the value for the for loops and therefore sets the amount of steps in each call
int num_of_steps = 1;
int stopMotor = 0;

Stepper myStepper1(stepsInRev, 4, 5, 6, 7);
Stepper myStepper2(stepsInRev, 8, 9, 10, 11);






void forwardStep(int steps){
  Serial.println("forward");

  myStepper1.step(-1);
  myStepper2.step(-1);
  delay(10);
}

void backwardStep(int steps){
  Serial.println("backward");

  myStepper1.step(1);
  myStepper2.step(1);
  delay(10);
}
 


void leftStep(int steps){
  Serial.println("left");

  myStepper1.step(1);
  myStepper2.step(-1);
  delay(10);
}



void rightStep(int steps){
  Serial.println("right");

  myStepper1.step(-1);
  myStepper2.step(1);
  delay(10); 
}


void allStop(int steps){
  Serial.println("stop");

    myStepper1.step(0);
    myStepper2.step(0);
}
void setup() {
  Serial.begin(9600);
  myStepper1.setSpeed(70);
  myStepper2.setSpeed(70);

}


void loop()
{
  while (Serial.available() > 0)
  {
  val = Serial.read();
  Serial.println(val);
  }

  if( val == 'F') // Forward
    {
     forwardStep(num_of_steps);
    }
  else if(val == 'B') // Backward
    {
      backwardStep(num_of_steps);
    }
  else if(val == 'S') //Stop
    {
      allStop(stopMotor);
    }

}

