/*******************************************************************************
* File Name: filtro2.h  
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

#if !defined(CY_PINS_filtro2_ALIASES_H) /* Pins filtro2_ALIASES_H */
#define CY_PINS_filtro2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define filtro2_0			(filtro2__0__PC)
#define filtro2_0_INTR	((uint16)((uint16)0x0001u << filtro2__0__SHIFT))

#define filtro2_INTR_ALL	 ((uint16)(filtro2_0_INTR))

#endif /* End Pins filtro2_ALIASES_H */


/* [] END OF FILE */
