/*
 * File:   SSD.c
 * Author: Hp
 *
 * Created on 09 July 2020, 05:30
 */


#include <xc.h>
#include "SSD.h"
#include "exe2prom.h"
#define _XTAL_FREQ 16000000

void SSD_Init(void){

TRISD=0x00;//set all pins of seven segment to be as output pins
PORTD=0x00;//initialize their value
}

/*SSD_Setsympol function to set the symbol (each number) of seven segment using port d in pic*/
    unsigned char SSD_SetSymbol( char Number){
        
        RA4=0;/*initialize the pins responsible to launch the two seven segments in the picsimlab*/
        RA5=0;
			
            switch(Number){
                case 0:
                    PORTD=0x3F;
                    break;
                    case 1:
                    PORTD=0x06;
                    break;
                    case 2:
                    PORTD=0x5B;
                    break;
                    case 3:
                    PORTD=0x4F;
                    break;
                    case 4:
                    PORTD=0x66;
                    break;
                    case 5:
                    PORTD=0x6D;
                    break;
                    case 6:
                    PORTD=0x7D;
                    break;
                    case 7:
                    PORTD=0x07;
                    break;
                    case 8:
                    PORTD=0x7F;
                    break;
                    case 9:
                    PORTD=0x6F;
                    break;
            }
            return PORTD;
    }
    
   void SSD_Off(void){
        PORTA &=(~(1<<5));
        PORTA &=(~(1<<4));
    }
    
    


