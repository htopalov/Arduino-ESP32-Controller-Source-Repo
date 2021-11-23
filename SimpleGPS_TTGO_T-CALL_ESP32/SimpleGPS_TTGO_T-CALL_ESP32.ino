#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// The TinyGPS++ object
TinyGPSPlus gps;



void setup(){
  Serial.begin(115200);

  Serial2.begin(9600, SERIAL_8N1, 14, 27); //RX, TX


}

void loop(){
  while (Serial2.available() > 0){
    gps.encode(Serial2.read());
    if (gps.location.isUpdated()){
      Serial.print("Latitude= "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= "); 
      Serial.println(gps.location.lng(), 6);
      Serial.print(" Altitude= "); 
      Serial.println(gps.altitude.meters(), 6);
      Serial.print(" Speed= "); 
      Serial.println(gps.speed.kmph(), 6); 
      Serial.print(" SatelliteCount= "); 
      Serial.println(gps.satellites.value(), 6);    
    }
  }
}
