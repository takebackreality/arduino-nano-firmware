#include "config.h"
#include "motor_control.h"
#include "firing_control.h"
#include "serial_commands.h"

void setup() {
    MotorControl::init();
    FiringControl::init();
    SerialCommands::init();
}

void loop() {
    SerialCommands::update();
}
