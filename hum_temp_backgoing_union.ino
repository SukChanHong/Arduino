
#include <Adafruit_Sensor.h> 
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define SOUND_SPEED 340
#define TRIG_PULSE_DURATION_US 10

long ultrason_duration;
float distance_cm;

DHT dht (DHTPIN, DHTTYPE);
const int RED_LED = 0;
const int buzz = 6;
const int relay = 22;
const int trig = 15;
const int echo = 14;

const int sw1 = 3;
const int sw2 = 4;



void setup() 
{
  Serial.begin(9600); 
  dht.begin();

  pinMode(RED_LED, OUTPUT);
  pinMode (buzz, OUTPUT);
  pinMode(relay, OUTPUT);
  Serial.begin(115200);
  pinMode(trig,OUTPUT);
  pinMode(echo,OUTPUT);
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);

}

void loop() 
{
  int state1 = digitalRead(sw1);
  int state2 = digitalRead(sw2);


  if (state1 == 0) 
  {
    delay(2000);

    float hum = dht.readHumidity();
    float temp = dht.readTemperature ();
    float F = dht.readTemperature (true);
    //Check if any reads failed and exit early (to try again)
    if (isnan (hum) || isnan (temp) || isnan (F)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    Serial.print ("Humidity: ");
    Serial.print (hum);
    Serial.print(" % ");
    Serial.print ("Temperature: ");
    Serial.print(temp);
    Serial.println("C");

      if(hum < 70 || temp > 25)
      {
        digitalWrite(RED_LED, 1);
        tone (buzz, 500); // 500Hz   
        digitalWrite(relay, 0);
        delay(1000);
      }
      else
      {
        digitalWrite(RED_LED, 0);
        noTone (buzz);   
        digitalWrite(relay, 1);
        delay(1000);
      }


  }
  else if (state2 == 0)
  {
    digitalWrite(trig,0);
    delayMicroseconds(2);
    digitalWrite(trig,1);
    delayMicroseconds(TRIG_PULSE_DURATION_US);
    digitalWrite(trig,0);

    ultrason_duration = pulseIn(echo, 1);
    distance_cm = ultrason_duration * SOUND_SPEED/2 * 0.0001;

    Serial.print("Distance (cm) : ");
    Serial.println(distance_cm);

    if(distance_cm>60 && distance_cm<=90){
      tone(buzz, 1000);
      delay(2000);
      noTone(buzz);
      delay(2000); 
    }
    else if(distance_cm>30 && distance_cm<=60){
    tone(buzz, 1000);
      delay(1000);
      noTone(buzz);
      delay(1000);  
    }
    else if(distance_cm>10 &&distance_cm<=30){
    tone(buzz, 1000);
      delay(500);
      noTone(buzz);
      delay(500);  
    }
    else if(distance_cm<=10){
      tone(buzz,1000);
      delay(250);
    }
    else {
      noTone(buzz);
      }
  }
  else
  {
    delay(1000);
  }
}


