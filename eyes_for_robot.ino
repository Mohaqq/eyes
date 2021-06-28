// C++ code
//
#include <Servo.h> 
#define tr 3  //trigger 
#define ech 2  //echo 
 
#define max_dis 20 // you can add more distance 
int p=0;
int distance=0;
int t=0;
Servo motor ;
void setup()
{
Serial.begin(9600);
delay(50);
pinMode(tr,OUTPUT);
pinMode(ech,INPUT);
motor.attach(9);
motor.write(180);

}

void loop()
{
  digitalWrite(tr,LOW); //for sonar 
  delayMicroseconds(5);
  digitalWrite(tr,HIGH);
  delayMicroseconds(10);
  digitalWrite(tr,LOW);
  t=pulseIn(ech,HIGH);
  distance=t/57;  // for convert the distance to cm 
for(p=0 ; p <180; p++){  
  Serial.println(distance);
  motor.write(p); 
  if(distance < 10 && distance > 0 )  {  // the servo (eyes) move even the sonar see anything near then it stop for a second or add any action you want 
     motor.write(90); // the servo stop in the middle for a person 
     delay(500);
 }
  }
  for(p=180 ; p>=1; p--){
      Serial.println(distance);
        motor.write(p);
  if(distance < 10 && distance > 0 )  { // the servo (eyes) move even the sonar see anything near then it stop for a second or add any action you want 
       motor.write(90);  //the servo stop in the middle for a person 
       delay(500);  
    }
      
}
}
