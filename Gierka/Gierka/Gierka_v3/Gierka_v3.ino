int Trud, Czas, iX, Ile, c=0, Pom, Punkty, Seria, sPomoc, p;
int ID[10][10];


#include <LiquidCrystal.h> 
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //Wczytanie bibliotek

//URODZENIE iMANA
byte iMan[8] = {
	0b00100,
	0b01010,
	0b00100,
	0b01110,
	0b10101,
	0b00100,
	0b01010,
	0b10001
};

void setup() 
{
 lcd.begin(16, 2); 
 lcd.createChar(0, iMan); //egzorcyzm iMana
 lcd.clear();
 
 randomSeed(analogRead(0));
 
 pinMode(9, INPUT_PULLUP);
}


void loop() 
{
 //WYCZYSZCZENIE ZMIENNYCH
 Trud=0; Ile=1; iX=1; c=0; Czas=100; Punkty=0; Seria=0; sPomoc=1; p=0;
 
 //WYCZYSZCZENIE ZMIENNYCH ID
 for(int i=0; i<4; i++) { ID[i][0]=16; ID[i][5]=1; } 

 //MENU START
 lcd.clear();
 lcd.setCursor(0, 0); lcd.print("NACISNIJ");
 lcd.setCursor(0, 1); lcd.print("BY ZACZAC");
 while(c<1)
 {if(digitalRead(9)==LOW) { c=1; } } c=0;

 //INICJACJA POSTACI 
 lcd.clear();
 lcd.setCursor(0, iX);  lcd.write(byte(0));
 delay(1500); 


 //POCZATEK PETLI GRY 
 while(c<1)



 //WYKRYWANIE PRZYCISKU
 { if(p==1) { p=0; }
  else if(digitalRead(9)==LOW)
   { if(iX==0){iX=1;} else {iX=0;} lcd.clear(); p=1;}
 lcd.clear();
 lcd.setCursor(0, iX); lcd.write(byte(0));



 //PETLA PRZESZKOD
 for(int i=0; i<Ile; i++)
 {ID[i][0]--;

 //RESET ID
 if(ID[i][0]==15)
 { 
   //Losowanie y
   ID[i][1]=random(0,2);
   if(ID[i][1]==0) { ID[i][4]=1; } 
   else            { ID[i][4]=0; } 
 
   Pom=random(25); //losowanie typu przeszkody
 
   //Wybor typu przeszkody 
   if     (Pom<2) { ID[i][2]=0; } 
   else if(Pom<4) { ID[i][2]=1; }
   else if(Pom<6) { ID[i][2]=2; }
   else if(Pom<7) { ID[i][2]=3; } 
   else if(Pom<8) { ID[i][2]=4; }
   else           { ID[i][2]=5; }
 
   //Nadanie zmiennych pomocniczych
   if      (ID[i][2]<3) { ID[i][3]=random(3,6); }
   else if(ID[i][2]==3) { ID[i][3]=8; }
   else if(ID[i][2]==4) { ID[i][3]=6; }
 }
 
 //AKTYWATORY PRZESZKOD SPECJALNYCH
 
 //Seria  
 if(ID[i][0]==15)
  {  Seria--;
     if(Seria>0)     { ID[i][2]=2; ID[i][3]=random(3,6); } 
     else if(Seria==0) { Punkty+=7; Czas+=30; if(Czas>100) { Czas=100; } }
     else if(Seria<0)  { Seria=0; } }
 
 //Przeskok
 if( (ID[i][2]==0)&&(ID[i][0]==ID[i][3])&&(Punkty>15) )
  { ID[i][1]=ID[i][4]; }

 //Sciana
 else if( (ID[i][2]==1)&&(ID[i][0]>ID[i][3])&&(Punkty>30) )
 { lcd.setCursor(ID[i][0],ID[i][4]); lcd.print("O"); }

 //Pojeb
 else if( (ID[i][2]==2)&&(ID[i][5]--==0)&&(ID[i][0]>3)&&(Punkty>45) )
  { Pom=ID[i][1]; ID[i][1]=ID[i][4]; ID[i][4]=Pom; ID[i][5]=random(3,5); }

 
 lcd.setCursor(ID[i][0],ID[i][1]); //ustawienie przeszkody

 //WYSWIETLENIE PRZESZKODY
 
 //Wyswietlenie Q
 if(  ( (ID[i][2]==3)||(ID[i][2]==4) )&&(ID[i][0]>ID[i][3])  )
  { lcd.print("Q"); }
 
 //Wyswietlenie O
 else {lcd.print("O");}

 //CZUJNIKI UDERZENIA PRZESZKODY 
 
 //Koniec drogi
 if(ID[i][0]==0)
  { ID[i][0]=16;
 
    //Uderzenie w iMana
    if(ID[i][1]==iX)  
    
       //Warunek dla Q
     { if( (ID[i][2]==3)||(ID[i][2]==4) )
     
         //reset wyswietlacza
       { if(Pom=random(3)==2)
          { for(int i=0; i<4; i++){ID[i][0]=16;} Ile=1;
            //dobre Q
            if(ID[i][2]==3)    { Punkty+=3; } 
            //zle Q (seria)
            else if(Punkty>45) { Seria=13; Czas-=30; if(Czas<0) { Czas=0; } } }
            
         //zmiana Czasu   
         else 
            //dobre Q
          { if(ID[i][2]==3)      { Czas+=10; if(Czas>100) { Czas=100; } Punkty+=3; }
            //zle Q
            else if(ID[i][2]==4) { Czas-=10; if(Czas<0) { Czas=0; } } } }

       //Warunek dla normalnej przeszkody
       else { c=1; } }
    
    //Ominiecie przeszkody
    else { Punkty++; } } }
  
 //UWALNIANIE PO KOLEJI PRZESZKOD
 if( (ID[Ile-1][0]==12)&&(Ile!=4) ) { Ile++; }
 
 //PRZYSPIESZANIE GRY
 if( (Trud++==56)&&(Czas>0) )
  { Trud=0; Czas-=10; } 
 
 //TEMPO GRY
 delay(100);
 
 
 //WYKRYWANIE PRZYCISKU
  if(p==1) { p=0; }
  else if(digitalRead(9)==LOW)
   { if(iX==0){iX=1;} else {iX=0;} lcd.clear(); p=1;}
    
 
 
 delay(Czas);}


//GAME OVER
c=0; lcd.clear();

//Wyswietlenie GAME OVER
lcd.setCursor(0,0); lcd.print("GAME OVER");

//Wyswietlenie punktow
lcd.setCursor(0,1); lcd.print("Zdobyles");
lcd.setCursor(11,1); lcd.print(Punkty);

//Kwestie estetyczne
delay(3500); lcd.clear();}

