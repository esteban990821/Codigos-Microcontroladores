/*******************************************************************************
* File Name: pin3.h  
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

#if !defined(CY_PINS_pin3_H) /* Pins pin3_H */
#define CY_PINS_pin3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "pin3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 pin3__PORT == 15 && ((pin3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    pin3_Write(uint8 value);
void    pin3_SetDriveMode(uint8 mode);
uint8   pin3_ReadDataReg(void);
uint8   pin3_Read(void);
void    pin3_SetInterruptMode(uint16 position, uint16 mode);
uint8   pin3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the pin3_SetDriveMode() function.
     *  @{
     */
        #define pin3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define pin3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define pin3_DM_RES_UP          PIN_DM_RES_UP
        #define pin3_DM_RES_DWN         PIN_DM_RES_DWN
        #define pin3_DM_OD_LO           PIN_DM_OD_LO
        #define pin3_DM_OD_HI           PIN_DM_OD_HI
        #define pin3_DM_STRONG          PIN_DM_STRONG
        #define pin3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define pin3_MASK               pin3__MASK
#define pin3_SHIFT              pin3__SHIFT
#define pin3_WIDTH              1u

/* Interrupt constants */
#if defined(pin3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pin3_SetInterruptMode() function.
     *  @{
     */
        #define pin3_INTR_NONE      (uint16)(0x0000u)
        #define pin3_INTR_RISING    (uint16)(0x0001u)
        #define pin3_INTR_FALLING   (uint16)(0x0002u)
        #define pin3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define pin3_INTR_MASK      (0x01u) 
#endif /* (pin3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pin3_PS                     (* (reg8 *) pin3__PS)
/* Data Register */
#define pin3_DR                     (* (reg8 *) pin3__DR)
/* Port Number */
#define pin3_PRT_NUM                (* (reg8 *) pin3__PRT) 
/* Connect to Analog Globals */                                                  
#define pin3_AG                     (* (reg8 *) pin3__AG)                       
/* Analog MUX bux enable */
#define pin3_AMUX                   (* (reg8 *) pin3__AMUX) 
/* Bidirectional Enable */                                                        
#define pin3_BIE                    (* (reg8 *) pin3__BIE)
/* Bit-mask for Aliased Register Access */
#define pin3_BIT_MASK               (* (reg8 *) pin3__BIT_MASK)
/* Bypass Enable */
#define pin3_BYP                    (* (reg8 *) pin3__BYP)
/* Port wide control signals */                                                   
#define pin3_CTL                    (* (reg8 *) pin3__CTL)
/* Drive Modes */
#define pin3_DM0                    (* (reg8 *) pin3__DM0) 
#define pin3_DM1                    (* (reg8 *) pin3__DM1)
#define pin3_DM2                    (* (reg8 *) pin3__DM2) 
/* Input Buffer Disable Override */
#define pin3_INP_DIS                (* (reg8 *) pin3__INP_DIS)
/* LCD Common or Segment Drive */
#define pin3_LCD_COM_SEG            (* (reg8 *) pin3__LCD_COM_SEG)
/* Enable Segment LCD */
#define pin3_LCD_EN                 (* (reg8 *) pin3__LCD_EN)
/* Slew Rate Control */
#define pin3_SLW                    (* (reg8 *) pin3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define pin3_PRTDSI__CAPS_SEL       (* (reg8 *) pin3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define pin3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) pin3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define pin3_PRTDSI__OE_SEL0        (* (reg8 *) pin3__PRTDSI__OE_SEL0) 
#define pin3_PRTDSI__OE_SEL1        (* (reg8 *) pin3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define pin3_PRTDSI__OUT_SEL0       (* (reg8 *) pin3__PRTDSI__OUT_SEL0) 
#define pin3_PRTDSI__OUT_SEL1       (* (reg8 *) pin3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define pin3_PRTDSI__SYNC_OUT       (* (reg8 *) pin3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(pin3__SIO_CFG)
    #define pin3_SIO_HYST_EN        (* (reg8 *) pin3__SIO_HYST_EN)
    #define pin3_SIO_REG_HIFREQ     (* (reg8 *) pin3__SIO_REG_HIFREQ)
    #define pin3_SIO_CFG            (* (reg8 *) pin3__SIO_CFG)
    #define pin3_SIO_DIFF           (* (reg8 *) pin3__SIO_DIFF)
#endif /* (pin3__SIO_CFG) */

/* Interrupt Registers */
#if defined(pin3__INTSTAT)
    #define pin3_INTSTAT            (* (reg8 *) pin3__INTSTAT)
    #define pin3_SNAP               (* (reg8 *) pin3__SNAP)
    
	#define pin3_0_INTTYPE_REG 		(* (reg8 *) pin3__0__INTTYPE)
#endif /* (pin3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_pin3_H */


/* [] END OF FILE */
