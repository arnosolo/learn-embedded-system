#include <8051.h>
#include <stdint.h>

#ifndef I2C_H
#define I2C_H

#define I2C_SDA P2_0
#define I2C_SCL P2_1

typedef enum {
  I2C_ACK = 0,
  I2C_NO_ACK = 1,
} I2C_ACK_BIT;

void i2c_start(void);
void i2c_stop(void);
void i2c_send(uint8_t data);
uint8_t i2c_receive(void);
void i2c_send_ack(I2C_ACK_BIT ack_bit);
I2C_ACK_BIT i2c_receive_ack(void);

#endif