
#include "RgbLedActuator.h"

const Command RgbLedActuator::RED_COMMAND =
    Command(RgbLedActuator::RED_COMMAND_ID);

const Command RgbLedActuator::GREEN_COMMAND =
    Command(RgbLedActuator::GREEN_COMMAND_ID);

const Command RgbLedActuator::BLUE_COMMAND =
    Command(RgbLedActuator::BLUE_COMMAND_ID);

const Command RgbLedActuator::WHITE_COMMAND =
    Command(RgbLedActuator::WHITE_COMMAND_ID);

const Command RgbLedActuator::OFF_COMMAND =
    Command(RgbLedActuator::OFF_COMMAND_ID);

RgbLedActuator::RgbLedActuator(
    int redPin,
    int greenPin,
    int bluePin,
    CommandHandler* handler
) : Actuator(redPin, handler),
    redPin(redPin),
    greenPin(greenPin),
    bluePin(bluePin) {

    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    turnOff();
}

void RgbLedActuator::executeCommand(Command command) {

    if (command == RED_COMMAND) {
        turnRed();
    }
    else if (command == GREEN_COMMAND) {
        turnGreen();
    }
    else if (command == BLUE_COMMAND) {
        turnBlue();
    }
    else if (command == WHITE_COMMAND) {
        turnWhite();
    }
    else if (command == OFF_COMMAND) {
        turnOff();
    }
}

void RgbLedActuator::setColor(
    bool red,
    bool green,
    bool blue
) {
    digitalWrite(redPin, red ? HIGH : LOW);
    digitalWrite(greenPin, green ? HIGH : LOW);
    digitalWrite(bluePin, blue ? HIGH : LOW);
}

void RgbLedActuator::turnRed() {
    setColor(true, false, false);
}

void RgbLedActuator::turnGreen() {
    setColor(false, true, false);
}

void RgbLedActuator::turnBlue() {
    setColor(false, false, true);
}

void RgbLedActuator::turnWhite() {
    setColor(true, true, true);
}

void RgbLedActuator::turnOff() {
    setColor(false, false, false);
}
