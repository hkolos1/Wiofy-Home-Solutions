#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "";

char ssid[] = "";
char pass[] = "";

const int relay=8;
const int Ainput=A0;
int ldrValue = 0;       
int range = 0; 

void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  
  ldrValue = analogRead(Ainput);

  range = map(ldrValue, 0, 1023, 0, 255);
  
  Serial.println(range);
  if(range>125)
  digitalWrite(relay,LOW);
  else
  digitalWrite(relay,HIGH);

}