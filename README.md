# GreenhouseDL
An ongoing IoT project where a data logger for a greenhouse is being developed.

The basic concept is as follows:
- An ESP32 microcontroller will meassure the temperature and humidity of the inside of the green house every 30 minutes. The data will be stored locally on the the microcontroller at first.
- In between readings, the microcontroller will enter hiberation to save battery. A timer will wake the microcontroller from hibernation.
- Every 12h the local data will be sent to a LAMP server, hosted on a raspberry pi.
- The data will be accessible from the LAMP server via an interactive website, which will show plots of the data.

![Basic concept of the greenhouse data logger.](https://raw.githubusercontent.com/daahl/GreenhouseDL/main/basic_concept.png)
