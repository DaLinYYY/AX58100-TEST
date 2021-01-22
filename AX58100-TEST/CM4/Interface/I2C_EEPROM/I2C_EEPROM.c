/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2020-11-30 10:46:30
 * @LastEditTime: 2020-12-04 15:15:34
 * @Description: 
 */


#include <I2C_EEPROM.h>
#include "i2c.h"
#include "TestDataDef.h"
#include "main.h"


void EEPROM_Test(I2C_EEPROM_t* EEPROM)
{
	static index_count = 0;
	uint8_t index = 0;
	bool flag = false;

	for(index = 1; index < 16; index++)
		EEPROM->EepromWritePage[index] = index * index + index_count;
	
	EEPROM_CheckSumCalculate_Page(EEPROM);

	EEPROM_WritePage(EEPROM, 0, EEPROM_RW_MODE_DMA);

	flag = EEPROM_CheckSumPage(EEPROM);
}

/**
  * Master以阻塞模式传输大量数据
  * HAL_StatusTypeDef HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)
  * HAL_I2C_Mem_Write(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout)
  * HAL_I2C_Mem_Read(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout)
  */
/**
 * @Date: 2020-11-30 14:11:09
 * @Author: YangSL
 * @Description: 
 */
void eeprom_12c_test(Test_t* mpData)
{
	uint16_t i = 0;

	/*write data init*/
	 for(i=0; i<255; i++)
	 {
	   mpData->EEPROM->EepromWriteBuff[i] =i;     /* WriteBuffer Initialization */
	 }
	/*write time test */
	HAL_GPIO_WritePin(TestIO_1_GPIO_Port, TestIO_1_Pin, GPIO_PIN_SET);
	for(i=0; i<256; i=i+16)
	{
		if (HAL_I2C_Mem_Write(&mpData->EEPROM->EepromHi2c, EEPROM_WRITE, i, I2C_MEMADD_SIZE_8BIT,mpData->EEPROM->EepromWriteBuff + i, 16, 10000) != HAL_OK);
		{
			while(HAL_I2C_IsDeviceReady(&mpData->EEPROM->EepromHi2c, 0xA1, 5, 0xffff) != HAL_OK);
		}
		HAL_Delay(5);
	}
	HAL_GPIO_WritePin(TestIO_1_GPIO_Port, TestIO_1_Pin, GPIO_PIN_RESET);
	HAL_Delay(5);
	/*read time test*/
	HAL_GPIO_WritePin(TestIO_1_GPIO_Port, TestIO_1_Pin, GPIO_PIN_SET);
	HAL_I2C_Mem_Read(&mpData->EEPROM->EepromHi2c, EEPROM_READ, 0, I2C_MEMADD_SIZE_8BIT,mpData->EEPROM->EepromReadBuff, 256, 10000);
	HAL_GPIO_WritePin(TestIO_1_GPIO_Port, TestIO_1_Pin, GPIO_PIN_RESET);
}

void eeprom_12c_test_it(Test_t* mpData)
{

}

/**
  * @brief  Write an amount of data in non-blocking mode with DMA to a specific memory address
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  DevAddress Target device address: The device 7 bits address value
  *         in datasheet must be shifted to the left before calling the interface
  * @param  MemAddress Internal memory address
  * @param  MemAddSize Size of internal memory address
  * @param  pData Pointer to data buffer
  * @param  Size Amount of data to be sent
 *  @API : HAL_I2C_Mem_Write_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size)
 *  @API : HAL_I2C_Mem_Read_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size)
 */
void eeprom_12c_test_dma(Test_t* mpData)
{
	uint16_t i = 0;
	/*write data init*/
	// for(i=0; i<255; i++)
	// {
	//   mpData->EEPROM->EepromWriteBuff[i] =i*i + i;     /* WriteBuffer Initialization */
	// }
	/*write time test */
	HAL_GPIO_WritePin(TestIO_1_GPIO_Port, TestIO_1_Pin, GPIO_PIN_SET);
	for(i=0; i<256; i=i+16)
	{
		if (HAL_I2C_Mem_Write_DMA(&hi2c1, EEPROM_WRITE, i, I2C_MEMADD_SIZE_8BIT,mpData->EEPROM->EepromWriteBuff + i, 16) != HAL_OK)
		{
			while(HAL_I2C_IsDeviceReady(&hi2c1, 0xA1, 5, 0xffff) != HAL_OK);
		}
		HAL_Delay(5);
	}
	HAL_GPIO_WritePin(TestIO_1_GPIO_Port, TestIO_1_Pin, GPIO_PIN_RESET);
	HAL_Delay(5);
	/*read time test*/
	HAL_GPIO_WritePin(TestIO_1_GPIO_Port, TestIO_1_Pin, GPIO_PIN_SET);
	HAL_I2C_Mem_Read_DMA(&hi2c1, EEPROM_READ, 0, I2C_MEMADD_SIZE_8BIT,mpData->EEPROM->EepromReadBuff, 256);
	HAL_GPIO_WritePin(TestIO_1_GPIO_Port, TestIO_1_Pin, GPIO_PIN_RESET);
}

