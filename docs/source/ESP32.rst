WIFI
****

WIFI Scan
=========

Using the ESP32, you can effortlessly perform a Wi-Fi scan to identify nearby wireless networks. This scan provides essential information including the SSID (network name), the channel each network operates on, and, most importantly, the signal strength (RSSI) of each network.

By analyzing the Wi-Fi scan results, you can assess the performance of different antennas with your ESP32 IPEX board. This allows you to make an informed decision on the most suitable antenna for your specific application, ensuring optimal connectivity and performance.

RSSI
----

RSSI (Received Signal Strength Indicator) is a measure of the power level of a received signal. It is commonly used in wireless communications to gauge the strength of a radio signal received by a device (ESP32). 

RSSI values are typically represented as negative numbers. For instance, 0 dBm represents the reference power level, and values like -30 dBm or -60 dBm represent power levels lower than this reference. The more negative the value, the weaker the signal. The closer the RSSI value is to zero, the stronger the signal. For example, -30 dBm is stronger than -60 dBm.  

For example, 
- -30dBm: Indicates a very strong signal close to the device.
- -60dBm: Represents a moderate signal strength, typically usable but not ideal.
- -90dBm: Indicates a very weak signal, likely to result in poor connectivity or intermittent drops.

Code
----

.. literalinclude:: ./code/ESP32/src/main-wifi-scan.cpp
    :linenos:
    :language: c++


.. image:: ./img/wifiscan_result
  :width: 400
  :alt: WIFI Scan Result