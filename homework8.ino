long rnd;

void setup() {
  Serial.begin(9600);
  for(int i=2;i<=9;i++)
    pinMode(i, OUTPUT);
}

void loop() {
  Clean(); 
  randomSeed(analogRead(0));
  rnd = random(254);
  Serial.println(rnd);
  ShowBinary(rnd);
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
void Clean()
{
  for(int i=2;i<=9;i++)
    digitalWrite(i, LOW);
  delay(1000);
}
