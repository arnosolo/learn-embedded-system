#include <8052.h>
#include <stdint.h>
#include "delay.h"

void uart_init(void) {
  TMOD &= 0x0F;       // 清除高8位
  TMOD |= 0b00100000; // 定时器1, 模式2, 8位自动重装载模式
  TH1 = 0xFA;         // 设置波特率为9600
  TL1 = 0xFA;         // 设置波特率
  ET1 = 0;            // 禁止定时器中断
  TR1 = 1;            // 启动定时器1

  PCON |= 0b10000000; // SMOD = 1
  SM0 = 0;            // 设置工作模式为方式1
  SM1 = 1;            // 设置工作模式
  SM2 = 1;            // 只有在接收到有效停止位时才将中断请求标志位RI置为1
  REN = 1;            // 使能串口接收

  ES = 1;            // 使能串口中断
  EA = 1;            // 使能总中断
}

void uart_send(char data) {
  SBUF = data;      // 将数据写入缓冲区
  while (TI == 0);  // 等待数据发送完成
  TI = 0;           // 清除发送完成标志
}

void uart_print(char* msg) {
  while (*msg) {
    uart_send(*msg++);
  }
}

// 中断号为4的原因: STC89C52RC数据手册, 第6章 中断系统
void uart_isr(void)  __interrupt (4) {
  if (RI == 1) {          // 如果是接收中断
    RI = 0;               // 清除接收标志

    char received_data = SBUF;  // 读取接收到的数据
    uart_send(received_data);   // 发送接受到的数据
  }
}


void main(void) {
  uart_init();

  while (1) {
    uart_print("Hello from MCU\n");
    delay_ms(1000);
  }
}
