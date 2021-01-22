/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2020-11-30 10:46:30
 * @LastEditTime: 2020-12-04 14:59:32
 * @Description: 
 */

#ifndef DRIVER_I2C_EEPROM_I2C_EEPROM_H_
#define DRIVER_I2C_EEPROM_I2C_EEPROM_H_

#include <stdint.h>
#include <stdbool.h>
#include "EEPROM_DATA_TYPE.h"
#include "TestDataDef.h"

void EEPROM_Test(I2C_EEPROM_t* EEPROM);

void eeprom_12c_test(Test_t* mpData);
void eeprom_12c_test_it(Test_t* mpData);
void eeprom_12c_test_dma(Test_t* mpData);

void EEPROM_ReadPage(I2C_EEPROM_t* EEPROM, uint8_t PageNum, EEPROM_RW_MODE_t RwMode);
void EEPROM_ReadAll(I2C_EEPROM_t* EEPROM, EEPROM_RW_MODE_t RwMode);

void EEPROM_WritePage(I2C_EEPROM_t* EEPROM, uint8_t PageNum, EEPROM_RW_MODE_t RwMode);
void EEPROM_WriteAll(I2C_EEPROM_t* EEPROM,EEPROM_RW_MODE_t RwMode);

bool EEPROM_CheckSumAll(I2C_EEPROM_t* EEPROM);
bool EEPROM_CheckSumPage(I2C_EEPROM_t* EEPROM);

void EEPROM_CheckSumCalculate_All(I2C_EEPROM_t* EEPROM);
void EEPROM_CheckSumCalculate_Page(I2C_EEPROM_t* EEPROM);


#endif /* DRIVER_I2C_EEPROM_I2C_EEPROM_H_ */
