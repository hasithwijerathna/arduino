/*
written by Hasith 
for automate water pump 
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3,POSITIVE);

#define trig 2
#define echo 4
#define buzzer 8
#define relay 1

void setup(){
  
  Serial.begin(9600);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);
  
  digitalWrite(relay, HIGH);
  
  lcd.begin(16, 2);
  
  //lcd.setCursor(0,0);
  //lcd.print("Hasith");
}

void loop(){
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  long t = pulseIn(echo, HIGH);
  
  long inch = t/(148);
  long cm = t/58;
  
  //tone(buzzer, 1000, 500);
  
  if(cm < 25){
      tone(buzzer, 1450);
      digitalWrite(relay, LOW);
  } else {
      noTone(buzzer);
      digitalWrite(relay, HIGH);
  }
  
  delay(100);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("cm : ");
  lcd.print(cm);
  
}
