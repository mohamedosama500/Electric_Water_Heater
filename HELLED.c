/*
 * File:   HELED.c
 * Author: Hp
 *
 * Created on 09 July 2020, 05:31
 */


#include <xc.h>
#include "HELLED.h"
#define _XTAL_FREQ 16000000
char b=0;
void HELLED_Init(void){
    TRISB &=(~(1<<6));//set bit6 as output for the led we will use in toggling
    PORTB=0x00;//initialize the value of the led
    
}
void HELED_Update(char status) {
    /*this status where the heater is on, we want to toggle the led by using 
     counter b after its value become (2) it will make led off then on again when
     its value become (0)*/
    if(status==1){
    if(b==0){
        PORTB |= (1 << 6);
        
    }
    b++;
    if(b==2){
        PORTB &= (~(1 << 6));
        
        b=0;
    }
    }
    /*this status where cooler is on, we want the led to be always on */
    if(status==0){
         PORTB |= (1 << 6);
    }
}
