

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _74HC165_H
#define	_74HC165_H

#include <xc.h> // include processor files - each processor file is guarded. 

#ifndef _BV
#define _BV(x)   (1 << (x)) 
#endif

typedef union inputShiftRegister {
    uint8_t data;

    struct {
        uint8_t dsp_on : 1;
        uint8_t in3 : 1;
        uint8_t in2 : 1;
        uint8_t in1 : 1;
        uint8_t pt4 : 1;
        uint8_t pt3 : 1;
        uint8_t pt2 : 1;
        uint8_t pt1 : 1;
    };
} inputShiftRegister_t;

void read74hc165(uint8_t *);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* _74HC165_H */

