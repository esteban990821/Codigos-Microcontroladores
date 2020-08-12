/*******************************************************************************
* File Name: Display0.h
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

#if !defined(CY_SEGLCD_Display0_H)
#define CY_SEGLCD_Display0_H

#include "cytypes.h"
#include "cydevice_trm.h"
#include "cyfitter.h"
#include "CyLib.h"
#include <Display0_Int_Clock.h>


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define Display0_COMM_NUM            (2u)

#define Display0_BIT_MASK            (0x0007u)
#define Display0_BYTE_MASK           (0x00F0u)
#define Display0_ROW_MASK            (0x0F00u)

#define Display0_BYTE_SHIFT          (0x04u)
#define Display0_ROW_SHIFT           (0x08u)

#define Display0__TYPE_A 0
#define Display0__TYPE_B 1


#define Display0_WAVEFORM_TYPE       (0u)

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
} Display0_BACKUP_STRUCT;

/* DMA_PROTO_GROUP_NAME=SegLcdPort */
struct Display0_DMA_TD_PROTO_ENTRY
{
	uint8 offset;	/* offset of the first register in this TD */
	uint8 length;	/* length of the register block in this TD */
};

/***************************************
*        Function Prototypes
***************************************/

void    Display0_Init(void) ;
uint8   Display0_Enable(void) ;
uint8   Display0_Start(void) ;
void    Display0_Stop(void) ;
void    Display0_EnableInt(void) ;
void    Display0_DisableInt(void) ;
uint8   Display0_SetBias(uint8 biasLevel) ;
uint8   Display0_WriteInvertState(uint8 invertState) ;
uint8   Display0_ReadInvertState(void) ;
void    Display0_ClearDisplay(void) ;
uint8   Display0_WritePixel(uint16 pixelNumber, uint8 pixelState)
                                                                    ;
uint8   Display0_ReadPixel(uint16 pixelNumber);
void    Display0_Sleep(void) ;
uint8   Display0_Wakeup(void) ;
void    Display0_SaveConfig(void) ;
void    Display0_RestoreConfig(void) ;

#define Display0_7SEG
void    Display0_Write7SegDigit_0(uint8 digit, uint8 position) ;
void    Display0_Write7SegNumber_0(uint16 value, uint8 position, uint8 mode) ;
CY_ISR_PROTO(Display0_ISR);
CY_ISR_PROTO(Display0_WAKEUP_ISR);

#define Display0_WRITE_PIXEL(pixelNumber,pixelState) (void) Display0_WritePixel(pixelNumber,pixelState)
#define Display0_READ_PIXEL(pixelNumber)             Display0_ReadPixel(pixelNumber)

/* Calculates pixel location in the frame buffer. */
#define Display0_FIND_PIXEL(port, pin, row)          ((uint16)(((((uint16)(row)) << Display0_ROW_SHIFT) + \
                                                             (((uint16)(port)) << Display0_BYTE_SHIFT)) + ((uint16)(pin))))

/* Internal macros that extract pixel information from a pixel number */
#define Display0_EXTRACT_ROW(pixel)                  ((uint8)(((pixel) & Display0_ROW_MASK) >> \
                                                                            Display0_ROW_SHIFT))
#define Display0_EXTRACT_PORT(pixel)                 ((uint8)(((pixel) & Display0_BYTE_MASK) >> \
                                                                            Display0_BYTE_SHIFT))
#define Display0_EXTRACT_PIN(pixel)                  ((uint8)((pixel) & Display0_BIT_MASK))


/***************************************
*           Global Variables
***************************************/

extern uint8 Display0_initVar;


/***************************************
*           API Constants
***************************************/
#if(CY_PSOC3)
    #define Display0_DMA_ADDRESS_MASK          (0x0000FFFFul)
#endif /* (CY_PSOC3) */

#define Display0_LOW_POWER                 (0x01u)

