/**
 * @file activity2.c
 * @author Hemanth Naik (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include"activity2.h"


/**
 * @brief initialising the ADC
 * 
 */
void init_ADC()
{
    ADMUX = (1<<REFS0);
    ADCSRA |= (1<<ADEN) | (7<<ADPS0);
}

/**
 * @brief passing the channel
 * 
 * @param ch any channel from the C port
 * @return uint16_t the value read by the ADC
 */
uint16_t read_ADC(uint8_t ch)
{
    //Selection of ADC channel ch=[0-7]
    ADMUX &= 0xf8;
    ch = ch & 0b00000111;
    ADMUX |= ch;
    //Start Single Conversion
    ADCSRA |= (1<<ADSC);
    //Wait for conversion to complete
    while(!(ADCSRA&(1<<ADIF)));
    //clearing ADIF
    ADCSRA |= (1<<ADIF);
    return(ADC);
}