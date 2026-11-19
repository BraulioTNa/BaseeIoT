
#ifndef BASE_IOT_DEVICE_H
#define BASE_IOT_DEVICE_H

#include <Arduino.h>
#include <ModestIoT.h>

#include "LedActuator.h"
#include "RgbLedActuator.h"
#include "RelayActuator.h"
#include "ServoActuator.h"
#include "Hcsr04Sensor.h"
#include "PirSensor.h"
#include "GasSensor.h"
#include "WeightSensor.h"
#include "WifiManager.h"
#include "LcdDisplay.h"
/**
 * BaseIoTDevice
 * Base class for reusable IoT PC2 devices.
 */
class BaseIoTDevice : public Device {
protected:
    unsigned long lastUpdateTime;
    unsigned long updateInterval;

    LedActuator led;
    RgbLedActuator rgbLed;
    RelayActuator relay;
    ServoActuator servoActuator;

    Hcsr04Sensor ultrasonic;
    MotionPirSensor pir;
    MQ2GasSensor gasSensor;
    LoadCellWeightSensor weightSensor;

    WifiManager wifiManager;
    LcdDisplay lcdDisplay;

public:
    explicit BaseIoTDevice(unsigned long samplingInterval = 2500);
    bool detectMotion();
    float measureDistance();
    int measureGasLevel();
    float measureWeight();
    void tareWeight();
    virtual void begin();
    virtual void update();
    bool connectWifi();
    void showWifiStatus();
    void disconnectWifi();

    void on(Event event) override;
    void handle(Command command) override;
};

#endif
