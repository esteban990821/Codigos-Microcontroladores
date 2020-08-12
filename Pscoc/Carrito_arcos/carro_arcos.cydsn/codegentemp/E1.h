/*******************************************************************************
* File Name: E1.h  
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

#if !defined(CY_PINS_E1_H) /* Pins E1_H */
#define CY_PINS_E1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "E1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 E1__PORT == 15 && ((E1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    E1_Write(uint8 value);
void    E1_SetDriveMode(uint8 mode);
uint8   E1_ReadDataReg(void);
uint8   E1_Read(void);
void    E1_SetInterruptMode(uint16 position, uint16 mode);
uint8   E1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the E1_SetDriveMode() function.
     *  @{
     */
        #define E1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define E1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define E1_DM_RES_UP          PIN_DM_RES_UP
        #define E1_DM_RES_DWN         PIN_DM_RES_DWN
        #define E1_DM_OD_LO           PIN_DM_OD_LO
        #define E1_DM_OD_HI           PIN_DM_OD_HI
        #define E1_DM_STRONG          PIN_DM_STRONG
        #define E1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define E1_MASK               E1__MASK
#define E1_SHIFT              E1__SHIFT
#define E1_WIDTH              1u

/* Interrupt constants */
#if defined(E1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in E1_SetInterruptMode() function.
     *  @{
     */
        #define E1_INTR_NONE      (uint16)(0x0000u)
        #define E1_INTR_RISING    (uint16)(0x0001u)
        #define E1_INTR_FALLING   (uint16)(0x0002u)
        #define E1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define E1_INTR_MASK      (0x01u) 
#endif /* (E1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define E1_PS                     (* (reg8 *) E1__PS)
/* Data Register */
#define E1_DR                     (* (reg8 *) E1__DR)
/* Port Number */
#define E1_PRT_NUM                (* (reg8 *) E1__PRT) 
/* Connect to Analog Globals */                                                  
#define E1_AG                     (* (reg8 *) E1__AG)                       
/* Analog MUX bux enable */
#define E1_AMUX                   (* (reg8 *) E1__AMUX) 
/* Bidirectional Enable */                                                        
#define E1_BIE                    (* (reg8 *) E1__BIE)
/* Bit-mask for Aliased Register Access */
#define E1_BIT_MASK               (* (reg8 *) E1__BIT_MASK)
/* Bypass Enable */
#define E1_BYP                    (* (reg8 *) E1__BYP)
/* Port wide control signals */                                                   
#define E1_CTL                    (* (reg8 *) E1__CTL)
/* Drive Modes */
#define E1_DM0                    (* (reg8 *) E1__DM0) 
#define E1_DM1                    (* (reg8 *) E1__DM1)
#define E1_DM2                    (* (reg8 *) E1__DM2) 
/* Input Buffer Disable Override */
#define E1_INP_DIS                (* (reg8 *) E1__INP_DIS)
/* LCD Common or Segment Drive */
#define E1_LCD_COM_SEG            (* (reg8 *) E1__LCD_COM_SEG)
/* Enable Segment LCD */
#define E1_LCD_EN                 (* (reg8 *) E1__LCD_EN)
/* Slew Rate Control */
#define E1_SLW                    (* (reg8 *) E1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define E1_PRTDSI__CAPS_SEL       (* (reg8 *) E1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define E1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) E1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define E1_PRTDSI__OE_SEL0        (* (reg8 *) E1__PRTDSI__OE_SEL0) 
#define E1_PRTDSI__OE_SEL1        (* (reg8 *) E1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define E1_PRTDSI__OUT_SEL0       (* (reg8 *) E1__PRTDSI__OUT_SEL0) 
#define E1_PRTDSI__OUT_SEL1       (* (reg8 *) E1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define E1_PRTDSI__SYNC_OUT       (* (reg8 *) E1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(E1__SIO_CFG)
    #define E1_SIO_HYST_EN        (* (reg8 *) E1__SIO_HYST_EN)
    #define E1_SIO_REG_HIFREQ     (* (reg8 *) E1__SIO_REG_HIFREQ)
    #define E1_SIO_CFG            (* (reg8 *) E1__SIO_CFG)
    #define E1_SIO_DIFF           (* (reg8 *) E1__SIO_DIFF)
#endif /* (E1__SIO_CFG) */

/* Interrupt Registers */
#if defined(E1__INTSTAT)
    #define E1_INTSTAT            (* (reg8 *) E1__INTSTAT)
    #define E1_SNAP               (* (reg8 *) E1__SNAP)
    
	#define E1_0_INTTYPE_REG 		(* (reg8 *) E1__0__INTTYPE)
#endif /* (E1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_E1_H */


/* [] END OF FILE */
