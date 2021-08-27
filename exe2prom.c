/*
 * File:   exe2prom.c
 * Author: Hp
 *
 * Created on 04 July 2020, 22:18
 */


#include <xc.h>
#include "exe2prom.h"
#include<pic16f877a.h>
#include <pic.h>
#define _XTAL_FREQ 16000000
 void EepromWrite(char Slaveadd ,char AddHigh,char AddLow,char EeData){
            SSPCON2bits.SEN=1;
            while(SEN);
            PIR1bits.SSPIF=0;
            SSPBUF=Slaveadd;
            while(!SSPIF);
            PIR1bits.SSPIF=0;
            
            if(SSPCON2bits.ACKSTAT){
                SSPCON2bits.PEN=1;
                while(PEN);
                return;
            }
            SSPBUF = AddHigh;
            while(!SSPIF);
            PIR1bits.SSPIF=0;
            if(SSPCON2bits.ACKSTAT){
                SSPCON2bits.PEN=1;
                while(PEN);
                return;
            }
            SSPBUF = AddLow;
            while(!SSPIF);
            PIR1bits.SSPIF=0;
            if(SSPCON2bits.ACKSTAT){
                SSPCON2bits.PEN=1;
                while(PEN);
                return;
            }
            SSPBUF = EeData;
            while(!SSPIF);
            PIR1bits.SSPIF=0;
            
             SSPCON2bits.PEN=1;
             while(PEN);
                
            
            
        }
        
        
    char EepromRead(char Slaveadd ,char AddHigh,char AddLow){
        char TempData;
        
        
        SSPCON2bits.SEN=1;
            while(SEN);
            PIR1bits.SSPIF=0;
            SSPBUF=Slaveadd;
             while(!SSPIF);
             PIR1bits.SSPIF=0;
            if(SSPCON2bits.ACKSTAT){
                SSPCON2bits.PEN=1;
                while(PEN);
                return(0xFF);
            }
            SSPBUF = AddHigh;
            while(!SSPIF);
            PIR1bits.SSPIF=0;
            if(SSPCON2bits.ACKSTAT){
                SSPCON2bits.PEN=1;
                while(PEN);
                return(0xFF);
            }
            
            SSPBUF = AddLow;
            while(!SSPIF);
            PIR1bits.SSPIF=0;
            if(SSPCON2bits.ACKSTAT){
                SSPCON2bits.PEN=1;
                while(PEN);
                return(0xFF);
            }
            
            SSPCON2bits.RSEN=1;
            while(RSEN);
            PIR1bits.SSPIF=0;
            SSPBUF=(Slaveadd+1);
            while(!SSPIF);
            PIR1bits.SSPIF=0;
            if(SSPCON2bits.ACKSTAT){
                SSPCON2bits.PEN=1;
                while(PEN);
                return(0xFF);
            }
            
            SSPCON2bits.RCEN=1;
            while(!SSPSTATbits.BF);
            TempData=SSPBUF;
            
            SSPCON2bits.ACKDT=1;
            SSPCON2bits.ACKEN=1;
            while(ACKEN);
            SSPCON2bits.PEN;
            while(PEN);
            return TempData;
    }
