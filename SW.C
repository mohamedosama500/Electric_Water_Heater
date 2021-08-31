
/*
 * File:   SW.c
 * Author: Hp
 *
 * Created on 09 July 2020, 05:29
 */


#include <xc.h>
#include "SW.h"
#include "CTR.h"
#include "exe2prom.h"
#include "Display.h"
#define increase 1
#define decrease 0
#define _XTAL_FREQ 16000000
volatile char ReadData;
char h = 0;
	char k = 0;
	char u = 0;
	char o =0;
    char tmp;
    unsigned char x = 0;
    /*SW_Init function to initialize the value of two pins used in increment and decrement temprature*/
void SW_Init(void){
    TRISB |=(1<<1);
    TRISB |=(1<<2);
    PORTB=0x00;
}





 void SW_Update(void){

     ReadData = EepromRead(0xA0, 0x12, 0x34);
    tmp = ReadData;
    char h = 0;/**/
	char u = 0;
	char o = 0;/*flag used to blink the seven segment 5 times when its in update mode */
	char tmp;
	unsigned char x = 0;
    tmp = ReadData;
while (o < 5) {
    
     /*in case of checking the switch update when display of seven segment is on we will make counter h to count 50
         times as function DISP_Update take 10 ms delay so total is 500 ms which is half second when 7 segment is  on */
		while (h < 50) {
			DISP_Update(1);
            /*either of two switches is pressed again*/
			
                /*after the switch of decreases or increases the temp. is pressed again we wait when its not pressed then
                 update temp. and make it to toggle the led 4 times by setting the while(o<4)*/
				if (RB2 == 1 || RB1 == 1) {
                    while (o < 4) {
				while (h < 100) {
					DISP_Update(1);

					if (RB1 == 0) {
						__delay_ms(70);/* to avoid switch bouncing*/
						
                            
							CTR_Update(decrease);
                             
						
					}

					if (RB2 == 0) {
						__delay_ms(70);
						
                           
							CTR_Update(increase);
                            
						
					}
					h++;
				}
				h = 0;
				while (u < 100) {
					DISP_Update(0);

					if (RB1 == 0) {
						__delay_ms(70);
						
							CTR_Update(decrease);
                             
						
					}

					if (RB2 == 0) {
						__delay_ms(70);
						
							CTR_Update(increase);
                             
						
					}
					u++;
				}
				u = 0;
				o++;
				//EepromWrite(0xA0, 0x12, 0x34, tmp);
				for (x = 1; x < 165; x++);
				ReadData = EepromRead(0xA0, 0x12, 0x34);

			}
                    
			o = 8;/*to exit from the loop */

				}
			
			h++;
		}

		h = 0;
        
        /*in case of checking the switch update when display of seven segment is off we will make counter u to count 50
         times as function DISP_Update take 10 ms delay so total is 500 ms which is half second when 7 segment is  off */
		while (u < 50) {
			DISP_Update(0);
			
				if (RB2 == 1 || RB1 == 1) {
                    while (o < 4) {
				while (h < 100) {
					DISP_Update(1);

					if (RB1 == 0) {
						__delay_ms(70);
						

							CTR_Update(decrease);
						
					}

					if (RB2 == 0) {
						__delay_ms(70);
						

							CTR_Update(increase);
						
					}
					h++;
				}
				h = 0;
				while (u < 100) {
					DISP_Update(0);

					if (RB1 == 0) {
						__delay_ms(70);
						

							CTR_Update(decrease);
						
					}

					if (RB2 == 0) {
						__delay_ms(70);
						

							CTR_Update(increase);
						
					}
					u++;
				}
				u = 0;
				o++;
				//EepromWrite(0xA0, 0x12, 0x34, tmp);
				for (x = 1; x < 165; x++)
					;
				ReadData = EepromRead(0xA0, 0x12, 0x34);

			}
			o = 8;

				}
			
			u++;
		}
		o++;
		u = 0;


		
	}
    o=8;
 }

 
 
 void SW_GetState(void) {
    
    if (RB2 == 0 ||RB1==0 ) {
		__delay_ms(140);
    if(RB1==1 ||RB2==1){
            
                CTR_Init();
              SW_Update();}}
    
    
}
