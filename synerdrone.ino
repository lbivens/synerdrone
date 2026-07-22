/*
  For use with Lilygo T-Dongle S3
  Set USB Mode to USB-OTG (TinyUSB)
  Platform ESP32 Arduino >= 3.3.0
*/

#include "USB.h"
#include "USBHIDMouse.h"

USBHIDMouse Mouse;
long x, y;
bool running = false;

void setup() {

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
