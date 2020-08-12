/*******************************************************************************
* File Name: Display2_Pins.c
* Version 3.40
*
* Description:
*  This file provides the API source code for the Segment LCD Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2011, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <Display2_Pins.h>

/*******************************************************************************
* Function Name: Display2_SegPort_SetDriveMode
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
void Display2_SegPort_SetDriveMode(uint8 mode) 
{
    CyPins_SetPinDriveMode(Display2_SegPort_0, mode);
    CyPins_SetPinDriveMode(Display2_SegPort_1, mode);
    CyPins_SetPinDriveMode(Display2_SegPort_2, mode);
    CyPins_SetPinDriveMode(Display2_SegPort_3, mode);
    CyPins_SetPinDriveMode(Display2_SegPort_4, mode);
    CyPins_SetPinDriveMode(Display2_SegPort_5, mode);
    CyPins_SetPinDriveMode(Display2_SegPort_6, mode);
}

/*******************************************************************************
* Function Name: Display2_ComPort_SetDriveMode
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
void Display2_ComPort_SetDriveMode(uint8 mode) 
{
    CyPins_SetPinDriveMode(Display2_ComPort_0, mode);
}




/* [] END OF FILE */
