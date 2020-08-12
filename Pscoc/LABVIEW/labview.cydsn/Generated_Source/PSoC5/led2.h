/*******************************************************************************
* File Name: led2.h  
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

#if !defined(CY_PINS_led2_H) /* Pins led2_H */
#define CY_PINS_led2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "led2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 led2__PORT == 15 && ((led2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    led2_Write(uint8 value);
void    led2_SetDriveMode(uint8 mode);
uint8   led2_ReadDataReg(void);
uint8   led2_Read(void);
void    led2_SetInterruptMode(uint16 position, uint16 mode);
uint8   led2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the led2_SetDriveMode() function.
     *  @{
     */
        #define led2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define led2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define led2_DM_RES_UP          PIN_DM_RES_UP
        #define led2_DM_RES_DWN         PIN_DM_RES_DWN
        #define led2_DM_OD_LO           PIN_DM_OD_LO
        #define led2_DM_OD_HI           PIN_DM_OD_HI
        #define led2_DM_STRONG          PIN_DM_STRONG
        #define led2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define led2_MASK               led2__MASK
#define led2_SHIFT              led2__SHIFT
#define led2_WIDTH              1u

/* Interrupt constants */
#if defined(led2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in led2_SetInterruptMode() function.
     *  @{
     */
        #define led2_INTR_NONE      (uint16)(0x0000u)
        #define led2_INTR_RISING    (uint16)(0x0001u)
        #define led2_INTR_FALLING   (uint16)(0x0002u)
        #define led2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define led2_INTR_MASK      (0x01u) 
#endif /* (led2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define led2_PS                     (* (reg8 *) led2__PS)
/* Data Register */
#define led2_DR                     (* (reg8 *) led2__DR)
/* Port Number */
#define led2_PRT_NUM                (* (reg8 *) led2__PRT) 
/* Connect to Analog Globals */                                                  
#define led2_AG                     (* (reg8 *) led2__AG)                       
/* Analog MUX bux enable */
#define led2_AMUX                   (* (reg8 *) led2__AMUX) 
/* Bidirectional Enable */                                                        
#define led2_BIE                    (* (reg8 *) led2__BIE)
/* Bit-mask for Aliased Register Access */
#define led2_BIT_MASK               (* (reg8 *) led2__BIT_MASK)
/* Bypass Enable */
#define led2_BYP                    (* (reg8 *) led2__BYP)
/* Port wide control signals */                                                   
#define led2_CTL                    (* (reg8 *) led2__CTL)
/* Drive Modes */
#define led2_DM0                    (* (reg8 *) led2__DM0) 
#define led2_DM1                    (* (reg8 *) led2__DM1)
#define led2_DM2                    (* (reg8 *) led2__DM2) 
/* Input Buffer Disable Override */
#define led2_INP_DIS                (* (reg8 *) led2__INP_DIS)
/* LCD Common or Segment Drive */
#define led2_LCD_COM_SEG            (* (reg8 *) led2__LCD_COM_SEG)
/* Enable Segment LCD */
#define led2_LCD_EN                 (* (reg8 *) led2__LCD_EN)
/* Slew Rate Control */
#define led2_SLW                    (* (reg8 *) led2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define led2_PRTDSI__CAPS_SEL       (* (reg8 *) led2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define led2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) led2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define led2_PRTDSI__OE_SEL0        (* (reg8 *) led2__PRTDSI__OE_SEL0) 
#define led2_PRTDSI__OE_SEL1        (* (reg8 *) led2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define led2_PRTDSI__OUT_SEL0       (* (reg8 *) led2__PRTDSI__OUT_SEL0) 
#define led2_PRTDSI__OUT_SEL1       (* (reg8 *) led2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define led2_PRTDSI__SYNC_OUT       (* (reg8 *) led2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(led2__SIO_CFG)
    #define led2_SIO_HYST_EN        (* (reg8 *) led2__SIO_HYST_EN)
    #define led2_SIO_REG_HIFREQ     (* (reg8 *) led2__SIO_REG_HIFREQ)
    #define led2_SIO_CFG            (* (reg8 *) led2__SIO_CFG)
    #define led2_SIO_DIFF           (* (reg8 *) led2__SIO_DIFF)
#endif /* (led2__SIO_CFG) */

/* Interrupt Registers */
#if defined(led2__INTSTAT)
    #define led2_INTSTAT            (* (reg8 *) led2__INTSTAT)
    #define led2_SNAP               (* (reg8 *) led2__SNAP)
    
	#define led2_0_INTTYPE_REG 		(* (reg8 *) led2__0__INTTYPE)
#endif /* (led2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_led2_H */


/* [] END OF FILE */
