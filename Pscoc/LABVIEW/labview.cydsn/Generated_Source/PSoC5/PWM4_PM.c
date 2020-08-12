/*******************************************************************************
* File Name: PWM4_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM4.h"

static PWM4_backupStruct PWM4_backup;


/*******************************************************************************
* Function Name: PWM4_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM4_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM4_SaveConfig(void) 
{

    #if(!PWM4_UsingFixedFunction)
        #if(!PWM4_PWMModeIsCenterAligned)
            PWM4_backup.PWMPeriod = PWM4_ReadPeriod();
        #endif /* (!PWM4_PWMModeIsCenterAligned) */
        PWM4_backup.PWMUdb = PWM4_ReadCounter();
        #if (PWM4_UseStatus)
            PWM4_backup.InterruptMaskValue = PWM4_STATUS_MASK;
        #endif /* (PWM4_UseStatus) */

        #if(PWM4_DeadBandMode == PWM4__B_PWM__DBM_256_CLOCKS || \
            PWM4_DeadBandMode == PWM4__B_PWM__DBM_2_4_CLOCKS)
            PWM4_backup.PWMdeadBandValue = PWM4_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM4_KillModeMinTime)
             PWM4_backup.PWMKillCounterPeriod = PWM4_ReadKillTime();
        #endif /* (PWM4_KillModeMinTime) */

        #if(PWM4_UseControl)
            PWM4_backup.PWMControlRegister = PWM4_ReadControlRegister();
        #endif /* (PWM4_UseControl) */
    #endif  /* (!PWM4_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM4_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM4_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM4_RestoreConfig(void) 
{
        #if(!PWM4_UsingFixedFunction)
            #if(!PWM4_PWMModeIsCenterAligned)
                PWM4_WritePeriod(PWM4_backup.PWMPeriod);
            #endif /* (!PWM4_PWMModeIsCenterAligned) */

            PWM4_WriteCounter(PWM4_backup.PWMUdb);

            #if (PWM4_UseStatus)
                PWM4_STATUS_MASK = PWM4_backup.InterruptMaskValue;
            #endif /* (PWM4_UseStatus) */

            #if(PWM4_DeadBandMode == PWM4__B_PWM__DBM_256_CLOCKS || \
                PWM4_DeadBandMode == PWM4__B_PWM__DBM_2_4_CLOCKS)
                PWM4_WriteDeadTime(PWM4_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM4_KillModeMinTime)
                PWM4_WriteKillTime(PWM4_backup.PWMKillCounterPeriod);
            #endif /* (PWM4_KillModeMinTime) */

            #if(PWM4_UseControl)
                PWM4_WriteControlRegister(PWM4_backup.PWMControlRegister);
            #endif /* (PWM4_UseControl) */
        #endif  /* (!PWM4_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM4_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM4_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM4_Sleep(void) 
{
    #if(PWM4_UseControl)
        if(PWM4_CTRL_ENABLE == (PWM4_CONTROL & PWM4_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM4_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM4_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM4_UseControl) */

    /* Stop component */
    PWM4_Stop();

    /* Save registers configuration */
    PWM4_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM4_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM4_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM4_Wakeup(void) 
{
     /* Restore registers values */
    PWM4_RestoreConfig();

    if(PWM4_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM4_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
