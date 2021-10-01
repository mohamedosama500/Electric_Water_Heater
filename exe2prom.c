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
            SSPCON2bits.SEN=1;//initiate start condition
            while(SEN);//wait for start condition to complete
            PIR1bits.SSPIF=0;//clear SSP interrupt flag
            SSPBUF=Slaveadd;//send the slave address and R/W bit
            while(!SSPIF);//wait for acknowledge.SSPIF bit is set every 9th clock cycle
            PIR1bits.SSPIF=0;//clear SSP interrupt flag
            
            if(SSPCON2bits.ACKSTAT){
                SSPCON2bits.PEN=1;//initiate stop condition 
                while(PEN);//wait for start condition to complete
                return;//exit write (no acknowledge)
            }
            SSPBUF = AddHigh;//send EEPROM Adress high
            while(!SSPIF);//wait for acknowledge.SSPIF bit is set every 9th clock cycle
            PIR1bits.SSPIF=0;//clear SSP interrupt flag
            if(SSPCON2bits.ACKSTAT){
                SSPCON2bits.PEN=1;//initiate stop condition 
                while(PEN);//wait for start condition to complete
                return;//exit write (no acknowledge)
            }
            SSPBUF = AddLow;//send EEPROM Adress low
            while(!SSPIF);//wait for acknowledge.SSPIF bit is set every 9th clock cycle
            PIR1bits.SSPIF=0;//clear SSP interrupt flag
            if(SSPCON2bits.ACKSTAT){
                SSPCON2bits.PEN=1;//initiate stop condition 
                while(PEN);//wait for start condition to complete
                return;//exit write (no acknowledge)
            }
            SSPBUF = EeData;//send the data byte
            while(!SSPIF);//wait for acknowledge.SSPIF bit is set every 9th clock cycle
            PIR1bits.SSPIF=0;//clear SSP interrupt flag
            
             SSPCON2bits.PEN=1;//initiate stop condition (Ack or Nack)
             while(PEN);//wait for start condition to complete
                
            
            
        }
        
        
    char EepromRead(char Slaveadd ,char AddHigh,char AddLow){
        char TempData;//Temporary holder for data byte
        
        
        SSPCON2bits.SEN=1;//initiate start condition
            while(SEN);//wait for start condition to complete
            PIR1bits.SSPIF=0;//clear SSP interrupt flag
            SSPBUF=Slaveadd;//send the slave address and R/W bit
             while(!SSPIF);//wait for acknowledge.SSPIF bit is set every 9th clock cycle
             PIR1bits.SSPIF=0;//clear SSP interrupt flag
            if(SSPCON2bits.ACKSTAT){
                SSPCON2bits.PEN=1;//initiate stop condition
                while(PEN);//wait for start condition to complete
                return(0xFF);//Exit read (no acknowledge)
            }
            SSPBUF = AddHigh;//send EEPROM address high
            while(!SSPIF);//wait for acknowledge.SSPIF bit is set every 9th clock cycle
            PIR1bits.SSPIF=0;//clear SSP interrupt flag
            if(SSPCON2bits.ACKSTAT){
                SSPCON2bits.PEN=1;//initiate stop condition
                while(PEN);//wait for start condition to complete
                return(0xFF);//Exit read (no acknowledge)
            }
            
            SSPBUF = AddLow;//send EEPROM address low
            while(!SSPIF);//wait for acknowledge.SSPIF bit is set every 9th clock cycle
            PIR1bits.SSPIF=0;//clear SSP interrupt flag
            if(SSPCON2bits.ACKSTAT){
                SSPCON2bits.PEN=1;//initiate stop condition
                while(PEN);//wait for start condition to complete
                return(0xFF);//Exit read (no acknowledge)
            }
            
            SSPCON2bits.RSEN=1;//initiate restart condition
            while(RSEN);//wait for restart condition to start
            PIR1bits.SSPIF=0;//clear SSP interrupt flag
            SSPBUF=(Slaveadd+1);//send the slave address and R/W bit
            while(!SSPIF);//wait for acknowledge.SSPIF bit is set every 9th clock cycle
            PIR1bits.SSPIF=0;//clear SSP interrupt flag
            if(SSPCON2bits.ACKSTAT){
                SSPCON2bits.PEN=1;//initiate stop condition
                while(PEN);//wait for start condition to complete
                return(0xFF);//Exit read (no acknowledge)
            }
            
            SSPCON2bits.RCEN=1;//recieve data byte from slave
            while(!SSPSTATbits.BF);//wait for the recieve to complete
            TempData=SSPBUF;//save the data byte
            
            SSPCON2bits.ACKDT=1;//prepare to send NACK
            SSPCON2bits.ACKEN=1;//initiate NACK to the EEPROM
            while(ACKEN);//wait for the NACK to complete
            SSPCON2bits.PEN;//initiate stop condition
            while(PEN);//wait for start condition to complete
            return TempData;//return the data byte value
    }
