/*
 * File:   BLINK_PIC16F628A.c
 * Author: ALESSANDRO
 *
 * Created on 8 de Novembro de 2023, 18:30
 */


// PIC16F628A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define _XTAL_FREQ 4000000

int counter = 0x00;

void __interrupt()IntTimer(){
    if(T0IF){ 
        T0IF = 0x00;
        counter ++;
        if(counter == 3){ //+ ou - 20 ms
            RB0 = !RB0;
            counter = 0;
        }
    }
};

void main(void) {
    //Desabilita os resistores de pull-up internos
    //Configura o prescaler para 1:4
    OPTION_REG = 0x81;    // 0x81 ou 0b10000001
    
    //Habilita a interrupção global
    INTCON = 0b11100100;

    // CONFIG TIMER0
    T0CS = 0;       //TMR0 Clock Source Select bit
    PSA = 0;        //Prescaler Assignment bit
    PS2 = 1;        //WATCHDOG TIMER REGISTERS/Bit 2/WDTE 
    PS1 = 1;        //WATCHDOG TIMER REGISTERS/Bit 1/FOSC1
    PS0 = 1;        //WATCHDOG TIMER REGISTERS/Bit 0/FOSC0
    
    GIE = 1;        //Global Interrupt Enable bit
    T0IE = 1;       //: TMR0 Overflow Interrupt Enable bit
    
    //Habilita a interrupção por periféricos
    PIE1 = 0x01;    //PERIPHERAL INTERRUPT ENABLE REGISTER 1 (ADDRESS: 8Ch)
    
    TMR0 = 0x00;    //Timer0 Module’s Register 
    
    // Configura RB0 como saída 
    TRISBbits.TRISB0 = 0;       
    
    // Atribui nivel logico Baixo 0v
    PORTBbits.RB0 = 0;          
        
    while(1) {
        // Nada aqui
    }
}
