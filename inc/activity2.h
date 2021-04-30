#ifndef __ACTIVITY2_H__
#define __ACTIVITY2_H__

#include <avr/io.h>
#include<util/delay.h>

void init_ADC();
uint16_t read_ADC(uint8_t ch);
#endif