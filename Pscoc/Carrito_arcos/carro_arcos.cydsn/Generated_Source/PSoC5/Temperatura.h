/*******************************************************************************
* File Name: Temperatura.h  
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

#if !defined(CY_PINS_Temperatura_H) /* Pins Temperatura_H */
#define CY_PINS_Temperatura_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Temperatura_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Temperatura__PORT == 15 && ((Temperatura__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Temperatura_Write(uint8 value);
void    Temperatura_SetDriveMode(uint8 mode);
uint8   Temperatura_ReadDataReg(void);
uint8   Temperatura_Read(void);
void    Temperatura_SetInterruptMode(uint16 position, uint16 mode);
uint8   Temperatura_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Temperatura_SetDriveMode() function.
     *  @{
     */
        #define Temperatura_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Temperatura_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Temperatura_DM_RES_UP          PIN_DM_RES_UP
        #define Temperatura_DM_RES_DWN         PIN_DM_RES_DWN
        #define Temperatura_DM_OD_LO           PIN_DM_OD_LO
        #define Temperatura_DM_OD_HI           PIN_DM_OD_HI
        #define Temperatura_DM_STRONG          PIN_DM_STRONG
        #define Temperatura_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Temperatura_MASK               Temperatura__MASK
#define Temperatura_SHIFT              Temperatura__SHIFT
#define Temperatura_WIDTH              1u

/* Interrupt constants */
#if defined(Temperatura__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Temperatura_SetInterruptMode() function.
     *  @{
     */
        #define Temperatura_INTR_NONE      (uint16)(0x0000u)
        #define Temperatura_INTR_RISING    (uint16)(0x0001u)
        #define Temperatura_INTR_FALLING   (uint16)(0x0002u)
        #define Temperatura_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Temperatura_INTR_MASK      (0x01u) 
#endif /* (Temperatura__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Temperatura_PS                     (* (reg8 *) Temperatura__PS)
/* Data Register */
#define Temperatura_DR                     (* (reg8 *) Temperatura__DR)
/* Port Number */
#define Temperatura_PRT_NUM                (* (reg8 *) Temperatura__PRT) 
/* Connect to Analog Globals */                                                  
#define Temperatura_AG                     (* (reg8 *) Temperatura__AG)                       
/* Analog MUX bux enable */
#define Temperatura_AMUX                   (* (reg8 *) Temperatura__AMUX) 
/* Bidirectional Enable */                                                        
#define Temperatura_BIE                    (* (reg8 *) Temperatura__BIE)
/* Bit-mask for Aliased Register Access */
#define Temperatura_BIT_MASK               (* (reg8 *) Temperatura__BIT_MASK)
/* Bypass Enable */
#define Temperatura_BYP                    (* (reg8 *) Temperatura__BYP)
/* Port wide control signals */                                                   
#define Temperatura_CTL                    (* (reg8 *) Temperatura__CTL)
/* Drive Modes */
#define Temperatura_DM0                    (* (reg8 *) Temperatura__DM0) 
#define Temperatura_DM1                    (* (reg8 *) Temperatura__DM1)
#define Temperatura_DM2                    (* (reg8 *) Temperatura__DM2) 
/* Input Buffer Disable Override */
#define Temperatura_INP_DIS                (* (reg8 *) Temperatura__INP_DIS)
/* LCD Common or Segment Drive */
#define Temperatura_LCD_COM_SEG            (* (reg8 *) Temperatura__LCD_COM_SEG)
/* Enable Segment LCD */
#define Temperatura_LCD_EN                 (* (reg8 *) Temperatura__LCD_EN)
/* Slew Rate Control */
#define Temperatura_SLW                    (* (reg8 *) Temperatura__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Temperatura_PRTDSI__CAPS_SEL       (* (reg8 *) Temperatura__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Temperatura_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Temperatura__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Temperatura_PRTDSI__OE_SEL0        (* (reg8 *) Temperatura__PRTDSI__OE_SEL0) 
#define Temperatura_PRTDSI__OE_SEL1        (* (reg8 *) Temperatura__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Temperatura_PRTDSI__OUT_SEL0       (* (reg8 *) Temperatura__PRTDSI__OUT_SEL0) 
#define Temperatura_PRTDSI__OUT_SEL1       (* (reg8 *) Temperatura__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Temperatura_PRTDSI__SYNC_OUT       (* (reg8 *) Temperatura__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Temperatura__SIO_CFG)
    #define Temperatura_SIO_HYST_EN        (* (reg8 *) Temperatura__SIO_HYST_EN)
    #define Temperatura_SIO_REG_HIFREQ     (* (reg8 *) Temperatura__SIO_REG_HIFREQ)
    #define Temperatura_SIO_CFG            (* (reg8 *) Temperatura__SIO_CFG)
    #define Temperatura_SIO_DIFF           (* (reg8 *) Temperatura__SIO_DIFF)
#endif /* (Temperatura__SIO_CFG) */

/* Interrupt Registers */
#if defined(Temperatura__INTSTAT)
    #define Temperatura_INTSTAT            (* (reg8 *) Temperatura__INTSTAT)
    #define Temperatura_SNAP               (* (reg8 *) Temperatura__SNAP)
    
	#define Temperatura_0_INTTYPE_REG 		(* (reg8 *) Temperatura__0__INTTYPE)
#endif /* (Temperatura__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Temperatura_H */


/* [] END OF FILE */
