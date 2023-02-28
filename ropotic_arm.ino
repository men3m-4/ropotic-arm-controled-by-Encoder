#include <Servo.h>
// Rotary Encoder Inputs
#define CLK 2
#define CLK2 4
#define DT 3
#define DT2 5
Servo servo;
Servo servo2;
int counter = 0;
int counter2 = 0;
int currentStateCLK;
int lastStateCLK;
int currentStateCLK2;
int lastStateCLK2;
void setup() {
  // Set encoder pins as inputs
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(CLK2,INPUT);
  pinMode(DT2,INPUT);
  // Setup Serial Monitor
  Serial.begin(9600);
  // Attach servo on pin 9 to the servo object
  servo.attach(9);
  servo2.attach(10);
  servo.write(counter);
   servo2.write(counter);
  // Read the initial state of CLK
  lastStateCLK = digitalRead(CLK);
  lastStateCLK2 = digitalRead(CLK2);
}
void loop() {
  // Read the current state of CLK
  currentStateCLK = digitalRead(CLK);
  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){
    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT) != currentStateCLK) {
      counter --;
      if (counter<0)
        counter=0;
    } else {
      // Encoder is rotating CW so increment
      counter ++;
      if (counter>179)
        counter=179;
    }
    // Move the servo
    servo.write(counter);
    Serial.print("Position: ");
    Serial.println(counter);
  }
  // Remember last CLK state
  lastStateCLK = currentStateCLK;
  
  ////////////////////////////////////////////////////////////////////////////////////////////
  
  // Read the current state of CLK
  currentStateCLK2 = digitalRead(CLK2);
  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK2 != lastStateCLK2  && currentStateCLK2 == 1){
    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT2) != currentStateCLK2) {
      counter2 --;
      if (counter2<0)
        counter2=0;
    } else {
      // Encoder is rotating CW so increment
      counter2 ++;
      if (counter2>179)
        counter2=179;
    }
    // Move the servo
    servo2.write(counter2);
    Serial.print("Position2: ");
    Serial.println(counter2);
  }
  // Remember last CLK state
  lastStateCLK2 = currentStateCLK2;

}
