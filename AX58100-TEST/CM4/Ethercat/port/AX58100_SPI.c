/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2020-11-12 15:21:28
 * @LastEditTime: 2021-01-22 15:27:43
 * @Description: 
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "ecat_def.h"
#include "AX58100_SPI.h"
#include "AX58100_Hw.h"
#include "spi.h"
#include "TestTypedef.h"
#include "stm32h745xx.h"
/* Private macro -------------------------------------------------------------*/

/* Function ------------------------------------------------------------------*/
static INT32 HW_SPI_TransmitReceive(HW_SPI_OBJECT *pSpiObj, UINT8 *pTxData, UINT8 *pRxData, UINT16 Size, UINT32 Timeout);
/**
 * @Date: 2021-01-20 11:39:00
 * @Author: YangSL
 * @Description: Read and write a bit， ll SPIs read and write at the bottom level
 */
uint8_t WR_CMD(uint8_t cmd)
{
    uint8_t RxData = 0;

    *(uint8_t *)&AX58100_SPI.Instance->TXDR = cmd;
    //	while((SPI4->SR&1<<1)==0);		        //Waiting to send zone empty love
    //	*(uint8_t *)&SPI4->TXDR=cmd;		    //Sends a byte to access the TXDR register at the transfer length
    while ((SPI4->SR & 1 << 12) == 0)
        ; //Wait for a byte to finish receiving

    RxData = *(uint8_t *)&AX58100_SPI.Instance->RXDR;
    //	RxData=*(uint8_t *)&SPI4->RXDR;

    //	SPI4->IFCR|=3<<3;				        //EOTC and TXTFC set 1,clear EOT and TXTFC bit
    //	SPI4->CR1&=~(1<<0);				        //SPE=0,CLOSE SPI2,Will perform state machine reset /FIFO reset and other operations
    return RxData;
}

/**
 * @Date: 2021-01-20 11:38:51
 * @Author: YangSL
 * @Description: 
 */
void SPIWrite(UINT8 data)
{
    WR_CMD(data);
}

/**
 * @Date: 2021-01-20 11:38:44
 * @Author: YangSL
 * @Description: 
 */
UINT8 SPIRead(void)
{
    UINT8 data;
    data = WR_CMD(0);
    return (data);
}

/**
 * @Date: 2021-01-20 11:38:35
 * @Author: YangSL
 * @Description: 
 */
uint32_t SPIReadDWord(uint16_t Address)
{
    UINT32_VAL dwResult;
    UINT16_VAL wAddr;
    uint8_t pTxData[6] = {0};
    uint8_t pRxData[6] = {0};

    wAddr.Val = Address << 3 | CMD_SERIAL_READ;
    //Assert CS line
    pTxData[0] = wAddr.byte.HB;
    pTxData[1] = wAddr.byte.LB;
    CSLOW();
    //Write Command
    //     SPIWriteByte(CMD_SERIAL_READ);
    //Write Address

    //    *(uint8_t *)&SPI4->TXDR=wAddr.byte.HB;
    //    while((SPI4->SR&1<<1)==0);
    //    *(uint8_t *)&SPI4->TXDR=wAddr.byte.LB;
    //    SPIWriteByte(wAddr.byte.HB);
    //    SPIWriteByte(wAddr.byte.LB);

    //    HAL_SPI_Transmit(&AX58100_SPI, wAddr, 2, 1000);
    HAL_SPI_TransmitReceive(&AX58100_SPI, pTxData, pRxData, 6, 1000);
    //Dummy Byte
    //    SPIWriteByte(CMD_SERIAL_READ_DUMMY);
    //    SPIWriteByte(CMD_SERIAL_READ_DUMMY);
    //Read Bytes
    //    while((SPI4->SR&1<<0)==0);
    //    dwResult.byte.LB = *(uint8_t *)&SPI4->RXDR;
    //    while((SPI4->SR&1<<0)==0);
    //    dwResult.byte.HB = *(uint8_t *)&SPI4->RXDR;
    //    while((SPI4->SR&1<<0)==0);
    //    dwResult.byte.UB = *(uint8_t *)&SPI4->RXDR;
    //    while((SPI4->SR&1<<0)==0);
    //    dwResult.byte.MB = *(uint8_t *)&SPI4->RXDR;

    dwResult.byte.LB = pRxData[2];
    dwResult.byte.HB = pRxData[3];
    dwResult.byte.UB = pRxData[4];
    dwResult.byte.MB = pRxData[5];
    //De-Assert CS line
    CSHIGH();

    return dwResult.Val;
}

