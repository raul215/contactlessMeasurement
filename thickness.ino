// author Rahul Raj Shah @rahulrajshah42@gmail.com

#include <Wire.h>

#include <LiquidCrystal_I2C.h>



LiquidCrystal_I2C lcd(0x27,16,2);

const int trigPin =4;
const int echoPin =11;

long duration;
int distace;

void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop()
{ 
  lcd.clear();
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  int distance = duration*0.034/2;
  int thickness = distance;

  
  Serial.print("Thickness: ");
  Serial.println(thickness);
  lcd.setCursor(0,1);
  lcd.print("Thickness:");
  lcd.print(thickness);
  lcd.print("cm"); 
  delay(100);
}
