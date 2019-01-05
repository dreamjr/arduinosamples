#include <ESP8266WiFi.h>

char *ssid = "..";
char *password = "..";

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  Serial.println("Connecting to \'");
  Serial.print(ssid);
  Serial.println("\'");

  WiFi.begin(ssid, password);

  // API 접속 대기
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.println("WiFi connected...");

  Serial.println();
  Serial.println(" * AP, IP information *");
  Serial.print("SSID : ");\
  Serial.println(WiFi.SSID());
  Serial.print("RSSI : ");
  Serial.println(WiFi.RSSI());
  Serial.print("IP : ");
  Serial.println(WiFi.localIP());  
  Serial.print("MAC address : ");
  Serial.println(WiFi.macAddress());
}

void loop() {
  
}
