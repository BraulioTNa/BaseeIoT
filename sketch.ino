
#include <Arduino.h>
#include <ModestIoT.h>

#include "BaseIoTDevice.h"
#include "LedActuator.h"
#include "RgbLedActuator.h"
#include "RelayActuator.h"
#include "ServoActuator.h"

// =====================================
// DEVICE INSTANCE
// =====================================

BaseIoTDevice device;

// =====================================
// STARTUP
// =====================================

void setup() {
    Serial.begin(115200);

    delay(500);

    Serial.println();
    Serial.println("================================");
    Serial.println("        IoT BASE PROJECT");
    Serial.println("================================");
    Serial.println("Developer: YOUR FULL NAME");
    Serial.println("Platform: ESP32");
    Serial.println("Framework: ModestIoT");
    Serial.println("================================");

    // Initialize device
    device.begin();

    // Display control menu
    Serial.println();
    Serial.println("================================");
    Serial.println("       DEVICE CONTROL MENU");
    Serial.println("================================");

    // INDIVIDUAL LED
    Serial.println();
    Serial.println("[INDIVIDUAL LED]");
    Serial.println("1 - TURN ON");
    Serial.println("0 - TURN OFF");
    Serial.println("t - TOGGLE");

    // RGB LED
    Serial.println();
    Serial.println("[RGB LED]");
    Serial.println("r - RED");
    Serial.println("g - GREEN");
    Serial.println("b - BLUE");
    Serial.println("w - WHITE");
    Serial.println("o - OFF");

    // RELAY
    Serial.println();
    Serial.println("[RELAY]");
    Serial.println("a - OPEN");
    Serial.println("c - CLOSE");
    Serial.println("v - TOGGLE");

    // SERVO
    Serial.println();
    Serial.println("[SERVO]");
    Serial.println("x - CLOSE (0 degrees)");
    Serial.println("y - OPEN (90 degrees)");
    Serial.println("z - MAX (180 degrees)");

    // SENSORS
    Serial.println();
    Serial.println("[SENSORS]");
    Serial.println("d - READ DISTANCE");
    Serial.println("p - DETECT MOTION");
    Serial.println("m - READ GAS LEVEL");
    Serial.println("h - READ WEIGHT");
    Serial.println("k - TARE SCALE");

    // WIFI
    Serial.println();
    Serial.println("[WIFI]");
    Serial.println("i - SHOW WIFI STATUS");
    Serial.println("n - CONNECT WIFI");
    Serial.println("j - DISCONNECT WIFI");

    Serial.println();
    Serial.println("================================");
    Serial.println("Enter a command in Serial Monitor");
    Serial.println("================================");
}

// =====================================
// MAIN LOOP
// =====================================

void loop() {

    // Periodic device update
    device.update();

    // Read serial commands
    if (Serial.available() > 0) {

        char command = Serial.read();

        switch (command) {

            // =============================
            // INDIVIDUAL LED
            // =============================

            case '1':
                device.handle(LedActuator::TURN_ON_COMMAND);
                break;

            case '0':
                device.handle(LedActuator::TURN_OFF_COMMAND);
                break;

            case 't':
            case 'T':
                device.handle(LedActuator::TOGGLE_LED_COMMAND);
                break;

            // =============================
            // RGB LED
            // =============================

            case 'r':
            case 'R':
                device.handle(RgbLedActuator::RED_COMMAND);
                break;

            case 'g':
            case 'G':
                device.handle(RgbLedActuator::GREEN_COMMAND);
                break;

            case 'b':
            case 'B':
                device.handle(RgbLedActuator::BLUE_COMMAND);
                break;

            case 'w':
            case 'W':
                device.handle(RgbLedActuator::WHITE_COMMAND);
                break;

            case 'o':
            case 'O':
                device.handle(RgbLedActuator::OFF_COMMAND);
                break;

            // =============================
            // RELAY
            // =============================

            case 'a':
            case 'A':
                device.handle(RelayActuator::OPEN_RELAY_COMMAND);
                break;

            case 'c':
            case 'C':
                device.handle(RelayActuator::CLOSE_RELAY_COMMAND);
                break;

            case 'v':
            case 'V':
                device.handle(RelayActuator::TOGGLE_RELAY_COMMAND);
                break;

            // =============================
            // SERVO
            // =============================

            case 'x':
            case 'X':
                device.handle(ServoActuator::CLOSE_COMMAND);
                break;

            case 'y':
            case 'Y':
                device.handle(ServoActuator::OPEN_COMMAND);
                break;

            case 'z':
            case 'Z':
                device.handle(ServoActuator::MAX_POSITION_COMMAND);
                break;

            // =============================
            // HC-SR04 ULTRASONIC SENSOR
            // =============================

            case 'd':
            case 'D':
                device.measureDistance();
                break;

            // =============================
            // PIR MOTION SENSOR
            // =============================

            case 'p':
            case 'P':
                device.detectMotion();
                break;

            // =============================
            // MQ-2 GAS SENSOR
            // =============================

            case 'm':
            case 'M':
                device.measureGasLevel();
                break;

            // =============================
            // HX711 WEIGHT SENSOR
            // =============================

            case 'h':
            case 'H':
                device.measureWeight();
                break;

            case 'k':
            case 'K':
                device.tareWeight();
                break;

            // =============================
            // WIFI
            // =============================

            case 'i':
            case 'I':
                device.showWifiStatus();
                break;

            case 'n':
            case 'N':
                device.connectWifi();
                device.showWifiStatus();
                break;

            case 'j':
            case 'J':
                device.disconnectWifi();
                break;

            // =============================
            // INVALID COMMAND
            // =============================

            case '\n':
            case '\r':
                break;

            default:
                Serial.print("Unknown command: ");
                Serial.println(command);
                break;
        }
    }
}
