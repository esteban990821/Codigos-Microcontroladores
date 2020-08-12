/*******************************************************************************
* File Name: Display1.h
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

#if !defined(CY_ST_SEG_LCD_Display1_H)
#define CY_ST_SEG_LCD_Display1_H

#include "cytypes.h"
#include "cydevice_trm.h"
#include "cyfitter.h"
#include <Display1_Pins.h>


/***************************************
*   Conditional Compilation Parameters
***************************************/

/* Print error if cy_boot version is below 3.0 */
#ifndef CY_PSOC5LP
    #error Component StaticSegLCD_v2_30 requires cy_boot v3.0 or later
#endif /* CY_PSOC5LP */

#define Display1_PORT_SHIFT          (0x04u)
#define Display1_ROW_SHIFT           (0x08u)

/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} Display1_BACKUP_STRUCT;

/* DMA_PROTO_GROUP_NAME=StSegLcdPort */
struct Display1_DMA_TD_PROTO_ENTRY
{
	uint8 offset;	/* offset of the first register in this TD */
	uint8 length;	/* length of the register block in this TD */
};


/***************************************
*        Function Prototypes
***************************************/

void   Display1_Init(void) ;
uint8  Display1_Enable(void) ;
uint8  Display1_Start(void) ;
void   Display1_Stop(void) ;
void   Display1_EnableInt(void) ;
void   Display1_DisableInt(void) ;
void   Display1_ClearDisplay(void) ;
uint8  Display1_WritePixel(uint16 pixelNumber, uint8 pixelState)
                                                                    ;
uint8  Display1_ReadPixel(uint16 pixelNumber) ;
uint8  Display1_WriteInvertState(uint8 invertState) ;
uint8  Display1_ReadInvertState(void) ;
void   Display1_Sleep(void) ;
uint8  Display1_Wakeup(void) ;
void   Display1_RestoreConfig(void) ;
void   Display1_SaveConfig(void) ;
#define Display1_7SEG
void Display1_Write7SegDigit_0(uint8 digit, uint8 position) ;
void Display1_Write7SegNumber_0(uint16 value, uint8 position, uint8 mode) ;

CY_ISR_PROTO(Display1_ISR);

#define Display1_WRITE_PIXEL(pixelNumber, pixelState)    \
                                                        ((void) Display1_WritePixel(pixelNumber, pixelState))
#define Display1_READ_PIXEL(pixelNumber)                 (Display1_ReadPixel(pixelNumber))
#define Display1_FIND_PIXEL(port, pin, row)     \
                                                ((uint16) (((uint16) (((uint16) (row)) << Display1_ROW_SHIFT) +\
                                                    (uint16) (((uint16)(port)) << Display1_PORT_SHIFT)) + \
                                                       ((uint16)(pin))))


/***************************************
*           Global Variables
***************************************/
extern uint8 Display1_enableState;
extern uint8 Display1_initVar;


/***************************************
*           API Constants
***************************************/

#if(CY_PSOC5)
    #define Display1_DMA_ADDRESS_MASK      (0xFFFFFFFFu)
#else
    #define Display1_DMA_ADDRESS_MASK      (0x0000FFFFu)
#endif /* (CYDEV_CHIP_DIE_EXPECT == CYDEV_CHIP_DIE_LEOPARD) */

#define Display1_ROW_LENGTH                (0x10u)

/* Number of pixels for different kind of LCDs */
#define Display1_7SEG_PIX_NUM              (0x07u)
#define Display1_14SEG_PIX_NUM             (0x0Eu)
#define Display1_16SEG_PIX_NUM             (0x10u)

/* Actually there is only one common line but we need to
* invert the signal on the common line for proper waveform generation.
*/
#define Display1_COMM_NUM                  (0x02u)

#define Display1_BIT_MASK                  (0x0007u)
#define Display1_PORT_MASK                 (0x00F0u)
#define Display1_ROW_MASK                  (0x0F00u)