/* Frame buffer row length */
#define Display0_ROW_LENGTH                (0x10u)
#define Display0_BUFFER_LENGTH             (Display0_COMM_NUM * Display0_ROW_LENGTH)

#if(Display0_WAVEFORM_TYPE == Display0__TYPE_A)
    #define Display0_CONTROL_WRITE_COUNT   (0x02u)
#else
    #define Display0_CONTROL_WRITE_COUNT   (2u * Display0_COMM_NUM)
#endif /* (Display0_WAVEFORM_TYPE == Display0__TYPE_A) */

#define Display0_INVERT_BIT_MASK           (0x04u)
#define Display0_INVERT_SHIFT              (0x02u)

#define Display0_LCD_STATE_DISABLED        (0x00u)
#define Display0_LCD_STATE_ENABLED         (0x01u)

#define Display0_NORMAL_STATE              (0x00u)
#define Display0_INVERTED_STATE            (0x01u)
#define Display0_STATE_MASK                (0x01u)

/* Number of pixels for different kind of LCDs */
#define Display0_7SEG_PIX_NUM              (0x07u)
#define Display0_14SEG_PIX_NUM             (0x0Eu)
#define Display0_16SEG_PIX_NUM             (0x10u)
#define Display0_DM_CHAR_HEIGHT            (0x08u)
#define Display0_DM_CHAR_WIDTH             (0x05u)

/* API parameter pixel state constants */
#define Display0_PIXEL_STATE_OFF           (0x00u)
#define Display0_PIXEL_STATE_ON            (0x01u)
#define Display0_PIXEL_STATE_INVERT        (0x02u)
#define Display0_PIXEL_UNKNOWN_STATE       (0xFFu)

/* 0 - No leadig zeros, 1 - leadig zeros */
#define Display0_MODE_0                    (0x00u)
#define Display0_MODE_1                    (0x01u)

#define Display0_MAX_BUFF_ROWS             (0x10u)
#define Display0_ROW_BYTE_LEN              (0x10u)

#define Display0_ISR_NUMBER                ((uint8) Display0_TD_DoneInt__INTC_NUMBER)
#define Display0_ISR_PRIORITY              ((uint8) Display0_TD_DoneInt__INTC_PRIOR_NUM)

#if(CY_PSOC5LP)
    #define Display0_WAKEUP_ISR_NUMBER         ((uint8) Display0_Wakeup__INTC_NUMBER)
    #define Display0_WAKEUP_ISR_PRIORITY       ((uint8) Display0_Wakeup__INTC_PRIOR_NUM)
#endif /* CY_PSOC5LP */

#define Display0_DIGIT_NUM_0            (2u)

#define Display0_COM0_PORT            Display0_Com__LCD_COM_PORT__0
#define Display0_COM0_PIN            Display0_Com__LCD_COM_PIN__0
#define Display0_COM1_PORT            Display0_Com__LCD_COM_PORT__1
#define Display0_COM1_PIN            Display0_Com__LCD_COM_PIN__1

#define Display0_Com0            Display0_FIND_PIXEL(Display0_COM0_PORT,  Display0_COM0_PIN,  0)
#define Display0_Com1            Display0_FIND_PIXEL(Display0_COM1_PORT,  Display0_COM1_PIN,  1)

#define Display0_SEG0_PORT            Display0_Seg__LCD_SEG_PORT__0
#define Display0_SEG0_PIN            Display0_Seg__LCD_SEG_PIN__0
#define Display0_SEG1_PORT            Display0_Seg__LCD_SEG_PORT__1
#define Display0_SEG1_PIN            Display0_Seg__LCD_SEG_PIN__1
#define Display0_SEG2_PORT            Display0_Seg__LCD_SEG_PORT__2
#define Display0_SEG2_PIN            Display0_Seg__LCD_SEG_PIN__2
#define Display0_SEG3_PORT            Display0_Seg__LCD_SEG_PORT__3
#define Display0_SEG3_PIN            Display0_Seg__LCD_SEG_PIN__3
#define Display0_SEG4_PORT            Display0_Seg__LCD_SEG_PORT__4
#define Display0_SEG4_PIN            Display0_Seg__LCD_SEG_PIN__4
#define Display0_SEG5_PORT            Display0_Seg__LCD_SEG_PORT__5
#define Display0_SEG5_PIN            Display0_Seg__LCD_SEG_PIN__5
#define Display0_SEG6_PORT            Display0_Seg__LCD_SEG_PORT__6
#define Display0_SEG6_PIN            Display0_Seg__LCD_SEG_PIN__6

