/*******************************************************************************
* File Name: PWM0_PM.c
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

#include "PWM0.h"

static PWM0_backupStruct PWM0_backup;


/*******************************************************************************
* Function Name: PWM0_SaveConfig
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
*  PWM0_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM0_SaveConfig(void) 
{

    #if(!PWM0_UsingFixedFunction)
        #if(!PWM0_PWMModeIsCenterAligned)
            PWM0_backup.PWMPeriod = PWM0_ReadPeriod();
        #endif /* (!PWM0_PWMModeIsCenterAligned) */
        PWM0_backup.PWMUdb = PWM0_ReadCounter();
        #if (PWM0_UseStatus)
            PWM0_backup.InterruptMaskValue = PWM0_STATUS_MASK;
        #endif /* (PWM0_UseStatus) */

        #if(PWM0_DeadBandMode == PWM0__B_PWM__DBM_256_CLOCKS || \
            PWM0_DeadBandMode == PWM0__B_PWM__DBM_2_4_CLOCKS)
            PWM0_backup.PWMdeadBandValue = PWM0_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM0_KillModeMinTime)
             PWM0_backup.PWMKillCounterPeriod = PWM0_ReadKillTime();
        #endif /* (PWM0_KillModeMinTime) */

        #if(PWM0_UseControl)
            PWM0_backup.PWMControlRegister = PWM0_ReadControlRegister();
        #endif /* (PWM0_UseControl) */
    #endif  /* (!PWM0_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM0_RestoreConfig
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
*  PWM0_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM0_RestoreConfig(void) 
{
        #if(!PWM0_UsingFixedFunction)
            #if(!PWM0_PWMModeIsCenterAligned)
                PWM0_WritePeriod(PWM0_backup.PWMPeriod);
            #endif /* (!PWM0_PWMModeIsCenterAligned) */

            PWM0_WriteCounter(PWM0_backup.PWMUdb);

            #if (PWM0_UseStatus)
                PWM0_STATUS_MASK = PWM0_backup.InterruptMaskValue;
            #endif /* (PWM0_UseStatus) */

            #if(PWM0_DeadBandMode == PWM0__B_PWM__DBM_256_CLOCKS || \
                PWM0_DeadBandMode == PWM0__B_PWM__DBM_2_4_CLOCKS)
                PWM0_WriteDeadTime(PWM0_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM0_KillModeMinTime)
                PWM0_WriteKillTime(PWM0_backup.PWMKillCounterPeriod);
            #endif /* (PWM0_KillModeMinTime) */

            #if(PWM0_UseControl)
                PWM0_WriteControlRegister(PWM0_backup.PWMControlRegister);
            #endif /* (PWM0_UseControl) */
        #endif  /* (!PWM0_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM0_Sleep
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
*  PWM0_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM0_Sleep(void) 
{
    #if(PWM0_UseControl)
        if(PWM0_CTRL_ENABLE == (PWM0_CONTROL & PWM0_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM0_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM0_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM0_UseControl) */

    /* Stop component */
    PWM0_Stop();

    /* Save registers configuration */
    PWM0_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM0_Wakeup
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
*  PWM0_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM0_Wakeup(void) 
{
     /* Restore registers values */
    PWM0_RestoreConfig();

    if(PWM0_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM0_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
