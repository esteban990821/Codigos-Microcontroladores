/*******************************************************************************
* File Name: DAC2.h  
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

#if !defined(CY_PINS_DAC2_H) /* Pins DAC2_H */
#define CY_PINS_DAC2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DAC2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DAC2__PORT == 15 && ((DAC2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DAC2_Write(uint8 value);
void    DAC2_SetDriveMode(uint8 mode);
uint8   DAC2_ReadDataReg(void);
uint8   DAC2_Read(void);
void    DAC2_SetInterruptMode(uint16 position, uint16 mode);
uint8   DAC2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DAC2_SetDriveMode() function.
     *  @{
     */
        #define DAC2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DAC2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DAC2_DM_RES_UP          PIN_DM_RES_UP
        #define DAC2_DM_RES_DWN         PIN_DM_RES_DWN
        #define DAC2_DM_OD_LO           PIN_DM_OD_LO
        #define DAC2_DM_OD_HI           PIN_DM_OD_HI
        #define DAC2_DM_STRONG          PIN_DM_STRONG
        #define DAC2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DAC2_MASK               DAC2__MASK
#define DAC2_SHIFT              DAC2__SHIFT
#define DAC2_WIDTH              1u

/* Interrupt constants */
#if defined(DAC2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DAC2_SetInterruptMode() function.
     *  @{
     */
        #define DAC2_INTR_NONE      (uint16)(0x0000u)
        #define DAC2_INTR_RISING    (uint16)(0x0001u)
        #define DAC2_INTR_FALLING   (uint16)(0x0002u)
        #define DAC2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DAC2_INTR_MASK      (0x01u) 
#endif /* (DAC2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DAC2_PS                     (* (reg8 *) DAC2__PS)
/* Data Register */
#define DAC2_DR                     (* (reg8 *) DAC2__DR)
/* Port Number */
#define DAC2_PRT_NUM                (* (reg8 *) DAC2__PRT) 
/* Connect to Analog Globals */                                                  
#define DAC2_AG                     (* (reg8 *) DAC2__AG)                       
/* Analog MUX bux enable */
#define DAC2_AMUX                   (* (reg8 *) DAC2__AMUX) 
/* Bidirectional Enable */                                                        
#define DAC2_BIE                    (* (reg8 *) DAC2__BIE)
/* Bit-mask for Aliased Register Access */
#define DAC2_BIT_MASK               (* (reg8 *) DAC2__BIT_MASK)
/* Bypass Enable */
#define DAC2_BYP                    (* (reg8 *) DAC2__BYP)
/* Port wide control signals */                                                   
#define DAC2_CTL                    (* (reg8 *) DAC2__CTL)
/* Drive Modes */
#define DAC2_DM0                    (* (reg8 *) DAC2__DM0) 
#define DAC2_DM1                    (* (reg8 *) DAC2__DM1)
#define DAC2_DM2                    (* (reg8 *) DAC2__DM2) 
/* Input Buffer Disable Override */
#define DAC2_INP_DIS                (* (reg8 *) DAC2__INP_DIS)
/* LCD Common or Segment Drive */
#define DAC2_LCD_COM_SEG            (* (reg8 *) DAC2__LCD_COM_SEG)
/* Enable Segment LCD */
#define DAC2_LCD_EN                 (* (reg8 *) DAC2__LCD_EN)
/* Slew Rate Control */
#define DAC2_SLW                    (* (reg8 *) DAC2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DAC2_PRTDSI__CAPS_SEL       (* (reg8 *) DAC2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DAC2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DAC2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DAC2_PRTDSI__OE_SEL0        (* (reg8 *) DAC2__PRTDSI__OE_SEL0) 
#define DAC2_PRTDSI__OE_SEL1        (* (reg8 *) DAC2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DAC2_PRTDSI__OUT_SEL0       (* (reg8 *) DAC2__PRTDSI__OUT_SEL0) 
#define DAC2_PRTDSI__OUT_SEL1       (* (reg8 *) DAC2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DAC2_PRTDSI__SYNC_OUT       (* (reg8 *) DAC2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DAC2__SIO_CFG)
    #define DAC2_SIO_HYST_EN        (* (reg8 *) DAC2__SIO_HYST_EN)
    #define DAC2_SIO_REG_HIFREQ     (* (reg8 *) DAC2__SIO_REG_HIFREQ)
    #define DAC2_SIO_CFG            (* (reg8 *) DAC2__SIO_CFG)
    #define DAC2_SIO_DIFF           (* (reg8 *) DAC2__SIO_DIFF)
#endif /* (DAC2__SIO_CFG) */

/* Interrupt Registers */
#if defined(DAC2__INTSTAT)
    #define DAC2_INTSTAT            (* (reg8 *) DAC2__INTSTAT)
    #define DAC2_SNAP               (* (reg8 *) DAC2__SNAP)
    
	#define DAC2_0_INTTYPE_REG 		(* (reg8 *) DAC2__0__INTTYPE)
#endif /* (DAC2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DAC2_H */


/* [] END OF FILE */
