#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX

void setup() 
{
    Serial.begin(9600);
    BTserial.begin(9600);  
}
 
void loop()
{  
    while (BTserial.available()) // 슬레이브로 부터 데이터 수신 대기
    {  
      Serial.write( BTserial.read()); // 물이 없으면 1
    }
  delay(20);

 
}
