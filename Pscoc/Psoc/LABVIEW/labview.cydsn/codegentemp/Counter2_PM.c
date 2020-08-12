/*******************************************************************************
* File Name: Counter2_PM.c  
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

#include "Counter2.h"

static Counter2_backupStruct Counter2_backup;


/*******************************************************************************
* Function Name: Counter2_SaveConfig
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
*  Counter2_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Counter2_SaveConfig(void) 
{
    #if (!Counter2_UsingFixedFunction)

        Counter2_backup.CounterUdb = Counter2_ReadCounter();

        #if(!Counter2_ControlRegRemoved)
            Counter2_backup.CounterControlRegister = Counter2_ReadControlRegister();
        #endif /* (!Counter2_ControlRegRemoved) */

    #endif /* (!Counter2_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter2_RestoreConfig
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
*  Counter2_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Counter2_RestoreConfig(void) 
{      
    #if (!Counter2_UsingFixedFunction)

       Counter2_WriteCounter(Counter2_backup.CounterUdb);

        #if(!Counter2_ControlRegRemoved)
            Counter2_WriteControlRegister(Counter2_backup.CounterControlRegister);
        #endif /* (!Counter2_ControlRegRemoved) */

    #endif /* (!Counter2_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter2_Sleep
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
*  Counter2_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Counter2_Sleep(void) 
{
    #if(!Counter2_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Counter2_CTRL_ENABLE == (Counter2_CONTROL & Counter2_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Counter2_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Counter2_backup.CounterEnableState = 0u;
        }
    #else
        Counter2_backup.CounterEnableState = 1u;
        if(Counter2_backup.CounterEnableState != 0u)
        {
            Counter2_backup.CounterEnableState = 0u;
        }
    #endif /* (!Counter2_ControlRegRemoved) */
    
    Counter2_Stop();
    Counter2_SaveConfig();
}


/*******************************************************************************
* Function Name: Counter2_Wakeup
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
*  Counter2_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Counter2_Wakeup(void) 
{
    Counter2_RestoreConfig();
    #if(!Counter2_ControlRegRemoved)
        if(Counter2_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Counter2_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Counter2_ControlRegRemoved) */
    
}


/* [] END OF FILE */
