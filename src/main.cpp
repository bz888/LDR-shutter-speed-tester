#include <Arduino.h>

const int startStopPin = 2;
const int ldrPin = A0;
bool programRunningState = false;
int threshold = 150;
bool isOpen = false;
unsigned long start = 0;
unsigned long stop = 0;

void test(int ldrValue) {
    if (ldrValue > threshold) {
      Serial.println(ldrValue);
    }
}

void setup() {
  pinMode(startStopPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
    if(digitalRead(startStopPin)== LOW){
        delay(200);
        programRunningState = !programRunningState;
        if (programRunningState) {
          Serial.println("Program Started. Monitoring light changes...");
        } else {
          Serial.println("Program Stopped.");
        }
        while (digitalRead(startStopPin) == LOW);
    }

    int ldrValue = analogRead(ldrPin);
    test(ldrValue);

    // shutter opens
    if (ldrValue > threshold && !isOpen) {
      start = micros();

      Serial.print("start ");
      Serial.println(start); 

      isOpen = true;
    } 
    // shutter closes
    else if (ldrValue <= threshold && isOpen) {
      stop = micros();
      Serial.print("stop ");
      Serial.println(stop); 

      unsigned long duration = stop - start;
      float ms = duration/1000;
      float secs = ms/1000;
      float shutterspeed = 1.0 / (ms / 1000.0);

      Serial.print("duration micro: ");
      Serial.println(duration);

      Serial.print("duration ms: ");
      Serial.println(ms);

      Serial.print("duration sec: ");
      Serial.println(secs);

      Serial.print("shutter speed: 1/");
      Serial.println(shutterspeed);

      start = 0;
      stop = 0;

      isOpen = false;
    }
}
