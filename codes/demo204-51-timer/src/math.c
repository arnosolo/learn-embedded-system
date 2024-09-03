#include "math.h"

uint8_t get_high_bit(uint16_t number) {
  return (number >> 8) & 0xFF;
}

uint8_t get_low_bit(uint16_t number) {
  return number & 0xFF;
}
