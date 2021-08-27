/*
 * File:   DISP.c
 * Author: Hp
 *
 * Created on 04 July 2020, 19:37
 */

#include <xc.h>
#include "XC.h"
#include<pic16f877a.h>
#include <pic.h>
#include "DISP.h"
#include"exe2prom.h"
#include "adjtemp.h"
#include "Display.h"
#include "SSD.h"

#define _XTAL_FREQ 4000000

unsigned int display1 = 0x7D;

unsigned int display2 = 0x3F;

volatile char ReadData;
void DISP(void) {

	char h = 0;
	char k = 0;
	int u = 0;
	int o = 0;
	char p = 0;
	char tmp;
	unsigned char x = 0;
	for (x = 1; x < 165; x++)
		;
	ReadData = EepromRead(0xA0, 0x12, 0x34);
	tmp = ReadData;
	__delay_ms(100);
	while (o < 3) {
		while (h < 50) {
			DISP_Update(1);
			if (RB2 == 0 || RB1 == 0) {
				__delay_ms(30);
				if (RB2 == 0 || RB1 == 0) {
					h = 100;
					u = 100;
					o = 7;
					k = 1;
				}
			}
			h++;
		}

		h = 0;
		while (u < 50) {
			DISP_Update(0);
			if (RB2 == 0 || RB1 == 0) {
				__delay_ms(30);
				if (RB2 == 0 || RB1 == 0) {
					h = 100;
					u = 100;
					o = 7;
					k = 1;
				}
			}
			u++;
		}
		o++;
		u = 0;

		if (o > 5) {
			o = 0;
			h = 0;
			u = 0;
		}

		if (k == 1) {
			k = 0;
			while (o < 4) {
				while (h < 100) {
					DISP_Update(1);

					if (RB1 == 0) {
						__delay_ms(70);
						if (RB1 == 1) {

							tmp = tmp - 5;
							if (tmp < 40 || tmp > 70) {
								tmp = 60;
							}
							EepromWrite(0xA0, 0x12, 0x34, tmp);
							for (x = 1; x < 165; x++)
								;
							ReadData = EepromRead(0xA0, 0x12, 0x34);
							tmp = ReadData;
						}
					}

					if (RB2 == 0) {
						__delay_ms(70);
						if (RB2 == 1) {

							tmp = tmp + 5;
							if (tmp < 40 || tmp > 70) {
								tmp = 60;
							}
							EepromWrite(0xA0, 0x12, 0x34, tmp);
							for (x = 1; x < 165; x++)
								;
							ReadData = EepromRead(0xA0, 0x12, 0x34);
							tmp = ReadData;
						}
					}
					h++;
				}
				h = 0;
				while (u < 100) {
					DISP_Update(0);

					if (RB1 == 0) {
						__delay_ms(70);
						if (RB1 == 1) {

							tmp = tmp - 5;
							if (tmp < 40 || tmp > 70) {
								tmp = 60;
							}
							EepromWrite(0xA0, 0x12, 0x34, tmp);
							for (x = 1; x < 165; x++)
								;
							ReadData = EepromRead(0xA0, 0x12, 0x34);
							tmp = ReadData;
						}
					}

					if (RB2 == 0) {
						__delay_ms(70);
						if (RB2 == 1) {

							tmp = tmp + 5;
							if (tmp < 40 || tmp > 70) {
								tmp = 60;
							}							
							EepromWrite(0xA0, 0x12, 0x34, tmp);
							for (x = 1; x < 165; x++)
								;
							ReadData = EepromRead(0xA0, 0x12, 0x34);
							tmp = ReadData;
						}
					}
					u++;
				}
				u = 0;
				o++;
				EepromWrite(0xA0, 0x12, 0x34, tmp);
				for (x = 1; x < 165; x++)
					;
				ReadData = EepromRead(0xA0, 0x12, 0x34);

			}
			o = 8;

		}
	}

}
