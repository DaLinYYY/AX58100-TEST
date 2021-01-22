/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2020-11-30 10:46:30
 * @LastEditTime: 2021-01-22 10:54:44
 * @Description: 
 */
#ifndef EEPROM_EEPROM_DATA_TYPE_H_
#define EEPROM_EEPROM_DATA_TYPE_H_

#include "main.h"

enum{
	EEPROM_READ 	= 0xA1,
	EEPROM_WRITE	= 0xA0
};

typedef enum{
	EEPROM_RW_MODE_BLOCKING,
	EEPROM_RW_MODE_TI,
	EEPROM_RW_MODE_DMA
}EEPROM_RW_MODE_t;
/****************************************Typedef*/

/************************************__EEPROM__**********************************/
typedef struct 
{
    I2C_HandleTypeDef EepromHi2c;

//	UINT32_VAL	EepromData32;
	
	uint8_t 	EepromDeviceAddress;
	uint8_t 	EepromPagesAddress;
	uint8_t 	EepromMaxPage;
	uint8_t		EepromOnePageByte;

	uint32_t	EepromTimeoutTimer;
	
	uint8_t		EepromWriteIndex;
	uint8_t		EepromWriteChoke;
	uint8_t		EepromReadIndex;
	uint8_t		EepromReadChoke;

	uint8_t		EepromWriteBuff[256];
	uint8_t		EepromReadBuff[256];

	uint8_t 	EepromWritePage[16];
	uint8_t 	EepromReadPage[16];

}I2C_EEPROM_t;

/************************************__TEST__**********************************/

typedef struct 
{	
	uint32_t 	aaaa;
	uint8_t 	data[64];
	uint8_t		buf[64];
}I2C_TEST_t;




#endif /* EEPROM_EEPROM_DATA_TYPE_H_ */
