#include <Wire.h>
#include <Adafruit_MotorShield.h>

//create the motor shield object with the default 12C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

//select which 'port' M1, M2, M3, M4. In this case M4
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);

void setup() 
{
  Serial.begin(9600);       //set up Serial library at 9600 bps
  Serial.println("Motorshield - Let's run some DC motors!");

  AFMS.begin(); // create with the default frequency 1.6KHz

  //set the speed to start, from 0 (off) to 255 (max speed)
  myMotor->setSpeed(150);
  myMotor->run(FORWARD);
  //turn on motor
  myMotor->run(RELEASE);
}

void loop() 
{
  uint8_t i;
  Serial.print("forward");
  myMotor->run(FORWARD);
  //keep increasing the motor speed forward
  for (i=0; i<255; i++)
  {
    myMotor->setSpeed(1);
    delay(10);
  }

  //keep decreasing the motor speed forward
  for (i=255; i!=0; i--)
  {
    myMotor->setSpeed(i);
    delay(10);
  }

}