#define Display1_NORMAL_STATE              (0x00u)
#define Display1_INVERTED_STATE            (0x01u)
#define Display1_STATE_MASK                (0x01u)

#define Display1_PIXEL_STATE_OFF           (0x00u)
#define Display1_PIXEL_STATE_ON            (0x01u)
#define Display1_PIXEL_STATE_INVERT        (0x02u)
#define Display1_PIXEL_UNKNOWN_STATE       (0xFFu)

#define Display1_TD_SIZE                   (0x10u)
#define Display1_BUFFER_LENGTH             (32u)

/* 0 - No leadig zeros, 1 - leadig zeros */
#define Display1_MODE_0                    (0x00u)
#define Display1_MODE_1                    (0x01u)

#define Display1_ROW_BYTE_LENGTH           (0x10u)

#define Display1_MAX_PORTS                 (0x10u)

#define Display1_ISR_NUMBER                (Display1_LCD_ISR__INTC_NUMBER)
#define Display1_ISR_PRIORITY              (Display1_LCD_ISR__INTC_PRIOR_NUM)

/* Defines index of "blank" digit in the look-up table for 7 segment helper */
#define Display1_7SEG_BLANK_DIG            (0x10u)

#define Display1_DIGIT_NUM_0            (2u)

#define Display1_COM0_PORT                Display1_Com__LCD_COM_PORT__0
#define Display1_COM0_PIN                Display1_Com__LCD_COM_PIN__0

#define Display1_Com0                Display1_FIND_PIXEL(Display1_COM0_PORT,  Display1_COM0_PIN,  0u)

#define Display1_SEG0_PORT                Display1_Seg__LCD_SEG_PORT__0
#define Display1_SEG0_PIN                Display1_Seg__LCD_SEG_PIN__0
#define Display1_SEG1_PORT                Display1_Seg__LCD_SEG_PORT__1
#define Display1_SEG1_PIN                Display1_Seg__LCD_SEG_PIN__1
#define Display1_SEG2_PORT                Display1_Seg__LCD_SEG_PORT__2
#define Display1_SEG2_PIN                Display1_Seg__LCD_SEG_PIN__2
#define Display1_SEG3_PORT                Display1_Seg__LCD_SEG_PORT__3
#define Display1_SEG3_PIN                Display1_Seg__LCD_SEG_PIN__3
#define Display1_SEG4_PORT                Display1_Seg__LCD_SEG_PORT__4
#define Display1_SEG4_PIN                Display1_Seg__LCD_SEG_PIN__4
#define Display1_SEG5_PORT                Display1_Seg__LCD_SEG_PORT__5
#define Display1_SEG5_PIN                Display1_Seg__LCD_SEG_PIN__5
#define Display1_SEG6_PORT                Display1_Seg__LCD_SEG_PORT__6
#define Display1_SEG6_PIN                Display1_Seg__LCD_SEG_PIN__6
#define Display1_SEG7_PORT                Display1_Seg__LCD_SEG_PORT__7
#define Display1_SEG7_PIN                Display1_Seg__LCD_SEG_PIN__7
#define Display1_SEG8_PORT                Display1_Seg__LCD_SEG_PORT__8
#define Display1_SEG8_PIN                Display1_Seg__LCD_SEG_PIN__8
#define Display1_SEG9_PORT                Display1_Seg__LCD_SEG_PORT__9
#define Display1_SEG9_PIN                Display1_Seg__LCD_SEG_PIN__9
#define Display1_SEG10_PORT                Display1_Seg__LCD_SEG_PORT__10
#define Display1_SEG10_PIN                Display1_Seg__LCD_SEG_PIN__10
#define Display1_SEG11_PORT                Display1_Seg__LCD_SEG_PORT__11
#define Display1_SEG11_PIN                Display1_Seg__LCD_SEG_PIN__11
#define Display1_SEG12_PORT                Display1_Seg__LCD_SEG_PORT__12
#define Display1_SEG12_PIN                Display1_Seg__LCD_SEG_PIN__12
#define Display1_SEG13_PORT                Display1_Seg__LCD_SEG_PORT__13
#define Display1_SEG13_PIN                Display1_Seg__LCD_SEG_PIN__13

