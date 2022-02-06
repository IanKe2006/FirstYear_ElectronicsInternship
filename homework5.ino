void setup() {
  //Serial.begin(9600);
  for(int i=2;i<=9;i++)
    pinMode(i, OUTPUT);
}

void loop() {
  //一開始燈全滅
  AllLed(false);
  bool allLight=false;
  while(!allLight)
  {
    //從低位元每次增加一個亮燈
    int n;
    for(n=1;n<=8;n++)
    {
      //Serial.println(n);
      ShowLedNumber(n, true);
    }
    //Serial.println(n);
    //當燈全亮的時候，下一次觸發低位元開始滅一個燈
    if (n>=8)
      allLight=true;
  }
  //從低位元每次多滅一個燈
  for(int i=1;i<8;i++)
  {
      ShowLedNumber(i, false);
  }
}
void ShowLedNumber(int i, bool led)
{
  for(int j=9;j>9-i;j--)
  {
    if (led==true)
      digitalWrite(j, HIGH);
    else
      digitalWrite(j, LOW);
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
