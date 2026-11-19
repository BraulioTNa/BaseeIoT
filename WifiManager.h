
#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <Arduino.h>
#include <WiFi.h>

class WifiManager {
private:
    String ssid;
    String password;

public:
    WifiManager();

    bool connect(
        const char* networkSSID,
        const char* networkPassword
    );

    bool isConnected() const;

    void disconnect();

    String getIPAddress() const;

    String getSSID() const;

    void printStatus();
};

#endif
