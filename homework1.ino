void setup() {
  InitialOutput(8);
}
void loop() {
  AllLed(true);
  AllLed(false);
}
void AllLed(bool led)
{
  for(int i=2;i<=9;i++)
  {
    if (led==true)
      digitalWrite(i, HIGH);
    else
      digitalWrite(i, LOW);
  }
  delay(1000);
}
void InitialOutput(int i)
{
  for(int j=9;j>=9-i+1;j--)
    pinMode(j, OUTPUT);
}
