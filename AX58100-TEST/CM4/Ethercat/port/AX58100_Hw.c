/*
 * @FileName:
 * @Author: YangSL
 * @Date: 2020-11-12 10:03:28
 * @LastEditTime: 2021-01-21 23:08:38
 * @Description:
 */

/*--------------------------------------------------------------------------------------
------
------    Includes
------
--------------------------------------------------------------------------------------*/
#include "ecat_def.h"
#if AX58100_HW
#include "AX58100_SPI.h"
#include "ecatslv.h"
#include "stm32h7xx_it.h"
#define    _AX58100_HW_ 1
#include "AX58100_Hw.h"
#undef     _AX58100_HW_

#include "ecatappl.h"
//#include "system.h"

/*--------------------------------------------------------------------------------------
------
------    internal Types and Defines
------
--------------------------------------------------------------------------------------*/

typedef union
{
    unsigned short    Word;
    unsigned char    Byte[2];
} UBYTETOWORD;

typedef union 
{
    UINT8           Byte[2];
    UINT16          Word;
}
UALEVENT;

HW_SPI_OBJECT      HW_SpiObj[HW_PDI_NUM];

/*-----------------------------------------------------------------------------------------
------
------    SPI defines/macros
------
-----------------------------------------------------------------------------------------*/
#define SPI_DEACTIVE                    1
#define SPI_ACTIVE                        0


#if INTERRUPTS_SUPPORTED
/*-----------------------------------------------------------------------------------------
------
------    Global Interrupt setting
------
-----------------------------------------------------------------------------------------*/

#define DISABLE_GLOBAL_INT				__disable_irq()			
#define ENABLE_GLOBAL_INT				  __enable_irq()
#define	DISABLE_AL_EVENT_INT			DISABLE_GLOBAL_INT
#define	ENABLE_AL_EVENT_INT				ENABLE_GLOBAL_INT

/*-----------------------------------------------------------------------------------------
------
------    ESC Interrupt
------
-----------------------------------------------------------------------------------------*/
#if AL_EVENT_ENABLED
#define    INIT_ESC_INT           EXTI0_Configuration();					
//#define    EcatIsr                EXTI3_IRQHandler
#define    ACK_ESC_INT         	  1;

#endif //#if AL_EVENT_ENABLED

/*-----------------------------------------------------------------------------------------
------
------    SYNC0 Interrupt
------
-----------------------------------------------------------------------------------------*/
#if DC_SUPPORTED && _STM32_IO8
#define    INIT_SYNC0_INT                 EXTI1_Configuration();		
//#define    Sync0Isr                        	EXTI3_IRQHandler // primary interrupt vector name
#define    DISABLE_SYNC0_INT              NVIC_DisableIRQ(EXTI3_IRQn);	  // {(_INT3IE)=0;}//disable interrupt source INT3
#define    ENABLE_SYNC0_INT               NVIC_EnableIRQ(EXTI3_IRQn);	// {(_INT3IE) = 1;} //enable interrupt source INT3
#define    ACK_SYNC0_INT                  1;

#define    INIT_SYNC1_INT                  EXTI2_Configuration();
//#define    Sync1Isr                        	EXTI1_IRQHandler
#define    DISABLE_SYNC1_INT                 NVIC_DisableIRQ(EXTI1_IRQn);// {(_INT4IE)=0;}//disable interrupt source INT4
#define    ENABLE_SYNC1_INT                 NVIC_EnableIRQ(EXTI1_IRQn); //{(_INT4IE) = 1;} //enable interrupt source INT4
#define    ACK_SYNC1_INT                  	 1;
//#define    ACK_SYNC1_INT                  	 EXTI_ClearITPendingBit(EXTI_Line1);// {(SYNC1_INT_REQ) = 0;}

/*ECATCHANGE_END(V5.10) HW3*/

#endif //#if DC_SUPPORTED && _STM32_IO8

#endif	//#if INTERRUPTS_SUPPORTED
/*-----------------------------------------------------------------------------------------
------
------    Hardware timer
------
-----------------------------------------------------------------------------------------*/
#if _STM32_IO8

