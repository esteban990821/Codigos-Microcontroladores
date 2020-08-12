/*******************************************************************************
* File Name: Display2_InClock.h
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

#if !defined(CY_CLOCK_Display2_InClock_H)
#define CY_CLOCK_Display2_InClock_H

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

void Display2_InClock_Start(void) ;
void Display2_InClock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Display2_InClock_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Display2_InClock_StandbyPower(uint8 state) ;
void Display2_InClock_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Display2_InClock_GetDividerRegister(void) ;
void Display2_InClock_SetModeRegister(uint8 modeBitMask) ;
void Display2_InClock_ClearModeRegister(uint8 modeBitMask) ;
uint8 Display2_InClock_GetModeRegister(void) ;
void Display2_InClock_SetSourceRegister(uint8 clkSource) ;
uint8 Display2_InClock_GetSourceRegister(void) ;
#if defined(Display2_InClock__CFG3)
void Display2_InClock_SetPhaseRegister(uint8 clkPhase) ;
uint8 Display2_InClock_GetPhaseRegister(void) ;
#endif /* defined(Display2_InClock__CFG3) */

#define Display2_InClock_Enable()                       Display2_InClock_Start()
#define Display2_InClock_Disable()                      Display2_InClock_Stop()
#define Display2_InClock_SetDivider(clkDivider)         Display2_InClock_SetDividerRegister(clkDivider, 1u)
#define Display2_InClock_SetDividerValue(clkDivider)    Display2_InClock_SetDividerRegister((clkDivider) - 1u, 1u)
#define Display2_InClock_SetMode(clkMode)               Display2_InClock_SetModeRegister(clkMode)
#define Display2_InClock_SetSource(clkSource)           Display2_InClock_SetSourceRegister(clkSource)
#if defined(Display2_InClock__CFG3)
#define Display2_InClock_SetPhase(clkPhase)             Display2_InClock_SetPhaseRegister(clkPhase)
#define Display2_InClock_SetPhaseValue(clkPhase)        Display2_InClock_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Display2_InClock__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Display2_InClock_CLKEN              (* (reg8 *) Display2_InClock__PM_ACT_CFG)
#define Display2_InClock_CLKEN_PTR          ((reg8 *) Display2_InClock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Display2_InClock_CLKSTBY            (* (reg8 *) Display2_InClock__PM_STBY_CFG)
#define Display2_InClock_CLKSTBY_PTR        ((reg8 *) Display2_InClock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Display2_InClock_DIV_LSB            (* (reg8 *) Display2_InClock__CFG0)
#define Display2_InClock_DIV_LSB_PTR        ((reg8 *) Display2_InClock__CFG0)
#define Display2_InClock_DIV_PTR            ((reg16 *) Display2_InClock__CFG0)

/* Clock MSB divider configuration register. */
#define Display2_InClock_DIV_MSB            (* (reg8 *) Display2_InClock__CFG1)
#define Display2_InClock_DIV_MSB_PTR        ((reg8 *) Display2_InClock__CFG1)

/* Mode and source configuration register */
#define Display2_InClock_MOD_SRC            (* (reg8 *) Display2_InClock__CFG2)
#define Display2_InClock_MOD_SRC_PTR        ((reg8 *) Display2_InClock__CFG2)

#if defined(Display2_InClock__CFG3)
/* Analog clock phase configuration register */
#define Display2_InClock_PHASE              (* (reg8 *) Display2_InClock__CFG3)
#define Display2_InClock_PHASE_PTR          ((reg8 *) Display2_InClock__CFG3)
#endif /* defined(Display2_InClock__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Display2_InClock_CLKEN_MASK         Display2_InClock__PM_ACT_MSK
#define Display2_InClock_CLKSTBY_MASK       Display2_InClock__PM_STBY_MSK

/* CFG2 field masks */
#define Display2_InClock_SRC_SEL_MSK        Display2_InClock__CFG2_SRC_SEL_MASK
#define Display2_InClock_MODE_MASK          (~(Display2_InClock_SRC_SEL_MSK))

#if defined(Display2_InClock__CFG3)
/* CFG3 phase mask */
#define Display2_InClock_PHASE_MASK         Display2_InClock__CFG3_PHASE_DLY_MASK
#endif /* defined(Display2_InClock__CFG3) */

#endif /* CY_CLOCK_Display2_InClock_H */


/* [] END OF FILE */
