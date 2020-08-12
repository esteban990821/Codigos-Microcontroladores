/*******************************************************************************
* File Name: Reloj.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Reloj_H)
#define CY_CLOCK_Reloj_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Reloj_Start(void) ;
void Reloj_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Reloj_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Reloj_StandbyPower(uint8 state) ;
void Reloj_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Reloj_GetDividerRegister(void) ;
void Reloj_SetModeRegister(uint8 modeBitMask) ;
void Reloj_ClearModeRegister(uint8 modeBitMask) ;
uint8 Reloj_GetModeRegister(void) ;
void Reloj_SetSourceRegister(uint8 clkSource) ;
uint8 Reloj_GetSourceRegister(void) ;
#if defined(Reloj__CFG3)
void Reloj_SetPhaseRegister(uint8 clkPhase) ;
uint8 Reloj_GetPhaseRegister(void) ;
#endif /* defined(Reloj__CFG3) */

#define Reloj_Enable()                       Reloj_Start()
#define Reloj_Disable()                      Reloj_Stop()
#define Reloj_SetDivider(clkDivider)         Reloj_SetDividerRegister(clkDivider, 1u)
#define Reloj_SetDividerValue(clkDivider)    Reloj_SetDividerRegister((clkDivider) - 1u, 1u)
#define Reloj_SetMode(clkMode)               Reloj_SetModeRegister(clkMode)
#define Reloj_SetSource(clkSource)           Reloj_SetSourceRegister(clkSource)
#if defined(Reloj__CFG3)
#define Reloj_SetPhase(clkPhase)             Reloj_SetPhaseRegister(clkPhase)
#define Reloj_SetPhaseValue(clkPhase)        Reloj_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Reloj__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Reloj_CLKEN              (* (reg8 *) Reloj__PM_ACT_CFG)
#define Reloj_CLKEN_PTR          ((reg8 *) Reloj__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Reloj_CLKSTBY            (* (reg8 *) Reloj__PM_STBY_CFG)
#define Reloj_CLKSTBY_PTR        ((reg8 *) Reloj__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Reloj_DIV_LSB            (* (reg8 *) Reloj__CFG0)
#define Reloj_DIV_LSB_PTR        ((reg8 *) Reloj__CFG0)
#define Reloj_DIV_PTR            ((reg16 *) Reloj__CFG0)

/* Clock MSB divider configuration register. */
#define Reloj_DIV_MSB            (* (reg8 *) Reloj__CFG1)
#define Reloj_DIV_MSB_PTR        ((reg8 *) Reloj__CFG1)

/* Mode and source configuration register */
#define Reloj_MOD_SRC            (* (reg8 *) Reloj__CFG2)
#define Reloj_MOD_SRC_PTR        ((reg8 *) Reloj__CFG2)

#if defined(Reloj__CFG3)
/* Analog clock phase configuration register */
#define Reloj_PHASE              (* (reg8 *) Reloj__CFG3)
#define Reloj_PHASE_PTR          ((reg8 *) Reloj__CFG3)
#endif /* defined(Reloj__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Reloj_CLKEN_MASK         Reloj__PM_ACT_MSK
#define Reloj_CLKSTBY_MASK       Reloj__PM_STBY_MSK

/* CFG2 field masks */
#define Reloj_SRC_SEL_MSK        Reloj__CFG2_SRC_SEL_MASK
#define Reloj_MODE_MASK          (~(Reloj_SRC_SEL_MSK))

#if defined(Reloj__CFG3)
/* CFG3 phase mask */
#define Reloj_PHASE_MASK         Reloj__CFG3_PHASE_DLY_MASK
#endif /* defined(Reloj__CFG3) */

#endif /* CY_CLOCK_Reloj_H */


/* [] END OF FILE */
