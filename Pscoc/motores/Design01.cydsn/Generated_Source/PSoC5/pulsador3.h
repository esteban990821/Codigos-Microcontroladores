/*******************************************************************************
* File Name: pulsador3.h  
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

#if !defined(CY_PINS_pulsador3_H) /* Pins pulsador3_H */
#define CY_PINS_pulsador3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "pulsador3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 pulsador3__PORT == 15 && ((pulsador3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    pulsador3_Write(uint8 value);
void    pulsador3_SetDriveMode(uint8 mode);
uint8   pulsador3_ReadDataReg(void);
uint8   pulsador3_Read(void);
void    pulsador3_SetInterruptMode(uint16 position, uint16 mode);
uint8   pulsador3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the pulsador3_SetDriveMode() function.
     *  @{
     */
        #define pulsador3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define pulsador3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define pulsador3_DM_RES_UP          PIN_DM_RES_UP
        #define pulsador3_DM_RES_DWN         PIN_DM_RES_DWN
        #define pulsador3_DM_OD_LO           PIN_DM_OD_LO
        #define pulsador3_DM_OD_HI           PIN_DM_OD_HI
        #define pulsador3_DM_STRONG          PIN_DM_STRONG
        #define pulsador3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define pulsador3_MASK               pulsador3__MASK
#define pulsador3_SHIFT              pulsador3__SHIFT
#define pulsador3_WIDTH              1u

/* Interrupt constants */
#if defined(pulsador3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pulsador3_SetInterruptMode() function.
     *  @{
     */
        #define pulsador3_INTR_NONE      (uint16)(0x0000u)
        #define pulsador3_INTR_RISING    (uint16)(0x0001u)
        #define pulsador3_INTR_FALLING   (uint16)(0x0002u)
        #define pulsador3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define pulsador3_INTR_MASK      (0x01u) 
#endif /* (pulsador3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pulsador3_PS                     (* (reg8 *) pulsador3__PS)
/* Data Register */
#define pulsador3_DR                     (* (reg8 *) pulsador3__DR)
/* Port Number */
#define pulsador3_PRT_NUM                (* (reg8 *) pulsador3__PRT) 
/* Connect to Analog Globals */                                                  
#define pulsador3_AG                     (* (reg8 *) pulsador3__AG)                       
/* Analog MUX bux enable */
#define pulsador3_AMUX                   (* (reg8 *) pulsador3__AMUX) 
/* Bidirectional Enable */                                                        
#define pulsador3_BIE                    (* (reg8 *) pulsador3__BIE)
/* Bit-mask for Aliased Register Access */
#define pulsador3_BIT_MASK               (* (reg8 *) pulsador3__BIT_MASK)
/* Bypass Enable */
#define pulsador3_BYP                    (* (reg8 *) pulsador3__BYP)
/* Port wide control signals */                                                   
#define pulsador3_CTL                    (* (reg8 *) pulsador3__CTL)
/* Drive Modes */
#define pulsador3_DM0                    (* (reg8 *) pulsador3__DM0) 
#define pulsador3_DM1                    (* (reg8 *) pulsador3__DM1)
#define pulsador3_DM2                    (* (reg8 *) pulsador3__DM2) 
/* Input Buffer Disable Override */
#define pulsador3_INP_DIS                (* (reg8 *) pulsador3__INP_DIS)
/* LCD Common or Segment Drive */
#define pulsador3_LCD_COM_SEG            (* (reg8 *) pulsador3__LCD_COM_SEG)
/* Enable Segment LCD */
#define pulsador3_LCD_EN                 (* (reg8 *) pulsador3__LCD_EN)
/* Slew Rate Control */
#define pulsador3_SLW                    (* (reg8 *) pulsador3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define pulsador3_PRTDSI__CAPS_SEL       (* (reg8 *) pulsador3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define pulsador3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) pulsador3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define pulsador3_PRTDSI__OE_SEL0        (* (reg8 *) pulsador3__PRTDSI__OE_SEL0) 
#define pulsador3_PRTDSI__OE_SEL1        (* (reg8 *) pulsador3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define pulsador3_PRTDSI__OUT_SEL0       (* (reg8 *) pulsador3__PRTDSI__OUT_SEL0) 
#define pulsador3_PRTDSI__OUT_SEL1       (* (reg8 *) pulsador3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define pulsador3_PRTDSI__SYNC_OUT       (* (reg8 *) pulsador3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(pulsador3__SIO_CFG)
    #define pulsador3_SIO_HYST_EN        (* (reg8 *) pulsador3__SIO_HYST_EN)
    #define pulsador3_SIO_REG_HIFREQ     (* (reg8 *) pulsador3__SIO_REG_HIFREQ)
    #define pulsador3_SIO_CFG            (* (reg8 *) pulsador3__SIO_CFG)
    #define pulsador3_SIO_DIFF           (* (reg8 *) pulsador3__SIO_DIFF)
#endif /* (pulsador3__SIO_CFG) */

/* Interrupt Registers */
#if defined(pulsador3__INTSTAT)
    #define pulsador3_INTSTAT            (* (reg8 *) pulsador3__INTSTAT)
    #define pulsador3_SNAP               (* (reg8 *) pulsador3__SNAP)
    
	#define pulsador3_0_INTTYPE_REG 		(* (reg8 *) pulsador3__0__INTTYPE)
#endif /* (pulsador3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_pulsador3_H */


/* [] END OF FILE */
