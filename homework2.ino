void setup() {
  //Serial.begin(9600);
  InitialOutput(3);
}

void loop() {
  for (int i=0;i<=5;i++)
  {
    //Serial.println(i);
    ShowBinary(i);
  }
}
void ShowBinary(int dec)
{
  Clean();
  int r;
  int p=0;
  while(dec!=0)
  {
    r=dec%2;
    dec=dec/2;
    if (r==1)
      digitalWrite(9-p, HIGH);
    else
      digitalWrite(9-p, LOW);
    p++;
  }
  delay(1000);
}
void InitialOutput(int i)
{
  for(int j=9;j>=9-i+1;j--)
    pinMode(j, OUTPUT);
}
void Clean()
{
  for(int i=2;i<=9;i++)
    digitalWrite(i, LOW);
}
