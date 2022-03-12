# Greenhouse Data Logger
An pretty much finished IoT project where a data logger for a greenhouse is being developed.

The basic concept is as follows:
- An ESP32 microcontroller will meassure the temperature and humidity of the inside of the green house every 20 minutes. 
- In between readings, the microcontroller will enter hiberation to save battery. A timer will wake the microcontroller from hibernation.
- Every reading is send to a LAMP server hostet on a local Raspberry Pi.
- TODO: The data will be accessible from the LAMP server via an interactive website, which will show plots of the data.

![Basic concept of the greenhouse data logger.](https://raw.githubusercontent.com/daahl/GreenhouseDL/main/images/basic_concept.png)

# The finished product

![Basic concept of the greenhouse data logger.](https://raw.githubusercontent.com/daahl/GreenhouseDL/main/images/setup.png | width = 500)

![Basic concept of the greenhouse data logger.](https://raw.githubusercontent.com/daahl/GreenhouseDL/main/images/box.png | width = 500)

![Basic concept of the greenhouse data logger.](https://raw.githubusercontent.com/daahl/GreenhouseDL/main/images/mounted.png | width = 500)

"https://your-image-url.type" height="100">
