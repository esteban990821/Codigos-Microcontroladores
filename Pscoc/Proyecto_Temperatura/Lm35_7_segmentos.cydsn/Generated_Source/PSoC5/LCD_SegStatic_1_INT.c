/*******************************************************************************
* File Name: LCD_SegStatic_1_INT.c
* Version 2.30
*
* Description:
*  This file contains the Interrupt Service Routine (ISR) for the Static
*  Segment LCD Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "LCD_SegStatic_1.h"
#include "cyapicallbacks.h"

/*`#START START_USER_DECLARATIONS_ISR`*/

/*`#END`*/


/*****************************************************************************
* Function Name:   LCD_SegStatic_1_ISR
******************************************************************************
*
* Summary:
*  This ISR is executed when the sub-frame completion event occurs. Both
*  global interrupts and component interrupts must be enabled to invoke this
*  ISR.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
 ******************************************************************************/
CY_ISR(LCD_SegStatic_1_ISR)
{
    #ifdef LCD_SegStatic_1_ISR_INTERRUPT_CALLBACK
        LCD_SegStatic_1_ISR_InterruptCallback();
    #endif /* LCD_SegStatic_1_ISR_INTERRUPT_CALLBACK */

    /* User code required at start of ISR */
    /*`#START START_ISR`*/

    /*`#END`*/
}


/* [] END OF FILE */
