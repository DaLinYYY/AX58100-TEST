/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2021-01-21 11:16:11
 * @LastEditTime: 2021-01-21 11:18:23
 * @Description: 
 */

#include "main.h"
#include "ecat_def.h"

#define AX58100_DEBUG_ENABLE            1

/* SPI PDI */
#define HW_SPI_MAX_DATA_FRAGMENT_SIZE      512
#define HW_SPI_MAX_ADDR_DUMMY_BYTES        4
#define HW_SPI_MAX_XFER_BUF_SIZE           (HW_SPI_MAX_ADDR_DUMMY_BYTES + HW_SPI_MAX_DATA_FRAGMENT_SIZE)
#define HW_SPI_XFER_TIMEOUT                10//ms
#define HW_MAX_DELAY                       0xFFFFFFFFU


typedef enum {
	HW_FUN_PDI = 0,
	HW_ESC_PDI,
	HW_PDI_NUM,
} HW_PDI_TYPE;

#if AX58100_DEBUG_ENABLE
typedef struct{
    UINT32  EscIsrCnt;
    UINT32  FunIsrCnt;
    UINT32  Sync0IsrCnt;
    UINT32  Sync1IsrCnt;
    UINT32  AdcTrgCnt;	
    UINT32  TIM1IsrCnt;
    UINT32  EncIsrCnt;	
    UINT32  TmrTskIsrCnt;
    UINT32  AmpErrCnt;
    INT32   AmpErrCode;	
    UINT32  AmpNotRspCnt;
    UINT32  AmpRspCnt;
    UINT32  AmpReqCnt;
    UINT32	AmpIsProSync0;
    UINT32	AmpIsProALINT;
    UINT32 	RspMsgType;
    UINT32 	ReqMsgType;
} HW_DEBUG;

HW_DEBUG* HW_GetDebugCounter(void);
#define HW_Get500usTimer()          ((UINT16)HW_TIMETICK_INSTANCE->CNT)
#endif

typedef struct{
    SPI_TypeDef   *pInstance;
    UINT8          AlterFunc;

    GPIO_TypeDef  *pCsPort;
    UINT16         CsPin;
    GPIO_TypeDef  *pClkPort;
    UINT16         ClkPin;
    GPIO_TypeDef  *pMisoPort;
    UINT16         MisoPin;
    GPIO_TypeDef  *pMosiPort;
    UINT16         MosiPin;
    GPIO_TypeDef  *pIntrPort;
    UINT16         IntrPin;
    IRQn_Type      IntrIrq;
    
    UINT32         IntrPrePrio;
    UINT32         IntrSubPrio;
    UINT8          Enable3BytesAddr;
    UINT32         Baudrate;
} HW_SPI_IO_CONFIG;

typedef struct{
    HW_SPI_IO_CONFIG  *pIoCfg;
    SPI_HandleTypeDef Handle;
    UINT8             TxBuf[HW_SPI_MAX_XFER_BUF_SIZE];
    UINT8             RxBuf[HW_SPI_MAX_XFER_BUF_SIZE];	
} HW_SPI_OBJECT;

