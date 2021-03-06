;
; File Name: cyfitterrv.inc
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

    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv.inc
    GET cydevicerv_trm.inc

; PWM
PWM_PWMUDB_genblk8_stsreg__0__MASK EQU 0x01
PWM_PWMUDB_genblk8_stsreg__0__POS EQU 0
PWM_PWMUDB_genblk8_stsreg__1__MASK EQU 0x02
PWM_PWMUDB_genblk8_stsreg__1__POS EQU 1
PWM_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB08_09_ACTL
PWM_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG EQU CYREG_B0_UDB08_09_ST
PWM_PWMUDB_genblk8_stsreg__2__MASK EQU 0x04
PWM_PWMUDB_genblk8_stsreg__2__POS EQU 2
PWM_PWMUDB_genblk8_stsreg__3__MASK EQU 0x08
PWM_PWMUDB_genblk8_stsreg__3__POS EQU 3
PWM_PWMUDB_genblk8_stsreg__MASK EQU 0x0F
PWM_PWMUDB_genblk8_stsreg__MASK_REG EQU CYREG_B0_UDB08_MSK
PWM_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB08_ACTL
PWM_PWMUDB_genblk8_stsreg__STATUS_REG EQU CYREG_B0_UDB08_ST
PWM_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG EQU CYREG_B0_UDB08_09_A0
PWM_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG EQU CYREG_B0_UDB08_09_A1
PWM_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG EQU CYREG_B0_UDB08_09_D0
PWM_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG EQU CYREG_B0_UDB08_09_D1
PWM_PWMUDB_sP8_pwmdp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB08_09_ACTL
PWM_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG EQU CYREG_B0_UDB08_09_F0
PWM_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG EQU CYREG_B0_UDB08_09_F1
PWM_PWMUDB_sP8_pwmdp_u0__A0_A1_REG EQU CYREG_B0_UDB08_A0_A1
PWM_PWMUDB_sP8_pwmdp_u0__A0_REG EQU CYREG_B0_UDB08_A0
PWM_PWMUDB_sP8_pwmdp_u0__A1_REG EQU CYREG_B0_UDB08_A1
PWM_PWMUDB_sP8_pwmdp_u0__D0_D1_REG EQU CYREG_B0_UDB08_D0_D1
PWM_PWMUDB_sP8_pwmdp_u0__D0_REG EQU CYREG_B0_UDB08_D0
PWM_PWMUDB_sP8_pwmdp_u0__D1_REG EQU CYREG_B0_UDB08_D1
PWM_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB08_ACTL
PWM_PWMUDB_sP8_pwmdp_u0__F0_F1_REG EQU CYREG_B0_UDB08_F0_F1
PWM_PWMUDB_sP8_pwmdp_u0__F0_REG EQU CYREG_B0_UDB08_F0
PWM_PWMUDB_sP8_pwmdp_u0__F1_REG EQU CYREG_B0_UDB08_F1

; led
led__0__INTTYPE EQU CYREG_PICU2_INTTYPE1
led__0__MASK EQU 0x02
led__0__PC EQU CYREG_PRT2_PC1
led__0__PORT EQU 2
led__0__SHIFT EQU 1
led__AG EQU CYREG_PRT2_AG
led__AMUX EQU CYREG_PRT2_AMUX
led__BIE EQU CYREG_PRT2_BIE
led__BIT_MASK EQU CYREG_PRT2_BIT_MASK
led__BYP EQU CYREG_PRT2_BYP
led__CTL EQU CYREG_PRT2_CTL
led__DM0 EQU CYREG_PRT2_DM0
led__DM1 EQU CYREG_PRT2_DM1
led__DM2 EQU CYREG_PRT2_DM2
led__DR EQU CYREG_PRT2_DR
led__INP_DIS EQU CYREG_PRT2_INP_DIS
led__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
led__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
led__LCD_EN EQU CYREG_PRT2_LCD_EN
led__MASK EQU 0x02
led__PORT EQU 2
led__PRT EQU CYREG_PRT2_PRT
led__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
led__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
led__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
led__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
led__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
led__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
led__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
led__PS EQU CYREG_PRT2_PS
led__SHIFT EQU 1
led__SLW EQU CYREG_PRT2_SLW

