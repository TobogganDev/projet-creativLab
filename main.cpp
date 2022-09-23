#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);

int i = 0;
int a;
int b;
int result = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); 
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  a = analogRead(A0);
  b = digitalRead(5);
  i = map(a, 0, 1023, 0, 255);
  if (a >= 50 && a <= 950){
    analogWrite(4, 0);
    analogWrite(3, 0);
  }else {
    analogWrite(4, i);
    analogWrite(3, (255-i));
  }
  if (a == 1023 || a == 0){
    result++;
    delay(150);
  }
  Serial.println(result);
  if (b == 1){
    result = 0;
    digitalWrite(3,255);
    digitalWrite(4,255);
    lcd.setCursor(2,0);
    lcd.print("Votre Score :");
    lcd.setCursor(6,1);
    lcd.print("        ");
  }
  lcd.setCursor(2,0);
  lcd.print("Votre Score :");
  lcd.setCursor(6,1);
  lcd.print("-");
  lcd.print(result);
  lcd.print("-");
}
