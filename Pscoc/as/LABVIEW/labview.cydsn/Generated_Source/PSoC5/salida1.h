/*******************************************************************************
* File Name: salida1.h  
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

#if !defined(CY_PINS_salida1_H) /* Pins salida1_H */
#define CY_PINS_salida1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "salida1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 salida1__PORT == 15 && ((salida1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    salida1_Write(uint8 value);
void    salida1_SetDriveMode(uint8 mode);
uint8   salida1_ReadDataReg(void);
uint8   salida1_Read(void);
void    salida1_SetInterruptMode(uint16 position, uint16 mode);
uint8   salida1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the salida1_SetDriveMode() function.
     *  @{
     */
        #define salida1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define salida1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define salida1_DM_RES_UP          PIN_DM_RES_UP
        #define salida1_DM_RES_DWN         PIN_DM_RES_DWN
        #define salida1_DM_OD_LO           PIN_DM_OD_LO
        #define salida1_DM_OD_HI           PIN_DM_OD_HI
        #define salida1_DM_STRONG          PIN_DM_STRONG
        #define salida1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define salida1_MASK               salida1__MASK
#define salida1_SHIFT              salida1__SHIFT
#define salida1_WIDTH              1u

/* Interrupt constants */
#if defined(salida1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in salida1_SetInterruptMode() function.
     *  @{
     */
        #define salida1_INTR_NONE      (uint16)(0x0000u)
        #define salida1_INTR_RISING    (uint16)(0x0001u)
        #define salida1_INTR_FALLING   (uint16)(0x0002u)
        #define salida1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define salida1_INTR_MASK      (0x01u) 
#endif /* (salida1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define salida1_PS                     (* (reg8 *) salida1__PS)
/* Data Register */
#define salida1_DR                     (* (reg8 *) salida1__DR)
/* Port Number */
#define salida1_PRT_NUM                (* (reg8 *) salida1__PRT) 
/* Connect to Analog Globals */                                                  
#define salida1_AG                     (* (reg8 *) salida1__AG)                       
/* Analog MUX bux enable */
#define salida1_AMUX                   (* (reg8 *) salida1__AMUX) 
/* Bidirectional Enable */                                                        
#define salida1_BIE                    (* (reg8 *) salida1__BIE)
/* Bit-mask for Aliased Register Access */
#define salida1_BIT_MASK               (* (reg8 *) salida1__BIT_MASK)
/* Bypass Enable */
#define salida1_BYP                    (* (reg8 *) salida1__BYP)
/* Port wide control signals */                                                   
#define salida1_CTL                    (* (reg8 *) salida1__CTL)
/* Drive Modes */
#define salida1_DM0                    (* (reg8 *) salida1__DM0) 
#define salida1_DM1                    (* (reg8 *) salida1__DM1)
#define salida1_DM2                    (* (reg8 *) salida1__DM2) 
/* Input Buffer Disable Override */
#define salida1_INP_DIS                (* (reg8 *) salida1__INP_DIS)
/* LCD Common or Segment Drive */
#define salida1_LCD_COM_SEG            (* (reg8 *) salida1__LCD_COM_SEG)
/* Enable Segment LCD */
#define salida1_LCD_EN                 (* (reg8 *) salida1__LCD_EN)
/* Slew Rate Control */
#define salida1_SLW                    (* (reg8 *) salida1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define salida1_PRTDSI__CAPS_SEL       (* (reg8 *) salida1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define salida1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) salida1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define salida1_PRTDSI__OE_SEL0        (* (reg8 *) salida1__PRTDSI__OE_SEL0) 
#define salida1_PRTDSI__OE_SEL1        (* (reg8 *) salida1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define salida1_PRTDSI__OUT_SEL0       (* (reg8 *) salida1__PRTDSI__OUT_SEL0) 
#define salida1_PRTDSI__OUT_SEL1       (* (reg8 *) salida1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define salida1_PRTDSI__SYNC_OUT       (* (reg8 *) salida1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(salida1__SIO_CFG)
    #define salida1_SIO_HYST_EN        (* (reg8 *) salida1__SIO_HYST_EN)
    #define salida1_SIO_REG_HIFREQ     (* (reg8 *) salida1__SIO_REG_HIFREQ)
    #define salida1_SIO_CFG            (* (reg8 *) salida1__SIO_CFG)
    #define salida1_SIO_DIFF           (* (reg8 *) salida1__SIO_DIFF)
#endif /* (salida1__SIO_CFG) */

/* Interrupt Registers */
#if defined(salida1__INTSTAT)
    #define salida1_INTSTAT            (* (reg8 *) salida1__INTSTAT)
    #define salida1_SNAP               (* (reg8 *) salida1__SNAP)
    
	#define salida1_0_INTTYPE_REG 		(* (reg8 *) salida1__0__INTTYPE)
#endif /* (salida1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_salida1_H */


/* [] END OF FILE */
