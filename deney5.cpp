#include <Arduino.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

// *** BAGLANTILAR ***
// LCD pins
#define RS 2
#define E  3
#define D4 4
#define D5 5
#define D6 6
#define D7 7

// HC05 pins

#define BRX 8
#define BTX 9
// STATE Pini mavi ledin 
// 220 ohmluk bir direncle
// + bacagina baglanacak.

// *******************

SoftwareSerial bt(BRX, BTX);
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

void setup()
{
    bt.begin(9600);
    lcd.begin(16, 2);
    Serial.begin(9600);
}

void loop()
{
  while(bt.available()){ /* Yeni porta gelen bir mesaj var mı */
    int c = bt.read();
    Serial.println(c);
    if (c == 70)
    {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.write("Ileri");
        lcd.setCursor(0,1);
        lcd.write("tusuna basildi");
    }
    else if (c == 66){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.write("Geri");
        lcd.setCursor(0,1);
        lcd.write("tusuna basildi");
    }
    else if (c == 76){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.write("Sol");
        lcd.setCursor(0,1);
        lcd.write("tusuna basildi");
    }
    else if (c == 82){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.write("Sag");
        lcd.setCursor(0,1);
        lcd.write("tusuna basildi");
    }
    else if (c == 87){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.write("On isik");
        lcd.setCursor(0,1);
        lcd.write("tusuna basildi");
    }
    else if (c == 119){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.write("Arka isik");
        lcd.setCursor(0,1);
        lcd.write("tusuna basildi");
    }
  }
}
