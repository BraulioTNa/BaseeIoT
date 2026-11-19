
#include "BaseIoTDevice.h"

BaseIoTDevice::BaseIoTDevice(unsigned long samplingInterval)
    : Device(samplingInterval),
      lastUpdateTime(0),
      updateInterval(samplingInterval),
      led(4, false),
      rgbLed(25, 26, 27),
      relay(23, false),
      servoActuator(13),
      ultrasonic(5, 18),
      pir(19),
      gasSensor(34),
      weightSensor(16, 17, 1.0),
      lcdDisplay(0x27, 20, 4) {
}

// ===============================
// INITIALIZATION
// ===============================

void BaseIoTDevice::begin() {
    Serial.println("Initializing IoT Device...");

    lcdDisplay.begin();
    lcdDisplay.showWelcome();

    led.turnOff();
    rgbLed.turnOff();
    relay.close();
    servoActuator.close();

    weightSensor.begin();

    bool connected = connectWifi();

    lcdDisplay.showWifiStatus(
        connected,
        wifiManager.getIPAddress()
    );
}

void BaseIoTDevice::update() {
    unsigned long currentTime = millis();

    if (currentTime - lastUpdateTime >= updateInterval) {
        lastUpdateTime = currentTime;
        Serial.println("IoT Device update...");
    }
}

// ===============================
// MODESTIOT EVENTS AND COMMANDS
// ===============================

void BaseIoTDevice::on(Event event) {
    Serial.print("Event received: ");
    Serial.println(event.identifier);
}

void BaseIoTDevice::handle(Command command) {
    Serial.print("Command received: ");
    Serial.println(command.identifier);

    led.handle(command);
    rgbLed.handle(command);
    relay.handle(command);
    servoActuator.handle(command);
}

// ===============================
// HC-SR04
// ===============================

float BaseIoTDevice::measureDistance() {
    float distance = ultrasonic.readDistance();

    Serial.print("Distance: ");

    if (distance < 0) {
        Serial.println("No echo detected");
    } else {
        Serial.print(distance);
        Serial.println(" cm");
    }

    lcdDisplay.showDistance(distance);

    return distance;
}

// ===============================
// PIR
// ===============================

bool BaseIoTDevice::detectMotion() {
    bool detected = pir.readMotion();

    Serial.print("Motion: ");
    Serial.println(detected ? "DETECTED" : "NOT DETECTED");

    lcdDisplay.showMotion(detected);

    return detected;
}

// ===============================
// MQ-2
// ===============================

int BaseIoTDevice::measureGasLevel() {
    int gasLevel = gasSensor.readGasLevel();

    Serial.print("Gas sensor ADC: ");
    Serial.println(gasLevel);

    if (gasLevel < 1000) {
        Serial.println("Gas level: LOW");
    } else if (gasLevel < 2500) {
        Serial.println("Gas level: MODERATE");
    } else {
        Serial.println("Gas level: HIGH");
    }

    lcdDisplay.showGasLevel(gasLevel);

    return gasLevel;
}

// ===============================
// HX711
// ===============================

float BaseIoTDevice::measureWeight() {
    float weight = weightSensor.readWeight();

    Serial.print("Weight: ");

    if (weight < 0) {
        Serial.println("Sensor not ready");
    } else {
        Serial.print(weight, 2);
        Serial.println(" units");
    }

    lcdDisplay.showWeight(weight);

    return weight;
}

void BaseIoTDevice::tareWeight() {
    weightSensor.tare();

    Serial.println("Weight sensor tared.");

    lcdDisplay.showMessage(
        "HX711 SENSOR",
        "Scale calibrated",
        "Tare completed",
        "Ready"
    );
}

// ===============================
// WIFI
// ===============================

bool BaseIoTDevice::connectWifi() {
    return wifiManager.connect("Wokwi-GUEST", "");
}

void BaseIoTDevice::showWifiStatus() {
    wifiManager.printStatus();

    lcdDisplay.showWifiStatus(
        wifiManager.isConnected(),
        wifiManager.getIPAddress()
    );
}

void BaseIoTDevice::disconnectWifi() {
    wifiManager.disconnect();

    lcdDisplay.showWifiStatus(false);
}
