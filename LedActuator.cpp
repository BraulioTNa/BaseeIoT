
#include "LedActuator.h"

const Command LedActuator::TURN_ON_COMMAND =
    Command(LedActuator::TURN_ON_COMMAND_ID);

const Command LedActuator::TURN_OFF_COMMAND =
    Command(LedActuator::TURN_OFF_COMMAND_ID);

const Command LedActuator::TOGGLE_LED_COMMAND =
    Command(LedActuator::TOGGLE_LED_COMMAND_ID);

LedActuator::LedActuator(
    int pin,
    bool initialState,
    CommandHandler* handler
) : Actuator(pin, handler), state(initialState) {

    pinMode(pin, OUTPUT);
    digitalWrite(pin, state ? HIGH : LOW);
}

void LedActuator::executeCommand(Command command) {

    if (command == TURN_ON_COMMAND) {
        turnOn();
    }
    else if (command == TURN_OFF_COMMAND) {
        turnOff();
    }
    else if (command == TOGGLE_LED_COMMAND) {
        toggle();
    }
}

void LedActuator::turnOn() {
    setState(true);
}

void LedActuator::turnOff() {
    setState(false);
}

void LedActuator::toggle() {
    setState(!state);
}

void LedActuator::setState(bool newState) {
    state = newState;
    digitalWrite(pin, state ? HIGH : LOW);
}

bool LedActuator::getState() const {
    return state;
}
