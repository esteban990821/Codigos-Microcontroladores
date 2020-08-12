/*******************************************************************************
* File Name: Display0.c
* Version 2.30
*
* Description:
*  This file provides the pin API source code for the Static Segment LCD
*  component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <Display0_Pins.h>

/*******************************************************************************
* Function Name: Display0_SegPort_SetDriveMode 
********************************************************************************
* Summary:
*  Change the drive mode on the pins of the port.
*
* Parameters:
*  mode: Changes the pins to this drive mode.
*
* Return:
*  void
*
*******************************************************************************/
void Display0_SegPort_SetDriveMode(uint8 mode) 
{
    CyPins_SetPinDriveMode(Display0_SegPort_0, mode);
    CyPins_SetPinDriveMode(Display0_SegPort_1, mode);
    CyPins_SetPinDriveMode(Display0_SegPort_2, mode);
    CyPins_SetPinDriveMode(Display0_SegPort_3, mode);
}

/*******************************************************************************
* Function Name: Display0_ComPort_SetDriveMode 
********************************************************************************
* Summary:
*  Change the drive mode on the pins of the port.
*
* Parameters:
*  mode: Changes the pins to this drive mode.
*
* Return:
*  void
*
*******************************************************************************/
void Display0_ComPort_SetDriveMode(uint8 mode) 
{
    CyPins_SetPinDriveMode(Display0_ComPort_0, mode);
}
/* [] END OF FILE */
