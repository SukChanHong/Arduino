
#include <Adafruit_Sensor.h> 
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht (DHTPIN, DHTTYPE);
const int RED_LED = 0;
const int buzzer = 6;
const int relay = 22;

void setup() 
{
  Serial.begin(9600); 
  dht.begin();

  pinMode(RED_LED, OUTPUT);
  pinMode (buzzer, OUTPUT);
  pinMode(relay, OUTPUT);
}

void loop() 
{
//Wait a few seconds between measurements
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
    tone (buzzer, 500); // 500Hz   
    digitalWrite(relay, 0);
    delay(1000);
  }
  else
  {
    digitalWrite(RED_LED, 0);
    noTone (buzzer);   
    digitalWrite(relay, 1);
    delay(1000);
  }
}


