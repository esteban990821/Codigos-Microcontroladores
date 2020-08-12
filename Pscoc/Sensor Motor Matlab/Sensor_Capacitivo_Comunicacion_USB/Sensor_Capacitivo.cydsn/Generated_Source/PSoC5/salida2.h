/*******************************************************************************
* File Name: salida2.h  
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

#if !defined(CY_PINS_salida2_H) /* Pins salida2_H */
#define CY_PINS_salida2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "salida2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 salida2__PORT == 15 && ((salida2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    salida2_Write(uint8 value);
void    salida2_SetDriveMode(uint8 mode);
uint8   salida2_ReadDataReg(void);
uint8   salida2_Read(void);
void    salida2_SetInterruptMode(uint16 position, uint16 mode);
uint8   salida2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the salida2_SetDriveMode() function.
     *  @{
     */
        #define salida2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define salida2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define salida2_DM_RES_UP          PIN_DM_RES_UP
        #define salida2_DM_RES_DWN         PIN_DM_RES_DWN
        #define salida2_DM_OD_LO           PIN_DM_OD_LO
        #define salida2_DM_OD_HI           PIN_DM_OD_HI
        #define salida2_DM_STRONG          PIN_DM_STRONG
        #define salida2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define salida2_MASK               salida2__MASK
#define salida2_SHIFT              salida2__SHIFT
#define salida2_WIDTH              1u

/* Interrupt constants */
#if defined(salida2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in salida2_SetInterruptMode() function.
     *  @{
     */
        #define salida2_INTR_NONE      (uint16)(0x0000u)
        #define salida2_INTR_RISING    (uint16)(0x0001u)
        #define salida2_INTR_FALLING   (uint16)(0x0002u)
        #define salida2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define salida2_INTR_MASK      (0x01u) 
#endif /* (salida2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define salida2_PS                     (* (reg8 *) salida2__PS)
/* Data Register */
#define salida2_DR                     (* (reg8 *) salida2__DR)
/* Port Number */
#define salida2_PRT_NUM                (* (reg8 *) salida2__PRT) 
/* Connect to Analog Globals */                                                  
#define salida2_AG                     (* (reg8 *) salida2__AG)                       
/* Analog MUX bux enable */
#define salida2_AMUX                   (* (reg8 *) salida2__AMUX) 
/* Bidirectional Enable */                                                        
#define salida2_BIE                    (* (reg8 *) salida2__BIE)
/* Bit-mask for Aliased Register Access */
#define salida2_BIT_MASK               (* (reg8 *) salida2__BIT_MASK)
/* Bypass Enable */
#define salida2_BYP                    (* (reg8 *) salida2__BYP)
/* Port wide control signals */                                                   
#define salida2_CTL                    (* (reg8 *) salida2__CTL)
/* Drive Modes */
#define salida2_DM0                    (* (reg8 *) salida2__DM0) 
#define salida2_DM1                    (* (reg8 *) salida2__DM1)
#define salida2_DM2                    (* (reg8 *) salida2__DM2) 
/* Input Buffer Disable Override */
#define salida2_INP_DIS                (* (reg8 *) salida2__INP_DIS)
/* LCD Common or Segment Drive */
#define salida2_LCD_COM_SEG            (* (reg8 *) salida2__LCD_COM_SEG)
/* Enable Segment LCD */
#define salida2_LCD_EN                 (* (reg8 *) salida2__LCD_EN)
/* Slew Rate Control */
#define salida2_SLW                    (* (reg8 *) salida2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define salida2_PRTDSI__CAPS_SEL       (* (reg8 *) salida2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define salida2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) salida2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define salida2_PRTDSI__OE_SEL0        (* (reg8 *) salida2__PRTDSI__OE_SEL0) 
#define salida2_PRTDSI__OE_SEL1        (* (reg8 *) salida2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define salida2_PRTDSI__OUT_SEL0       (* (reg8 *) salida2__PRTDSI__OUT_SEL0) 
#define salida2_PRTDSI__OUT_SEL1       (* (reg8 *) salida2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define salida2_PRTDSI__SYNC_OUT       (* (reg8 *) salida2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(salida2__SIO_CFG)
    #define salida2_SIO_HYST_EN        (* (reg8 *) salida2__SIO_HYST_EN)
    #define salida2_SIO_REG_HIFREQ     (* (reg8 *) salida2__SIO_REG_HIFREQ)
    #define salida2_SIO_CFG            (* (reg8 *) salida2__SIO_CFG)
    #define salida2_SIO_DIFF           (* (reg8 *) salida2__SIO_DIFF)
#endif /* (salida2__SIO_CFG) */

/* Interrupt Registers */
#if defined(salida2__INTSTAT)
    #define salida2_INTSTAT            (* (reg8 *) salida2__INTSTAT)
    #define salida2_SNAP               (* (reg8 *) salida2__SNAP)
    
	#define salida2_0_INTTYPE_REG 		(* (reg8 *) salida2__0__INTTYPE)
#endif /* (salida2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_salida2_H */


/* [] END OF FILE */
