/*******************************************************************************
* File Name: Entrada_PM.c
* Version 3.10
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Entrada.h"


/***************************************
* Local data allocation
***************************************/

static Entrada_BACKUP_STRUCT  Entrada_backup =
{
    Entrada_DISABLED
};


/*******************************************************************************
* Function Name: Entrada_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Entrada_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: Entrada_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Entrada_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: Entrada_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The Entrada_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Entrada_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void Entrada_Sleep(void)
{
    if((Entrada_PWRMGR_SAR_REG  & Entrada_ACT_PWR_SAR_EN) != 0u)
    {
        if((Entrada_SAR_CSR0_REG & Entrada_SAR_SOF_START_CONV) != 0u)
        {
            Entrada_backup.enableState = Entrada_ENABLED | Entrada_STARTED;
        }
        else
        {
            Entrada_backup.enableState = Entrada_ENABLED;
        }
        Entrada_Stop();
    }
    else
    {
        Entrada_backup.enableState = Entrada_DISABLED;
    }
}


/*******************************************************************************
* Function Name: Entrada_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  Entrada_Sleep() was called. If the component was enabled before the
*  Entrada_Sleep() function was called, the
*  Entrada_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Entrada_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void Entrada_Wakeup(void)
{
    if(Entrada_backup.enableState != Entrada_DISABLED)
    {
        Entrada_Enable();
        #if(Entrada_DEFAULT_CONV_MODE != Entrada__HARDWARE_TRIGGER)
            if((Entrada_backup.enableState & Entrada_STARTED) != 0u)
            {
                Entrada_StartConvert();
            }
        #endif /* End Entrada_DEFAULT_CONV_MODE != Entrada__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
