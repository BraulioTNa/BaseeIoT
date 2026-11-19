
#include "LcdDisplay.h"

LcdDisplay::LcdDisplay(uint8_t address, uint8_t columns, uint8_t rows)
    : lcd(address, columns, rows) {
}

void LcdDisplay::begin() {
    lcd.init();
    lcd.backlight();
    lcd.clear();
}

void LcdDisplay::clear() {
    lcd.clear();
}

void LcdDisplay::showMessage(
    const String& line1,
    const String& line2,
    const String& line3,
    const String& line4
) {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print(line1);

    lcd.setCursor(0, 1);
    lcd.print(line2);

    lcd.setCursor(0, 2);
    lcd.print(line3);

    lcd.setCursor(0, 3);
    lcd.print(line4);
}

void LcdDisplay::showWelcome() {
    showMessage(
        "IoT DEVICE - PC2",
        "System Starting...",
        "Initializing...",
        "Please wait"
    );
}

void LcdDisplay::showDistance(float distance) {
    showMessage(
        "HC-SR04 SENSOR",
        "Distance:",
        distance < 0 ? "No echo detected" : String(distance, 2) + " cm",
        "Measurement done"
    );
}

void LcdDisplay::showMotion(bool detected) {
    showMessage(
        "PIR SENSOR",
        "Motion detection:",
        detected ? "MOTION DETECTED" : "NO MOTION",
        "Status updated"
    );
}

void LcdDisplay::showGasLevel(int gasLevel) {
    String level;

    if (gasLevel < 1000) {
        level = "LOW";
    } else if (gasLevel < 2500) {
        level = "MODERATE";
    } else {
        level = "HIGH";
    }

    showMessage(
        "MQ-2 GAS SENSOR",
        "ADC: " + String(gasLevel),
        "Level: " + level,
        "Measurement done"
    );
}

void LcdDisplay::showWeight(float weight) {
    showMessage(
        "HX711 SENSOR",
        "Weight:",
        weight < 0 ? "Sensor not ready" : String(weight, 2) + " units",
        "Measurement done"
    );
}

void LcdDisplay::showWifiStatus(bool connected, const String& ip) {
    showMessage(
        "WIFI STATUS",
        connected ? "CONNECTED" : "DISCONNECTED",
        connected ? "IP: " + ip : "Check connection",
        "IoT DEVICE"
    );
}
