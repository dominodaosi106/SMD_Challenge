/*
 *SMD Challenge Badge ATtiny13A 32mm 
 *製作 dominoTECH EqUret
 *製作年 20240809
 */

/*
 * SMD_Challenge Firmware
 * Based on: Attiny85Challenge by aspro648 (https://github.com/aspro648/KiCad/tree/master/projects/Attiny/Attiny85Challenge)
 * License: Creative Commons Attribution-ShareAlike 3.0 United States (CC BY-SA 3.0 US)
 * https://creativecommons.org/licenses/by-sa/3.0/us/
 */

#include<avr/io.h>
#include<util/delay.h>

const uint8_t LED_CTRL_REG[] = {0x01,0x02,0x04,0x08,0x10};


void onled (int index)
    {
    PORTB = LED_CTRL_REG[index];
    }

int main(void){
	DDRB  =0b00011111;	// ポートB 01234出力
	PORTB = 0x00;  // ポートB初期化

    unsigned char x;

    while(1){		//メインループ
        for (x=0;x < 5; x++){
        onled(x);
        _delay_ms(200);
        PORTB = 0;
        _delay_us(100);
        }
        for (x=0;x < 3; x++){
        onled(3-x);
        _delay_ms(200);
        PORTB = 0;
        _delay_ms(1);
        }
    }
}
