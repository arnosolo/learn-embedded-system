#include "i2c.h"

void i2c_start(void) {
  I2C_SDA = 1;
  I2C_SCL = 1;
  I2C_SDA = 0;  // Start condition: SDA goes low when SCL is high
  I2C_SCL = 0;
}

void i2c_stop(void) {
  I2C_SDA = 0;
  I2C_SCL = 1;
  I2C_SDA = 1;  // Stop condition: SDA goes high when SCL is high
}

void i2c_send(uint8_t data) {
  for (uint8_t i = 0; i < 8; i++) {
    I2C_SDA = data & (0x80 >> i);  // Send each bit
    // 注意! 从设备读取 SDA 状态需要时间, 所以 SCL 需要保持一段时间的高电平
    // 查看 AT24C02 数据手册得该芯片最大 SCL 时钟频率为 400kHz, 0.4us一个周期.
    // 51 单片机时钟频率为 11059200 Hz, 11us一个周期. 
    // 所以, 单片机将 SCL 置高后马上置低, 少说了过了 11us, 足够从设备读取 SCL 数据了.
    // 但是对于频率更高的单片机, 就可能需要延时增加 SCL 的时长了.
    I2C_SCL = 1;  // Clock high
    I2C_SCL = 0;  // Clock low
  }
}

uint8_t i2c_receive(void) {
  uint8_t data = 0;
  I2C_SDA = 1;  // Release SDA to read data
  for (uint8_t i = 0; i < 8; i++) {
    I2C_SCL = 1;
    data = (data << 1) | I2C_SDA;  // Read each bit from SDA
    I2C_SCL = 0;
  }
  return data;
}

void i2c_send_ack(I2C_ACK_BIT ack_bit){
  I2C_SDA = ack_bit; // Set ack bit in SDA
  I2C_SCL = 1; // Slave device start reading SDA
  I2C_SCL = 0; // Slave device stop reading SDA
}

I2C_ACK_BIT i2c_receive_ack(void){
  I2C_SDA = 1; // Release SDA
  I2C_SCL = 1; // Start reading SDA
  I2C_ACK_BIT ack_bit = I2C_SDA; // Read ack bit from SDA
  I2C_SCL = 0; // Stop reading SDA

  return ack_bit;
}