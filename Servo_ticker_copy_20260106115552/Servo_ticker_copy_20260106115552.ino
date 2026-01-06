#include<Servo.h>
Servo motor;
void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  motor.attach(0);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
motor.write(0);
digitalWrite(LED_BUILTIN, HIGH); 
delay(15000);
motor.write(180);
 digitalWrite(LED_BUILTIN, LOW);
delay(15000);
}
