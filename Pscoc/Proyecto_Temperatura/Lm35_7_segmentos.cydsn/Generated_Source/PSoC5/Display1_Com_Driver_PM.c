/*******************************************************************************
* File Name: Display1_Com_Driver_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Display1_Com_Driver.h"

/* Check for removal by optimization */
#if !defined(Display1_Com_Driver_Sync_ctrl_reg__REMOVED)

static Display1_Com_Driver_BACKUP_STRUCT  Display1_Com_Driver_backup = {0u};

    
/*******************************************************************************
* Function Name: Display1_Com_Driver_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Display1_Com_Driver_SaveConfig(void) 
{
    Display1_Com_Driver_backup.controlState = Display1_Com_Driver_Control;
}


/*******************************************************************************
* Function Name: Display1_Com_Driver_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void Display1_Com_Driver_RestoreConfig(void) 
{
     Display1_Com_Driver_Control = Display1_Com_Driver_backup.controlState;
}


/*******************************************************************************
* Function Name: Display1_Com_Driver_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Display1_Com_Driver_Sleep(void) 
{
    Display1_Com_Driver_SaveConfig();
}


/*******************************************************************************
* Function Name: Display1_Com_Driver_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Display1_Com_Driver_Wakeup(void)  
{
    Display1_Com_Driver_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
