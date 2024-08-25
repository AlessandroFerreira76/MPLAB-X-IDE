/**
 * @author Ashutosh Singh Parmar
 * @file mcp2515_driver.h
 * @brief This file contains function declarations for core driver APIs.
*/
#ifndef MCP2515_DRIVER
#define MCP2515_DRIVER

#include "mcp2515_driver_pal.h"

/**
 * @brief ADDRESS OF MCP2515 CONTROL REGISTERS.
 */
#define MCP_BFPCTRL 0X0C	/* bit modify */

#define MCP_TXRTSCTRL 0X0D	/* bit modify */

#define MCP_CANSTAT 0XFE

#define MCP_CANCTRL 0XFF	/* bit modify */

#define MCP_TEC 0X1C

#define MCP_REC 0X1D

#define MCP_CNF3 0X28	/* bit modify */

#define MCP_CNF2 0X29	/* bit modify */

#define MCP_CNF1 0X2A	/* bit modify */

#define MCP_CANINTE 0X2B	/* bit modify */

#define MCP_CANINTF 0X2C	/* bit modify */

#define MCP_EFLG 0X2D	/* bit modify */

#define MCP_TXB0CTRL 0X30	/* bit modify */

#define MCP_TXB1CTRL 0X40	/* bit modify */

#define MCP_TXB2CTRL 0X50	/* bit modify */

#define MCP_RXB0CTRL 0X60	/* bit modify */

#define MCP_RXB1CTRL 0X70	/* bit modify */


/**
 * @brief MCP2515 INSTRUCTIONS
 */

#define MCP_RESET 0XC0

#define MCP_READ  0X03

#define MCP_WRITE 0X02

#define MCP_RTS_TX0 0X81

#define MCP_RTS_TX1 0X82

#define MCP_RTS_TX2 0X84

#define MCP_RTS_TX0_TX1 0X83

#define MCP_RTS_TX0_TX2 0X85

#define MCP_RTS_TX1_TX2 0X86

#define MCP_RTS_ALL 0X87

#define MCP_READ_STATUS 0XA0

#define MCP_RX_STATUS 0XB0

#define MCP_BIT_MODIFY 0X05

#define MCP_LOAD_TX0_ID 0x40

#define MCP_LOAD_TX0_DATA 0x41

#define MCP_LOAD_TX1_ID 0x42

#define MCP_LOAD_TX1_DATA 0x43

#define MCP_LOAD_TX2_ID 0x44

#define MCP_LOAD_TX2_DATA 0x45

#define MCP_READ_RX0_ID 0x90

#define MCP_READ_RX0_DATA 0x92

#define MCP_READ_RX1_ID 0x94

#define MCP_READ_RX1_DATA 0x96



/**
 * @brief ADDRESSES OF MCP2515 RECEIVE BUFFER REGISTERS
 */

#define MCP_RXB0SIDH 0X61

#define MCP_RXB0SIDL 0X62

#define MCP_RXB0EID8 0X63

#define MCP_RXB0EID0 0X64

#define MCP_RXB0DLC 0X65

#define MCP_RXB0D0 0X66

#define MCP_RXB0D1 0X67

#define MCP_RXB0D2 0X68

#define MCP_RXB0D3 0X69

#define MCP_RXB0D4 0X6A

#define MCP_RXB0D5 0X6B

#define MCP_RXB0D6 0X6C

#define MCP_RXB0D7 0X6D



#define MCP_RXB1SIDH 0X71

#define MCP_RXB1SIDL 0X72

#define MCP_RXB1EID8 0X73

#define MCP_RXB1EID0 0X74

#define MCP_RXB1DLC 0X75

#define MCP_RXB1D0 0X76

#define MCP_RXB1D1 0X77

#define MCP_RXB1D2 0X78

#define MCP_RXB1D3 0X79

#define MCP_RXB1D4 0X7A

#define MCP_RXB1D5 0X7B

#define MCP_RXB1D6 0X7C

