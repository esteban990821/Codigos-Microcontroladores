/*******************************************************************************
* File Name: CO2.h  
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

#if !defined(CY_PINS_CO2_H) /* Pins CO2_H */
#define CY_PINS_CO2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CO2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CO2__PORT == 15 && ((CO2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CO2_Write(uint8 value);
void    CO2_SetDriveMode(uint8 mode);
uint8   CO2_ReadDataReg(void);
uint8   CO2_Read(void);
void    CO2_SetInterruptMode(uint16 position, uint16 mode);
uint8   CO2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CO2_SetDriveMode() function.
     *  @{
     */
        #define CO2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CO2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CO2_DM_RES_UP          PIN_DM_RES_UP
        #define CO2_DM_RES_DWN         PIN_DM_RES_DWN
        #define CO2_DM_OD_LO           PIN_DM_OD_LO
        #define CO2_DM_OD_HI           PIN_DM_OD_HI
        #define CO2_DM_STRONG          PIN_DM_STRONG
        #define CO2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CO2_MASK               CO2__MASK
#define CO2_SHIFT              CO2__SHIFT
#define CO2_WIDTH              1u

/* Interrupt constants */
#if defined(CO2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CO2_SetInterruptMode() function.
     *  @{
     */
        #define CO2_INTR_NONE      (uint16)(0x0000u)
        #define CO2_INTR_RISING    (uint16)(0x0001u)
        #define CO2_INTR_FALLING   (uint16)(0x0002u)
        #define CO2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CO2_INTR_MASK      (0x01u) 
#endif /* (CO2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CO2_PS                     (* (reg8 *) CO2__PS)
/* Data Register */
#define CO2_DR                     (* (reg8 *) CO2__DR)
/* Port Number */
#define CO2_PRT_NUM                (* (reg8 *) CO2__PRT) 
/* Connect to Analog Globals */                                                  
#define CO2_AG                     (* (reg8 *) CO2__AG)                       
/* Analog MUX bux enable */
#define CO2_AMUX                   (* (reg8 *) CO2__AMUX) 
/* Bidirectional Enable */                                                        
#define CO2_BIE                    (* (reg8 *) CO2__BIE)
/* Bit-mask for Aliased Register Access */
#define CO2_BIT_MASK               (* (reg8 *) CO2__BIT_MASK)
/* Bypass Enable */
#define CO2_BYP                    (* (reg8 *) CO2__BYP)
/* Port wide control signals */                                                   
#define CO2_CTL                    (* (reg8 *) CO2__CTL)
/* Drive Modes */
#define CO2_DM0                    (* (reg8 *) CO2__DM0) 
#define CO2_DM1                    (* (reg8 *) CO2__DM1)
#define CO2_DM2                    (* (reg8 *) CO2__DM2) 
/* Input Buffer Disable Override */
#define CO2_INP_DIS                (* (reg8 *) CO2__INP_DIS)
/* LCD Common or Segment Drive */
#define CO2_LCD_COM_SEG            (* (reg8 *) CO2__LCD_COM_SEG)
/* Enable Segment LCD */
#define CO2_LCD_EN                 (* (reg8 *) CO2__LCD_EN)
/* Slew Rate Control */
#define CO2_SLW                    (* (reg8 *) CO2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CO2_PRTDSI__CAPS_SEL       (* (reg8 *) CO2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CO2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CO2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CO2_PRTDSI__OE_SEL0        (* (reg8 *) CO2__PRTDSI__OE_SEL0) 
#define CO2_PRTDSI__OE_SEL1        (* (reg8 *) CO2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CO2_PRTDSI__OUT_SEL0       (* (reg8 *) CO2__PRTDSI__OUT_SEL0) 
#define CO2_PRTDSI__OUT_SEL1       (* (reg8 *) CO2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CO2_PRTDSI__SYNC_OUT       (* (reg8 *) CO2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CO2__SIO_CFG)
    #define CO2_SIO_HYST_EN        (* (reg8 *) CO2__SIO_HYST_EN)
    #define CO2_SIO_REG_HIFREQ     (* (reg8 *) CO2__SIO_REG_HIFREQ)
    #define CO2_SIO_CFG            (* (reg8 *) CO2__SIO_CFG)
    #define CO2_SIO_DIFF           (* (reg8 *) CO2__SIO_DIFF)
#endif /* (CO2__SIO_CFG) */

/* Interrupt Registers */
#if defined(CO2__INTSTAT)
    #define CO2_INTSTAT            (* (reg8 *) CO2__INTSTAT)
    #define CO2_SNAP               (* (reg8 *) CO2__SNAP)
    
	#define CO2_0_INTTYPE_REG 		(* (reg8 *) CO2__0__INTTYPE)
#endif /* (CO2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CO2_H */


/* [] END OF FILE */
