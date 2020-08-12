/*******************************************************************************
* File Name: israumentar.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_israumentar_H)
#define CY_ISR_israumentar_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void israumentar_Start(void);
void israumentar_StartEx(cyisraddress address);
void israumentar_Stop(void);

CY_ISR_PROTO(israumentar_Interrupt);

void israumentar_SetVector(cyisraddress address);
cyisraddress israumentar_GetVector(void);

void israumentar_SetPriority(uint8 priority);
uint8 israumentar_GetPriority(void);

void israumentar_Enable(void);
uint8 israumentar_GetState(void);
void israumentar_Disable(void);

void israumentar_SetPending(void);
void israumentar_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the israumentar ISR. */
#define israumentar_INTC_VECTOR            ((reg32 *) israumentar__INTC_VECT)

/* Address of the israumentar ISR priority. */
#define israumentar_INTC_PRIOR             ((reg8 *) israumentar__INTC_PRIOR_REG)

/* Priority of the israumentar interrupt. */
#define israumentar_INTC_PRIOR_NUMBER      israumentar__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable israumentar interrupt. */
#define israumentar_INTC_SET_EN            ((reg32 *) israumentar__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the israumentar interrupt. */
#define israumentar_INTC_CLR_EN            ((reg32 *) israumentar__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the israumentar interrupt state to pending. */
#define israumentar_INTC_SET_PD            ((reg32 *) israumentar__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the israumentar interrupt. */
#define israumentar_INTC_CLR_PD            ((reg32 *) israumentar__INTC_CLR_PD_REG)


#endif /* CY_ISR_israumentar_H */


/* [] END OF FILE */