/**
 * @Date: 2021-01-22 09:58:27
 * @Author: YangSL
 * @Description: 
 */
void HW_SPI_Read(HW_SPI_OBJECT *pSpiObj, UINT8 *pBuf, UINT16 Addr, UINT16 ByteLen)
{
    HW_SPI_IO_CONFIG *pSpiIoCfg = pSpiObj->pIoCfg;
    UINT16 XferLen, AddrTmp, i;
    UINT8 *ptr, DataOffset = 0;
    INT32 ret;

    while (ByteLen)
    {
        AddrTmp = Addr;

        /* Fragmented to specified data length per-section */
        if (ByteLen > HW_SPI_MAX_DATA_FRAGMENT_SIZE)
        {
            XferLen = HW_SPI_MAX_DATA_FRAGMENT_SIZE;
        }
        else
        {
            XferLen = ByteLen;
        }

        /* Set address, command */
        ptr = (UINT8 *)&AddrTmp;
        if (pSpiIoCfg->Enable3BytesAddr)
        {
            pSpiObj->TxBuf[2] = (ptr[1] & 0xe0) | (HW_SPI_READ_WITH_WAIT_CMD << 2);
            AddrTmp = AddrTmp << 3;
            pSpiObj->TxBuf[0] = ptr[1];
            pSpiObj->TxBuf[1] = ptr[0] | HW_SPI_ADDR_EXT_CMD;
            DataOffset = 3;
        }
        else
        {
            AddrTmp = AddrTmp << 3;
            pSpiObj->TxBuf[0] = ptr[1];
            pSpiObj->TxBuf[1] = ptr[0] | HW_SPI_READ_WITH_WAIT_CMD;
            DataOffset = 2;
        }

        /* Set dummy byte */
        pSpiObj->TxBuf[DataOffset] = 0xff;

        /* Set read terminal byte */
        memset(&pSpiObj->TxBuf[DataOffset + 1], 0, XferLen);
        pSpiObj->TxBuf[DataOffset + XferLen] = 0xff;
        DataOffset++;

        ret = HW_SPI_TransmitReceive(pSpiObj, pSpiObj->TxBuf, pSpiObj->RxBuf, DataOffset + XferLen, HW_SPI_XFER_TIMEOUT);
        /* Start read */
        if (ret != 0)
        {
            break;
        }

        /* Store received data */
        for (i = 0; i < XferLen; i++)
        {
            pBuf[i] = pSpiObj->RxBuf[DataOffset + i];
        }

        /* Next section */
        Addr += XferLen;
        pBuf += XferLen;
        ByteLen -= XferLen;
    }

} /* End of HW_SPI_Read() */

static INT32 HW_SPI_DeInit(HW_SPI_OBJECT *pSpiObj)
{
    return 0;
} /* End of HW_SPI_DeInit() */


/**
 * @Date: 2021-01-22 15:27:31
 * @Author: YangSL
 * @Description: 
 */
