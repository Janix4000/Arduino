#define green  2
#define red  3

String Odbior;
bool Stan[10];

void kontrolaDiody(int Numer, bool stat);

void setup() {
pinMode(green, OUTPUT);
pinMode(red, OUTPUT);
Serial.begin(9600);
Stan[red] = false; Stan[green] = false;

digitalWrite(green, LOW);
digitalWrite(red, LOW);

}

void loop() {

  if(Serial.available() > 0)
  {
    Odbior = Serial.readStringUntil('\n');
  
  
    if(Odbior=="zielony")
    {
      kontrolaDiody(green, Stan[green]);
    }
  
    else if(Odbior=="czerwony")
    {
      kontrolaDiody(red, Stan[red]);
    }
  
    else 
    {
      Serial.println("Bledna Komenda");
    }

  }
}


void kontrolaDiody(int Numer, bool stat)
{
  if(stat==false)
  {
    Stan[Numer]=true;
    digitalWrite(Numer, HIGH);
  }
  
  else if(stat==true)
  {
    Stan[Numer]=false;
    digitalWrite(Numer, LOW);
  }
  Odbior="i";
}
