#include <stdint.h>

#ifndef UTILS_H
#define UTILS_H

void delay_ms(unsigned int ms);
void split_16bit_number(uint16_t number, uint8_t *highByte, uint8_t *lowByte);

#endif // UTILS_H