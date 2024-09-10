#include <8052.h>
#include <stdint.h>

#ifndef UART_H
#define UART_H

void uart_init(void);
void uart_send(char data);
void uart_print(char* msg);

#endif
