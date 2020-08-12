/*******************************************************************************
* File Name: Display2.h
* Version 3.40
*
* Description:
*  This header file contains definitions associated with the Segment LCD
*  component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SEGLCD_Display2_H)
#define CY_SEGLCD_Display2_H

#include "cytypes.h"
#include "cydevice_trm.h"
#include "cyfitter.h"
#include "CyLib.h"
#include <Display2_Int_Clock.h>


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define Display2_COMM_NUM            (1u)

#define Display2_BIT_MASK            (0x0007u)
#define Display2_BYTE_MASK           (0x00F0u)
#define Display2_ROW_MASK            (0x0F00u)

#define Display2_BYTE_SHIFT          (0x04u)
#define Display2_ROW_SHIFT           (0x08u)

#define Display2__TYPE_A 0
#define Display2__TYPE_B 1


#define Display2_WAVEFORM_TYPE       (0u)

/* Print error if cy_boot version is below 3.0 */
#ifndef CY_PSOC5LP
    #error Component SegLCD_v3_40 requires cy_boot v3.0 or later
#endif /* CY_PSOC5LP */


/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} Display2_BACKUP_STRUCT;

/* DMA_PROTO_GROUP_NAME=SegLcdPort */
struct Display2_DMA_TD_PROTO_ENTRY
{
	uint8 offset;	/* offset of the first register in this TD */
	uint8 length;	/* length of the register block in this TD */
};

/***************************************
*        Function Prototypes
***************************************/

void    Display2_Init(void) ;
uint8   Display2_Enable(void) ;
uint8   Display2_Start(void) ;
void    Display2_Stop(void) ;
void    Display2_EnableInt(void) ;
void    Display2_DisableInt(void) ;
uint8   Display2_SetBias(uint8 biasLevel) ;
uint8   Display2_WriteInvertState(uint8 invertState) ;
uint8   Display2_ReadInvertState(void) ;
void    Display2_ClearDisplay(void) ;
uint8   Display2_WritePixel(uint16 pixelNumber, uint8 pixelState)
                                                                    ;
uint8   Display2_ReadPixel(uint16 pixelNumber);
void    Display2_Sleep(void) ;
uint8   Display2_Wakeup(void) ;
void    Display2_SaveConfig(void) ;
void    Display2_RestoreConfig(void) ;

#define Display2_7SEG
void    Display2_Write7SegDigit_0(uint8 digit, uint8 position) ;
void    Display2_Write7SegNumber_0(uint16 value, uint8 position, uint8 mode) ;
CY_ISR_PROTO(Display2_ISR);
CY_ISR_PROTO(Display2_WAKEUP_ISR);

#define Display2_WRITE_PIXEL(pixelNumber,pixelState) (void) Display2_WritePixel(pixelNumber,pixelState)
#define Display2_READ_PIXEL(pixelNumber)             Display2_ReadPixel(pixelNumber)

/* Calculates pixel location in the frame buffer. */
#define Display2_FIND_PIXEL(port, pin, row)          ((uint16)(((((uint16)(row)) << Display2_ROW_SHIFT) + \
                                                             (((uint16)(port)) << Display2_BYTE_SHIFT)) + ((uint16)(pin))))

/* Internal macros that extract pixel information from a pixel number */
#define Display2_EXTRACT_ROW(pixel)                  ((uint8)(((pixel) & Display2_ROW_MASK) >> \
                                                                            Display2_ROW_SHIFT))
#define Display2_EXTRACT_PORT(pixel)                 ((uint8)(((pixel) & Display2_BYTE_MASK) >> \
                                                                            Display2_BYTE_SHIFT))
#define Display2_EXTRACT_PIN(pixel)                  ((uint8)((pixel) & Display2_BIT_MASK))


/***************************************
*           Global Variables
***************************************/

extern uint8 Display2_initVar;


/***************************************
*           API Constants
***************************************/
#if(CY_PSOC3)
    #define Display2_DMA_ADDRESS_MASK          (0x0000FFFFul)
