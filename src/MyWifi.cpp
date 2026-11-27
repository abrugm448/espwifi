#include "MyWifi.h"
#include <WiFi.h>
#include <esp_wifi.h>

void MyWifi::connect(const char *ssid, const char *password)
{
    WiFi.mode(WIFI_STA);

    uint8_t myMac[6] = { 0x02, 0x12, 0x34, 0x56, 0x78, 0x9A };
    esp_wifi_set_mac(WIFI_IF_STA, myMac);

    WiFi.begin(ssid, password);

    Serial.print("Connecting to wifi");
    Serial.println("[" + String(password) + "]");
    WiFi.begin(ssid, password);

    Serial.print("MAC-adres: ");
    Serial.println(WiFi.macAddress());

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(WiFi.status());
        Serial.print(" ");
    }
    Serial.println();
    Serial.print("Connected to wifi, IP-adres: ");
    Serial.println(WiFi.localIP());
}

bool MyWifi::isConnected()
{
    return WiFi.status() == WL_CONNECTED;
}
