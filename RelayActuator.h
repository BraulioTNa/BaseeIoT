
#ifndef RELAY_ACTUATOR_H
#define RELAY_ACTUATOR_H

#include <Arduino.h>
#include <ModestIoT.h>

class RelayActuator : public Actuator {
private:
    bool state;
    bool activeLow;

public:
    static const int OPEN_RELAY_COMMAND_ID = 701;
    static const int CLOSE_RELAY_COMMAND_ID = 702;
    static const int TOGGLE_RELAY_COMMAND_ID = 703;

    static const Command OPEN_RELAY_COMMAND;
    static const Command CLOSE_RELAY_COMMAND;
    static const Command TOGGLE_RELAY_COMMAND;

    explicit RelayActuator(
        int pin,
        bool activeLow = false,
        CommandHandler* handler = nullptr
    );

    void executeCommand(Command command) override;

    void open();
    void close();
    void toggle();

    void setState(bool newState);
    bool getState() const;
};

#endif
