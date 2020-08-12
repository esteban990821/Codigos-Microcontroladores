/*******************************************************************************
* File Name: pulsador6.h  
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

#if !defined(CY_PINS_pulsador6_H) /* Pins pulsador6_H */
#define CY_PINS_pulsador6_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "pulsador6_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 pulsador6__PORT == 15 && ((pulsador6__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    pulsador6_Write(uint8 value);
void    pulsador6_SetDriveMode(uint8 mode);
uint8   pulsador6_ReadDataReg(void);
uint8   pulsador6_Read(void);
void    pulsador6_SetInterruptMode(uint16 position, uint16 mode);
uint8   pulsador6_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the pulsador6_SetDriveMode() function.
     *  @{
     */
        #define pulsador6_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define pulsador6_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define pulsador6_DM_RES_UP          PIN_DM_RES_UP
        #define pulsador6_DM_RES_DWN         PIN_DM_RES_DWN
        #define pulsador6_DM_OD_LO           PIN_DM_OD_LO
        #define pulsador6_DM_OD_HI           PIN_DM_OD_HI
        #define pulsador6_DM_STRONG          PIN_DM_STRONG
        #define pulsador6_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define pulsador6_MASK               pulsador6__MASK
#define pulsador6_SHIFT              pulsador6__SHIFT
#define pulsador6_WIDTH              1u

/* Interrupt constants */
#if defined(pulsador6__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pulsador6_SetInterruptMode() function.
     *  @{
     */
        #define pulsador6_INTR_NONE      (uint16)(0x0000u)
        #define pulsador6_INTR_RISING    (uint16)(0x0001u)
        #define pulsador6_INTR_FALLING   (uint16)(0x0002u)
        #define pulsador6_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define pulsador6_INTR_MASK      (0x01u) 
#endif /* (pulsador6__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pulsador6_PS                     (* (reg8 *) pulsador6__PS)
/* Data Register */
#define pulsador6_DR                     (* (reg8 *) pulsador6__DR)
/* Port Number */
#define pulsador6_PRT_NUM                (* (reg8 *) pulsador6__PRT) 
/* Connect to Analog Globals */                                                  
#define pulsador6_AG                     (* (reg8 *) pulsador6__AG)                       
/* Analog MUX bux enable */
#define pulsador6_AMUX                   (* (reg8 *) pulsador6__AMUX) 
/* Bidirectional Enable */                                                        
#define pulsador6_BIE                    (* (reg8 *) pulsador6__BIE)
/* Bit-mask for Aliased Register Access */
#define pulsador6_BIT_MASK               (* (reg8 *) pulsador6__BIT_MASK)
/* Bypass Enable */
#define pulsador6_BYP                    (* (reg8 *) pulsador6__BYP)
/* Port wide control signals */                                                   
#define pulsador6_CTL                    (* (reg8 *) pulsador6__CTL)
/* Drive Modes */
#define pulsador6_DM0                    (* (reg8 *) pulsador6__DM0) 
#define pulsador6_DM1                    (* (reg8 *) pulsador6__DM1)
#define pulsador6_DM2                    (* (reg8 *) pulsador6__DM2) 
/* Input Buffer Disable Override */
#define pulsador6_INP_DIS                (* (reg8 *) pulsador6__INP_DIS)
/* LCD Common or Segment Drive */
#define pulsador6_LCD_COM_SEG            (* (reg8 *) pulsador6__LCD_COM_SEG)
/* Enable Segment LCD */
#define pulsador6_LCD_EN                 (* (reg8 *) pulsador6__LCD_EN)
/* Slew Rate Control */
#define pulsador6_SLW                    (* (reg8 *) pulsador6__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define pulsador6_PRTDSI__CAPS_SEL       (* (reg8 *) pulsador6__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define pulsador6_PRTDSI__DBL_SYNC_IN    (* (reg8 *) pulsador6__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define pulsador6_PRTDSI__OE_SEL0        (* (reg8 *) pulsador6__PRTDSI__OE_SEL0) 
#define pulsador6_PRTDSI__OE_SEL1        (* (reg8 *) pulsador6__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define pulsador6_PRTDSI__OUT_SEL0       (* (reg8 *) pulsador6__PRTDSI__OUT_SEL0) 
#define pulsador6_PRTDSI__OUT_SEL1       (* (reg8 *) pulsador6__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define pulsador6_PRTDSI__SYNC_OUT       (* (reg8 *) pulsador6__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(pulsador6__SIO_CFG)
    #define pulsador6_SIO_HYST_EN        (* (reg8 *) pulsador6__SIO_HYST_EN)
    #define pulsador6_SIO_REG_HIFREQ     (* (reg8 *) pulsador6__SIO_REG_HIFREQ)
    #define pulsador6_SIO_CFG            (* (reg8 *) pulsador6__SIO_CFG)
    #define pulsador6_SIO_DIFF           (* (reg8 *) pulsador6__SIO_DIFF)
#endif /* (pulsador6__SIO_CFG) */

/* Interrupt Registers */
#if defined(pulsador6__INTSTAT)
    #define pulsador6_INTSTAT            (* (reg8 *) pulsador6__INTSTAT)
    #define pulsador6_SNAP               (* (reg8 *) pulsador6__SNAP)
    
	#define pulsador6_0_INTTYPE_REG 		(* (reg8 *) pulsador6__0__INTTYPE)
#endif /* (pulsador6__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_pulsador6_H */


/* [] END OF FILE */
