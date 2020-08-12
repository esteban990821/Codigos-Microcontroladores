/*******************************************************************************
* File Name: CNY1.h  
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

#if !defined(CY_PINS_CNY1_H) /* Pins CNY1_H */
#define CY_PINS_CNY1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CNY1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CNY1__PORT == 15 && ((CNY1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CNY1_Write(uint8 value);
void    CNY1_SetDriveMode(uint8 mode);
uint8   CNY1_ReadDataReg(void);
uint8   CNY1_Read(void);
void    CNY1_SetInterruptMode(uint16 position, uint16 mode);
uint8   CNY1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CNY1_SetDriveMode() function.
     *  @{
     */
        #define CNY1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CNY1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CNY1_DM_RES_UP          PIN_DM_RES_UP
        #define CNY1_DM_RES_DWN         PIN_DM_RES_DWN
        #define CNY1_DM_OD_LO           PIN_DM_OD_LO
        #define CNY1_DM_OD_HI           PIN_DM_OD_HI
        #define CNY1_DM_STRONG          PIN_DM_STRONG
        #define CNY1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CNY1_MASK               CNY1__MASK
#define CNY1_SHIFT              CNY1__SHIFT
#define CNY1_WIDTH              1u

/* Interrupt constants */
#if defined(CNY1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CNY1_SetInterruptMode() function.
     *  @{
     */
        #define CNY1_INTR_NONE      (uint16)(0x0000u)
        #define CNY1_INTR_RISING    (uint16)(0x0001u)
        #define CNY1_INTR_FALLING   (uint16)(0x0002u)
        #define CNY1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CNY1_INTR_MASK      (0x01u) 
#endif /* (CNY1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CNY1_PS                     (* (reg8 *) CNY1__PS)
/* Data Register */
#define CNY1_DR                     (* (reg8 *) CNY1__DR)
/* Port Number */
#define CNY1_PRT_NUM                (* (reg8 *) CNY1__PRT) 
/* Connect to Analog Globals */                                                  
#define CNY1_AG                     (* (reg8 *) CNY1__AG)                       
/* Analog MUX bux enable */
#define CNY1_AMUX                   (* (reg8 *) CNY1__AMUX) 
/* Bidirectional Enable */                                                        
#define CNY1_BIE                    (* (reg8 *) CNY1__BIE)
/* Bit-mask for Aliased Register Access */
#define CNY1_BIT_MASK               (* (reg8 *) CNY1__BIT_MASK)
/* Bypass Enable */
#define CNY1_BYP                    (* (reg8 *) CNY1__BYP)
/* Port wide control signals */                                                   
#define CNY1_CTL                    (* (reg8 *) CNY1__CTL)
/* Drive Modes */
#define CNY1_DM0                    (* (reg8 *) CNY1__DM0) 
#define CNY1_DM1                    (* (reg8 *) CNY1__DM1)
#define CNY1_DM2                    (* (reg8 *) CNY1__DM2) 
/* Input Buffer Disable Override */
#define CNY1_INP_DIS                (* (reg8 *) CNY1__INP_DIS)
/* LCD Common or Segment Drive */
#define CNY1_LCD_COM_SEG            (* (reg8 *) CNY1__LCD_COM_SEG)
/* Enable Segment LCD */
#define CNY1_LCD_EN                 (* (reg8 *) CNY1__LCD_EN)
/* Slew Rate Control */
#define CNY1_SLW                    (* (reg8 *) CNY1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CNY1_PRTDSI__CAPS_SEL       (* (reg8 *) CNY1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CNY1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CNY1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CNY1_PRTDSI__OE_SEL0        (* (reg8 *) CNY1__PRTDSI__OE_SEL0) 
#define CNY1_PRTDSI__OE_SEL1        (* (reg8 *) CNY1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CNY1_PRTDSI__OUT_SEL0       (* (reg8 *) CNY1__PRTDSI__OUT_SEL0) 
#define CNY1_PRTDSI__OUT_SEL1       (* (reg8 *) CNY1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CNY1_PRTDSI__SYNC_OUT       (* (reg8 *) CNY1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CNY1__SIO_CFG)
    #define CNY1_SIO_HYST_EN        (* (reg8 *) CNY1__SIO_HYST_EN)
    #define CNY1_SIO_REG_HIFREQ     (* (reg8 *) CNY1__SIO_REG_HIFREQ)
    #define CNY1_SIO_CFG            (* (reg8 *) CNY1__SIO_CFG)
    #define CNY1_SIO_DIFF           (* (reg8 *) CNY1__SIO_DIFF)
#endif /* (CNY1__SIO_CFG) */

/* Interrupt Registers */
#if defined(CNY1__INTSTAT)
    #define CNY1_INTSTAT            (* (reg8 *) CNY1__INTSTAT)
    #define CNY1_SNAP               (* (reg8 *) CNY1__SNAP)
    
	#define CNY1_0_INTTYPE_REG 		(* (reg8 *) CNY1__0__INTTYPE)
#endif /* (CNY1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CNY1_H */


/* [] END OF FILE */