static INT32 HW_SPI_WaitFlagStateUntilTimeout(HW_SPI_OBJECT *pSpiObj, UINT32 Flag, UINT32 State, UINT32 Timeout, UINT32 Tickstart)
{
    SPI_HandleTypeDef *hspi = &(pSpiObj->Handle);

    while ((__HAL_SPI_GET_FLAG(hspi, Flag) ? SET : RESET) != State)
    {
        if (HW_CheckTimeout(Tickstart, Timeout))
        {
            /* Disable TXE, RXNE and ERR interrupts for the interrupt process */
            __HAL_SPI_DISABLE_IT(hspi, (SPI_IT_TXE | SPI_IT_RXNE | SPI_IT_ERR));

            /* Disable SPI peripheral */
            __HAL_SPI_DISABLE(hspi);
            return -1;
        }
    }
    return 0;
} /* End of HW_SPI_WaitFlagStateUntilTimeout() */


/**
 * @Date: 2021-01-22 15:27:23
 * @Author: YangSL
 * @Description: 
 */
static void HW_SPI_CloseTransfer(SPI_HandleTypeDef *hspi)
{
    uint32_t itflag = hspi->Instance->SR;

    __HAL_SPI_CLEAR_EOTFLAG(hspi);
    __HAL_SPI_CLEAR_TXTFFLAG(hspi);

    /* Disable SPI peripheral */
    __HAL_SPI_DISABLE(hspi);

    /* Disable ITs */
    __HAL_SPI_DISABLE_IT(hspi, (SPI_IT_EOT | SPI_IT_TXP | SPI_IT_RXP | SPI_IT_DXP | SPI_IT_UDR | SPI_IT_OVR | SPI_IT_FRE | SPI_IT_MODF));

    /* Disable Tx DMA Request */
    CLEAR_BIT(hspi->Instance->CFG1, SPI_CFG1_TXDMAEN | SPI_CFG1_RXDMAEN);

    /* Report UnderRun error for non RX Only communication */
    if (hspi->State != HAL_SPI_STATE_BUSY_RX)
    {
        if ((itflag & SPI_FLAG_UDR) != 0UL)
        {
            SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_UDR);
            __HAL_SPI_CLEAR_UDRFLAG(hspi);
        }
    }

    /* Report OverRun error for non TX Only communication */
    if (hspi->State != HAL_SPI_STATE_BUSY_TX)
    {
        if ((itflag & SPI_FLAG_OVR) != 0UL)
        {
            SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_OVR);
            __HAL_SPI_CLEAR_OVRFLAG(hspi);
        }

#if (USE_SPI_CRC != 0UL)
        /* Check if CRC error occurred */
        if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
        {
            if ((itflag & SPI_FLAG_CRCERR) != 0UL)
            {
                SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_CRC);
                __HAL_SPI_CLEAR_CRCERRFLAG(hspi);
            }
        }
#endif /* USE_SPI_CRC */
    }

    /* SPI Mode Fault error interrupt occurred -------------------------------*/
    if ((itflag & SPI_FLAG_MODF) != 0UL)
    {
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_MODF);
        __HAL_SPI_CLEAR_MODFFLAG(hspi);
    }

    /* SPI Frame error interrupt occurred ------------------------------------*/
    if ((itflag & SPI_FLAG_FRE) != 0UL)
    {
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FRE);
        __HAL_SPI_CLEAR_FREFLAG(hspi);
    }

    hspi->TxXferCount = (uint16_t)0UL;
    hspi->RxXferCount = (uint16_t)0UL;
}


/**
 * @Date: 2021-01-22 15:27:15
 * @Author: YangSL
 * @Description: 
 */
