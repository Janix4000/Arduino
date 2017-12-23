String OdebraneDane;

void setup() {
Serial.begin(9600);

}

void loop() {

  if(Serial.available() > 0)
    {
      OdebraneDane = Serial.readStringUntil('/n');
      Serial.println("Witaj" + OdebraneDane + "!");
    }

}
