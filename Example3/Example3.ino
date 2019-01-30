
#include "WiFi.h"
#include <Wire.h>
#include "SSD1306.h"

SSD1306  display(0x3c, 21, 22);


void setup()
{
  Serial.begin(115200);
  display.init();

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void loop()
{
  display.clear();
  display.drawString(32, 20, "Scan Starting.");
  display.display();
  delay(750);

  display.clear();
  display.drawString(32, 20, "Scan Starting..");
  display.display();
  delay(750);

  display.clear();
  display.drawString(32, 20, "Scan Starting...");
  display.display();
  delay(750);

  display.clear();
  int n = WiFi.scanNetworks();

  if (n == 0) {
    display.clear();
    display.drawString(32, 20, "Networks Not Found!");
    display.display();
    delay(750);
  } else {
    int indis = 0;
    for (int i = 0; i < n; ++i) {
      display.drawString(0, indis, WiFi.SSID(i));
      display.display();
      delay(10);
      indis = indis + 10;
    }
  }
  delay(5000);
}
