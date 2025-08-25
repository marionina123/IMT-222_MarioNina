void setup() {
  for (int pin = 2; pin <= 11; pin++)
  {
    pinMode(pin, OUTPUT);
  }
}

void loop() 
{
  for (int pin = 2; pin <= 11; pin++)
  {
    digitalWrite(pin, HIGH);
    delay(2000);
    digitalWrite(pin, LOW);
  }
}
