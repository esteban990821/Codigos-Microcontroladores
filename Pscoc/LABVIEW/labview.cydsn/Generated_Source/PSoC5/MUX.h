/*******************************************************************************
* File Name: MUX.h
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

#if !defined(CY_AMUX_MUX_H)
#define CY_AMUX_MUX_H

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

void MUX_Start(void) ;
#define MUX_Init() MUX_Start()
void MUX_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void MUX_Stop(void); */
/* void MUX_Select(uint8 channel); */
/* void MUX_Connect(uint8 channel); */
/* void MUX_Disconnect(uint8 channel); */
/* void MUX_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define MUX_CHANNELS  8u
#define MUX_MUXTYPE   1
#define MUX_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define MUX_NULL_CHANNEL 0xFFu
#define MUX_MUX_SINGLE   1
#define MUX_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if MUX_MUXTYPE == MUX_MUX_SINGLE
# if !MUX_ATMOSTONE
#  define MUX_Connect(channel) MUX_Set(channel)
# endif
# define MUX_Disconnect(channel) MUX_Unset(channel)
#else
# if !MUX_ATMOSTONE
void MUX_Connect(uint8 channel) ;
# endif
void MUX_Disconnect(uint8 channel) ;
#endif

#if MUX_ATMOSTONE
# define MUX_Stop() MUX_DisconnectAll()
# define MUX_Select(channel) MUX_FastSelect(channel)
void MUX_DisconnectAll(void) ;
#else
# define MUX_Stop() MUX_Start()
void MUX_Select(uint8 channel) ;
# define MUX_DisconnectAll() MUX_Start()
#endif

#endif /* CY_AMUX_MUX_H */


/* [] END OF FILE */
