/*******************************************************************************
* File Name: Display2_PM.c
* Version 3.40
*
* Description:
*  This file provides the API source code for Power Management of the Segment
*  LCD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Display2.h"
#include "cyapicallbacks.h"


static Display2_BACKUP_STRUCT Display2_backup;


/*******************************************************************************
* Function Name: Display2_SaveConfig
********************************************************************************
*
* Summary:
*  Stores user data. This function is called by the Display2_Sleep()
*  function prior entering to a Sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Display2_SaveConfig(void) 
{
    /* Nothing to save for current version of the component */

    /* Optional user code */
    /*`#START` SAVE_CONFIG_USER_CODE */

    /*`#END`*/

    #ifdef Display2_SAVE_CONFIG_CALLBACK
        Display2_SaveConfig_Callback();
    #endif /* Display2_SAVE_CONFIG_CALLBACK */
}


/*******************************************************************************
* Function Name: Display2_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores user data. This function is called by the Display2_Wakeup()
*  function after resuming from a Sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Display2_RestoreConfig(void) 
{
    /* Nothing to restore for current version of the component */

    /* Optional user code */
    /*`#START RESTORE_CONFIG_USER_CODE` */

    /*`#END`*/

    #ifdef Display2_RESTORE_CONFIG_CALLBACK
        Display2_RestoreConfig_Callback();
    #endif /* Display2_RESTORE_CONFIG_CALLBACK */
}


/*******************************************************************************
* Function Name: Display2_Sleep
********************************************************************************
*
* Summary:
*  Prepare the component to enter into a Sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  Display2_backup - stores the state of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Display2_Sleep(void) 
{
    if((Display2_CONTROL_REG & Display2_CNTL_CLK_EN) == Display2_CNTL_CLK_EN)
    {
        Display2_backup.enableState = Display2_LCD_STATE_ENABLED;
    }
    else
    {
        Display2_backup.enableState = Display2_LCD_STATE_DISABLED;
    }

    Display2_Stop();
    Display2_SaveConfig();
}


/*******************************************************************************
* Function Name: Display2_Wakeup
********************************************************************************
*
* Summary:
*  Wakes up components from a Sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  Status one of standard status for PSoC3 Component:
*      CYRET_SUCCESS - Function completed successfully.
*      CYRET_LOCKED - The object was locked, already in use. Some of TDs or a
*                     channel already in use or the component was turned off by
*                     the user before entering to a sleep.
*
* Global variables:
*  Display2_backup - this API fetch the component state from the
*  structure to analyze and decide if the component should be enabled or not
*  after waking from a Sleep mode.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 Display2_Wakeup(void) 
{
    uint8 status;

    Display2_RestoreConfig();

    if(Display2_backup.enableState == Display2_LCD_STATE_ENABLED)
    {
        status = Display2_Enable();
    }
    else
    {
        status = CYRET_LOCKED;
    }

    return(status);
}


/* [] END OF FILE */
