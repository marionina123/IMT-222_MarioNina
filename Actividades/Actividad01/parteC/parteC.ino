#define   INTERVALO 500
#define   N_LEDS 15

int leds[N_LEDS] = {2,3,4,5,6,7,8,9,10,11,12,13, A0, A1, A2};

void setup()
{
  for (int i = 0; i < N_LEDS; i++) 
  {
    pinMode(leds[i], OUTPUT);
  }
}

void loop()
{
  for (int i = 0; i < N_LEDS; i++)
  {
    digitalWrite(leds[i], HIGH);
    delay(INTERVALO);
    digitalWrite(leds[i], LOW);
  }
}
