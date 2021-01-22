/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2020-11-12 15:21:28
 * @LastEditTime: 2021-01-22 11:50:07
 * @Description: 
 */

#ifndef _TOUCHPANEL_H_
#define _TOUCHPANEL_H_

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "AX58100_Config.h"




//  #define SPIx                           SPI1
//  #define SPIx_CLK                       RCC_APB2Periph_SPI1
//  #define SPIx_CLK_INIT                  RCC_APB2PeriphClockCmd
//
//  #define SPIx_SCK_PIN                   GPIO_Pin_5
//  #define SPIx_SCK_GPIO_PORT             GPIOA
//  #define SPIx_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOA
//  #define SPIx_SCK_SOURCE                GPIO_PinSource5
//  #define SPIx_SCK_AF                    GPIO_AF_SPI1
//
//  #define SPIx_MISO_PIN                  GPIO_Pin_6
//  #define SPIx_MISO_GPIO_PORT            GPIOA
//  #define SPIx_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOA
//  #define SPIx_MISO_SOURCE               GPIO_PinSource6
//  #define SPIx_MISO_AF                   GPIO_AF_SPI1
//
//  #define SPIx_MOSI_PIN                  GPIO_Pin_7
//  #define SPIx_MOSI_GPIO_PORT            GPIOA
//  #define SPIx_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOA
//  #define SPIx_MOSI_SOURCE               GPIO_PinSource7
//  #define SPIx_MOSI_AF                   GPIO_AF_SPI1

	#define DESELECT_SPI 		 HAL_GPIO_WritePin(GPIOE, AX58100_CS_Pin, GPIO_PIN_SET);
	#define SELECT_SPI 			 HAL_GPIO_WritePin(GPIOE, AX58100_CS_Pin, GPIO_PIN_RESET);
//	#define DESELECT_SPI 		 GPIOG->BSRRL = GPIO_Pin_12
//	#define SELECT_SPI 			 GPIOG->BSRRH = GPIO_Pin_12


	#define CSLOW()      SELECT_SPI
	#define CSHIGH()     DESELECT_SPI

	#define SPIWriteByte SPIWrite
	#define SPIReadByte() SPIRead()



	// *****************************************************************************
	// *****************************************************************************
	// Section: File Scope or Global Data Types
	// *****************************************************************************
	// *****************************************************************************
	#define CMD_SERIAL_READ 	0x02
	#define CMD_SERIAL_WRITE 	0x04

	#define CMD_FAST_READ 0x0B
	#define CMD_DUAL_OP_READ 0x3B
	#define CMD_DUAL_IO_READ 0xBB
	#define CMD_QUAD_OP_READ 0x6B
	#define CMD_QUAD_IO_READ 0xEB

	#define CMD_DUAL_DATA_WRITE 0x32
	#define CMD_DUAL_ADDR_DATA_WRITE 0xB2
	#define CMD_QUAD_DATA_WRITE 0x62
	#define CMD_QUAD_ADDR_DARA_WRITE 0xE2

	#define CMD_SERIAL_READ_DUMMY 0
	#define CMD_FAST_READ_DUMMY 1
	#define CMD_DUAL_OP_READ_DUMMY 1
	#define CMD_DUAL_IO_READ_DUMMY 2
	#define CMD_QUAD_OP_READ_DUMMY 1
	#define CMD_QUAD_IO_READ_DUMMY 4
	#define CMD_SERIAL_WRITE_DUMMY 0XFF
	#define CMD_DUAL_DATA_WRITE_DUMMY 0
	#define CMD_DUAL_ADDR_DATA_WRITE_DUMMY 0
	#define CMD_QUAD_DATA_WRITE_DUMMY 0
	#define CMD_QUAD_ADDR_DARA_WRITE_DUMMY 0

	#define ESC_CSR_CMD_REG		0x304
	#define ESC_CSR_DATA_REG	0x300
	#define ESC_WRITE_BYTE 		0x80
	#define ESC_READ_BYTE 		0xC0
	#define ESC_CSR_BUSY		0x80

	
//
//typedef union
//{
//	uint32_t Val;
//	uint8_t v[4];
//	uint16_t w[2];
//	struct
//	{
//		uint8_t LB;
//		uint8_t HB;
//		uint8_t UB;
//		uint8_t MB;
//	}byte;
//}UINT32_VAL;
//
//
//typedef union
//{
//	uint16_t Val;
//	struct
//	{
//		uint8_t LB;
//		uint8_t HB;
//	}byte;
//}UINT16_VAL;



/* Private function prototypes -----------------------------------------------*/				
void SPI1_GPIO_Init(void);	
uint8_t WR_CMD (uint8_t cmd)  ;
void ADC_GPIO_Configuration(void);
void ADC_Configuration(void);
void NVIC_Configuration(void);
void TIM_Configuration(uint8_t period)	;
void EXTI1_Configuration(void);
void EXTI2_Configuration(void);
void EXTI3_Configuration(void);
void SPIReadDRegister(uint8_t *ReadBuffer, uint16_t Address, uint16_t Count);
void SPIWriteRegister( uint8_t *WriteBuffer, uint16_t Address, uint16_t Count);
uint32_t SPIReadDWord (uint16_t Address);
void SPIWriteDWord (uint16_t Address, uint32_t Val);


void HW_SPI_Read(HW_SPI_OBJECT* pSpiObj, UINT8 *pBuf, UINT16 Addr, UINT16 ByteLen);

void mem_test(void);
#endif

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/


