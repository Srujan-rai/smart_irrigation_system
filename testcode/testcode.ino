int temp;
int humidity;
int moisture;
int pump=0;
int ledPin = 13;

void setup() {
 Serial.begin(9600); 
 pinMode(ledPin, OUTPUT);
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
 
}   else if (receivedChar == '1') {
    digitalWrite(ledPin, HIGH);
}
}
}
