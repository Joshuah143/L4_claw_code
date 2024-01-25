#include <Servo.h>

int pos = 0;
int deg = 90;
Servo servo_9;
int inches = 0;
int cm = 0;
int triggerPin = 7; 
int echoPin = 6;
int counter = 0;
int lastCm[10] = {0};
int state = 0; \\ 0 is open 1 is closed


long readUltrasonicDistancecm() {
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microsecond 
  return 0.01723 * pulseIn(echoPin, HIGH);
}

int all_close() {
  int close_to_ground = 1;
  for (int i = 0; i <10 ; i++){
    if (lastCm[i]>10) {
      close_to_ground = 0;
    } 
  }
  return all_close();
}

void open(){
  servo_9.write(0)
}

void close(){
  servo_9.write(170)
}


void setup()
{
  servo_9.attach(9);
}

void loop()
{
  cm =  readUltrasonicDistance();
  lastCm[counter++ % 10] = cm;
  int temp =  all_close();
  if (temp == 1) {
    if (state) {
      open();
    } else {
      close();
    }
  } 
  delay(20);
}
