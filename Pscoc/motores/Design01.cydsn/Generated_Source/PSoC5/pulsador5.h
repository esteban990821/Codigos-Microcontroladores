/*******************************************************************************
* File Name: pulsador5.h  
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

#if !defined(CY_PINS_pulsador5_H) /* Pins pulsador5_H */
#define CY_PINS_pulsador5_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "pulsador5_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 pulsador5__PORT == 15 && ((pulsador5__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    pulsador5_Write(uint8 value);
void    pulsador5_SetDriveMode(uint8 mode);
uint8   pulsador5_ReadDataReg(void);
uint8   pulsador5_Read(void);
void    pulsador5_SetInterruptMode(uint16 position, uint16 mode);
uint8   pulsador5_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the pulsador5_SetDriveMode() function.
     *  @{
     */
        #define pulsador5_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define pulsador5_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define pulsador5_DM_RES_UP          PIN_DM_RES_UP
        #define pulsador5_DM_RES_DWN         PIN_DM_RES_DWN
        #define pulsador5_DM_OD_LO           PIN_DM_OD_LO
        #define pulsador5_DM_OD_HI           PIN_DM_OD_HI
        #define pulsador5_DM_STRONG          PIN_DM_STRONG
        #define pulsador5_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define pulsador5_MASK               pulsador5__MASK
#define pulsador5_SHIFT              pulsador5__SHIFT
#define pulsador5_WIDTH              1u

/* Interrupt constants */
#if defined(pulsador5__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pulsador5_SetInterruptMode() function.
     *  @{
     */
        #define pulsador5_INTR_NONE      (uint16)(0x0000u)
        #define pulsador5_INTR_RISING    (uint16)(0x0001u)
        #define pulsador5_INTR_FALLING   (uint16)(0x0002u)
        #define pulsador5_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define pulsador5_INTR_MASK      (0x01u) 
#endif /* (pulsador5__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pulsador5_PS                     (* (reg8 *) pulsador5__PS)
/* Data Register */
#define pulsador5_DR                     (* (reg8 *) pulsador5__DR)
/* Port Number */
#define pulsador5_PRT_NUM                (* (reg8 *) pulsador5__PRT) 
/* Connect to Analog Globals */                                                  
#define pulsador5_AG                     (* (reg8 *) pulsador5__AG)                       
/* Analog MUX bux enable */
#define pulsador5_AMUX                   (* (reg8 *) pulsador5__AMUX) 
/* Bidirectional Enable */                                                        
#define pulsador5_BIE                    (* (reg8 *) pulsador5__BIE)
/* Bit-mask for Aliased Register Access */
#define pulsador5_BIT_MASK               (* (reg8 *) pulsador5__BIT_MASK)
/* Bypass Enable */
#define pulsador5_BYP                    (* (reg8 *) pulsador5__BYP)
/* Port wide control signals */                                                   
#define pulsador5_CTL                    (* (reg8 *) pulsador5__CTL)
/* Drive Modes */
#define pulsador5_DM0                    (* (reg8 *) pulsador5__DM0) 
#define pulsador5_DM1                    (* (reg8 *) pulsador5__DM1)
#define pulsador5_DM2                    (* (reg8 *) pulsador5__DM2) 
/* Input Buffer Disable Override */
#define pulsador5_INP_DIS                (* (reg8 *) pulsador5__INP_DIS)
/* LCD Common or Segment Drive */
#define pulsador5_LCD_COM_SEG            (* (reg8 *) pulsador5__LCD_COM_SEG)
/* Enable Segment LCD */
#define pulsador5_LCD_EN                 (* (reg8 *) pulsador5__LCD_EN)
/* Slew Rate Control */
#define pulsador5_SLW                    (* (reg8 *) pulsador5__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define pulsador5_PRTDSI__CAPS_SEL       (* (reg8 *) pulsador5__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define pulsador5_PRTDSI__DBL_SYNC_IN    (* (reg8 *) pulsador5__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define pulsador5_PRTDSI__OE_SEL0        (* (reg8 *) pulsador5__PRTDSI__OE_SEL0) 
#define pulsador5_PRTDSI__OE_SEL1        (* (reg8 *) pulsador5__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define pulsador5_PRTDSI__OUT_SEL0       (* (reg8 *) pulsador5__PRTDSI__OUT_SEL0) 
#define pulsador5_PRTDSI__OUT_SEL1       (* (reg8 *) pulsador5__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define pulsador5_PRTDSI__SYNC_OUT       (* (reg8 *) pulsador5__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(pulsador5__SIO_CFG)
    #define pulsador5_SIO_HYST_EN        (* (reg8 *) pulsador5__SIO_HYST_EN)
    #define pulsador5_SIO_REG_HIFREQ     (* (reg8 *) pulsador5__SIO_REG_HIFREQ)
    #define pulsador5_SIO_CFG            (* (reg8 *) pulsador5__SIO_CFG)
    #define pulsador5_SIO_DIFF           (* (reg8 *) pulsador5__SIO_DIFF)
#endif /* (pulsador5__SIO_CFG) */

/* Interrupt Registers */
#if defined(pulsador5__INTSTAT)
    #define pulsador5_INTSTAT            (* (reg8 *) pulsador5__INTSTAT)
    #define pulsador5_SNAP               (* (reg8 *) pulsador5__SNAP)
    
	#define pulsador5_0_INTTYPE_REG 		(* (reg8 *) pulsador5__0__INTTYPE)
#endif /* (pulsador5__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_pulsador5_H */


/* [] END OF FILE */