#endif /* (CY_PSOC3) */

#define Display2_LOW_POWER                 (0x01u)

/* Frame buffer row length */
#define Display2_ROW_LENGTH                (0x10u)
#define Display2_BUFFER_LENGTH             (Display2_COMM_NUM * Display2_ROW_LENGTH)

#if(Display2_WAVEFORM_TYPE == Display2__TYPE_A)
    #define Display2_CONTROL_WRITE_COUNT   (0x02u)
#else
    #define Display2_CONTROL_WRITE_COUNT   (2u * Display2_COMM_NUM)
#endif /* (Display2_WAVEFORM_TYPE == Display2__TYPE_A) */

#define Display2_INVERT_BIT_MASK           (0x04u)
#define Display2_INVERT_SHIFT              (0x02u)

#define Display2_LCD_STATE_DISABLED        (0x00u)
#define Display2_LCD_STATE_ENABLED         (0x01u)

#define Display2_NORMAL_STATE              (0x00u)
#define Display2_INVERTED_STATE            (0x01u)
#define Display2_STATE_MASK                (0x01u)

/* Number of pixels for different kind of LCDs */
#define Display2_7SEG_PIX_NUM              (0x07u)
#define Display2_14SEG_PIX_NUM             (0x0Eu)
#define Display2_16SEG_PIX_NUM             (0x10u)
#define Display2_DM_CHAR_HEIGHT            (0x08u)
#define Display2_DM_CHAR_WIDTH             (0x05u)

/* API parameter pixel state constants */
#define Display2_PIXEL_STATE_OFF           (0x00u)
#define Display2_PIXEL_STATE_ON            (0x01u)
#define Display2_PIXEL_STATE_INVERT        (0x02u)
#define Display2_PIXEL_UNKNOWN_STATE       (0xFFu)

/* 0 - No leadig zeros, 1 - leadig zeros */
#define Display2_MODE_0                    (0x00u)
#define Display2_MODE_1                    (0x01u)

#define Display2_MAX_BUFF_ROWS             (0x10u)
#define Display2_ROW_BYTE_LEN              (0x10u)

#define Display2_ISR_NUMBER                ((uint8) Display2_TD_DoneInt__INTC_NUMBER)
#define Display2_ISR_PRIORITY              ((uint8) Display2_TD_DoneInt__INTC_PRIOR_NUM)

#if(CY_PSOC5LP)
    #define Display2_WAKEUP_ISR_NUMBER         ((uint8) Display2_Wakeup__INTC_NUMBER)
    #define Display2_WAKEUP_ISR_PRIORITY       ((uint8) Display2_Wakeup__INTC_PRIOR_NUM)
#endif /* CY_PSOC5LP */

#define Display2_DIGIT_NUM_0            (1u)

#define Display2_COM0_PORT            Display2_Com__LCD_COM_PORT__0
#define Display2_COM0_PIN            Display2_Com__LCD_COM_PIN__0

#define Display2_Com0            Display2_FIND_PIXEL(Display2_COM0_PORT,  Display2_COM0_PIN,  0)

#define Display2_SEG0_PORT            Display2_Seg__LCD_SEG_PORT__0
#define Display2_SEG0_PIN            Display2_Seg__LCD_SEG_PIN__0
#define Display2_SEG1_PORT            Display2_Seg__LCD_SEG_PORT__1
#define Display2_SEG1_PIN            Display2_Seg__LCD_SEG_PIN__1
#define Display2_SEG2_PORT            Display2_Seg__LCD_SEG_PORT__2
#define Display2_SEG2_PIN            Display2_Seg__LCD_SEG_PIN__2
#define Display2_SEG3_PORT            Display2_Seg__LCD_SEG_PORT__3
#define Display2_SEG3_PIN            Display2_Seg__LCD_SEG_PIN__3
#define Display2_SEG4_PORT            Display2_Seg__LCD_SEG_PORT__4
#define Display2_SEG4_PIN            Display2_Seg__LCD_SEG_PIN__4
#define Display2_SEG5_PORT            Display2_Seg__LCD_SEG_PORT__5
#define Display2_SEG5_PIN            Display2_Seg__LCD_SEG_PIN__5
#define Display2_SEG6_PORT            Display2_Seg__LCD_SEG_PORT__6
#define Display2_SEG6_PIN            Display2_Seg__LCD_SEG_PIN__6

