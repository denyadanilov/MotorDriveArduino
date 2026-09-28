#include "application_controller.h"
#include "adapter.h"
#include "application_model.h"
#include "motor_driver.h"
#include "potenciometro_driver.h"

unsigned long last_update_time = 0;
bool is_motor_running = false;

void setup_application() {
  setup_potenciometro();
  setup_motor();
}

void loop_application() {
  int potenciometro_value = get_potenciometro_value();
  int current_period =
      get_current_period(potenciometro_value, is_motor_running);

  auto current_time = get_micros_from_start();

  if (current_time - last_update_time >= current_period) {

    last_update_time = current_time;
    is_motor_running = !is_motor_running;

    update_motor();
  }
}