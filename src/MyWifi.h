#pragma once
#include <Arduino.h>

class MyWifi {
public:
  void connect();
  bool isConnected();

private:
    const KnownNetwork *findBestNetwork();
};