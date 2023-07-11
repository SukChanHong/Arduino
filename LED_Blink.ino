const int RED_LED = 0;
const int GREEN_LED = 2;
const int YELLOW_LED = 1;
//이걸로 PIN NUMBER 설정해주는 것

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
}

void loop() 
{
  digitalWrite(RED_LED, 1);
  digitalWrite(GREEN_LED, 0);
  digitalWrite(YELLOW_LED, 0);
  delay(1000);

  digitalWrite(RED_LED, 0);
  digitalWrite(GREEN_LED, 1);
  digitalWrite(YELLOW_LED, 0);
  delay(1000);

  digitalWrite(RED_LED, 0);
  digitalWrite(GREEN_LED, 0);
  digitalWrite(YELLOW_LED, 1);
  delay(400);
}
