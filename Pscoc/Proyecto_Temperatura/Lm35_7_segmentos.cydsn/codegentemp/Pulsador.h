/*******************************************************************************
* File Name: Pulsador.h  
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

#if !defined(CY_PINS_Pulsador_H) /* Pins Pulsador_H */
#define CY_PINS_Pulsador_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pulsador_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pulsador__PORT == 15 && ((Pulsador__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Pulsador_Write(uint8 value);
void    Pulsador_SetDriveMode(uint8 mode);
uint8   Pulsador_ReadDataReg(void);
uint8   Pulsador_Read(void);
void    Pulsador_SetInterruptMode(uint16 position, uint16 mode);
uint8   Pulsador_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Pulsador_SetDriveMode() function.
     *  @{
     */
        #define Pulsador_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Pulsador_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Pulsador_DM_RES_UP          PIN_DM_RES_UP
        #define Pulsador_DM_RES_DWN         PIN_DM_RES_DWN
        #define Pulsador_DM_OD_LO           PIN_DM_OD_LO
        #define Pulsador_DM_OD_HI           PIN_DM_OD_HI
        #define Pulsador_DM_STRONG          PIN_DM_STRONG
        #define Pulsador_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Pulsador_MASK               Pulsador__MASK
#define Pulsador_SHIFT              Pulsador__SHIFT
#define Pulsador_WIDTH              1u

/* Interrupt constants */
#if defined(Pulsador__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Pulsador_SetInterruptMode() function.
     *  @{
     */
        #define Pulsador_INTR_NONE      (uint16)(0x0000u)
        #define Pulsador_INTR_RISING    (uint16)(0x0001u)
        #define Pulsador_INTR_FALLING   (uint16)(0x0002u)
        #define Pulsador_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Pulsador_INTR_MASK      (0x01u) 
#endif /* (Pulsador__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pulsador_PS                     (* (reg8 *) Pulsador__PS)
/* Data Register */
#define Pulsador_DR                     (* (reg8 *) Pulsador__DR)
/* Port Number */
#define Pulsador_PRT_NUM                (* (reg8 *) Pulsador__PRT) 
/* Connect to Analog Globals */                                                  
#define Pulsador_AG                     (* (reg8 *) Pulsador__AG)                       
/* Analog MUX bux enable */
#define Pulsador_AMUX                   (* (reg8 *) Pulsador__AMUX) 
/* Bidirectional Enable */                                                        
#define Pulsador_BIE                    (* (reg8 *) Pulsador__BIE)
/* Bit-mask for Aliased Register Access */
#define Pulsador_BIT_MASK               (* (reg8 *) Pulsador__BIT_MASK)
/* Bypass Enable */
#define Pulsador_BYP                    (* (reg8 *) Pulsador__BYP)
/* Port wide control signals */                                                   
#define Pulsador_CTL                    (* (reg8 *) Pulsador__CTL)
/* Drive Modes */
#define Pulsador_DM0                    (* (reg8 *) Pulsador__DM0) 
#define Pulsador_DM1                    (* (reg8 *) Pulsador__DM1)
#define Pulsador_DM2                    (* (reg8 *) Pulsador__DM2) 
/* Input Buffer Disable Override */
#define Pulsador_INP_DIS                (* (reg8 *) Pulsador__INP_DIS)
/* LCD Common or Segment Drive */
#define Pulsador_LCD_COM_SEG            (* (reg8 *) Pulsador__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pulsador_LCD_EN                 (* (reg8 *) Pulsador__LCD_EN)
/* Slew Rate Control */
#define Pulsador_SLW                    (* (reg8 *) Pulsador__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pulsador_PRTDSI__CAPS_SEL       (* (reg8 *) Pulsador__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pulsador_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pulsador__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pulsador_PRTDSI__OE_SEL0        (* (reg8 *) Pulsador__PRTDSI__OE_SEL0) 
#define Pulsador_PRTDSI__OE_SEL1        (* (reg8 *) Pulsador__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pulsador_PRTDSI__OUT_SEL0       (* (reg8 *) Pulsador__PRTDSI__OUT_SEL0) 
#define Pulsador_PRTDSI__OUT_SEL1       (* (reg8 *) Pulsador__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pulsador_PRTDSI__SYNC_OUT       (* (reg8 *) Pulsador__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Pulsador__SIO_CFG)
    #define Pulsador_SIO_HYST_EN        (* (reg8 *) Pulsador__SIO_HYST_EN)
    #define Pulsador_SIO_REG_HIFREQ     (* (reg8 *) Pulsador__SIO_REG_HIFREQ)
    #define Pulsador_SIO_CFG            (* (reg8 *) Pulsador__SIO_CFG)
    #define Pulsador_SIO_DIFF           (* (reg8 *) Pulsador__SIO_DIFF)
#endif /* (Pulsador__SIO_CFG) */

/* Interrupt Registers */
#if defined(Pulsador__INTSTAT)
    #define Pulsador_INTSTAT            (* (reg8 *) Pulsador__INTSTAT)
    #define Pulsador_SNAP               (* (reg8 *) Pulsador__SNAP)
    
	#define Pulsador_0_INTTYPE_REG 		(* (reg8 *) Pulsador__0__INTTYPE)
#endif /* (Pulsador__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pulsador_H */


/* [] END OF FILE */
