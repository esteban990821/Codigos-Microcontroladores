;
; File Name: cyfitteriar.inc
; 
; PSoC Creator  4.2
;
; Description:
; 
;
;-------------------------------------------------------------------------------
; Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions, 
; disclaimers, and limitations in the end user license agreement accompanying 
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

#ifndef INCLUDED_CYFITTERIAR_INC
#define INCLUDED_CYFITTERIAR_INC
    INCLUDE cydeviceiar.inc
    INCLUDE cydeviceiar_trm.inc

/* D0 */
D0__0__INTTYPE EQU CYREG_PICU1_INTTYPE2
D0__0__MASK EQU 0x04
D0__0__PC EQU CYREG_PRT1_PC2
D0__0__PORT EQU 1
D0__0__SHIFT EQU 2
D0__AG EQU CYREG_PRT1_AG
D0__AMUX EQU CYREG_PRT1_AMUX
D0__BIE EQU CYREG_PRT1_BIE
D0__BIT_MASK EQU CYREG_PRT1_BIT_MASK
D0__BYP EQU CYREG_PRT1_BYP
D0__CTL EQU CYREG_PRT1_CTL
D0__DM0 EQU CYREG_PRT1_DM0
D0__DM1 EQU CYREG_PRT1_DM1
D0__DM2 EQU CYREG_PRT1_DM2
D0__DR EQU CYREG_PRT1_DR
D0__INP_DIS EQU CYREG_PRT1_INP_DIS
D0__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
D0__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
D0__LCD_EN EQU CYREG_PRT1_LCD_EN
D0__MASK EQU 0x04
D0__PORT EQU 1
D0__PRT EQU CYREG_PRT1_PRT
D0__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
D0__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
D0__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
D0__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
D0__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
D0__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
D0__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
D0__PS EQU CYREG_PRT1_PS
D0__SHIFT EQU 2
D0__SLW EQU CYREG_PRT1_SLW

/* D1 */
D1__0__INTTYPE EQU CYREG_PICU1_INTTYPE4
D1__0__MASK EQU 0x10
D1__0__PC EQU CYREG_PRT1_PC4
D1__0__PORT EQU 1
D1__0__SHIFT EQU 4
D1__AG EQU CYREG_PRT1_AG
D1__AMUX EQU CYREG_PRT1_AMUX
D1__BIE EQU CYREG_PRT1_BIE
D1__BIT_MASK EQU CYREG_PRT1_BIT_MASK
D1__BYP EQU CYREG_PRT1_BYP
D1__CTL EQU CYREG_PRT1_CTL
D1__DM0 EQU CYREG_PRT1_DM0
D1__DM1 EQU CYREG_PRT1_DM1
D1__DM2 EQU CYREG_PRT1_DM2
D1__DR EQU CYREG_PRT1_DR
D1__INP_DIS EQU CYREG_PRT1_INP_DIS
D1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
D1__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
D1__LCD_EN EQU CYREG_PRT1_LCD_EN
D1__MASK EQU 0x10
D1__PORT EQU 1
D1__PRT EQU CYREG_PRT1_PRT
D1__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
D1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
D1__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
D1__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
D1__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
D1__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
D1__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
D1__PS EQU CYREG_PRT1_PS
D1__SHIFT EQU 4
D1__SLW EQU CYREG_PRT1_SLW

/* Display1_Com */
Display1_Com__0__INTTYPE EQU CYREG_PICU0_INTTYPE0
Display1_Com__0__MASK EQU 0x01
Display1_Com__0__PC EQU CYREG_PRT0_PC0
Display1_Com__0__PORT EQU 0
Display1_Com__0__SHIFT EQU 0
Display1_Com__AG EQU CYREG_PRT0_AG
Display1_Com__AMUX EQU CYREG_PRT0_AMUX
Display1_Com__BIE EQU CYREG_PRT0_BIE
Display1_Com__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Display1_Com__BYP EQU CYREG_PRT0_BYP
Display1_Com__CTL EQU CYREG_PRT0_CTL
Display1_Com__DM0 EQU CYREG_PRT0_DM0
Display1_Com__DM1 EQU CYREG_PRT0_DM1
Display1_Com__DM2 EQU CYREG_PRT0_DM2
Display1_Com__DR EQU CYREG_PRT0_DR
Display1_Com__INP_DIS EQU CYREG_PRT0_INP_DIS
Display1_Com__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
Display1_Com__LCD_COM_MASK__0 EQU 0x01
Display1_Com__LCD_COM_MASK__1 EQU 0x00
Display1_Com__LCD_COM_MASK__12 EQU 0x00
Display1_Com__LCD_COM_MASK__15 EQU 0x00
Display1_Com__LCD_COM_MASK__2 EQU 0x00
Display1_Com__LCD_COM_MASK__3 EQU 0x00
Display1_Com__LCD_COM_MASK__4 EQU 0x00
Display1_Com__LCD_COM_MASK__5 EQU 0x00
Display1_Com__LCD_COM_MASK__6 EQU 0x00
Display1_Com__LCD_COM_PIN__0 EQU 0
Display1_Com__LCD_COM_PORT__0 EQU 0
Display1_Com__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Display1_Com__LCD_EN EQU CYREG_PRT0_LCD_EN
Display1_Com__LCD_SEG_MASK__0 EQU 0x00
Display1_Com__LCD_SEG_MASK__1 EQU 0x00
Display1_Com__LCD_SEG_MASK__12 EQU 0x00
Display1_Com__LCD_SEG_MASK__15 EQU 0x00
Display1_Com__LCD_SEG_MASK__2 EQU 0x00
Display1_Com__LCD_SEG_MASK__3 EQU 0x00
Display1_Com__LCD_SEG_MASK__4 EQU 0x00
Display1_Com__LCD_SEG_MASK__5 EQU 0x00
Display1_Com__LCD_SEG_MASK__6 EQU 0x00
Display1_Com__MASK EQU 0x01
Display1_Com__PORT EQU 0
Display1_Com__PRT EQU CYREG_PRT0_PRT
Display1_Com__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Display1_Com__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Display1_Com__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Display1_Com__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Display1_Com__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Display1_Com__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Display1_Com__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Display1_Com__PS EQU CYREG_PRT0_PS
Display1_Com__SHIFT EQU 0
Display1_Com__SLW EQU CYREG_PRT0_SLW

