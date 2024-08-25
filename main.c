#include "mcc_generated_files/mcc.h"
#include "mcp2515_driver/mcp2515_driver.h"

unsigned long num=0, num2=0;
volatile _Bool canReceiveFlag = false;

void mcpInitialze(void);
void set_cont(void);
void jigaCanRX(void);

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    mcpInitialze();
    TMR2_SetInterruptHandler(set_cont);
    INT_SetInterruptHandler(jigaCanRX); 
    
    CAN_FRAME RXJiga, TXJiga;
    memset(&TXJiga, 0x00, sizeof (CAN_FRAME));
    
    TXJiga.ID = 0x18018081;
    TXJiga.type = can_extended;
    TXJiga.isRemote = 0;
    TXJiga.DLC = 8;
    TXJiga.DATA[0] = 0x00;
    TXJiga.DATA[1] = 0x00;
    TXJiga.DATA[2] = 0x00;
    TXJiga.DATA[3] = 0x00;
    TXJiga.DATA[4] = 0x00;
    TXJiga.DATA[5] = 0x00;
    TXJiga.DATA[6] = 0x00;
    TXJiga.DATA[7] = 0x00;

    while (1)
    {
        if((num - num2) > 10){
            num2 = num;
            //LED_Toggle();
            TXJiga.DATA[0]++;
            mcpCanSend(TXJiga);
        }
        //mcpCanReceive(&RXJiga);
        if (mcpCanReceive(&RXJiga)) {
            //canReceiveFlag = false;
            LED_Toggle();
            //mcpCanReceive(&RXJiga);
                if (RXJiga.ID == 0x00C70148) {
                    TXJiga.DATA[1] = RXJiga.DATA[1];
                    TXJiga.DATA[2] = RXJiga.DATA[2];
                    TXJiga.DATA[3] = RXJiga.DATA[3];
                    TXJiga.DATA[4] = RXJiga.DATA[4];
                    TXJiga.DATA[5] = RXJiga.DATA[5];
                    TXJiga.DATA[6] = RXJiga.DATA[6];
                    TXJiga.DATA[7] = RXJiga.DATA[7];
                }
        }        
    }//End while
}//End main

void mcpInitialze(void) {
    int* auxPtr;
    canChipReset();
    __delay_ms(5);    
    canBegin(auxPtr, 250);
    canEnableRXInterrupts();
}

void set_cont(){
    num++;
    return;
}

void jigaCanRX(void){
    canReceiveFlag = true;
    return;
}
/**
 End of File
*/