#define Display0_H7SEG0_A            Display0_FIND_PIXEL(Display0_SEG0_PORT,  Display0_SEG0_PIN,  1)
#define Display0_H7SEG0_B            Display0_FIND_PIXEL(Display0_SEG1_PORT,  Display0_SEG1_PIN,  1)
#define Display0_H7SEG0_C            Display0_FIND_PIXEL(Display0_SEG2_PORT,  Display0_SEG2_PIN,  1)
#define Display0_H7SEG0_D            Display0_FIND_PIXEL(Display0_SEG3_PORT,  Display0_SEG3_PIN,  1)
#define Display0_H7SEG0_E            Display0_FIND_PIXEL(Display0_SEG4_PORT,  Display0_SEG4_PIN,  1)
#define Display0_H7SEG0_F            Display0_FIND_PIXEL(Display0_SEG5_PORT,  Display0_SEG5_PIN,  1)
#define Display0_H7SEG0_G            Display0_FIND_PIXEL(Display0_SEG6_PORT,  Display0_SEG6_PIN,  1)
#define Display0_H7SEG1_A            Display0_FIND_PIXEL(Display0_SEG0_PORT,  Display0_SEG0_PIN,  0)
#define Display0_H7SEG1_B            Display0_FIND_PIXEL(Display0_SEG1_PORT,  Display0_SEG1_PIN,  0)
#define Display0_H7SEG1_C            Display0_FIND_PIXEL(Display0_SEG2_PORT,  Display0_SEG2_PIN,  0)
#define Display0_H7SEG1_D            Display0_FIND_PIXEL(Display0_SEG3_PORT,  Display0_SEG3_PIN,  0)
#define Display0_H7SEG1_E            Display0_FIND_PIXEL(Display0_SEG4_PORT,  Display0_SEG4_PIN,  0)
#define Display0_H7SEG1_F            Display0_FIND_PIXEL(Display0_SEG5_PORT,  Display0_SEG5_PIN,  0)
#define Display0_H7SEG1_G            Display0_FIND_PIXEL(Display0_SEG6_PORT,  Display0_SEG6_PIN,  0)

#define Display0_PIX14            Display0_FIND_PIXEL(Display0_SEG3_PORT,  Display0_SEG3_PIN,  2)
#define Display0_PIX15            Display0_FIND_PIXEL(Display0_SEG3_PORT,  Display0_SEG3_PIN,  3)
#define Display0_PIX18            Display0_FIND_PIXEL(Display0_SEG4_PORT,  Display0_SEG4_PIN,  2)
#define Display0_PIX19            Display0_FIND_PIXEL(Display0_SEG4_PORT,  Display0_SEG4_PIN,  3)
#define Display0_PIX22            Display0_FIND_PIXEL(Display0_SEG5_PORT,  Display0_SEG5_PIN,  2)
#define Display0_PIX23            Display0_FIND_PIXEL(Display0_SEG5_PORT,  Display0_SEG5_PIN,  3)
#define Display0_PIX26            Display0_FIND_PIXEL(Display0_SEG6_PORT,  Display0_SEG6_PIN,  2)
#define Display0_PIX27            Display0_FIND_PIXEL(Display0_SEG6_PORT,  Display0_SEG6_PIN,  3)
#define Display0_PIX28            Display0_FIND_PIXEL(Display0_SEG7_PORT,  Display0_SEG7_PIN,  0)
#define Display0_PIX29            Display0_FIND_PIXEL(Display0_SEG7_PORT,  Display0_SEG7_PIN,  1)
#define Display0_PIX30            Display0_FIND_PIXEL(Display0_SEG7_PORT,  Display0_SEG7_PIN,  2)
#define Display0_PIX31            Display0_FIND_PIXEL(Display0_SEG7_PORT,  Display0_SEG7_PIN,  3)

