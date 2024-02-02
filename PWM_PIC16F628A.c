/*
 * File:   PWM.c
 * Author: ALESSANDRO
 *
 * Created on January 1, 2024, 6:06 PM
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

#define _XTAL_FREQ 8000000

//#define S1 PORTAbits.RA0;
//#define S2 PORTAbits.RA1;

void  __interrupt()IntTimer(){
    if(T0IF_bit){
        T0IF = 0x00;
        TMR0 = 0x6C;
        
        if(PORTAbits.RA1 == 0) {
            CCPR1L++;            
        }
        else if(PORTAbits.RA2 == 0) {
            CCPR1L--;            
        }//End else if
    }
}// End Interrupt

void main(void) {
    CMCON   = 0x07;     //Desabilita os comparadores
    OPTION_REG = 0x86;  //Timer0 incrementa com ciclo de instrução, prescaler 1:128
    GIE     = 0x01;     //Global Interrupt Enable bit    
    PEIE    = 0x01;     //PERIPHERAL INTERRUPT ENABLE REGISTER 1 (ADDRESS: 8Ch)
    T0IE    = 0x01;     //TMR0 Overflow Interrupt Enable bit
    TMR0    = 0x6C;     //Timer0 Module?s Register
    
    // PERIODO = (PR2 + 1) X CICLO DE MAQUINA X PRESCALER DO TIMER2
    // periodo = 256 x 1us x 16 = 4,096ms
    // frequencia = 1/periodo = 244,14hz
    
    PR2     = 0xFF;      //Inicializa o registrador de controle do timer 2 em 255
    T2CON   = 0x06;      //Liga o timer2 e prescaler 1:16 
    CCPR1L  = 0x00;      //Led iniciará desligado
    CCP1CON = 0x0C;      //Habilita o modo PWM
    
    TRISA   = 0x06;      //Entrada em RA0 e RA1 00000110    
    TRISB   = 0x00;      //Todo portB será saida
    PORTA   = 0x00;      //RA0 e RA1 iniciam em high    
    PORTB   = 0x00;      //Todo PORTB inicia em nivel low   
    
    while(1) {
        // Nada aqui
    }
}



