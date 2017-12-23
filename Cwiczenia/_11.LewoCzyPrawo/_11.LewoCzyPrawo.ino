#define lYellow 2
#define rYellow 3
#define mRed 4
#define lGreen 5
#define rGreen 6

int lewyOdczyt=0;
int prawyOdczyt=0;
int Zakres=0;
int Dokres=0;

void sterDiod(int Numer);

void setup() {
pinMode(lYellow, OUTPUT);
pinMode(rYellow, OUTPUT);
pinMode(mRed, OUTPUT);
pinMode(lGreen, OUTPUT);
pinMode(rGreen, OUTPUT);

Zakres = analogRead(A5);
delay(100);
while(analogRead(A5)<Zakres + 200){}
delay(600);
Dokres = analogRead(A5) - 150;

Serial.begin(9600);
}

void loop() {

  lewyOdczyt = analogRead(A5);
  prawyOdczyt = analogRead(A4);
  
  lewyOdczyt = map(lewyOdczyt, Zakres, Dokres, 1, 5);
  prawyOdczyt = map(prawyOdczyt, Zakres, Dokres, 1, 5);
    
  Serial.println(lewyOdczyt);
  Serial.println(prawyOdczyt);
    
  if     (lewyOdczyt==prawyOdczyt)      sterDiod(mRed);
  else if(lewyOdczyt - prawyOdczyt > 3) sterDiod(lYellow);
  else if(prawyOdczyt - lewyOdczyt > 3) sterDiod(rGreen);
  else if(lewyOdczyt - prawyOdczyt > 1) sterDiod(rYellow);
  else if(prawyOdczyt - lewyOdczyt > 1) sterDiod(lGreen);
  
  delay(50);

}


void sterDiod(int Numer)
{
  for(int i=lYellow; i<=rGreen; i++)
  {
    digitalWrite(i, LOW);
  }
  digitalWrite(Numer, HIGH);
}

