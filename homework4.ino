void setup() {
  InitialOutput(8);
}

void loop() {
  int i;
  for(i=9;i>=3;i--){
    digitalWrite(i, HIGH);
    delay(1000);
    digitalWrite(i, LOW);
  }
  for(i=2;i<=9;i++){
    digitalWrite(i, HIGH);
    delay(1000);
    digitalWrite(i, LOW);
  }
}
void InitialOutput(int i)
{
  for(int j=9;j>=9-i+1;j--)
    pinMode(j, OUTPUT);
}
