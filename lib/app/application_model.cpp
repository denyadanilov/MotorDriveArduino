#include "application_model.h"

int get_high_period(int potenciometro_value) {
  return (PWM_PERIOD * static_cast<double>(potenciometro_value) /
          MAX_POTENCIOMETRO_VALUE);
}