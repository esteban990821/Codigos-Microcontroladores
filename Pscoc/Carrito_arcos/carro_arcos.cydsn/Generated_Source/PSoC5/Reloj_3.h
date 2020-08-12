/*******************************************************************************
* File Name: Reloj_3.h
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

#if !defined(CY_CLOCK_Reloj_3_H)
#define CY_CLOCK_Reloj_3_H

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

void Reloj_3_Start(void) ;
void Reloj_3_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Reloj_3_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Reloj_3_StandbyPower(uint8 state) ;
void Reloj_3_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Reloj_3_GetDividerRegister(void) ;
void Reloj_3_SetModeRegister(uint8 modeBitMask) ;
void Reloj_3_ClearModeRegister(uint8 modeBitMask) ;
uint8 Reloj_3_GetModeRegister(void) ;
void Reloj_3_SetSourceRegister(uint8 clkSource) ;
uint8 Reloj_3_GetSourceRegister(void) ;
#if defined(Reloj_3__CFG3)
void Reloj_3_SetPhaseRegister(uint8 clkPhase) ;
uint8 Reloj_3_GetPhaseRegister(void) ;
#endif /* defined(Reloj_3__CFG3) */

#define Reloj_3_Enable()                       Reloj_3_Start()
#define Reloj_3_Disable()                      Reloj_3_Stop()
#define Reloj_3_SetDivider(clkDivider)         Reloj_3_SetDividerRegister(clkDivider, 1u)
#define Reloj_3_SetDividerValue(clkDivider)    Reloj_3_SetDividerRegister((clkDivider) - 1u, 1u)
#define Reloj_3_SetMode(clkMode)               Reloj_3_SetModeRegister(clkMode)
#define Reloj_3_SetSource(clkSource)           Reloj_3_SetSourceRegister(clkSource)
#if defined(Reloj_3__CFG3)
#define Reloj_3_SetPhase(clkPhase)             Reloj_3_SetPhaseRegister(clkPhase)
#define Reloj_3_SetPhaseValue(clkPhase)        Reloj_3_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Reloj_3__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Reloj_3_CLKEN              (* (reg8 *) Reloj_3__PM_ACT_CFG)
#define Reloj_3_CLKEN_PTR          ((reg8 *) Reloj_3__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Reloj_3_CLKSTBY            (* (reg8 *) Reloj_3__PM_STBY_CFG)
#define Reloj_3_CLKSTBY_PTR        ((reg8 *) Reloj_3__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Reloj_3_DIV_LSB            (* (reg8 *) Reloj_3__CFG0)
#define Reloj_3_DIV_LSB_PTR        ((reg8 *) Reloj_3__CFG0)
#define Reloj_3_DIV_PTR            ((reg16 *) Reloj_3__CFG0)

/* Clock MSB divider configuration register. */
#define Reloj_3_DIV_MSB            (* (reg8 *) Reloj_3__CFG1)
#define Reloj_3_DIV_MSB_PTR        ((reg8 *) Reloj_3__CFG1)

/* Mode and source configuration register */
#define Reloj_3_MOD_SRC            (* (reg8 *) Reloj_3__CFG2)
#define Reloj_3_MOD_SRC_PTR        ((reg8 *) Reloj_3__CFG2)

#if defined(Reloj_3__CFG3)
/* Analog clock phase configuration register */
#define Reloj_3_PHASE              (* (reg8 *) Reloj_3__CFG3)
#define Reloj_3_PHASE_PTR          ((reg8 *) Reloj_3__CFG3)
#endif /* defined(Reloj_3__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Reloj_3_CLKEN_MASK         Reloj_3__PM_ACT_MSK
#define Reloj_3_CLKSTBY_MASK       Reloj_3__PM_STBY_MSK

/* CFG2 field masks */
#define Reloj_3_SRC_SEL_MSK        Reloj_3__CFG2_SRC_SEL_MASK
#define Reloj_3_MODE_MASK          (~(Reloj_3_SRC_SEL_MSK))

#if defined(Reloj_3__CFG3)
/* CFG3 phase mask */
#define Reloj_3_PHASE_MASK         Reloj_3__CFG3_PHASE_DLY_MASK
#endif /* defined(Reloj_3__CFG3) */

#endif /* CY_CLOCK_Reloj_3_H */


/* [] END OF FILE */
