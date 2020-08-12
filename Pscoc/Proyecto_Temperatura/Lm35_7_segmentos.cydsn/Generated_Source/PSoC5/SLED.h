/*******************************************************************************
* File Name: SLED.h  
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

#if !defined(CY_PINS_SLED_H) /* Pins SLED_H */
#define CY_PINS_SLED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SLED_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SLED__PORT == 15 && ((SLED__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SLED_Write(uint8 value);
void    SLED_SetDriveMode(uint8 mode);
uint8   SLED_ReadDataReg(void);
uint8   SLED_Read(void);
void    SLED_SetInterruptMode(uint16 position, uint16 mode);
uint8   SLED_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SLED_SetDriveMode() function.
     *  @{
     */
        #define SLED_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SLED_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SLED_DM_RES_UP          PIN_DM_RES_UP
        #define SLED_DM_RES_DWN         PIN_DM_RES_DWN
        #define SLED_DM_OD_LO           PIN_DM_OD_LO
        #define SLED_DM_OD_HI           PIN_DM_OD_HI
        #define SLED_DM_STRONG          PIN_DM_STRONG
        #define SLED_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SLED_MASK               SLED__MASK
#define SLED_SHIFT              SLED__SHIFT
#define SLED_WIDTH              1u

/* Interrupt constants */
#if defined(SLED__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SLED_SetInterruptMode() function.
     *  @{
     */
        #define SLED_INTR_NONE      (uint16)(0x0000u)
        #define SLED_INTR_RISING    (uint16)(0x0001u)
        #define SLED_INTR_FALLING   (uint16)(0x0002u)
        #define SLED_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SLED_INTR_MASK      (0x01u) 
#endif /* (SLED__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SLED_PS                     (* (reg8 *) SLED__PS)
/* Data Register */
#define SLED_DR                     (* (reg8 *) SLED__DR)
/* Port Number */
#define SLED_PRT_NUM                (* (reg8 *) SLED__PRT) 
/* Connect to Analog Globals */                                                  
#define SLED_AG                     (* (reg8 *) SLED__AG)                       
/* Analog MUX bux enable */
#define SLED_AMUX                   (* (reg8 *) SLED__AMUX) 
/* Bidirectional Enable */                                                        
#define SLED_BIE                    (* (reg8 *) SLED__BIE)
/* Bit-mask for Aliased Register Access */
#define SLED_BIT_MASK               (* (reg8 *) SLED__BIT_MASK)
/* Bypass Enable */
#define SLED_BYP                    (* (reg8 *) SLED__BYP)
/* Port wide control signals */                                                   
#define SLED_CTL                    (* (reg8 *) SLED__CTL)
/* Drive Modes */
#define SLED_DM0                    (* (reg8 *) SLED__DM0) 
#define SLED_DM1                    (* (reg8 *) SLED__DM1)
#define SLED_DM2                    (* (reg8 *) SLED__DM2) 
/* Input Buffer Disable Override */
#define SLED_INP_DIS                (* (reg8 *) SLED__INP_DIS)
/* LCD Common or Segment Drive */
#define SLED_LCD_COM_SEG            (* (reg8 *) SLED__LCD_COM_SEG)
/* Enable Segment LCD */
#define SLED_LCD_EN                 (* (reg8 *) SLED__LCD_EN)
/* Slew Rate Control */
#define SLED_SLW                    (* (reg8 *) SLED__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SLED_PRTDSI__CAPS_SEL       (* (reg8 *) SLED__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SLED_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SLED__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SLED_PRTDSI__OE_SEL0        (* (reg8 *) SLED__PRTDSI__OE_SEL0) 
#define SLED_PRTDSI__OE_SEL1        (* (reg8 *) SLED__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SLED_PRTDSI__OUT_SEL0       (* (reg8 *) SLED__PRTDSI__OUT_SEL0) 
#define SLED_PRTDSI__OUT_SEL1       (* (reg8 *) SLED__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SLED_PRTDSI__SYNC_OUT       (* (reg8 *) SLED__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SLED__SIO_CFG)
    #define SLED_SIO_HYST_EN        (* (reg8 *) SLED__SIO_HYST_EN)
    #define SLED_SIO_REG_HIFREQ     (* (reg8 *) SLED__SIO_REG_HIFREQ)
    #define SLED_SIO_CFG            (* (reg8 *) SLED__SIO_CFG)
    #define SLED_SIO_DIFF           (* (reg8 *) SLED__SIO_DIFF)
#endif /* (SLED__SIO_CFG) */

/* Interrupt Registers */
#if defined(SLED__INTSTAT)
    #define SLED_INTSTAT            (* (reg8 *) SLED__INTSTAT)
    #define SLED_SNAP               (* (reg8 *) SLED__SNAP)
    
	#define SLED_0_INTTYPE_REG 		(* (reg8 *) SLED__0__INTTYPE)
#endif /* (SLED__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SLED_H */


/* [] END OF FILE */
