/*******************************************************************************
* File Name: inicio.h  
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

#if !defined(CY_PINS_inicio_H) /* Pins inicio_H */
#define CY_PINS_inicio_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "inicio_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 inicio__PORT == 15 && ((inicio__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    inicio_Write(uint8 value);
void    inicio_SetDriveMode(uint8 mode);
uint8   inicio_ReadDataReg(void);
uint8   inicio_Read(void);
void    inicio_SetInterruptMode(uint16 position, uint16 mode);
uint8   inicio_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the inicio_SetDriveMode() function.
     *  @{
     */
        #define inicio_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define inicio_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define inicio_DM_RES_UP          PIN_DM_RES_UP
        #define inicio_DM_RES_DWN         PIN_DM_RES_DWN
        #define inicio_DM_OD_LO           PIN_DM_OD_LO
        #define inicio_DM_OD_HI           PIN_DM_OD_HI
        #define inicio_DM_STRONG          PIN_DM_STRONG
        #define inicio_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define inicio_MASK               inicio__MASK
#define inicio_SHIFT              inicio__SHIFT
#define inicio_WIDTH              1u

/* Interrupt constants */
#if defined(inicio__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in inicio_SetInterruptMode() function.
     *  @{
     */
        #define inicio_INTR_NONE      (uint16)(0x0000u)
        #define inicio_INTR_RISING    (uint16)(0x0001u)
        #define inicio_INTR_FALLING   (uint16)(0x0002u)
        #define inicio_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define inicio_INTR_MASK      (0x01u) 
#endif /* (inicio__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define inicio_PS                     (* (reg8 *) inicio__PS)
/* Data Register */
#define inicio_DR                     (* (reg8 *) inicio__DR)
/* Port Number */
#define inicio_PRT_NUM                (* (reg8 *) inicio__PRT) 
/* Connect to Analog Globals */                                                  
#define inicio_AG                     (* (reg8 *) inicio__AG)                       
/* Analog MUX bux enable */
#define inicio_AMUX                   (* (reg8 *) inicio__AMUX) 
/* Bidirectional Enable */                                                        
#define inicio_BIE                    (* (reg8 *) inicio__BIE)
/* Bit-mask for Aliased Register Access */
#define inicio_BIT_MASK               (* (reg8 *) inicio__BIT_MASK)
/* Bypass Enable */
#define inicio_BYP                    (* (reg8 *) inicio__BYP)
/* Port wide control signals */                                                   
#define inicio_CTL                    (* (reg8 *) inicio__CTL)
/* Drive Modes */
#define inicio_DM0                    (* (reg8 *) inicio__DM0) 
#define inicio_DM1                    (* (reg8 *) inicio__DM1)
#define inicio_DM2                    (* (reg8 *) inicio__DM2) 
/* Input Buffer Disable Override */
#define inicio_INP_DIS                (* (reg8 *) inicio__INP_DIS)
/* LCD Common or Segment Drive */
#define inicio_LCD_COM_SEG            (* (reg8 *) inicio__LCD_COM_SEG)
/* Enable Segment LCD */
#define inicio_LCD_EN                 (* (reg8 *) inicio__LCD_EN)
/* Slew Rate Control */
#define inicio_SLW                    (* (reg8 *) inicio__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define inicio_PRTDSI__CAPS_SEL       (* (reg8 *) inicio__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define inicio_PRTDSI__DBL_SYNC_IN    (* (reg8 *) inicio__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define inicio_PRTDSI__OE_SEL0        (* (reg8 *) inicio__PRTDSI__OE_SEL0) 
#define inicio_PRTDSI__OE_SEL1        (* (reg8 *) inicio__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define inicio_PRTDSI__OUT_SEL0       (* (reg8 *) inicio__PRTDSI__OUT_SEL0) 
#define inicio_PRTDSI__OUT_SEL1       (* (reg8 *) inicio__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define inicio_PRTDSI__SYNC_OUT       (* (reg8 *) inicio__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(inicio__SIO_CFG)
    #define inicio_SIO_HYST_EN        (* (reg8 *) inicio__SIO_HYST_EN)
    #define inicio_SIO_REG_HIFREQ     (* (reg8 *) inicio__SIO_REG_HIFREQ)
    #define inicio_SIO_CFG            (* (reg8 *) inicio__SIO_CFG)
    #define inicio_SIO_DIFF           (* (reg8 *) inicio__SIO_DIFF)
#endif /* (inicio__SIO_CFG) */

/* Interrupt Registers */
#if defined(inicio__INTSTAT)
    #define inicio_INTSTAT            (* (reg8 *) inicio__INTSTAT)
    #define inicio_SNAP               (* (reg8 *) inicio__SNAP)
    
	#define inicio_0_INTTYPE_REG 		(* (reg8 *) inicio__0__INTTYPE)
#endif /* (inicio__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_inicio_H */


/* [] END OF FILE */
