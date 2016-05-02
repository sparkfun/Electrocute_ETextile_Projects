#include <SoftwareSerial.h>
int Mic = A2;
int LED1 = 5;
int LED2 = A5;
int LED3 = A4;
int LED4 = 9;
int LED5 = 10;
int LED6 = 11;

void setup() {
  pinMode(Mic, INPUT);
  pinMode(LED1, OUTPUT);
  digitalWrite(LED1, LOW);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED2, LOW);
  pinMode(LED3, OUTPUT);
  digitalWrite(LED3, LOW);
  pinMode(LED4, OUTPUT);
  digitalWrite(LED4, LOW);
  pinMode(LED5, OUTPUT);
  digitalWrite(LED5, LOW);
  pinMode(LED6, OUTPUT);
  digitalWrite(LED6, LOW);
  Serial.begin(9600);

}

void loop() {
  int Aud = analogRead(Mic);
  Serial.println(Aud);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);

  if (Aud < 550){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    delay(20);
  }
  if (550 < Aud && Aud < 650){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    delay(20);
  }
  if (650 < Aud && Aud < 750){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    delay(20);
  }
  if (750 < Aud && Aud < 850){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    delay(20);
  }
  if (850 < Aud && Aud < 950){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED6, LOW);
    delay(20);
  }
  if (Aud > 950){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED6, HIGH);
    delay(20);
  }
  
}