#if ECAT_TIMER_INT
#define ECAT_TIMER_INT_STATE       
#define ECAT_TIMER_ACK_INT        		 	1;
//#define ECAT_TIMER_ACK_INT        		 	TIM_ClearITPendingBit(TIM2 , TIM_FLAG_Update);
#define    TimerIsr                    	TIM6_IRQHandler //	SysTick_Handler//
#define    ENABLE_ECAT_TIMER_INT        NVIC_EnableIRQ(TIM2_IRQn) ;	//SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;//NVIC_EnableIRQ(TIM2_IRQn) ;	
#define    DISABLE_ECAT_TIMER_INT       NVIC_DisableIRQ(TIM2_IRQn) ;//SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;//NVIC_DisableIRQ(SysTick_IRQn/*TIM2_IRQn*/) ;

#define INIT_ECAT_TIMER            TIM_Configuration(10) ;  // SysTick_Config(SystemCoreClock/1000);  

#define STOP_ECAT_TIMER            DISABLE_ECAT_TIMER_INT;/*disable timer interrupt*/ \

#define START_ECAT_TIMER          ENABLE_ECAT_TIMER_INT


#else    //#if ECAT_TIMER_INT

#define INIT_ECAT_TIMER      					TIM_Configuration(10) //SysTick_Config(SystemCoreClock/1000);//          {(PR7) = 2000;/*set period*/ \

#define STOP_ECAT_TIMER              TIM_Cmd(TIM2, DISABLE);	// SysTick->CTRL  &=  ~SysTick_CTRL_ENABLE_Msk;      //			 

#define START_ECAT_TIMER              TIM_Cmd(TIM2, ENABLE);// SysTick->CTRL  |=  SysTick_CTRL_ENABLE_Msk;      			

#endif //#else #if ECAT_TIMER_INT

#elif _STM32_IO4

#if !ECAT_TIMER_INT
#define    ENABLE_ECAT_TIMER_INT       NVIC_EnableIRQ(TIM2_IRQn) ;	// SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;//
#define    DISABLE_ECAT_TIMER_INT      NVIC_DisableIRQ(TIM2_IRQn) ;//SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;//
#define INIT_ECAT_TIMER               TIM_Configuration(10) ;//	SysTick_Config(SystemCoreClock/1000);//			
#define STOP_ECAT_TIMER              	TIM_Cmd(TIM2, DISABLE);//	SysTick->CTRL  &=  ~SysTick_CTRL_ENABLE_Msk; //		
#define START_ECAT_TIMER           		TIM_Cmd(TIM2, ENABLE);	//	SysTick->CTRL  |=  SysTick_CTRL_ENABLE_Msk; //		

#else    //#if !ECAT_TIMER_INT

#warning "define Timer Interrupt Macros"

#endif //#else #if !ECAT_TIMER_INT
#endif //#elif _STM32_IO4

/*-----------------------------------------------------------------------------------------
------
------    Configuration Bits
------
-----------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------
------
------    LED defines
------
-----------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------
------
------    internal Variables
------
--------------------------------------------------------------------------------------*/
/**
 * contains the content of the ALEvent register (0x220), 
 * this variable is updated on each Access to the Esc
 **/
UALEVENT         EscALEvent;           

/*--------------------------------------------------------------------------------------
------
------    internal functions
------
--------------------------------------------------------------------------------------*/


/**
 * Read the AL Event Requests register
 **/
static void GetInterruptRegister(void)
{
#if AL_EVENT_ENABLED
    DISABLE_AL_EVENT_INT;
#endif
	
    /* select the SPI */
    SELECT_SPI;
	
	HW_EscReadIsr((MEM_ADDR *)&EscALEvent.Word, 0x220, 2);
	/* if the SPI transmission rate is higher than 15 MBaud, the Busy detection shall be done here */
	
	DESELECT_SPI;
#if AL_EVENT_ENABLED
    ENABLE_AL_EVENT_INT;
#endif
}


#if !INTERRUPTS_SUPPORTED
#define ISR_GetInterruptRegister GetInterruptRegister
#else
/**
 * Read the AL Event Requests register
 **/
