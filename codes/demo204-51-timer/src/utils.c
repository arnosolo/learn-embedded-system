#include "utils.h"

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 120; j++) {
            // Do nothing, just waste time
        }
    }
}

void split_16bit_number(uint16_t number, uint8_t *highByte, uint8_t *lowByte) {
  *highByte = (number >> 8) & 0xFF; // Extract the high byte
  *lowByte = number & 0xFF;         // Extract the low byte
}
