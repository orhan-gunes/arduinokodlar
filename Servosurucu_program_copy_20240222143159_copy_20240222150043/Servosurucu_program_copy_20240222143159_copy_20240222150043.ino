#include<Servo.h>

Servo motor;



int pod=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor.attach(9);
  motor.write(0);
  Serial.println("Motor Sıfırlandı");

}

void loop() 
{
delay(10000);
int rd= motor.read();
Serial.println(rd);
if(rd==0){
 motor.write(90);
}
else{
  motor.write(0);
}



}
