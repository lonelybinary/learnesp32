E-INK Paper
***********

Overview 
=========

E-ink technology, also known as electronic paper or e-paper, has evolved significantly since its conceptual beginnings in the 1970s. Initially explored as a way to create displays that mimic the appearance of ink on paper, e-ink technology was developed into a practical solution by the late 1990s and became widely adopted by the 2000s. Unlike traditional LCD or OLED screens, e-ink displays do not emit light directly but instead reflect ambient light, making them easier on the eyes and highly readable in bright sunlight, much like physical paper.

This technology has revolutionized industries such as e-readers and retail by providing energy-efficient, paper-like displays. Over the years, e-ink has expanded into a variety of applications, including digital signage, smartwatches, and other low-power devices, solidifying its role as a versatile and innovative display solution.

Here is the Key Features of E-ink paper:

**Low Power Consumption** E-ink displays only use power when the image on the screen changes. This makes them incredibly energy-efficient, with devices often lasting weeks on a single charge.

**High Readability** The screens have high contrast, resembling printed text on paper. They are easier to read in various lighting conditions, including direct sunlight.

**Bi-stability** Once an image is displayed, it remains on the screen without any power consumption until it is changed. This makes them ideal for applications like e-readers or electronic shelf labels.

**Slow Refresh Rate** E-ink displays typically have a slower refresh rate compared to other display technologies, which is why they are not ideal for video playback but are perfect for static images or text.

Recently, major supermarkets such as Woolworths and Coles have increasingly adopted e-ink price tags to replace traditional paper labels. Although the initial investment in e-ink technology may be higher, these digital tags significantly reduce ongoing costs by eliminating the need for frequent printing and manual replacement of paper labels. E-ink price tags allow prices to be updated instantly and remotely, enabling quick adjustments without requiring staff intervention. More importantly, electronic tags eliminate human error in price labeling, ensuring that the price displayed on the shelf always matches the checkout price, enhancing accuracy and customer trust.

E-ink price tags typically rely on small, long-lasting batteries to power both the display and communication components. Most are powered by coin-cell batteries, such as the CR2032, which provide low voltage (around 3V) and small current. These batteries can last several years, often between 3 to 5 years, with some tags utilizing more than one battery to extend lifespan. To update price details, e-ink price tags use energy-efficient communication protocols, such as sub-GHz radio frequencies (e.g., 433 MHz, 868 MHz), which consume far less power than Wi-Fi.

Monochrome and Color
====================
The e-ink display market offers a variety of options in terms of both size and color. These displays are typically available in sizes ranging from 1.5 inches to 7.5 inches or larger. Monochrome e-ink displays render content in black and white (grayscale), which is ideal for most text-based applications, such as e-readers. For color displays, options include 3-color, 4-color, and 7-color variations. Generally, the more colors a display supports, the slower the refresh rate will be.


Refresh Rate
============

E-ink displays have traditionally been monochrome, but color e-ink technology has been developed and refined over the years. However, the introduction of color e-ink does come with some trade-offs, particularly in terms of refresh rate.

Monochrome e-ink displays have relatively slow refresh rates compared to LCD or OLED screens, as the e-ink particles take time to rearrange when the image changes. This makes them suitable for static content like text and simple images, but less ideal for video or rapidly changing content.

The refresh rate of color e-ink displays is generally slower than that of monochrome e-ink. The additional complexity of manipulating color layers or filters means that updating the screen takes longer, further reducing the refresh rate.

While color e-ink technology enhances the versatility of e-ink displays, it also generally results in slower refresh rates compared to monochrome e-ink. This trade-off means that color e-ink is best used in scenarios where the benefits of color outweigh the need for quick screen updates.

Refresh Mode
============

E-ink displays typically offer two refresh modes: partial refresh and full refresh. Monochrome e-ink displays generally support both modes, while color e-ink displays usually support only full refresh.

Partial refresh updates only the portion of the e-ink screen where changes have occurred, rather than refreshing the entire display. This mode is faster and consumes less power, making it ideal for small, frequent updates.

Full refresh, on the other hand, updates the entire e-ink screen, redrawing all content even if only a small part has changed. While full refresh ensures that the display is completely accurate and free from ghosting (faint remnants of previous images), it takes more time and energy compared to partial refresh.


ESP32 to E-Ink Display Wiring
=============================
Many e-ink displays use a Flexible Printed Circuit (FPC) connector with 24 pins, commonly referred to as FPC 24. This type of connector is often used to interface the e-ink display with the controller board or directly with the microcontroller (MCU).

