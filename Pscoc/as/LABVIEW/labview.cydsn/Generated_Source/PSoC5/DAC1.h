/*******************************************************************************
* File Name: DAC1.h  
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

#if !defined(CY_PINS_DAC1_H) /* Pins DAC1_H */
#define CY_PINS_DAC1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DAC1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DAC1__PORT == 15 && ((DAC1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DAC1_Write(uint8 value);
void    DAC1_SetDriveMode(uint8 mode);
uint8   DAC1_ReadDataReg(void);
uint8   DAC1_Read(void);
void    DAC1_SetInterruptMode(uint16 position, uint16 mode);
uint8   DAC1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DAC1_SetDriveMode() function.
     *  @{
     */
        #define DAC1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DAC1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DAC1_DM_RES_UP          PIN_DM_RES_UP
        #define DAC1_DM_RES_DWN         PIN_DM_RES_DWN
        #define DAC1_DM_OD_LO           PIN_DM_OD_LO
        #define DAC1_DM_OD_HI           PIN_DM_OD_HI
        #define DAC1_DM_STRONG          PIN_DM_STRONG
        #define DAC1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DAC1_MASK               DAC1__MASK
#define DAC1_SHIFT              DAC1__SHIFT
#define DAC1_WIDTH              1u

/* Interrupt constants */
#if defined(DAC1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DAC1_SetInterruptMode() function.
     *  @{
     */
        #define DAC1_INTR_NONE      (uint16)(0x0000u)
        #define DAC1_INTR_RISING    (uint16)(0x0001u)
        #define DAC1_INTR_FALLING   (uint16)(0x0002u)
        #define DAC1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DAC1_INTR_MASK      (0x01u) 
#endif /* (DAC1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DAC1_PS                     (* (reg8 *) DAC1__PS)
/* Data Register */
#define DAC1_DR                     (* (reg8 *) DAC1__DR)
/* Port Number */
#define DAC1_PRT_NUM                (* (reg8 *) DAC1__PRT) 
/* Connect to Analog Globals */                                                  
#define DAC1_AG                     (* (reg8 *) DAC1__AG)                       
/* Analog MUX bux enable */
#define DAC1_AMUX                   (* (reg8 *) DAC1__AMUX) 
/* Bidirectional Enable */                                                        
#define DAC1_BIE                    (* (reg8 *) DAC1__BIE)
/* Bit-mask for Aliased Register Access */
#define DAC1_BIT_MASK               (* (reg8 *) DAC1__BIT_MASK)
/* Bypass Enable */
#define DAC1_BYP                    (* (reg8 *) DAC1__BYP)
/* Port wide control signals */                                                   
#define DAC1_CTL                    (* (reg8 *) DAC1__CTL)
/* Drive Modes */
#define DAC1_DM0                    (* (reg8 *) DAC1__DM0) 
#define DAC1_DM1                    (* (reg8 *) DAC1__DM1)
#define DAC1_DM2                    (* (reg8 *) DAC1__DM2) 
/* Input Buffer Disable Override */
#define DAC1_INP_DIS                (* (reg8 *) DAC1__INP_DIS)
/* LCD Common or Segment Drive */
#define DAC1_LCD_COM_SEG            (* (reg8 *) DAC1__LCD_COM_SEG)
/* Enable Segment LCD */
#define DAC1_LCD_EN                 (* (reg8 *) DAC1__LCD_EN)
/* Slew Rate Control */
#define DAC1_SLW                    (* (reg8 *) DAC1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DAC1_PRTDSI__CAPS_SEL       (* (reg8 *) DAC1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DAC1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DAC1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DAC1_PRTDSI__OE_SEL0        (* (reg8 *) DAC1__PRTDSI__OE_SEL0) 
#define DAC1_PRTDSI__OE_SEL1        (* (reg8 *) DAC1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DAC1_PRTDSI__OUT_SEL0       (* (reg8 *) DAC1__PRTDSI__OUT_SEL0) 
#define DAC1_PRTDSI__OUT_SEL1       (* (reg8 *) DAC1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DAC1_PRTDSI__SYNC_OUT       (* (reg8 *) DAC1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DAC1__SIO_CFG)
    #define DAC1_SIO_HYST_EN        (* (reg8 *) DAC1__SIO_HYST_EN)
    #define DAC1_SIO_REG_HIFREQ     (* (reg8 *) DAC1__SIO_REG_HIFREQ)
    #define DAC1_SIO_CFG            (* (reg8 *) DAC1__SIO_CFG)
    #define DAC1_SIO_DIFF           (* (reg8 *) DAC1__SIO_DIFF)
#endif /* (DAC1__SIO_CFG) */

/* Interrupt Registers */
#if defined(DAC1__INTSTAT)
    #define DAC1_INTSTAT            (* (reg8 *) DAC1__INTSTAT)
    #define DAC1_SNAP               (* (reg8 *) DAC1__SNAP)
    
	#define DAC1_0_INTTYPE_REG 		(* (reg8 *) DAC1__0__INTTYPE)
#endif /* (DAC1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DAC1_H */


/* [] END OF FILE */
