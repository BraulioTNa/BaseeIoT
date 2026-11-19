
#ifndef HCSR04_SENSOR_H
#define HCSR04_SENSOR_H

#include <Arduino.h>
#include <ModestIoT.h>

class Hcsr04Sensor : public Sensor {
private:
    int echoPin;
    float distance;

    void processEvent(Event& event) override;

public:
    static const int DISTANCE_UPDATED_EVENT_ID = 301;

    explicit Hcsr04Sensor(
        int triggerPin,
        int echoPin,
        EventHandler* handler = nullptr
    );

    float readDistance();
    float getDistance() const;

    void triggerRead();
};

#endif