; PWM1
PWM1_PWMUDB_genblk8_stsreg__0__MASK EQU 0x01
PWM1_PWMUDB_genblk8_stsreg__0__POS EQU 0
PWM1_PWMUDB_genblk8_stsreg__1__MASK EQU 0x02
PWM1_PWMUDB_genblk8_stsreg__1__POS EQU 1
PWM1_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB13_14_ACTL
PWM1_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG EQU CYREG_B0_UDB13_14_ST
PWM1_PWMUDB_genblk8_stsreg__2__MASK EQU 0x04
PWM1_PWMUDB_genblk8_stsreg__2__POS EQU 2
PWM1_PWMUDB_genblk8_stsreg__3__MASK EQU 0x08
PWM1_PWMUDB_genblk8_stsreg__3__POS EQU 3
PWM1_PWMUDB_genblk8_stsreg__MASK EQU 0x0F
PWM1_PWMUDB_genblk8_stsreg__MASK_REG EQU CYREG_B0_UDB13_MSK
PWM1_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB13_ACTL
PWM1_PWMUDB_genblk8_stsreg__STATUS_REG EQU CYREG_B0_UDB13_ST
PWM1_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG EQU CYREG_B0_UDB13_14_A0
PWM1_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG EQU CYREG_B0_UDB13_14_A1
PWM1_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG EQU CYREG_B0_UDB13_14_D0
PWM1_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG EQU CYREG_B0_UDB13_14_D1
PWM1_PWMUDB_sP8_pwmdp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB13_14_ACTL
PWM1_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG EQU CYREG_B0_UDB13_14_F0
PWM1_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG EQU CYREG_B0_UDB13_14_F1
PWM1_PWMUDB_sP8_pwmdp_u0__A0_A1_REG EQU CYREG_B0_UDB13_A0_A1
PWM1_PWMUDB_sP8_pwmdp_u0__A0_REG EQU CYREG_B0_UDB13_A0
PWM1_PWMUDB_sP8_pwmdp_u0__A1_REG EQU CYREG_B0_UDB13_A1
PWM1_PWMUDB_sP8_pwmdp_u0__D0_D1_REG EQU CYREG_B0_UDB13_D0_D1
PWM1_PWMUDB_sP8_pwmdp_u0__D0_REG EQU CYREG_B0_UDB13_D0
PWM1_PWMUDB_sP8_pwmdp_u0__D1_REG EQU CYREG_B0_UDB13_D1
PWM1_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB13_ACTL
PWM1_PWMUDB_sP8_pwmdp_u0__F0_F1_REG EQU CYREG_B0_UDB13_F0_F1
PWM1_PWMUDB_sP8_pwmdp_u0__F0_REG EQU CYREG_B0_UDB13_F0
PWM1_PWMUDB_sP8_pwmdp_u0__F1_REG EQU CYREG_B0_UDB13_F1

