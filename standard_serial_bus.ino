#include <SoftwareSerial.h>

// Pins to be used for slave select function
#define controller1 2
#define controller2 3
#define controller3 4
#define controller4 5

SoftwareSerial serial(10,11);

void setup() {
  // Set the slave select pins as outputs
  pinMode(controller1,OUTPUT);
  pinMode(controller2,OUTPUT);
  pinMode(controller3,OUTPUT);
  pinMode(controller4,OUTPUT);

  serial.begin(38400);
}

void loop() {
  // We will select each controller in sequentially and operate the motor attached to each
  digitalWrite(controller1, HIGH);
  serial.write(94);
  delay(2000);
  serial.write((byte)0);
  digitalWrite(controller1, LOW);
  delay(2000);
  

  digitalWrite(controller2, HIGH);
  serial.write(94);
  delay(2000);
  serial.write((byte)0);
  digitalWrite(controller2, LOW);
  delay(2000);
 

  digitalWrite(controller3, HIGH);
  serial.write(94);
  delay(2000);
  serial.write((byte)0);
  digitalWrite(controller3, LOW);
  delay(2000);
  

  digitalWrite(controller4, HIGH);
  serial.write(94);
  delay(2000);
  serial.write((byte)0);
  digitalWrite(controller4, LOW);
  delay(2000);
  
}
