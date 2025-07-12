#include <Arduino.h>

int buttonPin = 2;int button2Pin = 3;int button3Pin = 4;
int button4Pin = 5;int ledRGBrPin = 9;int ledRGBgPin = 10;
int ledRGBbPin = 11;

int ledPinByNumber[3] = {9, 10, 11};
int buttonPinByNumber[4] = {2, 3, 4, 5};
int buttonLastStateStreak[4] = {0, 0, 0, 0};
int ledRGBstate[3] = {0, 0, 0};

unsigned long cooldown[4] {millis(), millis(), millis(), millis()};

void ledRGBaddRGB(int red, int green, int blue) {
  red += ledRGBstate[0];green += ledRGBstate[1];blue += ledRGBstate[2];
  if (red > 255){red = 0;};if (green > 255){green = 0;};if (blue > 255){blue = 0;};
  if (red < 0){red = 255;};if (green < 0){green = 255;};if (blue < 0){blue = 255;};
  
  ledRGBstate[0] = red;ledRGBstate[1] = green;ledRGBstate[2] = blue;
}
void ledRGBresetRGB() {ledRGBstate[0] = 0;ledRGBstate[1] = 0;ledRGBstate[2] = 0;}
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);pinMode(button2Pin, INPUT_PULLUP);pinMode(button3Pin, INPUT_PULLUP);
  pinMode(button4Pin, INPUT_PULLUP);pinMode(ledRGBrPin, OUTPUT);pinMode(ledRGBgPin, OUTPUT);
  pinMode(ledRGBbPin, OUTPUT);

  Serial.begin(250000);
}

void loop() {
  //Serial.println(String(digitalRead(buttonPin)) + String(digitalRead(button2Pin)) + String(digitalRead(button3Pin)) + String(digitalRead(button4Pin)));
  Serial.println(String(ledRGBstate[0]) + " " + String(ledRGBstate[1]) + " " + String(ledRGBstate[2]));
  analogWrite(ledRGBrPin, ledRGBstate[0]);analogWrite(ledRGBgPin, ledRGBstate[1]);analogWrite(ledRGBbPin, ledRGBstate[2]);
  
  for (int i = 0; i < 4; i++) {
    int localDigitalReadedButtonPin = digitalRead(buttonPinByNumber[i]);

    if(((localDigitalReadedButtonPin == 0 && abs(millis() - cooldown[i]) > 150)) || (buttonLastStateStreak[i] > 2 && localDigitalReadedButtonPin == 0 && abs(millis() - cooldown[i]) > 10)) {
      if(i == 3) {ledRGBresetRGB();}
      ledRGBaddRGB((i == 0 ? 1 : 0), (i == 1 ? 1 : 0), (i == 2 ? 1 : 0));
      buttonLastStateStreak[i]++;
      cooldown[i] = millis();
    } else if(localDigitalReadedButtonPin == 1) buttonLastStateStreak[i] = 0;
  }
}