To physically connect an e-ink display to a microcontroller (MCU), you typically use the SPI (Serial Peripheral Interface) protocol, which is a common method for communication between an MCU and various peripheral devices.

SPI protocol
------------
The SPI protocol typically involves four main signal lines: MOSI (Master Out Slave In), MISO (Master In Slave Out), SCLK (Serial Clock), and CS (Chip Select). 

**MOSI (Master Out Slave In)** Connect the MOSI pin on the MCU to the MOSI pin on the e-ink display. This line carries data from the MCU to the display.

**MISO (Master In Slave Out)** Connect the MISO pin on the MCU to the MISO pin on the e-ink display. This line is usually not needed for e-ink displays, as they often only require data to be sent to them (MISO may be left unconnected if not used).

**SCLK (Serial Clock)** Connect the SCLK pin on the MCU to the SCLK pin on the e-ink display. This line carries the clock signal from the MCU to synchronize data transmission.

**CS (Chip Select)** Connect the CS pin on the MCU to the CS (or sometimes labeled as SS for Slave Select) pin on the e-ink display. This line is used to select the e-ink display as the active device on the SPI bus.

Besides, those four SPI pins, we also need those additional three Control Pins:

**DC (Data/Command)** Connect the DC pin on the e-ink display to a digital I/O pin on the MCU. This pin is used to distinguish between data and command instructions.

**RST (Reset)** Connect the RST pin on the e-ink display to a digital I/O pin on the MCU. This pin is used to reset the display.

**BUSY** Connect the BUSY pin on the e-ink display to a digital I/O pin on the MCU. This pin indicates when the display is busy processing data and should not be disturbed.


ESP32 to E-Ink Display Wiring Pinout

.. list-table:: Wiring Connections between ESP32 and E-Ink Display
   :header-rows: 1

   * - E-Ink Display Pin
     - ESP32 Pin
     - Description
   * - VCC
     - 3.3V
     - Power supply for the e-ink display
   * - GND
     - GND
     - Ground connection
   * - MOSI
     - GPIO23
     - SPI Master Out Slave In (data line from ESP32 to display)
   * - SCLK
     - GPIO18
     - SPI Clock signal
   * - CS
     - GPIO5
     - Chip Select (enables communication with the display)
   * - DC
     - GPIO17
     - Data/Command control (selects between sending data or commands)
   * - RST
     - GPIO16
     - Reset pin for the e-ink display
   * - BUSY
     - GPIO4
     - Busy signal (indicates if the display is processing data)
   * - VCOM
     - Not connected
     - Common voltage, typically managed internally by the display controller
   * - LE
     - Not connected
     - Latch enable, often not required in basic SPI setups
   * - OE
     - Not connected
     - Output enable, not typically used
   * - D0-D7
     - Not connected
     - Parallel data lines, used in alternative interface modes
   * - BORDER
     - Not connected
     - Controls the border color in some e-ink displays
   * - VGL/VGH
     - Not connected
     - Voltage supplies for gate drivers, usually internal
   * - FR
     - Not connected
     - Frame signal for timing control
   * - SHD
     - Not connected
     - Shadow register control
   * - CKV
     - Not connected
     - Clock for the driver stage
   * - STV
     - Not connected
     - Vertical start signal
   * - Source/Gate
     - Not connected
     - Controls for source and gate drivers, often managed internally
   * - Enable
     - Not connected
     - Power enable, typically handled by VCC

ESP32 E-Ink Boards
==================

ESP32 with 3-color 2.13" E-Ink
------------------------------

ESP32 with 3-color 7.5" E-Ink
------------------------------

Programming
===========

The GxEPD2 library is a widely used Arduino library designed for controlling e-ink displays, particularly with microcontrollers like the ESP32. It supports a variety of e-ink displays from different manufacturers and offers both partial and full refresh capabilities. The library is optimized to work efficiently even on microcontrollers with limited memory, making it suitable for diverse projects.

GxEPD2 is built on top of the Adafruit GFX graphics library, which provides powerful and flexible functions for drawing pixels, lines, text, and shapes on a display buffer. By integrating with Adafruit GFX, GxEPD2 simplifies the process of rendering graphics on e-ink displays. While GxEPD2 manages the hardware-specific communication with the e-ink display, Adafruit GFX handles the general-purpose graphics rendering, making this combination a robust and user-friendly solution for e-ink display projects.

Installatioin
=============

Arduino IDE
-----------

Platform IO
-----------


Hello world
===========

full buffer
-----------

paged-based
-----------

