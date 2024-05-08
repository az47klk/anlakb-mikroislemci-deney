// C++ code
//


#define ILERI 1
#define GERI 2

class motor
{
  int pin[3];
  public:
  int hiz = 0;
  int yon = 0;
  
  motor(int, int, int);
  
  void yonBelirle(int);
  void hizBelirle(int);
};

motor::motor(int pin1, int pin2, int pin3)
{
	this->pin[0] = pin1;
  	this->pin[1] = pin2;
  	this->pin[2] = pin3;
  	
 	pinMode(pin1, OUTPUT);
  	pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
}

void motor::yonBelirle(int _yon)
{
  if(this->yon != _yon)
  {
    this->yon = _yon;
	if (_yon == ILERI)
    {
      digitalWrite(this->pin[0], HIGH);
      digitalWrite(this->pin[1], LOW);
    }
  	else if (_yon == GERI)
    {
     digitalWrite(this->pin[0], LOW);
     digitalWrite(this->pin[1], HIGH);
    }
  }
}

void motor::hizBelirle(int _hiz)
{
  if (this->hiz != _hiz && _hiz >= 0 && _hiz <= 255)
  {
    this->hiz = _hiz;
    analogWrite(pin[2], _hiz);
  }
}

motor mt(2,4,3);

void motorYon()
{
	if (mt.yon == ILERI)
      digitalWrite(6,HIGH);
  	else digitalWrite(6,LOW);
}

bool yanipSonmeDurum = false;
bool yanipSonmeD = false;
unsigned long time;

void yanipSonme()
{
  if (millis() - time > 100)
  {
    time = millis();
	if (yanipSonmeDurum)
	{
	if (yanipSonmeD)
		digitalWrite(5, HIGH);
	else
		digitalWrite(5, LOW);
    	yanipSonmeD = yanipSonmeD^1;
	}
  }
}

void baskaBirFonksiyon()
{
	if (mt.hiz == 255 || mt.hiz == 5)
    {
    	digitalWrite(7, HIGH);
		digitalWrite(6,HIGH);
      	yanipSonmeDurum = true;
    }
    else if (mt.hiz >= 205 || mt.hiz <= 55)
    {
    	yanipSonmeDurum = false;
      	digitalWrite(7, LOW);
      	motorYon();
      	digitalWrite(5, HIGH);
    }
  	else if (mt.hiz >= 55 && mt.hiz <= 205)
    {
      yanipSonmeDurum = false;
      digitalWrite(7, HIGH);
      motorYon();
      digitalWrite(5, LOW);
    }
}

void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT_PULLUP);
  pinMode(A1,INPUT_PULLUP);
  pinMode(A2,INPUT_PULLUP);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  mt.yonBelirle(ILERI);
  mt.hizBelirle(0); 
  time = millis();
  
}

void loop()
{
  yanipSonme();
  if (!digitalRead(A0))
  {
  	delay(50);
	Serial.print("A0");
    if (mt.hiz == 0)
      mt.hizBelirle(5);
    int a = 0;
    int c = 0;
    while (c <= 100){
		Serial.print(".");
      if (!digitalRead(A0))
      {
        delay(50);
		mt.yonBelirle(GERI);
		a = 1;
		break;
      }
	  c++;
    }
	
    if (a != 1)
		mt.yonBelirle(ILERI);
	Serial.println(mt.yon);
	baskaBirFonksiyon();
  }
  else if (!digitalRead(A1))
  {
  	delay(50);
	Serial.print("A1");
	int c = 0;
	if (mt.hiz == 5){
		while (c <= 100)
		{
			Serial.print(".");
			if (!digitalRead(A1))
			{
				delay(50);
				mt.hizBelirle(0);
				break;
			}
			c++;
		}
	}
	else
	{
		mt.hizBelirle(mt.hiz - 25);
	}
	Serial.println();
	baskaBirFonksiyon();
	Serial.println("Hiz: " + String(mt.hiz));
  }
  else if (!digitalRead(A2))
  {
  	delay(60);
    if (mt.hiz == 0)
		mt.hizBelirle(5);
	else mt.hizBelirle(mt.hiz + 25);
	baskaBirFonksiyon();
	Serial.println("Hiz: " + String(mt.hiz));
  }
}