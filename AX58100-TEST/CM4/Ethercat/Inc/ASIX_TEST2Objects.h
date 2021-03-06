/*
* This source file is part of the EtherCAT Slave Stack Code licensed by Beckhoff Automation GmbH & Co KG, 33415 Verl, Germany.
* The corresponding license agreement applies. This hint shall not be removed.
*/

/**
* \addtogroup ASIX_TEST2 ASIX_TEST2
* @{
*/

/**
\file ASIX_TEST2Objects
\author ET9300Utilities.ApplicationHandler (Version 1.5.0.0) | EthercatSSC@beckhoff.com

\brief ASIX_TEST2 specific objects<br>
\brief NOTE : This file will be overwritten if a new object dictionary is generated!<br>
*/

#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
#define PROTO
#else
#define PROTO extern
#endif
/******************************************************************************
*                    Object 0x1600 : PDO0_TimeStamp process data mapping
******************************************************************************/
/**
* \addtogroup 0x1600 0x1600 | PDO0_TimeStamp process data mapping
* @{
* \brief Object 0x1600 (PDO0_TimeStamp process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x7000.1<br>
* SubIndex 2 - Reference to 0x7000.2<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1600[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x7000.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex2 - Reference to 0x7000.2 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1600[] = "PDO0_TimeStamp process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x7000.1 */
UINT32 SI2; /* Subindex2 - Reference to 0x7000.2 */
} OBJ_STRUCT_PACKED_END
TOBJ1600;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1600 PDO0_TimeStampProcessDataMapping0x1600
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={2,0x70000108,0x70000208}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1601 : PDO1_ModeSegment process data mapping
******************************************************************************/
/**
* \addtogroup 0x1601 0x1601 | PDO1_ModeSegment process data mapping
* @{
* \brief Object 0x1601 (PDO1_ModeSegment process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x7010.1<br>
* SubIndex 2 - Reference to 0x7010.2<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1601[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x7010.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex2 - Reference to 0x7010.2 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1601[] = "PDO1_ModeSegment process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x7010.1 */
UINT32 SI2; /* Subindex2 - Reference to 0x7010.2 */
} OBJ_STRUCT_PACKED_END
TOBJ1601;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1601 PDO1_ModeSegmentProcessDataMapping0x1601
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={2,0x70100108,0x70100208}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1602 : PDO2_StatusSegment process data mapping
******************************************************************************/
/**
* \addtogroup 0x1602 0x1602 | PDO2_StatusSegment process data mapping
* @{
* \brief Object 0x1602 (PDO2_StatusSegment process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x7020.1<br>
* SubIndex 2 - Reference to 0x7020.2<br>
* SubIndex 3 - Reference to 0x7020.3<br>
* SubIndex 4 - Reference to 0x7020.4<br>
* SubIndex 5 - Reference to 0x7020.5<br>
* SubIndex 6 - Reference to 0x7020.6<br>
* SubIndex 7 - Reference to 0x7020.7<br>
* SubIndex 8 - Reference to 0x7020.8<br>
* SubIndex 9 - Reference to 0x7020.9<br>
* SubIndex 10 - Reference to 0x7020.10<br>
* SubIndex 11 - Reference to 0x7020.11<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1602[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x7020.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - Reference to 0x7020.2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 - Reference to 0x7020.3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex4 - Reference to 0x7020.4 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex5 - Reference to 0x7020.5 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex6 - Reference to 0x7020.6 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex7 - Reference to 0x7020.7 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex8 - Reference to 0x7020.8 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex9 - Reference to 0x7020.9 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex10 - Reference to 0x7020.10 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex11 - Reference to 0x7020.11 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1602[] = "PDO2_StatusSegment process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000"
"SubIndex 005\000"
"SubIndex 006\000"
"SubIndex 007\000"
"SubIndex 008\000"
"SubIndex 009\000"
"SubIndex 010\000"
"SubIndex 011\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x7020.1 */
UINT32 SI2; /* Subindex2 - Reference to 0x7020.2 */
UINT32 SI3; /* Subindex3 - Reference to 0x7020.3 */
UINT32 SI4; /* Subindex4 - Reference to 0x7020.4 */
UINT32 SI5; /* Subindex5 - Reference to 0x7020.5 */
UINT32 SI6; /* Subindex6 - Reference to 0x7020.6 */
UINT32 SI7; /* Subindex7 - Reference to 0x7020.7 */
UINT32 SI8; /* Subindex8 - Reference to 0x7020.8 */
UINT32 SI9; /* Subindex9 - Reference to 0x7020.9 */
UINT32 SI10; /* Subindex10 - Reference to 0x7020.10 */
UINT32 SI11; /* Subindex11 - Reference to 0x7020.11 */
} OBJ_STRUCT_PACKED_END
TOBJ1602;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1602 PDO2_StatusSegmentProcessDataMapping0x1602
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={11,0x70200108,0x70200208,0x70200308,0x70200408,0x70200508,0x70200608,0x70200708,0x70200808,0x70200908,0x70200A08,0x70200B08}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1603 : PDO3_CommandDataSegment process data mapping
******************************************************************************/
/**
* \addtogroup 0x1603 0x1603 | PDO3_CommandDataSegment process data mapping
* @{
* \brief Object 0x1603 (PDO3_CommandDataSegment process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x7030.1<br>
* SubIndex 2 - Reference to 0x7030.2<br>
* SubIndex 3 - Reference to 0x7030.3<br>
* SubIndex 4 - Reference to 0x7030.4<br>
* SubIndex 5 - Reference to 0x7030.5<br>
* SubIndex 6 - Reference to 0x7030.6<br>
* SubIndex 7 - Reference to 0x7030.7<br>
* SubIndex 8 - Reference to 0x7030.8<br>
* SubIndex 9 - Reference to 0x7030.9<br>
* SubIndex 10 - Reference to 0x7030.10<br>
* SubIndex 11 - Reference to 0x7030.11<br>
* SubIndex 12 - Reference to 0x7030.12<br>
* SubIndex 13 - Reference to 0x7030.13<br>
* SubIndex 14 - Reference to 0x7030.14<br>
* SubIndex 15 - Reference to 0x7030.15<br>
* SubIndex 16 - Reference to 0x7030.16<br>
* SubIndex 17 - Reference to 0x7030.17<br>
* SubIndex 18 - Reference to 0x7030.18<br>
* SubIndex 19 - Reference to 0x7030.19<br>
* SubIndex 20 - Reference to 0x7030.20<br>
* SubIndex 21 - Reference to 0x7030.21<br>
* SubIndex 22 - Reference to 0x7030.22<br>
* SubIndex 23 - Reference to 0x7030.23<br>
* SubIndex 24 - Reference to 0x7030.24<br>
* SubIndex 25 - Reference to 0x7030.25<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1603[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x7030.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - Reference to 0x7030.2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 - Reference to 0x7030.3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex4 - Reference to 0x7030.4 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex5 - Reference to 0x7030.5 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex6 - Reference to 0x7030.6 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex7 - Reference to 0x7030.7 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex8 - Reference to 0x7030.8 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex9 - Reference to 0x7030.9 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex10 - Reference to 0x7030.10 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex11 - Reference to 0x7030.11 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex12 - Reference to 0x7030.12 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex13 - Reference to 0x7030.13 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex14 - Reference to 0x7030.14 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex15 - Reference to 0x7030.15 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex16 - Reference to 0x7030.16 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex17 - Reference to 0x7030.17 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex18 - Reference to 0x7030.18 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex19 - Reference to 0x7030.19 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex20 - Reference to 0x7030.20 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex21 - Reference to 0x7030.21 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex22 - Reference to 0x7030.22 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex23 - Reference to 0x7030.23 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex24 - Reference to 0x7030.24 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex25 - Reference to 0x7030.25 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1603[] = "PDO3_CommandDataSegment process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000"
"SubIndex 005\000"
"SubIndex 006\000"
"SubIndex 007\000"
"SubIndex 008\000"
"SubIndex 009\000"
"SubIndex 010\000"
"SubIndex 011\000"
"SubIndex 012\000"
"SubIndex 013\000"
"SubIndex 014\000"
"SubIndex 015\000"
"SubIndex 016\000"
"SubIndex 017\000"
"SubIndex 018\000"
"SubIndex 019\000"
"SubIndex 020\000"
"SubIndex 021\000"
"SubIndex 022\000"
"SubIndex 023\000"
"SubIndex 024\000"
"SubIndex 025\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x7030.1 */
UINT32 SI2; /* Subindex2 - Reference to 0x7030.2 */
UINT32 SI3; /* Subindex3 - Reference to 0x7030.3 */
UINT32 SI4; /* Subindex4 - Reference to 0x7030.4 */
UINT32 SI5; /* Subindex5 - Reference to 0x7030.5 */
UINT32 SI6; /* Subindex6 - Reference to 0x7030.6 */
UINT32 SI7; /* Subindex7 - Reference to 0x7030.7 */
UINT32 SI8; /* Subindex8 - Reference to 0x7030.8 */
UINT32 SI9; /* Subindex9 - Reference to 0x7030.9 */
UINT32 SI10; /* Subindex10 - Reference to 0x7030.10 */
UINT32 SI11; /* Subindex11 - Reference to 0x7030.11 */
UINT32 SI12; /* Subindex12 - Reference to 0x7030.12 */
UINT32 SI13; /* Subindex13 - Reference to 0x7030.13 */
UINT32 SI14; /* Subindex14 - Reference to 0x7030.14 */
UINT32 SI15; /* Subindex15 - Reference to 0x7030.15 */
UINT32 SI16; /* Subindex16 - Reference to 0x7030.16 */
UINT32 SI17; /* Subindex17 - Reference to 0x7030.17 */
UINT32 SI18; /* Subindex18 - Reference to 0x7030.18 */
UINT32 SI19; /* Subindex19 - Reference to 0x7030.19 */
UINT32 SI20; /* Subindex20 - Reference to 0x7030.20 */
UINT32 SI21; /* Subindex21 - Reference to 0x7030.21 */
UINT32 SI22; /* Subindex22 - Reference to 0x7030.22 */
UINT32 SI23; /* Subindex23 - Reference to 0x7030.23 */
UINT32 SI24; /* Subindex24 - Reference to 0x7030.24 */
UINT32 SI25; /* Subindex25 - Reference to 0x7030.25 */
} OBJ_STRUCT_PACKED_END
TOBJ1603;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1603 PDO3_CommandDataSegmentProcessDataMapping0x1603
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={25,0x70300120,0x70300220,0x70300320,0x70300420,0x70300520,0x70300620,0x70300720,0x70300820,0x70300920,0x70300A20,0x70300B20,0x70300C20,0x70300D20,0x70300E20,0x70300F20,0x70301020,0x70301120,0x70301220,0x70301320,0x70301420,0x70301520,0x70301620,0x70301720,0x70301820,0x70301920}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1604 : PDO4_FrameVerifySegment process data mapping
******************************************************************************/
/**
* \addtogroup 0x1604 0x1604 | PDO4_FrameVerifySegment process data mapping
* @{
* \brief Object 0x1604 (PDO4_FrameVerifySegment process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x7040.1<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1604[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex1 - Reference to 0x7040.1 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1604[] = "PDO4_FrameVerifySegment process data mapping\000"
"SubIndex 001\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x7040.1 */
} OBJ_STRUCT_PACKED_END
TOBJ1604;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1604 PDO4_FrameVerifySegmentProcessDataMapping0x1604
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={1,0x70400120}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A00 : PDI0_TimeStamp process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A00 0x1A00 | PDI0_TimeStamp process data mapping
* @{
* \brief Object 0x1A00 (PDI0_TimeStamp process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6000.1<br>
* SubIndex 2 - Reference to 0x6000.2<br>
* SubIndex 3 - Reference to 0x6000.3<br>
* SubIndex 4 - Reference to 0x6000.4<br>
* SubIndex 5 - Reference to 0x6000.5<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A00[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x6000.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - Reference to 0x6000.2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 - Reference to 0x6000.3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex4 - Reference to 0x6000.4 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex5 - Reference to 0x6000.5 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A00[] = "PDI0_TimeStamp process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000"
"SubIndex 005\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6000.1 */
UINT32 SI2; /* Subindex2 - Reference to 0x6000.2 */
UINT32 SI3; /* Subindex3 - Reference to 0x6000.3 */
UINT32 SI4; /* Subindex4 - Reference to 0x6000.4 */
UINT32 SI5; /* Subindex5 - Reference to 0x6000.5 */
} OBJ_STRUCT_PACKED_END
TOBJ1A00;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A00 PDI0_TimeStampProcessDataMapping0x1A00
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={5,0x60000120,0x60000208,0x60000308,0x60000408,0x60000508}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A01 : PDI1_ModeSegment process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A01 0x1A01 | PDI1_ModeSegment process data mapping
* @{
* \brief Object 0x1A01 (PDI1_ModeSegment process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6010.1<br>
* SubIndex 2 - Reference to 0x6010.2<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A01[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x6010.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex2 - Reference to 0x6010.2 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A01[] = "PDI1_ModeSegment process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6010.1 */
UINT32 SI2; /* Subindex2 - Reference to 0x6010.2 */
} OBJ_STRUCT_PACKED_END
TOBJ1A01;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A01 PDI1_ModeSegmentProcessDataMapping0x1A01
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={2,0x60100108,0x60100208}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A02 : PDI2_StatusSegment process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A02 0x1A02 | PDI2_StatusSegment process data mapping
* @{
* \brief Object 0x1A02 (PDI2_StatusSegment process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6020.1<br>
* SubIndex 2 - Reference to 0x6020.2<br>
* SubIndex 3 - Reference to 0x6020.3<br>
* SubIndex 4 - Reference to 0x6020.4<br>
* SubIndex 5 - Reference to 0x6020.5<br>
* SubIndex 6 - Reference to 0x6020.6<br>
* SubIndex 7 - Reference to 0x6020.7<br>
* SubIndex 8 - Reference to 0x6020.8<br>
* SubIndex 9 - Reference to 0x6020.9<br>
* SubIndex 10 - Reference to 0x6020.10<br>
* SubIndex 11 - Reference to 0x6020.11<br>
* SubIndex 12 - Reference to 0x6020.12<br>
* SubIndex 13 - Reference to 0x6020.13<br>
* SubIndex 14 - Reference to 0x6020.14<br>
* SubIndex 15 - Reference to 0x6020.15<br>
* SubIndex 16 - Reference to 0x6020.16<br>
* SubIndex 17 - Reference to 0x6020.17<br>
* SubIndex 18 - Reference to 0x6020.18<br>
* SubIndex 19 - Reference to 0x6020.19<br>
* SubIndex 20 - Reference to 0x6020.20<br>
* SubIndex 21 - Reference to 0x6020.21<br>
* SubIndex 22 - Reference to 0x6020.22<br>
* SubIndex 23 - Reference to 0x6020.23<br>
* SubIndex 24 - Reference to 0x6020.24<br>
* SubIndex 25 - Reference to 0x6020.25<br>
* SubIndex 26 - Reference to 0x6020.26<br>
* SubIndex 27 - Reference to 0x6020.27<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A02[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x6020.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - Reference to 0x6020.2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 - Reference to 0x6020.3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex4 - Reference to 0x6020.4 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex5 - Reference to 0x6020.5 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex6 - Reference to 0x6020.6 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex7 - Reference to 0x6020.7 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex8 - Reference to 0x6020.8 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex9 - Reference to 0x6020.9 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex10 - Reference to 0x6020.10 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex11 - Reference to 0x6020.11 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex12 - Reference to 0x6020.12 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex13 - Reference to 0x6020.13 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex14 - Reference to 0x6020.14 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex15 - Reference to 0x6020.15 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex16 - Reference to 0x6020.16 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex17 - Reference to 0x6020.17 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex18 - Reference to 0x6020.18 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex19 - Reference to 0x6020.19 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex20 - Reference to 0x6020.20 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex21 - Reference to 0x6020.21 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex22 - Reference to 0x6020.22 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex23 - Reference to 0x6020.23 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex24 - Reference to 0x6020.24 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex25 - Reference to 0x6020.25 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex26 - Reference to 0x6020.26 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex27 - Reference to 0x6020.27 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A02[] = "PDI2_StatusSegment process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000"
"SubIndex 005\000"
"SubIndex 006\000"
"SubIndex 007\000"
"SubIndex 008\000"
"SubIndex 009\000"
"SubIndex 010\000"
"SubIndex 011\000"
"SubIndex 012\000"
"SubIndex 013\000"
"SubIndex 014\000"
"SubIndex 015\000"
"SubIndex 016\000"
"SubIndex 017\000"
"SubIndex 018\000"
"SubIndex 019\000"
"SubIndex 020\000"
"SubIndex 021\000"
"SubIndex 022\000"
"SubIndex 023\000"
"SubIndex 024\000"
"SubIndex 025\000"
"SubIndex 026\000"
"SubIndex 027\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6020.1 */
UINT32 SI2; /* Subindex2 - Reference to 0x6020.2 */
UINT32 SI3; /* Subindex3 - Reference to 0x6020.3 */
UINT32 SI4; /* Subindex4 - Reference to 0x6020.4 */
UINT32 SI5; /* Subindex5 - Reference to 0x6020.5 */
UINT32 SI6; /* Subindex6 - Reference to 0x6020.6 */
UINT32 SI7; /* Subindex7 - Reference to 0x6020.7 */
UINT32 SI8; /* Subindex8 - Reference to 0x6020.8 */
UINT32 SI9; /* Subindex9 - Reference to 0x6020.9 */
UINT32 SI10; /* Subindex10 - Reference to 0x6020.10 */
UINT32 SI11; /* Subindex11 - Reference to 0x6020.11 */
UINT32 SI12; /* Subindex12 - Reference to 0x6020.12 */
UINT32 SI13; /* Subindex13 - Reference to 0x6020.13 */
UINT32 SI14; /* Subindex14 - Reference to 0x6020.14 */
UINT32 SI15; /* Subindex15 - Reference to 0x6020.15 */
UINT32 SI16; /* Subindex16 - Reference to 0x6020.16 */
UINT32 SI17; /* Subindex17 - Reference to 0x6020.17 */
UINT32 SI18; /* Subindex18 - Reference to 0x6020.18 */
UINT32 SI19; /* Subindex19 - Reference to 0x6020.19 */
UINT32 SI20; /* Subindex20 - Reference to 0x6020.20 */
UINT32 SI21; /* Subindex21 - Reference to 0x6020.21 */
UINT32 SI22; /* Subindex22 - Reference to 0x6020.22 */
UINT32 SI23; /* Subindex23 - Reference to 0x6020.23 */
UINT32 SI24; /* Subindex24 - Reference to 0x6020.24 */
UINT32 SI25; /* Subindex25 - Reference to 0x6020.25 */
UINT32 SI26; /* Subindex26 - Reference to 0x6020.26 */
UINT32 SI27; /* Subindex27 - Reference to 0x6020.27 */
} OBJ_STRUCT_PACKED_END
TOBJ1A02;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A02 PDI2_StatusSegmentProcessDataMapping0x1A02
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={27,0x60200108,0x60200208,0x60200308,0x60200408,0x60200508,0x60200608,0x60200708,0x60200808,0x60200908,0x60200A08,0x60200B08,0x60200C08,0x60200D08,0x60200E08,0x60200F08,0x60201008,0x60201108,0x60201208,0x60201308,0x60201408,0x60201508,0x60201608,0x60201708,0x60201808,0x60201908,0x60201A08,0x60201B08}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A03 : PDI3_FeedbackDataSegment process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A03 0x1A03 | PDI3_FeedbackDataSegment process data mapping
* @{
* \brief Object 0x1A03 (PDI3_FeedbackDataSegment process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6030.1<br>
* SubIndex 2 - Reference to 0x6030.2<br>
* SubIndex 3 - Reference to 0x6030.3<br>
* SubIndex 4 - Reference to 0x6030.4<br>
* SubIndex 5 - Reference to 0x6030.5<br>
* SubIndex 6 - Reference to 0x6030.6<br>
* SubIndex 7 - Reference to 0x6030.7<br>
* SubIndex 8 - Reference to 0x6030.8<br>
* SubIndex 9 - Reference to 0x6030.9<br>
* SubIndex 10 - Reference to 0x6030.10<br>
* SubIndex 11 - Reference to 0x6030.11<br>
* SubIndex 12 - Reference to 0x6030.12<br>
* SubIndex 13 - Reference to 0x6030.13<br>
* SubIndex 14 - Reference to 0x6030.14<br>
* SubIndex 15 - Reference to 0x6030.15<br>
* SubIndex 16 - Reference to 0x6030.16<br>
* SubIndex 17 - Reference to 0x6030.17<br>
* SubIndex 18 - Reference to 0x6030.18<br>
* SubIndex 19 - Reference to 0x6030.19<br>
* SubIndex 20 - Reference to 0x6030.20<br>
* SubIndex 21 - Reference to 0x6030.21<br>
* SubIndex 22 - Reference to 0x6030.22<br>
* SubIndex 23 - Reference to 0x6030.23<br>
* SubIndex 24 - Reference to 0x6030.24<br>
* SubIndex 25 - Reference to 0x6030.25<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A03[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x6030.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - Reference to 0x6030.2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 - Reference to 0x6030.3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex4 - Reference to 0x6030.4 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex5 - Reference to 0x6030.5 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex6 - Reference to 0x6030.6 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex7 - Reference to 0x6030.7 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex8 - Reference to 0x6030.8 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex9 - Reference to 0x6030.9 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex10 - Reference to 0x6030.10 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex11 - Reference to 0x6030.11 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex12 - Reference to 0x6030.12 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex13 - Reference to 0x6030.13 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex14 - Reference to 0x6030.14 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex15 - Reference to 0x6030.15 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex16 - Reference to 0x6030.16 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex17 - Reference to 0x6030.17 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex18 - Reference to 0x6030.18 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex19 - Reference to 0x6030.19 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex20 - Reference to 0x6030.20 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex21 - Reference to 0x6030.21 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex22 - Reference to 0x6030.22 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex23 - Reference to 0x6030.23 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex24 - Reference to 0x6030.24 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex25 - Reference to 0x6030.25 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A03[] = "PDI3_FeedbackDataSegment process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000"
"SubIndex 005\000"
"SubIndex 006\000"
"SubIndex 007\000"
"SubIndex 008\000"
"SubIndex 009\000"
"SubIndex 010\000"
"SubIndex 011\000"
"SubIndex 012\000"
"SubIndex 013\000"
"SubIndex 014\000"
"SubIndex 015\000"
"SubIndex 016\000"
"SubIndex 017\000"
"SubIndex 018\000"
"SubIndex 019\000"
"SubIndex 020\000"
"SubIndex 021\000"
"SubIndex 022\000"
"SubIndex 023\000"
"SubIndex 024\000"
"SubIndex 025\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6030.1 */
UINT32 SI2; /* Subindex2 - Reference to 0x6030.2 */
UINT32 SI3; /* Subindex3 - Reference to 0x6030.3 */
UINT32 SI4; /* Subindex4 - Reference to 0x6030.4 */
UINT32 SI5; /* Subindex5 - Reference to 0x6030.5 */
UINT32 SI6; /* Subindex6 - Reference to 0x6030.6 */
UINT32 SI7; /* Subindex7 - Reference to 0x6030.7 */
UINT32 SI8; /* Subindex8 - Reference to 0x6030.8 */
UINT32 SI9; /* Subindex9 - Reference to 0x6030.9 */
UINT32 SI10; /* Subindex10 - Reference to 0x6030.10 */
UINT32 SI11; /* Subindex11 - Reference to 0x6030.11 */
UINT32 SI12; /* Subindex12 - Reference to 0x6030.12 */
UINT32 SI13; /* Subindex13 - Reference to 0x6030.13 */
UINT32 SI14; /* Subindex14 - Reference to 0x6030.14 */
UINT32 SI15; /* Subindex15 - Reference to 0x6030.15 */
UINT32 SI16; /* Subindex16 - Reference to 0x6030.16 */
UINT32 SI17; /* Subindex17 - Reference to 0x6030.17 */
UINT32 SI18; /* Subindex18 - Reference to 0x6030.18 */
UINT32 SI19; /* Subindex19 - Reference to 0x6030.19 */
UINT32 SI20; /* Subindex20 - Reference to 0x6030.20 */
UINT32 SI21; /* Subindex21 - Reference to 0x6030.21 */
UINT32 SI22; /* Subindex22 - Reference to 0x6030.22 */
UINT32 SI23; /* Subindex23 - Reference to 0x6030.23 */
UINT32 SI24; /* Subindex24 - Reference to 0x6030.24 */
UINT32 SI25; /* Subindex25 - Reference to 0x6030.25 */
} OBJ_STRUCT_PACKED_END
TOBJ1A03;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A03 PDI3_FeedbackDataSegmentProcessDataMapping0x1A03
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={25,0x60300120,0x60300220,0x60300320,0x60300420,0x60300520,0x60300620,0x60300720,0x60300820,0x60300920,0x60300A20,0x60300B20,0x60300C20,0x60300D20,0x60300E20,0x60300F20,0x60301020,0x60301120,0x60301220,0x60301320,0x60301420,0x60301520,0x60301620,0x60301720,0x60301820,0x60301920}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A04 : PDI4_FrameVerifySegment process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A04 0x1A04 | PDI4_FrameVerifySegment process data mapping
* @{
* \brief Object 0x1A04 (PDI4_FrameVerifySegment process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6040.1<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A04[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex1 - Reference to 0x6040.1 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A04[] = "PDI4_FrameVerifySegment process data mapping\000"
"SubIndex 001\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6040.1 */
} OBJ_STRUCT_PACKED_END
TOBJ1A04;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A04 PDI4_FrameVerifySegmentProcessDataMapping0x1A04
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={1,0x60400120}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1C12 : SyncManager 2 assignment
******************************************************************************/
/**
* \addtogroup 0x1C12 0x1C12 | SyncManager 2 assignment
* @{
* \brief Object 0x1C12 (SyncManager 2 assignment) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
* 
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1C12[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x1C12[] = "SyncManager 2 assignment\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[5];  /**< \brief Subindex 1 - 5 */
} OBJ_STRUCT_PACKED_END
TOBJ1C12;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C12 sRxPDOassign
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={5,{0x1600,0x1601,0x1602,0x1603,0x1604}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1C13 : SyncManager 3 assignment
******************************************************************************/
/**
* \addtogroup 0x1C13 0x1C13 | SyncManager 3 assignment
* @{
* \brief Object 0x1C13 (SyncManager 3 assignment) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
* 
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1C13[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x1C13[] = "SyncManager 3 assignment\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[5];  /**< \brief Subindex 1 - 5 */
} OBJ_STRUCT_PACKED_END
TOBJ1C13;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C13 sTxPDOassign
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={5,{0x1A00,0x1A01,0x1A02,0x1A03,0x1A04}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6000 : PDI0_TimeStamp
******************************************************************************/
/**
* \addtogroup 0x6000 0x6000 | PDI0_TimeStamp
* @{
* \brief Object 0x6000 (PDI0_TimeStamp) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - IsrTicker<br>
* SubIndex 2 - Ts<br>
* SubIndex 3 - Ack<br>
* SubIndex 4 - Reserve1<br>
* SubIndex 5 - Reserve2<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex1 - IsrTicker */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex2 - Ts */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex3 - Ack */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex4 - Reserve1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }}; /* Subindex5 - Reserve2 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6000[] = "PDI0_TimeStamp\000"
"IsrTicker\000"
"Ts\000"
"Ack\000"
"Reserve1\000"
"Reserve2\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 IsrTicker; /* Subindex1 - IsrTicker */
UINT8 Ts; /* Subindex2 - Ts */
UINT8 Ack; /* Subindex3 - Ack */
UINT8 Reserve1; /* Subindex4 - Reserve1 */
UINT8 Reserve2; /* Subindex5 - Reserve2 */
} OBJ_STRUCT_PACKED_END
TOBJ6000;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6000 PDI0_TimeStamp0x6000
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={5,0x00000000,0x00,0x00,0x00,0x00}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6010 : PDI1_ModeSegment
******************************************************************************/
/**
* \addtogroup 0x6010 0x6010 | PDI1_ModeSegment
* @{
* \brief Object 0x6010 (PDI1_ModeSegment) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - ConfigMode<br>
* SubIndex 2 - RunMode<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6010[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex1 - ConfigMode */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }}; /* Subindex2 - RunMode */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6010[] = "PDI1_ModeSegment\000"
"ConfigMode\000"
"RunMode\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT8 ConfigMode; /* Subindex1 - ConfigMode */
UINT8 RunMode; /* Subindex2 - RunMode */
} OBJ_STRUCT_PACKED_END
TOBJ6010;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6010 PDI1_ModeSegment0x6010
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={2,0x00,0x00}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6020 : PDI2_StatusSegment
******************************************************************************/
/**
* \addtogroup 0x6020 0x6020 | PDI2_StatusSegment
* @{
* \brief Object 0x6020 (PDI2_StatusSegment) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - EMGFLAG<br>
* SubIndex 2 - ProtectionCode1<br>
* SubIndex 3 - ProtectionCode2<br>
* SubIndex 4 - ProtectionCode3<br>
* SubIndex 5 - ProtectionCode4<br>
* SubIndex 6 - ProtectionCode5<br>
* SubIndex 7 - ProtectionCode6<br>
* SubIndex 8 - ProtectionCode7<br>
* SubIndex 9 - ProtectionCode8<br>
* SubIndex 10 - ProtectionCode9<br>
* SubIndex 11 - ProtectionCode10<br>
* SubIndex 12 - ProtectionCode11<br>
* SubIndex 13 - ProtectionCode12<br>
* SubIndex 14 - ProtectionCode13<br>
* SubIndex 15 - ProtectionCode14<br>
* SubIndex 16 - ProtectionCode15<br>
* SubIndex 17 - ProtectionCode16<br>
* SubIndex 18 - Reserve1<br>
* SubIndex 19 - Reserve2<br>
* SubIndex 20 - Reserve3<br>
* SubIndex 21 - Reserve4<br>
* SubIndex 22 - Reserve5<br>
* SubIndex 23 - Reserve6<br>
* SubIndex 24 - Reserve7<br>
* SubIndex 25 - Reserve8<br>
* SubIndex 26 - Reserve9<br>
* SubIndex 27 - ReserveA<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6020[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex1 - EMGFLAG */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex2 - ProtectionCode1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex3 - ProtectionCode2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex4 - ProtectionCode3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex5 - ProtectionCode4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex6 - ProtectionCode5 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex7 - ProtectionCode6 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex8 - ProtectionCode7 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex9 - ProtectionCode8 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex10 - ProtectionCode9 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex11 - ProtectionCode10 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex12 - ProtectionCode11 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex13 - ProtectionCode12 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex14 - ProtectionCode13 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex15 - ProtectionCode14 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex16 - ProtectionCode15 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex17 - ProtectionCode16 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex18 - Reserve1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex19 - Reserve2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex20 - Reserve3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex21 - Reserve4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex22 - Reserve5 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex23 - Reserve6 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex24 - Reserve7 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex25 - Reserve8 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex26 - Reserve9 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }}; /* Subindex27 - ReserveA */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6020[] = "PDI2_StatusSegment\000"
"EMGFLAG\000"
"ProtectionCode1\000"
"ProtectionCode2\000"
"ProtectionCode3\000"
"ProtectionCode4\000"
"ProtectionCode5\000"
"ProtectionCode6\000"
"ProtectionCode7\000"
"ProtectionCode8\000"
"ProtectionCode9\000"
"ProtectionCode10\000"
"ProtectionCode11\000"
"ProtectionCode12\000"
"ProtectionCode13\000"
"ProtectionCode14\000"
"ProtectionCode15\000"
"ProtectionCode16\000"
"Reserve1\000"
"Reserve2\000"
"Reserve3\000"
"Reserve4\000"
"Reserve5\000"
"Reserve6\000"
"Reserve7\000"
"Reserve8\000"
"Reserve9\000"
"ReserveA\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT8 EMGFLAG; /* Subindex1 - EMGFLAG */
UINT8 ProtectionCode1; /* Subindex2 - ProtectionCode1 */
UINT8 ProtectionCode2; /* Subindex3 - ProtectionCode2 */
UINT8 ProtectionCode3; /* Subindex4 - ProtectionCode3 */
UINT8 ProtectionCode4; /* Subindex5 - ProtectionCode4 */
UINT8 ProtectionCode5; /* Subindex6 - ProtectionCode5 */
UINT8 ProtectionCode6; /* Subindex7 - ProtectionCode6 */
UINT8 ProtectionCode7; /* Subindex8 - ProtectionCode7 */
UINT8 ProtectionCode8; /* Subindex9 - ProtectionCode8 */
UINT8 ProtectionCode9; /* Subindex10 - ProtectionCode9 */
UINT8 ProtectionCode10; /* Subindex11 - ProtectionCode10 */
UINT8 ProtectionCode11; /* Subindex12 - ProtectionCode11 */
UINT8 ProtectionCode12; /* Subindex13 - ProtectionCode12 */
UINT8 ProtectionCode13; /* Subindex14 - ProtectionCode13 */
UINT8 ProtectionCode14; /* Subindex15 - ProtectionCode14 */
UINT8 ProtectionCode15; /* Subindex16 - ProtectionCode15 */
UINT8 ProtectionCode16; /* Subindex17 - ProtectionCode16 */
UINT8 Reserve1; /* Subindex18 - Reserve1 */
UINT8 Reserve2; /* Subindex19 - Reserve2 */
UINT8 Reserve3; /* Subindex20 - Reserve3 */
UINT8 Reserve4; /* Subindex21 - Reserve4 */
UINT8 Reserve5; /* Subindex22 - Reserve5 */
UINT8 Reserve6; /* Subindex23 - Reserve6 */
UINT8 Reserve7; /* Subindex24 - Reserve7 */
UINT8 Reserve8; /* Subindex25 - Reserve8 */
UINT8 Reserve9; /* Subindex26 - Reserve9 */
UINT8 ReserveA; /* Subindex27 - ReserveA */
} OBJ_STRUCT_PACKED_END
TOBJ6020;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6020 PDI2_StatusSegment0x6020
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={27,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6030 : PDI3_FeedbackDataSegment
******************************************************************************/
/**
* \addtogroup 0x6030 0x6030 | PDI3_FeedbackDataSegment
* @{
* \brief Object 0x6030 (PDI3_FeedbackDataSegment) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - posFdb<br>
* SubIndex 2 - spFdb<br>
* SubIndex 3 - iqFdb<br>
* SubIndex 4 - idFdb<br>
* SubIndex 5 - iaFdb<br>
* SubIndex 6 - ibFdb<br>
* SubIndex 7 - posRef<br>
* SubIndex 8 - spdRef<br>
* SubIndex 9 - iqRef<br>
* SubIndex 10 - idRef<br>
* SubIndex 11 - posOut<br>
* SubIndex 12 - spOut<br>
* SubIndex 13 - iqOut<br>
* SubIndex 14 - idOut<br>
* SubIndex 15 - Encoder<br>
* SubIndex 16 - Reserve0<br>
* SubIndex 17 - Reserve1<br>
* SubIndex 18 - Reserve2<br>
* SubIndex 19 - Reserve3<br>
* SubIndex 20 - Reserve4<br>
* SubIndex 21 - Reserve5<br>
* SubIndex 22 - Reserve6<br>
* SubIndex 23 - Reserve7<br>
* SubIndex 24 - Reserve8<br>
* SubIndex 25 - Reserve9<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6030[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex1 - posFdb */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex2 - spFdb */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex3 - iqFdb */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex4 - idFdb */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex5 - iaFdb */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex6 - ibFdb */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex7 - posRef */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex8 - spdRef */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex9 - iqRef */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex10 - idRef */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex11 - posOut */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex12 - spOut */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex13 - iqOut */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex14 - idOut */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex15 - Encoder */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex16 - Reserve0 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex17 - Reserve1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex18 - Reserve2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex19 - Reserve3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex20 - Reserve4 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex21 - Reserve5 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex22 - Reserve6 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex23 - Reserve7 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex24 - Reserve8 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }}; /* Subindex25 - Reserve9 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6030[] = "PDI3_FeedbackDataSegment\000"
"posFdb\000"
"spFdb\000"
"iqFdb\000"
"idFdb\000"
"iaFdb\000"
"ibFdb\000"
"posRef\000"
"spdRef\000"
"iqRef\000"
"idRef\000"
"posOut\000"
"spOut\000"
"iqOut\000"
"idOut\000"
"Encoder\000"
"Reserve0\000"
"Reserve1\000"
"Reserve2\000"
"Reserve3\000"
"Reserve4\000"
"Reserve5\000"
"Reserve6\000"
"Reserve7\000"
"Reserve8\000"
"Reserve9\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 PosFdb; /* Subindex1 - posFdb */
UINT32 SpFdb; /* Subindex2 - spFdb */
UINT32 IqFdb; /* Subindex3 - iqFdb */
UINT32 IdFdb; /* Subindex4 - idFdb */
UINT32 IaFdb; /* Subindex5 - iaFdb */
UINT32 IbFdb; /* Subindex6 - ibFdb */
UINT32 PosRef; /* Subindex7 - posRef */
UINT32 SpdRef; /* Subindex8 - spdRef */
UINT32 IqRef; /* Subindex9 - iqRef */
UINT32 IdRef; /* Subindex10 - idRef */
UINT32 PosOut; /* Subindex11 - posOut */
UINT32 SpOut; /* Subindex12 - spOut */
UINT32 IqOut; /* Subindex13 - iqOut */
UINT32 IdOut; /* Subindex14 - idOut */
UINT32 Encoder; /* Subindex15 - Encoder */
UINT32 Reserve0; /* Subindex16 - Reserve0 */
UINT32 Reserve1; /* Subindex17 - Reserve1 */
UINT32 Reserve2; /* Subindex18 - Reserve2 */
UINT32 Reserve3; /* Subindex19 - Reserve3 */
UINT32 Reserve4; /* Subindex20 - Reserve4 */
UINT32 Reserve5; /* Subindex21 - Reserve5 */
UINT32 Reserve6; /* Subindex22 - Reserve6 */
UINT32 Reserve7; /* Subindex23 - Reserve7 */
UINT32 Reserve8; /* Subindex24 - Reserve8 */
UINT32 Reserve9; /* Subindex25 - Reserve9 */
} OBJ_STRUCT_PACKED_END
TOBJ6030;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6030 PDI3_FeedbackDataSegment0x6030
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={25,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6040 : PDI4_FrameVerifySegment
******************************************************************************/
/**
* \addtogroup 0x6040 0x6040 | PDI4_FrameVerifySegment
* @{
* \brief Object 0x6040 (PDI4_FrameVerifySegment) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - CheckSum<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6040[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }}; /* Subindex1 - CheckSum */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6040[] = "PDI4_FrameVerifySegment\000"
"CheckSum\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 CheckSum; /* Subindex1 - CheckSum */
} OBJ_STRUCT_PACKED_END
TOBJ6040;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6040 PDI4_FrameVerifySegment0x6040
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={1,0x00000000}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x7000 : PDO0_TimeStamp
******************************************************************************/
/**
* \addtogroup 0x7000 0x7000 | PDO0_TimeStamp
* @{
* \brief Object 0x7000 (PDO0_TimeStamp) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Ts<br>
* SubIndex 2 - Ack<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex1 - Ts */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }}; /* Subindex2 - Ack */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x7000[] = "PDO0_TimeStamp\000"
"Ts\000"
"Ack\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT8 Ts; /* Subindex1 - Ts */
UINT8 Ack; /* Subindex2 - Ack */
} OBJ_STRUCT_PACKED_END
TOBJ7000;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ7000 PDO0_TimeStamp0x7000
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={2,0x00,0x00}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x7010 : PDO1_ModeSegment
******************************************************************************/
/**
* \addtogroup 0x7010 0x7010 | PDO1_ModeSegment
* @{
* \brief Object 0x7010 (PDO1_ModeSegment) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - ConfigMode<br>
* SubIndex 2 - RunMode<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7010[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex1 - ConfigMode */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }}; /* Subindex2 - RunMode */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x7010[] = "PDO1_ModeSegment\000"
"ConfigMode\000"
"RunMode\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT8 ConfigMode; /* Subindex1 - ConfigMode */
UINT8 RunMode; /* Subindex2 - RunMode */
} OBJ_STRUCT_PACKED_END
TOBJ7010;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ7010 PDO1_ModeSegment0x7010
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={2,0x00,0x00}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x7020 : PDO2_StatusSegment
******************************************************************************/
/**
* \addtogroup 0x7020 0x7020 | PDO2_StatusSegment
* @{
* \brief Object 0x7020 (PDO2_StatusSegment) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - EMGFLAG<br>
* SubIndex 2 - Reserve0<br>
* SubIndex 3 - Reserve1<br>
* SubIndex 4 - Reserve2<br>
* SubIndex 5 - Reserve3<br>
* SubIndex 6 - Reserve4<br>
* SubIndex 7 - Reserve5<br>
* SubIndex 8 - Reserve6<br>
* SubIndex 9 - Reserve7<br>
* SubIndex 10 - Reserve8<br>
* SubIndex 11 - Reserve9<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7020[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex1 - EMGFLAG */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex2 - Reserve0 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex3 - Reserve1 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex4 - Reserve2 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex5 - Reserve3 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex6 - Reserve4 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex7 - Reserve5 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex8 - Reserve6 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex9 - Reserve7 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex10 - Reserve8 */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }}; /* Subindex11 - Reserve9 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x7020[] = "PDO2_StatusSegment\000"
"EMGFLAG\000"
"Reserve0\000"
"Reserve1\000"
"Reserve2\000"
"Reserve3\000"
"Reserve4\000"
"Reserve5\000"
"Reserve6\000"
"Reserve7\000"
"Reserve8\000"
"Reserve9\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT8 EMGFLAG; /* Subindex1 - EMGFLAG */
UINT8 Reserve0; /* Subindex2 - Reserve0 */
UINT8 Reserve1; /* Subindex3 - Reserve1 */
UINT8 Reserve2; /* Subindex4 - Reserve2 */
UINT8 Reserve3; /* Subindex5 - Reserve3 */
UINT8 Reserve4; /* Subindex6 - Reserve4 */
UINT8 Reserve5; /* Subindex7 - Reserve5 */
UINT8 Reserve6; /* Subindex8 - Reserve6 */
UINT8 Reserve7; /* Subindex9 - Reserve7 */
UINT8 Reserve8; /* Subindex10 - Reserve8 */
UINT8 Reserve9; /* Subindex11 - Reserve9 */
} OBJ_STRUCT_PACKED_END
TOBJ7020;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ7020 PDO2_StatusSegment0x7020
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={11,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x7030 : PDO3_CommandDataSegment
******************************************************************************/
/**
* \addtogroup 0x7030 0x7030 | PDO3_CommandDataSegment
* @{
* \brief Object 0x7030 (PDO3_CommandDataSegment) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - posRef1<br>
* SubIndex 2 - posRef2<br>
* SubIndex 3 - posRef3<br>
* SubIndex 4 - spdRef1<br>
* SubIndex 5 - spdRef2<br>
* SubIndex 6 - spdRef3<br>
* SubIndex 7 - accRef1<br>
* SubIndex 8 - accRef2<br>
* SubIndex 9 - accRef3<br>
* SubIndex 10 - iqRef1<br>
* SubIndex 11 - iqRef2<br>
* SubIndex 12 - iqRef3<br>
* SubIndex 13 - torRef1<br>
* SubIndex 14 - torRef2<br>
* SubIndex 15 - torRef3<br>
* SubIndex 16 - ffdata0<br>
* SubIndex 17 - ffdata1<br>
* SubIndex 18 - ffdata2<br>
* SubIndex 19 - ffdata3<br>
* SubIndex 20 - ffdata4<br>
* SubIndex 21 - ffdata5<br>
* SubIndex 22 - ffdata6<br>
* SubIndex 23 - ffdata7<br>
* SubIndex 24 - ffdata8<br>
* SubIndex 25 - ffdata9<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7030[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex1 - posRef1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex2 - posRef2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex3 - posRef3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex4 - spdRef1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex5 - spdRef2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex6 - spdRef3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex7 - accRef1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex8 - accRef2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex9 - accRef3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex10 - iqRef1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex11 - iqRef2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex12 - iqRef3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex13 - torRef1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex14 - torRef2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex15 - torRef3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex16 - ffdata0 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex17 - ffdata1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex18 - ffdata2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex19 - ffdata3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex20 - ffdata4 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex21 - ffdata5 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex22 - ffdata6 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex23 - ffdata7 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex24 - ffdata8 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }}; /* Subindex25 - ffdata9 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x7030[] = "PDO3_CommandDataSegment\000"
"posRef1\000"
"posRef2\000"
"posRef3\000"
"spdRef1\000"
"spdRef2\000"
"spdRef3\000"
"accRef1\000"
"accRef2\000"
"accRef3\000"
"iqRef1\000"
"iqRef2\000"
"iqRef3\000"
"torRef1\000"
"torRef2\000"
"torRef3\000"
"ffdata0\000"
"ffdata1\000"
"ffdata2\000"
"ffdata3\000"
"ffdata4\000"
"ffdata5\000"
"ffdata6\000"
"ffdata7\000"
"ffdata8\000"
"ffdata9\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 PosRef1; /* Subindex1 - posRef1 */
UINT32 PosRef2; /* Subindex2 - posRef2 */
UINT32 PosRef3; /* Subindex3 - posRef3 */
UINT32 SpdRef1; /* Subindex4 - spdRef1 */
UINT32 SpdRef2; /* Subindex5 - spdRef2 */
UINT32 SpdRef3; /* Subindex6 - spdRef3 */
UINT32 AccRef1; /* Subindex7 - accRef1 */
UINT32 AccRef2; /* Subindex8 - accRef2 */
UINT32 AccRef3; /* Subindex9 - accRef3 */
UINT32 IqRef1; /* Subindex10 - iqRef1 */
UINT32 IqRef2; /* Subindex11 - iqRef2 */
UINT32 IqRef3; /* Subindex12 - iqRef3 */
UINT32 TorRef1; /* Subindex13 - torRef1 */
UINT32 TorRef2; /* Subindex14 - torRef2 */
UINT32 TorRef3; /* Subindex15 - torRef3 */
UINT32 Ffdata0; /* Subindex16 - ffdata0 */
UINT32 Ffdata1; /* Subindex17 - ffdata1 */
UINT32 Ffdata2; /* Subindex18 - ffdata2 */
UINT32 Ffdata3; /* Subindex19 - ffdata3 */
UINT32 Ffdata4; /* Subindex20 - ffdata4 */
UINT32 Ffdata5; /* Subindex21 - ffdata5 */
UINT32 Ffdata6; /* Subindex22 - ffdata6 */
UINT32 Ffdata7; /* Subindex23 - ffdata7 */
UINT32 Ffdata8; /* Subindex24 - ffdata8 */
UINT32 Ffdata9; /* Subindex25 - ffdata9 */
} OBJ_STRUCT_PACKED_END
TOBJ7030;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ7030 PDO3_CommandDataSegment0x7030
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={25,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x7040 : PDO4_FrameVerifySegment
******************************************************************************/
/**
* \addtogroup 0x7040 0x7040 | PDO4_FrameVerifySegment
* @{
* \brief Object 0x7040 (PDO4_FrameVerifySegment) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - CheckSum<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7040[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }}; /* Subindex1 - CheckSum */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x7040[] = "PDO4_FrameVerifySegment\000"
"CheckSum\000\377";
#endif //#ifdef _OBJD_

#ifndef _ASIX__TEST2_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 CheckSum; /* Subindex1 - CheckSum */
} OBJ_STRUCT_PACKED_END
TOBJ7040;
#endif //#ifndef _ASIX__TEST2_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ7040 PDO4_FrameVerifySegment0x7040
#if defined(_ASIX__TEST2_) && (_ASIX__TEST2_ == 1)
={1,0x00000000}
#endif
;
/** @}*/