static INT32 HW_SPI_TransmitReceive(HW_SPI_OBJECT *pSpiObj, UINT8 *pTxData, UINT8 *pRxData, UINT16 Size, UINT32 Timeout)
{
    HW_SPI_IO_CONFIG *pSpiIoCfg = pSpiObj->pIoCfg;
    SPI_TypeDef *pInst = pSpiObj->Handle.Instance;
    int32_t errorcode = HAL_OK;

    /* Init tickstart for timeout management*/
    uint32_t tickstart = HW_GetTimer();

    uint16_t initial_TxXferCount = Size;
    uint16_t initial_RxXferCount = Size;

    MODIFY_REG(pInst->CR2, SPI_CR2_TSIZE, 0);

    /* Check if the SPI is already enabled */
    if ((pInst->CR1 & SPI_CR1_SPE) == 0)
    {
        /* Enable SPI peripheral */
        pInst->CR1 |= SPI_CR1_SPE;
    }
    pInst->CR1 |= SPI_CR1_CSTART;

    /* CS = low */
    pSpiIoCfg->pCsPort->ODR &= ~(pSpiIoCfg->CsPin);

    /* Transmit and Receive data in 8 Bit mode */
    if (initial_TxXferCount == 0x01)
    {
        *((__IO uint8_t *)&(pInst->TXDR)) = (*pTxData);
        pTxData += sizeof(uint8_t);
        initial_TxXferCount--;
    }

    while ((initial_TxXferCount > 0UL) || (initial_RxXferCount > 0UL))
    {
        /* check TXP flag */
        if ((pInst->SR & SPI_FLAG_TXP) && (initial_TxXferCount > 0UL))
        {
            if (initial_TxXferCount > 3UL)
            {
                *((__IO uint32_t *)&pInst->TXDR) = *((uint32_t *)pTxData);
                pTxData += sizeof(uint32_t);
                initial_TxXferCount -= (uint16_t)4UL;
            }
            else if (initial_TxXferCount > 1UL)
            {
                *((__IO uint16_t *)&pInst->TXDR) = *((uint16_t *)pTxData);
                pTxData += sizeof(uint16_t);
                initial_TxXferCount -= (uint16_t)2UL;
            }
            else
            {
                *((__IO uint8_t *)&pInst->TXDR) = *((uint8_t *)pTxData);
                pTxData += sizeof(uint8_t);
                initial_TxXferCount--;
            }
        }

        /* Wait until RXWNE/FRLVL flag is reset */
        if ((pInst->SR & (SPI_FLAG_RXWNE | SPI_FLAG_FRLVL | SPI_FLAG_RXP)) && (initial_RxXferCount > 0UL))
        {
            if ((pInst->SR & SPI_FLAG_RXWNE) != 0UL)
            {
                (*(uint32_t *)pRxData) = *((__IO uint32_t *)&pInst->RXDR);
                pRxData += sizeof(uint32_t);
                initial_RxXferCount -= (uint16_t)4UL;
            }
            else if ((pInst->SR & SPI_FLAG_FRLVL) > SPI_RX_FIFO_1PACKET)
            {
                (*(uint16_t *)pRxData) = *((__IO uint16_t *)&pInst->RXDR);
                pRxData += sizeof(uint16_t);
                initial_RxXferCount -= (uint16_t)2UL;
            }
            else
            {
                (*(uint8_t *)pRxData) = *((__IO uint8_t *)&pInst->RXDR);
                pRxData += sizeof(uint8_t);
                initial_RxXferCount--;
            }
        }

        /* Timeout management */
        if (HW_CheckTimeout(tickstart, Timeout))
        {
            errorcode = -2;
            goto HW_SPI_XferError;
        }
    }

    /* Wait until TXE flag */
    if (HW_SPI_WaitFlagStateUntilTimeout(pSpiObj, SPI_FLAG_TXC, SET, Timeout, tickstart) < 0)
    {
        errorcode = -3;
        goto HW_SPI_XferError;
    }

HW_SPI_XferError:
    /* Clear overrun flag in 2 Lines communication mode because received is not read */
    pInst->IFCR |= SPI_IFCR_OVRC | SPI_IFCR_UDRC | SPI_IFCR_EOTC | SPI_IFCR_TIFREC;

    /* CS = high */
    pSpiIoCfg->pCsPort->ODR |= pSpiIoCfg->CsPin;

    return errorcode;
} /* End of HW_SPI_TransmitReceive() */

/**
 * @Date: 2021-01-20 11:38:20
 * @Author: YangSL
 * @Description: 
 */
