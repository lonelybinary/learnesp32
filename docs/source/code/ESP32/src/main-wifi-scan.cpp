/*

The following ESP32 code performs a Wi-Fi network scan and outputs the SSID, channel, and signal strength (RSSI) of detected networks to the Serial Monitor. This example demonstrates how to utilize the ESP32's Wi-Fi scanning capabilities to gather and display network information.

You can use this code to evaluate the performance of various antennas with your ESP32 IPEX board and determine the optimal antenna for your application.

RSSI (Received Signal Strength Indicator) is a measure of the power level of a received signal. It is commonly used in wireless communications to gauge the strength of a radio signal received by a device (ESP32). 

RSSI values are typically represented as negative numbers. For instance, 0 dBm represents the reference power level, and values like -30 dBm or -60 dBm represent power levels lower than this reference. The more negative the value, the weaker the signal. The closer the RSSI value is to zero, the stronger the signal. For example, -30 dBm is stronger than -60 dBm.  

For example, 
-30 dBm: Indicates a very strong signal close to the device.
-60 dBm: Represents a moderate signal strength, typically usable but not ideal.
-90 dBm: Indicates a very weak signal, likely to result in poor connectivity or intermittent drops.

Support the creation of high-quality ESP32 tutorials by purchasing from Lonely Binary at www.lonelybinary.com.

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