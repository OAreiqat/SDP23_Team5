#include <SoftwareSerial.h>

#define RF_F 21
#define RF_B 20
#define LF_F 10
#define LF_B 11
#define LB_F 12
#define LB_B 13
#define RB_F 19
#define RB_B 18
/*
#define RF_F 8
#define RF_B 7
#define LF_F 6
#define LF_B 5
#define LB_F 4
#define LB_B 3
#define RB_F 2
#define RB_B 1
*/

SoftwareSerial Bluetooth(16, 17); // Arduino(RX, TX) - HC-05 Bluetooth (TX, RX)

int dataIn, m;

void setup() {
	Serial.begin(9600);
	Bluetooth.begin(9600); // Default baud rate of the Bluetooth module
	Bluetooth.setTimeout(1);
	delay(20);
	pinMode(RF_F, OUTPUT);
	pinMode(RF_B, OUTPUT);
	pinMode(RB_F, OUTPUT);
	pinMode(RB_B, OUTPUT);
	pinMode(LF_F, OUTPUT);
	pinMode(LF_B, OUTPUT);
	pinMode(LB_F, OUTPUT);
	pinMode(LB_B, OUTPUT);
}




void loop() {
  // Check for incoming data

  if (Bluetooth.available() > 0) {
    dataIn = Bluetooth.read();  // Read the data
    Serial.println(dataIn);
    if(dataIn < 15) m = dataIn
  }
  switch(m) {
    case 0:
      stopMoving();         break;
    case 1:
	    moveLeftForward();    break;
    case 2:
      moveForward();        break;
    case 3:
      moveRightForward();   break;
    case 4:
      moveSidewaysLeft();   break;
    case 5:
      moveSidewaysRight();  break;
    case 6:
      moveLeftBackward();   break;
    case 7:
      moveBackward();       break;
    case 8:
      moveRightBackward();  break;
    case 9:
      rotateLeft();         break;
    case 10:
      rotateRight();        break;
  }
}


void moveForward() {
  //RF Forward
  digitalWrite(RF_F, HIGH);
  digitalWrite(RF_B, LOW);
  //LF Forward
  digitalWrite(LF_F, HIGH);
  digitalWrite(LF_B, LOW);
  //LB Forward
  digitalWrite(LB_F, HIGH);
  digitalWrite(LB_B, LOW);
  //RB Forward
  digitalWrite(RB_F, HIGH);
  digitalWrite(RB_B, LOW);
}
void moveBackward() {
  //RF Backward
  digitalWrite(RF_F, LOW);
  digitalWrite(RF_B, HIGH);
  //LF Backward
  digitalWrite(LF_F, LOW);
  digitalWrite(LF_B, HIGH);
  //LB Backward
  digitalWrite(LB_F, LOW);
  digitalWrite(LB_B, HIGH);
  //RB Backward
  digitalWrite(RB_F, LOW);
  digitalWrite(RB_B, HIGH);
}
void moveSidewaysRight() {
  //LF Forward
  digitalWrite(LF_F, HIGH);
  digitalWrite(LF_B, LOW);
  //LB Backward
  digitalWrite(LB_F, LOW);
  digitalWrite(LB_B, HIGH);
  //RF Backward
  digitalWrite(RF_F, LOW);
  digitalWrite(RF_B, HIGH);
  //RB Forward
  digitalWrite(RB_F, HIGH);
  digitalWrite(RB_B, LOW);
}
void moveSidewaysLeft() {
  //LF Backward
  digitalWrite(LF_F, LOW);
  digitalWrite(LF_B, HIGH);
  //LB Forward
  digitalWrite(LB_F, HIGH);
  digitalWrite(LB_B, LOW);
  //RF Forward
  digitalWrite(RF_F, HIGH);
  digitalWrite(RF_B, LOW);
  //RB Backward
  digitalWrite(RB_F, LOW);
  digitalWrite(RB_B, HIGH);
}
void rotateLeft() {
  //LF Backward
  digitalWrite(LF_F, LOW);
  digitalWrite(LF_B, HIGH);
  //LB Backward
  digitalWrite(LB_F, LOW);
  digitalWrite(LB_B, HIGH);
  //RF Forward
  digitalWrite(RF_F, HIGH);
  digitalWrite(RF_B, LOW);
  //RB Forward
  digitalWrite(RB_F, HIGH);
  digitalWrite(RB_B, LOW);
}
void rotateRight() {
  //LF Forward
  digitalWrite(LF_F, HIGH);
  digitalWrite(LF_B, LOW);
  //LB Forward
  digitalWrite(LB_F, HIGH);
  digitalWrite(LB_B, LOW);
  //RF Backward
  digitalWrite(RF_F, LOW);
  digitalWrite(RF_B, HIGH);
  //RB Backward
  digitalWrite(RB_F, LOW);
  digitalWrite(RB_B, HIGH);
}
void moveRightForward() {
  //LF Forward
  digitalWrite(LF_F, HIGH);
  digitalWrite(LF_B, LOW);
  //LB STOP
  digitalWrite(LB_F, LOW);
  digitalWrite(LB_B, LOW);
  //RF STOP
  digitalWrite(RF_F, LOW);
  digitalWrite(RF_B, LOW);
  //RB Forward
  digitalWrite(RB_F, HIGH);
  digitalWrite(RB_B, LOW);
}
void moveRightBackward() {
  //LF STOP
  digitalWrite(LF_F, LOW);
  digitalWrite(LF_B, LOW);
  //LB Backward
  digitalWrite(LB_F, LOW);
  digitalWrite(LB_B, HIGH);
  //RF Backward
  digitalWrite(RF_F, LOW);
  digitalWrite(RF_B, HIGH);
  //RB STOP
  digitalWrite(RB_F, LOW);
  digitalWrite(RB_B, LOW);
}
void moveLeftForward() {
  //LF STOP
  digitalWrite(LF_F, LOW);
  digitalWrite(LF_B, LOW);
  //LF Forward
  digitalWrite(LB_F, HIGH);
  digitalWrite(LB_B, LOW);
  //RF Forward
  digitalWrite(RF_F, HIGH);
  digitalWrite(RF_B, LOW);
  //RB STOP
  digitalWrite(RB_F, LOW);
  digitalWrite(RB_B, LOW);
}
void moveLeftBackward() {
  //LF Backward
  digitalWrite(LF_F, LOW);
  digitalWrite(LF_B, HIGH);
  //LB STOP
  digitalWrite(LB_F, LOW);
  digitalWrite(LB_B, LOW);
  //RF STOP
  digitalWrite(RF_F, LOW);
  digitalWrite(RF_B, LOW);
  //RB Backward
  digitalWrite(RB_F, LOW);
  digitalWrite(RB_B, HIGH);
}
void stopMoving() {
  //RF STOP
  digitalWrite(RF_F, LOW);
  digitalWrite(RF_B, LOW);
  //LF STOP
  digitalWrite(LF_F, LOW);
  digitalWrite(LF_B, LOW);
  //LB STOP
  digitalWrite(LB_F, LOW);
  digitalWrite(LB_B, LOW);
  //RB STOP
  digitalWrite(RB_F, LOW);
  digitalWrite(RB_B, LOW);
}