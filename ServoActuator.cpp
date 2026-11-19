
#include "ServoActuator.h"

const Command ServoActuator::CLOSE_COMMAND =
    Command(ServoActuator::CLOSE_COMMAND_ID);

const Command ServoActuator::OPEN_COMMAND =
    Command(ServoActuator::OPEN_COMMAND_ID);

const Command ServoActuator::MAX_POSITION_COMMAND =
    Command(ServoActuator::MAX_POSITION_COMMAND_ID);

ServoActuator::ServoActuator(
    int pin,
    CommandHandler* handler
) : Actuator(pin, handler),
    currentAngle(0) {

    servo.setPeriodHertz(50);
    servo.attach(pin, 500, 2400);

    servo.write(currentAngle);
}

void ServoActuator::executeCommand(Command command) {

    if (command == CLOSE_COMMAND) {
        close();
    }
    else if (command == OPEN_COMMAND) {
        open();
    }
    else if (command == MAX_POSITION_COMMAND) {
        moveToMaximum();
    }
}

void ServoActuator::close() {
    setAngle(0);
}

void ServoActuator::open() {
    setAngle(90);
}

void ServoActuator::moveToMaximum() {
    setAngle(180);
}

void ServoActuator::setAngle(int angle) {

    if (angle < 0) {
        angle = 0;
    }

    if (angle > 180) {
        angle = 180;
    }

    currentAngle = angle;
    servo.write(currentAngle);
}

int ServoActuator::getAngle() const {
    return currentAngle;
}
