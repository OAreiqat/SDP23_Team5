// Pins for rp2040 thing plus
#define echoPin0 20 // PIN 2 Orange
#define trigPin0 16 // PIN 28 Yellow

#define echoPin1 8 // PIN 20
#define trigPin1 6 // PIN 10

#define toMotor 12 // PIN 4 Green
#define LED 9 // PIN 21

// defines variables
long duration0; // variable for the duration of sound wave travel
long duration1;

int distance0; // variable for the distance measurement
int distance1;

bool objectBlock;
bool offEdge; // variable for if the cart is off edge
bool stopCart; 

void setup() {  
  pinMode(trigPin0, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(trigPin1, OUTPUT);

  pinMode(echoPin0, INPUT); // Sets the echoPin as an INPUT
  pinMode(echoPin1, INPUT);

  pinMode(toMotor, OUTPUT);
  pinMode(LED, OUTPUT);
  
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with RP2040 Thing Plus");
}

void loop() {
  // Clears the trigPin0 condition
  digitalWrite(trigPin0, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin0 HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin0, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin0, LOW);
  
  // Reads the echoPin0, returns the sound wave travel time in microseconds
  duration0 = pulseIn(echoPin0, HIGH);

  // Clears the trigPin1 condition
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);

  // Sets the trigPin1 HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  // Reads the echoPin1, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  
  // Calculating the distance
  distance0 = duration0 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  distance1 = duration1 * 0.034 / 2;

  // Conditionals
  if (distance0 < 7) {
    offEdge = false;
  } else {
    offEdge = true;
  }
  
  if (distance1 > 15) {
    objectBlock = false;
  } else {
    objectBlock = true;
  }

  if (offEdge == true || objectBlock == true) {
    stopCart = true;

  } else {
    stopCart = false;
  }
  
  digitalWrite(LED, stopCart);
  digitalWrite(toMotor, stopCart);

//   Displays on the Serial Monitor
  Serial.print("Distance Sensor0: ");
  Serial.print(distance0);
  Serial.println(" cm");

  Serial.print("Distance Sensor1: ");
  Serial.print(distance1);
  Serial.println(" cm");
  
  Serial.print("Off Edge: ");
  Serial.println(offEdge);

  Serial.print("Object Blocking: ");
  Serial.print(objectBlock);
  Serial.println("\n");

  Serial.print("Stop Cart: ");
  Serial.print(stopCart);
  Serial.println("\n");
  
  delay(100);
}

// Pins for rp2040 thing plus
#define echoPin0 20 // PIN 2 Orange
#define trigPin0 16 // PIN 28 Yellow

#define echoPin1 8 // PIN 20
#define trigPin1 6 // PIN 10

#define toMotor 12 // PIN 4 Green
#define LED 9 // PIN 21

// defines variables
long duration0; // variable for the duration of sound wave travel
long duration1;

int distance0; // variable for the distance measurement
int distance1;

bool objectBlock;
bool offEdge; // variable for if the cart is off edge
bool stopCart; 

void setup() {  
  pinMode(trigPin0, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(trigPin1, OUTPUT);

  pinMode(echoPin0, INPUT); // Sets the echoPin as an INPUT
  pinMode(echoPin1, INPUT);

  pinMode(toMotor, OUTPUT);
  pinMode(LED, OUTPUT);
  
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with RP2040 Thing Plus");
}

void loop() {
  // Clears the trigPin0 condition
  digitalWrite(trigPin0, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin0 HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin0, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin0, LOW);
  
  // Reads the echoPin0, returns the sound wave travel time in microseconds
  duration0 = pulseIn(echoPin0, HIGH);

  // Clears the trigPin1 condition
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);

  // Sets the trigPin1 HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  // Reads the echoPin1, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  
  // Calculating the distance
  distance0 = duration0 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  distance1 = duration1 * 0.034 / 2;

  // Conditionals
  if (distance0 < 7) {
    offEdge = false;
  } else {
    offEdge = true;
  }
  
  if (distance1 > 15) {
    objectBlock = false;
  } else {
    objectBlock = true;
  }

  if (offEdge == true || objectBlock == true) {
    stopCart = true;

  } else {
    stopCart = false;
  }
  
  digitalWrite(LED, stopCart);
  digitalWrite(toMotor, stopCart);

//   Displays on the Serial Monitor
  Serial.print("Distance Sensor0: ");
  Serial.print(distance0);
  Serial.println(" cm");

  Serial.print("Distance Sensor1: ");
  Serial.print(distance1);
  Serial.println(" cm");
  
  Serial.print("Off Edge: ");
  Serial.println(offEdge);

  Serial.print("Object Blocking: ");
  Serial.print(objectBlock);
  Serial.println("\n");

  Serial.print("Stop Cart: ");
  Serial.print(stopCart);
  Serial.println("\n");
  
  delay(100);
}

