/*
 *SMD Challenge Badge ATtiny13A 32mm 
 *���� dominoTECH EqUret
 *����N 20240809
 */*
 * SMD Challenge - ��ɂ����v���W�F�N�g: https://github.com/aspro648/KiCad/tree/master/projects/Attiny/Attiny85Challenge
 * ���C�Z���X: CC BY-SA 3.0 US (https://creativecommons.org/licenses/by-sa/3.0/)
 * �쐬��: [���Ȃ��̖��O]
 * �ύX�_: [LED�̔z�u��ύX�AATtiny85����ATtiny13A�ɕύX]
 */
 */
#include<avr/io.h>
#include<util/delay.h>

const uint8_t LED_CTRL_REG[] = {0x01,0x02,0x04,0x08,0x10};


void onled (int index)
    {
    PORTB = LED_CTRL_REG[index];
    }

int main(void){
	DDRB  =0b00011111;	// �|�[�gB 01234�o��
	PORTB = 0x00;  // �|�[�gB������

    unsigned char x;

    while(1){		//���C�����[�v
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
