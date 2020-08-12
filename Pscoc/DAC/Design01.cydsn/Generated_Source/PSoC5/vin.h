/*******************************************************************************
* File Name: vin.h  
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

#if !defined(CY_PINS_vin_H) /* Pins vin_H */
#define CY_PINS_vin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "vin_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 vin__PORT == 15 && ((vin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    vin_Write(uint8 value);
void    vin_SetDriveMode(uint8 mode);
uint8   vin_ReadDataReg(void);
uint8   vin_Read(void);
void    vin_SetInterruptMode(uint16 position, uint16 mode);
uint8   vin_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the vin_SetDriveMode() function.
     *  @{
     */
        #define vin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define vin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define vin_DM_RES_UP          PIN_DM_RES_UP
        #define vin_DM_RES_DWN         PIN_DM_RES_DWN
        #define vin_DM_OD_LO           PIN_DM_OD_LO
        #define vin_DM_OD_HI           PIN_DM_OD_HI
        #define vin_DM_STRONG          PIN_DM_STRONG
        #define vin_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define vin_MASK               vin__MASK
#define vin_SHIFT              vin__SHIFT
#define vin_WIDTH              1u

/* Interrupt constants */
#if defined(vin__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in vin_SetInterruptMode() function.
     *  @{
     */
        #define vin_INTR_NONE      (uint16)(0x0000u)
        #define vin_INTR_RISING    (uint16)(0x0001u)
        #define vin_INTR_FALLING   (uint16)(0x0002u)
        #define vin_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define vin_INTR_MASK      (0x01u) 
#endif /* (vin__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define vin_PS                     (* (reg8 *) vin__PS)
/* Data Register */
#define vin_DR                     (* (reg8 *) vin__DR)
/* Port Number */
#define vin_PRT_NUM                (* (reg8 *) vin__PRT) 
/* Connect to Analog Globals */                                                  
#define vin_AG                     (* (reg8 *) vin__AG)                       
/* Analog MUX bux enable */
#define vin_AMUX                   (* (reg8 *) vin__AMUX) 
/* Bidirectional Enable */                                                        
#define vin_BIE                    (* (reg8 *) vin__BIE)
/* Bit-mask for Aliased Register Access */
#define vin_BIT_MASK               (* (reg8 *) vin__BIT_MASK)
/* Bypass Enable */
#define vin_BYP                    (* (reg8 *) vin__BYP)
/* Port wide control signals */                                                   
#define vin_CTL                    (* (reg8 *) vin__CTL)
/* Drive Modes */
#define vin_DM0                    (* (reg8 *) vin__DM0) 
#define vin_DM1                    (* (reg8 *) vin__DM1)
#define vin_DM2                    (* (reg8 *) vin__DM2) 
/* Input Buffer Disable Override */
#define vin_INP_DIS                (* (reg8 *) vin__INP_DIS)
/* LCD Common or Segment Drive */
#define vin_LCD_COM_SEG            (* (reg8 *) vin__LCD_COM_SEG)
/* Enable Segment LCD */
#define vin_LCD_EN                 (* (reg8 *) vin__LCD_EN)
/* Slew Rate Control */
#define vin_SLW                    (* (reg8 *) vin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define vin_PRTDSI__CAPS_SEL       (* (reg8 *) vin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define vin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) vin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define vin_PRTDSI__OE_SEL0        (* (reg8 *) vin__PRTDSI__OE_SEL0) 
#define vin_PRTDSI__OE_SEL1        (* (reg8 *) vin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define vin_PRTDSI__OUT_SEL0       (* (reg8 *) vin__PRTDSI__OUT_SEL0) 
#define vin_PRTDSI__OUT_SEL1       (* (reg8 *) vin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define vin_PRTDSI__SYNC_OUT       (* (reg8 *) vin__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(vin__SIO_CFG)
    #define vin_SIO_HYST_EN        (* (reg8 *) vin__SIO_HYST_EN)
    #define vin_SIO_REG_HIFREQ     (* (reg8 *) vin__SIO_REG_HIFREQ)
    #define vin_SIO_CFG            (* (reg8 *) vin__SIO_CFG)
    #define vin_SIO_DIFF           (* (reg8 *) vin__SIO_DIFF)
#endif /* (vin__SIO_CFG) */

/* Interrupt Registers */
#if defined(vin__INTSTAT)
    #define vin_INTSTAT            (* (reg8 *) vin__INTSTAT)
    #define vin_SNAP               (* (reg8 *) vin__SNAP)
    
	#define vin_0_INTTYPE_REG 		(* (reg8 *) vin__0__INTTYPE)
#endif /* (vin__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_vin_H */


/* [] END OF FILE */