; Rx_1
Rx_1__0__INTTYPE EQU CYREG_PICU12_INTTYPE6
Rx_1__0__MASK EQU 0x40
Rx_1__0__PC EQU CYREG_PRT12_PC6
Rx_1__0__PORT EQU 12
Rx_1__0__SHIFT EQU 6
Rx_1__AG EQU CYREG_PRT12_AG
Rx_1__BIE EQU CYREG_PRT12_BIE
Rx_1__BIT_MASK EQU CYREG_PRT12_BIT_MASK
Rx_1__BYP EQU CYREG_PRT12_BYP
Rx_1__DM0 EQU CYREG_PRT12_DM0
Rx_1__DM1 EQU CYREG_PRT12_DM1
Rx_1__DM2 EQU CYREG_PRT12_DM2
Rx_1__DR EQU CYREG_PRT12_DR
Rx_1__INP_DIS EQU CYREG_PRT12_INP_DIS
Rx_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
Rx_1__MASK EQU 0x40
Rx_1__PORT EQU 12
Rx_1__PRT EQU CYREG_PRT12_PRT
Rx_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
Rx_1__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
Rx_1__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
Rx_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
Rx_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
Rx_1__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
Rx_1__PS EQU CYREG_PRT12_PS
Rx_1__SHIFT EQU 6
Rx_1__SIO_CFG EQU CYREG_PRT12_SIO_CFG
Rx_1__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
Rx_1__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
Rx_1__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
Rx_1__SLW EQU CYREG_PRT12_SLW

; Tx_1
Tx_1__0__INTTYPE EQU CYREG_PICU12_INTTYPE7
Tx_1__0__MASK EQU 0x80
Tx_1__0__PC EQU CYREG_PRT12_PC7
Tx_1__0__PORT EQU 12
Tx_1__0__SHIFT EQU 7
Tx_1__AG EQU CYREG_PRT12_AG
Tx_1__BIE EQU CYREG_PRT12_BIE
Tx_1__BIT_MASK EQU CYREG_PRT12_BIT_MASK
Tx_1__BYP EQU CYREG_PRT12_BYP
Tx_1__DM0 EQU CYREG_PRT12_DM0
Tx_1__DM1 EQU CYREG_PRT12_DM1
Tx_1__DM2 EQU CYREG_PRT12_DM2
Tx_1__DR EQU CYREG_PRT12_DR
Tx_1__INP_DIS EQU CYREG_PRT12_INP_DIS
Tx_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
Tx_1__MASK EQU 0x80
Tx_1__PORT EQU 12
Tx_1__PRT EQU CYREG_PRT12_PRT
Tx_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
Tx_1__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
Tx_1__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
Tx_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
Tx_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
Tx_1__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
Tx_1__PS EQU CYREG_PRT12_PS
Tx_1__SHIFT EQU 7
Tx_1__SIO_CFG EQU CYREG_PRT12_SIO_CFG
Tx_1__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
Tx_1__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
Tx_1__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
Tx_1__SLW EQU CYREG_PRT12_SLW

; pin1
pin1__0__INTTYPE EQU CYREG_PICU2_INTTYPE6
pin1__0__MASK EQU 0x40
pin1__0__PC EQU CYREG_PRT2_PC6
pin1__0__PORT EQU 2
pin1__0__SHIFT EQU 6
pin1__AG EQU CYREG_PRT2_AG
pin1__AMUX EQU CYREG_PRT2_AMUX
pin1__BIE EQU CYREG_PRT2_BIE
pin1__BIT_MASK EQU CYREG_PRT2_BIT_MASK
pin1__BYP EQU CYREG_PRT2_BYP
pin1__CTL EQU CYREG_PRT2_CTL
pin1__DM0 EQU CYREG_PRT2_DM0
pin1__DM1 EQU CYREG_PRT2_DM1
pin1__DM2 EQU CYREG_PRT2_DM2
pin1__DR EQU CYREG_PRT2_DR
pin1__INP_DIS EQU CYREG_PRT2_INP_DIS
pin1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
pin1__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
pin1__LCD_EN EQU CYREG_PRT2_LCD_EN
pin1__MASK EQU 0x40
pin1__PORT EQU 2
pin1__PRT EQU CYREG_PRT2_PRT
pin1__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
pin1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
pin1__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
pin1__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
pin1__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
pin1__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
pin1__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
pin1__PS EQU CYREG_PRT2_PS
pin1__SHIFT EQU 6
pin1__SLW EQU CYREG_PRT2_SLW