#define Display2_H7SEG0_A            Display2_FIND_PIXEL(Display2_SEG0_PORT,  Display2_SEG0_PIN,  0)
#define Display2_H7SEG0_B            Display2_FIND_PIXEL(Display2_SEG1_PORT,  Display2_SEG1_PIN,  0)
#define Display2_H7SEG0_C            Display2_FIND_PIXEL(Display2_SEG2_PORT,  Display2_SEG2_PIN,  0)
#define Display2_H7SEG0_D            Display2_FIND_PIXEL(Display2_SEG3_PORT,  Display2_SEG3_PIN,  0)
#define Display2_H7SEG0_E            Display2_FIND_PIXEL(Display2_SEG4_PORT,  Display2_SEG4_PIN,  0)
#define Display2_H7SEG0_F            Display2_FIND_PIXEL(Display2_SEG5_PORT,  Display2_SEG5_PIN,  0)
#define Display2_H7SEG0_G            Display2_FIND_PIXEL(Display2_SEG6_PORT,  Display2_SEG6_PIN,  0)

#define Display2_PIX7            Display2_FIND_PIXEL(Display2_SEG1_PORT,  Display2_SEG1_PIN,  3)
#define Display2_PIX9            Display2_FIND_PIXEL(Display2_SEG2_PORT,  Display2_SEG2_PIN,  1)
#define Display2_PIX10            Display2_FIND_PIXEL(Display2_SEG2_PORT,  Display2_SEG2_PIN,  2)
#define Display2_PIX11            Display2_FIND_PIXEL(Display2_SEG2_PORT,  Display2_SEG2_PIN,  3)
#define Display2_PIX13            Display2_FIND_PIXEL(Display2_SEG3_PORT,  Display2_SEG3_PIN,  1)
#define Display2_PIX14            Display2_FIND_PIXEL(Display2_SEG3_PORT,  Display2_SEG3_PIN,  2)
#define Display2_PIX15            Display2_FIND_PIXEL(Display2_SEG3_PORT,  Display2_SEG3_PIN,  3)
#define Display2_PIX17            Display2_FIND_PIXEL(Display2_SEG4_PORT,  Display2_SEG4_PIN,  1)
#define Display2_PIX18            Display2_FIND_PIXEL(Display2_SEG4_PORT,  Display2_SEG4_PIN,  2)
#define Display2_PIX19            Display2_FIND_PIXEL(Display2_SEG4_PORT,  Display2_SEG4_PIN,  3)
#define Display2_PIX21            Display2_FIND_PIXEL(Display2_SEG5_PORT,  Display2_SEG5_PIN,  1)
#define Display2_PIX22            Display2_FIND_PIXEL(Display2_SEG5_PORT,  Display2_SEG5_PIN,  2)
#define Display2_PIX23            Display2_FIND_PIXEL(Display2_SEG5_PORT,  Display2_SEG5_PIN,  3)
#define Display2_PIX25            Display2_FIND_PIXEL(Display2_SEG6_PORT,  Display2_SEG6_PIN,  1)
#define Display2_PIX26            Display2_FIND_PIXEL(Display2_SEG6_PORT,  Display2_SEG6_PIN,  2)
#define Display2_PIX27            Display2_FIND_PIXEL(Display2_SEG6_PORT,  Display2_SEG6_PIN,  3)
#define Display2_PIX28            Display2_FIND_PIXEL(Display2_SEG7_PORT,  Display2_SEG7_PIN,  0)
#define Display2_PIX29            Display2_FIND_PIXEL(Display2_SEG7_PORT,  Display2_SEG7_PIN,  1)
#define Display2_PIX30            Display2_FIND_PIXEL(Display2_SEG7_PORT,  Display2_SEG7_PIN,  2)
#define Display2_PIX31            Display2_FIND_PIXEL(Display2_SEG7_PORT,  Display2_SEG7_PIN,  3)

