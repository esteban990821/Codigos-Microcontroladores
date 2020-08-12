/*******************************************************************************
* File Name: filtro1.h  
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

#if !defined(CY_PINS_filtro1_H) /* Pins filtro1_H */
#define CY_PINS_filtro1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "filtro1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 filtro1__PORT == 15 && ((filtro1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    filtro1_Write(uint8 value);
void    filtro1_SetDriveMode(uint8 mode);
uint8   filtro1_ReadDataReg(void);
uint8   filtro1_Read(void);
void    filtro1_SetInterruptMode(uint16 position, uint16 mode);
uint8   filtro1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the filtro1_SetDriveMode() function.
     *  @{
     */
        #define filtro1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define filtro1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define filtro1_DM_RES_UP          PIN_DM_RES_UP
        #define filtro1_DM_RES_DWN         PIN_DM_RES_DWN
        #define filtro1_DM_OD_LO           PIN_DM_OD_LO
        #define filtro1_DM_OD_HI           PIN_DM_OD_HI
        #define filtro1_DM_STRONG          PIN_DM_STRONG
        #define filtro1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define filtro1_MASK               filtro1__MASK
#define filtro1_SHIFT              filtro1__SHIFT
#define filtro1_WIDTH              1u

/* Interrupt constants */
#if defined(filtro1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in filtro1_SetInterruptMode() function.
     *  @{
     */
        #define filtro1_INTR_NONE      (uint16)(0x0000u)
        #define filtro1_INTR_RISING    (uint16)(0x0001u)
        #define filtro1_INTR_FALLING   (uint16)(0x0002u)
        #define filtro1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define filtro1_INTR_MASK      (0x01u) 
#endif /* (filtro1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define filtro1_PS                     (* (reg8 *) filtro1__PS)
/* Data Register */
#define filtro1_DR                     (* (reg8 *) filtro1__DR)
/* Port Number */
#define filtro1_PRT_NUM                (* (reg8 *) filtro1__PRT) 
/* Connect to Analog Globals */                                                  
#define filtro1_AG                     (* (reg8 *) filtro1__AG)                       
/* Analog MUX bux enable */
#define filtro1_AMUX                   (* (reg8 *) filtro1__AMUX) 
/* Bidirectional Enable */                                                        
#define filtro1_BIE                    (* (reg8 *) filtro1__BIE)
/* Bit-mask for Aliased Register Access */
#define filtro1_BIT_MASK               (* (reg8 *) filtro1__BIT_MASK)
/* Bypass Enable */
#define filtro1_BYP                    (* (reg8 *) filtro1__BYP)
/* Port wide control signals */                                                   
#define filtro1_CTL                    (* (reg8 *) filtro1__CTL)
/* Drive Modes */
#define filtro1_DM0                    (* (reg8 *) filtro1__DM0) 
#define filtro1_DM1                    (* (reg8 *) filtro1__DM1)
#define filtro1_DM2                    (* (reg8 *) filtro1__DM2) 
/* Input Buffer Disable Override */
#define filtro1_INP_DIS                (* (reg8 *) filtro1__INP_DIS)
/* LCD Common or Segment Drive */
#define filtro1_LCD_COM_SEG            (* (reg8 *) filtro1__LCD_COM_SEG)
/* Enable Segment LCD */
#define filtro1_LCD_EN                 (* (reg8 *) filtro1__LCD_EN)
/* Slew Rate Control */
#define filtro1_SLW                    (* (reg8 *) filtro1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define filtro1_PRTDSI__CAPS_SEL       (* (reg8 *) filtro1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define filtro1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) filtro1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define filtro1_PRTDSI__OE_SEL0        (* (reg8 *) filtro1__PRTDSI__OE_SEL0) 
#define filtro1_PRTDSI__OE_SEL1        (* (reg8 *) filtro1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define filtro1_PRTDSI__OUT_SEL0       (* (reg8 *) filtro1__PRTDSI__OUT_SEL0) 
#define filtro1_PRTDSI__OUT_SEL1       (* (reg8 *) filtro1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define filtro1_PRTDSI__SYNC_OUT       (* (reg8 *) filtro1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(filtro1__SIO_CFG)
    #define filtro1_SIO_HYST_EN        (* (reg8 *) filtro1__SIO_HYST_EN)
    #define filtro1_SIO_REG_HIFREQ     (* (reg8 *) filtro1__SIO_REG_HIFREQ)
    #define filtro1_SIO_CFG            (* (reg8 *) filtro1__SIO_CFG)
    #define filtro1_SIO_DIFF           (* (reg8 *) filtro1__SIO_DIFF)
#endif /* (filtro1__SIO_CFG) */

/* Interrupt Registers */
#if defined(filtro1__INTSTAT)
    #define filtro1_INTSTAT            (* (reg8 *) filtro1__INTSTAT)
    #define filtro1_SNAP               (* (reg8 *) filtro1__SNAP)
    
	#define filtro1_0_INTTYPE_REG 		(* (reg8 *) filtro1__0__INTTYPE)
#endif /* (filtro1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_filtro1_H */


/* [] END OF FILE */
