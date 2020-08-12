/*******************************************************************************
* File Name: U1.h  
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

#if !defined(CY_PINS_U1_H) /* Pins U1_H */
#define CY_PINS_U1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "U1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 U1__PORT == 15 && ((U1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    U1_Write(uint8 value);
void    U1_SetDriveMode(uint8 mode);
uint8   U1_ReadDataReg(void);
uint8   U1_Read(void);
void    U1_SetInterruptMode(uint16 position, uint16 mode);
uint8   U1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the U1_SetDriveMode() function.
     *  @{
     */
        #define U1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define U1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define U1_DM_RES_UP          PIN_DM_RES_UP
        #define U1_DM_RES_DWN         PIN_DM_RES_DWN
        #define U1_DM_OD_LO           PIN_DM_OD_LO
        #define U1_DM_OD_HI           PIN_DM_OD_HI
        #define U1_DM_STRONG          PIN_DM_STRONG
        #define U1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define U1_MASK               U1__MASK
#define U1_SHIFT              U1__SHIFT
#define U1_WIDTH              1u

/* Interrupt constants */
#if defined(U1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in U1_SetInterruptMode() function.
     *  @{
     */
        #define U1_INTR_NONE      (uint16)(0x0000u)
        #define U1_INTR_RISING    (uint16)(0x0001u)
        #define U1_INTR_FALLING   (uint16)(0x0002u)
        #define U1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define U1_INTR_MASK      (0x01u) 
#endif /* (U1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define U1_PS                     (* (reg8 *) U1__PS)
/* Data Register */
#define U1_DR                     (* (reg8 *) U1__DR)
/* Port Number */
#define U1_PRT_NUM                (* (reg8 *) U1__PRT) 
/* Connect to Analog Globals */                                                  
#define U1_AG                     (* (reg8 *) U1__AG)                       
/* Analog MUX bux enable */
#define U1_AMUX                   (* (reg8 *) U1__AMUX) 
/* Bidirectional Enable */                                                        
#define U1_BIE                    (* (reg8 *) U1__BIE)
/* Bit-mask for Aliased Register Access */
#define U1_BIT_MASK               (* (reg8 *) U1__BIT_MASK)
/* Bypass Enable */
#define U1_BYP                    (* (reg8 *) U1__BYP)
/* Port wide control signals */                                                   
#define U1_CTL                    (* (reg8 *) U1__CTL)
/* Drive Modes */
#define U1_DM0                    (* (reg8 *) U1__DM0) 
#define U1_DM1                    (* (reg8 *) U1__DM1)
#define U1_DM2                    (* (reg8 *) U1__DM2) 
/* Input Buffer Disable Override */
#define U1_INP_DIS                (* (reg8 *) U1__INP_DIS)
/* LCD Common or Segment Drive */
#define U1_LCD_COM_SEG            (* (reg8 *) U1__LCD_COM_SEG)
/* Enable Segment LCD */
#define U1_LCD_EN                 (* (reg8 *) U1__LCD_EN)
/* Slew Rate Control */
#define U1_SLW                    (* (reg8 *) U1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define U1_PRTDSI__CAPS_SEL       (* (reg8 *) U1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define U1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) U1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define U1_PRTDSI__OE_SEL0        (* (reg8 *) U1__PRTDSI__OE_SEL0) 
#define U1_PRTDSI__OE_SEL1        (* (reg8 *) U1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define U1_PRTDSI__OUT_SEL0       (* (reg8 *) U1__PRTDSI__OUT_SEL0) 
#define U1_PRTDSI__OUT_SEL1       (* (reg8 *) U1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define U1_PRTDSI__SYNC_OUT       (* (reg8 *) U1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(U1__SIO_CFG)
    #define U1_SIO_HYST_EN        (* (reg8 *) U1__SIO_HYST_EN)
    #define U1_SIO_REG_HIFREQ     (* (reg8 *) U1__SIO_REG_HIFREQ)
    #define U1_SIO_CFG            (* (reg8 *) U1__SIO_CFG)
    #define U1_SIO_DIFF           (* (reg8 *) U1__SIO_DIFF)
#endif /* (U1__SIO_CFG) */

/* Interrupt Registers */
#if defined(U1__INTSTAT)
    #define U1_INTSTAT            (* (reg8 *) U1__INTSTAT)
    #define U1_SNAP               (* (reg8 *) U1__SNAP)
    
	#define U1_0_INTTYPE_REG 		(* (reg8 *) U1__0__INTTYPE)
#endif /* (U1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_U1_H */


/* [] END OF FILE */
