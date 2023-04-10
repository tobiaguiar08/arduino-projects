#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BAUD 9600
#define UBRR_VAL ((F_CPU/16/BAUD) - 1)

void uart_init() {
  UBRR0H = (unsigned char)(UBRR_VAL >> 8);
  UBRR0L = (unsigned char)UBRR_VAL;
  UCSR0B = (1 << TXEN0);
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

int main ()
{
  /*Init*/
  uart_init();
  while (1);
  return 0;
}
