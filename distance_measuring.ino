#include<LiquidCrystal.h>
const int  trigPin =  9;
const int  echoPin = 10;
LiquidCrystal lcd (2,3,4,5,6,7);

float time=0,distance=0;
 
void setup()
{
 lcd.begin(16,2);
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 lcd.print("Industrial Electronics");
 lcd.setCursor(0,1);
 lcd.print("Distance Meter");
 delay(2000);
 lcd.clear();
 Serial.begin(9600);
}
 
void loop()
{
 lcd.clear();
 digitalWrite(trigPin ,LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin ,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin ,LOW);
 delayMicroseconds(2);
 time=pulseIn(echoPin,HIGH);
 distance=time*344/20000;
 lcd.clear();
 lcd.print("Distance:");
 lcd.print(distance);
 lcd.print("cm");
 Serial.print(distance);
 Serial.println("cm");
 lcd.setCursor(0,1);
 lcd.print("Distance:");
 lcd.print(distance/100);
 lcd.print("m");
 Serial.print(distance/100);
 Serial.println("m");
 delay(1000);
}
