//Libraries
#include <ezButton.h>     //for the button
#include <ServoTimer2.h>  //for ServoMotor, because this is Timer2 and don't have problems
//These libraries are for DFPlayer functionalities
//In this case we use dfplayer to have a better sound and have fewer conflicts with the servomotor
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

//Variables for Servomotors
/*creation of servomotors with the servoTimer2 library for 
the left arm, right arm, left leg, right leg, and head.*/
ServoTimer2 sLeftArm, sRightArm, sLeftLeg, sRightLeg, sHead;

/*These variables are for the servomotor pins that will generate the movements 
of the left arm, right arm, left leg, right leg, and head.*/
const int spLeftArm = 5;
const int spRightArm = 6;
const int spLeftLeg = 9;
const int spRightLeg = 10;
const int spHead = 11;

//Angles for the servos
const int saInitial = 750;        //for 0 degree
const int saIntermediate = 1500;  //for 90 degree
const int saFinal = 2250;         //for around 180 degree

//States for the servos
const int sState = saInitial;
const int sStateLeftArm = saInitial;
const int sStateRightArm = saInitial;
const int sStateLeftLeg = saInitial;
const int sStateRightLeg = saInitial;
const int sStateHead = saInitial;

//---------------------------------------

//Variables for Switch

const int switchP = 7;  //Pin for switch
//only for test //these are optional for this moment
const int ledRedP = 2;    //off
const int ledGreenP = 2;  //on

// Variables for Button
const int buttonP = 8;  //Pin for button

//States for the buttons
int buttonOld = 1;
int buttonNew;

//Flag for button
int buttonFlag = 1;

//create ezButton object for Switch
ezButton toggleSwitch(switchP);

//---------------------------------------
//times por daleys
int dtI = 100;
int dt = 500;

////////////////////////////////////////////////
///////////     Initializations     ///////////
//////////////////////////////////////////////

void setup() {

  Serial.begin(9600);

  //For Servomotors
  sLeftArm.attach(spLeftArm);
  sRightArm.attach(spRightArm);
  sLeftLeg.attach(spLeftLeg);
  sRightLeg.attach(spRightLeg);
  sHead.attach(spHead);

  //For Switch
  toggleSwitch.setDebounceTime(50);  // set debounce time to 50 milliseconds
  pinMode(ledRedP, OUTPUT);
  pinMode(ledGreenP, OUTPUT);

  //For Button
  pinMode(buttonP, INPUT);

  //For Funtion Random
  randomSeed(analogRead(A5));
  delay(2000);
  buttonFlag = random(1, 6);

  Serial.println("El numero aleatorio INICIAL es: ");
  Serial.println(buttonFlag);
}

////////////////////////////////////////////////
///////////         Funtions        ///////////
//////////////////////////////////////////////

void leftArmMovements() {
  /*
  sLeftArm.write(saInitial);
  delay(dt);
  myServo2.write(saIntermediate);
  delay(dt);
  myServo2.write(saFinal);
  delay(dt);
  myServo2.write(saIntermediate);
  delay(dt);
  myServo2.write(saInitial);
  delay(dt);
  */

  // Move the servo of 0 to 180 dregrees
  for (int pos = saInitial; pos <= saFinal; pos += 15) {
    sLeftArm.write(pos);
    delay(15);
  }

  // Move the servo of 180 to 0 dregrees
  for (int pos = saFinal; pos >= saInitial; pos -= 15) {
    sLeftArm.write(pos);
    delay(15);
  }
}

void rightArmMovements() {
  // Move the servo of 0 to 180 dregrees
  for (int pos = saInitial; pos <= saFinal; pos += 15) {
    sRightArm.write(pos);
    delay(15);
  }

  // Move the servo of 180 to 0 dregrees
  for (int pos = saFinal; pos >= saInitial; pos -= 15) {
    sRightArm.write(pos);
    delay(15);
  }
}


