int temp;
int humidity;
int moisture;
int pump=0;
int ledPin = 13;

#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
void setup() {
 Serial.begin(9600); 
 pinMode(ledPin, OUTPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
 display.clearDisplay();  
 display.display(); 

}

void loop() {
temp=analogRead(A0);
humidity=analogRead(A1);
moisture=analogRead(A2);
moisture=moisture/10;
moisture=105-moisture;
moisture=moisture+10;
temp=temp/10;
temp=72 -temp;
humidity=humidity/10;
humidity=humidity-45;


Serial.print(temp);
Serial.print(",");
Serial.print(humidity);
Serial.print(",");
Serial.println(moisture);
delay(3000);
  if (Serial.available() > 0) {
    char receivedChar = Serial.read();
    if (receivedChar == '0') {
    digitalWrite(ledPin, LOW);
    display.clearDisplay();
  display.setTextSize(2);  
  display.setTextColor(WHITE); 
  display.setCursor(1, 0); 
  display.print("water=");  
  display.println(moisture); 
  display.print("humid=");  
  display.println(humidity);  
  display.print("temp=");  
  display.println(temp); 
  display.println("PUMP OFF");    
  display.display();  
  delay(10);
 
}   else if (receivedChar == '1') {
    digitalWrite(ledPin, HIGH);
    display.clearDisplay();
  display.setTextSize(2);  
  display.setTextColor(WHITE); 
  display.setCursor(1, 0); 
  display.print("water=");  
  display.println(moisture); 
  display.print("humid=");  
  display.println(humidity);  
  display.print("temp=");  
  display.println(temp); 
  display.println("PUMP ON");    
  display.display();  
  delay(10);
}
}
}
