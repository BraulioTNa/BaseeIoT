
#include "GasSensor.h"

MQ2GasSensor::MQ2GasSensor(
    int pin,
    EventHandler* handler
) : Sensor(pin, handler),
    gasValue(0) {

    pinMode(pin, INPUT);
}

int MQ2GasSensor::readGasLevel() {

    gasValue = analogRead(pin);

    return gasValue;
}

int MQ2GasSensor::getGasLevel() const {
    return gasValue;
}

void MQ2GasSensor::triggerRead() {
    readGasLevel();
}

void MQ2GasSensor::processEvent(Event& event) {

    if (event.identifier ==
        MEASURE_DATA_REQUESTED_EVENT_IDENTIFIER) {

        triggerRead();
    }
}
