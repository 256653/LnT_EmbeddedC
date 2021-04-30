#ifndef __ACTIVITY_H__
#define __ACTIVITY_H__

#include <avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>


void Init_USART(unsigned int ubrr);
void Transmit_USART(unsigned char data);

#endif