/* 
 * File:   serialFrame.h
 * Author: John Carter
 * Comments:
 * Revision history: 1.0
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef SERIAL_FRAME_H
#define	SERIAL_FRAME_H

#include <xc.h> // include processor files - each processor file is guarded. 

#define BYTES_TO_ADDRESS(msb,lsb) (uint16_t)((((uint16_t)(msb) & 0x000F) << 8) | ((uint16_t)(lsb)))

typedef union keypadButtons {
    uint8_t buttons[3];

    struct {
        uint8_t bHome : 1;
        uint8_t bSobe : 1;
        uint8_t bMenu : 1;

        uint8_t bEsquerda : 1;
        uint8_t bOK : 1;
        uint8_t bDireita : 1;

        uint8_t bGiroAntiHor : 1;
        uint8_t bDesce : 1;
        uint8_t bGiroHor : 1;

        uint8_t b1 : 1;
        uint8_t b2 : 1;
        uint8_t b3 : 1;

        uint8_t bAuto : 1;
        uint8_t bFarol1 : 1;
        uint8_t bFarol2 : 1;

        uint8_t bBloqueioHid_FreioMotor : 1;
        uint8_t bRPMmais_FreioMotorMais : 1;
        uint8_t bCoelho_BloqueioDif : 1;

        uint8_t bParkBreak : 1;
        uint8_t bRPMmenos_FreioMotorMenos : 1;
        uint8_t bTartaruga_TomadaForca : 1;

        uint8_t bStart : 1;
        uint8_t bEmergencia: 1;
        uint8_t bUnused : 1;
    };
} keypadButtons_t;

typedef union serialFrame {
    uint8_t data[16];

    struct {
        uint8_t initOfFrame; //byte 0

        struct {
            uint8_t addressCodeH : 4; //byte 1.0 - 1.3 
            uint8_t specialMessage : 4; //byte 1.4 - 1.7
        };

        uint8_t addressCodeL; //byte 2 

        struct { //byte 3
            uint8_t leftJoyForwardFlag : 1;
            uint8_t leftJoyBackwardFlag : 1;
            uint8_t leftJoyYPoint : 6;
        };

        struct { //byte 4
            uint8_t leftJoyRightFlag : 1;
            uint8_t leftJoyLeftFlag : 1;
            uint8_t leftJoyXPoint : 6;
        };

        struct { //byte 5
            uint8_t rightJoyForwardFlag : 1;
            uint8_t rightJoyBackwardFlag : 1;
            uint8_t rightJoyYPoint : 6;
        };

        struct { //byte 6
            uint8_t rightJoyRightFlag : 1;
            uint8_t rightJoyLeftFlag : 1;
            uint8_t rightJoyXPoint : 6;
        };

        struct { //byte 7n
            uint8_t leftPedalForwardFlag : 1;
            uint8_t leftPedalBackwardFlag : 1;
            uint8_t leftPedalYPoint : 6;
        };

        struct { //byte 8
            uint8_t rightPedalForwardFlag : 1;
            uint8_t rightPedalBackwardFlag : 1;
            uint8_t rightPedalYPoint : 6;
        };

        struct { //byte 9
            uint8_t rightJoyB4 : 1;
            uint8_t rightJoyB3 : 1;
            uint8_t rightJoyB2 : 1;
            uint8_t rightJoyB1 : 1;
            uint8_t leftJoyB4 : 1;
            uint8_t leftJoyB3 : 1;
            uint8_t leftJoyB2 : 1;
            uint8_t leftJoyB1 : 1;
        };

        keypadButtons_t keypad; //byte 10 - 12

        uint8_t endOfFrame;

        uint8_t crcH;
        uint8_t crcL;
    };
} serialFrame_t;

typedef union heartbeatFrame {
    uint8_t data[6];

    struct {
        uint8_t initOfFrame; //byte 0

        struct {
            uint8_t addressCodeH : 4; //byte 1.0 - 1.3 
            uint8_t rxState : 4; //byte 1.4 - 1.7
        };

        uint8_t addressCodeL; //byte 2 

        uint8_t endOfFrame; //byte 3

        uint8_t crcH; //byte 4
        uint8_t crcL; //byte 5
    };
} feedbackFrame_t;

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* SERIAL_FRAME_H */

