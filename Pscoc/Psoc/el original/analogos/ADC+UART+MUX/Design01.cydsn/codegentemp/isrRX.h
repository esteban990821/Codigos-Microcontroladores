/*******************************************************************************
* File Name: isrRX.h
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
#if !defined(CY_ISR_isrRX_H)
#define CY_ISR_isrRX_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrRX_Start(void);
void isrRX_StartEx(cyisraddress address);
void isrRX_Stop(void);

CY_ISR_PROTO(isrRX_Interrupt);

void isrRX_SetVector(cyisraddress address);
cyisraddress isrRX_GetVector(void);

void isrRX_SetPriority(uint8 priority);
uint8 isrRX_GetPriority(void);

void isrRX_Enable(void);
uint8 isrRX_GetState(void);
void isrRX_Disable(void);

void isrRX_SetPending(void);
void isrRX_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrRX ISR. */
#define isrRX_INTC_VECTOR            ((reg32 *) isrRX__INTC_VECT)

/* Address of the isrRX ISR priority. */
#define isrRX_INTC_PRIOR             ((reg8 *) isrRX__INTC_PRIOR_REG)

/* Priority of the isrRX interrupt. */
#define isrRX_INTC_PRIOR_NUMBER      isrRX__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrRX interrupt. */
#define isrRX_INTC_SET_EN            ((reg32 *) isrRX__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrRX interrupt. */
#define isrRX_INTC_CLR_EN            ((reg32 *) isrRX__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrRX interrupt state to pending. */
#define isrRX_INTC_SET_PD            ((reg32 *) isrRX__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrRX interrupt. */
#define isrRX_INTC_CLR_PD            ((reg32 *) isrRX__INTC_CLR_PD_REG)


#endif /* CY_ISR_isrRX_H */


/* [] END OF FILE */
