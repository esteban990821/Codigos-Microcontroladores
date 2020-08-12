/*******************************************************************************
* File Name: LCD_SegStatic_1_PM.c
* Version 2.30
*
* Description:
*  This file provides the API source code for Power Management of the Static
*  Segment LCD component.
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


static LCD_SegStatic_1_BACKUP_STRUCT LCD_SegStatic_1_backup;


/*******************************************************************************
* Function Name: LCD_SegStatic_1_SaveConfig
********************************************************************************
*
* Summary:
*  Does nothing, provided for consistency.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void LCD_SegStatic_1_SaveConfig(void) 
{
    /* Nothing to save in current version */
}


/*******************************************************************************
* Function Name: LCD_SegStatic_1_RestoreConfig
********************************************************************************
*
* Summary:
*  Does nothing, provided for consistency.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void LCD_SegStatic_1_RestoreConfig(void) 
{
    /* Nothing to restore in current version */
}


/*******************************************************************************
* Function Name: LCD_SegStatic_1_Sleep
********************************************************************************
*
* Summary:
*  Prepares component for entering the sleep mode.
*
* Parameters:
*  None.

*
* Return:
*  None.
*
* Global variables:
*  LCD_SegStatic_1_enableState - holds a state of the component that will be
*  stored in LCD_SegStatic_1_backup.
*
*  LCD_SegStatic_1_backup - stores the state of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void LCD_SegStatic_1_Sleep(void) 
{
    LCD_SegStatic_1_backup.enableState = LCD_SegStatic_1_enableState;
    LCD_SegStatic_1_SaveConfig();
    LCD_SegStatic_1_Stop();
}


/*******************************************************************************
* Function Name: LCD_SegStatic_1_Wakeup
********************************************************************************
*
* Summary:
*  Wakes component from sleep mode. Configures DMA and enables the component for
*  normal operation.
*
* Parameters:
*  LCD_SegStatic_1_enableState - Global variable.
*
* Global variables:
*  LCD_SegStatic_1_backup - this API fetch the component state from the
*  structure to analyze and decide if the component should be enabled or not.
*
* Return:
*  Status one of standard status for PSoC3 Component:
*       CYRET_SUCCESS - Function completed successfully.
*       CYRET_LOCKED - The object was locked, already in use. Some of TDs or
*                      a channel already in use or the component was turned
*                      off by the user before entering to a sleep.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 LCD_SegStatic_1_Wakeup(void) 
{
    uint8 status;

    LCD_SegStatic_1_RestoreConfig();

    if(LCD_SegStatic_1_backup.enableState == 1u)
    {
       status = LCD_SegStatic_1_Enable();
    }
    else
    {
        status = CYRET_LOCKED;
    }

    return(status);
}


/* [] END OF FILE */
