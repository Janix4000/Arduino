void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT_PULLUP);

}

void loop() {
  
  for(int i=4; i>1; i--)
    {
     while(digitalRead(5)==HIGH){}
     digitalWrite(i, HIGH);
     delay(200);
     digitalWrite(i, LOW);
     delay(200);
    }
    
    for(int i=2; i<5; i++)
    {
     while(digitalRead(5)==HIGH){}
     digitalWrite(i, HIGH);
     delay(200);
     digitalWrite(i, LOW);
     delay(200);
    }

}