#define Display0_NOT_CON            (0xFFFFu)
#define Display0_SegLcdPort_DMA_TD_PROTO_COUNT 1

#define Display0_LCD_TD_SIZE               ((uint8) Display0_SegLcdPort_DMA_TD_PROTO_COUNT)

#define Display0_COM_TD_COUNT              ((uint8) \
                                                   ((Display0_COMM_NUM * Display0_LCD_TD_SIZE) - 1u))

#define Display0_MODE_MASK                 (0x06u)

/* Defines index of "blank" didgit in the look-up table for 7 segment helper */
#define Display0_7SEG_BLANK_DIG            (0x10u)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define Display0__NO_SLEEP 0
#define Display0__LOW_POWER_32XTAL 2
#define Display0__LOW_POWER_ILO 1


/***************************************
*    Initial Parameter Constants
***************************************/

#define Display0_SEG_NUM               (7u)
#define Display0_BIAS_TYPE             (1u)
#define Display0_BIAS_VOLTAGE          (49u)
#define Display0_POWER_MODE            (0u)
#define Display0_FRAME_RATE            (80u)
#define Display0_HI_DRIVE_TIME         (5u)
#define Display0_LOW_DRIVE_TIME        (249u)
#define Display0_HIDRIVE_STRENGTH      (2u)
#define Display0_LOWDRIVE_STRENGTH     (6u)

#if(Display0_POWER_MODE == Display0__NO_SLEEP)
    #define Display0_DRIVE_TIME        ((Display0_LOW_DRIVE_TIME + Display0_HI_DRIVE_TIME) - 1u)
#else
    #define Display0_DRIVE_TIME        (Display0_HI_DRIVE_TIME)
#endif /* Display0_POWER_MODE == Display0__NO_SLEEP */

#if(Display0_POWER_MODE == Display0__NO_SLEEP)

    /* Set PWM period for 255 in NoSleep mode */
    #define Display0_PWM_PERIOD_VAL        (0xFFu)
    /* D0 = 255 - HiDrive time */
    #define Display0_PWM_DRIVE_VAL        ((Display0_PWM_PERIOD_VAL) - (Display0_HI_DRIVE_TIME))
    /* D1 = 255 - Drive time */
    #define Display0_PWM_LOWDRIVE_VAL     ((Display0_PWM_PERIOD_VAL) - (Display0_DRIVE_TIME))

#else

    /* PWM period will be equal to 0 */
    #define Display0_PWM_PERIOD_VAL        (0x00u)
    /* D0 is equal to HiDrive time, as it used as period reg for Low Power mode */
    #define Display0_PWM_DRIVE_VAL         (Display0_HI_DRIVE_TIME - 1u)
    /* Make sure D1 is 0 */
    #define Display0_PWM_LOWDRIVE_VAL      (0x00u)

#endif /* Display0_POWER_MODE == Display0__NO_SLEEP */


/***************************************
*             Registers
***************************************/

