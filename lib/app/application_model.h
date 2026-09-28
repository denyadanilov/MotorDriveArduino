#ifndef APPLICATION_MODEL_H
#define APPLICATION_MODEL_H

#define MAX_FREQUENCY 5000
#define MAX_POTENCIOMETRO_VALUE 4095
#define MICROSECONDS_IN_SECOND 1000000
#define PWM_PERIOD (MICROSECONDS_IN_SECOND / MAX_FREQUENCY)

int get_current_period(int potenciometro_value, bool is_motor_running);

#endif // APPLICATION_MODEL_H