; pin2
pin2__0__INTTYPE EQU CYREG_PICU2_INTTYPE7
pin2__0__MASK EQU 0x80
pin2__0__PC EQU CYREG_PRT2_PC7
pin2__0__PORT EQU 2
pin2__0__SHIFT EQU 7
pin2__AG EQU CYREG_PRT2_AG
pin2__AMUX EQU CYREG_PRT2_AMUX
pin2__BIE EQU CYREG_PRT2_BIE
pin2__BIT_MASK EQU CYREG_PRT2_BIT_MASK
pin2__BYP EQU CYREG_PRT2_BYP
pin2__CTL EQU CYREG_PRT2_CTL
pin2__DM0 EQU CYREG_PRT2_DM0
pin2__DM1 EQU CYREG_PRT2_DM1
pin2__DM2 EQU CYREG_PRT2_DM2
pin2__DR EQU CYREG_PRT2_DR
pin2__INP_DIS EQU CYREG_PRT2_INP_DIS
pin2__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
pin2__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
pin2__LCD_EN EQU CYREG_PRT2_LCD_EN
pin2__MASK EQU 0x80
pin2__PORT EQU 2
pin2__PRT EQU CYREG_PRT2_PRT
pin2__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
pin2__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
pin2__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
pin2__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
pin2__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
pin2__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
pin2__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
pin2__PS EQU CYREG_PRT2_PS
pin2__SHIFT EQU 7
pin2__SLW EQU CYREG_PRT2_SLW

; pin3
pin3__0__INTTYPE EQU CYREG_PICU2_INTTYPE4
pin3__0__MASK EQU 0x10
pin3__0__PC EQU CYREG_PRT2_PC4
pin3__0__PORT EQU 2
pin3__0__SHIFT EQU 4
pin3__AG EQU CYREG_PRT2_AG
pin3__AMUX EQU CYREG_PRT2_AMUX
pin3__BIE EQU CYREG_PRT2_BIE
pin3__BIT_MASK EQU CYREG_PRT2_BIT_MASK
pin3__BYP EQU CYREG_PRT2_BYP
pin3__CTL EQU CYREG_PRT2_CTL
pin3__DM0 EQU CYREG_PRT2_DM0
pin3__DM1 EQU CYREG_PRT2_DM1
pin3__DM2 EQU CYREG_PRT2_DM2
pin3__DR EQU CYREG_PRT2_DR
pin3__INP_DIS EQU CYREG_PRT2_INP_DIS
pin3__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
pin3__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
pin3__LCD_EN EQU CYREG_PRT2_LCD_EN
pin3__MASK EQU 0x10
pin3__PORT EQU 2
pin3__PRT EQU CYREG_PRT2_PRT
pin3__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
pin3__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
pin3__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
pin3__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
pin3__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
pin3__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
pin3__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
pin3__PS EQU CYREG_PRT2_PS
pin3__SHIFT EQU 4
pin3__SLW EQU CYREG_PRT2_SLW

; pin4
pin4__0__INTTYPE EQU CYREG_PICU2_INTTYPE5
pin4__0__MASK EQU 0x20
pin4__0__PC EQU CYREG_PRT2_PC5
pin4__0__PORT EQU 2
pin4__0__SHIFT EQU 5
pin4__AG EQU CYREG_PRT2_AG
pin4__AMUX EQU CYREG_PRT2_AMUX
pin4__BIE EQU CYREG_PRT2_BIE
pin4__BIT_MASK EQU CYREG_PRT2_BIT_MASK
pin4__BYP EQU CYREG_PRT2_BYP
pin4__CTL EQU CYREG_PRT2_CTL
pin4__DM0 EQU CYREG_PRT2_DM0
pin4__DM1 EQU CYREG_PRT2_DM1
pin4__DM2 EQU CYREG_PRT2_DM2
pin4__DR EQU CYREG_PRT2_DR
pin4__INP_DIS EQU CYREG_PRT2_INP_DIS
pin4__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
pin4__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
pin4__LCD_EN EQU CYREG_PRT2_LCD_EN
pin4__MASK EQU 0x20
pin4__PORT EQU 2
pin4__PRT EQU CYREG_PRT2_PRT
pin4__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
pin4__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
pin4__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
pin4__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
pin4__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
pin4__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
pin4__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
pin4__PS EQU CYREG_PRT2_PS
pin4__SHIFT EQU 5
pin4__SLW EQU CYREG_PRT2_SLW

