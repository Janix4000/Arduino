#define DiodaZielona 2
#define DiodaCzerwona 3
#define Przycisk 4

void setup() {
pinMode(DiodaZielona, OUTPUT); //Zielona
pinMode(DiodaCzerwona, OUTPUT); //Czerwona
pinMode(4, INPUT_PULLUP);

Serial.begin(9600);

}

void loop() {
if(digitalRead(Przycisk)==LOW)
  {
    digitalWrite(DiodaZielona, HIGH);
    digitalWrite(DiodaCzerwona, LOW);
  }
else
  {
    digitalWrite(DiodaZielona, LOW);
    digitalWrite(DiodaCzerwona, HIGH);
    Serial.println("ALarm! Wlamuja sie!");
    while(digitalRead(Przycisk)==HIGH){};
    delay(25);
  }

}
