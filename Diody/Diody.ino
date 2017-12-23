#define FirstLed 2
#define LastLed 8

void toMiddle(int First, int Second, int Time);
void fromMiddle(int First, int Second, int Time);
void everySecond(int First, int Second, int Time);
void toFromMiddle(int First, int Second, int Time);
void toMiddleBlinker(int First, int Second, int Time);
void fromMiddleBlinker(int First, int Second, int Time);
void everyThirdToLower(int First, int Second, int Time);
void everyThirdToHigher(int First, int Second, int Time);

void setup() {
  
  for(int i = FirstLed; i<=LastLed; i++)
  {
    pinMode(i, OUTPUT);
  }
  randomSeed(analogRead(0));



}

void loop() 
{

  for(int i=0; i<7; i++)
  {
    everySecond(FirstLed, LastLed, 130);
  }
  for(int i=0; i<5; i++)
  {
    fromMiddle(FirstLed, LastLed, 100);
  }
    for(int i=0; i<5; i++)
  {
    toMiddleBlinker(FirstLed, LastLed, 100);
  }
  for(int i=0; i<5; i++)
  {
    toFromMiddle(FirstLed, LastLed, 100);
  }
  for(int i=0; i<5; i++)
  {
    everyThirdToHigher(FirstLed, LastLed, 200);
  } 
  for(int i=0; i<5; i++)
  {
    everyThirdToHigher(FirstLed, LastLed, 100);
    everyThirdToLower(FirstLed, LastLed, 100);
  } 
  for(int i=0; i<5; i++)
  {
    everyThirdToLower(FirstLed, LastLed, 200);
  } 
  for(int i=0; i<5; i++)
  {
    toFromMiddle(FirstLed, LastLed, 100);
  } 
  for(int i=0; i<5; i++)
  {
    fromMiddleBlinker(FirstLed, LastLed, 100);
  } 
  for(int i=0; i<5; i++)
  {
    toMiddle(FirstLed, LastLed, 100);
  } 
  for(int i=0; i<7; i++)
  {
    everySecond(FirstLed, LastLed, 100);
  } 

}






void fromMiddle(int First, int Second, int Time)
{
  int Lowing, Highing;
  
  if((Second-First + 1)%2==1)
  {
    Lowing = First + ((Second - First + 2)/2) - 1;
    Highing = Lowing;
    Second++;
  }
  else if((Second-First + 1)%2==0)
  {
    Lowing = First + ((Second - First + 1)/2) - 1;
    Highing = Lowing + 1;
  }
  
  for(int i = 0; i<(Second - First + 1)/2; i++)
  {
    digitalWrite(Lowing - i, HIGH);
    digitalWrite(Highing + i, HIGH);
    delay(Time);
    digitalWrite(Lowing - i, LOW);
    digitalWrite(Highing + i, LOW);
  }
}


void toMiddle(int First, int Second, int Time)
{
  int x;
  if((Second-First + 1)%2==1) x = (Second - First + 3)/2;
  else x = (Second - First + 1)/2;
  
  for(int i= 0; i<x; i++)
  {
    digitalWrite(Second - i, HIGH);
    digitalWrite(First + i, HIGH);
    delay(Time);
    digitalWrite(Second - i, LOW);
    digitalWrite(First + i, LOW); 
  }
}

void everySecond(int First, int Second, int Time)
{
  int Rest=-1;
  for(int x=0; x<2; x++)
  {
    Rest++;
    for(int i=0; i<=(Second - First); i++)
    {
      if(i%2==Rest){digitalWrite(First + i, HIGH);}
    }
    delay(Time);
    for(int i=0; i<=(Second - First); i++)
    {
      digitalWrite(First + i, LOW);
    }
  }
}

void toFromMiddle(int First, int Second, int Time)
{
  for(int i=0; i<=(Second - First); i++)
  {
    digitalWrite(First + i, HIGH);
    digitalWrite(Second - i, HIGH);
    if(First + i!=Second - i +1)delay(Time);
    digitalWrite(First + i, LOW);
    digitalWrite(Second - i, LOW);
  }
}

void toMiddleBlinker(int First, int Second, int Time)
{
  int x;
  int rand=random(2);
    
  if((Second-First + 1)%2==1) x = (Second - First + 3)/2;
  else x = (Second - First + 1)/2;
  
  for(int i= 0; i<x; i++)
  {
    digitalWrite(Second - i, HIGH);
    delay(Time);
    digitalWrite(Second - i, LOW);
    digitalWrite(First + i, HIGH);
    if(First+i!=Second-i) delay(Time);
    digitalWrite(First + i, LOW); 
  }
}

void fromMiddleBlinker(int First, int Second, int Time)
{
  int Lowing, Highing;
  
  if((Second-First + 1)%2==1)
  {
    Lowing = First + ((Second - First + 2)/2) - 1;
    Highing = Lowing;
    Second++;
  }
  else if((Second-First + 1)%2==0)
  {
    Lowing = First + ((Second - First + 1)/2) - 1;
    Highing = Lowing + 1;
  }
  
  for(int i = 0; i<(Second - First + 1)/2; i++)
  { 
    digitalWrite(Lowing - i, HIGH);
    delay(Time);
    digitalWrite(Lowing - i, LOW);
    digitalWrite(Highing + i, HIGH);
    if(Highing +i != Lowing -i) delay(Time);
    digitalWrite(Highing + i, LOW);
  }
}

void everyThirdToHigher(int First, int Second, int Time)
{
  int Reszta = -1;
  
  for(int x=0; x<3; x++)
  {
    Reszta++;
    for(int i=0; i<=Second-First; i++)
    {
      if(i%3==Reszta)
     {
       digitalWrite(i+First, HIGH);
     } 
    }
    delay(Time);
    for(int i=First; i<=Second; i++)
    {
      digitalWrite(i, LOW);
    }
  }
}


void everyThirdToLower(int First, int Second, int Time)
{
  int Reszta = 3;
  
  for(int x=0; x<3; x++)
  {
    Reszta--;
    for(int i=0; i<=Second-First; i++)
    {
      if(i%3==Reszta)
     {
       digitalWrite(i+First, HIGH);
     } 
    }
    delay(Time);
    for(int i=First; i<=Second; i++)
    {
      digitalWrite(i, LOW);
    }
  }
}
