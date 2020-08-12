/*******************************************************************************
* File Name: Display1.h
* Version 2.30
*
* Description:
*  This header file contains pins specific definitions associated with the
*  Static Segment LCD component .
*
* Note:
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_ST_SEG_LCD_Display1_PINS_H)
#define CY_ST_SEG_LCD_Display1_PINS_H

#include <cypins.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void Display1_SegPort_SetDriveMode(uint8 mode) ;
void Display1_ComPort_SetDriveMode(uint8 mode) ;


/***************************************
*              Constants
***************************************/
#define Display1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Display1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Display1_DM_RES_UP          PIN_DM_RES_UP
#define Display1_DM_RES_DWN         PIN_DM_RES_DWN
#define Display1_DM_OD_LO           PIN_DM_OD_LO
#define Display1_DM_OD_HI           PIN_DM_OD_HI
#define Display1_DM_STRONG          PIN_DM_STRONG
#define Display1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

#define Display1_SegPort_0            Display1_Seg__0__PC
#define Display1_SegPort_1            Display1_Seg__1__PC
#define Display1_SegPort_2            Display1_Seg__2__PC
#define Display1_SegPort_3            Display1_Seg__3__PC
#define Display1_SegPort_4            Display1_Seg__4__PC
#define Display1_SegPort_5            Display1_Seg__5__PC
#define Display1_SegPort_6            Display1_Seg__6__PC
#define Display1_SegPort_7            Display1_Seg__7__PC
#define Display1_SegPort_8            Display1_Seg__8__PC
#define Display1_SegPort_9            Display1_Seg__9__PC
#define Display1_SegPort_10            Display1_Seg__10__PC
#define Display1_SegPort_11            Display1_Seg__11__PC
#define Display1_SegPort_12            Display1_Seg__12__PC
#define Display1_SegPort_13            Display1_Seg__13__PC
#define Display1_ComPort_0            Display1_Com__0__PC

#endif /* CY_ST_SEG_LCD_Display1_PINS_H */
