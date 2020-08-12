/*******************************************************************************
* File Name: LCD_SegStatic_1.h
* Version 2.30
*
* Description:
*  This header file contains definitions associated with the Static Segment LCD
*  component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_ST_SEG_LCD_LCD_SegStatic_1_H)
#define CY_ST_SEG_LCD_LCD_SegStatic_1_H

#include "cytypes.h"
#include "cydevice_trm.h"
#include "cyfitter.h"
#include <LCD_SegStatic_1_Pins.h>


/***************************************
*   Conditional Compilation Parameters
***************************************/

/* Print error if cy_boot version is below 3.0 */
#ifndef CY_PSOC5LP
    #error Component StaticSegLCD_v2_30 requires cy_boot v3.0 or later
#endif /* CY_PSOC5LP */

#define LCD_SegStatic_1_PORT_SHIFT          (0x04u)
#define LCD_SegStatic_1_ROW_SHIFT           (0x08u)

/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} LCD_SegStatic_1_BACKUP_STRUCT;

/* DMA_PROTO_GROUP_NAME=StSegLcdPort */
struct LCD_SegStatic_1_DMA_TD_PROTO_ENTRY
{
	uint8 offset;	/* offset of the first register in this TD */
	uint8 length;	/* length of the register block in this TD */
};


/***************************************
*        Function Prototypes
***************************************/

void   LCD_SegStatic_1_Init(void) ;
uint8  LCD_SegStatic_1_Enable(void) ;
uint8  LCD_SegStatic_1_Start(void) ;
void   LCD_SegStatic_1_Stop(void) ;
void   LCD_SegStatic_1_EnableInt(void) ;
void   LCD_SegStatic_1_DisableInt(void) ;
void   LCD_SegStatic_1_ClearDisplay(void) ;
uint8  LCD_SegStatic_1_WritePixel(uint16 pixelNumber, uint8 pixelState)
                                                                    ;
uint8  LCD_SegStatic_1_ReadPixel(uint16 pixelNumber) ;
uint8  LCD_SegStatic_1_WriteInvertState(uint8 invertState) ;
uint8  LCD_SegStatic_1_ReadInvertState(void) ;
void   LCD_SegStatic_1_Sleep(void) ;
uint8  LCD_SegStatic_1_Wakeup(void) ;
void   LCD_SegStatic_1_RestoreConfig(void) ;
void   LCD_SegStatic_1_SaveConfig(void) ;


CY_ISR_PROTO(LCD_SegStatic_1_ISR);

#define LCD_SegStatic_1_WRITE_PIXEL(pixelNumber, pixelState)    \
                                                        ((void) LCD_SegStatic_1_WritePixel(pixelNumber, pixelState))
#define LCD_SegStatic_1_READ_PIXEL(pixelNumber)                 (LCD_SegStatic_1_ReadPixel(pixelNumber))
#define LCD_SegStatic_1_FIND_PIXEL(port, pin, row)     \
                                                ((uint16) (((uint16) (((uint16) (row)) << LCD_SegStatic_1_ROW_SHIFT) +\
                                                    (uint16) (((uint16)(port)) << LCD_SegStatic_1_PORT_SHIFT)) + \
                                                       ((uint16)(pin))))


/***************************************
*           Global Variables
***************************************/
extern uint8 LCD_SegStatic_1_enableState;
extern uint8 LCD_SegStatic_1_initVar;


/***************************************
*           API Constants
***************************************/

#if(CY_PSOC5)
    #define LCD_SegStatic_1_DMA_ADDRESS_MASK      (0xFFFFFFFFu)
#else
    #define LCD_SegStatic_1_DMA_ADDRESS_MASK      (0x0000FFFFu)
#endif /* (CYDEV_CHIP_DIE_EXPECT == CYDEV_CHIP_DIE_LEOPARD) */

#define LCD_SegStatic_1_ROW_LENGTH                (0x10u)

/* Number of pixels for different kind of LCDs */
#define LCD_SegStatic_1_7SEG_PIX_NUM              (0x07u)
#define LCD_SegStatic_1_14SEG_PIX_NUM             (0x0Eu)
#define LCD_SegStatic_1_16SEG_PIX_NUM             (0x10u)

/* Actually there is only one common line but we need to
* invert the signal on the common line for proper waveform generation.
*/
#define LCD_SegStatic_1_COMM_NUM                  (0x02u)

#define LCD_SegStatic_1_BIT_MASK                  (0x0007u)
#define LCD_SegStatic_1_PORT_MASK                 (0x00F0u)
#define LCD_SegStatic_1_ROW_MASK                  (0x0F00u)

#define LCD_SegStatic_1_NORMAL_STATE              (0x00u)
#define LCD_SegStatic_1_INVERTED_STATE            (0x01u)
#define LCD_SegStatic_1_STATE_MASK                (0x01u)

#define LCD_SegStatic_1_PIXEL_STATE_OFF           (0x00u)
#define LCD_SegStatic_1_PIXEL_STATE_ON            (0x01u)
#define LCD_SegStatic_1_PIXEL_STATE_INVERT        (0x02u)
#define LCD_SegStatic_1_PIXEL_UNKNOWN_STATE       (0xFFu)

#define LCD_SegStatic_1_TD_SIZE                   (0x10u)
#define LCD_SegStatic_1_BUFFER_LENGTH             (32u)

/* 0 - No leadig zeros, 1 - leadig zeros */
#define LCD_SegStatic_1_MODE_0                    (0x00u)
#define LCD_SegStatic_1_MODE_1                    (0x01u)

