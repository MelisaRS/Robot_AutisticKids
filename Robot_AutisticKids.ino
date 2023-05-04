//Libraries
#include <ezButton.h> //for the button
#include <ServoTimer2.h> //for ServoMotor, because this is Timer2 and don't have problems
//These libraries are for DFPlayer functionalities
//In this case we use dfplayer to have a better sound and have fewer conflicts with the servomotor
#include <SoftwareSerial.h> 
#include <DFRobotDFPlayerMini.h>

//Variables for Servomotors
/*creation of servomotors with the servoTimer2 library for 
the left arm, right arm, left leg, right leg, and head.*/
ServoTimer2 sLeftArm, sRightArm, sLeftLeg, sRightLeg, sphead;

/*These variables are for the servomotor pins that will generate the movements 
of the left arm, right arm, left leg, right leg, and head.*/
const int spLeftArm = 5;
const int spRightArm = 6;
const int spLeftLeg = 9;
const int spRightLeg = 10;
const int spHead = 11;

//Angles for the servos
const int saInitial = 750; //for 0 degree
const int saIntermediate = 1500; //for 90 degree
const int saFinal = 2250; //for around 180 degree

//States for the servos
const int sStateLeftArm = saInitial;
const int sStateRightArm = saInitial;
const int sStateLeftLeg = saInitial;
const int sStateRightLeg = saInitial;
const int sStateHead = saInitial;

//---------------------------------------

int buttonOnOffPin = 2;
int ledRedPin = 4;
int ledGreenPin = 8;

int buttonPin = 6;
int buttonOld = 1;
int buttonNew;

int dtI = 100;
int dt = 500;

int buttonFlag = 1;
//int buttonFlag;
//int aleatorio;

ezButton toggleSwitch(buttonOnOffPin);  // create ezButton object that attach to pin 7;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
