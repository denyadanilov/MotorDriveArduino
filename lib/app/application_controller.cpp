#include "application_controller.h"
#include "adapter.h"
#include "application_model.h"
#include "motor_driver.h"
#include "potenciometro_driver.h"
#include <string>

unsigned long last_update_time = 0;
bool motor_running = false;

void setup_application() {
  initialize_logger();
  setup_potenciometro();
  setup_motor();
}

void loop_application() {
  int potenciometro_value = get_potenciometro_value();
  int high_period = get_high_period(potenciometro_value);
  int low_period = PWM_PERIOD - high_period;
  int current_period = motor_running ? high_period : low_period;

  auto current_time = get_micros_from_start();

  if (current_time - last_update_time >= current_period) {

    last_update_time = current_time;
    motor_running = !motor_running;

    update_motor();
  }
}