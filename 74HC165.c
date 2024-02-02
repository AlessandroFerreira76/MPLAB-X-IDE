/*
 * File:   74hc165.c
 * Author: Usuario
 *
 * Created on 16 de Novembro de 2022, 14:07
 */


#include "74hc165.h"

void read74hc165(uint8_t *dataBuffer) {
    uint8_t i;
    *dataBuffer = 0;

    //74HC165 Step 1: Sample (HC165-SH)
    //PORTB &= ~_BV(_PORTB_PORTB1_POSN);
    PORTB &= ~_BV(_PORTB_RB1_POSN);
    NOP();
    PORTB |= _BV(_PORTB_RB1_POSN);

    //74HC165 Step 2: Shift
    for (i = 0; i < 8; i++) {
        *dataBuffer |= (((PORTA & _PORTA_RA0_MASK) >> (_PORTA_RA0_POSN)) << i); //Read HC165-SO and store

        PORTB |= _BV(_PORTB_RB2_POSN); //74HC165 Shift out (HC165-CLK) the next bit
        NOP();
        PORTB &= ~_BV(_PORTB_RB2_POSN);
    }

    *dataBuffer = ~*dataBuffer; // Invert buffer 
    
    return;
}