#define Display2_NOT_CON            (0xFFFFu)
#define Display2_SegLcdPort_DMA_TD_PROTO_COUNT 1

#define Display2_LCD_TD_SIZE               ((uint8) Display2_SegLcdPort_DMA_TD_PROTO_COUNT)

#define Display2_COM_TD_COUNT              ((uint8) \
                                                   ((Display2_COMM_NUM * Display2_LCD_TD_SIZE) - 1u))

#define Display2_MODE_MASK                 (0x06u)

/* Defines index of "blank" didgit in the look-up table for 7 segment helper */
#define Display2_7SEG_BLANK_DIG            (0x10u)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define Display2__NO_SLEEP 0
#define Display2__LOW_POWER_32XTAL 2
#define Display2__LOW_POWER_ILO 1


/***************************************
*    Initial Parameter Constants
***************************************/

#define Display2_SEG_NUM               (7u)
#define Display2_BIAS_TYPE             (2u)
#define Display2_BIAS_VOLTAGE          (63u)
#define Display2_POWER_MODE            (0u)
#define Display2_FRAME_RATE            (10u)
#define Display2_HI_DRIVE_TIME         (1u)
#define Display2_LOW_DRIVE_TIME        (253u)
#define Display2_HIDRIVE_STRENGTH      (2u)
#define Display2_LOWDRIVE_STRENGTH     (0u)

#if(Display2_POWER_MODE == Display2__NO_SLEEP)
    #define Display2_DRIVE_TIME        ((Display2_LOW_DRIVE_TIME + Display2_HI_DRIVE_TIME) - 1u)
#else
    #define Display2_DRIVE_TIME        (Display2_HI_DRIVE_TIME)
#endif /* Display2_POWER_MODE == Display2__NO_SLEEP */

#if(Display2_POWER_MODE == Display2__NO_SLEEP)

    /* Set PWM period for 255 in NoSleep mode */
    #define Display2_PWM_PERIOD_VAL        (0xFFu)
    /* D0 = 255 - HiDrive time */
    #define Display2_PWM_DRIVE_VAL        ((Display2_PWM_PERIOD_VAL) - (Display2_HI_DRIVE_TIME))
    /* D1 = 255 - Drive time */
    #define Display2_PWM_LOWDRIVE_VAL     ((Display2_PWM_PERIOD_VAL) - (Display2_DRIVE_TIME))

#else

    /* PWM period will be equal to 0 */
    #define Display2_PWM_PERIOD_VAL        (0x00u)
    /* D0 is equal to HiDrive time, as it used as period reg for Low Power mode */
    #define Display2_PWM_DRIVE_VAL         (Display2_HI_DRIVE_TIME - 1u)
    /* Make sure D1 is 0 */
    #define Display2_PWM_LOWDRIVE_VAL      (0x00u)

#endif /* Display2_POWER_MODE == Display2__NO_SLEEP */


/***************************************
*             Registers
***************************************/

