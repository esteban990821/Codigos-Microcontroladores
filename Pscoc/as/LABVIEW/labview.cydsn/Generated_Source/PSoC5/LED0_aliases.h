/*******************************************************************************
* File Name: led0.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_led0_ALIASES_H) /* Pins led0_ALIASES_H */
#define CY_PINS_led0_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define led0_0			(led0__0__PC)
#define led0_0_INTR	((uint16)((uint16)0x0001u << led0__0__SHIFT))

#define led0_INTR_ALL	 ((uint16)(led0_0_INTR))

#endif /* End Pins led0_ALIASES_H */


/* [] END OF FILE */
