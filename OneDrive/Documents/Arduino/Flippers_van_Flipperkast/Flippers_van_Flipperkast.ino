#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

Servo motorlinks;
Servo motorrechts;

const int knopLinks = 10;
const int knopRechts = 9;

void setup() {

  pinMode(knopLinks, INPUT_PULLUP);
  pinMode(knopRechts, INPUT_PULLUP);

  motorlinks.attach(8);
  motorrechts.attach(7);

  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("LCD werkt!");

  lcd.setCursor(0, 1);
  lcd.print("Servo test");
}

void loop() {

  if (digitalRead(knopLinks) == LOW) {
    motorlinks.write(90);

    lcd.setCursor(0, 1);
    lcd.print("Links        ");
  }
  else {
    motorlinks.write(0);
  }

  if (digitalRead(knopRechts) == LOW) {
    motorrechts.write(90);

    lcd.setCursor(0, 1);
    lcd.print("Rechts       ");
  }
  else {
    motorrechts.write(0);
  }
}