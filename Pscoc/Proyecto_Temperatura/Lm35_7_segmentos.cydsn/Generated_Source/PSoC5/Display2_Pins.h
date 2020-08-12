/*******************************************************************************
* File Name: Display2_Pins.h
* Version 3.40
*
* Description:
*  This header file contains definitions associated with the Segment LCD
*  Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SEGLCD_Display2_PINS_H)
#define CY_SEGLCD_Display2_PINS_H

#include <cypins.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void Display2_SegPort_SetDriveMode(uint8 mode) ;
void Display2_ComPort_SetDriveMode(uint8 mode) ;


/***************************************
*              Constants
***************************************/
#define Display2_DM_ALG_HIZ         (PIN_DM_ALG_HIZ)
#define Display2_DM_DIG_HIZ         (PIN_DM_DIG_HIZ)
#define Display2_DM_RES_UP          (PIN_DM_RES_UP)
#define Display2_DM_RES_DWN         (PIN_DM_RES_DWN)
#define Display2_DM_OD_LO           (PIN_DM_OD_LO)
#define Display2_DM_OD_HI           (PIN_DM_OD_HI)
#define Display2_DM_STRONG          (PIN_DM_STRONG)
#define Display2_DM_RES_UPDWN       (PIN_DM_RES_UPDWN)

#define Display2_SegPort_0            Display2_Seg__0__PC
#define Display2_SegPort_1            Display2_Seg__1__PC
#define Display2_SegPort_2            Display2_Seg__2__PC
#define Display2_SegPort_3            Display2_Seg__3__PC
#define Display2_SegPort_4            Display2_Seg__4__PC
#define Display2_SegPort_5            Display2_Seg__5__PC
#define Display2_SegPort_6            Display2_Seg__6__PC
#define Display2_ComPort_0            Display2_Com__0__PC


#endif/* CY_SEGLCD_Display2_PINS_H */

/* [] END OF FILE */
