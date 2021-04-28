#ifndef __ACTIVITY2_H__
#define __ACTIVITY2_H__

#include <avr/io.h>
#include<util/delay.h>

void initADC();
uint16_t ReadADC(uint8_t ch);
#endif