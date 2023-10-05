#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);   

int ledPin = 2;
int sensorPin = A1;
float value, value1, value2, value3;

void setup()
{
Serial.begin(9600);
lcd.init();
lcd.backlight();
pinMode(ledPin,OUTPUT);
}
void loop() 
{
    int Value = analogRead(sensorPin);
    value1 = analogRead(A1);delay(15);
    value2 = analogRead(A1);delay(15);
    value3 = analogRead(A1);delay(15);
    value = (value1+value2+value3)/3;
    lcd.print("Alcohol:");
    lcd.print((value/1023)-(-0.01)-0.25);
    lcd.print("mg/l:");
    Serial.print((value/10023)-(-0.01)-0.25);
    if ((value/1000)-(-0.01)-0.25 > 0.17 ){
        digitalWrite(ledPin,HIGH);
        lcd.setCursor(0, 1);
        lcd.print("You are drank...");
        Serial.println (":mg/l - You are drank...");   
    } 
    else {
        digitalWrite(ledPin,LOW); 
        lcd.setCursor(0, 1);
        lcd.print("You are sober...");
        Serial.println(":mg/l - You are sober...");
    }
    delay(500);
    lcd.clear();
}