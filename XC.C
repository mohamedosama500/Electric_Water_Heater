/*
 * File:   XC.c
 * Author: Hp
 *
 * Created on 04 July 2020, 19:43
 */
#include <xc.h>
#include "XC.h"
#include"adc.h"
#include<pic16f877a.h>
#include <pic.h>
#include "AdjTemperature.h"
#include"exe2prom.h"
#include "CTR.h"
#include "SW.h"
#include "HELLED.h"
#include "SSD.h"
#define _XTAL_FREQ 16000000
unsigned char g_Interrupt_Flag = 0;
char z = 0;
char c = 0;
char h = 0;
//char n=0;
//char r=0;
void __interrupt()my_isr_routine (void) {
	if(c==0) {
		g_Interrupt_Flag=1;
		z=0;
	}

	if(z==1) {
		g_Interrupt_Flag=0;
		c=0;
	}

	INTF=0;
}
//extern void DISP(void);

char tmp;
volatile char ReadData;
int main(void) {
	 
	OPTION_REG = 0x00;
	INTCON = 0xd0;
	TRISA = 0b11001111;
	TRISC = 0x18;
	TRISB = 0x00;
	TRISB |= (1 << 0);
	TRISB |= (1 << 1);
	TRISB |= (1 << 2);
	TRISB |= (1 << 3);
    TRISB |= (1 << 4);
	TRISB &= (~(1 << 6));
	TRISD = 0x00;
	PORTB = 0x00;
   ADC_iinit();
   unsigned char x=0;
  
    SSPADD =4;
    SSPCON=0x28;
    
           
           //ReadData=EepromRead(0xA0,0x12,0x34);
	while (1) {
        if(g_Interrupt_Flag == 1) {
          //  SSD_Init();
          //  SW_Init();
          //  HELLED_Init();
           temp_Update();
			
        }
            
        else{
			//temp_Update();
           c=0;
            z=0;
            PORTC &= (~(1 << 5));
			PORTC &= (~(1 << 2));
            PORTC &=(~(1 << 0));
			
			//SW_GetState();
            
                SSD_Off();
            }
		}

		return 0;
	}

	


