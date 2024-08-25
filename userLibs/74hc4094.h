/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:    74hc4094.h
 * Author: John Santos, Fernando Martins
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
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

void write74hc4094(uint16_t* _dataOut);

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

