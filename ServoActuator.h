
#ifndef SERVO_ACTUATOR_H
#define SERVO_ACTUATOR_H

#include <Arduino.h>
#include <ModestIoT.h>
#include <ESP32Servo.h>

class ServoActuator : public Actuator {
private:
    Servo servo;
    int currentAngle;

public:
    static const int CLOSE_COMMAND_ID = 801;
    static const int OPEN_COMMAND_ID = 802;
    static const int MAX_POSITION_COMMAND_ID = 803;

    static const Command CLOSE_COMMAND;
    static const Command OPEN_COMMAND;
    static const Command MAX_POSITION_COMMAND;

    explicit ServoActuator(
        int pin,
        CommandHandler* handler = nullptr
    );

    void executeCommand(Command command) override;

    void close();
    void open();
    void moveToMaximum();
    void setAngle(int angle);

    int getAngle() const;
};

#endif
