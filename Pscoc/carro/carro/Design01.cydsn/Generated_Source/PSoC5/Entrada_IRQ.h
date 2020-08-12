/*******************************************************************************
* File Name: Entrada_IRQ.h
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
#if !defined(CY_ISR_Entrada_IRQ_H)
#define CY_ISR_Entrada_IRQ_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Entrada_IRQ_Start(void);
void Entrada_IRQ_StartEx(cyisraddress address);
void Entrada_IRQ_Stop(void);

CY_ISR_PROTO(Entrada_IRQ_Interrupt);

void Entrada_IRQ_SetVector(cyisraddress address);
cyisraddress Entrada_IRQ_GetVector(void);

void Entrada_IRQ_SetPriority(uint8 priority);
uint8 Entrada_IRQ_GetPriority(void);

void Entrada_IRQ_Enable(void);
uint8 Entrada_IRQ_GetState(void);
void Entrada_IRQ_Disable(void);

void Entrada_IRQ_SetPending(void);
void Entrada_IRQ_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Entrada_IRQ ISR. */
#define Entrada_IRQ_INTC_VECTOR            ((reg32 *) Entrada_IRQ__INTC_VECT)

/* Address of the Entrada_IRQ ISR priority. */
#define Entrada_IRQ_INTC_PRIOR             ((reg8 *) Entrada_IRQ__INTC_PRIOR_REG)

/* Priority of the Entrada_IRQ interrupt. */
#define Entrada_IRQ_INTC_PRIOR_NUMBER      Entrada_IRQ__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Entrada_IRQ interrupt. */
#define Entrada_IRQ_INTC_SET_EN            ((reg32 *) Entrada_IRQ__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Entrada_IRQ interrupt. */
#define Entrada_IRQ_INTC_CLR_EN            ((reg32 *) Entrada_IRQ__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Entrada_IRQ interrupt state to pending. */
#define Entrada_IRQ_INTC_SET_PD            ((reg32 *) Entrada_IRQ__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Entrada_IRQ interrupt. */
#define Entrada_IRQ_INTC_CLR_PD            ((reg32 *) Entrada_IRQ__INTC_CLR_PD_REG)


#endif /* CY_ISR_Entrada_IRQ_H */


/* [] END OF FILE */
