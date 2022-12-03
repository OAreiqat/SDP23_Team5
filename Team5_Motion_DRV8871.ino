

#include <SoftwareSerial.h>

#define RF_F 21
#define RF_B 20
#define LF_F 10
#define LF_B 11
#define LB_F 12
#define LB_B 13
#define RB_F 19
#define RB_B 18

SoftwareSerial Bluetooth(16, 17); // Arduino(RX, TX) - HC-05 Bluetooth (TX, RX)

int wheelSpeed = 1500;

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
    // Update speed // to be tested 
    if (dataIn >= 16) {
      wheelSpeed = map(dataIn, 16, 255, 0 , 255); // Map the potentiometer value from 0 to 255
      // Serial.println(wheelSpeed);
      // analogWrite(LF_F, wheelSpeed); 
      // analogWrite(LF_B, wheelSpeed); 
      // analogWrite(RF_F, wheelSpeed); 
      // analogWrite(RF_B, wheelSpeed); 
      // analogWrite(LB_F, wheelSpeed); 
      // analogWrite(LB_B, wheelSpeed); 
      // analogWrite(RB_F, wheelSpeed); 
      // analogWrite(RB_B, wheelSpeed); 
	
    }
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

void moveForward() {
  //RF Forward
  analogWrite(RF_F, wheelSpeed);
  digitalWrite(RF_B, LOW);
  //LF Forward
  analogWrite(LF_F, wheelSpeed);
  digitalWrite(LF_B, LOW);
  //LB Forward
  analogWrite(LB_F, wheelSpeed);
  digitalWrite(LB_B, LOW);
  //RB Forward
  analogWrite(RB_F, wheelSpeed);
  digitalWrite(RB_B, LOW);
}
void moveBackward() {
  //RF Backward
  digitalWrite(RF_F, LOW);
  analogWrite(RF_B, wheelSpeed);
  //LF Backward
  digitalWrite(LF_F, LOW);
  analogWrite(LF_B, wheelSpeed);
  //LB Backward
  digitalWrite(LB_F, LOW);
  analogWrite(LB_B, wheelSpeed);
  //RB Backward
  digitalWrite(RB_F, LOW);
  analogWrite(RB_B, wheelSpeed);
}
void moveSidewaysRight() {
  //LF Forward
  analogWrite(LF_F, wheelSpeed);
  digitalWrite(LF_B, LOW);
  //LB Backward
  digitalWrite(LB_F, LOW);
  analogWrite(LB_B, wheelSpeed);
  //RF Backward
  digitalWrite(RF_F, LOW);
  analogWrite(RF_B, wheelSpeed);
  //RB Forward
  analogWrite(RB_F, wheelSpeed);
  digitalWrite(RB_B, LOW);
}
void moveSidewaysLeft() {
  //LF Backward
  digitalWrite(LF_F, LOW);
  analogWrite(LF_B, wheelSpeed);
  //LB Forward
  analogWrite(LB_F, wheelSpeed);
  digitalWrite(LB_B, LOW);
  //RF Forward
  analogWrite(RF_F, wheelSpeed);
  digitalWrite(RF_B, LOW);
  //RB Backward
  digitalWrite(RB_F, LOW);
  analogWrite(RB_B, wheelSpeed);
}
void rotateLeft() {
  //LF Backward
  digitalWrite(LF_F, LOW);
  analogWrite(LF_B, wheelSpeed);
  //LB Backward
  digitalWrite(LB_F, LOW);
  analogWrite(LB_B, wheelSpeed);
  //RF Forward
  analogWrite(RF_F, wheelSpeed);
  digitalWrite(RF_B, LOW);
  //RB Forward
  analogWrite(RB_F, wheelSpeed);
  digitalWrite(RB_B, LOW);
}
void rotateRight() {
  //LF Forward
  analogWrite(LF_F, wheelSpeed);
  digitalWrite(LF_B, LOW);
  //LB Forward
  analogWrite(LB_F, wheelSpeed);
  digitalWrite(LB_B, LOW);
  //RF Backward
  digitalWrite(RF_F, LOW);
  analogWrite(RF_B, wheelSpeed);
  //RB Backward
  digitalWrite(RB_F, LOW);
  analogWrite(RB_B, wheelSpeed);
}
void moveRightForward() {
  //LF Forward
  analogWrite(LF_F, wheelSpeed);
  digitalWrite(LF_B, LOW);
  //LB STOP
  digitalWrite(LB_F, LOW);
  digitalWrite(LB_B, LOW);
  //RF STOP
  digitalWrite(RF_F, LOW);
  digitalWrite(RF_B, LOW);
  //RB Forward
  analogWrite(RB_F, wheelSpeed);
  digitalWrite(RB_B, LOW);
}
void moveRightBackward() {
  //LF STOP
  digitalWrite(LF_F, LOW);
  digitalWrite(LF_B, LOW);
  //LB Backward
  digitalWrite(LB_F, LOW);
  analogWrite(LB_B, wheelSpeed);
  //RF Backward
  digitalWrite(RF_F, LOW);
  analogWrite(RF_B, wheelSpeed);
  //RB STOP
  digitalWrite(RB_F, LOW);
  digitalWrite(RB_B, LOW);
}
void moveLeftForward() {
  //LF STOP
  digitalWrite(LF_F, LOW);
  digitalWrite(LF_B, LOW);
  //LF Forward
  analogWrite(LB_F, wheelSpeed);
  digitalWrite(LB_B, LOW);
  //RF Forward
  analogWrite(RF_F, wheelSpeed);
  digitalWrite(RF_B, LOW);
  //RB STOP
  digitalWrite(RB_F, LOW);
  digitalWrite(RB_B, LOW);
}
void moveLeftBackward() {
  //LF Backward
  digitalWrite(LF_F, LOW);
  analogWrite(LF_B, wheelSpeed);
  //LB STOP
  digitalWrite(LB_F, LOW);
  digitalWrite(LB_B, LOW);
  //RF STOP
  digitalWrite(RF_F, LOW);
  digitalWrite(RF_B, LOW);
  //RB Backward
  digitalWrite(RB_F, LOW);
  analogWrite(RB_B, wheelSpeed);
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