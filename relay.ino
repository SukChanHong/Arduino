const int relay = 22;

void setup() {
  // put your setup code here, to run once:
  pinMode(relay, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(relay, 1);
  delay(1000);
  digitalWrite(relay, 0);
  delay(1000);
  
}
