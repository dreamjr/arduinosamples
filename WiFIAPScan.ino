#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  Serial.println("Ready to scan...");

}

void loop() {
  Serial.println("Scanning start...");

  int n = WiFi.scanNetworks();
  Serial.println("Scanning completed...");

  if(n == 0) {
    Serial.println("AP is NOT found...");
  } else {
    Serial.print(n);
    Serial.println(" APs are found...");

    for(int i = 0; i < n; i++) {
      Serial.print(i + 1);
      Serial.print(" : ");
      Serial.print(WiFi.SSID(i));

      Serial.print(" <");
      Serial.print(WiFi.RSSI(i));
      Serial.println(" >");
    }
  }

  delay(5000);

}
