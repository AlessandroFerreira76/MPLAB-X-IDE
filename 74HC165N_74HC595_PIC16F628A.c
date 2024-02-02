// CONFIG
#pragma config FOSC = INTOSCCLK // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#include "userLibs/74hc4094.h"
#include "userLibs/74hc165.h"

#define _XTAL_FREQ 8000000

void main(void) {
    CMCON   = 0x07;     //Desabilita os comparadores
    
    TRISA   = 0x06;      //Entrada em RA0 e RA1 00000110    
    TRISB   = 0x00;      //Todo portB será saida
    PORTA   = 0x00;      //RA0 e RA1 iniciam em high    
    PORTB   = 0x00;      //Todo PORTB inicia em nivel low  
    
    outputShiftRegister_t dataOut;
    inputShiftRegister_t dataIn;
    dataIn.data = 0;
    
    while(1){
        read74hc165(&dataIn.data);
        if(dataIn.in3){
            PORTBbits.RB5 = 1;
            dataOut.data = 0b00000001;
        } else {
            PORTBbits.RB5 = 0;
            dataOut.data = 0b00000000;
        }        
        write74hc4094(&dataOut);
        __delay_ms(200);              
        
    }//End while
}//End main
