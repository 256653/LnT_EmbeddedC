#include"activity1.h"
#include"activity2.h"
#include"activity3.h"


#define SETD 0b00000011


int main(void)
{
  volatile uint8_t check=0;
  uint16_t temp;
  DDRD|=(1<<PD6);
  PORTD=SETD;
  DDRB|=(1<<PB0);
  initADC();
  set_pwm();
  while(1)
  {

    check=check_seating();
    if(check==1)
    {
      PORTB|=(1<<PB0);
    }
    else
    {
      PORTB&=~(1<<PB0);
    }
    temp=ReadADC(0);
      
      if((temp>=0 && temp<=200))
      { 
         OCR0A=52;
        _delay_ms(2000);
      }
      else if(temp>=210 && temp<=500)
      {  
        OCR0A=105;
        _delay_ms(2000);
      }
      else if(temp>=510 && temp<=700)
      {
        OCR0A=179;
        _delay_ms(2000);  
      }
      else{
          OCR0A=243;
        _delay_ms(2000);  
      }

}

}
