#include<Servo.h>


 Servo motor;
void setup() 
{
 motor.attach(9);
 Serial.begin(9600);
   motor.write(0);
}

void loop() {
  int isik = analogRead(A0);
  Serial.println(isik);
  delay(100);
     motor.write(0);
  if(isik >900)
  {
   
  }
}
