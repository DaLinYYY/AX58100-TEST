/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2020-11-30 13:54:40
 * @LastEditTime: 2021-01-22 14:47:12
 * @Description: 
 */

#include <stddef.h>
#include <string.h>
#include "TestDataDef.h"
#include "TestTypedef.h"
#include "main.h"
#include "i2c.h"



/********Static variable definition********/

static I2C_EEPROM_t 		EEPROM_DEFAULT_PARAM;
static I2C_TEST_t			IIC_DEFAULT_PARAM; 
static HW_SPI_OBJECT		HWSPIESC_DEFAULT_PARAM;
static HW_SPI_OBJECT		HWSPIFUN_DEFAULT_PARAM;

/********Global variable definition********/
Test_t TEST_PARAM = {	
	.EEPROM             = &EEPROM_DEFAULT_PARAM,
	.Test				= &IIC_DEFAULT_PARAM,
	.HWSpiEsc			= &HWSPIESC_DEFAULT_PARAM,
	.HWSpiFun			= &HWSPIFUN_DEFAULT_PARAM
};

//Test_t* pData = &TEST_PARAM;
Test_t* pTest = &TEST_PARAM;



/* NAMING CONSTANT DECLARATIONS */
HW_SPI_IO_CONFIG HW_EscSpiIoCfig = {
  .pInstance              = HW_SPI_ESC_INSTANCE,
  .AlterFunc              = HW_SPI_ESC_GPIO_AF,

  .pCsPort                = HW_SPI_ESC_CS_PORT,
  .CsPin                  = HW_SPI_ESC_CS_PIN,
  .pClkPort               = HW_SPI_ESC_SCLK_PORT,
  .ClkPin                 = HW_SPI_ESC_SCLK_PIN,
  .pMisoPort              = HW_SPI_ESC_MISO_PORT,
  .MisoPin                = HW_SPI_ESC_MISO_PIN,
  .pMosiPort              = HW_SPI_ESC_MOSI_PORT,
  .MosiPin                = HW_SPI_ESC_MOSI_PIN,

  .pIntrPort              = HW_SPI_ESC_INT_PORT,
  .IntrPin                = HW_SPI_ESC_INT_PIN,
  .IntrIrq                = HW_SPI_ESC_INT_IRQ,

  .IntrPrePrio            = HW_SPI_ESC_INT_NVIC_PREEMPTION_PRIORITY,
  .IntrSubPrio            = HW_SPI_ESC_INT_NVIC_SUB_PRIORITY,
  
  .Enable3BytesAddr       = 1,
  .Baudrate               = SPI_BAUDRATEPRESCALER_16,
};

HW_SPI_IO_CONFIG HW_FunSpiIoCfig = {
  .pInstance              = HW_SPI_ESC_INSTANCE,
  .AlterFunc              = HW_SPI_ESC_GPIO_AF,

  .pCsPort                = HW_SPI_FUN_CS_PORT,
  .CsPin                  = HW_SPI_FUN_CS_PIN,
  .pClkPort               = HW_SPI_ESC_SCLK_PORT,
  .ClkPin                 = HW_SPI_ESC_SCLK_PIN,
  .pMisoPort              = HW_SPI_ESC_MISO_PORT,
  .MisoPin                = HW_SPI_ESC_MISO_PIN,
  .pMosiPort              = HW_SPI_ESC_MOSI_PORT,
  .MosiPin                = HW_SPI_ESC_MOSI_PIN,

  .pIntrPort              = HW_SPI_ESC_INT_PORT,
  .IntrPin                = HW_SPI_ESC_INT_PIN,
  .IntrIrq                = HW_SPI_ESC_INT_IRQ,

  .IntrPrePrio            = HW_SPI_ESC_INT_NVIC_PREEMPTION_PRIORITY,
  .IntrSubPrio            = HW_SPI_ESC_INT_NVIC_SUB_PRIORITY,

  .Enable3BytesAddr       = 0,
  .Baudrate               = SPI_BAUDRATEPRESCALER_16,
};
/**
 * @Date: 2020-11-30 14:11:32
 * @Author: YangSL
 * @Description: Global variable initialization
 */
void SYSTEM_VariableInitialize(Test_t* mpData)
{
	/* Initializa the EEPROM variable */
	memset(mpData->EEPROM, 0, sizeof(*mpData->EEPROM));

	memset(mpData->Test, 0, sizeof(*mpData->Test));

	memset(mpData->HWSpiEsc, 0, sizeof(*mpData->HWSpiEsc));

	memset(mpData->HWSpiFun, 0, sizeof(*mpData->HWSpiFun));


}

/**
 * @Date: 2020-11-30 14:11:35
 * @Author: YangSL
 * @Description: Global variable configuration
 */
void SYSTEM_VariableConfiguration(Test_t* mpData)
{
	uint8_t index = 0;

	mpData->Index								=	0x5A;

	// mpData->EEPROM->EepromDeviceAddress  	= 	0;
	// mpData->EEPROM->EepromMaxPage			=	0;

//	mpData->EEPROM->EepromHi2c					=	hi2c1;
//	mpData->EEPROM->EepromMaxPage				=	16;
//	mpData->EEPROM->EepromOnePageByte			=	16;
//
//	for(index = 0; index < 16; index++)
//		mpData->EEPROM->EepromWritePage[index] = index;
//	for(index = 0; index < 255; index++)
//	{
//		mpData->EEPROM->EepromWriteBuff[index] =index * index;     /* WriteBuffer Initialization */
//	}

	mpData->HWSpiEsc->pIoCfg  	=	&HW_EscSpiIoCfig;
	mpData->HWSpiFun->pIoCfg  	=	&HW_FunSpiIoCfig;

	
}
