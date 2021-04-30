/**
 * @file activity4.c
 * @author Hemanth Naik (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "activity4.h"


/**
 * @brief clock speed
 * 
 */
#define FOSC 16000000

/**
 * @brief baud rate
 * 
 */
#define BAUD 9600

/**
 * @brief MYBURR
 * 
 */
#define MYUBRR FOSC/16/BAUD-1

/**
 * @brief initialising the USART
 * 
 * @param ubrr 
 */
void Init_USART(unsigned int ubrr)
{
    /*Set baud rate */
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;
    /*Enable receiver and transmitter */
    UCSR0B = (1<<RXEN0) | (1<<TXEN0);
    /* Set frame format: 8data, 2stop bit */
    UCSR0C = (1<<USBS0) | (3<<UCSZ00);
}

/**
 * @brief transmitting data through USART
 * 
 * @param data 
 */
void Transmit_USART(unsigned char data)
{
    /* Wait for empty transmit buffer */
    while (!(UCSR0A & (1<<UDRE0)))
    ;
    /* Put data into buffer, sends the data */
    UDR0 = data;
}