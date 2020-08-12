/*******************************************************************************
* File Name: VDAC1_VDAC8_PM.c  
* Version 1.90
*
* Description:
*  This file provides the power management source code to API for the
*  VDAC8.  
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "VDAC1_VDAC8.h"

static VDAC1_VDAC8_backupStruct VDAC1_VDAC8_backup;


/*******************************************************************************
* Function Name: VDAC1_VDAC8_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void VDAC1_VDAC8_SaveConfig(void) 
{
    if (!((VDAC1_VDAC8_CR1 & VDAC1_VDAC8_SRC_MASK) == VDAC1_VDAC8_SRC_UDB))
    {
        VDAC1_VDAC8_backup.data_value = VDAC1_VDAC8_Data;
    }
}


/*******************************************************************************
* Function Name: VDAC1_VDAC8_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
*******************************************************************************/
void VDAC1_VDAC8_RestoreConfig(void) 
{
    if (!((VDAC1_VDAC8_CR1 & VDAC1_VDAC8_SRC_MASK) == VDAC1_VDAC8_SRC_UDB))
    {
        if((VDAC1_VDAC8_Strobe & VDAC1_VDAC8_STRB_MASK) == VDAC1_VDAC8_STRB_EN)
        {
            VDAC1_VDAC8_Strobe &= (uint8)(~VDAC1_VDAC8_STRB_MASK);
            VDAC1_VDAC8_Data = VDAC1_VDAC8_backup.data_value;
            VDAC1_VDAC8_Strobe |= VDAC1_VDAC8_STRB_EN;
        }
        else
        {
            VDAC1_VDAC8_Data = VDAC1_VDAC8_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: VDAC1_VDAC8_Sleep
********************************************************************************
* Summary:
*  Stop and Save the user configuration
*
* Parameters:  
*  void:  
*
* Return: 
*  void
*
* Global variables:
*  VDAC1_VDAC8_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void VDAC1_VDAC8_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(VDAC1_VDAC8_ACT_PWR_EN == (VDAC1_VDAC8_PWRMGR & VDAC1_VDAC8_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        VDAC1_VDAC8_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        VDAC1_VDAC8_backup.enableState = 0u;
    }
    
    VDAC1_VDAC8_Stop();
    VDAC1_VDAC8_SaveConfig();
}


/*******************************************************************************
* Function Name: VDAC1_VDAC8_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  VDAC1_VDAC8_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void VDAC1_VDAC8_Wakeup(void) 
{
    VDAC1_VDAC8_RestoreConfig();
    
    if(VDAC1_VDAC8_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        VDAC1_VDAC8_Enable();

        /* Restore the data register */
        VDAC1_VDAC8_SetValue(VDAC1_VDAC8_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
