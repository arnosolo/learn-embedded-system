#include <8052.h>

#ifndef LED_H
#define LED_H

typedef enum {
  D1,
  D2,
  D3,
  D4,
  D5,
  D6,
  D7,
  D8,
} LedName;

typedef enum {
  OFF = 0,
  ON = 1,
} LedState;

void control_led(LedName led_name, LedState led_state);
LedState read_led_state(LedName led_name);
void toggle_led_state(LedName led_name);

#endif
