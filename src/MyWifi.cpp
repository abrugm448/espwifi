#include "MyWifi.h"
#include <WiFi.h>
#include "Secrets.h"
#include <esp_wifi.h>

void MyWifi::connect()
{
    WiFi.mode(WIFI_STA);

    uint8_t myMac[6] = { 0x02, 0x12, 0x34, 0x56, 0x78, 0x9A };
    esp_wifi_set_mac(WIFI_IF_STA, myMac);

    const KnownNetwork *net = findBestNetwork();
    if (!net)
    {
        return;
    }

    WiFi.begin(net.ssid, net.password);

    Serial.print("Connecting to wifi");
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

const KnownNetwork *MyWifi::findBestNetwork()
{
    int n = WiFi.scanNetworks();
    const KnownNetwork *best = nullptr;
    int bestRssi = -1000;

    for (int i = 0; i < n; ++i)
    {
        String ssid = WiFi.SSID(i);
        int rssi = WiFi.RSSI(i);

        for (size_t k = 0; k < KNOWN_NETWORKS_COUNT; ++k)
        {
            if (ssid == KNOWN_NETWORKS[k].ssid && rssi > bestRssi)
            {
                best = &KNOWN_NETWORKS[k];
                bestRssi = rssi;
            }
        }
    }
    WiFi.scanDelete();
    return best;
}