void SPISendAddr(uint16_t Address)
{
    UINT16_VAL wAddr;

    wAddr.Val = Address;
    //Write Address
    SPIWriteByte(wAddr.byte.HB);
    SPIWriteByte(wAddr.byte.LB);
}

/**
 * @Date: 2021-01-20 11:38:13
 * @Author: YangSL
 * @Description: 
 */
UINT32 SPIReadBurstMode()
{
    UINT32_VAL dwResult;
    //Read Bytes
    dwResult.byte.LB = SPIReadByte();
    dwResult.byte.HB = SPIReadByte();
    dwResult.byte.UB = SPIReadByte();
    dwResult.byte.MB = SPIReadByte();

    return dwResult.Val;
}

/**
 * @Date: 2021-01-20 11:38:04
 * @Author: YangSL
 * @Description: 
 */
void SPIWriteBurstMode(uint32_t Val)
{
    UINT32_VAL dwData;
    dwData.Val = Val;

    //Write Bytes
    SPIWriteByte(dwData.byte.LB);
    SPIWriteByte(dwData.byte.HB);
    SPIWriteByte(dwData.byte.UB);
    SPIWriteByte(dwData.byte.MB);
}

/**
 * @Date: 2021-01-20 11:37:53
 * @Author: YangSL
 * @Description: 
 */
void SPIWriteDWord(uint16_t Address, uint32_t Val)
{
    UINT32_VAL dwData;
    UINT16_VAL wAddr;

    wAddr.Val = Address;
    dwData.Val = Val;
    //Assert CS line
    CSLOW();
    //Write Command
    SPIWriteByte(CMD_SERIAL_WRITE);
    //Write Address
    SPIWriteByte(wAddr.byte.HB);
    SPIWriteByte(wAddr.byte.LB);
    //Write Bytes
    SPIWriteByte(dwData.byte.LB);
    SPIWriteByte(dwData.byte.HB);
    SPIWriteByte(dwData.byte.UB);
    SPIWriteByte(dwData.byte.MB);

    //De-Assert CS line
    CSHIGH();
}

/**
 * @Date: 2021-01-20 11:37:43
 * @Author: YangSL
 * @Description: 
 * @param {uint8_t} *ReadBuffer
 * @param {uint16_t} Address
 * @param {uint8_t} Count
 */
void SPIReadRegUsingCSR(uint8_t *ReadBuffer, uint16_t Address, uint8_t Count)
{
    UINT32_VAL param32_1 = {0};
    UINT8 i = 0;
    UINT16_VAL wAddr;
    wAddr.Val = Address;

    param32_1.v[0] = wAddr.byte.LB;
    param32_1.v[1] = wAddr.byte.HB;
    param32_1.v[2] = Count;
    param32_1.v[3] = ESC_READ_BYTE;

    SPIWriteDWord(ESC_CSR_CMD_REG, param32_1.Val);

    do
    {
        param32_1.Val = SPIReadDWord(ESC_CSR_CMD_REG);

    } while (param32_1.v[3] & ESC_CSR_BUSY);

    param32_1.Val = SPIReadDWord(ESC_CSR_DATA_REG);

    for (i = 0; i < Count; i++)
        ReadBuffer[i] = param32_1.v[i];

    return;
}

/**
 * @Date: 2021-01-20 11:37:38
 * @Author: YangSL
 * @Description: 
 * @param {uint8_t} *WriteBuffer
 * @param {uint16_t} Address
 * @param {uint8_t} Count
 */
void SPIWriteRegUsingCSR(uint8_t *WriteBuffer, uint16_t Address, uint8_t Count)
{
    UINT32_VAL param32_1 = {0};
    UINT8 i = 0;
    UINT16_VAL wAddr;

    for (i = 0; i < Count; i++)
        param32_1.v[i] = WriteBuffer[i];

    SPIWriteDWord(ESC_CSR_DATA_REG, param32_1.Val);

    wAddr.Val = Address;

    param32_1.v[0] = wAddr.byte.LB;
    param32_1.v[1] = wAddr.byte.HB;
    param32_1.v[2] = Count;
    param32_1.v[3] = ESC_WRITE_BYTE;

    SPIWriteDWord(0x304, param32_1.Val);
    do
    {
        param32_1.Val = SPIReadDWord(0x304);

    } while (param32_1.v[3] & ESC_CSR_BUSY);

    return;
}

