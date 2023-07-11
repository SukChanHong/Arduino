void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial);

  Serial.println("Serial Open!");
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available()) {
    char c = Serial.read();
    if (c != '\n') {
      char convertedChar = c + 1;
      Serial.print(convertedChar);
    }
  }
}
