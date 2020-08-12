/*******************************************************************************
* File Name: pulsador4.h  
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

#if !defined(CY_PINS_pulsador4_H) /* Pins pulsador4_H */
#define CY_PINS_pulsador4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "pulsador4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 pulsador4__PORT == 15 && ((pulsador4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    pulsador4_Write(uint8 value);
void    pulsador4_SetDriveMode(uint8 mode);
uint8   pulsador4_ReadDataReg(void);
uint8   pulsador4_Read(void);
void    pulsador4_SetInterruptMode(uint16 position, uint16 mode);
uint8   pulsador4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the pulsador4_SetDriveMode() function.
     *  @{
     */
        #define pulsador4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define pulsador4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define pulsador4_DM_RES_UP          PIN_DM_RES_UP
        #define pulsador4_DM_RES_DWN         PIN_DM_RES_DWN
        #define pulsador4_DM_OD_LO           PIN_DM_OD_LO
        #define pulsador4_DM_OD_HI           PIN_DM_OD_HI
        #define pulsador4_DM_STRONG          PIN_DM_STRONG
        #define pulsador4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define pulsador4_MASK               pulsador4__MASK
#define pulsador4_SHIFT              pulsador4__SHIFT
#define pulsador4_WIDTH              1u

/* Interrupt constants */
#if defined(pulsador4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pulsador4_SetInterruptMode() function.
     *  @{
     */
        #define pulsador4_INTR_NONE      (uint16)(0x0000u)
        #define pulsador4_INTR_RISING    (uint16)(0x0001u)
        #define pulsador4_INTR_FALLING   (uint16)(0x0002u)
        #define pulsador4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define pulsador4_INTR_MASK      (0x01u) 
#endif /* (pulsador4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pulsador4_PS                     (* (reg8 *) pulsador4__PS)
/* Data Register */
#define pulsador4_DR                     (* (reg8 *) pulsador4__DR)
/* Port Number */
#define pulsador4_PRT_NUM                (* (reg8 *) pulsador4__PRT) 
/* Connect to Analog Globals */                                                  
#define pulsador4_AG                     (* (reg8 *) pulsador4__AG)                       
/* Analog MUX bux enable */
#define pulsador4_AMUX                   (* (reg8 *) pulsador4__AMUX) 
/* Bidirectional Enable */                                                        
#define pulsador4_BIE                    (* (reg8 *) pulsador4__BIE)
/* Bit-mask for Aliased Register Access */
#define pulsador4_BIT_MASK               (* (reg8 *) pulsador4__BIT_MASK)
/* Bypass Enable */
#define pulsador4_BYP                    (* (reg8 *) pulsador4__BYP)
/* Port wide control signals */                                                   
#define pulsador4_CTL                    (* (reg8 *) pulsador4__CTL)
/* Drive Modes */
#define pulsador4_DM0                    (* (reg8 *) pulsador4__DM0) 
#define pulsador4_DM1                    (* (reg8 *) pulsador4__DM1)
#define pulsador4_DM2                    (* (reg8 *) pulsador4__DM2) 
/* Input Buffer Disable Override */
#define pulsador4_INP_DIS                (* (reg8 *) pulsador4__INP_DIS)
/* LCD Common or Segment Drive */
#define pulsador4_LCD_COM_SEG            (* (reg8 *) pulsador4__LCD_COM_SEG)
/* Enable Segment LCD */
#define pulsador4_LCD_EN                 (* (reg8 *) pulsador4__LCD_EN)
/* Slew Rate Control */
#define pulsador4_SLW                    (* (reg8 *) pulsador4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define pulsador4_PRTDSI__CAPS_SEL       (* (reg8 *) pulsador4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define pulsador4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) pulsador4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define pulsador4_PRTDSI__OE_SEL0        (* (reg8 *) pulsador4__PRTDSI__OE_SEL0) 
#define pulsador4_PRTDSI__OE_SEL1        (* (reg8 *) pulsador4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define pulsador4_PRTDSI__OUT_SEL0       (* (reg8 *) pulsador4__PRTDSI__OUT_SEL0) 
#define pulsador4_PRTDSI__OUT_SEL1       (* (reg8 *) pulsador4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define pulsador4_PRTDSI__SYNC_OUT       (* (reg8 *) pulsador4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(pulsador4__SIO_CFG)
    #define pulsador4_SIO_HYST_EN        (* (reg8 *) pulsador4__SIO_HYST_EN)
    #define pulsador4_SIO_REG_HIFREQ     (* (reg8 *) pulsador4__SIO_REG_HIFREQ)
    #define pulsador4_SIO_CFG            (* (reg8 *) pulsador4__SIO_CFG)
    #define pulsador4_SIO_DIFF           (* (reg8 *) pulsador4__SIO_DIFF)
#endif /* (pulsador4__SIO_CFG) */

/* Interrupt Registers */
#if defined(pulsador4__INTSTAT)
    #define pulsador4_INTSTAT            (* (reg8 *) pulsador4__INTSTAT)
    #define pulsador4_SNAP               (* (reg8 *) pulsador4__SNAP)
    
	#define pulsador4_0_INTTYPE_REG 		(* (reg8 *) pulsador4__0__INTTYPE)
#endif /* (pulsador4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_pulsador4_H */


/* [] END OF FILE */
