#include <SoftwareSerial.h>

// Pins to be used for slave select function
#define controller1 2
#define controller2 3
#define controller3 4
#define controller4 5

void run_controller(int, int, int);

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
  // We will select each controller sequentially and operate the motor attached to each
  run_controller(controller1, 94, 2000);
  delay(2000);

  run_controller(controller2, 94, 2000);
  delay(2000);

  run_controller(controller3, 94, 2000);
  delay(2000);

  run_controller(controller4, 94, 2000);
  delay(2000);
}


void run_controller(int controller, int speed, int run_time){
  // run_time is in milliseconds
  digitalWrite(controller, HIGH);
  delay(50);
  serial.write(speed);
  delay(run_time);
  serial.write((byte)0);
  delay(50);
  digitalWrite(controller, LOW);  
}
