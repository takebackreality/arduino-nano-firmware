#include <Arduino.h>
#include "config.h"

namespace FiringControl {
    void init() {
        pinMode(FIRE_PIN, OUTPUT);
        digitalWrite(FIRE_PIN, LOW);
    }

    void fire() {
        digitalWrite(FIRE_PIN, HIGH);
        delay(200);
        digitalWrite(FIRE_PIN, LOW);
    }
}
