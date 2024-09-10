#include "at24c02.h"

uint8_t at24c02_read(uint8_t address) {
  i2c_start();
  i2c_send(AT24C02_WRITE_ADDRESS);
  i2c_receive_ack();
  i2c_send(address);
  i2c_receive_ack();
  i2c_start();
  i2c_send(AT24C02_READ_ADDRESS);
  i2c_receive_ack();
  uint8_t data = i2c_receive();
  i2c_send_ack(I2C_NO_ACK);
  i2c_stop();

  return data;
}

void at24c02_write(uint8_t address, uint8_t data) {
  i2c_start();
  i2c_send(AT24C02_WRITE_ADDRESS);
  i2c_receive_ack();
  i2c_send(address);
  i2c_receive_ack();
  i2c_send(data);
  i2c_receive_ack();
  i2c_stop();
}