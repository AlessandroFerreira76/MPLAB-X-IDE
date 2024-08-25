/*
 * File:   pwmSettings.c
 * Author: John Santos
 *
 * Created on June 20, 2023, 2:22 PM
 */


#include "pwmSettings.h"
#include "../mcc_generated_files/memory.h"
#include <string.h>

void readSettingsOnMemory(uint8_t* dataSettings, uint16_t address) {
    for (uint16_t i = address, j = 0; j < sizeof (pwmSettings_t); i++, j++, dataSettings++)
        *dataSettings = DATAEE_ReadByte(i);
}

void loadPWMSettings(uint8_t* dataSettings, uint16_t address) {
    pwmSettings_t auxSettings;

    readSettingsOnMemory(dataSettings, address); //Read data on EEPROM

    memset(auxSettings.data, 0xFF, sizeof (pwmSettings_t)); //Load 0xFF in all bytes of pAuxSettings

    if (memcmp(auxSettings.data, dataSettings, sizeof (pwmSettings_t)) != 0) //When an EEPROM has no data written to a certain area of memory, the data is read as 0xFF
    {
        return;
    } else { // Default Values

        switch (address) {
            case PWM1_EEPROM_ADDRESS:
                auxSettings.forward[0] = 50;
                auxSettings.forward[1] = 70;
                auxSettings.forward[2] = 71;
                auxSettings.forward[3] = 72;
                auxSettings.forward[4] = 73;
                auxSettings.forward[5] = 74;
                auxSettings.forward[6] = 75;
                auxSettings.forward[7] = 76;
                auxSettings.forward[8] = 77;
                auxSettings.forward[9] = 78;
                auxSettings.forward[10] = 79;
                auxSettings.forward[11] = 80;
                auxSettings.forward[12] = 81;
                auxSettings.forward[13] = 82;
                auxSettings.forward[14] = 83;
                auxSettings.forward[15] = 84;
                auxSettings.forward[16] = 86;
                auxSettings.forward[17] = 88;
                auxSettings.forward[18] = 90;
                auxSettings.forward[19] = 92;
                auxSettings.forward[20] = 93;
                
                auxSettings.backward[0] = 50;
                auxSettings.backward[1] = 40;
                auxSettings.backward[2] = 38;
                auxSettings.backward[3] = 36;
                auxSettings.backward[4] = 34;
                auxSettings.backward[5] = 32;
                auxSettings.backward[6] = 30;
                auxSettings.backward[7] = 28;
                auxSettings.backward[8] = 26;
                auxSettings.backward[9] = 24;
                auxSettings.backward[10] = 22;
                auxSettings.backward[11] = 20;
                auxSettings.backward[12] = 18;
                auxSettings.backward[13] = 16;
                auxSettings.backward[14] = 14;
                auxSettings.backward[15] = 12;
                auxSettings.backward[16] = 10;
                auxSettings.backward[17] = 9;
                auxSettings.backward[18] = 8;
                auxSettings.backward[19] = 7;
                auxSettings.backward[20] = 6;
                auxSettings.stepTime = 1;
                break;

            case PWM2_EEPROM_ADDRESS:
                auxSettings.forward[0] = 50;
                auxSettings.forward[1] = 40;
                auxSettings.forward[2] = 38;
                auxSettings.forward[3] = 36;
                auxSettings.forward[4] = 34;
                auxSettings.forward[5] = 32;
                auxSettings.forward[6] = 30;
                auxSettings.forward[7] = 28;
                auxSettings.forward[8] = 26;
                auxSettings.forward[9] = 24;
                auxSettings.forward[10] = 22;
                auxSettings.forward[11] = 20;
                auxSettings.forward[12] = 18;
                auxSettings.forward[13] = 16;
                auxSettings.forward[14] = 14;
                auxSettings.forward[15] = 12;
                auxSettings.forward[16] = 10;
                auxSettings.forward[17] = 9;
                auxSettings.forward[18] = 8;
                auxSettings.forward[19] = 7;
                auxSettings.forward[20] = 6;

                auxSettings.backward[0] = 50;
                auxSettings.backward[1] = 60;
                auxSettings.backward[2] = 61;
                auxSettings.backward[3] = 62;
                auxSettings.backward[4] = 63;
                auxSettings.backward[5] = 64;
                auxSettings.backward[6] = 65;
                auxSettings.backward[7] = 66;
                auxSettings.backward[8] = 67;
                auxSettings.backward[9] = 68;
                auxSettings.backward[10] = 69;
                auxSettings.backward[11] = 70;
                auxSettings.backward[12] = 72;
                auxSettings.backward[13] = 74;
                auxSettings.backward[14] = 76;
                auxSettings.backward[15] = 78;
                auxSettings.backward[16] = 80;
                auxSettings.backward[17] = 82;
                auxSettings.backward[18] = 85;
                auxSettings.backward[19] = 88;
                auxSettings.backward[20] = 93;
                auxSettings.stepTime = 1;
                break;
            case PWM3_EEPROM_ADDRESS:
                auxSettings.forward[0] = 50;
                auxSettings.forward[1] = 70;
                auxSettings.forward[2] = 71;
                auxSettings.forward[3] = 72;
                auxSettings.forward[4] = 73;
                auxSettings.forward[5] = 74;
                auxSettings.forward[6] = 75;
                auxSettings.forward[7] = 76;
                auxSettings.forward[8] = 77;
                auxSettings.forward[9] = 78;
                auxSettings.forward[10] = 79;
                auxSettings.forward[11] = 80;
                auxSettings.forward[12] = 81;
                auxSettings.forward[13] = 82;
                auxSettings.forward[14] = 83;
                auxSettings.forward[15] = 84;
                auxSettings.forward[16] = 86;
                auxSettings.forward[17] = 88;
                auxSettings.forward[18] = 90;
                auxSettings.forward[19] = 92;
                auxSettings.forward[20] = 93;
                
                auxSettings.backward[0] = 50;
                auxSettings.backward[1] = 40;
                auxSettings.backward[2] = 38;
                auxSettings.backward[3] = 36;
                auxSettings.backward[4] = 34;
                auxSettings.backward[5] = 32;
                auxSettings.backward[6] = 30;
                auxSettings.backward[7] = 28;
                auxSettings.backward[8] = 26;
                auxSettings.backward[9] = 24;
                auxSettings.backward[10] = 22;
                auxSettings.backward[11] = 20;
                auxSettings.backward[12] = 18;
                auxSettings.backward[13] = 16;
                auxSettings.backward[14] = 14;
                auxSettings.backward[15] = 12;
                auxSettings.backward[16] = 10;
                auxSettings.backward[17] = 9;
                auxSettings.backward[18] = 8;
                auxSettings.backward[19] = 7;
                auxSettings.backward[20] = 6;
                auxSettings.stepTime = 1;
                break;
            case PWM4_EEPROM_ADDRESS:
                auxSettings.forward[0] = 50;
                auxSettings.forward[1] = 37;
                auxSettings.forward[2] = 36;
                auxSettings.forward[3] = 35;
                auxSettings.forward[4] = 34;
                auxSettings.forward[5] = 32;
                auxSettings.forward[6] = 30;
                auxSettings.forward[7] = 28;
                auxSettings.forward[8] = 26;
                auxSettings.forward[9] = 24;
                auxSettings.forward[10] = 22;
                auxSettings.forward[11] = 20;
                auxSettings.forward[12] = 18;
                auxSettings.forward[13] = 16;
                auxSettings.forward[14] = 14;
                auxSettings.forward[15] = 12;
                auxSettings.forward[16] = 10;
                auxSettings.forward[17] = 9;
                auxSettings.forward[18] = 8;
                auxSettings.forward[19] = 7;
                auxSettings.forward[20] = 6;

                auxSettings.backward[0] = 50;
                auxSettings.backward[1] = 70;
                auxSettings.backward[2] = 71;
                auxSettings.backward[3] = 72;
                auxSettings.backward[4] = 73;
                auxSettings.backward[5] = 74;
                auxSettings.backward[6] = 75;
                auxSettings.backward[7] = 76;
                auxSettings.backward[8] = 77;
                auxSettings.backward[9] = 78;
                auxSettings.backward[10] = 79;
                auxSettings.backward[11] = 80;
                auxSettings.backward[12] = 81;
                auxSettings.backward[13] = 82;
                auxSettings.backward[14] = 83;
                auxSettings.backward[15] = 84;
                auxSettings.backward[16] = 86;
                auxSettings.backward[17] = 88;
                auxSettings.backward[18] = 90;
                auxSettings.backward[19] = 92;
                auxSettings.backward[20] = 93;
                auxSettings.stepTime = 1;
                break;
            case PWM5_EEPROM_ADDRESS:
                auxSettings.forward[0] = 50;
                auxSettings.forward[1] = 70;
                auxSettings.forward[2] = 71;
                auxSettings.forward[3] = 72;
                auxSettings.forward[4] = 73;
                auxSettings.forward[5] = 74;
                auxSettings.forward[6] = 75;
                auxSettings.forward[7] = 76;
                auxSettings.forward[8] = 77;
                auxSettings.forward[9] = 78;
                auxSettings.forward[10] = 79;
                auxSettings.forward[11] = 80;
                auxSettings.forward[12] = 81;
                auxSettings.forward[13] = 82;
                auxSettings.forward[14] = 83;
                auxSettings.forward[15] = 84;
                auxSettings.forward[16] = 86;
                auxSettings.forward[17] = 87;
                auxSettings.forward[18] = 88;
                auxSettings.forward[19] = 89;
                auxSettings.forward[20] = 90; //93%
                
                auxSettings.backward[0] = 50;
                auxSettings.backward[1] = 40;
                auxSettings.backward[2] = 38;
                auxSettings.backward[3] = 36;
                auxSettings.backward[4] = 34;
                auxSettings.backward[5] = 32;
                auxSettings.backward[6] = 30;
                auxSettings.backward[7] = 28;
                auxSettings.backward[8] = 26;
                auxSettings.backward[9] = 24;
                auxSettings.backward[10] = 22;
                auxSettings.backward[11] = 20;
                auxSettings.backward[12] = 18;
                auxSettings.backward[13] = 16;
                auxSettings.backward[14] = 14;
                auxSettings.backward[15] = 12;
                auxSettings.backward[16] = 10;
                auxSettings.backward[17] = 9;
                auxSettings.backward[18] = 8;
                auxSettings.backward[19] = 7;
                auxSettings.backward[20] = 6;
                auxSettings.stepTime = 1;
                break;
            case PWM6_EEPROM_ADDRESS:
                auxSettings.forward[0] = 50;
                auxSettings.forward[1] = 70;
                auxSettings.forward[2] = 71;
                auxSettings.forward[3] = 72;
                auxSettings.forward[4] = 73;
                auxSettings.forward[5] = 74;
                auxSettings.forward[6] = 75;
                auxSettings.forward[7] = 76;
                auxSettings.forward[8] = 77;
                auxSettings.forward[9] = 78;
                auxSettings.forward[10] = 79;
                auxSettings.forward[11] = 80;
                auxSettings.forward[12] = 81;
                auxSettings.forward[13] = 82;
                auxSettings.forward[14] = 83;
                auxSettings.forward[15] = 84;
                auxSettings.forward[16] = 86;
                auxSettings.forward[17] = 87;
                auxSettings.forward[18] = 88;
                auxSettings.forward[19] = 89;
                auxSettings.forward[20] = 90; //93%
                
                auxSettings.backward[0] = 50;
                auxSettings.backward[1] = 40;
                auxSettings.backward[2] = 38;
                auxSettings.backward[3] = 36;
                auxSettings.backward[4] = 34;
                auxSettings.backward[5] = 32;
                auxSettings.backward[6] = 30;
                auxSettings.backward[7] = 28;
                auxSettings.backward[8] = 26;
                auxSettings.backward[9] = 24;
                auxSettings.backward[10] = 22;
                auxSettings.backward[11] = 20;
                auxSettings.backward[12] = 18;
                auxSettings.backward[13] = 16;
                auxSettings.backward[14] = 14;
                auxSettings.backward[15] = 12;
                auxSettings.backward[16] = 10;
                auxSettings.backward[17] = 9;
                auxSettings.backward[18] = 8;
                auxSettings.backward[19] = 7;
                auxSettings.backward[20] = 6;
                auxSettings.stepTime = 1;
                break;
            case PWM7_EEPROM_ADDRESS:
                auxSettings.forward[0] = 50;
                auxSettings.forward[1] = 40;
                auxSettings.forward[2] = 38;
                auxSettings.forward[3] = 36;
                auxSettings.forward[4] = 34;
                auxSettings.forward[5] = 32;
                auxSettings.forward[6] = 30;
                auxSettings.forward[7] = 28;
                auxSettings.forward[8] = 26;
                auxSettings.forward[9] = 24;
                auxSettings.forward[10] = 22;
                auxSettings.forward[11] = 20;
                auxSettings.forward[12] = 18;
                auxSettings.forward[13] = 16;
                auxSettings.forward[14] = 14;
                auxSettings.forward[15] = 12;
                auxSettings.forward[16] = 10;
                auxSettings.forward[17] = 9;
                auxSettings.forward[18] = 8;
                auxSettings.forward[19] = 7;
                auxSettings.forward[20] = 6;

                auxSettings.backward[0] = 50;
                auxSettings.backward[1] = 70;
                auxSettings.backward[2] = 71;
                auxSettings.backward[3] = 72;
                auxSettings.backward[4] = 73;
                auxSettings.backward[5] = 74;
                auxSettings.backward[6] = 75;
                auxSettings.backward[7] = 76;
                auxSettings.backward[8] = 77;
                auxSettings.backward[9] = 78;
                auxSettings.backward[10] = 79;
                auxSettings.backward[11] = 80;
                auxSettings.backward[12] = 81;
                auxSettings.backward[13] = 82;
                auxSettings.backward[14] = 83;
                auxSettings.backward[15] = 84;
                auxSettings.backward[16] = 86;
                auxSettings.backward[17] = 88;
                auxSettings.backward[18] = 90;
                auxSettings.backward[19] = 92;
                auxSettings.backward[20] = 93;
                auxSettings.stepTime = 1;
                break;
            case PWM8_EEPROM_ADDRESS:
                auxSettings.forward[0] = 50;
                auxSettings.forward[1] = 40;
                auxSettings.forward[2] = 38;
                auxSettings.forward[3] = 36;
                auxSettings.forward[4] = 34;
                auxSettings.forward[5] = 32;
                auxSettings.forward[6] = 30;
                auxSettings.forward[7] = 28;
                auxSettings.forward[8] = 26;
                auxSettings.forward[9] = 24;
                auxSettings.forward[10] = 22;
                auxSettings.forward[11] = 20;
                auxSettings.forward[12] = 18;
                auxSettings.forward[13] = 16;
                auxSettings.forward[14] = 14;
                auxSettings.forward[15] = 13;
                auxSettings.forward[16] = 12;
                auxSettings.forward[17] = 11;
                auxSettings.forward[18] = 10;
                auxSettings.forward[19] = 9;
                auxSettings.forward[20] = 8;

                auxSettings.backward[0] = 50;
                auxSettings.backward[1] = 70;
                auxSettings.backward[2] = 71;
                auxSettings.backward[3] = 72;
                auxSettings.backward[4] = 73;
                auxSettings.backward[5] = 74;
                auxSettings.backward[6] = 75;
                auxSettings.backward[7] = 76;
                auxSettings.backward[8] = 77;
                auxSettings.backward[9] = 78;
                auxSettings.backward[10] = 79;
                auxSettings.backward[11] = 80;
                auxSettings.backward[12] = 81;
                auxSettings.backward[13] = 82;
                auxSettings.backward[14] = 83;
                auxSettings.backward[15] = 84;
                auxSettings.backward[16] = 85;
                auxSettings.backward[17] = 86;
                auxSettings.backward[18] = 87;
                auxSettings.backward[19] = 88;
                auxSettings.backward[20] = 89; //92%
                auxSettings.stepTime = 1;
                break;
        }

        memcpy(dataSettings, auxSettings.data, sizeof (pwmSettings_t));

        return;
    }

}
