/*
* lab4.c  -- When no switches are pressed the LED is off
          -- When switch 1 is pressed and switch 2 is not, the LED has dim brightness
          -- When switch 1 is not pressed and switch 2 is, the LED has medium brightness
          -- When both switch 1 and 2 are pressed the LED has full brightness
* Date          Author              Revision
*4/21/22         Jordan Andrade      initial code creation
*/

#include "avr/io.h"
#include "util/delay.h"

int main(void){

    DDRB = 0x00;   // make PORTB inputs 
    PORTB = (1<<PB1)|(1<<PB2);   // set internal pullups on PB1 & PB2
    DDRD = 1<<DDD6;   // set PD6 as output

    TCCR0A = 0x81;   // mode FASTPWM
    TCCR0B = 0x03;   // prescaler 1:64

   while(1){

        if (((PINB & (1<<PINB1)) == 0) & ((PINB & (1<<PINB2)) == 0)){   // when switch 1 and 2 are pressed 
            OCR0A = 255;   // 100% of 255
        }

        else if ((PINB & (1<<PINB1)) == 0){  // when switch 1 is pressed 
            OCR0A = 32;   // ~13% of 255
        }

        else if ((PINB & (1<<PINB2)) == 0){  // when switch 2 is pressed 
            OCR0A = 128;   // 50% of 255
        }

        else{   // when neither switch is pressed 
            OCR0A = 0;   // 0% of 255
        }
    }
}