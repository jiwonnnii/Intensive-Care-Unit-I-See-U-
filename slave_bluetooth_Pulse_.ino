#include <Wire.h>
#include <SoftwareSerial.h>

SoftwareSerial BTserial(2, 3); // RX | TX
 byte buffer[1024] ;
 int num=0; 
 
void setup() {
  Serial.begin(9600);
  BTserial.begin(9600);  

  Wire.begin();
  
  // water
  pinMode(2, INPUT);
  pinMode(13, OUTPUT); 
  //
}
void loop() {
  int sensorVal = digitalRead(7);
  
  Wire.requestFrom(0xA0 >> 1, 1);    // request 1 bytes from slave device 
  while(Wire.available()) {          // slave may send less than requested
    unsigned char c = Wire.read();   // receive heart rate value (a byte)

    Serial.print(c, DEC);         // print heart rate value
    Serial.print(",");
    Serial.println(sensorVal);

    if (sensorVal == HIGH) {
      digitalWrite(13, LOW);    
    } 
    else {
      digitalWrite(13, HIGH); 
    }

    BTserial.print(c);
    BTserial.print(",");
    BTserial.println(sensorVal);
  }
  delay(500);
}
