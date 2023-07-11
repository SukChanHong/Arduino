const int RED_LED = 0;
const int buzz = 6;

void setup() 
{
  Serial.begin(9600);
  pinMode (27, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode (buzz, OUTPUT);
}

void loop() 
{
  int rain_sensor = analogRead (27);

  if(rain_sensor > 900 ) 
  {
  Serial.println("Not Raining");
  digitalWrite(RED_LED, 0);
  noTone (buzz);
  }
  else if(900>=rain_sensor && rain_sensor > 700)
  {
  Serial.println("Raining");
  digitalWrite(RED_LED, 1);
  tone (buzz, 500);
  }
  else if(700>=rain_sensor && rain_sensor >500)
  {
  Serial.println("Hurricane is coming");
  digitalWrite(RED_LED, 1);
  tone(buzz, 500);
  delay(250);
  noTone(buzz);
  delay(250); 
  }
  else
  {
  Serial.println("Hurricane");
  digitalWrite(RED_LED, 1);
  tone(buzz, 1000);
  delay(125);
  noTone(buzz);
  delay(125); 
  }

  Serial.print ("Rain Sensor Value: ");
  Serial.print (rain_sensor);
  Serial.print(" ");

  delay(1000);
}