/* LCD's fixed block registers */
#define Display2_LCDDAC_CONTROL_REG       (* (reg8*) Display2_LCD__CR0)
#define Display2_LCDDAC_CONTROL_PTR       ((reg8*) Display2_LCD__CR0)
#define Display2_CONTRAST_CONTROL_REG     (* (reg8*) Display2_LCD__CR1)
#define Display2_CONTRAST_CONTROL_PTR     ((reg8*) Display2_LCD__CR1)
#define Display2_DRIVER_CONTROL_REG       (* (reg8*)Display2_LCD__CR)
#define Display2_DRIVER_CONTROL_PTR       ((reg8*)Display2_LCD__CR)
#define Display2_TIMER_CONTROL_REG        (* (reg8*) Display2_LCD__CFG)
#define Display2_TIMER_CONTROL_PTR        ((reg8*) Display2_LCD__CFG)
#define Display2_ALIASED_AREA_PTR         ((reg32) CYREG_PRT0_DR_ALIAS)
#define Display2_PWR_MGR_REG              (* (reg8 *) Display2_LCD__PM_ACT_CFG)
#define Display2_PWR_MGR_PTR              ((reg8 *) Display2_LCD__PM_ACT_CFG)
#define Display2_PWR_MGR_STBY_REG         (* (reg8 *) Display2_LCD__PM_STBY_CFG)
#define Display2_PWR_MGR_STBY_PTR         ((reg8 *) Display2_LCD__PM_STBY_CFG)

#if(Display2_POWER_MODE == Display2__LOW_POWER_32XTAL)
    #define Display2_TM_WL_GFG_REG         (*(reg8 *) CYREG_PM_TW_CFG2)
    #define Display2_TM_WL_GFG_PTR         ((reg8 *) CYREG_PM_TW_CFG2)
#endif /* Display2_POWER_MODE == Display2__LOW_POWER_32XTAL */

#define Display2_LCDDAC_SWITCH_REG0_REG   (* (reg8*)Display2_LCD__SW0)
#define Display2_LCDDAC_SWITCH_REG1_REG   (* (reg8*)Display2_LCD__SW1)
#define Display2_LCDDAC_SWITCH_REG2_REG   (* (reg8*)Display2_LCD__SW2)
#define Display2_LCDDAC_SWITCH_REG3_REG   (* (reg8*)Display2_LCD__SW3)
#define Display2_LCDDAC_SWITCH_REG4_REG   (* (reg8*)Display2_LCD__SW4)

#define Display2_LCDDAC_SWITCH_REG0_PTR   ((reg8*)Display2_LCD__SW0)
#define Display2_LCDDAC_SWITCH_REG1_PTR   ((reg8*)Display2_LCD__SW1)
#define Display2_LCDDAC_SWITCH_REG2_PTR   ((reg8*)Display2_LCD__SW2)
#define Display2_LCDDAC_SWITCH_REG3_PTR   ((reg8*)Display2_LCD__SW3)
#define Display2_LCDDAC_SWITCH_REG4_PTR   ((reg8*)Display2_LCD__SW4)

/* UDB registers */
#if(Display2_POWER_MODE == Display2__NO_SLEEP)
    #define Display2_PWM_PERIOD_REG         (* (reg8 *) Display2_bLCDDSD_NoSleep_bSegLCDdp_u0__A1_REG)
    #define Display2_PWM_PERIOD_PTR         ((reg8 *) Display2_bLCDDSD_NoSleep_bSegLCDdp_u0__A1_REG)
    #define Display2_PWM_DRIVE_REG          (* (reg8 *) Display2_bLCDDSD_NoSleep_bSegLCDdp_u0__D0_REG)
    #define Display2_PWM_DRIVE_PTR          ((reg8 *) Display2_bLCDDSD_NoSleep_bSegLCDdp_u0__D0_REG)
    #define Display2_PWM_LODRIVE_REG        (* (reg8 *) Display2_bLCDDSD_NoSleep_bSegLCDdp_u0__D1_REG)
    #define Display2_PWM_LODRIVE_PTR        ((reg8 *) Display2_bLCDDSD_NoSleep_bSegLCDdp_u0__D1_REG)
