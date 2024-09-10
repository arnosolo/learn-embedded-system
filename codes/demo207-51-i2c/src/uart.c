#include "uart.h"

// 定时器初始值计算方法
// 定时器初始值 = 定时器最大值 - (系统时钟频率 / 定时器分频数) / (波特率 * (32 / 2^SMOD))
// 定时器初始值 = 256 - (11059200 / 12) / (9600 * (32 / 2^1)) = 250 = 0xFA
#define TIMER_START_VAL 0xFA

// 波特率 9600
void uart_init(void) {
  TMOD &= 0x0F;       // 清除高8位
  TMOD |= 0b00100000; // 定时器1, 模式2, 8位自动重装载模式
  TH1 = TIMER_START_VAL;         // 设置波特率
  TL1 = TIMER_START_VAL;         // 设置波特率
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
