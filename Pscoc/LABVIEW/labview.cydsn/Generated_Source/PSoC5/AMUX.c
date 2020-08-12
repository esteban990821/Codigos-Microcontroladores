/*******************************************************************************
* File Name: AMUX.c
* Version 1.80
*
*  Description:
*    This file contains all functions required for the analog multiplexer
*    AMux User Module.
*
*   Note:
*
*******************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "AMUX.h"

static uint8 AMUX_lastChannel = AMUX_NULL_CHANNEL;


/*******************************************************************************
* Function Name: AMUX_Start
********************************************************************************
* Summary:
*  Disconnect all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AMUX_Start(void) 
{
    uint8 chan;

    for(chan = 0u; chan < AMUX_CHANNELS ; chan++)
    {
#if (AMUX_MUXTYPE == AMUX_MUX_SINGLE)
        AMUX_Unset(chan);
#else
        AMUX_CYAMUXSIDE_A_Unset(chan);
        AMUX_CYAMUXSIDE_B_Unset(chan);
#endif
    }

    AMUX_lastChannel = AMUX_NULL_CHANNEL;
}


#if (!AMUX_ATMOSTONE)
/*******************************************************************************
* Function Name: AMUX_Select
********************************************************************************
* Summary:
*  This functions first disconnects all channels then connects the given
*  channel.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void AMUX_Select(uint8 channel) 
{
    AMUX_DisconnectAll();        /* Disconnect all previous connections */
    AMUX_Connect(channel);       /* Make the given selection */
    AMUX_lastChannel = channel;  /* Update last channel */
}
#endif


/*******************************************************************************
* Function Name: AMUX_FastSelect
********************************************************************************
* Summary:
*  This function first disconnects the last connection made with FastSelect or
*  Select, then connects the given channel. The FastSelect function is similar
*  to the Select function, except it is faster since it only disconnects the
*  last channel selected rather than all channels.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void AMUX_FastSelect(uint8 channel) 
{
    /* Disconnect the last valid channel */
    if( AMUX_lastChannel != AMUX_NULL_CHANNEL)
    {
        AMUX_Disconnect(AMUX_lastChannel);
    }

    /* Make the new channel connection */
#if (AMUX_MUXTYPE == AMUX_MUX_SINGLE)
    AMUX_Set(channel);
#else
    AMUX_CYAMUXSIDE_A_Set(channel);
    AMUX_CYAMUXSIDE_B_Set(channel);
#endif


    AMUX_lastChannel = channel;   /* Update last channel */
}


#if (AMUX_MUXTYPE == AMUX_MUX_DIFF)
#if (!AMUX_ATMOSTONE)
/*******************************************************************************
* Function Name: AMUX_Connect
********************************************************************************
* Summary:
*  This function connects the given channel without affecting other connections.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void AMUX_Connect(uint8 channel) 
{
    AMUX_CYAMUXSIDE_A_Set(channel);
    AMUX_CYAMUXSIDE_B_Set(channel);
}
#endif

/*******************************************************************************
* Function Name: AMUX_Disconnect
********************************************************************************
* Summary:
*  This function disconnects the given channel from the common or output
*  terminal without affecting other connections.
*
* Parameters:
*  channel:  The channel to disconnect from the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void AMUX_Disconnect(uint8 channel) 
{
    AMUX_CYAMUXSIDE_A_Unset(channel);
    AMUX_CYAMUXSIDE_B_Unset(channel);
}
#endif

#if (AMUX_ATMOSTONE)
/*******************************************************************************
* Function Name: AMUX_DisconnectAll
********************************************************************************
* Summary:
*  This function disconnects all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AMUX_DisconnectAll(void) 
{
    if(AMUX_lastChannel != AMUX_NULL_CHANNEL) 
    {
        AMUX_Disconnect(AMUX_lastChannel);
        AMUX_lastChannel = AMUX_NULL_CHANNEL;
    }
}
#endif

/* [] END OF FILE */