#define MCP_RXB1D7 0X7D


/**
 * @brief ADDRESSES OF MCP2515 TRANSMIT BUFFERS
 */

#define MCP_TXB0SIDH 0X31

#define MCP_TXB0SIDL 0X32

#define MCP_TXB0EID8 0X33

#define MCP_TXB0EID0 0X34

#define MCP_TXB0DLC 0X35

#define MCP_TXB0D0 0X36

#define MCP_TXB0D1 0X37

#define MCP_TXB0D2 0X38

#define MCP_TXB0D3 0X39

#define MCP_TXB0D4 0X3A

#define MCP_TXB0D5 0X3B

#define MCP_TXB0D6 0X3C

#define MCP_TXB0D7 0X3D


#define MCP_TXB1SIDH 0X41

#define MCP_TXB1SIDL 0X42

#define MCP_TXB1EID8 0X43

#define MCP_TXB1EID0 0X44

#define MCP_TXB1DLC 0X45

#define MCP_TXB1D0 0X46

#define MCP_TXB1D1 0X47

#define MCP_TXB1D2 0X48

#define MCP_TXB1D3 0X49

#define MCP_TXB1D4 0X4A

#define MCP_TXB1D5 0X4B

#define MCP_TXB1D6 0X4C

#define MCP_TXB1D7 0X4D


#define MCP_TXB2SIDH 0X51

#define MCP_TXB2SIDL 0X52

#define MCP_TXB2EID8 0X53

#define MCP_TXB2EID0 0X54

#define MCP_TXB2DLC 0X55

#define MCP_TXB2D0 0X56

#define MCP_TXB2D1 0X57

#define MCP_TXB2D2 0X58

#define MCP_TXB2D3 0X59

#define MCP_TXB2D4 0X5A

#define MCP_TXB2D5 0X5B

#define MCP_TXB2D6 0X5C

#define MCP_TXB2D7 0X5D

/**
 * @brief MCP2515 MASKS AND FILTERS.
 */

#define MCP_RXF0SIDH 0x00

#define MCP_RXF0SIDL 0x01

#define MCP_RXF0EID8 0x02

#define MCP_RXF0EID0 0x03


#define MCP_RXF1SIDH 0x04

#define MCP_RXF1SIDL 0x05

#define MCP_RXF1EID8 0x06

#define MCP_RXF1EID0 0x07


#define MCP_RXF2SIDH 0x08

#define MCP_RXF2SIDL 0x09

#define MCP_RXF2EID8 0x0A

#define MCP_RXF2EID0 0x0B


#define MCP_RXF3SIDH 0X10

#define MCP_RXF3SIDL 0X11

#define MCP_RXF3EID8 0X12

#define MCP_RXF3EID0 0X13


#define MCP_RXF4SIDH 0X14

#define MCP_RXF4SIDL 0X15

#define MCP_RXF4EID8 0X16

#define MCP_RXF4EID0 0X17


#define MCP_RXF5SIDH 0X18

#define MCP_RXF5SIDL 0X19

#define MCP_RXF5EID8 0X1A

#define MCP_RXF5EID0 0X1B


#define MCP_RXM0SIDH 0X20

#define MCP_RXM0SIDL 0X21

#define MCP_RXM0EID8 0X23

#define MCP_RXM0EID0 0X24


#define MCP_RXM1SIDH 0X25

#define MCP_RXM1SIDL 0X26

#define MCP_RXM1EID8 0X27

#define MCP_RXM1EID0 0X28

/**
 * BITS
 */

/** 
 * @brief TXBnCTRL
 */
#define MCP_ABTF 6
#define MCP_MLOA 5
#define MCP_TXERR 4
#define MCP_TXREQ 3
#define MCP_TXP1 1
#define MCP_TXP0 0

/**
 * @brief TXBnSIDL, RXFnSIDL
*/
#define MCP_EXIDE 3

/**
 * @brief TXBnDLC
 */
