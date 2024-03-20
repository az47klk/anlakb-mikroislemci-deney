#include <Arduino.h>

// put function declarations here:

void button1();
void button2();
void button3();
void button4();
void button5();
void button6();
void button7();
void button8();

int oldC = 8;
int counter = 1;

void getInput()
{
  Serial.print("A0: " + String(!digitalRead(A0))  + " ");
  Serial.print("A1: " + String(!digitalRead(A1))  + " ");
  Serial.print("A2: " + String(!digitalRead(A2))  + " ");
  Serial.print("A3: " + String(!digitalRead(A3))  + " ");
  Serial.print("A4: " + String(!digitalRead(A4))  + " ");
  Serial.print("A5: " + String(!digitalRead(A5))  + " ");
  Serial.print("12: " + String(!digitalRead(12))  + " ");
  Serial.println("11: " + String(!digitalRead(11))  + " ");

}

void setup()
{
  
  Serial.begin(9600);

  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(13, OUTPUT);
  
  pinMode(A0,INPUT_PULLUP);
  pinMode(A1,INPUT_PULLUP);
  pinMode(A2,INPUT_PULLUP);
  pinMode(A3,INPUT_PULLUP);
  pinMode(A4,INPUT_PULLUP);
  pinMode(A5,INPUT_PULLUP);
  pinMode(11,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);
  
  for(int i = 2; i <= 9; i++)
  {
  	digitalWrite(i,HIGH);
  }
  
}

void loop()
{
  getInput();
  
  if (!digitalRead(A0))
  {
    int c = 1;
  	delay(100);
    unsigned long tmr = millis();
    while (1)
    {
      if (!digitalRead(A0))
      {
        c++;
        delay(100);
        tmr = millis();
      }
      if(c >= 3)
      {
        button1();
        Serial.println("c: " + String(c));
      	break;
      }
      if (millis() - tmr == 300)
        break;
    }
  }
  
  if (!digitalRead(A1))
  {
    
  	button2();
    delay(100);
  }
  if (!digitalRead(A2))
  {
  	button3();
    delay(100);
  }
  if (!digitalRead(A3))
  {
  	button4();
    delay(100);
  }
  if (!digitalRead(A4))
  {
  	button5();
    delay(100);
  }
  if (!digitalRead(A5))
  {
  	button6();
    delay(100);
  }
  if (!digitalRead(11))
  {
  	button7();
    delay(150);
  }
  if (!digitalRead(12))
  {
  	button8();
    delay(100);
  }


}



void button1()
{
 	for(int i = 2; i <= 9; i++)
    {
      digitalWrite(i,LOW);
    }
  	delay(500);
  	digitalWrite(9, HIGH);
}

void button2()
{
   	for(int i = 2; i <= 9; i++)
    {
      digitalWrite(i,LOW);
    }
	for (int i = 9; i >= 2; i--)
    {
    	digitalWrite(i, HIGH);
      	delay(500);
    }
}

void button3()
{
	for(int i = 2; i <= 9; i++)
    {
      digitalWrite(i,LOW);
    }
  	for (int i = 2; i <= 9; i++)
    {
    	digitalWrite(i, HIGH);
      	delay(500);
    }
}

void button4()
{
  int ss[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  while(1)
  {
    ss[0]++;
    if (ss[0] > 1){
      ss[0] = 0;
      ss[1]++;
    }
    if (ss[1] > 1){
      ss[1] = 0;
      ss[2]++;
    }
    if (ss[2] > 1){
      ss[2] = 0;
      ss[3]++;
    }
    if (ss[3] > 1){
      ss[3] = 0;
      ss[4]++;
    }
    if (ss[4] > 1){
      ss[4] = 0;
      ss[5]++;
    }
     if (ss[5] > 1){
      ss[5] = 0;
      ss[6]++;
    }
     if (ss[6] > 1){
      ss[6] = 0;
      ss[7]++;
    }
     if (ss[7] > 1){
      ss[7] = 1;
      break;
    }
    for (int i = 2; i <=9; i++)
    {
      digitalWrite(i, ss[i-2]);
    }
    delay(100);
  }
  	
}

void button5()
{
	for(int i = 2; i <= 9; i++)
    {
      digitalWrite(i,LOW);
    }
  	for (int i = 1;i <= 8; i++)
    {
    	if (i % 2 == 0)
          digitalWrite(i+1,HIGH);
    }
}

void button6()
{
	for(int i = 2; i <= 9; i++)
    {
      digitalWrite(i,LOW);
    }
  	for (int i = 1;i <= 8; i++)
    {
    	if (i % 2 == 1)
          digitalWrite(i+1,HIGH);
    }
}

void button7()
{
  	for(int i = 2; i <= 9; i++)
    {
      digitalWrite(i,LOW);
    }
	oldC = counter;	
  	counter++;
  	if (counter > 8)
      counter = 1;
  	digitalWrite(10-oldC, LOW);
  	digitalWrite(10-counter, HIGH);
  	
}

void button8()
{
	for(int i = 2; i <= 9; i++)
    {
      digitalWrite(i,LOW);
    }
  	digitalWrite(13, HIGH);
  	delay(500);
	digitalWrite(13, LOW);
}