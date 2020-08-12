/*******************************************************************************
* File Name: Display0_PM.c
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

#include "Display0.h"
#include "cyapicallbacks.h"


static Display0_BACKUP_STRUCT Display0_backup;


/*******************************************************************************
* Function Name: Display0_SaveConfig
********************************************************************************
*
* Summary:
*  Stores user data. This function is called by the Display0_Sleep()
*  function prior entering to a Sleep mode.
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
    /* Nothing to save for current version of the component */

    /* Optional user code */
    /*`#START` SAVE_CONFIG_USER_CODE */

    /*`#END`*/

    #ifdef Display0_SAVE_CONFIG_CALLBACK
        Display0_SaveConfig_Callback();
    #endif /* Display0_SAVE_CONFIG_CALLBACK */
}


/*******************************************************************************
* Function Name: Display0_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores user data. This function is called by the Display0_Wakeup()
*  function after resuming from a Sleep mode.
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
    /* Nothing to restore for current version of the component */

    /* Optional user code */
    /*`#START RESTORE_CONFIG_USER_CODE` */

    /*`#END`*/

    #ifdef Display0_RESTORE_CONFIG_CALLBACK
        Display0_RestoreConfig_Callback();
    #endif /* Display0_RESTORE_CONFIG_CALLBACK */
}


/*******************************************************************************
* Function Name: Display0_Sleep
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
*  Display0_backup - stores the state of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Display0_Sleep(void) 
{
    if((Display0_CONTROL_REG & Display0_CNTL_CLK_EN) == Display0_CNTL_CLK_EN)
    {
        Display0_backup.enableState = Display0_LCD_STATE_ENABLED;
    }
    else
    {
        Display0_backup.enableState = Display0_LCD_STATE_DISABLED;
    }

    Display0_Stop();
    Display0_SaveConfig();
}


/*******************************************************************************
* Function Name: Display0_Wakeup
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
*  Display0_backup - this API fetch the component state from the
*  structure to analyze and decide if the component should be enabled or not
*  after waking from a Sleep mode.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 Display0_Wakeup(void) 
{
    uint8 status;

    Display0_RestoreConfig();

    if(Display0_backup.enableState == Display0_LCD_STATE_ENABLED)
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
