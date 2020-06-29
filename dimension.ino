// author Rahul Raj Shah @rahulrajshah42@gmail.com

#include <QuickStats.h>

#include <Wire.h>

#include <LiquidCrystal_I2C.h>




LiquidCrystal_I2C lcd(0x27,16,2);

QuickStats stats;

int sample = 100;

const int l_trigPin = 12;
const int l_echoPin = 9;

const int b_trigPin = 7;
const int b_echoPin = 6;

const int h_trigPin = 4;
const int h_echoPin = 11;

long duration;
//int distance;

void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(l_trigPin, OUTPUT);
  pinMode(l_echoPin, INPUT);

  pinMode(b_trigPin, OUTPUT);
  pinMode(b_echoPin, INPUT);

  pinMode(h_trigPin, OUTPUT);
  pinMode(h_echoPin, INPUT);
  
  Serial.begin(9600);
  lcd.begin(16,2);

  

}

void loop()
{ lcd.clear();
  float filter[sample] = {};
  for (int i=0;i<sample;i++){
    filter[i] = distance(l_trigPin, l_echoPin, 37.00, "L", 0, 0);
    //Serial.println(filter[i]);
    }
   Serial.println(stats.mode(filter,sample,0.00001));
  distance(l_trigPin, l_echoPin, 37.00, "L", 0, 0);
  distance(b_trigPin, b_echoPin, 26.00, "B", 7, 0);
  distance(h_trigPin, h_echoPin, 43.00, "H", 0, 1);
  delay(200);
}


float distance(int trig, int echo, float thresh, char dim[], int r, int c) 
{
  float temp;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  temp = (thresh - (pulseIn(echo, HIGH) * 0.034/2));
  lcd.setCursor(r,c);
  lcd.print(dim); 
  lcd.print(":");
  lcd.print(temp);
  return temp;
  }
