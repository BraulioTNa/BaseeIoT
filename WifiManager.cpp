
#include "WifiManager.h"

WifiManager::WifiManager() {
    ssid = "";
    password = "";
}

bool WifiManager::connect(
    const char* networkSSID,
    const char* networkPassword
) {
    ssid = networkSSID;
    password = networkPassword;

    Serial.println();
    Serial.println("Connecting to WiFi...");

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid.c_str(), password.c_str());

    unsigned long startTime = millis();

    while (
        WiFi.status() != WL_CONNECTED &&
        millis() - startTime < 15000
    ) {
        delay(500);
        Serial.print(".");
    }

    Serial.println();

    if (isConnected()) {
        Serial.println("WiFi connected!");
        printStatus();
        return true;
    }

    Serial.println("WiFi connection failed.");
    return false;
}

bool WifiManager::isConnected() const {
    return WiFi.status() == WL_CONNECTED;
}

void WifiManager::disconnect() {
    WiFi.disconnect();
    Serial.println("WiFi disconnected.");
}

String WifiManager::getIPAddress() const {
    return WiFi.localIP().toString();
}

String WifiManager::getSSID() const {
    return ssid;
}

void WifiManager::printStatus() {

    Serial.println("----- WIFI STATUS -----");

    if (isConnected()) {
        Serial.println("Status: CONNECTED");

        Serial.print("SSID: ");
        Serial.println(getSSID());

        Serial.print("IP Address: ");
        Serial.println(getIPAddress());
    } else {
        Serial.println("Status: DISCONNECTED");
    }

    Serial.println("-----------------------");
}
