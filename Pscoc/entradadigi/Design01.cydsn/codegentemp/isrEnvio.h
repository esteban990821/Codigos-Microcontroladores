/*******************************************************************************
* File Name: isrEnvio.h
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
#if !defined(CY_ISR_isrEnvio_H)
#define CY_ISR_isrEnvio_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrEnvio_Start(void);
void isrEnvio_StartEx(cyisraddress address);
void isrEnvio_Stop(void);

CY_ISR_PROTO(isrEnvio_Interrupt);

void isrEnvio_SetVector(cyisraddress address);
cyisraddress isrEnvio_GetVector(void);

void isrEnvio_SetPriority(uint8 priority);
uint8 isrEnvio_GetPriority(void);

void isrEnvio_Enable(void);
uint8 isrEnvio_GetState(void);
void isrEnvio_Disable(void);

void isrEnvio_SetPending(void);
void isrEnvio_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrEnvio ISR. */
#define isrEnvio_INTC_VECTOR            ((reg32 *) isrEnvio__INTC_VECT)

/* Address of the isrEnvio ISR priority. */
#define isrEnvio_INTC_PRIOR             ((reg8 *) isrEnvio__INTC_PRIOR_REG)

/* Priority of the isrEnvio interrupt. */
#define isrEnvio_INTC_PRIOR_NUMBER      isrEnvio__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrEnvio interrupt. */
#define isrEnvio_INTC_SET_EN            ((reg32 *) isrEnvio__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrEnvio interrupt. */
#define isrEnvio_INTC_CLR_EN            ((reg32 *) isrEnvio__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrEnvio interrupt state to pending. */
#define isrEnvio_INTC_SET_PD            ((reg32 *) isrEnvio__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrEnvio interrupt. */
#define isrEnvio_INTC_CLR_PD            ((reg32 *) isrEnvio__INTC_CLR_PD_REG)


#endif /* CY_ISR_isrEnvio_H */


/* [] END OF FILE */