static void ISR_GetInterruptRegister(void)
{
    /* SPI should be deactivated to interrupt a possible transmission */
    DESELECT_SPI;

    /* select the SPI */
    SELECT_SPI;

		 HW_EscReadIsr((MEM_ADDR *)&EscALEvent.Word, 0x220, 2);

  /* if the SPI transmission rate is higher than 15 MBaud, the Busy detection shall be
       done here */

    DESELECT_SPI;
}
#endif //#else #if !INTERRUPTS_SUPPORTED


/**
 * @description: The function addresses the EtherCAT ASIC via SPI for a following SPI access.
 */
static void AddressingEsc( UINT16 Address, UINT8 Command )
{
    UBYTETOWORD tmp;
    VARVOLATILE UINT8 dummy;
    tmp.Word = ( Address << 3 ) | Command;
    /* select the SPI */
    SELECT_SPI;

   /* there have to be at least 15 ns after the SPI1_SEL signal was active (0) before
       the transmission shall be started */
    /* send the first address/command byte to the ESC */	
	dummy = WR_CMD(tmp.Byte[1]);
	
    /* send the second address/command byte to the ESC */
 
	dummy =	WR_CMD(tmp.Byte[0]);
	
    /* if the SPI transmission rate is higher than 15 MBaud, the Busy detection shall be
       done here */
}


#if !INTERRUPTS_SUPPORTED
#define ISR_AddressingEsc AddressingEsc
#else
/**
 * @description: The function addresses the EtherCAT ASIC via SPI for a following SPI access.
 *               Shall be implemented if interrupts are supported else this function is equal to "AddressingEsc()"
 * @param {*}EtherCAT ASIC address ( upper limit is 0x1FFF )    for access.
 * @return {*}ESC_WR performs a write access; ESC_RD performs a read access.
 */
static void ISR_AddressingEsc( UINT16 Address, UINT8 Command )
{
    VARVOLATILE UINT8 dummy;
    UBYTETOWORD tmp;
    tmp.Word = ( Address << 3 ) | Command;

    /* there have to be at least 15 ns after the SPI1_SEL signal was active (0) before
      the transmission shall be started */
	
    /* send the first address/command byte to the ESC */
	dummy= WR_CMD(tmp.Byte[1]);
	
   /* send the second address/command byte to the ESC */

	dummy= WR_CMD(tmp.Byte[0]);
    /* if the SPI transmission rate is higher than 15 MBaud, the Busy detection shall be
       done here */
}
#endif //!INTERRUPTS_SUPPORTED


/*--------------------------------------------------------------------------------------
------
------    exported hardware access functions
------
--------------------------------------------------------------------------------------*/


/**
 * @description: This function intialize the Process Data Interface (PDI) and the host controller
 * @return: 0 if initialization was successful
 */
UINT16 intMask;
UINT8 HW_Init(void)
{
	/* initialize the SSP registers for the ESC SPI */
    do
    {
        intMask = 0x93;
        HW_EscWriteWord(intMask, ESC_AL_EVENTMASK_OFFSET);
        intMask = 0;
        HW_EscReadWord(intMask, ESC_AL_EVENTMASK_OFFSET);
    } while (intMask != 0x93);		

	intMask = 0x00;

    HW_EscWriteDWord(intMask, ESC_AL_EVENTMASK_OFFSET);

//#if AL_EVENT_ENABLED
//    INIT_ESC_INT;
//    ENABLE_ESC_INT();
//#endif

//#if DC_SUPPORTED&& _STM32_IO8
//    INIT_SYNC0_INT
//    INIT_SYNC1_INT
//
//    ENABLE_SYNC0_INT;
//    ENABLE_SYNC1_INT;
//#endif

//    INIT_ECAT_TIMER;
//    START_ECAT_TIMER;


//#if INTERRUPTS_SUPPORTED
//    /* enable all interrupts */
//    ENABLE_GLOBAL_INT;
//#endif

    return 0;
}




/**
 * @description: This function shall be implemented if hardware resources need to be release 
 *               when the sample application stops
 */
void HW_Release(void)
{
}


/**
 * @description: This function gets the current content of ALEvent register
 * @param {*}   first two Bytes of ALEvent register (0x220)
 * @return {*}
 */
