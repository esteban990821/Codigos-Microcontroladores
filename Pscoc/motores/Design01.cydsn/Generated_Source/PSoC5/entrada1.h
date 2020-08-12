/*******************************************************************************
* File Name: entrada1.h  
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

#if !defined(CY_PINS_entrada1_H) /* Pins entrada1_H */
#define CY_PINS_entrada1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "entrada1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 entrada1__PORT == 15 && ((entrada1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    entrada1_Write(uint8 value);
void    entrada1_SetDriveMode(uint8 mode);
uint8   entrada1_ReadDataReg(void);
uint8   entrada1_Read(void);
void    entrada1_SetInterruptMode(uint16 position, uint16 mode);
uint8   entrada1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the entrada1_SetDriveMode() function.
     *  @{
     */
        #define entrada1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define entrada1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define entrada1_DM_RES_UP          PIN_DM_RES_UP
        #define entrada1_DM_RES_DWN         PIN_DM_RES_DWN
        #define entrada1_DM_OD_LO           PIN_DM_OD_LO
        #define entrada1_DM_OD_HI           PIN_DM_OD_HI
        #define entrada1_DM_STRONG          PIN_DM_STRONG
        #define entrada1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define entrada1_MASK               entrada1__MASK
#define entrada1_SHIFT              entrada1__SHIFT
#define entrada1_WIDTH              1u

/* Interrupt constants */
#if defined(entrada1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in entrada1_SetInterruptMode() function.
     *  @{
     */
        #define entrada1_INTR_NONE      (uint16)(0x0000u)
        #define entrada1_INTR_RISING    (uint16)(0x0001u)
        #define entrada1_INTR_FALLING   (uint16)(0x0002u)
        #define entrada1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define entrada1_INTR_MASK      (0x01u) 
#endif /* (entrada1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define entrada1_PS                     (* (reg8 *) entrada1__PS)
/* Data Register */
#define entrada1_DR                     (* (reg8 *) entrada1__DR)
/* Port Number */
#define entrada1_PRT_NUM                (* (reg8 *) entrada1__PRT) 
/* Connect to Analog Globals */                                                  
#define entrada1_AG                     (* (reg8 *) entrada1__AG)                       
/* Analog MUX bux enable */
#define entrada1_AMUX                   (* (reg8 *) entrada1__AMUX) 
/* Bidirectional Enable */                                                        
#define entrada1_BIE                    (* (reg8 *) entrada1__BIE)
/* Bit-mask for Aliased Register Access */
#define entrada1_BIT_MASK               (* (reg8 *) entrada1__BIT_MASK)
/* Bypass Enable */
#define entrada1_BYP                    (* (reg8 *) entrada1__BYP)
/* Port wide control signals */                                                   
#define entrada1_CTL                    (* (reg8 *) entrada1__CTL)
/* Drive Modes */
#define entrada1_DM0                    (* (reg8 *) entrada1__DM0) 
#define entrada1_DM1                    (* (reg8 *) entrada1__DM1)
#define entrada1_DM2                    (* (reg8 *) entrada1__DM2) 
/* Input Buffer Disable Override */
#define entrada1_INP_DIS                (* (reg8 *) entrada1__INP_DIS)
/* LCD Common or Segment Drive */
#define entrada1_LCD_COM_SEG            (* (reg8 *) entrada1__LCD_COM_SEG)
/* Enable Segment LCD */
#define entrada1_LCD_EN                 (* (reg8 *) entrada1__LCD_EN)
/* Slew Rate Control */
#define entrada1_SLW                    (* (reg8 *) entrada1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define entrada1_PRTDSI__CAPS_SEL       (* (reg8 *) entrada1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define entrada1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) entrada1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define entrada1_PRTDSI__OE_SEL0        (* (reg8 *) entrada1__PRTDSI__OE_SEL0) 
#define entrada1_PRTDSI__OE_SEL1        (* (reg8 *) entrada1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define entrada1_PRTDSI__OUT_SEL0       (* (reg8 *) entrada1__PRTDSI__OUT_SEL0) 
#define entrada1_PRTDSI__OUT_SEL1       (* (reg8 *) entrada1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define entrada1_PRTDSI__SYNC_OUT       (* (reg8 *) entrada1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(entrada1__SIO_CFG)
    #define entrada1_SIO_HYST_EN        (* (reg8 *) entrada1__SIO_HYST_EN)
    #define entrada1_SIO_REG_HIFREQ     (* (reg8 *) entrada1__SIO_REG_HIFREQ)
    #define entrada1_SIO_CFG            (* (reg8 *) entrada1__SIO_CFG)
    #define entrada1_SIO_DIFF           (* (reg8 *) entrada1__SIO_DIFF)
#endif /* (entrada1__SIO_CFG) */

/* Interrupt Registers */
#if defined(entrada1__INTSTAT)
    #define entrada1_INTSTAT            (* (reg8 *) entrada1__INTSTAT)
    #define entrada1_SNAP               (* (reg8 *) entrada1__SNAP)
    
	#define entrada1_0_INTTYPE_REG 		(* (reg8 *) entrada1__0__INTTYPE)
#endif /* (entrada1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_entrada1_H */


/* [] END OF FILE */
