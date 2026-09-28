#include "motor_driver.h"
#include "adapter.h"

#define MOTOR_PIN 17

void setup_motor() { setup_pin(MOTOR_PIN, pin_mode::OUTPUT_MODE); }

void update_motor() {
  auto pin_state = read_pin_state(MOTOR_PIN);
  switch (pin_state) {
  case pin_state::HIGH_STATE:
    change_pin_state(MOTOR_PIN, pin_state::LOW_STATE);
    break;
  case pin_state::LOW_STATE:
    change_pin_state(MOTOR_PIN, pin_state::HIGH_STATE);
    break;
  }
}