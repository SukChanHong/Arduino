const int buzzer = 6;

int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};

//이걸로 PIN NUMBER 설정해주는 것

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
}

void loop() 
{
 
  int i = 0;

  for(i = 0; i <8; i++)
  {
    tone(buzzer, melody[i]);
    delay(500);
    noTone(buzzer);
    delay(500);
  }

    for(i = 8; i >= 0 ; i--)
  {
    tone(buzzer, melody[i]);
    delay(500);
    noTone(buzzer);
    delay(500);
  }
}