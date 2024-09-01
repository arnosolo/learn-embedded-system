#include "led.h"

void control_led(LedName led_name, LedState led_state)
{
  unsigned int val = led_state == ON ? 0 : 1;
  switch (led_name)
  {
  case D1:
    P2_0 = val;
    break;
  case D2:
    P2_1 = val;
    break;
  case D3:
    P2_2 = val;
    break;
  case D4:
    P2_3 = val;
    break;
  case D5:
    P2_4 = val;
    break;
  case D6:
    P2_5 = val;
    break;
  case D7:
    P2_6 = val;
    break;
  case D8:
    P2_7 = val;
    break;

  default:
    break;
  }
}

LedState read_led_state(LedName led_name) {
  switch (led_name)
  {
  case D1:
    return P2_0 == 0 ? ON : OFF;
  case D2:
    return P2_1 == 0 ? ON : OFF;
    break;
  case D3:
    return P2_2 == 0 ? ON : OFF;
    break;
  case D4:
    return P2_3 == 0 ? ON : OFF;
    break;
  case D5:
    return P2_4 == 0 ? ON : OFF;
    break;
  case D6:
    return P2_5 == 0 ? ON : OFF;
    break;
  case D7:
    return P2_6 == 0 ? ON : OFF;
    break;
  case D8:
    return P2_7 == 0 ? ON : OFF;
    break;

  default:
    return OFF;
  }
}

void toggle_led_state(LedName led_name) {
  LedState led_state = read_led_state(led_name);
  control_led(led_name, led_state == ON ? OFF : ON);
}