#define MCP_RTR 6

/**
 * @brief CANCTRL
 */
#define MCP_REQOP2 7
#define MCP_REQOP1 6
#define MCP_REQOP0 5
#define MCP_ABAT 4
#define MCP_OSM 3
#define MCP_CLKEN 2
#define MCP_CLKPRE1 1
#define MCP_CLKPRE0 0

/**
 * @brief CANSTAT
*/
#define MCP_OPMOD2 7
#define MCP_OPMOD1 6
#define MCP_OPMOD0 5
#define MCP_ICOD2 3
#define MCP_ICOD1 2
#define MCP_ICOD0 1

/**
 * @brief CANINTF
*/
#define MCP_MERRF 7
#define MCP_WAKIF 6
#define MCP_ERRIF 5
#define MCP_TX2IF 4
#define MCP_TX1IF 3
#define MCP_TX0IF 2
#define MCP_RX1IF 1
#define MCP_RX0IF 0

/**
 * @brief CANINTE
*/
#define MCP_MERRE 7
#define MCP_WAKIE 6
#define MCP_ERRIE 5
#define MCP_TX2IE 4
#define MCP_TX1IE 3
#define MCP_TX0IE 2
#define MCP_RX1IE 1
#define MCP_RX0IE 0

/**
 * @brief RXBnCTRL
*/
#define MCP_RXM1 6
#define MCP_RXM0 5
#define MCP_RXRTR 3
#define MCP_BUKT 2
#define MCP_BUKT1 1
#define MCP_FILHIT00 0
#define MCP_FILHIT21 2
#define MCP_FILHIT11 1
#define MCP_FILHIT10 0

/**
 * @brief RXBnSIDL
*/
#define MCP_IDE 3

/**
 * @brief speed 16M
*/

#define MCP_16MHz_1000kBPS_CNF1 (0x00)
#define MCP_16MHz_1000kBPS_CNF2 (0xD0)
#define MCP_16MHz_1000kBPS_CNF3 (0x82)

#define MCP_16MHz_500kBPS_CNF1 (0x00)
#define MCP_16MHz_500kBPS_CNF2 (0xF0)
#define MCP_16MHz_500kBPS_CNF3 (0x86)

#define MCP_16MHz_250kBPS_CNF1 (0x41)
#define MCP_16MHz_250kBPS_CNF2 (0xF1)
#define MCP_16MHz_250kBPS_CNF3 (0x85)

#define MCP_16MHz_200kBPS_CNF1 (0x01)
#define MCP_16MHz_200kBPS_CNF2 (0xFA)
#define MCP_16MHz_200kBPS_CNF3 (0x87)

#define MCP_16MHz_125kBPS_CNF1 (0x03)
#define MCP_16MHz_125kBPS_CNF2 (0xF0)
#define MCP_16MHz_125kBPS_CNF3 (0x86)

#define MCP_16MHz_100kBPS_CNF1 (0x03)
#define MCP_16MHz_100kBPS_CNF2 (0xFA)
#define MCP_16MHz_100kBPS_CNF3 (0x87)

#define MCP_16MHz_95kBPS_CNF1 (0x03)
#define MCP_16MHz_95kBPS_CNF2 (0xAD)
#define MCP_16MHz_95kBPS_CNF3 (0x07)

#define MCP_16MHz_83k3BPS_CNF1 (0x03)
#define MCP_16MHz_83k3BPS_CNF2 (0xBE)
#define MCP_16MHz_83k3BPS_CNF3 (0x07)

#define MCP_16MHz_80kBPS_CNF1 (0x03)
#define MCP_16MHz_80kBPS_CNF2 (0xFF)
#define MCP_16MHz_80kBPS_CNF3 (0x87)

#define MCP_16MHz_50kBPS_CNF1 (0x07)
#define MCP_16MHz_50kBPS_CNF2 (0xFA)
#define MCP_16MHz_50kBPS_CNF3 (0x87)