/**
 * @Date: 2020-12-04 14:32:39
 * @Author: YangSL
 * @Description: Read a Page, PageNum: Page number
 */
void EEPROM_ReadPage(I2C_EEPROM_t* EEPROM, uint8_t PageNum, EEPROM_RW_MODE_t RwMode)
{
	if(RwMode == EEPROM_RW_MODE_BLOCKING)
	{
		HAL_I2C_Mem_Read(&EEPROM->EepromHi2c, EEPROM_READ, PageNum * EEPROM->EepromOnePageByte, I2C_MEMADD_SIZE_8BIT,EEPROM->EepromReadPage, EEPROM->EepromOnePageByte, 0xffff);
	}
	if(RwMode == EEPROM_RW_MODE_DMA)
	{
		HAL_I2C_Mem_Read_DMA(&EEPROM->EepromHi2c, EEPROM_READ,PageNum * EEPROM->EepromOnePageByte, I2C_MEMADD_SIZE_8BIT,EEPROM->EepromReadPage, EEPROM->EepromOnePageByte);
	}
}

/**
 * @Date: 2020-12-04 14:45:41
 * @Author: YangSL
 * @Description: Read the entire EEPROM
 */
void EEPROM_ReadAll(I2C_EEPROM_t* EEPROM, EEPROM_RW_MODE_t RwMode)
{
	if(RwMode == EEPROM_RW_MODE_BLOCKING)
	{
		HAL_I2C_Mem_Read(&EEPROM->EepromHi2c, EEPROM_READ, 0, I2C_MEMADD_SIZE_8BIT, EEPROM->EepromReadBuff, EEPROM->EepromOnePageByte * EEPROM->EepromMaxPage, 0xffff);
	}
	if(RwMode == EEPROM_RW_MODE_DMA)
	{
		HAL_I2C_Mem_Read_DMA(&EEPROM->EepromHi2c, EEPROM_READ, 0, I2C_MEMADD_SIZE_8BIT, EEPROM->EepromReadBuff, EEPROM->EepromOnePageByte * EEPROM->EepromMaxPage);
	}
}

/**
 * @Date: 2020-12-04 11:31:53
 * @Author: YangSL
 * @Description: Write a PAGE data to EEPROM
 */
void EEPROM_WritePage(I2C_EEPROM_t* EEPROM, uint8_t PageNum, EEPROM_RW_MODE_t RwMode)
{
	if(RwMode == EEPROM_RW_MODE_DMA)
	{
		if (HAL_I2C_Mem_Write_DMA(&EEPROM->EepromHi2c, EEPROM_WRITE, PageNum * EEPROM->EepromOnePageByte, I2C_MEMADD_SIZE_8BIT,EEPROM->EepromWritePage, EEPROM->EepromOnePageByte) != HAL_OK)
		{
			while(HAL_I2C_IsDeviceReady(&EEPROM->EepromHi2c, EEPROM_READ, 5, 0xffff) != HAL_OK);
		}
	}
	if(RwMode == EEPROM_RW_MODE_BLOCKING)
	{
		if (HAL_I2C_Mem_Write(&EEPROM->EepromHi2c, EEPROM_WRITE, PageNum * EEPROM->EepromOnePageByte, I2C_MEMADD_SIZE_8BIT,EEPROM->EepromWritePage, EEPROM->EepromOnePageByte, 0xfff) != HAL_OK)
		{
			while(HAL_I2C_IsDeviceReady(&EEPROM->EepromHi2c, EEPROM_READ, 5, 0xffff) != HAL_OK);
		}	
	}
}

