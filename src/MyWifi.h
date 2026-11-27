#pragma once
#include <Arduino.h>

class MyWifi {
public:
  void connect(const char* ssid, const char* password);
  bool isConnected();
};