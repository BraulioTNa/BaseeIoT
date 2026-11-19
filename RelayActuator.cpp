
#include "RelayActuator.h"

const Command RelayActuator::OPEN_RELAY_COMMAND =
    Command(RelayActuator::OPEN_RELAY_COMMAND_ID);

const Command RelayActuator::CLOSE_RELAY_COMMAND =
    Command(RelayActuator::CLOSE_RELAY_COMMAND_ID);

const Command RelayActuator::TOGGLE_RELAY_COMMAND =
    Command(RelayActuator::TOGGLE_RELAY_COMMAND_ID);

RelayActuator::RelayActuator(
    int pin,
    bool activeLow,
    CommandHandler* handler
) : Actuator(pin, handler),
    state(false),
    activeLow(activeLow) {

    pinMode(pin, OUTPUT);
    close();
}

void RelayActuator::executeCommand(Command command) {

    if (command == OPEN_RELAY_COMMAND) {
        open();
    }
    else if (command == CLOSE_RELAY_COMMAND) {
        close();
    }
    else if (command == TOGGLE_RELAY_COMMAND) {
        toggle();
    }
}

void RelayActuator::open() {
    setState(true);
}

void RelayActuator::close() {
    setState(false);
}

void RelayActuator::toggle() {
    setState(!state);
}

void RelayActuator::setState(bool newState) {
    state = newState;

    if (activeLow) {
        digitalWrite(pin, state ? LOW : HIGH);
    } else {
        digitalWrite(pin, state ? HIGH : LOW);
    }
}

bool RelayActuator::getState() const {
    return state;
}