/* LCD's fixed block registers */
#define Display0_LCDDAC_CONTROL_REG       (* (reg8*) Display0_LCD__CR0)
#define Display0_LCDDAC_CONTROL_PTR       ((reg8*) Display0_LCD__CR0)
#define Display0_CONTRAST_CONTROL_REG     (* (reg8*) Display0_LCD__CR1)
#define Display0_CONTRAST_CONTROL_PTR     ((reg8*) Display0_LCD__CR1)
#define Display0_DRIVER_CONTROL_REG       (* (reg8*)Display0_LCD__CR)
#define Display0_DRIVER_CONTROL_PTR       ((reg8*)Display0_LCD__CR)
#define Display0_TIMER_CONTROL_REG        (* (reg8*) Display0_LCD__CFG)
#define Display0_TIMER_CONTROL_PTR        ((reg8*) Display0_LCD__CFG)
#define Display0_ALIASED_AREA_PTR         ((reg32) CYREG_PRT0_DR_ALIAS)
#define Display0_PWR_MGR_REG              (* (reg8 *) Display0_LCD__PM_ACT_CFG)
#define Display0_PWR_MGR_PTR              ((reg8 *) Display0_LCD__PM_ACT_CFG)
#define Display0_PWR_MGR_STBY_REG         (* (reg8 *) Display0_LCD__PM_STBY_CFG)
#define Display0_PWR_MGR_STBY_PTR         ((reg8 *) Display0_LCD__PM_STBY_CFG)

#if(Display0_POWER_MODE == Display0__LOW_POWER_32XTAL)
    #define Display0_TM_WL_GFG_REG         (*(reg8 *) CYREG_PM_TW_CFG2)
    #define Display0_TM_WL_GFG_PTR         ((reg8 *) CYREG_PM_TW_CFG2)
#endif /* Display0_POWER_MODE == Display0__LOW_POWER_32XTAL */

#define Display0_LCDDAC_SWITCH_REG0_REG   (* (reg8*)Display0_LCD__SW0)
#define Display0_LCDDAC_SWITCH_REG1_REG   (* (reg8*)Display0_LCD__SW1)
#define Display0_LCDDAC_SWITCH_REG2_REG   (* (reg8*)Display0_LCD__SW2)
#define Display0_LCDDAC_SWITCH_REG3_REG   (* (reg8*)Display0_LCD__SW3)
#define Display0_LCDDAC_SWITCH_REG4_REG   (* (reg8*)Display0_LCD__SW4)

#define Display0_LCDDAC_SWITCH_REG0_PTR   ((reg8*)Display0_LCD__SW0)
#define Display0_LCDDAC_SWITCH_REG1_PTR   ((reg8*)Display0_LCD__SW1)
#define Display0_LCDDAC_SWITCH_REG2_PTR   ((reg8*)Display0_LCD__SW2)
#define Display0_LCDDAC_SWITCH_REG3_PTR   ((reg8*)Display0_LCD__SW3)
#define Display0_LCDDAC_SWITCH_REG4_PTR   ((reg8*)Display0_LCD__SW4)

/* UDB registers */
#if(Display0_POWER_MODE == Display0__NO_SLEEP)
    #define Display0_PWM_PERIOD_REG         (* (reg8 *) Display0_bLCDDSD_NoSleep_bSegLCDdp_u0__A1_REG)
    #define Display0_PWM_PERIOD_PTR         ((reg8 *) Display0_bLCDDSD_NoSleep_bSegLCDdp_u0__A1_REG)
    #define Display0_PWM_DRIVE_REG          (* (reg8 *) Display0_bLCDDSD_NoSleep_bSegLCDdp_u0__D0_REG)
    #define Display0_PWM_DRIVE_PTR          ((reg8 *) Display0_bLCDDSD_NoSleep_bSegLCDdp_u0__D0_REG)
    #define Display0_PWM_LODRIVE_REG        (* (reg8 *) Display0_bLCDDSD_NoSleep_bSegLCDdp_u0__D1_REG)
    #define Display0_PWM_LODRIVE_PTR        ((reg8 *) Display0_bLCDDSD_NoSleep_bSegLCDdp_u0__D1_REG)
