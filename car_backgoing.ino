
const int trig_pin = 15;
const int echo_pin = 14;
const int buzzer = 6;


// Vitesse du son dans l'air
#define SOUND_SPEED 340
#define TRIG_PULSE_DURATION_US 10

long ultrason_duration;
float distance_cm;

void setup() 
{
Serial.begin(115200);
pinMode (trig_pin, OUTPUT); // On configure le trig en output 
pinMode (echo_pin, INPUT); // On configure l'echo en input
pinMode(buzzer, OUTPUT);
}

void loop() 
{
// Prepare le signal
digitalWrite(trig_pin, LOW); 
delayMicroseconds (2);
// Créer une impulsion de 10 us 
digitalWrite(trig_pin, HIGH);
delayMicroseconds (TRIG_PULSE_DURATION_US);
digitalWrite(trig_pin, LOW);

// Renvoie le temps de propagation de l'onde (en us) 
ultrason_duration =  pulseIn (echo_pin, HIGH);

// Calcul de la distance
distance_cm = ultrason_duration * SOUND_SPEED/2 * 0.0001;

// On affiche la distance sur le port série 
Serial.print ("Distance (cm): ");
Serial.println(distance_cm);


  if(90 >= distacne_cm && distacne_cm > 60)
  {
      tone(buzzer, 400);
      delay(1000);
      tone(buzzer,200);
      delay(1000);
  }
  else if(60 >= distacne_cm && distacne_cm > 30)
  {
      tone(buzzer, 600);
      delay(500);
      tone(buzzer,300);
      delay(500);
  }
  else if(30 >= distacne_cm && distance_cm > 10)
  {
      tone(buzzer, 800);
      delay(250);
      tone(buzzer,400);
      delay(250);
  }
  else if(10 >= distacne_cm)
  {
      tone(buzzer, 1200);
      delay(100);
      tone(buzzer,600);
      delay(100);
  }
  else
  {
    noTone(buzzer);
    delay(1000);
  }
}