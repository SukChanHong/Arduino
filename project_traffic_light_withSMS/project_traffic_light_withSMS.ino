const int trig_pin = 15;
const int echo_pin = 14;

const int RED_LED = 0;

// Vitesse du son dans l'air
#define SOUND_SPEED 340
#define TRIG_PULSE_DURATION_US 10

long ultrason_duration;
float distance_cm = 0;
float previous_cm = 0;
float velocity = 0;

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

///
const int buzzer = 6;



void setup() 
{
  Serial.begin(115200);
  Serial2.begin(115200);
  pinMode (trig_pin, OUTPUT); // On configure le trig en output 
  pinMode (echo_pin, INPUT); // On configure l'echo en input

  pinMode(RED_LED, OUTPUT);

    
  Wire.setSDA(12);
  Wire.setSCL(13);
  Wire.begin();  
  

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("VELOCITY!!");
  display.display(); 
  delay(1000);


  pinMode(buzzer, OUTPUT); 
}

void loop() 
{
  noTone(buzzer);
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
  velocity = (previous_cm - distance_cm) / 0.125 / 100000 * 3600 ; 
  previous_cm = distance_cm;
  
  //print velocity on SSD1306 
  if(velocity >= 3)
  { 
    sendSMS("01048903017", "Current Speed : ", velocity, "km/h  \r\nYou're speeding.  \r\nSlow down");  // 스위치 누를 때 SMS 전송 함수 호출

    display.clearDisplay();
    display.setTextColor(BLACK,WHITE);
    display.setCursor(0, 10);
    display.print(velocity);
    display.println("km/h");
    display.display();
    tone(buzzer, 500);
    delay(250);
  }

  else
  {
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
    display.print(velocity);
    display.println("km/h");
    display.display();  
    delay(250);
  }

  if(distance_cm > 5)
  { 
    
  }

}

void sendSMS(String phoneNumber, String message1, float message2, String message3) 
{
  Serial2.println("AT+CMGF=1");    // SMS 모드로 설정
  delay(100);
  Serial2.print("AT+CMGS=\"");
  Serial2.print(phoneNumber);     // 수신자 전화번호 설정
  Serial2.println("\"");
  delay(100);
  
  Serial2.print(message1);          // 메시지 내용 설정
  Serial2.print(message2);
  Serial2.print(message3);
  delay(100);
  
  Serial2.write(0x1A);               // Ctrl+Z 문자 전송 (메시지 보내기)
  delay(100);
  
  // 전송 결과 확인
  while (Serial2.available()) {
    Serial2.write(Serial2.read());
  }
}