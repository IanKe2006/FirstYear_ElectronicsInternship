void setup() {
  //Serial.begin(9600);
  InitialInput();
  InitialOutput(8);
}
void loop() {
  AllLed(false);
  //Serial.println("====");
  int intSwitch = BinaryToDec(digitalRead(10), digitalRead(11), digitalRead(12), digitalRead(13));
  //Serial.println(intSwitch);
  ShowBinary(intSwitch);
  DoWork(intSwitch);
}
void DoWork(int i)
{
  AllLed(false);
  switch(i)
  {
    case 0:
      AllLed(false);
      break;
    case 1:
      Work1();
      break;
    case 2:
      Work2();
      break;
    case 3:
      Work3();
      break;
    case 4:
      Work4();
      break;
    case 5:
      Work5();
      break;
    case 6:
      Work6();
      break;
    case 7:
      Work7();
      break;
    case 8:
      Work8();
      break;
    case 9:
      Work9();
      break;
    default:
      break;
  }
  delay(500);
}
void Work1()
{
  //閃爍燈
  AllLed(true);
  AllLed(false);
}
void Work2()
{
  //左移燈
  for(int i=9;i>=2;i--){
    digitalWrite(i, HIGH);
    delay(1000);
    digitalWrite(i, LOW);
  }
}
void Work3()
{
  //右移燈
  for(int i=2;i<=9;i++){
    digitalWrite(i, HIGH);
    delay(1000);
    digitalWrite(i, LOW);
  }
}
void Work4()
{
  //上數10模
  for (int i=0;i<=9;i++)
  {
    Clean();
    ShowBinary(i);
  }
}
void Work5()
{
  //下數10模
  for (int i=9;i>=0;i--)
  {
    Clean();
    ShowBinary(i);
  }
}
void Work6()
{
  //強森計數
  AllLed(false);
  bool allLight=false;
  while(!allLight)
  {
    int n;
    for(n=1;n<=8;n++)
      ShowLedNumber(n, true);
    if (n>=8)
      allLight=true;
  }
  for(int i=1;i<8;i++)
      ShowLedNumber(i, false);
}
void Work7()
{
  //呼吸燈
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
void Work8()
{
  //霹靂燈
  ShowLed(true);
  AllLed(true);
  ShowLed(false);
  AllLed(true);
  AllLed(false);
  AllLed(true);
}
void Work9()
{
  //亂數燈
  randomSeed(analogRead(0));
  long rnd = random(254);
  ShowBinary(rnd);
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
void DoBreath(float k)
{
  for(int i=2;i<=9;i++)
  {
    analogWrite(i, k);
  }
  delay(100);
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
int BinaryToDec(bool p1,bool p2, bool p4, bool p8)
{
  int r=0;
  if (p1)
    r=r+1;
  if (p2)
    r=r+2;
  if (p4)
    r=r+4;
  if (p8)
    r=r+8;
  return r;
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
void InitialInput()
{
  for(int j=10;j<=13;j++)
    pinMode(j, INPUT);
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
