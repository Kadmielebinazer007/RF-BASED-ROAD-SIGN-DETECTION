#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int rfinput = A0;                  
int buzzer = D8;

int count = 0;

void setup() 
{  
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);

  pinMode(rfinput, INPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);

  lcd.setCursor(0, 0);
  lcd.print("   Road Signs   ");
  lcd.setCursor(0, 1);
  lcd.print("Identity System ");
  delay(2000);
  lcd.setCursor(0, 0);
  lcd.print("Connecting......");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  delay(2000);
  lcd.clear();
}

void loop() 
{
  int rfr = analogRead(rfinput);
  int rf = rfr / 5;

  // lcd.setCursor(0, 0);
  // lcd.print("Area:");
  // lcd.print(rf);
  // lcd.print("    ");
  lcd.setCursor(13, 0);
  lcd.print(count);
  lcd.print("  ");

  if (rf > 10) { 
    count++;
  } 
  else if (rf < 10 && count > 0) {  
    count--; 
  }

  // lcd.setCursor(0, 1);
  // lcd.print("S: ");
  // lcd.setCursor(5, 1);

  if (count > 5) 
  {
    lcd.setCursor(0, 0);
    lcd.print("School Zone");
    lcd.setCursor(0, 1);
    lcd.print("  Go Slow  ");
    digitalWrite(buzzer, HIGH);
    delay(2000);
    digitalWrite(buzzer, LOW);
    delay(1000);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(1000);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(1000);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(1000);
    digitalWrite(buzzer, HIGH);
  } 
  else 
  {
    lcd.setCursor(0, 0);
    lcd.print(" Normal     ");
    lcd.setCursor(0, 1);
    lcd.print("            ");
    digitalWrite(buzzer, LOW);
  }

  delay(100);
}