/**
 * @Date: 2020-12-04 14:04:16
 * @Author: YangSL
 * @Description: Write block the EEPROM
 */
void EEPROM_WriteAll(I2C_EEPROM_t* EEPROM,EEPROM_RW_MODE_t RwMode)
{
	uint16_t index = 0;

	if(RwMode == EEPROM_RW_MODE_DMA)
	{
		for(index = 0; index < EEPROM->EepromMaxPage * EEPROM->EepromOnePageByte; index = index + 16)
		{
			if (HAL_I2C_Mem_Write_DMA(&EEPROM->EepromHi2c, EEPROM_WRITE, index , I2C_MEMADD_SIZE_8BIT,EEPROM->EepromWriteBuff + index, EEPROM->EepromOnePageByte) != HAL_OK)
			{
				while(HAL_I2C_IsDeviceReady(&EEPROM->EepromHi2c, EEPROM_READ, 5, 0xffff) != HAL_OK);
			}
			HAL_Delay(5);
		}
	}
	if(RwMode == EEPROM_RW_MODE_BLOCKING)
	{
		for(index = 0; index < EEPROM->EepromMaxPage * EEPROM->EepromOnePageByte; index = index + 16)
		{
			if (HAL_I2C_Mem_Write(&EEPROM->EepromHi2c, EEPROM_WRITE, index , I2C_MEMADD_SIZE_8BIT,EEPROM->EepromWriteBuff + index, EEPROM->EepromOnePageByte, 0xfff) != HAL_OK)
			{
				while(HAL_I2C_IsDeviceReady(&EEPROM->EepromHi2c, EEPROM_READ, 5, 0xffff) != HAL_OK);
			}
			HAL_Delay(5);
		}
	}
}

/**
 * @Date: 2020-12-04 10:07:18
 * @Author: YangSL
 * @Description: Check the CheckSum throughout EEPROM. CheckSum is placed in the first byte
 */
bool EEPROM_CheckSumAll(I2C_EEPROM_t* EEPROM)
{
	bool ret = false;

	int16_t index = 0;
	uint8_t ReadDataCheckSum = 0;

	/* calculate the data check sum */
	for(index = 1; index < EEPROM->EepromMaxPage*EEPROM->EepromOnePageByte; index++)
		ReadDataCheckSum += EEPROM->EepromReadBuff[index];

	/* judge the check sum result */
	if(EEPROM->EepromReadBuff[0] != ReadDataCheckSum)
		ret = true;
	else
		ret = false;

	return ret;
}

/**
 * @Date: 2020-12-04 10:28:45
 * @Author: YangSL
 * @Description: Check the Checksum of a PAGE. Checksum is placed in the first byte of the PAGE
 */
bool EEPROM_CheckSumPage(I2C_EEPROM_t* EEPROM)
{
	bool ret = false;

	uint16_t index  = 0;
	uint8_t ReadDataCheckSum = 0;

	for(index =  1; index < EEPROM->EepromOnePageByte; index++)
		ReadDataCheckSum += EEPROM->EepromReadPage[index];
	
	if(EEPROM->EepromReadPage[0] != ReadDataCheckSum)
		ret = true;
	else
		ret = false;

	return ret;
}

/**
 * @Date: 2020-12-04 10:47:43
 * @Author: YangSL
 * @Description: Calculates the Checksum of the entire EEPROM, stored in the first byte
 */
void EEPROM_CheckSumCalculate_All(I2C_EEPROM_t* EEPROM)
{
	uint16_t index = 0;
	uint8_t WriteDataCheckSum = 0;

	for(index = 1; index < EEPROM->EepromMaxPage*EEPROM->EepromOnePageByte; index++)
		WriteDataCheckSum += EEPROM->EepromWriteBuff[index];

	EEPROM->EepromWriteBuff[0] = WriteDataCheckSum;
}

/**
 * @Date: 2020-12-04 10:47:39
 * @Author: YangSL
 * @Description: Computes a Page content stored in the first byte
 */
void EEPROM_CheckSumCalculate_Page(I2C_EEPROM_t* EEPROM)
{
	uint8_t index = 0;
	uint8_t WriteDataCheckSum = 0;

	for(index =  1; index < EEPROM->EepromOnePageByte; index++)
		WriteDataCheckSum += EEPROM->EepromWritePage[index];

	EEPROM->EepromWritePage[0] = WriteDataCheckSum;
}