UINT16 HW_GetALEventRegister(void)
{
    GetInterruptRegister();
    return EscALEvent.Word;
}


#if INTERRUPTS_SUPPORTED
/**
 * @description: The SPI PDI requires an extra ESC read access functions from interrupts service routines.
 *               The behaviour is equal to "HW_GetALEventRegister()"
 * @param {*}   first two Bytes of ALEvent register (0x220)
 * @return {*}
 */
UINT16 HW_GetALEventRegister_Isr(void)
{
     ISR_GetInterruptRegister();
    return EscALEvent.Word;
}
#endif


#if UC_SET_ECAT_LED
/**
 * @description: This function updates the EtherCAT run and error led
 * @param {UINT8} RunLed    desired EtherCAT Run led state
 * @param {UINT8} ErrLed    desired EtherCAT Error led state
 * @return {*}
 */
void HW_SetLed(UINT8 RunLed,UINT8 ErrLed)
{
#if _STM32_IO8

#endif
}
#endif //UC_SET_ECAT_LED


/**
 * @description: This function operates the SPI read access to the EtherCAT ASIC.
 */
void HW_EscRead( MEM_ADDR *pData, UINT16 Address, UINT16 Len )
{
    /* HBu 24.01.06: if the SPI will be read by an interrupt routine too the
                     mailbox reading may be interrupted but an interrupted
                     reading will remain in a SPI transmission fault that will
                     reset the internal Sync Manager status. Therefore the reading
                     will be divided in 1-byte reads with disabled interrupt */
    UINT16 i = Len;
    uint8_t data[2] = {0};
    UINT8 *pTmpData = (UINT8 *)pData;

    /* loop for all bytes to be read */
    while ( i-- > 0 )
    {
			#if AL_EVENT_ENABLED
        /* the reading of data from the ESC can be interrupted by the
           AL Event ISR, in that case the address has to be reinitialized,
           in that case the status flag will indicate an error because
           the reading operation was interrupted without setting the last
           sent byte to 0xFF */
        DISABLE_AL_EVENT_INT;
#endif
         AddressingEsc( Address, ESC_RD );

//		*pTmpData++= WR_CMD(0xFF);
		data[i] = WR_CMD(0xFF);

		*pTmpData++ = data[i];
   #if AL_EVENT_ENABLED
        ENABLE_AL_EVENT_INT;
#endif

        DESELECT_SPI;
        /* next address */
        Address++;

    }
}


#if INTERRUPTS_SUPPORTED
/**
 * @description: The SPI PDI requires an extra ESC read access functions from interrupts service routines.
 *               The behaviour is equal to "HW_EscRead()"
 * @param {MEM_ADDR} *pData     Pointer to a byte array which holds data to write or saves read data
 * @param {UINT16} Address      EtherCAT ASIC address ( upper limit is 0x1FFF )    for access.
 * @param {UINT16} Len          Access size in Bytes.
 */
void HW_EscReadIsr( MEM_ADDR *pData, UINT16 Address, UINT16 Len )
{
    UINT16 i = Len;
    UINT8 data = 0;

   UINT8 *pTmpData = (UINT8 *)pData;

    /* select the SPI */
    SELECT_SPI;
    
    /* send the address and command to the ESC */
     ISR_AddressingEsc( Address, ESC_RD );
    /* loop for all bytes to be read */
    while ( i-- > 0 )
    {
        if ( i == 0 )
        {
            /* when reading the last byte the DI pin shall be 1 */
            data = 0xFF;
        }

		*pTmpData++= WR_CMD(data);
    }

    /* there has to be at least 15 ns + CLK/2 after the transmission is finished
       before the SPI1_SEL signal shall be 1 */
    DESELECT_SPI;
}
#endif //INTERRUPTS_SUPPORTED


/**
 * @description: This function operates the SPI write access to the EtherCAT ASIC
 * @param {MEM_ADDR} *pData     Pointer to a byte array which holds data to write or saves write data
 * @param {UINT16} Address      EtherCAT ASIC address ( upper limit is 0x1FFF )    for access
 * @param {UINT16} Len          Access size in Bytes.
 * @return {*}
 */
