/*******************************************************************************
* File Name: SalidaD2.h  
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

#if !defined(CY_PINS_SalidaD2_H) /* Pins SalidaD2_H */
#define CY_PINS_SalidaD2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SalidaD2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SalidaD2__PORT == 15 && ((SalidaD2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SalidaD2_Write(uint8 value);
void    SalidaD2_SetDriveMode(uint8 mode);
uint8   SalidaD2_ReadDataReg(void);
uint8   SalidaD2_Read(void);
void    SalidaD2_SetInterruptMode(uint16 position, uint16 mode);
uint8   SalidaD2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SalidaD2_SetDriveMode() function.
     *  @{
     */
        #define SalidaD2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SalidaD2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SalidaD2_DM_RES_UP          PIN_DM_RES_UP
        #define SalidaD2_DM_RES_DWN         PIN_DM_RES_DWN
        #define SalidaD2_DM_OD_LO           PIN_DM_OD_LO
        #define SalidaD2_DM_OD_HI           PIN_DM_OD_HI
        #define SalidaD2_DM_STRONG          PIN_DM_STRONG
        #define SalidaD2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SalidaD2_MASK               SalidaD2__MASK
#define SalidaD2_SHIFT              SalidaD2__SHIFT
#define SalidaD2_WIDTH              1u

/* Interrupt constants */
#if defined(SalidaD2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SalidaD2_SetInterruptMode() function.
     *  @{
     */
        #define SalidaD2_INTR_NONE      (uint16)(0x0000u)
        #define SalidaD2_INTR_RISING    (uint16)(0x0001u)
        #define SalidaD2_INTR_FALLING   (uint16)(0x0002u)
        #define SalidaD2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SalidaD2_INTR_MASK      (0x01u) 
#endif /* (SalidaD2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SalidaD2_PS                     (* (reg8 *) SalidaD2__PS)
/* Data Register */
#define SalidaD2_DR                     (* (reg8 *) SalidaD2__DR)
/* Port Number */
#define SalidaD2_PRT_NUM                (* (reg8 *) SalidaD2__PRT) 
/* Connect to Analog Globals */                                                  
#define SalidaD2_AG                     (* (reg8 *) SalidaD2__AG)                       
/* Analog MUX bux enable */
#define SalidaD2_AMUX                   (* (reg8 *) SalidaD2__AMUX) 
/* Bidirectional Enable */                                                        
#define SalidaD2_BIE                    (* (reg8 *) SalidaD2__BIE)
/* Bit-mask for Aliased Register Access */
#define SalidaD2_BIT_MASK               (* (reg8 *) SalidaD2__BIT_MASK)
/* Bypass Enable */
#define SalidaD2_BYP                    (* (reg8 *) SalidaD2__BYP)
/* Port wide control signals */                                                   
#define SalidaD2_CTL                    (* (reg8 *) SalidaD2__CTL)
/* Drive Modes */
#define SalidaD2_DM0                    (* (reg8 *) SalidaD2__DM0) 
#define SalidaD2_DM1                    (* (reg8 *) SalidaD2__DM1)
#define SalidaD2_DM2                    (* (reg8 *) SalidaD2__DM2) 
/* Input Buffer Disable Override */
#define SalidaD2_INP_DIS                (* (reg8 *) SalidaD2__INP_DIS)
/* LCD Common or Segment Drive */
#define SalidaD2_LCD_COM_SEG            (* (reg8 *) SalidaD2__LCD_COM_SEG)
/* Enable Segment LCD */
#define SalidaD2_LCD_EN                 (* (reg8 *) SalidaD2__LCD_EN)
/* Slew Rate Control */
#define SalidaD2_SLW                    (* (reg8 *) SalidaD2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SalidaD2_PRTDSI__CAPS_SEL       (* (reg8 *) SalidaD2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SalidaD2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SalidaD2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SalidaD2_PRTDSI__OE_SEL0        (* (reg8 *) SalidaD2__PRTDSI__OE_SEL0) 
#define SalidaD2_PRTDSI__OE_SEL1        (* (reg8 *) SalidaD2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SalidaD2_PRTDSI__OUT_SEL0       (* (reg8 *) SalidaD2__PRTDSI__OUT_SEL0) 
#define SalidaD2_PRTDSI__OUT_SEL1       (* (reg8 *) SalidaD2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SalidaD2_PRTDSI__SYNC_OUT       (* (reg8 *) SalidaD2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SalidaD2__SIO_CFG)
    #define SalidaD2_SIO_HYST_EN        (* (reg8 *) SalidaD2__SIO_HYST_EN)
    #define SalidaD2_SIO_REG_HIFREQ     (* (reg8 *) SalidaD2__SIO_REG_HIFREQ)
    #define SalidaD2_SIO_CFG            (* (reg8 *) SalidaD2__SIO_CFG)
    #define SalidaD2_SIO_DIFF           (* (reg8 *) SalidaD2__SIO_DIFF)
#endif /* (SalidaD2__SIO_CFG) */

/* Interrupt Registers */
#if defined(SalidaD2__INTSTAT)
    #define SalidaD2_INTSTAT            (* (reg8 *) SalidaD2__INTSTAT)
    #define SalidaD2_SNAP               (* (reg8 *) SalidaD2__SNAP)
    
	#define SalidaD2_0_INTTYPE_REG 		(* (reg8 *) SalidaD2__0__INTTYPE)
#endif /* (SalidaD2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SalidaD2_H */


/* [] END OF FILE */
