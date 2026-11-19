
#include "PirSensor.h"

MotionPirSensor::MotionPirSensor(
    int pin,
    EventHandler* handler
) : Sensor(pin, handler),
    motionDetected(false) {

    pinMode(pin, INPUT);
}

bool MotionPirSensor::readMotion() {

    int sensorValue = digitalRead(pin);

    motionDetected = (sensorValue == HIGH);

    return motionDetected;
}

bool MotionPirSensor::getMotionDetected() const {
    return motionDetected;
}

void MotionPirSensor::triggerRead() {
    readMotion();
}

void MotionPirSensor::processEvent(Event& event) {

    if (event.identifier ==
        MEASURE_DATA_REQUESTED_EVENT_IDENTIFIER) {

        triggerRead();
    }
}
