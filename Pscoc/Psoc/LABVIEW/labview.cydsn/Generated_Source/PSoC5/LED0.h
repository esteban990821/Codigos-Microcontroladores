/*******************************************************************************
* File Name: led0.h  
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

#if !defined(CY_PINS_led0_H) /* Pins led0_H */
#define CY_PINS_led0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "led0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 led0__PORT == 15 && ((led0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    led0_Write(uint8 value);
void    led0_SetDriveMode(uint8 mode);
uint8   led0_ReadDataReg(void);
uint8   led0_Read(void);
void    led0_SetInterruptMode(uint16 position, uint16 mode);
uint8   led0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the led0_SetDriveMode() function.
     *  @{
     */
        #define led0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define led0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define led0_DM_RES_UP          PIN_DM_RES_UP
        #define led0_DM_RES_DWN         PIN_DM_RES_DWN
        #define led0_DM_OD_LO           PIN_DM_OD_LO
        #define led0_DM_OD_HI           PIN_DM_OD_HI
        #define led0_DM_STRONG          PIN_DM_STRONG
        #define led0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define led0_MASK               led0__MASK
#define led0_SHIFT              led0__SHIFT
#define led0_WIDTH              1u

/* Interrupt constants */
#if defined(led0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in led0_SetInterruptMode() function.
     *  @{
     */
        #define led0_INTR_NONE      (uint16)(0x0000u)
        #define led0_INTR_RISING    (uint16)(0x0001u)
        #define led0_INTR_FALLING   (uint16)(0x0002u)
        #define led0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define led0_INTR_MASK      (0x01u) 
#endif /* (led0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define led0_PS                     (* (reg8 *) led0__PS)
/* Data Register */
#define led0_DR                     (* (reg8 *) led0__DR)
/* Port Number */
#define led0_PRT_NUM                (* (reg8 *) led0__PRT) 
/* Connect to Analog Globals */                                                  
#define led0_AG                     (* (reg8 *) led0__AG)                       
/* Analog MUX bux enable */
#define led0_AMUX                   (* (reg8 *) led0__AMUX) 
/* Bidirectional Enable */                                                        
#define led0_BIE                    (* (reg8 *) led0__BIE)
/* Bit-mask for Aliased Register Access */
#define led0_BIT_MASK               (* (reg8 *) led0__BIT_MASK)
/* Bypass Enable */
#define led0_BYP                    (* (reg8 *) led0__BYP)
/* Port wide control signals */                                                   
#define led0_CTL                    (* (reg8 *) led0__CTL)
/* Drive Modes */
#define led0_DM0                    (* (reg8 *) led0__DM0) 
#define led0_DM1                    (* (reg8 *) led0__DM1)
#define led0_DM2                    (* (reg8 *) led0__DM2) 
/* Input Buffer Disable Override */
#define led0_INP_DIS                (* (reg8 *) led0__INP_DIS)
/* LCD Common or Segment Drive */
#define led0_LCD_COM_SEG            (* (reg8 *) led0__LCD_COM_SEG)
/* Enable Segment LCD */
#define led0_LCD_EN                 (* (reg8 *) led0__LCD_EN)
/* Slew Rate Control */
#define led0_SLW                    (* (reg8 *) led0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define led0_PRTDSI__CAPS_SEL       (* (reg8 *) led0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define led0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) led0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define led0_PRTDSI__OE_SEL0        (* (reg8 *) led0__PRTDSI__OE_SEL0) 
#define led0_PRTDSI__OE_SEL1        (* (reg8 *) led0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define led0_PRTDSI__OUT_SEL0       (* (reg8 *) led0__PRTDSI__OUT_SEL0) 
#define led0_PRTDSI__OUT_SEL1       (* (reg8 *) led0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define led0_PRTDSI__SYNC_OUT       (* (reg8 *) led0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(led0__SIO_CFG)
    #define led0_SIO_HYST_EN        (* (reg8 *) led0__SIO_HYST_EN)
    #define led0_SIO_REG_HIFREQ     (* (reg8 *) led0__SIO_REG_HIFREQ)
    #define led0_SIO_CFG            (* (reg8 *) led0__SIO_CFG)
    #define led0_SIO_DIFF           (* (reg8 *) led0__SIO_DIFF)
#endif /* (led0__SIO_CFG) */

/* Interrupt Registers */
#if defined(led0__INTSTAT)
    #define led0_INTSTAT            (* (reg8 *) led0__INTSTAT)
    #define led0_SNAP               (* (reg8 *) led0__SNAP)
    
	#define led0_0_INTTYPE_REG 		(* (reg8 *) led0__0__INTTYPE)
#endif /* (led0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_led0_H */


/* [] END OF FILE */
