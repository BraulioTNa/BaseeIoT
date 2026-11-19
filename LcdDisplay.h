
#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class LcdDisplay {
private:
    LiquidCrystal_I2C lcd;

public:
    LcdDisplay(uint8_t address = 0x27, uint8_t columns = 20, uint8_t rows = 4);

    void begin();
    void clear();

    void showWelcome();
    void showMessage(
        const String& line1,
        const String& line2 = "",
        const String& line3 = "",
        const String& line4 = ""
    );

    void showDistance(float distance);
    void showMotion(bool detected);
    void showGasLevel(int gasLevel);
    void showWeight(float weight);
    void showWifiStatus(bool connected, const String& ip = "");
};

#endif
