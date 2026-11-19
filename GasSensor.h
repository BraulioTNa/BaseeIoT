
#ifndef PC2_GAS_SENSOR_H
#define PC2_GAS_SENSOR_H

#include <Arduino.h>
#include <ModestIoT.h>

class MQ2GasSensor : public Sensor {
private:
    int gasValue;

    void processEvent(Event& event) override;

public:
    static const int GAS_VALUE_UPDATED_EVENT_ID = 501;

    explicit MQ2GasSensor(
        int pin,
        EventHandler* handler = nullptr
    );

    int readGasLevel();
    int getGasLevel() const;

    void triggerRead();
};

#endif
