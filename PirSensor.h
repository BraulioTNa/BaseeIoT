
#ifndef PC2_PIR_SENSOR_H
#define PC2_PIR_SENSOR_H

#include <Arduino.h>
#include <ModestIoT.h>

class MotionPirSensor : public Sensor {
private:
    bool motionDetected;

    void processEvent(Event& event) override;

public:
    static const int MOTION_DETECTED_EVENT_ID = 401;

    explicit MotionPirSensor(
        int pin,
        EventHandler* handler = nullptr
    );

    bool readMotion();
    bool getMotionDetected() const;

    void triggerRead();
};

#endif
