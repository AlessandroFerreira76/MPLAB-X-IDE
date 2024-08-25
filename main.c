#include "userLibs/74hc4094.h"
#include "userLibs/74hc165.h"
#include "mcc_generated_files/mcc.h"

unsigned long cont=0, cont2=0;

void set_timer(void);

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    TMR2_SetInterruptHandler(set_timer);

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();    
    
    inputShiftRegister_t dataIn;

    while (1)
    {
        if((cont - cont2) > 10){
            cont2 = cont;
            read74hc165(&dataIn.data);
            LED1_Toggle();
            if(dataIn.in1){
                LED_SetHigh();
            }else{
                LED_SetLow();
            }
        }        
        
    }
}

void set_timer(void){
    cont++;
}
/**
 End of File
*/