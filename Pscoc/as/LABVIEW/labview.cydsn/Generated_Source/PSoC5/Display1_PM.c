/*******************************************************************************
* File Name: Display1_PM.c
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

#include "Display1.h"


static Display1_BACKUP_STRUCT Display1_backup;


/*******************************************************************************
* Function Name: Display1_SaveConfig
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
void Display1_SaveConfig(void) 
{
    /* Nothing to save in current version */
}


/*******************************************************************************
* Function Name: Display1_RestoreConfig
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
void Display1_RestoreConfig(void) 
{
    /* Nothing to restore in current version */
}


/*******************************************************************************
* Function Name: Display1_Sleep
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
*  Display1_enableState - holds a state of the component that will be
*  stored in Display1_backup.
*
*  Display1_backup - stores the state of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Display1_Sleep(void) 
{
    Display1_backup.enableState = Display1_enableState;
    Display1_SaveConfig();
    Display1_Stop();
}


/*******************************************************************************
* Function Name: Display1_Wakeup
********************************************************************************
*
* Summary:
*  Wakes component from sleep mode. Configures DMA and enables the component for
*  normal operation.
*
* Parameters:
*  Display1_enableState - Global variable.
*
* Global variables:
*  Display1_backup - this API fetch the component state from the
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
uint8 Display1_Wakeup(void) 
{
    uint8 status;

    Display1_RestoreConfig();

    if(Display1_backup.enableState == 1u)
    {
       status = Display1_Enable();
    }
    else
    {
        status = CYRET_LOCKED;
    }

    return(status);
}


/* [] END OF FILE */
