/*******************************************************************************
* File Name: Pusador.h  
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

#if !defined(CY_PINS_Pusador_H) /* Pins Pusador_H */
#define CY_PINS_Pusador_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pusador_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pusador__PORT == 15 && ((Pusador__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Pusador_Write(uint8 value);
void    Pusador_SetDriveMode(uint8 mode);
uint8   Pusador_ReadDataReg(void);
uint8   Pusador_Read(void);
void    Pusador_SetInterruptMode(uint16 position, uint16 mode);
uint8   Pusador_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Pusador_SetDriveMode() function.
     *  @{
     */
        #define Pusador_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Pusador_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Pusador_DM_RES_UP          PIN_DM_RES_UP
        #define Pusador_DM_RES_DWN         PIN_DM_RES_DWN
        #define Pusador_DM_OD_LO           PIN_DM_OD_LO
        #define Pusador_DM_OD_HI           PIN_DM_OD_HI
        #define Pusador_DM_STRONG          PIN_DM_STRONG
        #define Pusador_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Pusador_MASK               Pusador__MASK
#define Pusador_SHIFT              Pusador__SHIFT
#define Pusador_WIDTH              1u

/* Interrupt constants */
#if defined(Pusador__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Pusador_SetInterruptMode() function.
     *  @{
     */
        #define Pusador_INTR_NONE      (uint16)(0x0000u)
        #define Pusador_INTR_RISING    (uint16)(0x0001u)
        #define Pusador_INTR_FALLING   (uint16)(0x0002u)
        #define Pusador_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Pusador_INTR_MASK      (0x01u) 
#endif /* (Pusador__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pusador_PS                     (* (reg8 *) Pusador__PS)
/* Data Register */
#define Pusador_DR                     (* (reg8 *) Pusador__DR)
/* Port Number */
#define Pusador_PRT_NUM                (* (reg8 *) Pusador__PRT) 
/* Connect to Analog Globals */                                                  
#define Pusador_AG                     (* (reg8 *) Pusador__AG)                       
/* Analog MUX bux enable */
#define Pusador_AMUX                   (* (reg8 *) Pusador__AMUX) 
/* Bidirectional Enable */                                                        
#define Pusador_BIE                    (* (reg8 *) Pusador__BIE)
/* Bit-mask for Aliased Register Access */
#define Pusador_BIT_MASK               (* (reg8 *) Pusador__BIT_MASK)
/* Bypass Enable */
#define Pusador_BYP                    (* (reg8 *) Pusador__BYP)
/* Port wide control signals */                                                   
#define Pusador_CTL                    (* (reg8 *) Pusador__CTL)
/* Drive Modes */
#define Pusador_DM0                    (* (reg8 *) Pusador__DM0) 
#define Pusador_DM1                    (* (reg8 *) Pusador__DM1)
#define Pusador_DM2                    (* (reg8 *) Pusador__DM2) 
/* Input Buffer Disable Override */
#define Pusador_INP_DIS                (* (reg8 *) Pusador__INP_DIS)
/* LCD Common or Segment Drive */
#define Pusador_LCD_COM_SEG            (* (reg8 *) Pusador__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pusador_LCD_EN                 (* (reg8 *) Pusador__LCD_EN)
/* Slew Rate Control */
#define Pusador_SLW                    (* (reg8 *) Pusador__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pusador_PRTDSI__CAPS_SEL       (* (reg8 *) Pusador__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pusador_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pusador__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pusador_PRTDSI__OE_SEL0        (* (reg8 *) Pusador__PRTDSI__OE_SEL0) 
#define Pusador_PRTDSI__OE_SEL1        (* (reg8 *) Pusador__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pusador_PRTDSI__OUT_SEL0       (* (reg8 *) Pusador__PRTDSI__OUT_SEL0) 
#define Pusador_PRTDSI__OUT_SEL1       (* (reg8 *) Pusador__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pusador_PRTDSI__SYNC_OUT       (* (reg8 *) Pusador__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Pusador__SIO_CFG)
    #define Pusador_SIO_HYST_EN        (* (reg8 *) Pusador__SIO_HYST_EN)
    #define Pusador_SIO_REG_HIFREQ     (* (reg8 *) Pusador__SIO_REG_HIFREQ)
    #define Pusador_SIO_CFG            (* (reg8 *) Pusador__SIO_CFG)
    #define Pusador_SIO_DIFF           (* (reg8 *) Pusador__SIO_DIFF)
#endif /* (Pusador__SIO_CFG) */

/* Interrupt Registers */
#if defined(Pusador__INTSTAT)
    #define Pusador_INTSTAT            (* (reg8 *) Pusador__INTSTAT)
    #define Pusador_SNAP               (* (reg8 *) Pusador__SNAP)
    
	#define Pusador_0_INTTYPE_REG 		(* (reg8 *) Pusador__0__INTTYPE)
#endif /* (Pusador__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pusador_H */


/* [] END OF FILE */
