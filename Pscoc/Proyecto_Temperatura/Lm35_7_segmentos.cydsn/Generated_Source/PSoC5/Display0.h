/*******************************************************************************
* File Name: Display0.h
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

#if !defined(CY_ST_SEG_LCD_Display0_H)
#define CY_ST_SEG_LCD_Display0_H

#include "cytypes.h"
#include "cydevice_trm.h"
#include "cyfitter.h"
#include <Display0_Pins.h>


/***************************************
*   Conditional Compilation Parameters
***************************************/

/* Print error if cy_boot version is below 3.0 */
#ifndef CY_PSOC5LP
    #error Component StaticSegLCD_v2_30 requires cy_boot v3.0 or later
#endif /* CY_PSOC5LP */

#define Display0_PORT_SHIFT          (0x04u)
#define Display0_ROW_SHIFT           (0x08u)

/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} Display0_BACKUP_STRUCT;

/* DMA_PROTO_GROUP_NAME=StSegLcdPort */
struct Display0_DMA_TD_PROTO_ENTRY
{
	uint8 offset;	/* offset of the first register in this TD */
	uint8 length;	/* length of the register block in this TD */
};


/***************************************
*        Function Prototypes
***************************************/

void   Display0_Init(void) ;
uint8  Display0_Enable(void) ;
uint8  Display0_Start(void) ;
void   Display0_Stop(void) ;
void   Display0_EnableInt(void) ;
void   Display0_DisableInt(void) ;
void   Display0_ClearDisplay(void) ;
uint8  Display0_WritePixel(uint16 pixelNumber, uint8 pixelState)
                                                                    ;
uint8  Display0_ReadPixel(uint16 pixelNumber) ;
uint8  Display0_WriteInvertState(uint8 invertState) ;
uint8  Display0_ReadInvertState(void) ;
void   Display0_Sleep(void) ;
uint8  Display0_Wakeup(void) ;
void   Display0_RestoreConfig(void) ;
void   Display0_SaveConfig(void) ;


CY_ISR_PROTO(Display0_ISR);

#define Display0_WRITE_PIXEL(pixelNumber, pixelState)    \
                                                        ((void) Display0_WritePixel(pixelNumber, pixelState))
#define Display0_READ_PIXEL(pixelNumber)                 (Display0_ReadPixel(pixelNumber))
#define Display0_FIND_PIXEL(port, pin, row)     \
                                                ((uint16) (((uint16) (((uint16) (row)) << Display0_ROW_SHIFT) +\
                                                    (uint16) (((uint16)(port)) << Display0_PORT_SHIFT)) + \
                                                       ((uint16)(pin))))


/***************************************
*           Global Variables
***************************************/
extern uint8 Display0_enableState;
extern uint8 Display0_initVar;


/***************************************
*           API Constants
***************************************/

#if(CY_PSOC5)
    #define Display0_DMA_ADDRESS_MASK      (0xFFFFFFFFu)
#else
    #define Display0_DMA_ADDRESS_MASK      (0x0000FFFFu)
#endif /* (CYDEV_CHIP_DIE_EXPECT == CYDEV_CHIP_DIE_LEOPARD) */

#define Display0_ROW_LENGTH                (0x10u)

/* Number of pixels for different kind of LCDs */
#define Display0_7SEG_PIX_NUM              (0x07u)
#define Display0_14SEG_PIX_NUM             (0x0Eu)
#define Display0_16SEG_PIX_NUM             (0x10u)

/* Actually there is only one common line but we need to
* invert the signal on the common line for proper waveform generation.
*/
#define Display0_COMM_NUM                  (0x02u)

#define Display0_BIT_MASK                  (0x0007u)
#define Display0_PORT_MASK                 (0x00F0u)
#define Display0_ROW_MASK                  (0x0F00u)

#define Display0_NORMAL_STATE              (0x00u)
#define Display0_INVERTED_STATE            (0x01u)
#define Display0_STATE_MASK                (0x01u)

#define Display0_PIXEL_STATE_OFF           (0x00u)
#define Display0_PIXEL_STATE_ON            (0x01u)
#define Display0_PIXEL_STATE_INVERT        (0x02u)
#define Display0_PIXEL_UNKNOWN_STATE       (0xFFu)

#define Display0_TD_SIZE                   (0x10u)
#define Display0_BUFFER_LENGTH             (32u)

/* 0 - No leadig zeros, 1 - leadig zeros */
#define Display0_MODE_0                    (0x00u)
#define Display0_MODE_1                    (0x01u)

#define Display0_ROW_BYTE_LENGTH           (0x10u)

#define Display0_MAX_PORTS                 (0x10u)

#define Display0_ISR_NUMBER                (Display0_LCD_ISR__INTC_NUMBER)
#define Display0_ISR_PRIORITY              (Display0_LCD_ISR__INTC_PRIOR_NUM)

/* Defines index of "blank" digit in the look-up table for 7 segment helper */
#define Display0_7SEG_BLANK_DIG            (0x10u)


#define Display0_COM0_PORT                Display0_Com__LCD_COM_PORT__0
#define Display0_COM0_PIN                Display0_Com__LCD_COM_PIN__0

#define Display0_Com0                Display0_FIND_PIXEL(Display0_COM0_PORT,  Display0_COM0_PIN,  0u)

#define Display0_SEG0_PORT                Display0_Seg__LCD_SEG_PORT__0
#define Display0_SEG0_PIN                Display0_Seg__LCD_SEG_PIN__0
#define Display0_SEG1_PORT                Display0_Seg__LCD_SEG_PORT__1
#define Display0_SEG1_PIN                Display0_Seg__LCD_SEG_PIN__1
#define Display0_SEG2_PORT                Display0_Seg__LCD_SEG_PORT__2
#define Display0_SEG2_PIN                Display0_Seg__LCD_SEG_PIN__2
#define Display0_SEG3_PORT                Display0_Seg__LCD_SEG_PORT__3
#define Display0_SEG3_PIN                Display0_Seg__LCD_SEG_PIN__3


#define Display0_PIX0                Display0_FIND_PIXEL(Display0_SEG0_PORT,  Display0_SEG0_PIN,  0u)
#define Display0_PIX1                Display0_FIND_PIXEL(Display0_SEG1_PORT,  Display0_SEG1_PIN,  0u)
#define Display0_PIX2                Display0_FIND_PIXEL(Display0_SEG2_PORT,  Display0_SEG2_PIN,  0u)
#define Display0_PIX3                Display0_FIND_PIXEL(Display0_SEG3_PORT,  Display0_SEG3_PIN,  0u)

#define Display0_NOT_CON            ((uint8) (0xFFu))

/*
* Following definitions of the global variables are
* obsolete and which will be removed in the near future.
*/
#define PIX0                Display0_PIX0
#define PIX1                Display0_PIX1
#define PIX2                Display0_PIX2
#define PIX3                Display0_PIX3

#define Display0_StSegLcdPort_DMA_TD_PROTO_COUNT 1


#define Display0_LCD_TD_SIZE               ((uint8) Display0_StSegLcdPort_DMA_TD_PROTO_COUNT)


/***************************************
*             Registers
***************************************/

#define Display0_ALIASED_AREA_PTR                        ((reg32) CYDEV_IO_DR_PRT0_DR_ALIAS)
#define Display0_PORT_BASE_PTR                           ((reg8 *) CYDEV_IO_PRT_PRT0_BASE)

#endif /* CY_ST_SEG_LCD_Display0_H */


/* [] END OF FILE */
