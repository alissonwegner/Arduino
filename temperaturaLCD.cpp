// C++ code
#include <LiquidCrystal.h>
#define led_vermelho 8
#define led_verde 9
#define temp A0
#define BRILHO A1
LiquidCrystal lcd (12, 11, 5, 4, 3, 2);
void setup()
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(BRILHO, OUTPUT);
  pinMode(temp, INPUT);
  Serial.begin(9600);
  lcd.begin (16, 2);
  Serial.begin(9600);
  int brilho = 1023;
  analogWrite(BRILHO, brilho);
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperatura: ");
  lcd.setCursor(0, 1);
  int sensor_temp;
  sensor_temp = analogRead(temp);
 float volts = ((float)sensor_temp*5)/1024;
  Serial.print("\n valor lido: ");
  Serial.print(volts);
  float tempc =( volts -0.5)*100;
  Serial.print("\n temperatura: ");
  Serial.print(tempc);
  lcd.print(tempc);
  delay(1000);


//led de teste
  if (tempc <= 25) {
    digitalWrite(led_vermelho, LOW);
  	digitalWrite(led_verde, HIGH);
} else if (tempc > 25) {
    digitalWrite(led_verde, LOW);
    digitalWrite(led_vermelho, HIGH);
}
  
    delay(1000);

 // digitalWrite(led, HIGH);
 // delay(1000); // Wait for 1000 millisecond(s)
 // digitalWrite(led, LOW);
 // delay(1000); // Wait for 1000 millisecond(s)
}
