#include"activity3.h"

void set_pwm()
{
    TCCR0A |=(1<<COM0A1)|(1<<WGM01)|(1<<WGM00);
    TCCR0B|=(1<<CS00)|(1<<CS01);
}