/* Display1_GCom */
Display1_GCom__0__INTTYPE EQU CYREG_PICU3_INTTYPE0
Display1_GCom__0__MASK EQU 0x01
Display1_GCom__0__PC EQU CYREG_PRT3_PC0
Display1_GCom__0__PORT EQU 3
Display1_GCom__0__SHIFT EQU 0
Display1_GCom__AG EQU CYREG_PRT3_AG
Display1_GCom__AMUX EQU CYREG_PRT3_AMUX
Display1_GCom__BIE EQU CYREG_PRT3_BIE
Display1_GCom__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Display1_GCom__BYP EQU CYREG_PRT3_BYP
Display1_GCom__CTL EQU CYREG_PRT3_CTL
Display1_GCom__DM0 EQU CYREG_PRT3_DM0
Display1_GCom__DM1 EQU CYREG_PRT3_DM1
Display1_GCom__DM2 EQU CYREG_PRT3_DM2
Display1_GCom__DR EQU CYREG_PRT3_DR
Display1_GCom__INP_DIS EQU CYREG_PRT3_INP_DIS
Display1_GCom__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
Display1_GCom__LCD_COM_MASK__0 EQU 0x00
Display1_GCom__LCD_COM_MASK__1 EQU 0x00
Display1_GCom__LCD_COM_MASK__12 EQU 0x00
Display1_GCom__LCD_COM_MASK__15 EQU 0x00
Display1_GCom__LCD_COM_MASK__2 EQU 0x00
Display1_GCom__LCD_COM_MASK__3 EQU 0x01
Display1_GCom__LCD_COM_MASK__4 EQU 0x00
Display1_GCom__LCD_COM_MASK__5 EQU 0x00
Display1_GCom__LCD_COM_MASK__6 EQU 0x00
Display1_GCom__LCD_COM_PIN__0 EQU 0
Display1_GCom__LCD_COM_PORT__0 EQU 3
Display1_GCom__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Display1_GCom__LCD_EN EQU CYREG_PRT3_LCD_EN
Display1_GCom__LCD_SEG_MASK__0 EQU 0x00
Display1_GCom__LCD_SEG_MASK__1 EQU 0x00
Display1_GCom__LCD_SEG_MASK__12 EQU 0x00
Display1_GCom__LCD_SEG_MASK__15 EQU 0x00
Display1_GCom__LCD_SEG_MASK__2 EQU 0x00
Display1_GCom__LCD_SEG_MASK__3 EQU 0x00
Display1_GCom__LCD_SEG_MASK__4 EQU 0x00
Display1_GCom__LCD_SEG_MASK__5 EQU 0x00
Display1_GCom__LCD_SEG_MASK__6 EQU 0x00
Display1_GCom__MASK EQU 0x01
Display1_GCom__PORT EQU 3
Display1_GCom__PRT EQU CYREG_PRT3_PRT
Display1_GCom__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Display1_GCom__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Display1_GCom__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Display1_GCom__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Display1_GCom__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Display1_GCom__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Display1_GCom__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Display1_GCom__PS EQU CYREG_PRT3_PS
Display1_GCom__SHIFT EQU 0
Display1_GCom__SLW EQU CYREG_PRT3_SLW

/* Display1_InClock */
Display1_InClock__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
Display1_InClock__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
Display1_InClock__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
Display1_InClock__CFG2_SRC_SEL_MASK EQU 0x07
Display1_InClock__INDEX EQU 0x00
Display1_InClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Display1_InClock__PM_ACT_MSK EQU 0x01
Display1_InClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Display1_InClock__PM_STBY_MSK EQU 0x01

