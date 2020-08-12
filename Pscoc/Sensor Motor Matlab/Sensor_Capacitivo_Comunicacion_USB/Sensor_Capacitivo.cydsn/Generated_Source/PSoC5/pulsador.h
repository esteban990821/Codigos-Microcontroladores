/*******************************************************************************
* File Name: pulsador.h  
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

#if !defined(CY_PINS_pulsador_H) /* Pins pulsador_H */
#define CY_PINS_pulsador_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "pulsador_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 pulsador__PORT == 15 && ((pulsador__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    pulsador_Write(uint8 value);
void    pulsador_SetDriveMode(uint8 mode);
uint8   pulsador_ReadDataReg(void);
uint8   pulsador_Read(void);
void    pulsador_SetInterruptMode(uint16 position, uint16 mode);
uint8   pulsador_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the pulsador_SetDriveMode() function.
     *  @{
     */
        #define pulsador_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define pulsador_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define pulsador_DM_RES_UP          PIN_DM_RES_UP
        #define pulsador_DM_RES_DWN         PIN_DM_RES_DWN
        #define pulsador_DM_OD_LO           PIN_DM_OD_LO
        #define pulsador_DM_OD_HI           PIN_DM_OD_HI
        #define pulsador_DM_STRONG          PIN_DM_STRONG
        #define pulsador_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define pulsador_MASK               pulsador__MASK
#define pulsador_SHIFT              pulsador__SHIFT
#define pulsador_WIDTH              1u

/* Interrupt constants */
#if defined(pulsador__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pulsador_SetInterruptMode() function.
     *  @{
     */
        #define pulsador_INTR_NONE      (uint16)(0x0000u)
        #define pulsador_INTR_RISING    (uint16)(0x0001u)
        #define pulsador_INTR_FALLING   (uint16)(0x0002u)
        #define pulsador_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define pulsador_INTR_MASK      (0x01u) 
#endif /* (pulsador__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pulsador_PS                     (* (reg8 *) pulsador__PS)
/* Data Register */
#define pulsador_DR                     (* (reg8 *) pulsador__DR)
/* Port Number */
#define pulsador_PRT_NUM                (* (reg8 *) pulsador__PRT) 
/* Connect to Analog Globals */                                                  
#define pulsador_AG                     (* (reg8 *) pulsador__AG)                       
/* Analog MUX bux enable */
#define pulsador_AMUX                   (* (reg8 *) pulsador__AMUX) 
/* Bidirectional Enable */                                                        
#define pulsador_BIE                    (* (reg8 *) pulsador__BIE)
/* Bit-mask for Aliased Register Access */
#define pulsador_BIT_MASK               (* (reg8 *) pulsador__BIT_MASK)
/* Bypass Enable */
#define pulsador_BYP                    (* (reg8 *) pulsador__BYP)
/* Port wide control signals */                                                   
#define pulsador_CTL                    (* (reg8 *) pulsador__CTL)
/* Drive Modes */
#define pulsador_DM0                    (* (reg8 *) pulsador__DM0) 
#define pulsador_DM1                    (* (reg8 *) pulsador__DM1)
#define pulsador_DM2                    (* (reg8 *) pulsador__DM2) 
/* Input Buffer Disable Override */
#define pulsador_INP_DIS                (* (reg8 *) pulsador__INP_DIS)
/* LCD Common or Segment Drive */
#define pulsador_LCD_COM_SEG            (* (reg8 *) pulsador__LCD_COM_SEG)
/* Enable Segment LCD */
#define pulsador_LCD_EN                 (* (reg8 *) pulsador__LCD_EN)
/* Slew Rate Control */
#define pulsador_SLW                    (* (reg8 *) pulsador__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define pulsador_PRTDSI__CAPS_SEL       (* (reg8 *) pulsador__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define pulsador_PRTDSI__DBL_SYNC_IN    (* (reg8 *) pulsador__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define pulsador_PRTDSI__OE_SEL0        (* (reg8 *) pulsador__PRTDSI__OE_SEL0) 
#define pulsador_PRTDSI__OE_SEL1        (* (reg8 *) pulsador__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define pulsador_PRTDSI__OUT_SEL0       (* (reg8 *) pulsador__PRTDSI__OUT_SEL0) 
#define pulsador_PRTDSI__OUT_SEL1       (* (reg8 *) pulsador__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define pulsador_PRTDSI__SYNC_OUT       (* (reg8 *) pulsador__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(pulsador__SIO_CFG)
    #define pulsador_SIO_HYST_EN        (* (reg8 *) pulsador__SIO_HYST_EN)
    #define pulsador_SIO_REG_HIFREQ     (* (reg8 *) pulsador__SIO_REG_HIFREQ)
    #define pulsador_SIO_CFG            (* (reg8 *) pulsador__SIO_CFG)
    #define pulsador_SIO_DIFF           (* (reg8 *) pulsador__SIO_DIFF)
#endif /* (pulsador__SIO_CFG) */

/* Interrupt Registers */
#if defined(pulsador__INTSTAT)
    #define pulsador_INTSTAT            (* (reg8 *) pulsador__INTSTAT)
    #define pulsador_SNAP               (* (reg8 *) pulsador__SNAP)
    
	#define pulsador_0_INTTYPE_REG 		(* (reg8 *) pulsador__0__INTTYPE)
#endif /* (pulsador__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_pulsador_H */


/* [] END OF FILE */
