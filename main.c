#include <msp430.h>

#define IRLED1 BIT3
#define Switch1 BIT2



int count =0;
int bit =0;
int i =0;
int ii =0;
int iii=0;
int bitt =0;


unsigned long irdata=0;


void tx_send(long irdata);


int main(void)
{

WDTCTL = WDTPW + WDTHOLD;                            // Stop watchdog timer

P2DIR |= (IRLED1);
P2OUT &= ~IRLED1;
P1REN |= Switch1;
P1OUT |= Switch1;

__enable_interrupt(); // enable all interrupts
while(1)
{

if((P1IN & Switch1) != Switch1)
    {

    if(count >1000)
    {
       // tx_send(0x1CE348B7);//tv power
        tx_send(0x1CE3708F);//tv volume up
    }
    count =0;
    }
else
{
    count++;
}
if(count > 2000)
{
    count =2000;
}
_delay_cycles(100);
}
}


void tx_send(long irrealdata)
{


  __disable_interrupt(); // enable all interrupts
//  irdata = irrealdata;

for(iii=32;iii>0;iii--)
{
    bitt = irrealdata & 1;
    irdata |= bitt;
    irrealdata>>=1;
    irdata<<=1;
}

  for (i = 333;i>0;i--)
  {
    P2OUT |= IRLED1;
    __delay_cycles(4);
    P2OUT &= ~IRLED1;
    __delay_cycles(4);

  }

    __delay_cycles(3830);


  for(ii = 32; ii>0;ii--)
  {
    bit = irdata & 1;
    if(bit == 0)
    {
        __delay_cycles(500);
      for (i = 21;i>0;i--)
      {
        P2OUT |= IRLED1;
        __delay_cycles(4);
        P2OUT &= ~IRLED1;
        __delay_cycles(4);

      }



    }
    else
    {

        __delay_cycles(1590);

      for (i = 21;i>0;i--)
      {
        P2OUT |= IRLED1;
        __delay_cycles(4);
        P2OUT &= ~IRLED1;
        __delay_cycles(4);


      }



    }
    irdata >>= 1;
  }

  for (i = 5;i>0;i--)
  {
    P2OUT |= IRLED1;
    __delay_cycles(4);
    P2OUT &= ~IRLED1;
    __delay_cycles(4);


  }


    __delay_cycles(1590);

    for (i = 20;i>0;i--)
    {
      P2OUT |= IRLED1;
      __delay_cycles(4);
      P2OUT &= ~IRLED1;
      __delay_cycles(4);

    }

    __delay_cycles(38900);

    for (i = 333;i>0;i--)
    {
      P2OUT |= IRLED1;
      __delay_cycles(4);
      P2OUT &= ~IRLED1;
      __delay_cycles(4);

    }

      __delay_cycles(2130);

    for (i = 21;i>0;i--)
    {
      P2OUT |= IRLED1;
      __delay_cycles(4);
      P2OUT &= ~IRLED1;
      __delay_cycles(4);

    }

  __enable_interrupt(); // enable all interrupts
}

