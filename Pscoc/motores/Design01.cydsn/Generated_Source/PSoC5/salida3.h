/*******************************************************************************
* File Name: salida3.h  
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

#if !defined(CY_PINS_salida3_H) /* Pins salida3_H */
#define CY_PINS_salida3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "salida3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 salida3__PORT == 15 && ((salida3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    salida3_Write(uint8 value);
void    salida3_SetDriveMode(uint8 mode);
uint8   salida3_ReadDataReg(void);
uint8   salida3_Read(void);
void    salida3_SetInterruptMode(uint16 position, uint16 mode);
uint8   salida3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the salida3_SetDriveMode() function.
     *  @{
     */
        #define salida3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define salida3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define salida3_DM_RES_UP          PIN_DM_RES_UP
        #define salida3_DM_RES_DWN         PIN_DM_RES_DWN
        #define salida3_DM_OD_LO           PIN_DM_OD_LO
        #define salida3_DM_OD_HI           PIN_DM_OD_HI
        #define salida3_DM_STRONG          PIN_DM_STRONG
        #define salida3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define salida3_MASK               salida3__MASK
#define salida3_SHIFT              salida3__SHIFT
#define salida3_WIDTH              1u

/* Interrupt constants */
#if defined(salida3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in salida3_SetInterruptMode() function.
     *  @{
     */
        #define salida3_INTR_NONE      (uint16)(0x0000u)
        #define salida3_INTR_RISING    (uint16)(0x0001u)
        #define salida3_INTR_FALLING   (uint16)(0x0002u)
        #define salida3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define salida3_INTR_MASK      (0x01u) 
#endif /* (salida3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define salida3_PS                     (* (reg8 *) salida3__PS)
/* Data Register */
#define salida3_DR                     (* (reg8 *) salida3__DR)
/* Port Number */
#define salida3_PRT_NUM                (* (reg8 *) salida3__PRT) 
/* Connect to Analog Globals */                                                  
#define salida3_AG                     (* (reg8 *) salida3__AG)                       
/* Analog MUX bux enable */
#define salida3_AMUX                   (* (reg8 *) salida3__AMUX) 
/* Bidirectional Enable */                                                        
#define salida3_BIE                    (* (reg8 *) salida3__BIE)
/* Bit-mask for Aliased Register Access */
#define salida3_BIT_MASK               (* (reg8 *) salida3__BIT_MASK)
/* Bypass Enable */
#define salida3_BYP                    (* (reg8 *) salida3__BYP)
/* Port wide control signals */                                                   
#define salida3_CTL                    (* (reg8 *) salida3__CTL)
/* Drive Modes */
#define salida3_DM0                    (* (reg8 *) salida3__DM0) 
#define salida3_DM1                    (* (reg8 *) salida3__DM1)
#define salida3_DM2                    (* (reg8 *) salida3__DM2) 
/* Input Buffer Disable Override */
#define salida3_INP_DIS                (* (reg8 *) salida3__INP_DIS)
/* LCD Common or Segment Drive */
#define salida3_LCD_COM_SEG            (* (reg8 *) salida3__LCD_COM_SEG)
/* Enable Segment LCD */
#define salida3_LCD_EN                 (* (reg8 *) salida3__LCD_EN)
/* Slew Rate Control */
#define salida3_SLW                    (* (reg8 *) salida3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define salida3_PRTDSI__CAPS_SEL       (* (reg8 *) salida3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define salida3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) salida3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define salida3_PRTDSI__OE_SEL0        (* (reg8 *) salida3__PRTDSI__OE_SEL0) 
#define salida3_PRTDSI__OE_SEL1        (* (reg8 *) salida3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define salida3_PRTDSI__OUT_SEL0       (* (reg8 *) salida3__PRTDSI__OUT_SEL0) 
#define salida3_PRTDSI__OUT_SEL1       (* (reg8 *) salida3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define salida3_PRTDSI__SYNC_OUT       (* (reg8 *) salida3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(salida3__SIO_CFG)
    #define salida3_SIO_HYST_EN        (* (reg8 *) salida3__SIO_HYST_EN)
    #define salida3_SIO_REG_HIFREQ     (* (reg8 *) salida3__SIO_REG_HIFREQ)
    #define salida3_SIO_CFG            (* (reg8 *) salida3__SIO_CFG)
    #define salida3_SIO_DIFF           (* (reg8 *) salida3__SIO_DIFF)
#endif /* (salida3__SIO_CFG) */

/* Interrupt Registers */
#if defined(salida3__INTSTAT)
    #define salida3_INTSTAT            (* (reg8 *) salida3__INTSTAT)
    #define salida3_SNAP               (* (reg8 *) salida3__SNAP)
    
	#define salida3_0_INTTYPE_REG 		(* (reg8 *) salida3__0__INTTYPE)
#endif /* (salida3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_salida3_H */


/* [] END OF FILE */
