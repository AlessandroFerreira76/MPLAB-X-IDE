// more than once.  
#ifndef _74HC4094_H
#define	_74HC4094_H

#include <xc.h> // include processor files - each processor file is guarded.  

#ifndef _BV
#define _BV(x)   (1 << (x)) 
#endif

typedef union outputShiftRegister {
    uint16_t data;

    struct {
        struct {
            uint8_t exp1RL1 : 1;
            uint8_t exp1RL2 : 1;
            uint8_t exp1RL3 : 1;
            uint8_t exp1RL4 : 1;
            uint8_t unused : 1;
            uint8_t exp2RL2 : 1;
            uint8_t exp2RL1 : 1;
            uint8_t RL12 : 1;
        };

        struct {
            uint8_t RL11 : 1;
            uint8_t RL10 : 1;
            uint8_t RL9 : 1;
            uint8_t RL8 : 1;
            uint8_t RL7 : 1;
            uint8_t RL6 : 1;
            uint8_t RL5 : 1;
            uint8_t RL4 : 1;
        };
    };
} outputShiftRegister_t;

void write74hc4094(uint8_t* _dataOut);

// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* _74HC4094_H */