/**
 * @Date: 2021-01-20 11:37:19
 * @Author: YangSL
 * @Description: 
 * @param {uint8_t} *ReadBuffer
 * @param {uint16_t} Address
 * @param {uint16_t} Count
 */
void SPIReadPDRamRegister(uint8_t *ReadBuffer, uint16_t Address, uint16_t Count)
{
    UINT32_VAL param32_1 = {0};
    UINT8 i = 0, nlength, nBytePosition;
    UINT8 nReadSpaceAvblCount;

    //    /*Reset/Abort any previous commands.*/
    param32_1.Val = (unsigned long int)PRAM_RW_ABORT_MASK;

    SPIWriteDWord(PRAM_READ_CMD_REG, param32_1.Val);

    /*The host should not modify this field unless the PRAM Read Busy
    (PRAM_READ_BUSY) bit is a 0.*/
    do
    {

        param32_1.Val = SPIReadDWord(PRAM_READ_CMD_REG);

    } while ((param32_1.v[3] & PRAM_RW_BUSY_8B));

    /*Write address and length in the EtherCAT Process RAM Read Address and
     * Length Register (ECAT_PRAM_RD_ADDR_LEN)*/
    param32_1.w[0] = Address;
    param32_1.w[1] = Count;

    SPIWriteDWord(PRAM_READ_ADDR_LEN_REG, param32_1.Val);

    /*Set PRAM Read Busy (PRAM_READ_BUSY) bit(-EtherCAT Process RAM Read Command Register)
     *  to start read operatrion*/

    param32_1.Val = PRAM_RW_BUSY_32B; /*TODO:replace with #defines*/

    SPIWriteDWord(PRAM_READ_CMD_REG, param32_1.Val);

    /*Read PRAM Read Data Available (PRAM_READ_AVAIL) bit is set*/
    do
    {
        //  param32_1.Val
        param32_1.Val = SPIReadDWord(PRAM_READ_CMD_REG);

    } while (!(param32_1.v[0] & IS_PRAM_SPACE_AVBL_MASK));

    nReadSpaceAvblCount = param32_1.v[1] & PRAM_SPACE_AVBL_COUNT_MASK;

    /*Fifo registers are aliased address. In indexed it will read indexed data reg 0x04, but it will point to reg 0
     In other modes read 0x04 FIFO register since all registers are aliased*/

    /*get the UINT8 lenth for first read*/
    //Auto increment is supported in SPIO
    param32_1.Val = SPIReadDWord(PRAM_READ_FIFO_REG);
    nReadSpaceAvblCount--;
    nBytePosition = (Address & 0x03);
    nlength = (4 - nBytePosition) > Count ? Count : (4 - nBytePosition);
    memcpy(ReadBuffer + i, &param32_1.v[nBytePosition], nlength);
    Count -= nlength;
    i += nlength;

    //Lets do it in auto increment mode
    CSLOW();

    //Write Command
    SPIWriteByte(CMD_FAST_READ);

    SPISendAddr(PRAM_READ_FIFO_REG);

    //Dummy Byte
    SPIWriteByte(CMD_FAST_READ_DUMMY);

    while (Count)
    {
        param32_1.Val = SPIReadBurstMode();

        nlength = Count > 4 ? 4 : Count;
        memcpy((ReadBuffer + i), &param32_1, nlength);

        i += nlength;
        Count -= nlength;
        nReadSpaceAvblCount--;
    }

    CSHIGH();

    return;
}

/**
 * @Date: 2021-01-20 11:37:29
 * @Author: YangSL
 * @Description: 
 * @param {uint8_t} *WriteBuffer
 * @param {uint16_t} Address
 * @param {uint16_t} Count
 */
