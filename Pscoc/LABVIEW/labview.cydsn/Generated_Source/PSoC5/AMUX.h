/*******************************************************************************
* File Name: AMUX.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the Analog
*    Multiplexer User Module AMux.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUX_AMUX_H)
#define CY_AMUX_AMUX_H

#include "cyfitter.h"
#include "cyfitter_cfg.h"

#if ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) || \
         (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4) || \
         (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5))    
    #include "cytypes.h"
#else
    #include "syslib/cy_syslib.h"
#endif /* ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) */


/***************************************
*        Function Prototypes
***************************************/

void AMUX_Start(void) ;
#define AMUX_Init() AMUX_Start()
void AMUX_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void AMUX_Stop(void); */
/* void AMUX_Select(uint8 channel); */
/* void AMUX_Connect(uint8 channel); */
/* void AMUX_Disconnect(uint8 channel); */
/* void AMUX_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define AMUX_CHANNELS  8u
#define AMUX_MUXTYPE   1
#define AMUX_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define AMUX_NULL_CHANNEL 0xFFu
#define AMUX_MUX_SINGLE   1
#define AMUX_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if AMUX_MUXTYPE == AMUX_MUX_SINGLE
# if !AMUX_ATMOSTONE
#  define AMUX_Connect(channel) AMUX_Set(channel)
# endif
# define AMUX_Disconnect(channel) AMUX_Unset(channel)
#else
# if !AMUX_ATMOSTONE
void AMUX_Connect(uint8 channel) ;
# endif
void AMUX_Disconnect(uint8 channel) ;
#endif

#if AMUX_ATMOSTONE
# define AMUX_Stop() AMUX_DisconnectAll()
# define AMUX_Select(channel) AMUX_FastSelect(channel)
void AMUX_DisconnectAll(void) ;
#else
# define AMUX_Stop() AMUX_Start()
void AMUX_Select(uint8 channel) ;
# define AMUX_DisconnectAll() AMUX_Start()
#endif

#endif /* CY_AMUX_AMUX_H */


/* [] END OF FILE */
