/*******************************************************************************
* File Name: SalidaD0.h  
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

#if !defined(CY_PINS_SalidaD0_H) /* Pins SalidaD0_H */
#define CY_PINS_SalidaD0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SalidaD0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SalidaD0__PORT == 15 && ((SalidaD0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SalidaD0_Write(uint8 value);
void    SalidaD0_SetDriveMode(uint8 mode);
uint8   SalidaD0_ReadDataReg(void);
uint8   SalidaD0_Read(void);
void    SalidaD0_SetInterruptMode(uint16 position, uint16 mode);
uint8   SalidaD0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SalidaD0_SetDriveMode() function.
     *  @{
     */
        #define SalidaD0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SalidaD0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SalidaD0_DM_RES_UP          PIN_DM_RES_UP
        #define SalidaD0_DM_RES_DWN         PIN_DM_RES_DWN
        #define SalidaD0_DM_OD_LO           PIN_DM_OD_LO
        #define SalidaD0_DM_OD_HI           PIN_DM_OD_HI
        #define SalidaD0_DM_STRONG          PIN_DM_STRONG
        #define SalidaD0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SalidaD0_MASK               SalidaD0__MASK
#define SalidaD0_SHIFT              SalidaD0__SHIFT
#define SalidaD0_WIDTH              1u

/* Interrupt constants */
#if defined(SalidaD0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SalidaD0_SetInterruptMode() function.
     *  @{
     */
        #define SalidaD0_INTR_NONE      (uint16)(0x0000u)
        #define SalidaD0_INTR_RISING    (uint16)(0x0001u)
        #define SalidaD0_INTR_FALLING   (uint16)(0x0002u)
        #define SalidaD0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SalidaD0_INTR_MASK      (0x01u) 
#endif /* (SalidaD0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SalidaD0_PS                     (* (reg8 *) SalidaD0__PS)
/* Data Register */
#define SalidaD0_DR                     (* (reg8 *) SalidaD0__DR)
/* Port Number */
#define SalidaD0_PRT_NUM                (* (reg8 *) SalidaD0__PRT) 
/* Connect to Analog Globals */                                                  
#define SalidaD0_AG                     (* (reg8 *) SalidaD0__AG)                       
/* Analog MUX bux enable */
#define SalidaD0_AMUX                   (* (reg8 *) SalidaD0__AMUX) 
/* Bidirectional Enable */                                                        
#define SalidaD0_BIE                    (* (reg8 *) SalidaD0__BIE)
/* Bit-mask for Aliased Register Access */
#define SalidaD0_BIT_MASK               (* (reg8 *) SalidaD0__BIT_MASK)
/* Bypass Enable */
#define SalidaD0_BYP                    (* (reg8 *) SalidaD0__BYP)
/* Port wide control signals */                                                   
#define SalidaD0_CTL                    (* (reg8 *) SalidaD0__CTL)
/* Drive Modes */
#define SalidaD0_DM0                    (* (reg8 *) SalidaD0__DM0) 
#define SalidaD0_DM1                    (* (reg8 *) SalidaD0__DM1)
#define SalidaD0_DM2                    (* (reg8 *) SalidaD0__DM2) 
/* Input Buffer Disable Override */
#define SalidaD0_INP_DIS                (* (reg8 *) SalidaD0__INP_DIS)
/* LCD Common or Segment Drive */
#define SalidaD0_LCD_COM_SEG            (* (reg8 *) SalidaD0__LCD_COM_SEG)
/* Enable Segment LCD */
#define SalidaD0_LCD_EN                 (* (reg8 *) SalidaD0__LCD_EN)
/* Slew Rate Control */
#define SalidaD0_SLW                    (* (reg8 *) SalidaD0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SalidaD0_PRTDSI__CAPS_SEL       (* (reg8 *) SalidaD0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SalidaD0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SalidaD0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SalidaD0_PRTDSI__OE_SEL0        (* (reg8 *) SalidaD0__PRTDSI__OE_SEL0) 
#define SalidaD0_PRTDSI__OE_SEL1        (* (reg8 *) SalidaD0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SalidaD0_PRTDSI__OUT_SEL0       (* (reg8 *) SalidaD0__PRTDSI__OUT_SEL0) 
#define SalidaD0_PRTDSI__OUT_SEL1       (* (reg8 *) SalidaD0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SalidaD0_PRTDSI__SYNC_OUT       (* (reg8 *) SalidaD0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SalidaD0__SIO_CFG)
    #define SalidaD0_SIO_HYST_EN        (* (reg8 *) SalidaD0__SIO_HYST_EN)
    #define SalidaD0_SIO_REG_HIFREQ     (* (reg8 *) SalidaD0__SIO_REG_HIFREQ)
    #define SalidaD0_SIO_CFG            (* (reg8 *) SalidaD0__SIO_CFG)
    #define SalidaD0_SIO_DIFF           (* (reg8 *) SalidaD0__SIO_DIFF)
#endif /* (SalidaD0__SIO_CFG) */

/* Interrupt Registers */
#if defined(SalidaD0__INTSTAT)
    #define SalidaD0_INTSTAT            (* (reg8 *) SalidaD0__INTSTAT)
    #define SalidaD0_SNAP               (* (reg8 *) SalidaD0__SNAP)
    
	#define SalidaD0_0_INTTYPE_REG 		(* (reg8 *) SalidaD0__0__INTTYPE)
#endif /* (SalidaD0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SalidaD0_H */


/* [] END OF FILE */
