/*******************************************************************************
* File Name: isrRx.h
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
#if !defined(CY_ISR_isrRx_H)
#define CY_ISR_isrRx_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrRx_Start(void);
void isrRx_StartEx(cyisraddress address);
void isrRx_Stop(void);

CY_ISR_PROTO(isrRx_Interrupt);

void isrRx_SetVector(cyisraddress address);
cyisraddress isrRx_GetVector(void);

void isrRx_SetPriority(uint8 priority);
uint8 isrRx_GetPriority(void);

void isrRx_Enable(void);
uint8 isrRx_GetState(void);
void isrRx_Disable(void);

void isrRx_SetPending(void);
void isrRx_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrRx ISR. */
#define isrRx_INTC_VECTOR            ((reg32 *) isrRx__INTC_VECT)

/* Address of the isrRx ISR priority. */
#define isrRx_INTC_PRIOR             ((reg8 *) isrRx__INTC_PRIOR_REG)

/* Priority of the isrRx interrupt. */
#define isrRx_INTC_PRIOR_NUMBER      isrRx__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrRx interrupt. */
#define isrRx_INTC_SET_EN            ((reg32 *) isrRx__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrRx interrupt. */
#define isrRx_INTC_CLR_EN            ((reg32 *) isrRx__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrRx interrupt state to pending. */
#define isrRx_INTC_SET_PD            ((reg32 *) isrRx__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrRx interrupt. */
#define isrRx_INTC_CLR_PD            ((reg32 *) isrRx__INTC_CLR_PD_REG)


#endif /* CY_ISR_isrRx_H */


/* [] END OF FILE */
