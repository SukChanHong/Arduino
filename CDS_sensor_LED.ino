
#define PIN_CDS 26
const int RED_LED = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode (PIN_CDS, INPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() 
{
  int CDS_sensor = analogRead (26);

  if(CDS_sensor > 600 ) 
  {
  Serial.println("midnight");
  digitalWrite(RED_LED, 1);


  }
  else if(600>=CDS_sensor && CDS_sensor > 300)
  {
  Serial.println("Sunset");
  digitalWrite(RED_LED, 0);
  }

  else
  {
  Serial.println("SunRise");
  digitalWrite(RED_LED, 0);
  }  

  Serial.print ("CDS Value: ");
  Serial.println (CDS_sensor);
  delay(1000);
}
