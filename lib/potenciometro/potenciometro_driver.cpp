#include "potenciometro_driver.h"
#include "adapter.h"

void setup_potenciometro() {
  setup_analog_resolution(POTENCIOMETRO_RESOLUTION);
}

int get_potenciometro_value() { return read_analog_pin(POTENCIOMETRO_PIN); }