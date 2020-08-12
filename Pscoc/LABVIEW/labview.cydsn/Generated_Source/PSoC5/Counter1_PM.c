/*******************************************************************************
* File Name: Counter1_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Counter1.h"

static Counter1_backupStruct Counter1_backup;


/*******************************************************************************
* Function Name: Counter1_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Counter1_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Counter1_SaveConfig(void) 
{
    #if (!Counter1_UsingFixedFunction)

        Counter1_backup.CounterUdb = Counter1_ReadCounter();

        #if(!Counter1_ControlRegRemoved)
            Counter1_backup.CounterControlRegister = Counter1_ReadControlRegister();
        #endif /* (!Counter1_ControlRegRemoved) */

    #endif /* (!Counter1_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter1_RestoreConfig
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
* Global variables:
*  Counter1_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Counter1_RestoreConfig(void) 
{      
    #if (!Counter1_UsingFixedFunction)

       Counter1_WriteCounter(Counter1_backup.CounterUdb);

        #if(!Counter1_ControlRegRemoved)
            Counter1_WriteControlRegister(Counter1_backup.CounterControlRegister);
        #endif /* (!Counter1_ControlRegRemoved) */

    #endif /* (!Counter1_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter1_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Counter1_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Counter1_Sleep(void) 
{
    #if(!Counter1_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Counter1_CTRL_ENABLE == (Counter1_CONTROL & Counter1_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Counter1_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Counter1_backup.CounterEnableState = 0u;
        }
    #else
        Counter1_backup.CounterEnableState = 1u;
        if(Counter1_backup.CounterEnableState != 0u)
        {
            Counter1_backup.CounterEnableState = 0u;
        }
    #endif /* (!Counter1_ControlRegRemoved) */
    
    Counter1_Stop();
    Counter1_SaveConfig();
}


/*******************************************************************************
* Function Name: Counter1_Wakeup
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
*  Counter1_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Counter1_Wakeup(void) 
{
    Counter1_RestoreConfig();
    #if(!Counter1_ControlRegRemoved)
        if(Counter1_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Counter1_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Counter1_ControlRegRemoved) */
    
}


/* [] END OF FILE */
