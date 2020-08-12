/*******************************************************************************
* File Name: U.h  
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

#if !defined(CY_PINS_U_H) /* Pins U_H */
#define CY_PINS_U_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "U_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 U__PORT == 15 && ((U__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    U_Write(uint8 value);
void    U_SetDriveMode(uint8 mode);
uint8   U_ReadDataReg(void);
uint8   U_Read(void);
void    U_SetInterruptMode(uint16 position, uint16 mode);
uint8   U_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the U_SetDriveMode() function.
     *  @{
     */
        #define U_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define U_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define U_DM_RES_UP          PIN_DM_RES_UP
        #define U_DM_RES_DWN         PIN_DM_RES_DWN
        #define U_DM_OD_LO           PIN_DM_OD_LO
        #define U_DM_OD_HI           PIN_DM_OD_HI
        #define U_DM_STRONG          PIN_DM_STRONG
        #define U_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define U_MASK               U__MASK
#define U_SHIFT              U__SHIFT
#define U_WIDTH              1u

/* Interrupt constants */
#if defined(U__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in U_SetInterruptMode() function.
     *  @{
     */
        #define U_INTR_NONE      (uint16)(0x0000u)
        #define U_INTR_RISING    (uint16)(0x0001u)
        #define U_INTR_FALLING   (uint16)(0x0002u)
        #define U_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define U_INTR_MASK      (0x01u) 
#endif /* (U__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define U_PS                     (* (reg8 *) U__PS)
/* Data Register */
#define U_DR                     (* (reg8 *) U__DR)
/* Port Number */
#define U_PRT_NUM                (* (reg8 *) U__PRT) 
/* Connect to Analog Globals */                                                  
#define U_AG                     (* (reg8 *) U__AG)                       
/* Analog MUX bux enable */
#define U_AMUX                   (* (reg8 *) U__AMUX) 
/* Bidirectional Enable */                                                        
#define U_BIE                    (* (reg8 *) U__BIE)
/* Bit-mask for Aliased Register Access */
#define U_BIT_MASK               (* (reg8 *) U__BIT_MASK)
/* Bypass Enable */
#define U_BYP                    (* (reg8 *) U__BYP)
/* Port wide control signals */                                                   
#define U_CTL                    (* (reg8 *) U__CTL)
/* Drive Modes */
#define U_DM0                    (* (reg8 *) U__DM0) 
#define U_DM1                    (* (reg8 *) U__DM1)
#define U_DM2                    (* (reg8 *) U__DM2) 
/* Input Buffer Disable Override */
#define U_INP_DIS                (* (reg8 *) U__INP_DIS)
/* LCD Common or Segment Drive */
#define U_LCD_COM_SEG            (* (reg8 *) U__LCD_COM_SEG)
/* Enable Segment LCD */
#define U_LCD_EN                 (* (reg8 *) U__LCD_EN)
/* Slew Rate Control */
#define U_SLW                    (* (reg8 *) U__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define U_PRTDSI__CAPS_SEL       (* (reg8 *) U__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define U_PRTDSI__DBL_SYNC_IN    (* (reg8 *) U__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define U_PRTDSI__OE_SEL0        (* (reg8 *) U__PRTDSI__OE_SEL0) 
#define U_PRTDSI__OE_SEL1        (* (reg8 *) U__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define U_PRTDSI__OUT_SEL0       (* (reg8 *) U__PRTDSI__OUT_SEL0) 
#define U_PRTDSI__OUT_SEL1       (* (reg8 *) U__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define U_PRTDSI__SYNC_OUT       (* (reg8 *) U__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(U__SIO_CFG)
    #define U_SIO_HYST_EN        (* (reg8 *) U__SIO_HYST_EN)
    #define U_SIO_REG_HIFREQ     (* (reg8 *) U__SIO_REG_HIFREQ)
    #define U_SIO_CFG            (* (reg8 *) U__SIO_CFG)
    #define U_SIO_DIFF           (* (reg8 *) U__SIO_DIFF)
#endif /* (U__SIO_CFG) */

/* Interrupt Registers */
#if defined(U__INTSTAT)
    #define U_INTSTAT            (* (reg8 *) U__INTSTAT)
    #define U_SNAP               (* (reg8 *) U__SNAP)
    
	#define U_0_INTTYPE_REG 		(* (reg8 *) U__0__INTTYPE)
#endif /* (U__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_U_H */


/* [] END OF FILE */
