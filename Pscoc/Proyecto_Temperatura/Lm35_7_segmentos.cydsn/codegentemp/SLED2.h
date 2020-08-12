/*******************************************************************************
* File Name: SLED2.h  
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

#if !defined(CY_PINS_SLED2_H) /* Pins SLED2_H */
#define CY_PINS_SLED2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SLED2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SLED2__PORT == 15 && ((SLED2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SLED2_Write(uint8 value);
void    SLED2_SetDriveMode(uint8 mode);
uint8   SLED2_ReadDataReg(void);
uint8   SLED2_Read(void);
void    SLED2_SetInterruptMode(uint16 position, uint16 mode);
uint8   SLED2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SLED2_SetDriveMode() function.
     *  @{
     */
        #define SLED2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SLED2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SLED2_DM_RES_UP          PIN_DM_RES_UP
        #define SLED2_DM_RES_DWN         PIN_DM_RES_DWN
        #define SLED2_DM_OD_LO           PIN_DM_OD_LO
        #define SLED2_DM_OD_HI           PIN_DM_OD_HI
        #define SLED2_DM_STRONG          PIN_DM_STRONG
        #define SLED2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SLED2_MASK               SLED2__MASK
#define SLED2_SHIFT              SLED2__SHIFT
#define SLED2_WIDTH              1u

/* Interrupt constants */
#if defined(SLED2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SLED2_SetInterruptMode() function.
     *  @{
     */
        #define SLED2_INTR_NONE      (uint16)(0x0000u)
        #define SLED2_INTR_RISING    (uint16)(0x0001u)
        #define SLED2_INTR_FALLING   (uint16)(0x0002u)
        #define SLED2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SLED2_INTR_MASK      (0x01u) 
#endif /* (SLED2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SLED2_PS                     (* (reg8 *) SLED2__PS)
/* Data Register */
#define SLED2_DR                     (* (reg8 *) SLED2__DR)
/* Port Number */
#define SLED2_PRT_NUM                (* (reg8 *) SLED2__PRT) 
/* Connect to Analog Globals */                                                  
#define SLED2_AG                     (* (reg8 *) SLED2__AG)                       
/* Analog MUX bux enable */
#define SLED2_AMUX                   (* (reg8 *) SLED2__AMUX) 
/* Bidirectional Enable */                                                        
#define SLED2_BIE                    (* (reg8 *) SLED2__BIE)
/* Bit-mask for Aliased Register Access */
#define SLED2_BIT_MASK               (* (reg8 *) SLED2__BIT_MASK)
/* Bypass Enable */
#define SLED2_BYP                    (* (reg8 *) SLED2__BYP)
/* Port wide control signals */                                                   
#define SLED2_CTL                    (* (reg8 *) SLED2__CTL)
/* Drive Modes */
#define SLED2_DM0                    (* (reg8 *) SLED2__DM0) 
#define SLED2_DM1                    (* (reg8 *) SLED2__DM1)
#define SLED2_DM2                    (* (reg8 *) SLED2__DM2) 
/* Input Buffer Disable Override */
#define SLED2_INP_DIS                (* (reg8 *) SLED2__INP_DIS)
/* LCD Common or Segment Drive */
#define SLED2_LCD_COM_SEG            (* (reg8 *) SLED2__LCD_COM_SEG)
/* Enable Segment LCD */
#define SLED2_LCD_EN                 (* (reg8 *) SLED2__LCD_EN)
/* Slew Rate Control */
#define SLED2_SLW                    (* (reg8 *) SLED2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SLED2_PRTDSI__CAPS_SEL       (* (reg8 *) SLED2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SLED2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SLED2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SLED2_PRTDSI__OE_SEL0        (* (reg8 *) SLED2__PRTDSI__OE_SEL0) 
#define SLED2_PRTDSI__OE_SEL1        (* (reg8 *) SLED2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SLED2_PRTDSI__OUT_SEL0       (* (reg8 *) SLED2__PRTDSI__OUT_SEL0) 
#define SLED2_PRTDSI__OUT_SEL1       (* (reg8 *) SLED2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SLED2_PRTDSI__SYNC_OUT       (* (reg8 *) SLED2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SLED2__SIO_CFG)
    #define SLED2_SIO_HYST_EN        (* (reg8 *) SLED2__SIO_HYST_EN)
    #define SLED2_SIO_REG_HIFREQ     (* (reg8 *) SLED2__SIO_REG_HIFREQ)
    #define SLED2_SIO_CFG            (* (reg8 *) SLED2__SIO_CFG)
    #define SLED2_SIO_DIFF           (* (reg8 *) SLED2__SIO_DIFF)
#endif /* (SLED2__SIO_CFG) */

/* Interrupt Registers */
#if defined(SLED2__INTSTAT)
    #define SLED2_INTSTAT            (* (reg8 *) SLED2__INTSTAT)
    #define SLED2_SNAP               (* (reg8 *) SLED2__SNAP)
    
	#define SLED2_0_INTTYPE_REG 		(* (reg8 *) SLED2__0__INTTYPE)
#endif /* (SLED2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SLED2_H */


/* [] END OF FILE */
