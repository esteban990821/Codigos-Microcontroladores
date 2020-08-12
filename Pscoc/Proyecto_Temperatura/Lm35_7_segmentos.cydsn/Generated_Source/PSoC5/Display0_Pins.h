/*******************************************************************************
* File Name: Display0.h
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

#if !defined(CY_ST_SEG_LCD_Display0_PINS_H)
#define CY_ST_SEG_LCD_Display0_PINS_H

#include <cypins.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void Display0_SegPort_SetDriveMode(uint8 mode) ;
void Display0_ComPort_SetDriveMode(uint8 mode) ;


/***************************************
*              Constants
***************************************/
#define Display0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Display0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Display0_DM_RES_UP          PIN_DM_RES_UP
#define Display0_DM_RES_DWN         PIN_DM_RES_DWN
#define Display0_DM_OD_LO           PIN_DM_OD_LO
#define Display0_DM_OD_HI           PIN_DM_OD_HI
#define Display0_DM_STRONG          PIN_DM_STRONG
#define Display0_DM_RES_UPDWN       PIN_DM_RES_UPDWN

#define Display0_SegPort_0            Display0_Seg__0__PC
#define Display0_SegPort_1            Display0_Seg__1__PC
#define Display0_SegPort_2            Display0_Seg__2__PC
#define Display0_SegPort_3            Display0_Seg__3__PC
#define Display0_ComPort_0            Display0_Com__0__PC

#endif /* CY_ST_SEG_LCD_Display0_PINS_H */