; UART_1
UART_1_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB10_11_ACTL
UART_1_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_B1_UDB10_11_CTL
UART_1_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_B1_UDB10_11_CTL
UART_1_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_B1_UDB10_11_CTL
UART_1_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG EQU CYREG_B1_UDB10_11_CTL
UART_1_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG EQU CYREG_B1_UDB10_11_MSK
UART_1_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG EQU CYREG_B1_UDB10_11_MSK
UART_1_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG EQU CYREG_B1_UDB10_11_MSK
UART_1_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_B1_UDB10_11_MSK
UART_1_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB10_ACTL
UART_1_BUART_sRX_RxBitCounter__CONTROL_REG EQU CYREG_B1_UDB10_CTL
UART_1_BUART_sRX_RxBitCounter__CONTROL_ST_REG EQU CYREG_B1_UDB10_ST_CTL
UART_1_BUART_sRX_RxBitCounter__COUNT_REG EQU CYREG_B1_UDB10_CTL
UART_1_BUART_sRX_RxBitCounter__COUNT_ST_REG EQU CYREG_B1_UDB10_ST_CTL
UART_1_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B1_UDB10_MSK_ACTL
UART_1_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B1_UDB10_MSK_ACTL
UART_1_BUART_sRX_RxBitCounter__PERIOD_REG EQU CYREG_B1_UDB10_MSK
UART_1_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB10_11_ACTL
UART_1_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG EQU CYREG_B1_UDB10_11_ST
UART_1_BUART_sRX_RxBitCounter_ST__MASK_REG EQU CYREG_B1_UDB10_MSK
UART_1_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B1_UDB10_MSK_ACTL
UART_1_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B1_UDB10_MSK_ACTL
UART_1_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB10_ACTL
UART_1_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG EQU CYREG_B1_UDB10_ST_CTL
UART_1_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG EQU CYREG_B1_UDB10_ST_CTL
UART_1_BUART_sRX_RxBitCounter_ST__STATUS_REG EQU CYREG_B1_UDB10_ST
UART_1_BUART_sRX_RxShifter_u0__16BIT_A0_REG EQU CYREG_B1_UDB10_11_A0
UART_1_BUART_sRX_RxShifter_u0__16BIT_A1_REG EQU CYREG_B1_UDB10_11_A1
UART_1_BUART_sRX_RxShifter_u0__16BIT_D0_REG EQU CYREG_B1_UDB10_11_D0
UART_1_BUART_sRX_RxShifter_u0__16BIT_D1_REG EQU CYREG_B1_UDB10_11_D1
UART_1_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B1_UDB10_11_ACTL
UART_1_BUART_sRX_RxShifter_u0__16BIT_F0_REG EQU CYREG_B1_UDB10_11_F0
UART_1_BUART_sRX_RxShifter_u0__16BIT_F1_REG EQU CYREG_B1_UDB10_11_F1
UART_1_BUART_sRX_RxShifter_u0__A0_A1_REG EQU CYREG_B1_UDB10_A0_A1
UART_1_BUART_sRX_RxShifter_u0__A0_REG EQU CYREG_B1_UDB10_A0
UART_1_BUART_sRX_RxShifter_u0__A1_REG EQU CYREG_B1_UDB10_A1
UART_1_BUART_sRX_RxShifter_u0__D0_D1_REG EQU CYREG_B1_UDB10_D0_D1
UART_1_BUART_sRX_RxShifter_u0__D0_REG EQU CYREG_B1_UDB10_D0
UART_1_BUART_sRX_RxShifter_u0__D1_REG EQU CYREG_B1_UDB10_D1
UART_1_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B1_UDB10_ACTL
UART_1_BUART_sRX_RxShifter_u0__F0_F1_REG EQU CYREG_B1_UDB10_F0_F1
UART_1_BUART_sRX_RxShifter_u0__F0_REG EQU CYREG_B1_UDB10_F0
UART_1_BUART_sRX_RxShifter_u0__F1_REG EQU CYREG_B1_UDB10_F1
UART_1_BUART_sRX_RxShifter_u0__MSK_DP_AUX_CTL_REG EQU CYREG_B1_UDB10_MSK_ACTL
UART_1_BUART_sRX_RxShifter_u0__PER_DP_AUX_CTL_REG EQU CYREG_B1_UDB10_MSK_ACTL
UART_1_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB09_10_ACTL
UART_1_BUART_sRX_RxSts__16BIT_STATUS_REG EQU CYREG_B0_UDB09_10_ST
UART_1_BUART_sRX_RxSts__3__MASK EQU 0x08
UART_1_BUART_sRX_RxSts__3__POS EQU 3
UART_1_BUART_sRX_RxSts__4__MASK EQU 0x10
UART_1_BUART_sRX_RxSts__4__POS EQU 4
UART_1_BUART_sRX_RxSts__5__MASK EQU 0x20
UART_1_BUART_sRX_RxSts__5__POS EQU 5
UART_1_BUART_sRX_RxSts__MASK EQU 0x38
UART_1_BUART_sRX_RxSts__MASK_REG EQU CYREG_B0_UDB09_MSK
UART_1_BUART_sRX_RxSts__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB09_ACTL
UART_1_BUART_sRX_RxSts__STATUS_REG EQU CYREG_B0_UDB09_ST
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG EQU CYREG_B1_UDB08_09_A0
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG EQU CYREG_B1_UDB08_09_A1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG EQU CYREG_B1_UDB08_09_D0
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG EQU CYREG_B1_UDB08_09_D1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG EQU CYREG_B1_UDB08_09_ACTL
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG EQU CYREG_B1_UDB08_09_F0
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG EQU CYREG_B1_UDB08_09_F1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG EQU CYREG_B1_UDB08_A0_A1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG EQU CYREG_B1_UDB08_A0
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG EQU CYREG_B1_UDB08_A1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG EQU CYREG_B1_UDB08_D0_D1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG EQU CYREG_B1_UDB08_D0
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG EQU CYREG_B1_UDB08_D1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG EQU CYREG_B1_UDB08_ACTL
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG EQU CYREG_B1_UDB08_F0_F1
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG EQU CYREG_B1_UDB08_F0
UART_1_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG EQU CYREG_B1_UDB08_F1
UART_1_BUART_sTX_TxShifter_u0__16BIT_A0_REG EQU CYREG_B0_UDB09_10_A0
UART_1_BUART_sTX_TxShifter_u0__16BIT_A1_REG EQU CYREG_B0_UDB09_10_A1
UART_1_BUART_sTX_TxShifter_u0__16BIT_D0_REG EQU CYREG_B0_UDB09_10_D0
UART_1_BUART_sTX_TxShifter_u0__16BIT_D1_REG EQU CYREG_B0_UDB09_10_D1
UART_1_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB09_10_ACTL
UART_1_BUART_sTX_TxShifter_u0__16BIT_F0_REG EQU CYREG_B0_UDB09_10_F0
UART_1_BUART_sTX_TxShifter_u0__16BIT_F1_REG EQU CYREG_B0_UDB09_10_F1
UART_1_BUART_sTX_TxShifter_u0__A0_A1_REG EQU CYREG_B0_UDB09_A0_A1
UART_1_BUART_sTX_TxShifter_u0__A0_REG EQU CYREG_B0_UDB09_A0
UART_1_BUART_sTX_TxShifter_u0__A1_REG EQU CYREG_B0_UDB09_A1
UART_1_BUART_sTX_TxShifter_u0__D0_D1_REG EQU CYREG_B0_UDB09_D0_D1
UART_1_BUART_sTX_TxShifter_u0__D0_REG EQU CYREG_B0_UDB09_D0
UART_1_BUART_sTX_TxShifter_u0__D1_REG EQU CYREG_B0_UDB09_D1
UART_1_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB09_ACTL
UART_1_BUART_sTX_TxShifter_u0__F0_F1_REG EQU CYREG_B0_UDB09_F0_F1
UART_1_BUART_sTX_TxShifter_u0__F0_REG EQU CYREG_B0_UDB09_F0
UART_1_BUART_sTX_TxShifter_u0__F1_REG EQU CYREG_B0_UDB09_F1
UART_1_BUART_sTX_TxSts__0__MASK EQU 0x01
UART_1_BUART_sTX_TxSts__0__POS EQU 0
UART_1_BUART_sTX_TxSts__1__MASK EQU 0x02
UART_1_BUART_sTX_TxSts__1__POS EQU 1
UART_1_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB08_09_ACTL
UART_1_BUART_sTX_TxSts__16BIT_STATUS_REG EQU CYREG_B1_UDB08_09_ST
UART_1_BUART_sTX_TxSts__2__MASK EQU 0x04
UART_1_BUART_sTX_TxSts__2__POS EQU 2
UART_1_BUART_sTX_TxSts__3__MASK EQU 0x08
UART_1_BUART_sTX_TxSts__3__POS EQU 3
UART_1_BUART_sTX_TxSts__MASK EQU 0x0F
UART_1_BUART_sTX_TxSts__MASK_REG EQU CYREG_B1_UDB08_MSK
UART_1_BUART_sTX_TxSts__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB08_ACTL
UART_1_BUART_sTX_TxSts__STATUS_REG EQU CYREG_B1_UDB08_ST
UART_1_IntClock__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
UART_1_IntClock__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
UART_1_IntClock__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
UART_1_IntClock__CFG2_SRC_SEL_MASK EQU 0x07
UART_1_IntClock__INDEX EQU 0x00
UART_1_IntClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
UART_1_IntClock__PM_ACT_MSK EQU 0x01
UART_1_IntClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
UART_1_IntClock__PM_STBY_MSK EQU 0x01
UART_1_RXInternalInterrupt__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
UART_1_RXInternalInterrupt__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
UART_1_RXInternalInterrupt__INTC_MASK EQU 0x01
UART_1_RXInternalInterrupt__INTC_NUMBER EQU 0
UART_1_RXInternalInterrupt__INTC_PRIOR_NUM EQU 7
UART_1_RXInternalInterrupt__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_0
UART_1_RXInternalInterrupt__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
UART_1_RXInternalInterrupt__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0
UART_1_TXInternalInterrupt__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
UART_1_TXInternalInterrupt__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
UART_1_TXInternalInterrupt__INTC_MASK EQU 0x02
UART_1_TXInternalInterrupt__INTC_NUMBER EQU 1
UART_1_TXInternalInterrupt__INTC_PRIOR_NUM EQU 7
UART_1_TXInternalInterrupt__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_1
UART_1_TXInternalInterrupt__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
UART_1_TXInternalInterrupt__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; Clock_1
Clock_1__CFG0 EQU CYREG_CLKDIST_DCFG2_CFG0
Clock_1__CFG1 EQU CYREG_CLKDIST_DCFG2_CFG1
Clock_1__CFG2 EQU CYREG_CLKDIST_DCFG2_CFG2
Clock_1__CFG2_SRC_SEL_MASK EQU 0x07
Clock_1__INDEX EQU 0x02
Clock_1__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Clock_1__PM_ACT_MSK EQU 0x04
Clock_1__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Clock_1__PM_STBY_MSK EQU 0x04

