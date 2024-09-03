#include <8052.h>
#include "led.h"
#include "math.h"

#define OSCILLATOR_FREQUENCY  11059200L
// Counter number in 1ms (12T mode)
#define COUNTER_NUM_FOR_1MS       (OSCILLATOR_FREQUENCY/12/1000)
#define TIMER_1_START_NUM         (65536 - COUNTER_NUM_FOR_1MS)

int count = 0;

/*
 * Timer0 interrupt routine
 * Note: __interrupt (1) is a SDCC specific keyword,
 * other compilers use different keywords
 */
void timer0_isr(void) __interrupt (1) {
  TL0 = get_low_bit(TIMER_1_START_NUM);
  TH0 = get_high_bit(TIMER_1_START_NUM);

  if (count == 1000) {
    count = 0;
    toggle_led_state(D2);
  }
  count++;
}

void setup_timer0(void) {
  TMOD &= 0xF0;     // Clear the lower 4 bits of TMOD,
  TMOD |= 0x01;     // Timer 0, internal oscillator, mode1 (16-bit)
  TL0 = get_low_bit(TIMER_1_START_NUM);
  TH0 = get_high_bit(TIMER_1_START_NUM);
  TR0 = 1;          // Start Timer 0

  EA = 1;           // Enable global interrupts
  ET0 = 1;          // Enable Timer 0 interrupt
}

void main(void) {
  setup_timer0();

  while (1) {
  }
}
