#include"activity1.h"

uint8_t check_seating()
{
  if((!(PIND&(1<<PD0))) && (!(PIND&(1<<PD1))))
  {
    return 1;
  }
  return 0;
}
