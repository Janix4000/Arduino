int Trud, Czas, iX, Ile, c=0, Pom, Punkty;
int ID[10][10];


#include <LiquidCrystal.h> 
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
void setup() {
  lcd.begin(16, 2); //Deklaracja typu
  lcd.clear();
 
randomSeed(analogRead(0));


 lcd.setCursor(0,0);
 lcd.print("i");
 
  pinMode(9, INPUT_PULLUP);}


void loop() 


{Trud=0; Ile=1; iX=1; c=0; Czas=200; Punkty=0;
for(int i=0; i<4; i++){ID[i][0]=16; ID[i][5]=1;}


lcd.clear();
lcd.setCursor(0, 0); lcd.print("NACISNIJ");
lcd.setCursor(0, 1); lcd.print("BY ZACZAC");


while(c<1)
{if(digitalRead(9)==LOW){c=1;}} c=0;


lcd.clear();
lcd.setCursor(0, iX); lcd.print("i");
delay(1500);

while(c<1)

{if(digitalRead(9)==LOW)
	{if(iX==0){iX=1;} else {iX=0;} lcd.clear();
         lcd.setCursor(0, iX); lcd.print("i"); }
lcd.clear();
lcd.setCursor(0, iX); lcd.print("i");


for(int i=0; i<Ile; i++)
{ID[i][0]--;

if(ID[i][0]==15)
{ID[i][1]=random(0,2);
 if(ID[i][1]==0){ID[i][4]=1;} else {ID[i][4]=0;}
 Pom=random(12);
 if(Pom<3){ID[i][2]=Pom;} else{ID[i][2]=3;}
 if(Pom<2){ID[i][3]=random(3,6);}}
 
if((ID[i][2]==0)&&(ID[i][0]==ID[i][3]))
 {ID[i][1]=ID[i][4];}

if((ID[i][2]==1)&&(ID[i][0]>ID[i][3]))
 {lcd.setCursor(ID[i][0],ID[i][4]);
  lcd.print("O");}

if((ID[i][2]==2)&&(ID[i][5]--==0)&&(ID[i][0]>3))
{Pom=ID[i][1]; ID[i][1]=ID[i][4]; ID[i][4]=Pom;
 ID[i][5]=random(3,5);}

lcd.setCursor(ID[i][0],ID[i][1]);
lcd.print("O");

if(ID[i][0]==0)
 {ID[i][0]=16;
  if(ID[i][1]==iX){c=1;}
  else {Punkty++;}}}

if((ID[Ile-1][0]==12)&&(Ile!=4)){Ile++;}
 if((Trud++==56)&&(Czas>100))
{Trud=0; Czas-=10;} delay(Czas);}

c=0; lcd.clear();
lcd.setCursor(0,0); lcd.print("GAME OVER");
lcd.setCursor(0,1); lcd.print("Zdobyles");
lcd.setCursor(11,1); lcd.print(Punkty);
delay(4500); lcd.clear();}







