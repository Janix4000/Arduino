#define pS 0
#define oS 5
#define pM 6
#define oM 11
#define pG 12
#define oG 15
int latchPin = 8,
    clockPin = 12,
    dataPin = 11;
int numOfRegisters = 2;
byte* registerState;
int minut=48, sekond=0, godz=14;
int pgodz=godz;

void setup() {
  if(pgodz>12)pgodz-=12;
  registerState = new byte[numOfRegisters];
  for (size_t i = 0; i < numOfRegisters; i++) registerState[i] = 0;
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(9, INPUT_PULLUP);
  wyczysc(pS, oG);
  ustaw(godz, pG, oG, 1, 12);
  ustaw(minut, pM, oM, 0, 59);
  ustaw(sekond, pS, oS, 0, 59);
}



void loop() {
  sekond++;
  if(sekond==60)
  {
    sekond=0;
    minut+=1;
    if(minut==60)
    {
      minut=0;
      godz+=1;
      if(godz=24) godz=1;
      pgodz=godz;
      if(pgodz>12)pgodz-=12;
      wyczysc(pG, oG);
      zegar(pG, oG, pgodz);
    }
    wyczysc(pM, oM);
    zegar(pM, oM, minut);   
  }
  wyczysc(pS, oS);
  zegar(pS, oS, sekond);
  
  delay(1000);
}

void zegar(int n, int x, int l)
{
  if(pow(2, x-n)<=l)
  {
    regWrite(x, HIGH);
    l-=pow(2,x-n);
  }
  if(n!=x)
   zegar(n, x-1, l);
}

void wyczysc(int n, int x)
{
 for(int i=n; i<=x; i++) regWrite(i, LOW);
}

void regWrite(int pin, bool state){
	//Determines register
	int reg = pin / 8;
	//Determines pin for actual register
	int actualPin = pin - (8 * reg);

	//Begin session
	digitalWrite(latchPin, LOW);

	for (int i = 0; i < numOfRegisters; i++){
		//Get actual states for register
		byte* states = &registerState[i];

		//Update state
		if (i == reg){
			bitWrite(*states, actualPin, state);
		}

		//Write
		shiftOut(dataPin, clockPin, MSBFIRST, *states);
	}

	//End session
	digitalWrite(latchPin, HIGH);
}

void ustaw(int &co, int d, int g, int n, int x)
{
  while(digitalRead(9)==HIGH)
  {
    co = map(analogRead(A5), 0, 1023, n, x);
    wyczysc(d, g);
    zegar(d, g, co);
   delay(50); 
  }
  delay(20);
  while(digitalRead(9)==LOW);
  delay(20);
}