#define MCP_16MHz_40kBPS_CNF1 (0x07)
#define MCP_16MHz_40kBPS_CNF2 (0xFF)
#define MCP_16MHz_40kBPS_CNF3 (0x87)

#define MCP_16MHz_33kBPS_CNF1 (0x09)
#define MCP_16MHz_33kBPS_CNF2 (0xBE)
#define MCP_16MHz_33kBPS_CNF3 (0x07)

#define MCP_16MHz_31k25BPS_CNF1 (0x0F)
#define MCP_16MHz_31k25BPS_CNF2 (0xF1)
#define MCP_16MHz_31k25BPS_CNF3 (0x85)

#define MCP_16MHz_25kBPS_CNF1 (0X0F)
#define MCP_16MHz_25kBPS_CNF2 (0XBA)
#define MCP_16MHz_25kBPS_CNF3 (0X07)

#define MCP_16MHz_20kBPS_CNF1 (0x0F)
#define MCP_16MHz_20kBPS_CNF2 (0xFF)
#define MCP_16MHz_20kBPS_CNF3 (0x87)

#define MCP_16MHz_10kBPS_CNF1 (0x1F)
#define MCP_16MHz_10kBPS_CNF2 (0xFF)
#define MCP_16MHz_10kBPS_CNF3 (0x87)

#define MCP_16MHz_5kBPS_CNF1 (0x3F)
#define MCP_16MHz_5kBPS_CNF2 (0xFF)
#define MCP_16MHz_5kBPS_CNF3 (0x87)

#define MCP_16MHz_666kBPS_CNF1 (0x00)
#define MCP_16MHz_666kBPS_CNF2 (0xA0)
#define MCP_16MHz_666kBPS_CNF3 (0x04)


/**
 * @brief speed 8M
*/

#define MCP_8MHz_1000kBPS_CNF1 (0x00)
#define MCP_8MHz_1000kBPS_CNF2 (0x80)
#define MCP_8MHz_1000kBPS_CNF3 (0x00)

#define MCP_8MHz_500kBPS_CNF1 (0x00)
#define MCP_8MHz_500kBPS_CNF2 (0x90)
#define MCP_8MHz_500kBPS_CNF3 (0x02)

#define MCP_8MHz_250kBPS_CNF1 (0x00)
#define MCP_8MHz_250kBPS_CNF2 (0xb1)
#define MCP_8MHz_250kBPS_CNF3 (0x05)

#define MCP_8MHz_200kBPS_CNF1 (0x00)
#define MCP_8MHz_200kBPS_CNF2 (0xb4)
#define MCP_8MHz_200kBPS_CNF3 (0x06)

#define MCP_8MHz_125kBPS_CNF1 (0x01)
#define MCP_8MHz_125kBPS_CNF2 (0xb1)
#define MCP_8MHz_125kBPS_CNF3 (0x05)

#define MCP_8MHz_100kBPS_CNF1 (0x01)
#define MCP_8MHz_100kBPS_CNF2 (0xb4)
#define MCP_8MHz_100kBPS_CNF3 (0x06)

#define MCP_8MHz_80kBPS_CNF1 (0x01)
#define MCP_8MHz_80kBPS_CNF2 (0xbf)
#define MCP_8MHz_80kBPS_CNF3 (0x07)

#define MCP_8MHz_50kBPS_CNF1 (0x03)
#define MCP_8MHz_50kBPS_CNF2 (0xb4)
#define MCP_8MHz_50kBPS_CNF3 (0x06)

#define MCP_8MHz_40kBPS_CNF1 (0x03)
#define MCP_8MHz_40kBPS_CNF2 (0xbf)
#define MCP_8MHz_40kBPS_CNF3 (0x07)

#define MCP_8MHz_31k25BPS_CNF1 (0x07)
#define MCP_8MHz_31k25BPS_CNF2 (0xa4)
#define MCP_8MHz_31k25BPS_CNF3 (0x04)

