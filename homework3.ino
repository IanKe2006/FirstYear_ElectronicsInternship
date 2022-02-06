void setup() {
  int i;
  for(i=2;i<=9;i++)
    pinMode(i, OUTPUT);

}

void loop() {
  int i;
  for(i=2;i<=9;i++){
    digitalWrite(i, HIGH);
    delay(1000);
    digitalWrite(i, LOW);
  }
}
