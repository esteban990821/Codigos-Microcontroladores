/*******************************************************************************
* File Name: Pin4.h  
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

#if !defined(CY_PINS_Pin4_H) /* Pins Pin4_H */
#define CY_PINS_Pin4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pin4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pin4__PORT == 15 && ((Pin4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Pin4_Write(uint8 value);
void    Pin4_SetDriveMode(uint8 mode);
uint8   Pin4_ReadDataReg(void);
uint8   Pin4_Read(void);
void    Pin4_SetInterruptMode(uint16 position, uint16 mode);
uint8   Pin4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Pin4_SetDriveMode() function.
     *  @{
     */
        #define Pin4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Pin4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Pin4_DM_RES_UP          PIN_DM_RES_UP
        #define Pin4_DM_RES_DWN         PIN_DM_RES_DWN
        #define Pin4_DM_OD_LO           PIN_DM_OD_LO
        #define Pin4_DM_OD_HI           PIN_DM_OD_HI
        #define Pin4_DM_STRONG          PIN_DM_STRONG
        #define Pin4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Pin4_MASK               Pin4__MASK
#define Pin4_SHIFT              Pin4__SHIFT
#define Pin4_WIDTH              1u

/* Interrupt constants */
#if defined(Pin4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Pin4_SetInterruptMode() function.
     *  @{
     */
        #define Pin4_INTR_NONE      (uint16)(0x0000u)
        #define Pin4_INTR_RISING    (uint16)(0x0001u)
        #define Pin4_INTR_FALLING   (uint16)(0x0002u)
        #define Pin4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Pin4_INTR_MASK      (0x01u) 
#endif /* (Pin4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin4_PS                     (* (reg8 *) Pin4__PS)
/* Data Register */
#define Pin4_DR                     (* (reg8 *) Pin4__DR)
/* Port Number */
#define Pin4_PRT_NUM                (* (reg8 *) Pin4__PRT) 
/* Connect to Analog Globals */                                                  
#define Pin4_AG                     (* (reg8 *) Pin4__AG)                       
/* Analog MUX bux enable */
#define Pin4_AMUX                   (* (reg8 *) Pin4__AMUX) 
/* Bidirectional Enable */                                                        
#define Pin4_BIE                    (* (reg8 *) Pin4__BIE)
/* Bit-mask for Aliased Register Access */
#define Pin4_BIT_MASK               (* (reg8 *) Pin4__BIT_MASK)
/* Bypass Enable */
#define Pin4_BYP                    (* (reg8 *) Pin4__BYP)
/* Port wide control signals */                                                   
#define Pin4_CTL                    (* (reg8 *) Pin4__CTL)
/* Drive Modes */
#define Pin4_DM0                    (* (reg8 *) Pin4__DM0) 
#define Pin4_DM1                    (* (reg8 *) Pin4__DM1)
#define Pin4_DM2                    (* (reg8 *) Pin4__DM2) 
/* Input Buffer Disable Override */
#define Pin4_INP_DIS                (* (reg8 *) Pin4__INP_DIS)
/* LCD Common or Segment Drive */
#define Pin4_LCD_COM_SEG            (* (reg8 *) Pin4__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pin4_LCD_EN                 (* (reg8 *) Pin4__LCD_EN)
/* Slew Rate Control */
#define Pin4_SLW                    (* (reg8 *) Pin4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pin4_PRTDSI__CAPS_SEL       (* (reg8 *) Pin4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pin4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pin4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pin4_PRTDSI__OE_SEL0        (* (reg8 *) Pin4__PRTDSI__OE_SEL0) 
#define Pin4_PRTDSI__OE_SEL1        (* (reg8 *) Pin4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pin4_PRTDSI__OUT_SEL0       (* (reg8 *) Pin4__PRTDSI__OUT_SEL0) 
#define Pin4_PRTDSI__OUT_SEL1       (* (reg8 *) Pin4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pin4_PRTDSI__SYNC_OUT       (* (reg8 *) Pin4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Pin4__SIO_CFG)
    #define Pin4_SIO_HYST_EN        (* (reg8 *) Pin4__SIO_HYST_EN)
    #define Pin4_SIO_REG_HIFREQ     (* (reg8 *) Pin4__SIO_REG_HIFREQ)
    #define Pin4_SIO_CFG            (* (reg8 *) Pin4__SIO_CFG)
    #define Pin4_SIO_DIFF           (* (reg8 *) Pin4__SIO_DIFF)
#endif /* (Pin4__SIO_CFG) */

/* Interrupt Registers */
#if defined(Pin4__INTSTAT)
    #define Pin4_INTSTAT            (* (reg8 *) Pin4__INTSTAT)
    #define Pin4_SNAP               (* (reg8 *) Pin4__SNAP)
    
	#define Pin4_0_INTTYPE_REG 		(* (reg8 *) Pin4__0__INTTYPE)
#endif /* (Pin4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pin4_H */


/* [] END OF FILE */