void leftLegMovements() {
  // Move the servo of 0 to 180 dregrees
  for (int pos = saInitial; pos <= saFinal; pos += 15) {
    sLeftLeg.write(pos);
    delay(15);
  }

  // Move the servo of 180 to 0 dregrees
  for (int pos = saFinal; pos >= saInitial; pos -= 15) {
    sLeftLeg.write(pos);
    delay(15);
  }
}

void rightLegMovements() {
  // Move the servo of 0 to 180 dregrees
  for (int pos = saInitial; pos <= saFinal; pos += 15) {
    sRightLeg.write(pos);
    delay(15);
  }

  // Move the servo of 180 to 0 dregrees
  for (int pos = saFinal; pos >= saInitial; pos -= 15) {
    sRightLeg.write(pos);
    delay(15);
  }
}

void headMovements() {
  // Move the servo of 0 to 180 dregrees
  for (int pos = saInitial; pos <= saFinal; pos += 15) {
    sHead.write(pos);
    delay(15);
  }

  // Move the servo of 180 to 0 dregrees
  for (int pos = saFinal; pos >= saInitial; pos -= 15) {
    sHead.write(pos);
    delay(15);
  }
}

void bothArmsCombinationMovements() {
  // Move the servo of 0 to 180 dregrees
  for (int pos = saInitial; pos <= saFinal; pos += 15) {
    sLeftArm.write(pos);
    sRightArm.write(pos);
    delay(15);
  }

  // Move the servo of 180 to 0 dregrees
  for (int pos = saFinal; pos >= saInitial; pos -= 15) {
    sLeftArm.write(pos);
    sRightArm.write(pos);
    delay(15);
  }
}

void loop() {

  /*leftArmMovements();
  rightArmMovements();
  bothArmsCombinationMovements();*/

  //these IFs verify the status of the button and servo for its operation
  if (buttonNew == 0 && buttonOld == 1) {

    if (sStateLeftArm == 0 && buttonFlag == 1) {
      leftArmMovements();
      buttonFlag = random(1, 7);
      delay(dtI);
    } else if (sState == 0 && buttonFlag == 2) {
      rightArmMovements();
      buttonFlag = random(1, 7);
      delay(dtI);
    } else if (sState == 0 && buttonFlag == 3) {
      leftLegMovements();
      buttonFlag = random(1, 7);
      delay(dtI);
    } else if (sState == 0 && buttonFlag == 5) {
      rightLegMovements();
      buttonFlag = random(1, 7);
      delay(dtI);
    } else if (sState == 0 && buttonFlag == 4) {
      headMovements();
      buttonFlag = random(1, 7);
      delay(dtI);
    } else if (sState == 0 && buttonFlag == 5) {
      bothArmsCombinationMovements();
      buttonFlag = random(1, 7);
      delay(dtI);
    }


    /*
    switch (buttonFlag) {
      case 1:
        leftArmMovements();
        buttonFlag = random(1, 7);
        Serial.print("El numero aleatorio es: ");
        Serial.println(buttonFlag);
        delay(dtI);
        //break;

      case 2:
        rightArmMovements();
        buttonFlag = random(1, 7);
        Serial.print("El numero aleatorio es: ");
        Serial.println(buttonFlag);
        delay(dtI);
        //break;

      case 3:
        leftLegMovements();
        buttonFlag = random(1, 7);
        Serial.print("El numero aleatorio es: ");
        Serial.println(buttonFlag);
        delay(dtI);
        //break;

      case 4:
        rightLegMovements();
        buttonFlag = random(1, 7);
        Serial.print("El numero aleatorio es: ");
        Serial.println(buttonFlag);      
        delay(dtI);
        //break;

      case 5:
        headMovements();
        buttonFlag = random(1, 7);
        Serial.print("El numero aleatorio es: ");
        Serial.println(buttonFlag);
        delay(dtI);
        //break;

      case 6:
        bothArmsCombinationMovements();
        buttonFlag = random(1, 7);
        Serial.print("El numero aleatorio es: ");
        Serial.println(buttonFlag);
        delay(dtI);
        //break;
    }
    */
  }
  buttonOld = buttonNew;
}
