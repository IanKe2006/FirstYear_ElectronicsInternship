void setup() {
  InitialOutput(8);
}

void loop() { 
  ShowLed(true);
  AllLed(true);
  ShowLed(false);
  AllLed(true);
  AllLed(false);
  AllLed(true);
}
void ShowLed(bool increase)
{
  if (increase)
  {
    AllLed(false);
    ShowBinary(129);
    ShowBinary(195);
    ShowBinary(231);
  }
  else
  {
    ShowBinary(231);
    ShowBinary(195);
    ShowBinary(129);
    AllLed(false);
  }
}
void ShowBinary(int dec)
{
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
