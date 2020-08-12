/*******************************************************************************
* File Name: pin4.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_pin4_H) /* Pins pin4_H */
#define CY_PINS_pin4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "pin4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 pin4__PORT == 15 && ((pin4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    pin4_Write(uint8 value);
void    pin4_SetDriveMode(uint8 mode);
uint8   pin4_ReadDataReg(void);
uint8   pin4_Read(void);
void    pin4_SetInterruptMode(uint16 position, uint16 mode);
uint8   pin4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the pin4_SetDriveMode() function.
     *  @{
     */
        #define pin4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define pin4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define pin4_DM_RES_UP          PIN_DM_RES_UP
        #define pin4_DM_RES_DWN         PIN_DM_RES_DWN
        #define pin4_DM_OD_LO           PIN_DM_OD_LO
        #define pin4_DM_OD_HI           PIN_DM_OD_HI
        #define pin4_DM_STRONG          PIN_DM_STRONG
        #define pin4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define pin4_MASK               pin4__MASK
#define pin4_SHIFT              pin4__SHIFT
#define pin4_WIDTH              1u

/* Interrupt constants */
#if defined(pin4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pin4_SetInterruptMode() function.
     *  @{
     */
        #define pin4_INTR_NONE      (uint16)(0x0000u)
        #define pin4_INTR_RISING    (uint16)(0x0001u)
        #define pin4_INTR_FALLING   (uint16)(0x0002u)
        #define pin4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define pin4_INTR_MASK      (0x01u) 
#endif /* (pin4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pin4_PS                     (* (reg8 *) pin4__PS)
/* Data Register */
#define pin4_DR                     (* (reg8 *) pin4__DR)
/* Port Number */
#define pin4_PRT_NUM                (* (reg8 *) pin4__PRT) 
/* Connect to Analog Globals */                                                  
#define pin4_AG                     (* (reg8 *) pin4__AG)                       
/* Analog MUX bux enable */
#define pin4_AMUX                   (* (reg8 *) pin4__AMUX) 
/* Bidirectional Enable */                                                        
#define pin4_BIE                    (* (reg8 *) pin4__BIE)
/* Bit-mask for Aliased Register Access */
#define pin4_BIT_MASK               (* (reg8 *) pin4__BIT_MASK)
/* Bypass Enable */
#define pin4_BYP                    (* (reg8 *) pin4__BYP)
/* Port wide control signals */                                                   
#define pin4_CTL                    (* (reg8 *) pin4__CTL)
/* Drive Modes */
#define pin4_DM0                    (* (reg8 *) pin4__DM0) 
#define pin4_DM1                    (* (reg8 *) pin4__DM1)
#define pin4_DM2                    (* (reg8 *) pin4__DM2) 
/* Input Buffer Disable Override */
#define pin4_INP_DIS                (* (reg8 *) pin4__INP_DIS)
/* LCD Common or Segment Drive */
#define pin4_LCD_COM_SEG            (* (reg8 *) pin4__LCD_COM_SEG)
/* Enable Segment LCD */
#define pin4_LCD_EN                 (* (reg8 *) pin4__LCD_EN)
/* Slew Rate Control */
#define pin4_SLW                    (* (reg8 *) pin4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define pin4_PRTDSI__CAPS_SEL       (* (reg8 *) pin4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define pin4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) pin4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define pin4_PRTDSI__OE_SEL0        (* (reg8 *) pin4__PRTDSI__OE_SEL0) 
#define pin4_PRTDSI__OE_SEL1        (* (reg8 *) pin4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define pin4_PRTDSI__OUT_SEL0       (* (reg8 *) pin4__PRTDSI__OUT_SEL0) 
#define pin4_PRTDSI__OUT_SEL1       (* (reg8 *) pin4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define pin4_PRTDSI__SYNC_OUT       (* (reg8 *) pin4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(pin4__SIO_CFG)
    #define pin4_SIO_HYST_EN        (* (reg8 *) pin4__SIO_HYST_EN)
    #define pin4_SIO_REG_HIFREQ     (* (reg8 *) pin4__SIO_REG_HIFREQ)
    #define pin4_SIO_CFG            (* (reg8 *) pin4__SIO_CFG)
    #define pin4_SIO_DIFF           (* (reg8 *) pin4__SIO_DIFF)
#endif /* (pin4__SIO_CFG) */

/* Interrupt Registers */
#if defined(pin4__INTSTAT)
    #define pin4_INTSTAT            (* (reg8 *) pin4__INTSTAT)
    #define pin4_SNAP               (* (reg8 *) pin4__SNAP)
    
	#define pin4_0_INTTYPE_REG 		(* (reg8 *) pin4__0__INTTYPE)
#endif /* (pin4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_pin4_H */


/* [] END OF FILE */
