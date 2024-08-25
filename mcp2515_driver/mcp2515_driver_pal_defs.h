/**
 * @author Ashutosh Singh Parmar
 * @file mcp2515_driver_pal_defs.h
 * @brief This file contains all the required type definitions.
*/
#ifndef MCP2515_DRIVER_PAL_DEFS
#define MCP2515_DRIVER_PAL_DEFS

/**
 * Include Platform specfic header files over here.
 * 
 * Define any custom types below (if required).
*/

#define MSB_FIRST 1
#define LSB_FIRST 0

#define IDLE_HIGH 1
#define IDLE_LOW 0

#define LEADING_EDGE 1
#define TRAILING_EDGE 0

#include <xc.h>
#include <string.h>
//#include "../mcc_generated_files/spi1.h"
#include "../mcc_generated_files/spi.h"

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 16000000
#endif

#ifndef _BV
#define _BV(x)   (1 << (x)) 
#endif

/**
 * If the platform does not support types - 1. uint8_t, uint16_t, uin32_t then uncomment and stuitably modify the following lines.
 * 
*/
// typedef unsigned char uint8_t;
// typedef unigend short int uint16_t;
// typedef unsigned int uint32_t;
// typedef unsigned long uin64_t;

#endif