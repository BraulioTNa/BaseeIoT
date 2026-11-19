
#ifndef LED_ACTUATOR_H
#define LED_ACTUATOR_H

#include <Arduino.h>
#include <ModestIoT.h>

class LedActuator : public Actuator {
private:
    bool state;

public:
    static const int TURN_ON_COMMAND_ID = 601;
    static const int TURN_OFF_COMMAND_ID = 602;
    static const int TOGGLE_LED_COMMAND_ID = 603;

    static const Command TURN_ON_COMMAND;
    static const Command TURN_OFF_COMMAND;
    static const Command TOGGLE_LED_COMMAND;

    explicit LedActuator(
        int pin,
        bool initialState = false,
        CommandHandler* handler = nullptr
    );

    void executeCommand(Command command) override;

    void turnOn();
    void turnOff();
    void toggle();
    void setState(bool newState);

    bool getState() const;
};

#endif
