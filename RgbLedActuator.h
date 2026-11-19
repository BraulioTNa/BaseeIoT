
#ifndef RGB_LED_ACTUATOR_H
#define RGB_LED_ACTUATOR_H

#include <Arduino.h>
#include <ModestIoT.h>

class RgbLedActuator : public Actuator {
private:
    int redPin;
    int greenPin;
    int bluePin;

    void setColor(bool red, bool green, bool blue);

public:
    static const int RED_COMMAND_ID = 611;
    static const int GREEN_COMMAND_ID = 612;
    static const int BLUE_COMMAND_ID = 613;
    static const int WHITE_COMMAND_ID = 614;
    static const int OFF_COMMAND_ID = 615;

    static const Command RED_COMMAND;
    static const Command GREEN_COMMAND;
    static const Command BLUE_COMMAND;
    static const Command WHITE_COMMAND;
    static const Command OFF_COMMAND;

    RgbLedActuator(
        int redPin,
        int greenPin,
        int bluePin,
        CommandHandler* handler = nullptr
    );

    void executeCommand(Command command) override;

    void turnRed();
    void turnGreen();
    void turnBlue();
    void turnWhite();
    void turnOff();
};

#endif
