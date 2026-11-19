
#include "Hcsr04Sensor.h"

Hcsr04Sensor::Hcsr04Sensor(
    int triggerPin,
    int echoPin,
    EventHandler* handler
) : Sensor(triggerPin, handler),
    echoPin(echoPin),
    distance(-1.0) {

    pinMode(pin, OUTPUT);
    pinMode(echoPin, INPUT);

    digitalWrite(pin, LOW);
}

float Hcsr04Sensor::readDistance() {

    digitalWrite(pin, LOW);
    delayMicroseconds(2);

    digitalWrite(pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(pin, LOW);

    unsigned long duration = pulseIn(
        echoPin,
        HIGH,
        30000
    );

    if (duration == 0) {
        distance = -1.0;
        return distance;
    }

    distance = duration * 0.0343 / 2.0;

    return distance;
}

float Hcsr04Sensor::getDistance() const {
    return distance;
}

void Hcsr04Sensor::triggerRead() {
    readDistance();
}

void Hcsr04Sensor::processEvent(Event& event) {

    if (event.identifier ==
        MEASURE_DATA_REQUESTED_EVENT_IDENTIFIER) {

        triggerRead();
    }
}
