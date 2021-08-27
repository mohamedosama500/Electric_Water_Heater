/*
 * File:   adc.c
 * Author: Hp
 *
 * Created on 04 July 2020, 19:40
 */




#include <xc.h>
#include "adc.h"
#define _XTAL_FREQ 16000000
void ADC_iinit(void){
    ADCON1=0b11000000;
    ADCON0=0b10010001;
}

int ADC_Reead(char Channel){
   // Channel &=0x07;
    //__delay_ms(100);
    ADCON0 |=(1<<1);
    ADCON0 |=(1<<Channel);
    while(GO_DONE==1);
    
    return ((ADRESH<<8) + ADRESL);
    
}
