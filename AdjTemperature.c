/*
 * File:   AdjTemperature.c
 * Author: Hp
 *
 * Created on 11 July 2020, 02:36
 */



#include <xc.h>
#include "XC.h"
#include"adc.h"
#include<pic16f877a.h>
#include <pic.h>
#include "exe2prom.h"
#include "Display.h"
#include "CTR.h"
#include "HELLED.h"
#include "AdjTemperature.h"
#include "SW.h"
#define _XTAL_FREQ 16000000
#define toggle 1
#define on 0
char z = 0;
char c = 0;
char h = 0;
int temp = 0;
volatile char ReadData;
char tmp;
unsigned char x = 0;
int y = 0;
char m = 0;
unsigned int display1 = 0x7D;
unsigned int display2 = 0x3f;
extern unsigned char g_Interrupt_Flag;
char b=0;
/*Temp_Init function to initialize the temp. value to 60 celsius */
void Temp_Init(void) {
     ReadData = EepromRead(0xA0, 0x12, 0x34);
	tmp = ReadData;
    if(tmp!=35 ||tmp!=40 ||tmp!=45 ||tmp!=50 ||tmp!=55 ||tmp!=65 ||tmp!=70 ||tmp!=75){
        tmp=60;
    }
   
}
/*Temp_Reading function to read temp. from Eeprom */
void Temp_Reading(void){
    ReadData = EepromRead(0xA0, 0x12, 0x34);
	tmp = ReadData;
    DISP_Setdisplay1(tmp);
    DISP_Setdisplay2(tmp);
    DISP_Update(1);
}
/*temp_Update function to read the temp. from temp. sensor that is connected to ADC*/
void temp_Update(void){
    
    z = 1;
	c = 1;
	x = 0;
	y = 0;
    /*g_Interrupt_Flag is flag used when button is pressed causing interrupt 
      and checking the value of x is 10 as we want to read every 10 readings
      of ADC from temp.sensor */
	while (x != 10 && g_Interrupt_Flag == 1) {

		temp = ADC_Reead(2);
        /*equation to change reading of ADC to celsius */
		temp = ((temp * 5.0) / 10.24);
		while (m < 10 && g_Interrupt_Flag == 1) {
             SW_GetState();
             
             Temp_Reading();
             
             m++;
		}
		m = 0;
		x = x + 1;
		y = y + temp;
		if (x == 10) {
			y = ((y * 1.0) / 10.0);
		}
        
	}
    HELED_Update(toggle);
     Temp_Reading();
     
     if (y < (tmp - 6)) {
				PORTC |= (1 << 5);
				PORTC &= (~(1 << 2));
				
				PORTC &= (~(1 << 0));
				 SW_GetState();
                Temp_Reading();
     }
 
     ////////////////////////////////
     
     if (y >= (tmp + 5)) {
		PORTC |= (1 << 2);
		PORTC &= (~(1 << 5));
		HELED_Update(on);
		PORTC |= (1 << 0);
		z = 1;
		c = 1;
		 SW_GetState();
         Temp_Reading();
         
         while (y >= (tmp - 6) && g_Interrupt_Flag == 1) {
			 SW_GetState();
             
             Temp_Reading();
             
             
             x = 0;
			y = 0;
            
			while (x != 10 && g_Interrupt_Flag == 1) {
				 SW_GetState();
                 
                 
                  Temp_Reading();
                 
                 temp = ADC_Reead(2);
				temp = ((temp * 5.0) / 10.24);
				while (m < 10 && g_Interrupt_Flag == 1) {
                     SW_GetState();
                     
                     
             Temp_Reading();
             
             
             m++;
				}
				m = 0;
				x = x + 1;
				y = y + temp;
				if (x == 10) {
					y = ((y * 1.0) / 10.0);
				}
			}
            
              Temp_Reading();
              
              if (y >= (tmp + 5) || y >= (tmp - 6)) {
				PORTC |= (1 << 2);
				PORTC &= (~(1 << 5));
			}
			PORTC |= (1 << 0);
			HELED_Update(on);

		}

	}
}