#define LCD_SegStatic_1_ROW_BYTE_LENGTH           (0x10u)

#define LCD_SegStatic_1_MAX_PORTS                 (0x10u)

#define LCD_SegStatic_1_ISR_NUMBER                (LCD_SegStatic_1_LCD_ISR__INTC_NUMBER)
#define LCD_SegStatic_1_ISR_PRIORITY              (LCD_SegStatic_1_LCD_ISR__INTC_PRIOR_NUM)

/* Defines index of "blank" digit in the look-up table for 7 segment helper */
#define LCD_SegStatic_1_7SEG_BLANK_DIG            (0x10u)


#define LCD_SegStatic_1_COM0_PORT                LCD_SegStatic_1_Com__LCD_COM_PORT__0
#define LCD_SegStatic_1_COM0_PIN                LCD_SegStatic_1_Com__LCD_COM_PIN__0

#define LCD_SegStatic_1_Com0                LCD_SegStatic_1_FIND_PIXEL(LCD_SegStatic_1_COM0_PORT,  LCD_SegStatic_1_COM0_PIN,  0u)

#define LCD_SegStatic_1_SEG0_PORT                LCD_SegStatic_1_Seg__LCD_SEG_PORT__0
#define LCD_SegStatic_1_SEG0_PIN                LCD_SegStatic_1_Seg__LCD_SEG_PIN__0
#define LCD_SegStatic_1_SEG1_PORT                LCD_SegStatic_1_Seg__LCD_SEG_PORT__1
#define LCD_SegStatic_1_SEG1_PIN                LCD_SegStatic_1_Seg__LCD_SEG_PIN__1
#define LCD_SegStatic_1_SEG2_PORT                LCD_SegStatic_1_Seg__LCD_SEG_PORT__2
#define LCD_SegStatic_1_SEG2_PIN                LCD_SegStatic_1_Seg__LCD_SEG_PIN__2
#define LCD_SegStatic_1_SEG3_PORT                LCD_SegStatic_1_Seg__LCD_SEG_PORT__3
#define LCD_SegStatic_1_SEG3_PIN                LCD_SegStatic_1_Seg__LCD_SEG_PIN__3


#define LCD_SegStatic_1_PIX0                LCD_SegStatic_1_FIND_PIXEL(LCD_SegStatic_1_SEG0_PORT,  LCD_SegStatic_1_SEG0_PIN,  0u)
#define LCD_SegStatic_1_PIX1                LCD_SegStatic_1_FIND_PIXEL(LCD_SegStatic_1_SEG1_PORT,  LCD_SegStatic_1_SEG1_PIN,  0u)
#define LCD_SegStatic_1_PIX2                LCD_SegStatic_1_FIND_PIXEL(LCD_SegStatic_1_SEG2_PORT,  LCD_SegStatic_1_SEG2_PIN,  0u)
#define LCD_SegStatic_1_PIX3                LCD_SegStatic_1_FIND_PIXEL(LCD_SegStatic_1_SEG3_PORT,  LCD_SegStatic_1_SEG3_PIN,  0u)
#define LCD_SegStatic_1_PIX4                LCD_SegStatic_1_FIND_PIXEL(LCD_SegStatic_1_SEG4_PORT,  LCD_SegStatic_1_SEG4_PIN,  0u)
#define LCD_SegStatic_1_PIX5                LCD_SegStatic_1_FIND_PIXEL(LCD_SegStatic_1_SEG5_PORT,  LCD_SegStatic_1_SEG5_PIN,  0u)
#define LCD_SegStatic_1_PIX6                LCD_SegStatic_1_FIND_PIXEL(LCD_SegStatic_1_SEG6_PORT,  LCD_SegStatic_1_SEG6_PIN,  0u)
#define LCD_SegStatic_1_PIX7                LCD_SegStatic_1_FIND_PIXEL(LCD_SegStatic_1_SEG7_PORT,  LCD_SegStatic_1_SEG7_PIN,  0u)

#define LCD_SegStatic_1_NOT_CON            ((uint8) (0xFFu))

/*
* Following definitions of the global variables are
* obsolete and which will be removed in the near future.
*/
#define PIX0                LCD_SegStatic_1_PIX0
#define PIX1                LCD_SegStatic_1_PIX1
#define PIX2                LCD_SegStatic_1_PIX2
#define PIX3                LCD_SegStatic_1_PIX3
#define PIX4                LCD_SegStatic_1_PIX4
#define PIX5                LCD_SegStatic_1_PIX5
#define PIX6                LCD_SegStatic_1_PIX6
#define PIX7                LCD_SegStatic_1_PIX7

#define LCD_SegStatic_1_StSegLcdPort_DMA_TD_PROTO_COUNT 1


#define LCD_SegStatic_1_LCD_TD_SIZE               ((uint8) LCD_SegStatic_1_StSegLcdPort_DMA_TD_PROTO_COUNT)


/***************************************
*             Registers
***************************************/

#define LCD_SegStatic_1_ALIASED_AREA_PTR                        ((reg32) CYDEV_IO_DR_PRT0_DR_ALIAS)
#define LCD_SegStatic_1_PORT_BASE_PTR                           ((reg8 *) CYDEV_IO_PRT_PRT0_BASE)

#endif /* CY_ST_SEG_LCD_LCD_SegStatic_1_H */


/* [] END OF FILE */