#ifdef _OBJD_
TOBJECT    OBJMEM ApplicationObjDic[] = {
/* Object 0x1600 */
{NULL , NULL ,  0x1600 , {DEFTYPE_PDOMAPPING , 2 | (OBJCODE_REC << 8)} , asEntryDesc0x1600 , aName0x1600 , &PDO0_TimeStampProcessDataMapping0x1600 , NULL , NULL , 0x0000 },
/* Object 0x1601 */
{NULL , NULL ,  0x1601 , {DEFTYPE_PDOMAPPING , 2 | (OBJCODE_REC << 8)} , asEntryDesc0x1601 , aName0x1601 , &PDO1_ModeSegmentProcessDataMapping0x1601 , NULL , NULL , 0x0000 },
/* Object 0x1602 */
{NULL , NULL ,  0x1602 , {DEFTYPE_PDOMAPPING , 11 | (OBJCODE_REC << 8)} , asEntryDesc0x1602 , aName0x1602 , &PDO2_StatusSegmentProcessDataMapping0x1602 , NULL , NULL , 0x0000 },
/* Object 0x1603 */
{NULL , NULL ,  0x1603 , {DEFTYPE_PDOMAPPING , 25 | (OBJCODE_REC << 8)} , asEntryDesc0x1603 , aName0x1603 , &PDO3_CommandDataSegmentProcessDataMapping0x1603 , NULL , NULL , 0x0000 },
/* Object 0x1604 */
{NULL , NULL ,  0x1604 , {DEFTYPE_PDOMAPPING , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x1604 , aName0x1604 , &PDO4_FrameVerifySegmentProcessDataMapping0x1604 , NULL , NULL , 0x0000 },
/* Object 0x1A00 */
{NULL , NULL ,  0x1A00 , {DEFTYPE_PDOMAPPING , 5 | (OBJCODE_REC << 8)} , asEntryDesc0x1A00 , aName0x1A00 , &PDI0_TimeStampProcessDataMapping0x1A00 , NULL , NULL , 0x0000 },
/* Object 0x1A01 */
{NULL , NULL ,  0x1A01 , {DEFTYPE_PDOMAPPING , 2 | (OBJCODE_REC << 8)} , asEntryDesc0x1A01 , aName0x1A01 , &PDI1_ModeSegmentProcessDataMapping0x1A01 , NULL , NULL , 0x0000 },
/* Object 0x1A02 */
{NULL , NULL ,  0x1A02 , {DEFTYPE_PDOMAPPING , 27 | (OBJCODE_REC << 8)} , asEntryDesc0x1A02 , aName0x1A02 , &PDI2_StatusSegmentProcessDataMapping0x1A02 , NULL , NULL , 0x0000 },
/* Object 0x1A03 */
{NULL , NULL ,  0x1A03 , {DEFTYPE_PDOMAPPING , 25 | (OBJCODE_REC << 8)} , asEntryDesc0x1A03 , aName0x1A03 , &PDI3_FeedbackDataSegmentProcessDataMapping0x1A03 , NULL , NULL , 0x0000 },
/* Object 0x1A04 */
{NULL , NULL ,  0x1A04 , {DEFTYPE_PDOMAPPING , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x1A04 , aName0x1A04 , &PDI4_FrameVerifySegmentProcessDataMapping0x1A04 , NULL , NULL , 0x0000 },
/* Object 0x1C12 */
{NULL , NULL ,  0x1C12 , {DEFTYPE_UNSIGNED16 , 5 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C12 , aName0x1C12 , &sRxPDOassign , NULL , NULL , 0x0000 },
/* Object 0x1C13 */
{NULL , NULL ,  0x1C13 , {DEFTYPE_UNSIGNED16 , 5 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C13 , aName0x1C13 , &sTxPDOassign , NULL , NULL , 0x0000 },
/* Object 0x6000 */
{NULL , NULL ,  0x6000 , {DEFTYPE_RECORD , 5 | (OBJCODE_REC << 8)} , asEntryDesc0x6000 , aName0x6000 , &PDI0_TimeStamp0x6000 , NULL , NULL , 0x0000 },
/* Object 0x6010 */
{NULL , NULL ,  0x6010 , {DEFTYPE_RECORD , 2 | (OBJCODE_REC << 8)} , asEntryDesc0x6010 , aName0x6010 , &PDI1_ModeSegment0x6010 , NULL , NULL , 0x0000 },
/* Object 0x6020 */
{NULL , NULL ,  0x6020 , {DEFTYPE_RECORD , 27 | (OBJCODE_REC << 8)} , asEntryDesc0x6020 , aName0x6020 , &PDI2_StatusSegment0x6020 , NULL , NULL , 0x0000 },
/* Object 0x6030 */
{NULL , NULL ,  0x6030 , {DEFTYPE_RECORD , 25 | (OBJCODE_REC << 8)} , asEntryDesc0x6030 , aName0x6030 , &PDI3_FeedbackDataSegment0x6030 , NULL , NULL , 0x0000 },
/* Object 0x6040 */
{NULL , NULL ,  0x6040 , {DEFTYPE_RECORD , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x6040 , aName0x6040 , &PDI4_FrameVerifySegment0x6040 , NULL , NULL , 0x0000 },
/* Object 0x7000 */
{NULL , NULL ,  0x7000 , {DEFTYPE_RECORD , 2 | (OBJCODE_REC << 8)} , asEntryDesc0x7000 , aName0x7000 , &PDO0_TimeStamp0x7000 , NULL , NULL , 0x0000 },
/* Object 0x7010 */
{NULL , NULL ,  0x7010 , {DEFTYPE_RECORD , 2 | (OBJCODE_REC << 8)} , asEntryDesc0x7010 , aName0x7010 , &PDO1_ModeSegment0x7010 , NULL , NULL , 0x0000 },
/* Object 0x7020 */
{NULL , NULL ,  0x7020 , {DEFTYPE_RECORD , 11 | (OBJCODE_REC << 8)} , asEntryDesc0x7020 , aName0x7020 , &PDO2_StatusSegment0x7020 , NULL , NULL , 0x0000 },
/* Object 0x7030 */
{NULL , NULL ,  0x7030 , {DEFTYPE_RECORD , 25 | (OBJCODE_REC << 8)} , asEntryDesc0x7030 , aName0x7030 , &PDO3_CommandDataSegment0x7030 , NULL , NULL , 0x0000 },
/* Object 0x7040 */
{NULL , NULL ,  0x7040 , {DEFTYPE_RECORD , 1 | (OBJCODE_REC << 8)} , asEntryDesc0x7040 , aName0x7040 , &PDO4_FrameVerifySegment0x7040 , NULL , NULL , 0x0000 },
{NULL,NULL, 0xFFFF, {0, 0}, NULL, NULL, NULL, NULL}};
#endif    //#ifdef _OBJD_
#undef PROTO

/** @}*/
#define _ASIX__TEST2_OBJECTS_H_
