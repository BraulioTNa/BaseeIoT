
#include "WeightSensor.h"

LoadCellWeightSensor::LoadCellWeightSensor(
    int dataPin,
    int clockPin,
    float calibrationFactor,
    EventHandler* handler
) : Sensor(dataPin, handler),
    calibrationFactor(calibrationFactor),
    weight(0.0) {

    scale.begin(dataPin, clockPin);
}

void LoadCellWeightSensor::begin() {

    if (scale.is_ready()) {
        scale.set_scale(calibrationFactor);
        scale.tare();
    }
}

float LoadCellWeightSensor::readWeight() {

    if (!scale.is_ready()) {
        return -1.0;
    }

    weight = scale.get_units(5);

    return weight;
}

long LoadCellWeightSensor::readRawValue() {

    if (!scale.is_ready()) {
        return -1;
    }

    return scale.read();
}

float LoadCellWeightSensor::getWeight() const {
    return weight;
}

void LoadCellWeightSensor::setCalibrationFactor(float factor) {

    if (factor != 0.0) {
        calibrationFactor = factor;
        scale.set_scale(calibrationFactor);
    }
}

void LoadCellWeightSensor::tare() {

    if (scale.is_ready()) {
        scale.tare();
        weight = 0.0;
    }
}

void LoadCellWeightSensor::triggerRead() {
    readWeight();
}

void LoadCellWeightSensor::processEvent(Event& event) {

    if (event.identifier ==
        MEASURE_DATA_REQUESTED_EVENT_IDENTIFIER) {

        triggerRead();
    }
}
