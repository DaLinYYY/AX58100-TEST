/*
 * @FileName:
 * @Author: YangSL
 * @Date: 2020-11-12 10:03:28
 * @LastEditTime: 2021-01-22 13:29:11
 * @Description:
 */


#ifndef _AX58100_HW_H_
#define _AX58100_HW_H_


/*-----------------------------------------------------------------------------------------
------    Includes
-----------------------------------------------------------------------------------------*/
#include  "esc.h"
#include "AX58100_Config.h"
#include "main.h"




#define HW_EscReadByte(ByteValue,Address)	HW_EscRead(((MEM_ADDR *)&(ByteValue)),((UINT16)(Address)),1) 
#define HW_EscReadWord(WordValue, Address) HW_EscRead(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2) /**< \brief 16Bit ESC read access*/
#define HW_EscReadDWord(DWordValue, Address) HW_EscRead(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4) /**< \brief 32Bit ESC read access*/
#define HW_EscReadMbxMem(pData,Address,Len) HW_EscRead(((MEM_ADDR *)(pData)),((UINT16)(Address)),(Len)) /**< \brief The mailbox data is stored in the local uC memory therefore the default read function is used.*/

#define HW_EscReadByteIsr(ByteValue,Address)	HW_EscReadIsr(((MEM_ADDR *)&(ByteValue)),((UINT16)(Address)),1) 
#define HW_EscReadWordIsr(WordValue, Address) HW_EscReadIsr(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2) /**< \brief Interrupt specific 16Bit ESC read access*/
#define HW_EscReadDWordIsr(DWordValue, Address) HW_EscReadIsr(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4) /**< \brief Interrupt specific 32Bit ESC read access*/

#define HW_EscWriteByte(WordValue, Address) HW_EscWrite(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),1)
#define HW_EscWriteWord(WordValue, Address) HW_EscWrite(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2) /**< \brief 16Bit ESC write access*/
#define HW_EscWriteDWord(DWordValue, Address) HW_EscWrite(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4) /**< \brief 32Bit ESC write access*/
#define HW_EscWriteMbxMem(pData,Address,Len) HW_EscWrite(((MEM_ADDR *)(pData)),((UINT16)(Address)),(Len)) /**< \brief The mailbox data is stored in the local uC memory therefore the default write function is used.*/

#define HW_EscWriteWordIsr(WordValue, Address) HW_EscWriteIsr(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2) /**< \brief Interrupt specific 16Bit ESC write access*/
#define HW_EscWriteDWordIsr(DWordValue, Address) HW_EscWriteIsr(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4) /**< \brief Interrupt specific 32Bit ESC write access*/



#if _EL9800HW_
    #define PROTO
#else
    #define PROTO extern
#endif


/*-----------------------------------------------------------------------------------------
------
------    Global variables
------
-----------------------------------------------------------------------------------------*/
/* EXPORTED SUBPROGRAM SPECIFICATIONS */

/**
  * @brief  Access to the hardware timer
  */
#ifndef HW_GetTimer
#define HW_GetTimer()          ((UINT16)(HW_TIMETICK_INSTANCE->CNT>>1))
#endif

/**
  * @brief  Clear the hardware timer
  */
#ifndef HW_ClearTimer
#define HW_ClearTimer()        (HW_TIMETICK_INSTANCE->CNT = 0)
#endif

/*-----------------------------------------------------------------------------------------
------
------    Global functions
------
-----------------------------------------------------------------------------------------*/
PROTO UINT8 HW_Init(void);
PROTO void HW_Release(void);
PROTO UINT16 HW_GetALEventRegister(void);

PROTO UINT16 HW_GetALEventRegister_Isr(void);

PROTO void HW_ResetALEventMask(UINT16 intMask);
PROTO void HW_SetALEventMask(UINT16 intMask);
PROTO void HW_SetLed(UINT8 RunLed,UINT8 ErrLed);

PROTO void HW_EscRead( MEM_ADDR * pData, UINT16 Address, UINT16 Len );
PROTO void HW_EscReadIsr( MEM_ADDR *pData, UINT16 Address, UINT16 Len );

PROTO void HW_EscWrite( MEM_ADDR *pData, UINT16 Address, UINT16 Len );

PROTO void HW_EscWriteIsr( MEM_ADDR *pData, UINT16 Address, UINT16 Len );

PROTO void HW_DisableSyncManChannel(UINT8 channel);
PROTO void HW_EnableSyncManChannel(UINT8 channel);
PROTO TSYNCMAN ESCMEM *HW_GetSyncMan(UINT8 channel);

void TimerIsr(void);
void EcatIsr(void);
void Sync0Isr(void);
void Sync1Isr(void);
/*---------------------------------------------
-    ESC Access macros
-----------------------------------------------*/
// extern HW_SPI_OBJECT      HW_SpiObj[];

#endif //#if _AX58100_HW_H_