; Clock_2
Clock_2__CFG0 EQU CYREG_CLKDIST_DCFG1_CFG0
Clock_2__CFG1 EQU CYREG_CLKDIST_DCFG1_CFG1
Clock_2__CFG2 EQU CYREG_CLKDIST_DCFG1_CFG2
Clock_2__CFG2_SRC_SEL_MASK EQU 0x07
Clock_2__INDEX EQU 0x01
Clock_2__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Clock_2__PM_ACT_MSK EQU 0x02
Clock_2__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Clock_2__PM_STBY_MSK EQU 0x02

; filtro1
filtro1__0__INTTYPE EQU CYREG_PICU1_INTTYPE6
filtro1__0__MASK EQU 0x40
filtro1__0__PC EQU CYREG_PRT1_PC6
filtro1__0__PORT EQU 1
filtro1__0__SHIFT EQU 6
filtro1__AG EQU CYREG_PRT1_AG
filtro1__AMUX EQU CYREG_PRT1_AMUX
filtro1__BIE EQU CYREG_PRT1_BIE
filtro1__BIT_MASK EQU CYREG_PRT1_BIT_MASK
filtro1__BYP EQU CYREG_PRT1_BYP
filtro1__CTL EQU CYREG_PRT1_CTL
filtro1__DM0 EQU CYREG_PRT1_DM0
filtro1__DM1 EQU CYREG_PRT1_DM1
filtro1__DM2 EQU CYREG_PRT1_DM2
filtro1__DR EQU CYREG_PRT1_DR
filtro1__INP_DIS EQU CYREG_PRT1_INP_DIS
filtro1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
filtro1__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
filtro1__LCD_EN EQU CYREG_PRT1_LCD_EN
filtro1__MASK EQU 0x40
filtro1__PORT EQU 1
filtro1__PRT EQU CYREG_PRT1_PRT
filtro1__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
filtro1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
filtro1__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
filtro1__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
filtro1__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
filtro1__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
filtro1__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
filtro1__PS EQU CYREG_PRT1_PS
filtro1__SHIFT EQU 6
filtro1__SLW EQU CYREG_PRT1_SLW

