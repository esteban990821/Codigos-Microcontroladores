/*******************************************************************************
* File Name: Valor.h  
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

#if !defined(CY_PINS_Valor_H) /* Pins Valor_H */
#define CY_PINS_Valor_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Valor_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Valor__PORT == 15 && ((Valor__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Valor_Write(uint8 value);
void    Valor_SetDriveMode(uint8 mode);
uint8   Valor_ReadDataReg(void);
uint8   Valor_Read(void);
void    Valor_SetInterruptMode(uint16 position, uint16 mode);
uint8   Valor_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Valor_SetDriveMode() function.
     *  @{
     */
        #define Valor_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Valor_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Valor_DM_RES_UP          PIN_DM_RES_UP
        #define Valor_DM_RES_DWN         PIN_DM_RES_DWN
        #define Valor_DM_OD_LO           PIN_DM_OD_LO
        #define Valor_DM_OD_HI           PIN_DM_OD_HI
        #define Valor_DM_STRONG          PIN_DM_STRONG
        #define Valor_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Valor_MASK               Valor__MASK
#define Valor_SHIFT              Valor__SHIFT
#define Valor_WIDTH              1u

/* Interrupt constants */
#if defined(Valor__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Valor_SetInterruptMode() function.
     *  @{
     */
        #define Valor_INTR_NONE      (uint16)(0x0000u)
        #define Valor_INTR_RISING    (uint16)(0x0001u)
        #define Valor_INTR_FALLING   (uint16)(0x0002u)
        #define Valor_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Valor_INTR_MASK      (0x01u) 
#endif /* (Valor__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Valor_PS                     (* (reg8 *) Valor__PS)
/* Data Register */
#define Valor_DR                     (* (reg8 *) Valor__DR)
/* Port Number */
#define Valor_PRT_NUM                (* (reg8 *) Valor__PRT) 
/* Connect to Analog Globals */                                                  
#define Valor_AG                     (* (reg8 *) Valor__AG)                       
/* Analog MUX bux enable */
#define Valor_AMUX                   (* (reg8 *) Valor__AMUX) 
/* Bidirectional Enable */                                                        
#define Valor_BIE                    (* (reg8 *) Valor__BIE)
/* Bit-mask for Aliased Register Access */
#define Valor_BIT_MASK               (* (reg8 *) Valor__BIT_MASK)
/* Bypass Enable */
#define Valor_BYP                    (* (reg8 *) Valor__BYP)
/* Port wide control signals */                                                   
#define Valor_CTL                    (* (reg8 *) Valor__CTL)
/* Drive Modes */
#define Valor_DM0                    (* (reg8 *) Valor__DM0) 
#define Valor_DM1                    (* (reg8 *) Valor__DM1)
#define Valor_DM2                    (* (reg8 *) Valor__DM2) 
/* Input Buffer Disable Override */
#define Valor_INP_DIS                (* (reg8 *) Valor__INP_DIS)
/* LCD Common or Segment Drive */
#define Valor_LCD_COM_SEG            (* (reg8 *) Valor__LCD_COM_SEG)
/* Enable Segment LCD */
#define Valor_LCD_EN                 (* (reg8 *) Valor__LCD_EN)
/* Slew Rate Control */
#define Valor_SLW                    (* (reg8 *) Valor__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Valor_PRTDSI__CAPS_SEL       (* (reg8 *) Valor__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Valor_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Valor__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Valor_PRTDSI__OE_SEL0        (* (reg8 *) Valor__PRTDSI__OE_SEL0) 
#define Valor_PRTDSI__OE_SEL1        (* (reg8 *) Valor__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Valor_PRTDSI__OUT_SEL0       (* (reg8 *) Valor__PRTDSI__OUT_SEL0) 
#define Valor_PRTDSI__OUT_SEL1       (* (reg8 *) Valor__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Valor_PRTDSI__SYNC_OUT       (* (reg8 *) Valor__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Valor__SIO_CFG)
    #define Valor_SIO_HYST_EN        (* (reg8 *) Valor__SIO_HYST_EN)
    #define Valor_SIO_REG_HIFREQ     (* (reg8 *) Valor__SIO_REG_HIFREQ)
    #define Valor_SIO_CFG            (* (reg8 *) Valor__SIO_CFG)
    #define Valor_SIO_DIFF           (* (reg8 *) Valor__SIO_DIFF)
#endif /* (Valor__SIO_CFG) */

/* Interrupt Registers */
#if defined(Valor__INTSTAT)
    #define Valor_INTSTAT            (* (reg8 *) Valor__INTSTAT)
    #define Valor_SNAP               (* (reg8 *) Valor__SNAP)
    
	#define Valor_0_INTTYPE_REG 		(* (reg8 *) Valor__0__INTTYPE)
#endif /* (Valor__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Valor_H */


/* [] END OF FILE */
