/*******************************************************************************
* File Name: pin2_1.h  
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

#if !defined(CY_PINS_pin2_1_H) /* Pins pin2_1_H */
#define CY_PINS_pin2_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "pin2_1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 pin2_1__PORT == 15 && ((pin2_1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    pin2_1_Write(uint8 value);
void    pin2_1_SetDriveMode(uint8 mode);
uint8   pin2_1_ReadDataReg(void);
uint8   pin2_1_Read(void);
void    pin2_1_SetInterruptMode(uint16 position, uint16 mode);
uint8   pin2_1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the pin2_1_SetDriveMode() function.
     *  @{
     */
        #define pin2_1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define pin2_1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define pin2_1_DM_RES_UP          PIN_DM_RES_UP
        #define pin2_1_DM_RES_DWN         PIN_DM_RES_DWN
        #define pin2_1_DM_OD_LO           PIN_DM_OD_LO
        #define pin2_1_DM_OD_HI           PIN_DM_OD_HI
        #define pin2_1_DM_STRONG          PIN_DM_STRONG
        #define pin2_1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define pin2_1_MASK               pin2_1__MASK
#define pin2_1_SHIFT              pin2_1__SHIFT
#define pin2_1_WIDTH              1u

/* Interrupt constants */
#if defined(pin2_1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pin2_1_SetInterruptMode() function.
     *  @{
     */
        #define pin2_1_INTR_NONE      (uint16)(0x0000u)
        #define pin2_1_INTR_RISING    (uint16)(0x0001u)
        #define pin2_1_INTR_FALLING   (uint16)(0x0002u)
        #define pin2_1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define pin2_1_INTR_MASK      (0x01u) 
#endif /* (pin2_1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pin2_1_PS                     (* (reg8 *) pin2_1__PS)
/* Data Register */
#define pin2_1_DR                     (* (reg8 *) pin2_1__DR)
/* Port Number */
#define pin2_1_PRT_NUM                (* (reg8 *) pin2_1__PRT) 
/* Connect to Analog Globals */                                                  
#define pin2_1_AG                     (* (reg8 *) pin2_1__AG)                       
/* Analog MUX bux enable */
#define pin2_1_AMUX                   (* (reg8 *) pin2_1__AMUX) 
/* Bidirectional Enable */                                                        
#define pin2_1_BIE                    (* (reg8 *) pin2_1__BIE)
/* Bit-mask for Aliased Register Access */
#define pin2_1_BIT_MASK               (* (reg8 *) pin2_1__BIT_MASK)
/* Bypass Enable */
#define pin2_1_BYP                    (* (reg8 *) pin2_1__BYP)
/* Port wide control signals */                                                   
#define pin2_1_CTL                    (* (reg8 *) pin2_1__CTL)
/* Drive Modes */
#define pin2_1_DM0                    (* (reg8 *) pin2_1__DM0) 
#define pin2_1_DM1                    (* (reg8 *) pin2_1__DM1)
#define pin2_1_DM2                    (* (reg8 *) pin2_1__DM2) 
/* Input Buffer Disable Override */
#define pin2_1_INP_DIS                (* (reg8 *) pin2_1__INP_DIS)
/* LCD Common or Segment Drive */
#define pin2_1_LCD_COM_SEG            (* (reg8 *) pin2_1__LCD_COM_SEG)
/* Enable Segment LCD */
#define pin2_1_LCD_EN                 (* (reg8 *) pin2_1__LCD_EN)
/* Slew Rate Control */
#define pin2_1_SLW                    (* (reg8 *) pin2_1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define pin2_1_PRTDSI__CAPS_SEL       (* (reg8 *) pin2_1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define pin2_1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) pin2_1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define pin2_1_PRTDSI__OE_SEL0        (* (reg8 *) pin2_1__PRTDSI__OE_SEL0) 
#define pin2_1_PRTDSI__OE_SEL1        (* (reg8 *) pin2_1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define pin2_1_PRTDSI__OUT_SEL0       (* (reg8 *) pin2_1__PRTDSI__OUT_SEL0) 
#define pin2_1_PRTDSI__OUT_SEL1       (* (reg8 *) pin2_1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define pin2_1_PRTDSI__SYNC_OUT       (* (reg8 *) pin2_1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(pin2_1__SIO_CFG)
    #define pin2_1_SIO_HYST_EN        (* (reg8 *) pin2_1__SIO_HYST_EN)
    #define pin2_1_SIO_REG_HIFREQ     (* (reg8 *) pin2_1__SIO_REG_HIFREQ)
    #define pin2_1_SIO_CFG            (* (reg8 *) pin2_1__SIO_CFG)
    #define pin2_1_SIO_DIFF           (* (reg8 *) pin2_1__SIO_DIFF)
#endif /* (pin2_1__SIO_CFG) */

/* Interrupt Registers */
#if defined(pin2_1__INTSTAT)
    #define pin2_1_INTSTAT            (* (reg8 *) pin2_1__INTSTAT)
    #define pin2_1_SNAP               (* (reg8 *) pin2_1__SNAP)
    
	#define pin2_1_0_INTTYPE_REG 		(* (reg8 *) pin2_1__0__INTTYPE)
#endif /* (pin2_1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_pin2_1_H */


/* [] END OF FILE */