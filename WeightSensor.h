
#ifndef PC2_WEIGHT_SENSOR_H
#define PC2_WEIGHT_SENSOR_H

#include <Arduino.h>
#include <ModestIoT.h>
#include <HX711.h>

class LoadCellWeightSensor : public Sensor {
private:
    HX711 scale;
    float calibrationFactor;
    float weight;

    void processEvent(Event& event) override;

public:
    static const int WEIGHT_UPDATED_EVENT_ID = 601;

    explicit LoadCellWeightSensor(
        int dataPin,
        int clockPin,
        float calibrationFactor = 1.0,
        EventHandler* handler = nullptr
    );

    void begin();

    float readWeight();
    long readRawValue();

    float getWeight() const;

    void setCalibrationFactor(float factor);
    void tare();

    void triggerRead();
};

#endif
