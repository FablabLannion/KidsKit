
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

#define JOYSTICK 0 // analog pin used to connect the joystick
#define SERVO 3
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(SERVO);  // attaches the servo on pin 9 to the servo object
  myservo.write(90);
  Serial.begin (115200);
  delay (1000);
}

void loop() {
  val = analogRead(JOYSTICK);            // reads the value of the potentiometer (value between 0 and 1023)
  Serial.print(val);
  Serial.print("->");
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  Serial.println(val);
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}

