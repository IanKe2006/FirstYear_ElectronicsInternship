void setup() {
  InitialOutput(8);
}

void loop() {
  float j;
  delay(100);
  for(j=25.5;j<=255;j=j+25.5)
  {  
    DoBreath(j);
  }  
  for(j=255;j>=0;j=j-25.5)
  {
    DoBreath(j);
  }
}
void DoBreath(float k)
{
  for(int i=2;i<=9;i++)
  {
    analogWrite(i, k);
  }
  delay(100);
}
void InitialOutput(int i)
{
  for(int j=9;j>=9-i+1;j--)
    pinMode(j, OUTPUT);
}
