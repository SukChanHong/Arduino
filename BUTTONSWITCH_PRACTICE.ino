const int RED_LED = 7;
const int GREEN_LED = 10;
const int BLUE_LED = 11;
const int sw1 = 3;
const int sw2 = 4;
const int sw3 = 5;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
}

void loop() {
  int state1 = digitalRead(sw1);
  int state2 = digitalRead(sw2);
  int state3 = digitalRead(sw3);
  
  if (state1 == LOW) 
  {
    digitalWrite(RED_LED, 0);
  }
  else
  {
    digitalWrite(RED_LED, 1);
  }
//
  if (state2 == LOW) 
  {
    digitalWrite(GREEN_LED, 0);
  }
  else
  {
    digitalWrite(GREEN_LED, 1);
  }
//
  if (state3 == LOW) 
  {
    digitalWrite(BLUE_LED, 0);
  }
  else
  {
    digitalWrite(BLUE_LED, 1);
  }

}
