#pragma once

#include <iterator>

struct KnownNetwork
{
    const char *ssid;
    const char *password;
};


constexpr KnownNetwork KNOWN_NETWORKS[] = {
{"test", "test"},
};

constexpr size_t KNOWN_NETWORKS_COUNT = std::size(KNOWN_NETWORKS);