void SPIWritePDRamRegister(uint8_t *WriteBuffer, uint16_t Address, uint16_t Count)
{
    UINT32_VAL param32_1 = {0};
    UINT8 i = 0, nlength, nBytePosition, nWrtSpcAvlCount;

    //    /*Reset or Abort any previous commands.*/
    param32_1.Val = PRAM_RW_ABORT_MASK;

    SPIWriteDWord(PRAM_WRITE_CMD_REG, param32_1.Val);

    /*Make sure there is no previous write is pending
    (PRAM Write Busy) bit is a 0 */
    do
    {
        param32_1.Val = SPIReadDWord(PRAM_WRITE_CMD_REG);

    } while ((param32_1.v[3] & PRAM_RW_BUSY_8B));

    /*Write Address and Length Register (ECAT_PRAM_WR_ADDR_LEN) with the
    starting UINT8 address and length)*/
    param32_1.w[0] = Address;
    param32_1.w[1] = Count;

    SPIWriteDWord(PRAM_WRITE_ADDR_LEN_REG, param32_1.Val);

    /*write to the EtherCAT Process RAM Write Command Register (ECAT_PRAM_WR_CMD) with the  PRAM Write Busy
    (PRAM_WRITE_BUSY) bit set*/

    param32_1.Val = PRAM_RW_BUSY_32B; /*TODO:replace with #defines*/

    SPIWriteDWord(PRAM_WRITE_CMD_REG, param32_1.Val);

    /*Read PRAM write Data Available (PRAM_READ_AVAIL) bit is set*/
    do
    {
        param32_1.Val = SPIReadDWord(PRAM_WRITE_CMD_REG);

    } while (!(param32_1.v[0] & IS_PRAM_SPACE_AVBL_MASK));

    /*Check write data available count*/
    nWrtSpcAvlCount = param32_1.v[1] & PRAM_SPACE_AVBL_COUNT_MASK;

    /*Write data to Write FIFO) */
    /*get the byte lenth for first read*/
    nBytePosition = (Address & 0x03);

    nlength = (4 - nBytePosition) > Count ? Count : (4 - nBytePosition);

    param32_1.Val = 0;
    memcpy(&param32_1.v[nBytePosition], WriteBuffer + i, nlength);

    SPIWriteDWord(PRAM_WRITE_FIFO_REG, param32_1.Val);

    nWrtSpcAvlCount--;
    Count -= nlength;
    i += nlength;

    //Auto increment mode
    CSLOW();

    //Write Command
    SPIWriteByte(CMD_SERIAL_WRITE);

    SPISendAddr(PRAM_WRITE_FIFO_REG);

    while (Count)
    {
        nlength = Count > 4 ? 4 : Count;
        param32_1.Val = 0;
        memcpy(&param32_1, (WriteBuffer + i), nlength);

        SPIWriteBurstMode(param32_1.Val);
        i += nlength;
        Count -= nlength;
        nWrtSpcAvlCount--;
    }

    CSHIGH();
    return;
}

/**
 * @Date: 2021-01-20 11:36:39
 * @Author: YangSL
 * @Description: 
 */

void SPIReadDRegister(uint8_t *ReadBuffer, uint16_t Address, uint16_t Count)
{
    if (Address >= 0x1000)
    {
        SPIReadPDRamRegister(ReadBuffer, Address, Count);
    }
    else
    {
        SPIReadRegUsingCSR(ReadBuffer, Address, Count);
    }
}

/**
 * @Date: 2021-01-20 11:36:47
 * @Author: YangSL
 * @Description: 
 */
void SPIWriteRegister(uint8_t *WriteBuffer, uint16_t Address, uint16_t Count)
{

    if (Address >= 0x1000)
    {
        SPIWritePDRamRegister(WriteBuffer, Address, Count);
    }
    else
    {
        SPIWriteRegUsingCSR(WriteBuffer, Address, Count);
    }
}

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
