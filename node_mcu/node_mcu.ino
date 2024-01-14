#define BLYNK_TEMPLATE_ID "TMPL3F3mfIdQ-"
#define BLYNK_TEMPLATE_NAME "soil moisture"
#define BLYNK_AUTH_TOKEN "PlpwEI8xeXvNvwhly_Y-VraIZWSmZXtp"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "srujan";
char pass[] = "11111111";
int moisture_sensor1;
int resualt;
int readD1;
int moisture;
int pin1 = 0;
int temp;

BlynkTimer timer;










void setup() {
  Serial.begin(9600);
pinMode(pin1,OUTPUT);

  pinMode(A0,INPUT);





  Blynk.begin(auth, ssid, pass);

 

}

void loop() {
   Blynk.run();
   
 
 
   temp = analogRead(A0);


  temp=temp/10;
  temp=72 -temp;
  temp=temp+17;
   Serial.print("VALUE=");
   Serial.println(temp);
   resualt=temp;
   delay(3000);
 
   

Blynk.virtualWrite(V1,resualt);











 


}   
