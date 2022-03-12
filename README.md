# Greenhouse Data Logger
An pretty much finished IoT project where a data logger for a greenhouse is being developed.

The basic concept is as follows:
- An ESP32 microcontroller will meassure the temperature and humidity of the inside of the green house every 20 minutes. 
- In between readings, the microcontroller will enter hiberation to save battery. A timer will wake the microcontroller from hibernation.
- Every reading is send to a LAMP server hostet on a local Raspberry Pi.
- TODO: The data will be accessible from the LAMP server via an interactive website, which will show plots of the data.

<img  src="https://raw.githubusercontent.com/daahl/GreenhouseDL/main/images/basic_concept.png" width="700")

# The finished product

<img src="https://raw.githubusercontent.com/daahl/GreenhouseDL/main/images/setup.jpg" width="500">

<img src="https://raw.githubusercontent.com/daahl/GreenhouseDL/main/images/box.jpg" width="500">

<img src="https://raw.githubusercontent.com/daahl/GreenhouseDL/main/images/mounted.jpg" width="500">

<img src="https://raw.githubusercontent.com/daahl/GreenhouseDL/main/images/webpage.PNG" width="500">
