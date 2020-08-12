/*******************************************************************************
* File Name: Entrada2.h  
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

#if !defined(CY_PINS_Entrada2_H) /* Pins Entrada2_H */
#define CY_PINS_Entrada2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Entrada2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Entrada2__PORT == 15 && ((Entrada2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Entrada2_Write(uint8 value);
void    Entrada2_SetDriveMode(uint8 mode);
uint8   Entrada2_ReadDataReg(void);
uint8   Entrada2_Read(void);
void    Entrada2_SetInterruptMode(uint16 position, uint16 mode);
uint8   Entrada2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Entrada2_SetDriveMode() function.
     *  @{
     */
        #define Entrada2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Entrada2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Entrada2_DM_RES_UP          PIN_DM_RES_UP
        #define Entrada2_DM_RES_DWN         PIN_DM_RES_DWN
        #define Entrada2_DM_OD_LO           PIN_DM_OD_LO
        #define Entrada2_DM_OD_HI           PIN_DM_OD_HI
        #define Entrada2_DM_STRONG          PIN_DM_STRONG
        #define Entrada2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Entrada2_MASK               Entrada2__MASK
#define Entrada2_SHIFT              Entrada2__SHIFT
#define Entrada2_WIDTH              1u

/* Interrupt constants */
#if defined(Entrada2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Entrada2_SetInterruptMode() function.
     *  @{
     */
        #define Entrada2_INTR_NONE      (uint16)(0x0000u)
        #define Entrada2_INTR_RISING    (uint16)(0x0001u)
        #define Entrada2_INTR_FALLING   (uint16)(0x0002u)
        #define Entrada2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Entrada2_INTR_MASK      (0x01u) 
#endif /* (Entrada2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Entrada2_PS                     (* (reg8 *) Entrada2__PS)
/* Data Register */
#define Entrada2_DR                     (* (reg8 *) Entrada2__DR)
/* Port Number */
#define Entrada2_PRT_NUM                (* (reg8 *) Entrada2__PRT) 
/* Connect to Analog Globals */                                                  
#define Entrada2_AG                     (* (reg8 *) Entrada2__AG)                       
/* Analog MUX bux enable */
#define Entrada2_AMUX                   (* (reg8 *) Entrada2__AMUX) 
/* Bidirectional Enable */                                                        
#define Entrada2_BIE                    (* (reg8 *) Entrada2__BIE)
/* Bit-mask for Aliased Register Access */
#define Entrada2_BIT_MASK               (* (reg8 *) Entrada2__BIT_MASK)
/* Bypass Enable */
#define Entrada2_BYP                    (* (reg8 *) Entrada2__BYP)
/* Port wide control signals */                                                   
#define Entrada2_CTL                    (* (reg8 *) Entrada2__CTL)
/* Drive Modes */
#define Entrada2_DM0                    (* (reg8 *) Entrada2__DM0) 
#define Entrada2_DM1                    (* (reg8 *) Entrada2__DM1)
#define Entrada2_DM2                    (* (reg8 *) Entrada2__DM2) 
/* Input Buffer Disable Override */
#define Entrada2_INP_DIS                (* (reg8 *) Entrada2__INP_DIS)
/* LCD Common or Segment Drive */
#define Entrada2_LCD_COM_SEG            (* (reg8 *) Entrada2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Entrada2_LCD_EN                 (* (reg8 *) Entrada2__LCD_EN)
/* Slew Rate Control */
#define Entrada2_SLW                    (* (reg8 *) Entrada2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Entrada2_PRTDSI__CAPS_SEL       (* (reg8 *) Entrada2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Entrada2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Entrada2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Entrada2_PRTDSI__OE_SEL0        (* (reg8 *) Entrada2__PRTDSI__OE_SEL0) 
#define Entrada2_PRTDSI__OE_SEL1        (* (reg8 *) Entrada2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Entrada2_PRTDSI__OUT_SEL0       (* (reg8 *) Entrada2__PRTDSI__OUT_SEL0) 
#define Entrada2_PRTDSI__OUT_SEL1       (* (reg8 *) Entrada2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Entrada2_PRTDSI__SYNC_OUT       (* (reg8 *) Entrada2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Entrada2__SIO_CFG)
    #define Entrada2_SIO_HYST_EN        (* (reg8 *) Entrada2__SIO_HYST_EN)
    #define Entrada2_SIO_REG_HIFREQ     (* (reg8 *) Entrada2__SIO_REG_HIFREQ)
    #define Entrada2_SIO_CFG            (* (reg8 *) Entrada2__SIO_CFG)
    #define Entrada2_SIO_DIFF           (* (reg8 *) Entrada2__SIO_DIFF)
#endif /* (Entrada2__SIO_CFG) */

/* Interrupt Registers */
#if defined(Entrada2__INTSTAT)
    #define Entrada2_INTSTAT            (* (reg8 *) Entrada2__INTSTAT)
    #define Entrada2_SNAP               (* (reg8 *) Entrada2__SNAP)
    
	#define Entrada2_0_INTTYPE_REG 		(* (reg8 *) Entrada2__0__INTTYPE)
#endif /* (Entrada2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Entrada2_H */


/* [] END OF FILE */
