#define lRed 2
#define pRed 3
#define sYell 4
#define lGreen 5
#define pGreen 6

int Wartosc;

void kontrolaDiod(int Numer);

void setup() {
  pinMode(lRed, OUTPUT);
  pinMode(pRed, OUTPUT);
  pinMode(sYell, OUTPUT);
  pinMode(lGreen, OUTPUT);
  pinMode(pGreen, OUTPUT);

}

void loop() {
  Wartosc = analogRead(A5);
  Wartosc = map(Wartosc, 0, 1023, 1, 5);
  
  if(Wartosc==1)      kontrolaDiod(lRed);
  else if(Wartosc==2) kontrolaDiod(pRed);
  else if(Wartosc==3) kontrolaDiod(sYell);
  else if(Wartosc==4) kontrolaDiod(lGreen);
  else if(Wartosc==5) kontrolaDiod(pGreen);
  
  delay(50);
}


void kontrolaDiod(int Numer)
{
  for(int i=lRed; i<=pGreen; i++)
  {
    digitalWrite(i, LOW);
  }
  digitalWrite(Numer, HIGH);
}
