/*******************************************************************************
* File Name: Display0_PM.c
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

#include "Display0.h"


static Display0_BACKUP_STRUCT Display0_backup;


/*******************************************************************************
* Function Name: Display0_SaveConfig
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
void Display0_SaveConfig(void) 
{
    /* Nothing to save in current version */
}


/*******************************************************************************
* Function Name: Display0_RestoreConfig
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
void Display0_RestoreConfig(void) 
{
    /* Nothing to restore in current version */
}


/*******************************************************************************
* Function Name: Display0_Sleep
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
*  Display0_enableState - holds a state of the component that will be
*  stored in Display0_backup.
*
*  Display0_backup - stores the state of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Display0_Sleep(void) 
{
    Display0_backup.enableState = Display0_enableState;
    Display0_SaveConfig();
    Display0_Stop();
}


/*******************************************************************************
* Function Name: Display0_Wakeup
********************************************************************************
*
* Summary:
*  Wakes component from sleep mode. Configures DMA and enables the component for
*  normal operation.
*
* Parameters:
*  Display0_enableState - Global variable.
*
* Global variables:
*  Display0_backup - this API fetch the component state from the
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
uint8 Display0_Wakeup(void) 
{
    uint8 status;

    Display0_RestoreConfig();

    if(Display0_backup.enableState == 1u)
    {
       status = Display0_Enable();
    }
    else
    {
        status = CYRET_LOCKED;
    }

    return(status);
}


/* [] END OF FILE */
