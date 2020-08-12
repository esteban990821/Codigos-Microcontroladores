/*******************************************************************************
* File Name: vout.h  
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

#if !defined(CY_PINS_vout_H) /* Pins vout_H */
#define CY_PINS_vout_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "vout_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 vout__PORT == 15 && ((vout__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    vout_Write(uint8 value);
void    vout_SetDriveMode(uint8 mode);
uint8   vout_ReadDataReg(void);
uint8   vout_Read(void);
void    vout_SetInterruptMode(uint16 position, uint16 mode);
uint8   vout_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the vout_SetDriveMode() function.
     *  @{
     */
        #define vout_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define vout_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define vout_DM_RES_UP          PIN_DM_RES_UP
        #define vout_DM_RES_DWN         PIN_DM_RES_DWN
        #define vout_DM_OD_LO           PIN_DM_OD_LO
        #define vout_DM_OD_HI           PIN_DM_OD_HI
        #define vout_DM_STRONG          PIN_DM_STRONG
        #define vout_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define vout_MASK               vout__MASK
#define vout_SHIFT              vout__SHIFT
#define vout_WIDTH              1u

/* Interrupt constants */
#if defined(vout__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in vout_SetInterruptMode() function.
     *  @{
     */
        #define vout_INTR_NONE      (uint16)(0x0000u)
        #define vout_INTR_RISING    (uint16)(0x0001u)
        #define vout_INTR_FALLING   (uint16)(0x0002u)
        #define vout_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define vout_INTR_MASK      (0x01u) 
#endif /* (vout__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define vout_PS                     (* (reg8 *) vout__PS)
/* Data Register */
#define vout_DR                     (* (reg8 *) vout__DR)
/* Port Number */
#define vout_PRT_NUM                (* (reg8 *) vout__PRT) 
/* Connect to Analog Globals */                                                  
#define vout_AG                     (* (reg8 *) vout__AG)                       
/* Analog MUX bux enable */
#define vout_AMUX                   (* (reg8 *) vout__AMUX) 
/* Bidirectional Enable */                                                        
#define vout_BIE                    (* (reg8 *) vout__BIE)
/* Bit-mask for Aliased Register Access */
#define vout_BIT_MASK               (* (reg8 *) vout__BIT_MASK)
/* Bypass Enable */
#define vout_BYP                    (* (reg8 *) vout__BYP)
/* Port wide control signals */                                                   
#define vout_CTL                    (* (reg8 *) vout__CTL)
/* Drive Modes */
#define vout_DM0                    (* (reg8 *) vout__DM0) 
#define vout_DM1                    (* (reg8 *) vout__DM1)
#define vout_DM2                    (* (reg8 *) vout__DM2) 
/* Input Buffer Disable Override */
#define vout_INP_DIS                (* (reg8 *) vout__INP_DIS)
/* LCD Common or Segment Drive */
#define vout_LCD_COM_SEG            (* (reg8 *) vout__LCD_COM_SEG)
/* Enable Segment LCD */
#define vout_LCD_EN                 (* (reg8 *) vout__LCD_EN)
/* Slew Rate Control */
#define vout_SLW                    (* (reg8 *) vout__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define vout_PRTDSI__CAPS_SEL       (* (reg8 *) vout__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define vout_PRTDSI__DBL_SYNC_IN    (* (reg8 *) vout__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define vout_PRTDSI__OE_SEL0        (* (reg8 *) vout__PRTDSI__OE_SEL0) 
#define vout_PRTDSI__OE_SEL1        (* (reg8 *) vout__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define vout_PRTDSI__OUT_SEL0       (* (reg8 *) vout__PRTDSI__OUT_SEL0) 
#define vout_PRTDSI__OUT_SEL1       (* (reg8 *) vout__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define vout_PRTDSI__SYNC_OUT       (* (reg8 *) vout__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(vout__SIO_CFG)
    #define vout_SIO_HYST_EN        (* (reg8 *) vout__SIO_HYST_EN)
    #define vout_SIO_REG_HIFREQ     (* (reg8 *) vout__SIO_REG_HIFREQ)
    #define vout_SIO_CFG            (* (reg8 *) vout__SIO_CFG)
    #define vout_SIO_DIFF           (* (reg8 *) vout__SIO_DIFF)
#endif /* (vout__SIO_CFG) */

/* Interrupt Registers */
#if defined(vout__INTSTAT)
    #define vout_INTSTAT            (* (reg8 *) vout__INTSTAT)
    #define vout_SNAP               (* (reg8 *) vout__SNAP)
    
	#define vout_0_INTTYPE_REG 		(* (reg8 *) vout__0__INTTYPE)
#endif /* (vout__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_vout_H */


/* [] END OF FILE */