#else
    #define Display0_PWM_PERIOD_REG         (* (reg8 *) Display0_bLCDDSD_LowPower_bSegLCDdp_u0__A1_REG)
    #define Display0_PWM_PERIOD_PTR         ((reg8 *) Display0_bLCDDSD_LowPower_bSegLCDdp_u0__A1_REG)
    #define Display0_PWM_DRIVE_REG          (* (reg8 *) Display0_bLCDDSD_LowPower_bSegLCDdp_u0__D0_REG)
    #define Display0_PWM_DRIVE_PTR          ((reg8 *) Display0_bLCDDSD_LowPower_bSegLCDdp_u0__D0_REG)
    #define Display0_PWM_LODRIVE_REG        (* (reg8 *) Display0_bLCDDSD_LowPower_bSegLCDdp_u0__D1_REG)
    #define Display0_PWM_LODRIVE_PTR        ((reg8 *) Display0_bLCDDSD_LowPower_bSegLCDdp_u0__D1_REG)
#endif /* Display0_POWER_MODE == Display0__NO_SLEEP */

#define Display0_CONTROL_REG                (* (reg8 *) Display0_bLCDDSD_CtrlReg__CONTROL_REG)
#define Display0_CONTROL_PTR                ((reg8 *) Display0_bLCDDSD_CtrlReg__CONTROL_REG)

/* This is required for DmaInitialize() fou usage as a
* base destination address of conrol register. 
*/
#define Display0_CONTROL_REG_BASE           (CYDEV_PERIPH_BASE)

/***************************************
*       Register Constants
***************************************/

/* PM Control Register bits */
#define Display0_LCD_EN                    (Display0_LCD__PM_ACT_MSK)
#define Display0_LCD_STBY_EN               (Display0_LCD__PM_STBY_MSK)

/* LCD DAC Control Register Bits */
#define Display0_LCDDAC_UDB_LP_EN          (0x80u)
#define Display0_LCDDAC_CONT_DRIVE         (0x08u)
#define Display0_BIAS_TYPE_MASK            (0x03u)

#define Display0_LCDDAC_VOLTAGE_SEL        (0x01u)
#define Display0_LCDDAC_CONT_DRIVE         (0x08u)
#define Display0_LCDDAC_CONT_DRIVE_MASK    (~0x08u)

/* LCD Driver Control Register Bits */
#define Display0_LCDDRV_DISPLAY_BLNK       (0x01u)
#define Display0_LCDDRV_MODE0_MASK         (0x02u)
#define Display0_LCDDRV_MODE0_SHIFT        (0x01u)
#define Display0_LCDDRV_INVERT             (0x04u)
#define Display0_LCDDRV_PTS                (0x08u)
#define Display0_LCDDRV_BYPASS_EN          (0x10u)

#if(Display0_POWER_MODE == Display0__LOW_POWER_32XTAL)
    #define Display0_ONE_PPS_EN            (0x10u)
#endif /* Display0_POWER_MODE == Display0__LOW_POWER_32XTAL */

#if(Display0_POWER_MODE != Display0__NO_SLEEP)

    /* LCD Timer Control Register Bits */
    #define Display0_TIMER_EN                  (0x01u)
    #define Display0_TIMER_ILO_SEL             (0x00u)
    #define Display0_TIMER_32XTAL_SEL          (0x02u)
    #define Display0_TIMER_CLK_SEL_MASK        (0x02u)
    #define Display0_TIMER_PERIOD_MASK         (0xFCu)
    #define Display0_TIMER_PERIOD_SHIFT        (0x02u)

    #define Display0_TIMER_PERIOD              (8u)

#endif /* Display0_POWER_MODE != Display0__NO_SLEEP */

/* UDB Control Register bits */
#define Display0_CNTL_CLK_EN               (0x01u)
#define Display0_CNTL_CLK_EN_MASK          (~Display0_CNTL_CLK_EN)
#define Display0_CNTL_MODE_SHIFT           (0x01u)
#define Display0_CNTL_MODE_MASK            (~0x06u)
#define Display0_CNTL_FRAME_DONE           (0x08u)
#define Display0_CNTL_FRAME_DONE_MASK      (~Display0_CNTL_FRAME_DONE)


#endif  /* CY_SEGLCD_Display0_H */

/* [] END OF FILE */
