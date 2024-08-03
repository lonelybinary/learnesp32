/*

The following ESP32 code performs a Wi-Fi network scan and outputs the SSID, channel, 
and signal strength (RSSI) of detected networks to the Serial Monitor. 

Support the creation of high-quality ESP32 tutorials by purchasing 
from Lonely Binary at www.lonelybinary.com.

ESP32 IPEX External Antenna Board
https://lonelybinary.com/products/esp32-ipex

ESP32-S3 IPEX External Antenna Board
https://lonelybinary.com/products/esp32-s3-ipex

*/

#include <Arduino.h>
#include "WiFi.h"

void setup() {
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected.
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

}

void loop() {
  Serial.println("Scan start");

  // WiFi.scanNetworks will return the number of networks found.
  int n = WiFi.scanNetworks();

  Serial.println("Scan done");

  if (n == 0) {
    Serial.println("no networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    Serial.println("Nr | SSID                             | RSSI | CH");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.printf("%2d", i + 1);
      Serial.print(" | ");
      Serial.printf("%-32.32s", WiFi.SSID(i).c_str());
      Serial.print(" | ");
      Serial.printf("%4ld", WiFi.RSSI(i));
      Serial.print(" | ");
      Serial.printf("%2ld", WiFi.channel(i));
      Serial.println();
      delay(10);
    }
  }
  Serial.println("");

  // Delete the scan result to free memory for code below.
  WiFi.scanDelete();

  // Wait a bit before scanning again.
  delay(5000);
}