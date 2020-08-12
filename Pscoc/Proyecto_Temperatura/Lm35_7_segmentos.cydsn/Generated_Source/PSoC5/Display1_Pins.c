/*******************************************************************************
* File Name: Display1.c
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

#include <Display1_Pins.h>

/*******************************************************************************
* Function Name: Display1_SegPort_SetDriveMode 
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
void Display1_SegPort_SetDriveMode(uint8 mode) 
{
    CyPins_SetPinDriveMode(Display1_SegPort_0, mode);
    CyPins_SetPinDriveMode(Display1_SegPort_1, mode);
    CyPins_SetPinDriveMode(Display1_SegPort_2, mode);
    CyPins_SetPinDriveMode(Display1_SegPort_3, mode);
    CyPins_SetPinDriveMode(Display1_SegPort_4, mode);
    CyPins_SetPinDriveMode(Display1_SegPort_5, mode);
    CyPins_SetPinDriveMode(Display1_SegPort_6, mode);
    CyPins_SetPinDriveMode(Display1_SegPort_7, mode);
    CyPins_SetPinDriveMode(Display1_SegPort_8, mode);
    CyPins_SetPinDriveMode(Display1_SegPort_9, mode);
    CyPins_SetPinDriveMode(Display1_SegPort_10, mode);
    CyPins_SetPinDriveMode(Display1_SegPort_11, mode);
    CyPins_SetPinDriveMode(Display1_SegPort_12, mode);
    CyPins_SetPinDriveMode(Display1_SegPort_13, mode);
}

/*******************************************************************************
* Function Name: Display1_ComPort_SetDriveMode 
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
void Display1_ComPort_SetDriveMode(uint8 mode) 
{
    CyPins_SetPinDriveMode(Display1_ComPort_0, mode);
}
/* [] END OF FILE */
