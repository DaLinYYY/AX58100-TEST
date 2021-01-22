/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2020-11-30 13:54:40
 * @LastEditTime: 2021-01-22 10:20:32
 * @Description: 
 */


#ifndef TESTTYPEDEF_H_
#define TESTTYPEDEF_H_


#include <EEPROM_DATA_TYPE.h>
#include "stdint.h"
#include "stdbool.h"
#include "AX58100_Config.h"

/************************************！！EXTENSION！！***********************************/
#if 1
#define __EXTENSION __extension__
typedef union
{
	uint32_t Val;
	uint16_t w[2];
    uint8_t  v[4];
    struct
    {
    	uint16_t LW;
    	uint16_t HW;
    } word;
    struct
    {
    	uint8_t LB;
    	uint8_t HB;
    	uint8_t UB;
    	uint8_t MB;
    } byte;
    struct
    {
    	uint16_t low;
    	uint16_t high;
    }wordUnion;
    struct
    {
        __EXTENSION uint8_t b0:1;
        __EXTENSION uint8_t b1:1;
        __EXTENSION uint8_t b2:1;
        __EXTENSION uint8_t b3:1;
        __EXTENSION uint8_t b4:1;
        __EXTENSION uint8_t b5:1;
        __EXTENSION uint8_t b6:1;
        __EXTENSION uint8_t b7:1;
        __EXTENSION uint8_t b8:1;
        __EXTENSION uint8_t b9:1;
        __EXTENSION uint8_t b10:1;
        __EXTENSION uint8_t b11:1;
        __EXTENSION uint8_t b12:1;
        __EXTENSION uint8_t b13:1;
        __EXTENSION uint8_t b14:1;
        __EXTENSION uint8_t b15:1;
        __EXTENSION uint8_t b16:1;
        __EXTENSION uint8_t b17:1;
        __EXTENSION uint8_t b18:1;
        __EXTENSION uint8_t b19:1;
        __EXTENSION uint8_t b20:1;
        __EXTENSION uint8_t b21:1;
        __EXTENSION uint8_t b22:1;
        __EXTENSION uint8_t b23:1;
        __EXTENSION uint8_t b24:1;
        __EXTENSION uint8_t b25:1;
        __EXTENSION uint8_t b26:1;
        __EXTENSION uint8_t b27:1;
        __EXTENSION uint8_t b28:1;
        __EXTENSION uint8_t b29:1;
        __EXTENSION uint8_t b30:1;
        __EXTENSION uint8_t b31:1;
    } bits;
} UINT32_VAL;
typedef union
{
	uint16_t Val;
    uint8_t v[2];
    struct
    {
        uint8_t LB;
        uint8_t HB;
    } byte;
    struct
    {
        __EXTENSION uint8_t b0:1;
        __EXTENSION uint8_t b1:1;
        __EXTENSION uint8_t b2:1;
        __EXTENSION uint8_t b3:1;
        __EXTENSION uint8_t b4:1;
        __EXTENSION uint8_t b5:1;
        __EXTENSION uint8_t b6:1;
        __EXTENSION uint8_t b7:1;
        __EXTENSION uint8_t b8:1;
        __EXTENSION uint8_t b9:1;
        __EXTENSION uint8_t b10:1;
        __EXTENSION uint8_t b11:1;
        __EXTENSION uint8_t b12:1;
        __EXTENSION uint8_t b13:1;
        __EXTENSION uint8_t b14:1;
        __EXTENSION uint8_t b15:1;
    } bits;
} UINT16_VAL, UINT16_BITS;
/***********************************************************************/
#endif

/************************************__EEPROM__**********************************/

/************************************__TEST__**********************************/
typedef struct
{
	uint8_t								Index;
	I2C_EEPROM_t*						EEPROM;
	I2C_TEST_t*							Test;
    HW_SPI_OBJECT*                      HWSpiEsc;
    HW_SPI_OBJECT*                      HWSpiFun;
} Test_t;



#endif /* TESTTYPEDEF_H_ */