/* Display1_Lcd_Dma */
Display1_Lcd_Dma__DRQ_CTL EQU CYREG_IDMUX_DRQ_CTL0
Display1_Lcd_Dma__DRQ_NUMBER EQU 0
Display1_Lcd_Dma__NUMBEROF_TDS EQU 0
Display1_Lcd_Dma__PRIORITY EQU 2
Display1_Lcd_Dma__TERMIN_EN EQU 0
Display1_Lcd_Dma__TERMIN_SEL EQU 0
Display1_Lcd_Dma__TERMOUT0_EN EQU 1
Display1_Lcd_Dma__TERMOUT0_SEL EQU 0
Display1_Lcd_Dma__TERMOUT1_EN EQU 0
Display1_Lcd_Dma__TERMOUT1_SEL EQU 0

/* Miscellaneous */
Display1_LCD_ISR__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
Display1_LCD_ISR__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
Display1_LCD_ISR__INTC_MASK EQU 0x01
Display1_LCD_ISR__INTC_NUMBER EQU 0
Display1_LCD_ISR__INTC_PRIOR_NUM EQU 7
Display1_LCD_ISR__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_0
Display1_LCD_ISR__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
Display1_LCD_ISR__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0
Display1_Seg__0__AG EQU CYREG_PRT0_AG
Display1_Seg__0__AMUX EQU CYREG_PRT0_AMUX
Display1_Seg__0__BIE EQU CYREG_PRT0_BIE
Display1_Seg__0__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Display1_Seg__0__BYP EQU CYREG_PRT0_BYP
Display1_Seg__0__CTL EQU CYREG_PRT0_CTL
Display1_Seg__0__DM0 EQU CYREG_PRT0_DM0
Display1_Seg__0__DM1 EQU CYREG_PRT0_DM1
Display1_Seg__0__DM2 EQU CYREG_PRT0_DM2
Display1_Seg__0__DR EQU CYREG_PRT0_DR
Display1_Seg__0__INP_DIS EQU CYREG_PRT0_INP_DIS
Display1_Seg__0__INTTYPE EQU CYREG_PICU0_INTTYPE1
Display1_Seg__0__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Display1_Seg__0__LCD_EN EQU CYREG_PRT0_LCD_EN
Display1_Seg__0__MASK EQU 0x02
Display1_Seg__0__PC EQU CYREG_PRT0_PC1
Display1_Seg__0__PORT EQU 0
Display1_Seg__0__PRT EQU CYREG_PRT0_PRT
Display1_Seg__0__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Display1_Seg__0__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Display1_Seg__0__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Display1_Seg__0__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Display1_Seg__0__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Display1_Seg__0__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Display1_Seg__0__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Display1_Seg__0__PS EQU CYREG_PRT0_PS
Display1_Seg__0__SHIFT EQU 1
Display1_Seg__0__SLW EQU CYREG_PRT0_SLW
Display1_Seg__1__AG EQU CYREG_PRT0_AG
Display1_Seg__1__AMUX EQU CYREG_PRT0_AMUX
Display1_Seg__1__BIE EQU CYREG_PRT0_BIE
Display1_Seg__1__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Display1_Seg__1__BYP EQU CYREG_PRT0_BYP
Display1_Seg__1__CTL EQU CYREG_PRT0_CTL
Display1_Seg__1__DM0 EQU CYREG_PRT0_DM0
Display1_Seg__1__DM1 EQU CYREG_PRT0_DM1
Display1_Seg__1__DM2 EQU CYREG_PRT0_DM2
Display1_Seg__1__DR EQU CYREG_PRT0_DR
Display1_Seg__1__INP_DIS EQU CYREG_PRT0_INP_DIS
Display1_Seg__1__INTTYPE EQU CYREG_PICU0_INTTYPE2
Display1_Seg__1__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Display1_Seg__1__LCD_EN EQU CYREG_PRT0_LCD_EN
Display1_Seg__1__MASK EQU 0x04
Display1_Seg__1__PC EQU CYREG_PRT0_PC2
Display1_Seg__1__PORT EQU 0
Display1_Seg__1__PRT EQU CYREG_PRT0_PRT
Display1_Seg__1__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Display1_Seg__1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Display1_Seg__1__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Display1_Seg__1__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Display1_Seg__1__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Display1_Seg__1__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Display1_Seg__1__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Display1_Seg__1__PS EQU CYREG_PRT0_PS
Display1_Seg__1__SHIFT EQU 2
Display1_Seg__1__SLW EQU CYREG_PRT0_SLW
Display1_Seg__10__AG EQU CYREG_PRT3_AG
Display1_Seg__10__AMUX EQU CYREG_PRT3_AMUX
Display1_Seg__10__BIE EQU CYREG_PRT3_BIE
Display1_Seg__10__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Display1_Seg__10__BYP EQU CYREG_PRT3_BYP
Display1_Seg__10__CTL EQU CYREG_PRT3_CTL
Display1_Seg__10__DM0 EQU CYREG_PRT3_DM0
Display1_Seg__10__DM1 EQU CYREG_PRT3_DM1
Display1_Seg__10__DM2 EQU CYREG_PRT3_DM2
Display1_Seg__10__DR EQU CYREG_PRT3_DR
Display1_Seg__10__INP_DIS EQU CYREG_PRT3_INP_DIS
Display1_Seg__10__INTTYPE EQU CYREG_PICU3_INTTYPE4
Display1_Seg__10__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Display1_Seg__10__LCD_EN EQU CYREG_PRT3_LCD_EN
Display1_Seg__10__MASK EQU 0x10
Display1_Seg__10__PC EQU CYREG_PRT3_PC4
Display1_Seg__10__PORT EQU 3
Display1_Seg__10__PRT EQU CYREG_PRT3_PRT
Display1_Seg__10__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Display1_Seg__10__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Display1_Seg__10__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Display1_Seg__10__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Display1_Seg__10__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Display1_Seg__10__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Display1_Seg__10__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Display1_Seg__10__PS EQU CYREG_PRT3_PS
Display1_Seg__10__SHIFT EQU 4
Display1_Seg__10__SLW EQU CYREG_PRT3_SLW
Display1_Seg__11__AG EQU CYREG_PRT3_AG
Display1_Seg__11__AMUX EQU CYREG_PRT3_AMUX
Display1_Seg__11__BIE EQU CYREG_PRT3_BIE
Display1_Seg__11__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Display1_Seg__11__BYP EQU CYREG_PRT3_BYP
Display1_Seg__11__CTL EQU CYREG_PRT3_CTL
Display1_Seg__11__DM0 EQU CYREG_PRT3_DM0
Display1_Seg__11__DM1 EQU CYREG_PRT3_DM1
Display1_Seg__11__DM2 EQU CYREG_PRT3_DM2
Display1_Seg__11__DR EQU CYREG_PRT3_DR
Display1_Seg__11__INP_DIS EQU CYREG_PRT3_INP_DIS
Display1_Seg__11__INTTYPE EQU CYREG_PICU3_INTTYPE5
Display1_Seg__11__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Display1_Seg__11__LCD_EN EQU CYREG_PRT3_LCD_EN
Display1_Seg__11__MASK EQU 0x20
Display1_Seg__11__PC EQU CYREG_PRT3_PC5
Display1_Seg__11__PORT EQU 3
Display1_Seg__11__PRT EQU CYREG_PRT3_PRT
Display1_Seg__11__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Display1_Seg__11__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Display1_Seg__11__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Display1_Seg__11__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Display1_Seg__11__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Display1_Seg__11__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Display1_Seg__11__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Display1_Seg__11__PS EQU CYREG_PRT3_PS
Display1_Seg__11__SHIFT EQU 5
Display1_Seg__11__SLW EQU CYREG_PRT3_SLW
Display1_Seg__12__AG EQU CYREG_PRT3_AG
Display1_Seg__12__AMUX EQU CYREG_PRT3_AMUX
Display1_Seg__12__BIE EQU CYREG_PRT3_BIE
Display1_Seg__12__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Display1_Seg__12__BYP EQU CYREG_PRT3_BYP
Display1_Seg__12__CTL EQU CYREG_PRT3_CTL
Display1_Seg__12__DM0 EQU CYREG_PRT3_DM0
Display1_Seg__12__DM1 EQU CYREG_PRT3_DM1
Display1_Seg__12__DM2 EQU CYREG_PRT3_DM2
Display1_Seg__12__DR EQU CYREG_PRT3_DR
Display1_Seg__12__INP_DIS EQU CYREG_PRT3_INP_DIS
Display1_Seg__12__INTTYPE EQU CYREG_PICU3_INTTYPE6
Display1_Seg__12__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Display1_Seg__12__LCD_EN EQU CYREG_PRT3_LCD_EN
Display1_Seg__12__MASK EQU 0x40
Display1_Seg__12__PC EQU CYREG_PRT3_PC6
Display1_Seg__12__PORT EQU 3
Display1_Seg__12__PRT EQU CYREG_PRT3_PRT
Display1_Seg__12__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Display1_Seg__12__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Display1_Seg__12__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Display1_Seg__12__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Display1_Seg__12__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Display1_Seg__12__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Display1_Seg__12__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Display1_Seg__12__PS EQU CYREG_PRT3_PS
Display1_Seg__12__SHIFT EQU 6
Display1_Seg__12__SLW EQU CYREG_PRT3_SLW
Display1_Seg__13__AG EQU CYREG_PRT3_AG
Display1_Seg__13__AMUX EQU CYREG_PRT3_AMUX
Display1_Seg__13__BIE EQU CYREG_PRT3_BIE
Display1_Seg__13__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Display1_Seg__13__BYP EQU CYREG_PRT3_BYP
Display1_Seg__13__CTL EQU CYREG_PRT3_CTL
Display1_Seg__13__DM0 EQU CYREG_PRT3_DM0
Display1_Seg__13__DM1 EQU CYREG_PRT3_DM1
Display1_Seg__13__DM2 EQU CYREG_PRT3_DM2
Display1_Seg__13__DR EQU CYREG_PRT3_DR
Display1_Seg__13__INP_DIS EQU CYREG_PRT3_INP_DIS
Display1_Seg__13__INTTYPE EQU CYREG_PICU3_INTTYPE7
Display1_Seg__13__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Display1_Seg__13__LCD_EN EQU CYREG_PRT3_LCD_EN
Display1_Seg__13__MASK EQU 0x80
Display1_Seg__13__PC EQU CYREG_PRT3_PC7
Display1_Seg__13__PORT EQU 3
Display1_Seg__13__PRT EQU CYREG_PRT3_PRT
Display1_Seg__13__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Display1_Seg__13__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Display1_Seg__13__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Display1_Seg__13__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Display1_Seg__13__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Display1_Seg__13__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Display1_Seg__13__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Display1_Seg__13__PS EQU CYREG_PRT3_PS
Display1_Seg__13__SHIFT EQU 7
Display1_Seg__13__SLW EQU CYREG_PRT3_SLW
Display1_Seg__2__AG EQU CYREG_PRT0_AG
Display1_Seg__2__AMUX EQU CYREG_PRT0_AMUX
Display1_Seg__2__BIE EQU CYREG_PRT0_BIE
Display1_Seg__2__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Display1_Seg__2__BYP EQU CYREG_PRT0_BYP
Display1_Seg__2__CTL EQU CYREG_PRT0_CTL
Display1_Seg__2__DM0 EQU CYREG_PRT0_DM0
Display1_Seg__2__DM1 EQU CYREG_PRT0_DM1
Display1_Seg__2__DM2 EQU CYREG_PRT0_DM2
Display1_Seg__2__DR EQU CYREG_PRT0_DR
Display1_Seg__2__INP_DIS EQU CYREG_PRT0_INP_DIS
Display1_Seg__2__INTTYPE EQU CYREG_PICU0_INTTYPE3
Display1_Seg__2__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Display1_Seg__2__LCD_EN EQU CYREG_PRT0_LCD_EN
Display1_Seg__2__MASK EQU 0x08
Display1_Seg__2__PC EQU CYREG_PRT0_PC3
Display1_Seg__2__PORT EQU 0
Display1_Seg__2__PRT EQU CYREG_PRT0_PRT
Display1_Seg__2__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Display1_Seg__2__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Display1_Seg__2__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Display1_Seg__2__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Display1_Seg__2__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Display1_Seg__2__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Display1_Seg__2__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Display1_Seg__2__PS EQU CYREG_PRT0_PS
Display1_Seg__2__SHIFT EQU 3
Display1_Seg__2__SLW EQU CYREG_PRT0_SLW
Display1_Seg__3__AG EQU CYREG_PRT0_AG
Display1_Seg__3__AMUX EQU CYREG_PRT0_AMUX
Display1_Seg__3__BIE EQU CYREG_PRT0_BIE
Display1_Seg__3__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Display1_Seg__3__BYP EQU CYREG_PRT0_BYP
Display1_Seg__3__CTL EQU CYREG_PRT0_CTL
Display1_Seg__3__DM0 EQU CYREG_PRT0_DM0
Display1_Seg__3__DM1 EQU CYREG_PRT0_DM1
Display1_Seg__3__DM2 EQU CYREG_PRT0_DM2
Display1_Seg__3__DR EQU CYREG_PRT0_DR
Display1_Seg__3__INP_DIS EQU CYREG_PRT0_INP_DIS
Display1_Seg__3__INTTYPE EQU CYREG_PICU0_INTTYPE4
Display1_Seg__3__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Display1_Seg__3__LCD_EN EQU CYREG_PRT0_LCD_EN
Display1_Seg__3__MASK EQU 0x10
Display1_Seg__3__PC EQU CYREG_PRT0_PC4
Display1_Seg__3__PORT EQU 0
Display1_Seg__3__PRT EQU CYREG_PRT0_PRT
Display1_Seg__3__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Display1_Seg__3__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Display1_Seg__3__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Display1_Seg__3__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Display1_Seg__3__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Display1_Seg__3__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Display1_Seg__3__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Display1_Seg__3__PS EQU CYREG_PRT0_PS
Display1_Seg__3__SHIFT EQU 4
Display1_Seg__3__SLW EQU CYREG_PRT0_SLW
Display1_Seg__4__AG EQU CYREG_PRT0_AG
Display1_Seg__4__AMUX EQU CYREG_PRT0_AMUX
Display1_Seg__4__BIE EQU CYREG_PRT0_BIE
Display1_Seg__4__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Display1_Seg__4__BYP EQU CYREG_PRT0_BYP
Display1_Seg__4__CTL EQU CYREG_PRT0_CTL
Display1_Seg__4__DM0 EQU CYREG_PRT0_DM0
Display1_Seg__4__DM1 EQU CYREG_PRT0_DM1
Display1_Seg__4__DM2 EQU CYREG_PRT0_DM2
Display1_Seg__4__DR EQU CYREG_PRT0_DR
Display1_Seg__4__INP_DIS EQU CYREG_PRT0_INP_DIS
Display1_Seg__4__INTTYPE EQU CYREG_PICU0_INTTYPE5
Display1_Seg__4__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Display1_Seg__4__LCD_EN EQU CYREG_PRT0_LCD_EN
Display1_Seg__4__MASK EQU 0x20
Display1_Seg__4__PC EQU CYREG_PRT0_PC5
Display1_Seg__4__PORT EQU 0
Display1_Seg__4__PRT EQU CYREG_PRT0_PRT
Display1_Seg__4__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Display1_Seg__4__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Display1_Seg__4__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Display1_Seg__4__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Display1_Seg__4__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Display1_Seg__4__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Display1_Seg__4__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Display1_Seg__4__PS EQU CYREG_PRT0_PS
Display1_Seg__4__SHIFT EQU 5
Display1_Seg__4__SLW EQU CYREG_PRT0_SLW
Display1_Seg__5__AG EQU CYREG_PRT0_AG
Display1_Seg__5__AMUX EQU CYREG_PRT0_AMUX
Display1_Seg__5__BIE EQU CYREG_PRT0_BIE
Display1_Seg__5__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Display1_Seg__5__BYP EQU CYREG_PRT0_BYP
Display1_Seg__5__CTL EQU CYREG_PRT0_CTL
Display1_Seg__5__DM0 EQU CYREG_PRT0_DM0
Display1_Seg__5__DM1 EQU CYREG_PRT0_DM1
Display1_Seg__5__DM2 EQU CYREG_PRT0_DM2
Display1_Seg__5__DR EQU CYREG_PRT0_DR
Display1_Seg__5__INP_DIS EQU CYREG_PRT0_INP_DIS
Display1_Seg__5__INTTYPE EQU CYREG_PICU0_INTTYPE6
Display1_Seg__5__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Display1_Seg__5__LCD_EN EQU CYREG_PRT0_LCD_EN
Display1_Seg__5__MASK EQU 0x40
Display1_Seg__5__PC EQU CYREG_PRT0_PC6
Display1_Seg__5__PORT EQU 0
Display1_Seg__5__PRT EQU CYREG_PRT0_PRT
Display1_Seg__5__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Display1_Seg__5__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Display1_Seg__5__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Display1_Seg__5__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Display1_Seg__5__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Display1_Seg__5__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Display1_Seg__5__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Display1_Seg__5__PS EQU CYREG_PRT0_PS
Display1_Seg__5__SHIFT EQU 6
Display1_Seg__5__SLW EQU CYREG_PRT0_SLW
Display1_Seg__6__AG EQU CYREG_PRT0_AG
Display1_Seg__6__AMUX EQU CYREG_PRT0_AMUX
Display1_Seg__6__BIE EQU CYREG_PRT0_BIE
Display1_Seg__6__BIT_MASK EQU CYREG_PRT0_BIT_MASK
Display1_Seg__6__BYP EQU CYREG_PRT0_BYP
Display1_Seg__6__CTL EQU CYREG_PRT0_CTL
Display1_Seg__6__DM0 EQU CYREG_PRT0_DM0
Display1_Seg__6__DM1 EQU CYREG_PRT0_DM1
Display1_Seg__6__DM2 EQU CYREG_PRT0_DM2
Display1_Seg__6__DR EQU CYREG_PRT0_DR
Display1_Seg__6__INP_DIS EQU CYREG_PRT0_INP_DIS
Display1_Seg__6__INTTYPE EQU CYREG_PICU0_INTTYPE7
Display1_Seg__6__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
Display1_Seg__6__LCD_EN EQU CYREG_PRT0_LCD_EN
Display1_Seg__6__MASK EQU 0x80
Display1_Seg__6__PC EQU CYREG_PRT0_PC7
Display1_Seg__6__PORT EQU 0
Display1_Seg__6__PRT EQU CYREG_PRT0_PRT
Display1_Seg__6__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
Display1_Seg__6__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
Display1_Seg__6__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
Display1_Seg__6__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
Display1_Seg__6__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
Display1_Seg__6__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
Display1_Seg__6__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
Display1_Seg__6__PS EQU CYREG_PRT0_PS
Display1_Seg__6__SHIFT EQU 7
Display1_Seg__6__SLW EQU CYREG_PRT0_SLW
Display1_Seg__7__AG EQU CYREG_PRT3_AG
Display1_Seg__7__AMUX EQU CYREG_PRT3_AMUX
Display1_Seg__7__BIE EQU CYREG_PRT3_BIE
Display1_Seg__7__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Display1_Seg__7__BYP EQU CYREG_PRT3_BYP
Display1_Seg__7__CTL EQU CYREG_PRT3_CTL
Display1_Seg__7__DM0 EQU CYREG_PRT3_DM0
Display1_Seg__7__DM1 EQU CYREG_PRT3_DM1
Display1_Seg__7__DM2 EQU CYREG_PRT3_DM2
Display1_Seg__7__DR EQU CYREG_PRT3_DR
Display1_Seg__7__INP_DIS EQU CYREG_PRT3_INP_DIS
Display1_Seg__7__INTTYPE EQU CYREG_PICU3_INTTYPE1
Display1_Seg__7__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Display1_Seg__7__LCD_EN EQU CYREG_PRT3_LCD_EN
Display1_Seg__7__MASK EQU 0x02
Display1_Seg__7__PC EQU CYREG_PRT3_PC1
Display1_Seg__7__PORT EQU 3
Display1_Seg__7__PRT EQU CYREG_PRT3_PRT
Display1_Seg__7__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Display1_Seg__7__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Display1_Seg__7__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Display1_Seg__7__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Display1_Seg__7__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Display1_Seg__7__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Display1_Seg__7__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Display1_Seg__7__PS EQU CYREG_PRT3_PS
Display1_Seg__7__SHIFT EQU 1
Display1_Seg__7__SLW EQU CYREG_PRT3_SLW
Display1_Seg__8__AG EQU CYREG_PRT3_AG
Display1_Seg__8__AMUX EQU CYREG_PRT3_AMUX
Display1_Seg__8__BIE EQU CYREG_PRT3_BIE
Display1_Seg__8__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Display1_Seg__8__BYP EQU CYREG_PRT3_BYP
Display1_Seg__8__CTL EQU CYREG_PRT3_CTL
Display1_Seg__8__DM0 EQU CYREG_PRT3_DM0
Display1_Seg__8__DM1 EQU CYREG_PRT3_DM1
Display1_Seg__8__DM2 EQU CYREG_PRT3_DM2
Display1_Seg__8__DR EQU CYREG_PRT3_DR
Display1_Seg__8__INP_DIS EQU CYREG_PRT3_INP_DIS
Display1_Seg__8__INTTYPE EQU CYREG_PICU3_INTTYPE2
Display1_Seg__8__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Display1_Seg__8__LCD_EN EQU CYREG_PRT3_LCD_EN
Display1_Seg__8__MASK EQU 0x04
Display1_Seg__8__PC EQU CYREG_PRT3_PC2
Display1_Seg__8__PORT EQU 3
Display1_Seg__8__PRT EQU CYREG_PRT3_PRT
Display1_Seg__8__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Display1_Seg__8__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Display1_Seg__8__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Display1_Seg__8__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Display1_Seg__8__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Display1_Seg__8__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Display1_Seg__8__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Display1_Seg__8__PS EQU CYREG_PRT3_PS
Display1_Seg__8__SHIFT EQU 2
Display1_Seg__8__SLW EQU CYREG_PRT3_SLW
Display1_Seg__9__AG EQU CYREG_PRT3_AG
Display1_Seg__9__AMUX EQU CYREG_PRT3_AMUX
Display1_Seg__9__BIE EQU CYREG_PRT3_BIE
Display1_Seg__9__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Display1_Seg__9__BYP EQU CYREG_PRT3_BYP
Display1_Seg__9__CTL EQU CYREG_PRT3_CTL
Display1_Seg__9__DM0 EQU CYREG_PRT3_DM0
Display1_Seg__9__DM1 EQU CYREG_PRT3_DM1
Display1_Seg__9__DM2 EQU CYREG_PRT3_DM2
Display1_Seg__9__DR EQU CYREG_PRT3_DR
Display1_Seg__9__INP_DIS EQU CYREG_PRT3_INP_DIS
Display1_Seg__9__INTTYPE EQU CYREG_PICU3_INTTYPE3
Display1_Seg__9__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Display1_Seg__9__LCD_EN EQU CYREG_PRT3_LCD_EN
Display1_Seg__9__MASK EQU 0x08
Display1_Seg__9__PC EQU CYREG_PRT3_PC3
Display1_Seg__9__PORT EQU 3
Display1_Seg__9__PRT EQU CYREG_PRT3_PRT
Display1_Seg__9__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Display1_Seg__9__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Display1_Seg__9__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Display1_Seg__9__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Display1_Seg__9__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Display1_Seg__9__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Display1_Seg__9__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Display1_Seg__9__PS EQU CYREG_PRT3_PS
Display1_Seg__9__SHIFT EQU 3
Display1_Seg__9__SLW EQU CYREG_PRT3_SLW
Display1_Seg__LCD_COM_MASK__0 EQU 0x00
Display1_Seg__LCD_COM_MASK__1 EQU 0x00
Display1_Seg__LCD_COM_MASK__12 EQU 0x00
Display1_Seg__LCD_COM_MASK__15 EQU 0x00
Display1_Seg__LCD_COM_MASK__2 EQU 0x00
Display1_Seg__LCD_COM_MASK__3 EQU 0x00
Display1_Seg__LCD_COM_MASK__4 EQU 0x00
Display1_Seg__LCD_COM_MASK__5 EQU 0x00
Display1_Seg__LCD_COM_MASK__6 EQU 0x00
Display1_Seg__LCD_SEG_MASK__0 EQU 0xFE
Display1_Seg__LCD_SEG_MASK__1 EQU 0x00
Display1_Seg__LCD_SEG_MASK__12 EQU 0x00
Display1_Seg__LCD_SEG_MASK__15 EQU 0x00
Display1_Seg__LCD_SEG_MASK__2 EQU 0x00
Display1_Seg__LCD_SEG_MASK__3 EQU 0xFE
Display1_Seg__LCD_SEG_MASK__4 EQU 0x00
Display1_Seg__LCD_SEG_MASK__5 EQU 0x00
Display1_Seg__LCD_SEG_MASK__6 EQU 0x00
Display1_Seg__LCD_SEG_PIN__0 EQU 1
Display1_Seg__LCD_SEG_PIN__1 EQU 2
Display1_Seg__LCD_SEG_PIN__10 EQU 4
Display1_Seg__LCD_SEG_PIN__11 EQU 5
Display1_Seg__LCD_SEG_PIN__12 EQU 6
Display1_Seg__LCD_SEG_PIN__13 EQU 7
Display1_Seg__LCD_SEG_PIN__2 EQU 3
Display1_Seg__LCD_SEG_PIN__3 EQU 4
Display1_Seg__LCD_SEG_PIN__4 EQU 5
Display1_Seg__LCD_SEG_PIN__5 EQU 6
Display1_Seg__LCD_SEG_PIN__6 EQU 7
Display1_Seg__LCD_SEG_PIN__7 EQU 1
Display1_Seg__LCD_SEG_PIN__8 EQU 2
Display1_Seg__LCD_SEG_PIN__9 EQU 3
Display1_Seg__LCD_SEG_PORT__0 EQU 0
Display1_Seg__LCD_SEG_PORT__1 EQU 0
Display1_Seg__LCD_SEG_PORT__10 EQU 3
Display1_Seg__LCD_SEG_PORT__11 EQU 3
Display1_Seg__LCD_SEG_PORT__12 EQU 3
Display1_Seg__LCD_SEG_PORT__13 EQU 3
Display1_Seg__LCD_SEG_PORT__2 EQU 0
Display1_Seg__LCD_SEG_PORT__3 EQU 0
Display1_Seg__LCD_SEG_PORT__4 EQU 0
Display1_Seg__LCD_SEG_PORT__5 EQU 0
Display1_Seg__LCD_SEG_PORT__6 EQU 0
Display1_Seg__LCD_SEG_PORT__7 EQU 3
Display1_Seg__LCD_SEG_PORT__8 EQU 3
Display1_Seg__LCD_SEG_PORT__9 EQU 3
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 18
CYDEV_CHIP_DIE_PSOC5LP EQU 2
CYDEV_CHIP_DIE_PSOC5TM EQU 3
CYDEV_CHIP_DIE_TMA4 EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 5
CYDEV_CHIP_FAMILY_FM3 EQU 6
CYDEV_CHIP_FAMILY_FM4 EQU 7
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_PSOC6 EQU 4
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E161069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 18
CYDEV_CHIP_MEMBER_4D EQU 13
CYDEV_CHIP_MEMBER_4E EQU 6
CYDEV_CHIP_MEMBER_4F EQU 19
CYDEV_CHIP_MEMBER_4G EQU 4
CYDEV_CHIP_MEMBER_4H EQU 17
CYDEV_CHIP_MEMBER_4I EQU 23
CYDEV_CHIP_MEMBER_4J EQU 14
CYDEV_CHIP_MEMBER_4K EQU 15
CYDEV_CHIP_MEMBER_4L EQU 22
CYDEV_CHIP_MEMBER_4M EQU 21
CYDEV_CHIP_MEMBER_4N EQU 10
CYDEV_CHIP_MEMBER_4O EQU 7
CYDEV_CHIP_MEMBER_4P EQU 20
CYDEV_CHIP_MEMBER_4Q EQU 12
CYDEV_CHIP_MEMBER_4R EQU 8
CYDEV_CHIP_MEMBER_4S EQU 11
CYDEV_CHIP_MEMBER_4T EQU 9
CYDEV_CHIP_MEMBER_4U EQU 5
CYDEV_CHIP_MEMBER_4V EQU 16
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_MEMBER_5B EQU 2
CYDEV_CHIP_MEMBER_6A EQU 24
CYDEV_CHIP_MEMBER_FM3 EQU 28
CYDEV_CHIP_MEMBER_FM4 EQU 29
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 25
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 26
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 27
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4R_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4S_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4T_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4V_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_6A_ES EQU 17
CYDEV_CHIP_REVISION_6A_NO_UDB EQU 33
CYDEV_CHIP_REVISION_6A_PRODUCTION EQU 33
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x200
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x00000000
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000001
CYDEV_BOOTLOADER_ENABLE EQU 0

#endif /* INCLUDED_CYFITTERIAR_INC */
