/*
 * File:   Display.c
 * Author: Hp
 *
 * Created on 10 July 2020, 04:17
 */


#include <xc.h>
#include "Display.h"
#include "SSD.h"
#include "exe2prom.h"
#include "AdjTemperature.h"

#define _XTAL_FREQ 16000000

/*DISP_Setdisplay1 function to display the first number from left of the temp. in the seven segment */
unsigned char DISP_Setdisplay1(char Temprature) {
    unsigned char display1=0;
    
    switch (Temprature) {
            case 75:
                    
              display1=SSD_SetSymbol(7);
                
               // __delay_ms(100);
                    break;
			case 65:
				display1=SSD_SetSymbol( 6);
                
				//__delay_ms(100);
				break;
			case 70:
				display1=SSD_SetSymbol( 7);
                
				//__delay_ms(100);
				break;
			case 60:
				display1=SSD_SetSymbol( 6);
                
				//__delay_ms(100);
				break;
			case 55:
				display1=SSD_SetSymbol( 5);
                
				//__delay_ms(100);
				break;
			case 50:
				display1=SSD_SetSymbol( 5);
               
				//__delay_ms(100);
				break;
			case 45:
				display1=SSD_SetSymbol( 4);
                
				//__delay_ms(100);
				break;
			case 40:
				display1=SSD_SetSymbol( 4);
               
				//__delay_ms(100);
				break;
                case 35:
				display1=SSD_SetSymbol( 3);
               
				//__delay_ms(100);
				break;
			}
    return display1;
}
/*DISP_Setdisplay2 function to display the second number from left of the temp. in the seven segment */
unsigned char DISP_Setdisplay2(char Temprature) {
    unsigned char display2=0;
     switch (Temprature) {
            case 75:
                    
              
               display2= SSD_SetSymbol(5);
                //__delay_ms(100);
                    break;
			case 65:
				
                display2=SSD_SetSymbol(5);
				//__delay_ms(100);
				break;
			case 70:
				
                display2=SSD_SetSymbol(0);
				//__delay_ms(100);
				break;
			case 60:
				
                display2=SSD_SetSymbol(0);
				//__delay_ms(100);
				break;
			case 55:
				
                display2=SSD_SetSymbol( 5);
				//__delay_ms(100);
				break;
			case 50:
				
                display2=SSD_SetSymbol( 0);
				//__delay_ms(100);
				break;
			case 45:
				
                display2=SSD_SetSymbol( 5);
				//__delay_ms(100);
				break;
			case 40:
				
                display2=SSD_SetSymbol( 0);
				//__delay_ms(100);
				break;
                case 35:
				
                display2=SSD_SetSymbol( 5);
				//__delay_ms(100);
				break;
			}
     return display2;
}


volatile char ReadData;
void DISP_Update(char state){
    
    char tmp;
	unsigned char x = 0;
          //  for (x = 1; x < 165; x++);
    /*there is two states to make display off or on in the seven segments*/
            ReadData= EepromRead(0xA0, 0x12, 0x34);//Reading the current temp. in the Eeprom
            tmp=ReadData;
            /*displaying the first number of the pin RA4 in seven segment and second one in the RA5
             we must make small delay between off and on to make numbers appear continuous in 
             the seven segment , we made pins (RA4,RA5) on and off in the state==1 to update seven segment eachtime
             numbers were changed*/
            if(state==1){ 
                PORTD = DISP_Setdisplay1(tmp);
					RA4 = 1;
					__delay_ms(5);
					RA4 = 0;
					PORTD = DISP_Setdisplay2(tmp);
					RA5 = 1;
					__delay_ms(5);
					RA5 = 0;}
            if(state==0){
                PORTD = DISP_Setdisplay1(tmp);
					RA4 = 0;
					__delay_ms(5);
					RA4 = 0;
					PORTD = DISP_Setdisplay2(tmp);
					RA5 = 0;
					__delay_ms(5);
					RA5 = 0;}
}