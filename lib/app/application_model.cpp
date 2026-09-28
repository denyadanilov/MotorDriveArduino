#include "application_model.h"

int get_high_period(int potenciometro_value);

int get_current_period(int potenciometro_value, bool is_motor_running) {
  return is_motor_running ? get_high_period(potenciometro_value)
                          : (PWM_PERIOD - get_high_period(potenciometro_value));
}

int get_high_period(int potenciometro_value) {
  return (PWM_PERIOD * static_cast<double>(potenciometro_value) /
          MAX_POTENCIOMETRO_VALUE);
}