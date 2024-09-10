#include "i2c.h"

#ifndef AT24C02_H
#define AT24C02_H

#define AT24C02_ADDRESS       0b1010000
#define AT24C02_READ_ADDRESS  (uint8_t)(AT24C02_ADDRESS << 1 | 1)
#define AT24C02_WRITE_ADDRESS (uint8_t)(AT24C02_ADDRESS << 1 | 0)

uint8_t at24c02_read(uint8_t address);
void at24c02_write(uint8_t address, uint8_t data);

#endif