; filtro2
filtro2__0__INTTYPE EQU CYREG_PICU1_INTTYPE7
filtro2__0__MASK EQU 0x80
filtro2__0__PC EQU CYREG_PRT1_PC7
filtro2__0__PORT EQU 1
filtro2__0__SHIFT EQU 7
filtro2__AG EQU CYREG_PRT1_AG
filtro2__AMUX EQU CYREG_PRT1_AMUX
filtro2__BIE EQU CYREG_PRT1_BIE
filtro2__BIT_MASK EQU CYREG_PRT1_BIT_MASK
filtro2__BYP EQU CYREG_PRT1_BYP
filtro2__CTL EQU CYREG_PRT1_CTL
filtro2__DM0 EQU CYREG_PRT1_DM0
filtro2__DM1 EQU CYREG_PRT1_DM1
filtro2__DM2 EQU CYREG_PRT1_DM2
filtro2__DR EQU CYREG_PRT1_DR
filtro2__INP_DIS EQU CYREG_PRT1_INP_DIS
filtro2__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
filtro2__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
filtro2__LCD_EN EQU CYREG_PRT1_LCD_EN
filtro2__MASK EQU 0x80
filtro2__PORT EQU 1
filtro2__PRT EQU CYREG_PRT1_PRT
filtro2__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
filtro2__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
filtro2__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
filtro2__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
filtro2__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
filtro2__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
filtro2__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
filtro2__PS EQU CYREG_PRT1_PS
filtro2__SHIFT EQU 7
filtro2__SLW EQU CYREG_PRT1_SLW

; Miscellaneous
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
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x00000003
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
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END
