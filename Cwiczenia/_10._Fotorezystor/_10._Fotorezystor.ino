int Wartosc=0;
int prog = 0; 
bool Raz = false;

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  Wartosc = analogRead(A5);
  prog = analogRead(A4);
  
  if(Wartosc < prog)
  { 
    if(Raz==false)
    {
      Raz=true; Serial.println(Wartosc);   
    }
    
    digitalWrite(2, HIGH);
  }
  
  else 
  {
    digitalWrite(2, LOW); Raz=false;
  }
  
  delay(50);
}