#else
    #define Display2_PWM_PERIOD_REG         (* (reg8 *) Display2_bLCDDSD_LowPower_bSegLCDdp_u0__A1_REG)
    #define Display2_PWM_PERIOD_PTR         ((reg8 *) Display2_bLCDDSD_LowPower_bSegLCDdp_u0__A1_REG)
    #define Display2_PWM_DRIVE_REG          (* (reg8 *) Display2_bLCDDSD_LowPower_bSegLCDdp_u0__D0_REG)
    #define Display2_PWM_DRIVE_PTR          ((reg8 *) Display2_bLCDDSD_LowPower_bSegLCDdp_u0__D0_REG)
    #define Display2_PWM_LODRIVE_REG        (* (reg8 *) Display2_bLCDDSD_LowPower_bSegLCDdp_u0__D1_REG)
    #define Display2_PWM_LODRIVE_PTR        ((reg8 *) Display2_bLCDDSD_LowPower_bSegLCDdp_u0__D1_REG)
#endif /* Display2_POWER_MODE == Display2__NO_SLEEP */

#define Display2_CONTROL_REG                (* (reg8 *) Display2_bLCDDSD_CtrlReg__CONTROL_REG)
#define Display2_CONTROL_PTR                ((reg8 *) Display2_bLCDDSD_CtrlReg__CONTROL_REG)

/* This is required for DmaInitialize() fou usage as a
* base destination address of conrol register. 
*/
#define Display2_CONTROL_REG_BASE           (CYDEV_PERIPH_BASE)

/***************************************
*       Register Constants
***************************************/

/* PM Control Register bits */
#define Display2_LCD_EN                    (Display2_LCD__PM_ACT_MSK)
#define Display2_LCD_STBY_EN               (Display2_LCD__PM_STBY_MSK)

/* LCD DAC Control Register Bits */
#define Display2_LCDDAC_UDB_LP_EN          (0x80u)
#define Display2_LCDDAC_CONT_DRIVE         (0x08u)
#define Display2_BIAS_TYPE_MASK            (0x03u)

#define Display2_LCDDAC_VOLTAGE_SEL        (0x01u)
#define Display2_LCDDAC_CONT_DRIVE         (0x08u)
#define Display2_LCDDAC_CONT_DRIVE_MASK    (~0x08u)

/* LCD Driver Control Register Bits */
#define Display2_LCDDRV_DISPLAY_BLNK       (0x01u)
#define Display2_LCDDRV_MODE0_MASK         (0x02u)
#define Display2_LCDDRV_MODE0_SHIFT        (0x01u)
#define Display2_LCDDRV_INVERT             (0x04u)
#define Display2_LCDDRV_PTS                (0x08u)
#define Display2_LCDDRV_BYPASS_EN          (0x10u)

#if(Display2_POWER_MODE == Display2__LOW_POWER_32XTAL)
    #define Display2_ONE_PPS_EN            (0x10u)
#endif /* Display2_POWER_MODE == Display2__LOW_POWER_32XTAL */

#if(Display2_POWER_MODE != Display2__NO_SLEEP)

    /* LCD Timer Control Register Bits */
    #define Display2_TIMER_EN                  (0x01u)
    #define Display2_TIMER_ILO_SEL             (0x00u)
    #define Display2_TIMER_32XTAL_SEL          (0x02u)
    #define Display2_TIMER_CLK_SEL_MASK        (0x02u)
    #define Display2_TIMER_PERIOD_MASK         (0xFCu)
    #define Display2_TIMER_PERIOD_SHIFT        (0x02u)

    #define Display2_TIMER_PERIOD              (15u)

#endif /* Display2_POWER_MODE != Display2__NO_SLEEP */

/* UDB Control Register bits */
#define Display2_CNTL_CLK_EN               (0x01u)
#define Display2_CNTL_CLK_EN_MASK          (~Display2_CNTL_CLK_EN)
#define Display2_CNTL_MODE_SHIFT           (0x01u)
#define Display2_CNTL_MODE_MASK            (~0x06u)
#define Display2_CNTL_FRAME_DONE           (0x08u)
#define Display2_CNTL_FRAME_DONE_MASK      (~Display2_CNTL_FRAME_DONE)


#endif  /* CY_SEGLCD_Display2_H */

/* [] END OF FILE */
