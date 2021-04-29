#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"

#define LED_PIN PB0
#define LED_PORT PORTB
#define PWM_GEN_PIN PD6
#define SETD 0b00000011
#define PWM_GEN OCR0A
#define FOSC 16000000 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

void init_peripherial()
{
  DDRD|=(1<<PWM_GEN_PIN);
  PORTD=SETD;
  DDRB|=(1<<LED_PIN);
}

int main(void)
{
  volatile uint8_t check=0;
  uint16_t temp;
  int i=0;
  unsigned char a[]="20";
  unsigned char b[]="25";
  unsigned char c[]="29";
  unsigned char d[]="32";

  init_peripherial();
  initADC();
  set_pwm();
  USART_Init(MYUBRR);
  while(1)
  {
    check=check_seating();
    if(check==1)
    {
      LED_PORT|=(1<<LED_PIN);
      temp=ReadADC(0);  

      if((temp>=0 && temp<=200))
      {
        for(i=0;a[i]!='\0';i++)
        {
          USART_Transmit(a[i]);
        }     
        PWM_GEN=52;
        _delay_ms(2000);
      }

      else if(temp>=210 && temp<=500)
      {
        for(i=0;b[i]!='\0';i++)
        {
          USART_Transmit(b[i]);
        } 
        PWM_GEN=105;
        _delay_ms(2000);
      }

      else if(temp>=510 && temp<=700)
      {
        for(i=0;c[i]!='\0';i++)
        {
          USART_Transmit(c[i]);
        } 
        PWM_GEN=179;
        _delay_ms(2000);  
      }

      else if(temp>=710 && temp<=1024)
      {
        for(i=0;d[i]!='\0';i++)
        {
          USART_Transmit(d[i]);
        } 
        PWM_GEN=243;
        _delay_ms(2000);  
      }
    }
    else
    {
      LED_PORT&=~(1<<LED_PIN);
    }
  }

}