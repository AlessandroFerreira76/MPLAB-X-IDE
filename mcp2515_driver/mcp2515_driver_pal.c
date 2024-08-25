/**
 * @author Ashutosh Singh Parmar
 * @file mcp2515_driver_pal.c
 * @brief This file contains the platform abstraction layer APIs.
*/

#include "mcp2515_driver_pal.h"

/**
 * @brief This PAL API will be called by core APIs to initialize the SPI port.
 * 
 * @param 
 * 1. void * data : pointer to a custom structure containing initialization information.
 * 2. uint8_t data_direction : Direction of shifting out data - MSB_FIRST or LSB_FIRST.
 * 3. uint8_t idle_level : The idle level of spi port - IDLE_HIGH OR IDLE_LOW.
 * 4. uint8_t shift_iedge : The edge at which data will be shifted out - LEADING or TRAILING.
 * 
 * @return NOTHING
*/
void pal_spi_init(void* data, uint8_t data_direction, uint8_t idle_level, uint8_t shift_edge)
{
    /* !...Platform Specific Code here...! */
}

/**
 * @brief This PAL API will be called by core APIs to select the mcp2515 chip.
 * 
 * @param 
 * NONE
 * 
 * @return NOTHING
*/
extern _Bool useCAN1;

void pal_select_slave(void)
{
    /* !...Platform Specific Code here...! */
        LATC &= ~_BV(_LATC_LATC2_POSN);  
}

/**
 * @brief This PAL API will be called by core APIs to deselect the mcp2515 chip.
 * 
 * @param 
 * NONE
 * 
 * @return NOTHING
*/
void pal_deselect_slave(void)
{
    /* !...Platform Specific Code here...! */
    LATC |= _BV(_LATC_LATC2_POSN);
}

/**
 * @brief This PAL API will be called by core APIs to send a byte over the SPI port.
 * 
 * @param 
 * 1. uint8_t byt : The data byte to send
 * 
 * @return 
 * NOTHING
*/
void pal_spi_send(uint8_t byt)
{
    /* !...Platform Specific Code here...! */
    SPI_Open (SPI_DEFAULT);
    SPI_ExchangeByte(byt);
    SPI_Close();
    /*SPI1_Open (SPI1_DEFAULT);
    SPI1_ExchangeByte(byt);
    SPI1_Close();*/
    //SPI1_Master_TransmitOnly(byt);
}

/**
 * @brief This PAL API will be called by core APIs to send a byte over the SPI port.
 * 
 * @param 
 * NONE
 * 
 * @return 
 * uint8_t : the data byte read over the SPI port.
*/
uint8_t pal_spi_read(void)
{
    uint8_t ret;
    /* !...Platform Specific Code here...! */
    SPI_Open (SPI_DEFAULT);
    ret = SPI_ExchangeByte(0);
    SPI_Close();
    /*SPI1_Open (SPI1_DEFAULT);
    ret = SPI1_ExchangeByte(0);
    SPI1_Close();*/
    return ret;
    //return SPI1_Master_RecieveOnly(0);
}