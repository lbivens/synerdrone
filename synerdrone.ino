/*
  For use with Lilygo T-Dongle S3
  Set USB Mode to USB-OTG (TinyUSB)
  Platform ESP32 Arduino >= 3.3.0
*/

#include <WiFi.h>
#include "USB.h"
#include "USBHIDMouse.h"

char ssid[] = "yourNetwork";
char pass[] = "secretPassword";
int status = WL_IDLE_STATUS;

USBHIDMouse Mouse;
long x, y;
bool running = false;

void setup() {
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(10000);
  }

  // This is the only button we have 
  pinMode(BOOT_PIN, INPUT_PULLUP);

  randomSeed(analogRead(0));
  Mouse.begin();
  USB.begin();
}

void loop() {
  // Enable or disable mouse movement when pressing button
  if (digitalRead(BOOT_PIN) == LOW) {
      running = !running;
  }

  if (running) {
      x = random(-100, 100);
      y = random(-100, 100);
      Mouse.move(x, y);
  }
  
  delay(500);
}