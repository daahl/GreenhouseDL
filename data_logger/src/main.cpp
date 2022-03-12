/*
    Data logger for my greenhouse. Gotta know how those tomatoes are doing!
    Big thanks to https://randomnerdtutorials.com for all the amazing guides.
    This project would have been a lot less smooth without them.

    Feel free to reuse all or any of this code. Beerware, or something like that.

    By Marcus Dahlström 2022.
*/
#include <Arduino.h>
#include <esp_adc_cal.h>
// WiFi library
#include <WiFi.h>
// HTTP required to send push request to server
#include <HTTPClient.h>
// Temp and humidity sensor libraries
#include <SPI.h>
#include <Adafruit_Si7021.h>
// Local file not pushed to git with passwords, ssid, etc.
#include "password_config.h"

// Number of seconds between sensor readings = deep sleep time
const int SLEEPTIME = 1200;

// Data to be sent with the push request to the server
const String TEMPHUMSENSOR = "Si7021";
const String LOCATION = "Front greenhouse";
float currentTemp;
float currentHum;

/*
    Helper functions to keep the main program tidier
*/
void disableWiFi(){
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
  Serial.println("");
  Serial.println("WiFi disconnected");
}

void enableWiFi(){
  adc_power_on();
  WiFi.disconnect(false);
  WiFi.mode(WIFI_STA);
 
  Serial.println("WiFi connecting...");
  // Credentials saved in local file
  WiFi.begin(WIFI_SSID, WIFI_PASS);
 
  // Wait for the wifi connection
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void getthSensorReadings(){
  // Temp sensor object
  Adafruit_Si7021 thSensor = Adafruit_Si7021();

  // Open the sensor connection
  Serial.println("Connecting to sensor...");
  while(!thSensor.begin()){
    delay(100);
  }

  // Turn off heater, as we dont need it for short measurements
  thSensor.heater(false);

  currentTemp = thSensor.readTemperature();
  currentHum = thSensor.readHumidity();

  Serial.println(currentTemp);
  Serial.println(currentHum);
}

void sendDataToServer(){
  WiFiClient client;
  HTTPClient http;

  // Connect to the server. Credentials saved in local file
  http.begin(client, LAMP_SERVER);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  // Prepare your HTTP POST request data
  String httpRequestData = "api_key=" + String(API_KEY) + "&sensor=" + TEMPHUMSENSOR
                          + "&location=" + LOCATION + "&temperature=" + String(currentTemp)
                          + "&humidity=" + String(currentHum);
  Serial.print("httpRequestData: ");
  Serial.println(httpRequestData);

  // Send HTTP POST request
  int httpResponseCode = http.POST(httpRequestData);

  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
  }
  else {
     Serial.print("Error code: ");
     Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();
}

/*
    This is the main program, as deep sleep prevents the loop() from running.
*/
void setup(){
  Serial.begin(9600);
  delay(1000);
  Serial.println("Data logger started");
  adc_power_on();

  // Connect to wifi before and start logging
  enableWiFi();
  getthSensorReadings();
  sendDataToServer();

  // Enter deep sleep
  Serial.println("");
  Serial.printf("Going to sleep for %d seconds", SLEEPTIME);
  // Disconnect everything before going to sleep
  disableWiFi();
  btStop();
  adc_power_off();

  esp_sleep_enable_timer_wakeup(SLEEPTIME * 1000 * 1000);
  esp_deep_sleep_start();
}

void loop(){
}