#define Display1_H7SEG0_A                Display1_FIND_PIXEL(Display1_SEG0_PORT,  Display1_SEG0_PIN,  0u)
#define Display1_H7SEG0_B                Display1_FIND_PIXEL(Display1_SEG1_PORT,  Display1_SEG1_PIN,  0u)
#define Display1_H7SEG0_C                Display1_FIND_PIXEL(Display1_SEG2_PORT,  Display1_SEG2_PIN,  0u)
#define Display1_H7SEG0_D                Display1_FIND_PIXEL(Display1_SEG3_PORT,  Display1_SEG3_PIN,  0u)
#define Display1_H7SEG0_E                Display1_FIND_PIXEL(Display1_SEG4_PORT,  Display1_SEG4_PIN,  0u)
#define Display1_H7SEG0_F                Display1_FIND_PIXEL(Display1_SEG5_PORT,  Display1_SEG5_PIN,  0u)
#define Display1_H7SEG0_G                Display1_FIND_PIXEL(Display1_SEG6_PORT,  Display1_SEG6_PIN,  0u)
#define Display1_H7SEG1_A                Display1_FIND_PIXEL(Display1_SEG7_PORT,  Display1_SEG7_PIN,  0u)
#define Display1_H7SEG1_B                Display1_FIND_PIXEL(Display1_SEG8_PORT,  Display1_SEG8_PIN,  0u)
#define Display1_H7SEG1_C                Display1_FIND_PIXEL(Display1_SEG9_PORT,  Display1_SEG9_PIN,  0u)
#define Display1_H7SEG1_D                Display1_FIND_PIXEL(Display1_SEG10_PORT,  Display1_SEG10_PIN,  0u)
#define Display1_H7SEG1_E                Display1_FIND_PIXEL(Display1_SEG11_PORT,  Display1_SEG11_PIN,  0u)
#define Display1_H7SEG1_F                Display1_FIND_PIXEL(Display1_SEG12_PORT,  Display1_SEG12_PIN,  0u)
#define Display1_H7SEG1_G                Display1_FIND_PIXEL(Display1_SEG13_PORT,  Display1_SEG13_PIN,  0u)


#define Display1_NOT_CON            ((uint8) (0xFFu))

/*
* Following definitions of the global variables are
* obsolete and which will be removed in the near future.
*/
#define Display1_Disp0            Display1_disp0
#define H7SEG0_A                Display1_H7SEG0_A
#define H7SEG0_B                Display1_H7SEG0_B
#define H7SEG0_C                Display1_H7SEG0_C
#define H7SEG0_D                Display1_H7SEG0_D
#define H7SEG0_E                Display1_H7SEG0_E
#define H7SEG0_F                Display1_H7SEG0_F
#define H7SEG0_G                Display1_H7SEG0_G
#define H7SEG1_A                Display1_H7SEG1_A
#define H7SEG1_B                Display1_H7SEG1_B
#define H7SEG1_C                Display1_H7SEG1_C
#define H7SEG1_D                Display1_H7SEG1_D
#define H7SEG1_E                Display1_H7SEG1_E
#define H7SEG1_F                Display1_H7SEG1_F
#define H7SEG1_G                Display1_H7SEG1_G

#define Display1_StSegLcdPort_DMA_TD_PROTO_COUNT 2


#define Display1_LCD_TD_SIZE               ((uint8) Display1_StSegLcdPort_DMA_TD_PROTO_COUNT)


/***************************************
*             Registers
***************************************/

#define Display1_ALIASED_AREA_PTR                        ((reg32) CYDEV_IO_DR_PRT0_DR_ALIAS)
#define Display1_PORT_BASE_PTR                           ((reg8 *) CYDEV_IO_PRT_PRT0_BASE)

#endif /* CY_ST_SEG_LCD_Display1_H */


/* [] END OF FILE */
