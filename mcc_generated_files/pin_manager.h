/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1779
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SO aliases
#define SO_TRIS                 TRISAbits.TRISA0
#define SO_LAT                  LATAbits.LATA0
#define SO_PORT                 PORTAbits.RA0
#define SO_WPU                  WPUAbits.WPUA0
#define SO_OD                   ODCONAbits.ODA0
#define SO_ANS                  ANSELAbits.ANSA0
#define SO_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define SO_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define SO_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define SO_GetValue()           PORTAbits.RA0
#define SO_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define SO_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define SO_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define SO_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define SO_SetPushPull()        do { ODCONAbits.ODA0 = 0; } while(0)
#define SO_SetOpenDrain()       do { ODCONAbits.ODA0 = 1; } while(0)
#define SO_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define SO_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set SH aliases
#define SH_TRIS                 TRISAbits.TRISA1
#define SH_LAT                  LATAbits.LATA1
#define SH_PORT                 PORTAbits.RA1
#define SH_WPU                  WPUAbits.WPUA1
#define SH_OD                   ODCONAbits.ODA1
#define SH_ANS                  ANSELAbits.ANSA1
#define SH_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define SH_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define SH_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define SH_GetValue()           PORTAbits.RA1
#define SH_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define SH_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define SH_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define SH_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define SH_SetPushPull()        do { ODCONAbits.ODA1 = 0; } while(0)
#define SH_SetOpenDrain()       do { ODCONAbits.ODA1 = 1; } while(0)
#define SH_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define SH_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set CLK aliases
#define CLK_TRIS                 TRISAbits.TRISA2
#define CLK_LAT                  LATAbits.LATA2
#define CLK_PORT                 PORTAbits.RA2
#define CLK_WPU                  WPUAbits.WPUA2
#define CLK_OD                   ODCONAbits.ODA2
#define CLK_ANS                  ANSELAbits.ANSA2
#define CLK_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define CLK_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define CLK_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define CLK_GetValue()           PORTAbits.RA2
#define CLK_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define CLK_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define CLK_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define CLK_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define CLK_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define CLK_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define CLK_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define CLK_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISDbits.TRISD1
#define LED_LAT                  LATDbits.LATD1
#define LED_PORT                 PORTDbits.RD1
#define LED_WPU                  WPUDbits.WPUD1
#define LED_OD                   ODCONDbits.ODD1
#define LED_ANS                  ANSELDbits.ANSD1
#define LED_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define LED_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define LED_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define LED_GetValue()           PORTDbits.RD1
#define LED_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define LED_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define LED_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONDbits.ODD1 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONDbits.ODD1 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISDbits.TRISD2
#define LED1_LAT                  LATDbits.LATD2
#define LED1_PORT                 PORTDbits.RD2
#define LED1_WPU                  WPUDbits.WPUD2
#define LED1_OD                   ODCONDbits.ODD2
#define LED1_ANS                  ANSELDbits.ANSD2
#define LED1_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define LED1_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define LED1_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define LED1_GetValue()           PORTDbits.RD2
#define LED1_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define LED1_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONDbits.ODD2 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONDbits.ODD2 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/