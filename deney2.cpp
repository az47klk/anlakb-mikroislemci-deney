

#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);

int kaymaMiktari = 0;

void yaziyazdir()
{
	lcd.clear();
	lcd.setCursor(3 + kaymaMiktari,0);
	lcd.print("KKU MMF EEM");

	lcd.setCursor(1 + kaymaMiktari,1);
	lcd.print("200204019 DEN 2");
}

void setup () {
	lcd.begin(16,2);
	pinMode(A0, INPUT_PULLUP);
	pinMode(A1, INPUT_PULLUP);
	pinMode(A2, INPUT_PULLUP);
	
	yaziyazdir();
}

void loop() {
	if (!digitalRead(A0))
	{
		kaymaMiktari--;
		if (kaymaMiktari <= -16)
			kaymaMiktari = 16;
		yaziyazdir();
		delay(100);
	}

	if (!digitalRead(A1))
	{
		kaymaMiktari = 0;
		yaziyazdir();
		delay(100);
	}

	if (!digitalRead(A2))
	{
		kaymaMiktari++;
		if (kaymaMiktari >= 16)
			kaymaMiktari = -16;
		yaziyazdir();
		delay(100);
	}
}



