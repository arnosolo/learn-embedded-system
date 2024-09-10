#include <stdint.h>
#include <stdio.h>
#include "uart.h"
#include "at24c02.h"
#include "delay.h"

uint8_t count = 0;

// 中断号为4的原因: STC89C52RC数据手册, 第6章 中断系统
void uart_isr(void)  __interrupt (4) {
  if (RI == 1) {          // 如果是接收中断
    RI = 0;               // 清除接收标志

    char received_data = SBUF;  // 读取接收到的数据

    uint8_t storage_address = 0x02;
    count ++;

    if(received_data == 'w') {
      at24c02_write(storage_address, count);
      delay_ms(6); // 写入需要 5ms

      char str[20];
      sprintf(str, "Data saved, %d", count);
      uart_print(str);
      return;
    }
    if(received_data == 'r') {
      uint8_t data = at24c02_read(storage_address);

      char str[20];
      sprintf(str, "Data retrieved, %d", data);
      uart_print(str);
    }
  }
}

void main(void) {

  uart_init();
  while (1) {
  }
}
