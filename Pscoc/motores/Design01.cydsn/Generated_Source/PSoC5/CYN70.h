/*******************************************************************************
* File Name: CYN70.h  
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

#if !defined(CY_PINS_CYN70_H) /* Pins CYN70_H */
#define CY_PINS_CYN70_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CYN70_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CYN70__PORT == 15 && ((CYN70__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CYN70_Write(uint8 value);
void    CYN70_SetDriveMode(uint8 mode);
uint8   CYN70_ReadDataReg(void);
uint8   CYN70_Read(void);
void    CYN70_SetInterruptMode(uint16 position, uint16 mode);
uint8   CYN70_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CYN70_SetDriveMode() function.
     *  @{
     */
        #define CYN70_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CYN70_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CYN70_DM_RES_UP          PIN_DM_RES_UP
        #define CYN70_DM_RES_DWN         PIN_DM_RES_DWN
        #define CYN70_DM_OD_LO           PIN_DM_OD_LO
        #define CYN70_DM_OD_HI           PIN_DM_OD_HI
        #define CYN70_DM_STRONG          PIN_DM_STRONG
        #define CYN70_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CYN70_MASK               CYN70__MASK
#define CYN70_SHIFT              CYN70__SHIFT
#define CYN70_WIDTH              1u

/* Interrupt constants */
#if defined(CYN70__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CYN70_SetInterruptMode() function.
     *  @{
     */
        #define CYN70_INTR_NONE      (uint16)(0x0000u)
        #define CYN70_INTR_RISING    (uint16)(0x0001u)
        #define CYN70_INTR_FALLING   (uint16)(0x0002u)
        #define CYN70_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CYN70_INTR_MASK      (0x01u) 
#endif /* (CYN70__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CYN70_PS                     (* (reg8 *) CYN70__PS)
/* Data Register */
#define CYN70_DR                     (* (reg8 *) CYN70__DR)
/* Port Number */
#define CYN70_PRT_NUM                (* (reg8 *) CYN70__PRT) 
/* Connect to Analog Globals */                                                  
#define CYN70_AG                     (* (reg8 *) CYN70__AG)                       
/* Analog MUX bux enable */
#define CYN70_AMUX                   (* (reg8 *) CYN70__AMUX) 
/* Bidirectional Enable */                                                        
#define CYN70_BIE                    (* (reg8 *) CYN70__BIE)
/* Bit-mask for Aliased Register Access */
#define CYN70_BIT_MASK               (* (reg8 *) CYN70__BIT_MASK)
/* Bypass Enable */
#define CYN70_BYP                    (* (reg8 *) CYN70__BYP)
/* Port wide control signals */                                                   
#define CYN70_CTL                    (* (reg8 *) CYN70__CTL)
/* Drive Modes */
#define CYN70_DM0                    (* (reg8 *) CYN70__DM0) 
#define CYN70_DM1                    (* (reg8 *) CYN70__DM1)
#define CYN70_DM2                    (* (reg8 *) CYN70__DM2) 
/* Input Buffer Disable Override */
#define CYN70_INP_DIS                (* (reg8 *) CYN70__INP_DIS)
/* LCD Common or Segment Drive */
#define CYN70_LCD_COM_SEG            (* (reg8 *) CYN70__LCD_COM_SEG)
/* Enable Segment LCD */
#define CYN70_LCD_EN                 (* (reg8 *) CYN70__LCD_EN)
/* Slew Rate Control */
#define CYN70_SLW                    (* (reg8 *) CYN70__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CYN70_PRTDSI__CAPS_SEL       (* (reg8 *) CYN70__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CYN70_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CYN70__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CYN70_PRTDSI__OE_SEL0        (* (reg8 *) CYN70__PRTDSI__OE_SEL0) 
#define CYN70_PRTDSI__OE_SEL1        (* (reg8 *) CYN70__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CYN70_PRTDSI__OUT_SEL0       (* (reg8 *) CYN70__PRTDSI__OUT_SEL0) 
#define CYN70_PRTDSI__OUT_SEL1       (* (reg8 *) CYN70__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CYN70_PRTDSI__SYNC_OUT       (* (reg8 *) CYN70__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CYN70__SIO_CFG)
    #define CYN70_SIO_HYST_EN        (* (reg8 *) CYN70__SIO_HYST_EN)
    #define CYN70_SIO_REG_HIFREQ     (* (reg8 *) CYN70__SIO_REG_HIFREQ)
    #define CYN70_SIO_CFG            (* (reg8 *) CYN70__SIO_CFG)
    #define CYN70_SIO_DIFF           (* (reg8 *) CYN70__SIO_DIFF)
#endif /* (CYN70__SIO_CFG) */

/* Interrupt Registers */
#if defined(CYN70__INTSTAT)
    #define CYN70_INTSTAT            (* (reg8 *) CYN70__INTSTAT)
    #define CYN70_SNAP               (* (reg8 *) CYN70__SNAP)
    
	#define CYN70_0_INTTYPE_REG 		(* (reg8 *) CYN70__0__INTTYPE)
#endif /* (CYN70__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CYN70_H */


/* [] END OF FILE */
