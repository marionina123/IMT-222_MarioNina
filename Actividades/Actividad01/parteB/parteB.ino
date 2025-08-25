int leds[15] = {2,3,4,5,6,7,8,9,10,11,12,13, A0, A1, A2};
int intervalo = 500;

void setup() 
{
  for (int i = 0; i < 15; i++) 
  {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() 
{
  for (int i = 0; i < 15; i++)
  {
    digitalWrite(leds[i], HIGH);
    delay(intervalo);
    digitalWrite(leds[i], LOW);
  }
}
