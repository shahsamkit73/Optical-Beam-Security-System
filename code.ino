#include <SoftwareSerial.h>
SoftwareSerial mySerial(9,10);
void setup()
{
  mySerial.begin(9600);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
  delay(100);
}

void loop() 
{
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.println(voltage);
  if (voltage > 4 && voltage < 5.5)
  {
    sendMessage();
    digitalWrite(7,HIGH);
    delay(2000);
    digitalWrite(7,LOW);
    delay(2000);
  }
  else
  {
    digitalWrite(7,LOW);
  }
  delay(2000);
  }

void sendMessage()
{
  mySerial.println("AT+CMGS=\"phone_number\"\r");
  delay(1000);
  mySerial.println("ALERT !");
  delay(1000);
  mySerial.println((char)26);
  delay(1000);
}

