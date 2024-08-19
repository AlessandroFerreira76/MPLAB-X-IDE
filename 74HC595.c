

#include "74hc4094.h"

void write74hc4094(uint8_t* _dataOut) {
    
    uint8_t j;

    for (j = 0; j < 8 ; j++) { // 2 Shifters, 8 bit per shifter
        //4094 - data
        PORTB = (((uint8_t)*_dataOut >> j) & 0b1) ? (PORTB |= _BV(_PORTB_RB4_POSN)) : (PORTB &= ~_BV(_PORTB_RB4_POSN));
        //4094 - Clock
        PORTB |= _BV(_PORTB_RB2_POSN);
        NOP();
        PORTB &= ~_BV(_PORTB_RB2_POSN);
    }
    //4094 - Strobe
    PORTB |= _BV(_PORTB_RB3_POSN);
    NOP();
    PORTB &= ~_BV(_PORTB_RB3_POSN);
    
    return;
}
