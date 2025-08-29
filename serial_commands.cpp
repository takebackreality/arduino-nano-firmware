#include <Arduino.h>
#include "motor_control.h"
#include "firing_control.h"
#include "config.h"

namespace {
    String input;
}

namespace SerialCommands {
    void init() {
        Serial.begin(SERIAL_BAUD);
        input.reserve(32);
    }

    void update() {
        while (Serial.available()) {
            char c = (char)Serial.read();
            if (c == '\n') {
                if (input.startsWith("PAN")) {
                    int val = input.substring(3).toInt();
                    MotorControl::setPan(val);
                } else if (input.startsWith("TILT")) {
                    int val = input.substring(4).toInt();
                    MotorControl::setTilt(val);
                } else if (input.startsWith("FIRE")) {
                    FiringControl::fire();
                }
                input = "";
            } else {
                input += c;
            }
        }
    }
}
