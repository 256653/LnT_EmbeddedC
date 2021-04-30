/**
 * @file activity3.c
 * @author Hemanth Naik (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include"activity3.h"

/**
 * @brief Set the pwm object
 * initalising the pwm value
 * 
 */
void init_PWM()
{
    // using 16-bit timer and counter1
    TCCR0A |=(1<<COM0A1)|(1<<WGM01)|(1<<WGM00);
    //64 Prescaler for appropriate resolution
    TCCR0B|=(1<<CS00)|(1<<CS01);
}