#define MCP_8MHz_20kBPS_CNF1 (0x07)
#define MCP_8MHz_20kBPS_CNF2 (0xbf)
#define MCP_8MHz_20kBPS_CNF3 (0x07)

#define MCP_8MHz_10kBPS_CNF1 (0x0f)
#define MCP_8MHz_10kBPS_CNF2 (0xbf)
#define MCP_8MHz_10kBPS_CNF3 (0x07)

#define MCP_8MHz_5kBPS_CNF1 (0x1f)
#define MCP_8MHz_5kBPS_CNF2 (0xbf)
#define MCP_8MHz_5kBPS_CNF3 (0x07)      /* Sample point at 80% */

/**
 * @brief Operating modes of mcp2515 chip.
*/
typedef enum MCP_CAN_MODE{ mcp_normal_mode=0, mcp_sleep_mode=1, mcp_loopback_mode=2, mcp_listen_only_mode=3, mcp_configuration_mode=4 } MCP_CAN_MODE;

/**
 * @brief Error codes for mcp2515 chip.
*/
typedef enum MCP_CAN_TX_ERROR{ mcp_no_error_tx=0, mcp_tx_lost_arbitration=1, mcp_tx_message_error=2 } MCP_CAN_TX_ERROR;

/**
 * @brief Can frame types.
*/
typedef enum CAN_FRAME_TYPE{ can_standard=0, can_extended=1, can_data_frame=2, can_remote_frame=3 }CAN_FRAME_TYPE;

typedef struct CAN_FRAME
{
	CAN_FRAME_TYPE type;
	uint8_t isRemote;
	uint32_t ID;
	uint8_t DLC;
	unsigned char DATA[8];
}CAN_FRAME;



/**
 * @brief The following macro enables the intialization of SPI port by the init API itself. If you do not want this then, disable 
 * comment the following line.
*/
//#define AUTO_SPI_INITIALIZATION

/**
 * @brief The following macro defines the chip frequency in Hz.
*/
#define MCP_CHIP_FREQ 8000000



/**
 * 	FUNCTIONS
 */

MCP_CAN_MODE canGetMode(void);

void canRequestMode(MCP_CAN_MODE);

void canSetBitTiming(unsigned char, unsigned char, unsigned char);

void canBegin(void*, uint16_t);

uint8_t canGetTEC(void);

uint8_t canGetREC(void);

void canChipReset(void);

uint8_t canIsFreeTX(uint8_t);

uint8_t canSetPriorityTX(uint8_t, uint8_t);

uint8_t canSetSID_TX(uint8_t, uint16_t);

uint8_t canSetEID_TX(uint8_t, uint32_t);

void canSetTXREQ(uint8_t);

void canRequestTransmission_wiRTS(uint8_t);

uint8_t canTransmit(uint8_t, uint8_t, unsigned char [8]);

uint8_t canTransmit_wSID(uint8_t, uint16_t, uint8_t, unsigned char[8]);

uint8_t canTransmit_wEID(uint8_t, uint32_t, uint8_t, unsigned char[8]);

uint8_t canRemoteTransmit_wSID(uint8_t, uint16_t);

uint8_t canRemoteTransmit_wEID(uint8_t, uint32_t);

MCP_CAN_TX_ERROR canGetErrorTX(uint8_t);

void canClearMessageError(void);

void canAbortTX(uint8_t);

void canEnableFilterRX(uint8_t);

void canDisableFilterRX(uint8_t);

void canEnableRX(uint8_t);

uint8_t canIsFilledRX(uint8_t);

void canSetMaskRX(uint8_t, uint32_t);

void canSetFilterRX(uint8_t, CAN_FRAME_TYPE, uint32_t);

CAN_FRAME canGetFrame_wID(uint8_t);

void canEnableRXInterrupts(void);

_Bool mcpCanReceive(CAN_FRAME *);

_Bool mcpCanSend(CAN_FRAME);

#endif