void HW_EscWrite( MEM_ADDR *pData, UINT16 Address, UINT16 Len )
{
    UINT16 i = Len;
    VARVOLATILE UINT8 dummy;

    UINT8 *pTmpData = (UINT8 *)pData;

    /* loop for all bytes to be written */
    while ( i-- > 0 )
    {
    #if AL_EVENT_ENABLED
        /* the reading of data from the ESC can be interrupted by the
           AL Event ISR, so every byte will be written separate */
        DISABLE_AL_EVENT_INT;
    #endif //AL_EVENT_ENABLED
        /* HBu 24.01.06: wrong parameter ESC_RD */
         AddressingEsc( Address, ESC_WR );

        /* enable the ESC interrupt to get the AL Event ISR the chance to interrupt */
        /* SPI1_BUF must be read, otherwise the module will not transfer the next received data from SPIxSR to SPIxRXB.*/
			dummy= WR_CMD(*pTmpData++);
			
    #if AL_EVENT_ENABLED
        ENABLE_AL_EVENT_INT;
    #endif //AL_EVENT_ENABLED

        DESELECT_SPI;
        /* next address */
        Address++;
    }
}


#if INTERRUPTS_SUPPORTED
/**
 * @Date: 2021-01-21
 * @Author: YangSL
 * @Description: The SPI PDI requires an extra ESC write access functions from interrupts service routines.
 *               The behaviour is equal to "HW_EscWrite()
 * @param {MEM_ADDR} *pData     Pointer to a byte array which holds data to write or saves write data
 * @param {UINT16} Address      EtherCAT ASIC address ( upper limit is 0x1FFF )    for access.
 * @param {UINT16} Len          Access size in Bytes.
 */
void HW_EscWriteIsr( MEM_ADDR *pData, UINT16 Address, UINT16 Len )
{
    UINT16 i = Len;
    VARVOLATILE UINT16 dummy;
    UINT8 *pTmpData = (UINT8 *)pData;

    /* select the SPI */
    SELECT_SPI;

    /* send the address and command to the ESC */
     ISR_AddressingEsc( Address, ESC_WR );
    /* loop for all bytes to be written */
    while ( i-- > 0 )
    {
        /* start transmission */
			dummy= WR_CMD(*pTmpData);
      /* increment data pointer */
        pTmpData++;
    }

    /* there has to be at least 15 ns + CLK/2 after the transmission is finished
       before the SPI1_SEL signal shall be 1 */
    DESELECT_SPI;
}
#endif //#if INTERRUPTS_SUPPORTED


#if BOOTSTRAPMODE_SUPPORTED
/**
 * @Date: 2021-01-21 17:35:24
 * @Author: YangSL
 * @Description: This function resets the hardware
 */
void HW_RestartTarget(void)
{
}
#endif //BOOTSTRAPMODE_SUPPORTED


#if ESC_EEPROM_EMULATION
/**
 * @Date: 2021-01-21 17:33:36
 * @Author: YangSL
 * @Description: This function is called when the master has 
 *               request an EEPROM reload during EEPROM emulation
 * @return :0 if reload was successful
 */
UINT16 HW_EepromReload (void)
{
    return 0;
}
#endif  //ESC_EEPROM_EMULATION


#if AL_EVENT_ENABLED
/*Interrupt service routine for the PDI interrupt from the EtherCAT Slave Controller*/
void EcatIsr(void)
{			
    PDI_Isr();
    /* reset the interrupt flag */
    ACK_ESC_INT; 
}
#endif     // AL_EVENT_ENABLED


#if DC_SUPPORTED&& _STM32_IO8
void Sync0Isr(void)
{
    Sync0_Isr();
    /* reset the interrupt flag */

    ACK_SYNC0_INT;
}

void Sync1Isr(void)
{	
    Sync1_Isr();
    /* reset the interrupt flag */
    ACK_SYNC1_INT;
}
#endif


#if _STM32_IO8 && ECAT_TIMER_INT
void TimerIsr(void)
{
    ECAT_CheckTimer();
    ECAT_TIMER_ACK_INT;	
}
#endif


#endif //#if AX58100_HW


