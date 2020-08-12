/*******************************************************************************
* File Name: aumentar.h  
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

#if !defined(CY_PINS_aumentar_H) /* Pins aumentar_H */
#define CY_PINS_aumentar_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "aumentar_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 aumentar__PORT == 15 && ((aumentar__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    aumentar_Write(uint8 value);
void    aumentar_SetDriveMode(uint8 mode);
uint8   aumentar_ReadDataReg(void);
uint8   aumentar_Read(void);
void    aumentar_SetInterruptMode(uint16 position, uint16 mode);
uint8   aumentar_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the aumentar_SetDriveMode() function.
     *  @{
     */
        #define aumentar_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define aumentar_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define aumentar_DM_RES_UP          PIN_DM_RES_UP
        #define aumentar_DM_RES_DWN         PIN_DM_RES_DWN
        #define aumentar_DM_OD_LO           PIN_DM_OD_LO
        #define aumentar_DM_OD_HI           PIN_DM_OD_HI
        #define aumentar_DM_STRONG          PIN_DM_STRONG
        #define aumentar_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define aumentar_MASK               aumentar__MASK
#define aumentar_SHIFT              aumentar__SHIFT
#define aumentar_WIDTH              1u

/* Interrupt constants */
#if defined(aumentar__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in aumentar_SetInterruptMode() function.
     *  @{
     */
        #define aumentar_INTR_NONE      (uint16)(0x0000u)
        #define aumentar_INTR_RISING    (uint16)(0x0001u)
        #define aumentar_INTR_FALLING   (uint16)(0x0002u)
        #define aumentar_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define aumentar_INTR_MASK      (0x01u) 
#endif /* (aumentar__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define aumentar_PS                     (* (reg8 *) aumentar__PS)
/* Data Register */
#define aumentar_DR                     (* (reg8 *) aumentar__DR)
/* Port Number */
#define aumentar_PRT_NUM                (* (reg8 *) aumentar__PRT) 
/* Connect to Analog Globals */                                                  
#define aumentar_AG                     (* (reg8 *) aumentar__AG)                       
/* Analog MUX bux enable */
#define aumentar_AMUX                   (* (reg8 *) aumentar__AMUX) 
/* Bidirectional Enable */                                                        
#define aumentar_BIE                    (* (reg8 *) aumentar__BIE)
/* Bit-mask for Aliased Register Access */
#define aumentar_BIT_MASK               (* (reg8 *) aumentar__BIT_MASK)
/* Bypass Enable */
#define aumentar_BYP                    (* (reg8 *) aumentar__BYP)
/* Port wide control signals */                                                   
#define aumentar_CTL                    (* (reg8 *) aumentar__CTL)
/* Drive Modes */
#define aumentar_DM0                    (* (reg8 *) aumentar__DM0) 
#define aumentar_DM1                    (* (reg8 *) aumentar__DM1)
#define aumentar_DM2                    (* (reg8 *) aumentar__DM2) 
/* Input Buffer Disable Override */
#define aumentar_INP_DIS                (* (reg8 *) aumentar__INP_DIS)
/* LCD Common or Segment Drive */
#define aumentar_LCD_COM_SEG            (* (reg8 *) aumentar__LCD_COM_SEG)
/* Enable Segment LCD */
#define aumentar_LCD_EN                 (* (reg8 *) aumentar__LCD_EN)
/* Slew Rate Control */
#define aumentar_SLW                    (* (reg8 *) aumentar__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define aumentar_PRTDSI__CAPS_SEL       (* (reg8 *) aumentar__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define aumentar_PRTDSI__DBL_SYNC_IN    (* (reg8 *) aumentar__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define aumentar_PRTDSI__OE_SEL0        (* (reg8 *) aumentar__PRTDSI__OE_SEL0) 
#define aumentar_PRTDSI__OE_SEL1        (* (reg8 *) aumentar__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define aumentar_PRTDSI__OUT_SEL0       (* (reg8 *) aumentar__PRTDSI__OUT_SEL0) 
#define aumentar_PRTDSI__OUT_SEL1       (* (reg8 *) aumentar__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define aumentar_PRTDSI__SYNC_OUT       (* (reg8 *) aumentar__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(aumentar__SIO_CFG)
    #define aumentar_SIO_HYST_EN        (* (reg8 *) aumentar__SIO_HYST_EN)
    #define aumentar_SIO_REG_HIFREQ     (* (reg8 *) aumentar__SIO_REG_HIFREQ)
    #define aumentar_SIO_CFG            (* (reg8 *) aumentar__SIO_CFG)
    #define aumentar_SIO_DIFF           (* (reg8 *) aumentar__SIO_DIFF)
#endif /* (aumentar__SIO_CFG) */

/* Interrupt Registers */
#if defined(aumentar__INTSTAT)
    #define aumentar_INTSTAT            (* (reg8 *) aumentar__INTSTAT)
    #define aumentar_SNAP               (* (reg8 *) aumentar__SNAP)
    
	#define aumentar_0_INTTYPE_REG 		(* (reg8 *) aumentar__0__INTTYPE)
#endif /* (aumentar__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_aumentar_H */


/* [] END OF FILE */
