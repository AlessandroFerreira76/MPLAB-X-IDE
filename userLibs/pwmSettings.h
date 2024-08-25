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
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef PWM_SETTINGS_H
#define	PWM_SETTINGS_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define PWM1_EEPROM_ADDRESS 0
#define PWM2_EEPROM_ADDRESS (PWM1_EEPROM_ADDRESS + 43)
#define PWM3_EEPROM_ADDRESS (PWM2_EEPROM_ADDRESS + 43)
#define PWM4_EEPROM_ADDRESS (PWM3_EEPROM_ADDRESS + 43)
#define PWM5_EEPROM_ADDRESS (PWM4_EEPROM_ADDRESS + 43)
#define PWM6_EEPROM_ADDRESS (PWM5_EEPROM_ADDRESS + 43)
#define PWM7_EEPROM_ADDRESS (PWM6_EEPROM_ADDRESS + 43)
#define PWM8_EEPROM_ADDRESS (PWM7_EEPROM_ADDRESS + 43)

typedef union pwmSettings {
    uint8_t data[43];

    struct {
        uint8_t forward[21]; //PWM dutycycle in percentage  
        uint8_t backward[21]; //PWM dutycycle in percentage 

        uint8_t stepTime; //milliseconds to next PWM step   
    };
} pwmSettings_t;

// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

void loadPWMSettings(uint8_t* dataSettings, uint16_t address);
void readSettingsOnMemory(uint8_t* dataSettings, uint16_t address);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* PWM_SETTINGS_H */

