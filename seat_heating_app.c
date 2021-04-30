/**
 * @file seat_heating_app.c
 * @author Hemanth Naik (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"

/**
 * @brief Initialising pin PB0 as LED pin
 * 
 */
#define LED_PIN PB0

/**
 * @brief Initialising PORTB as LED port
 * 
 */
#define LED_PORT PORTB

/**
 * @brief Initialising pin PD6 as PWM generating pin
 * 
 */
#define PWM_GEN_PIN PD6

/**
 * @brief setting D bit
 * 
 */
#define SETD 0b00000011
// OCR1A (16-bit register contains the converted value

/**
 * @brief OCR1A (16-bit register contains the converted value
 */
#define PWM_GEN OCR0A

/**
 * @brief Clock Speed
 * 
 */
#define FOSC 16000000

/**
 * @brief Baud rate
 * 
 */
#define BAUD 9600

/**
 * @brief MYBURR
 * 
 */
#define MYUBRR FOSC/16/BAUD-1

/**
 * @brief initialising values
 * 
 */
void init_peripherial()
{
  // Direction of ports
  DDRD |= (1 << PWM_GEN_PIN);
  DDRB |= (1 << LED_PIN);
  // PULL-UP +5V for push-buttons
  PORTD = SETD;
}


int main(void)
{
  // temp contains the temperature value that ADC renders
  uint16_t volatile temp;
  int index = 0;
/**
 * @brief different temperature string initialisation
 * 
 */
unsigned char range1[] = "20";
unsigned char range2[] = "25";
unsigned char range3[] = "29";
unsigned char range4[] = "32";
/**
 * @brief call functionthat configures peripheral
 * 
 */
init_peripherial();
/**
 * @brief calling adc function which is initialised
 *  
 */
init_ADC();
/**
 * @brief Set the pulse width modultion registers
 * 
 */
init_PWM();
/**
 * @brief initialising uart communication
 * 
 */
Init_USART(MYUBRR);
  while(1)
  {
    /**
     * @brief Reading thetemperature value
     * 
     */
    volatile uint8_t check = 0;
    check = check_seat_status();
    if(check)
    {
      /**
     * @brief reading the temperature value
     * 
     */
      LED_PORT |= (1<<LED_PIN);
      temp = read_ADC(0);  

      if((temp >= 0 && temp <= 200))
      {
        /**
         * @brief transmitting the temperature values
         * 
         */
        for(index = 0; range1[index]!='\0' ;index++)
        {
          Transmit_USART(range1[index]);
        }     
        PWM_GEN = 52;
        _delay_ms(2000);
      }

      else if(temp >= 210 && temp <= 500)
      {
        for(index = 0 ; range2[index]!='\0' ; index++)
        {
          Transmit_USART(range2[index]);
        } 
        PWM_GEN = 105;
        _delay_ms(2000);
      }

      else if(temp >= 510 && temp <= 700)
      {
        for(index = 0 ; range3[index]!='\0' ; index++)
        {
          Transmit_USART(range3[index]);
        } 
        PWM_GEN = 179;
        _delay_ms(2000);  
      }

      else if(temp >= 710 && temp <= 1024)
      {
        for(index = 0 ; range4[index]!='\0' ; index++)
        {
          Transmit_USART(range4[index]);
        } 
        PWM_GEN = 243;
        _delay_ms(2000);  
      }
    }
    /**
 * @brief if driver is not seated
 * 
 */

    else
    {
      LED_PORT &=~ ( 1<< LED_PIN);
    }
  }

}