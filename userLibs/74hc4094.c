/*
 * File:   74hc4094.c
 * Author: Fernando Martins, John Santos
 *
 * Created on June 21, 2023, 9:39 AM
 */

#include "74hc4094.h"

void write74hc4094(uint16_t* _dataOut) {
    
    uint8_t j;

    for (j = 0; j < 8 ; j++) { // 2 Shifters, 8 bit per shifter
        //4094 - data
        LATA = (((uint16_t)*_dataOut >> j) & 0b1) ? (LATA |= _BV(_LATA_LATA4_POSN)) : (LATA &= ~_BV(_LATA_LATA4_POSN));
        //4094 - Clock
        LATA |= _BV(_LATA_LATA2_POSN);
        NOP();
        LATA &= ~_BV(_LATA_LATA2_POSN);
    }
    //4094 - Strobe
    LATA |= _BV(_LATA_LATA3_POSN);
    NOP();
    LATA &= ~_BV(_LATA_LATA3_POSN);
    
    return;
}
