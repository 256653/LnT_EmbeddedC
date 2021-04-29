#ifndef __ACTIVITY_H__
#define __ACTIVITY_H__

#include <avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

void USART_Init(unsigned int ubrr);
void USART_Transmit(unsigned char data);

#endif