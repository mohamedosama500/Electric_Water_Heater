///*
// * File:   adjtemp.c
// * Author: Hp
// *
// * Created on 04 July 2020, 21:12
// */
//
//#include "adjtemp.h"
//#include <xc.h>
//#include "XC.h"
//#include"adc.h"
//#include<pic16f877a.h>
//#include <pic.h>
//#include "exe2prom.h"
//#include "Display.h"
//#include "CTR.h"
//#include "HELLED.h"
//#define _XTAL_FREQ 4000000
//#define toggle 1
//#define on 0
//char z = 0;
//char c = 0;
//char h = 0;
//int temp = 0;
//volatile char ReadData;
//char tmp;
//unsigned char x = 0;
//int y = 0;
//char m = 0;
//unsigned int display1 = 0x7D;
//unsigned int display2 = 0x3f;
//extern unsigned char g_Interrupt_Flag;
//char b=0;
//void adj_temp(void) {
//	ReadData = EepromRead(0xA0, 0x12, 0x34);
//
//
//	tmp = ReadData;
////	switch (tmp) {
////	case 40:
////		display1 = 0x66;
////		display2 = 0x3F;
////		break;
////	case 45:
////		display1 = 0x66;
////		display2 = 0x6D;
////		break;
////	case 50:
////		display1 = 0x6D;
////		display2 = 0x3F;
////		break;
////	case 55:
////		display1 = 0x6D;
////		display2 = 0x6D;
////		break;
////	case 60:
////		display1 = 0x7D;
////		display2 = 0x3F;
////		break;
////	case 65:
////		display1 = 0x7D;
////		display2 = 0x6D;
////		break;
////	case 70:
////		display1 = 0x07;
////		display2 = 0x3F;
////		break;
////
////	}
//DISP_Setdisplay1(tmp);
//DISP_Setdisplay2(tmp);
////	PORTD = display1;
////	RA4 = 1;
////	__delay_ms(5);
////	RA4 = 0;
////	PORTD = display2;
////	RA5 = 1;
////	__delay_ms(5);
////	RA5 = 0;
//DISP_Update(1);
//
//	z = 1;
//	c = 1;
//	x = 0;
//	y = 0;
//	while (x != 10 && g_Interrupt_Flag == 1) {
//
//		temp = ADC_Reead(2);
//		temp = ((temp * 5.0) / 10.24);
//		while (m < 10 && g_Interrupt_Flag == 1) {
//             if(RB1==0 ){
//                __delay_ms(70);
//                if(RB1==1 ){
//            
//                CTR_Init();
//               CTR_Update();}}
//            if(RB2==0 ){
//                __delay_ms(70);
//                if(RB2==1 ){
//               CTR_Init();
//               CTR_Update();
//                }}
////			PORTD = display1;
////			RA4 = 1;
////			__delay_ms(5);
////			RA4 = 0;
////			PORTD = display2;
////			RA5 = 1;
////			__delay_ms(5);
////			RA5 = 0;
//             DISP_Update(1);
//			 if(RB1==0 ){
//                __delay_ms(70);
//                if(RB1==1 ){
//            
//                CTR_Init();
//               CTR_Update();}}
//            if(RB2==0 ){
//                __delay_ms(70);
//                if(RB2==1 ){
//               CTR_Init();
//               CTR_Update();
//                }}
//            ReadData = EepromRead(0xA0, 0x12, 0x34);
//
//
//	tmp = ReadData;
//			m++;
//		}
//		m = 0;
//		x = x + 1;
//		y = y + temp;
//		if (x == 10) {
//			y = ((y * 1.0) / 10.0);
//		}
//	}
//    
//    HELED_Update(toggle);
//    ReadData = EepromRead(0xA0, 0x12, 0x34);
//
//
//	tmp = ReadData;
//	if (y < (tmp - 6)) {
//				PORTC |= (1 << 5);
//				PORTC &= (~(1 << 2));
//				
//				PORTC &= (~(1 << 0));
//				 if(RB1==0 ){
//                __delay_ms(70);
//                if(RB1==1 ){
//            
//                CTR_Init();
//               CTR_Update();}}
//            if(RB2==0 ){
//                __delay_ms(70);
//                if(RB2==1 ){
//               CTR_Init();
//               CTR_Update();
//                }}
//                ReadData = EepromRead(0xA0, 0x12, 0x34);
//
//
//	tmp = ReadData;
//			}
//	if (y >= (tmp + 5)) {
//		PORTC |= (1 << 2);
//		PORTC &= (~(1 << 5));
//		HELED_Update(on);
//		PORTC |= (1 << 0);
//		z = 1;
//		c = 1;
//		 if(RB1==0 ){
//                __delay_ms(70);
//                if(RB1==1 ){
//            
//                CTR_Init();
//               CTR_Update();}}
//            if(RB2==0 ){
//                __delay_ms(70);
//                if(RB2==1 ){
//               CTR_Init();
//               CTR_Update();
//                }}
//        ReadData = EepromRead(0xA0, 0x12, 0x34);
//
//
//	tmp = ReadData;
//		while (y >= (tmp - 6) && g_Interrupt_Flag == 1) {
//			 if(RB1==0 ){
//                __delay_ms(70);
//                if(RB1==1 ){
//            
//                CTR_Init();
//               CTR_Update();}}
//            if(RB2==0 ){
//                __delay_ms(70);
//                if(RB2==1 ){
//               CTR_Init();
//               CTR_Update();
//                }}
//             ReadData = EepromRead(0xA0, 0x12, 0x34);
//
//
//	tmp = ReadData;
//    switch (tmp) {
//	case 40:
//		display1 = 0x66;
//		display2 = 0x3F;
//		break;
//	case 45:
//		display1 = 0x66;
//		display2 = 0x6D;
//		break;
//	case 50:
//		display1 = 0x6D;
//		display2 = 0x3F;
//		break;
//	case 55:
//		display1 = 0x6D;
//		display2 = 0x6D;
//		break;
//	case 60:
//		display1 = 0x7D;
//		display2 = 0x3F;
//		break;
//	case 65:
//		display1 = 0x7D;
//		display2 = 0x6D;
//		break;
//	case 70:
//		display1 = 0x07;
//		display2 = 0x3F;
//		break;
//
//	}
//
//			x = 0;
//			y = 0;
//            
//			while (x != 10 && g_Interrupt_Flag == 1) {
//				 if(RB1==0 ){
//                __delay_ms(70);
//                if(RB1==1 ){
//            
//                CTR_Init();
//               CTR_Update();}}
//            if(RB2==0 ){
//                __delay_ms(70);
//                if(RB2==1 ){
//               CTR_Init();
//               CTR_Update();
//                }}
//                 ReadData = EepromRead(0xA0, 0x12, 0x34);
//
//
//	tmp = ReadData;
//				temp = ADC_Reead(2);
//				temp = ((temp * 5.0) / 10.24);
//				while (m < 10 && g_Interrupt_Flag == 1) {
//                     if(RB1==0 ){
//                __delay_ms(70);
//                if(RB1==1 ){
//            
//                CTR_Init();
//               CTR_Update();}}
//            if(RB2==0 ){
//                __delay_ms(70);
//                if(RB2==1 ){
//               CTR_Init();
//               CTR_Update();
//                }}
//                     ReadData = EepromRead(0xA0, 0x12, 0x34);
//
//
//	tmp = ReadData;
//					PORTD = display1;
//					RA4 = 1;
//					__delay_ms(5);
//					RA4 = 0;
//					PORTD = display2;
//					RA5 = 1;
//					__delay_ms(5);
//					RA5 = 0;
//
//					m++;
//				}
//				m = 0;
//				x = x + 1;
//				y = y + temp;
//				if (x == 10) {
//					y = ((y * 1.0) / 10.0);
//				}
//			}
//            ReadData = EepromRead(0xA0, 0x12, 0x34);
//
//
//	tmp = ReadData;
//
//			if (y >= (tmp + 5) || y >= (tmp - 6)) {
//				PORTC |= (1 << 2);
//				PORTC &= (~(1 << 5));
//			}
//			PORTC |= (1 << 0);
//			HELED_Update(on);
//
//		}
//
//	}
//}
