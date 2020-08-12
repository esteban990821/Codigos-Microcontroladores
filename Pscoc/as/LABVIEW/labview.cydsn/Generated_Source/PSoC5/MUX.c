/*******************************************************************************
* File Name: MUX.c
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

#include "MUX.h"

static uint8 MUX_lastChannel = MUX_NULL_CHANNEL;


/*******************************************************************************
* Function Name: MUX_Start
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
void MUX_Start(void) 
{
    uint8 chan;

    for(chan = 0u; chan < MUX_CHANNELS ; chan++)
    {
#if (MUX_MUXTYPE == MUX_MUX_SINGLE)
        MUX_Unset(chan);
#else
        MUX_CYAMUXSIDE_A_Unset(chan);
        MUX_CYAMUXSIDE_B_Unset(chan);
#endif
    }

    MUX_lastChannel = MUX_NULL_CHANNEL;
}


#if (!MUX_ATMOSTONE)
/*******************************************************************************
* Function Name: MUX_Select
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
void MUX_Select(uint8 channel) 
{
    MUX_DisconnectAll();        /* Disconnect all previous connections */
    MUX_Connect(channel);       /* Make the given selection */
    MUX_lastChannel = channel;  /* Update last channel */
}
#endif


/*******************************************************************************
* Function Name: MUX_FastSelect
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
void MUX_FastSelect(uint8 channel) 
{
    /* Disconnect the last valid channel */
    if( MUX_lastChannel != MUX_NULL_CHANNEL)
    {
        MUX_Disconnect(MUX_lastChannel);
    }

    /* Make the new channel connection */
#if (MUX_MUXTYPE == MUX_MUX_SINGLE)
    MUX_Set(channel);
#else
    MUX_CYAMUXSIDE_A_Set(channel);
    MUX_CYAMUXSIDE_B_Set(channel);
#endif


    MUX_lastChannel = channel;   /* Update last channel */
}


#if (MUX_MUXTYPE == MUX_MUX_DIFF)
#if (!MUX_ATMOSTONE)
/*******************************************************************************
* Function Name: MUX_Connect
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
void MUX_Connect(uint8 channel) 
{
    MUX_CYAMUXSIDE_A_Set(channel);
    MUX_CYAMUXSIDE_B_Set(channel);
}
#endif

/*******************************************************************************
* Function Name: MUX_Disconnect
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
void MUX_Disconnect(uint8 channel) 
{
    MUX_CYAMUXSIDE_A_Unset(channel);
    MUX_CYAMUXSIDE_B_Unset(channel);
}
#endif

#if (MUX_ATMOSTONE)
/*******************************************************************************
* Function Name: MUX_DisconnectAll
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
void MUX_DisconnectAll(void) 
{
    if(MUX_lastChannel != MUX_NULL_CHANNEL) 
    {
        MUX_Disconnect(MUX_lastChannel);
        MUX_lastChannel = MUX_NULL_CHANNEL;
    }
}
#endif

/* [] END OF FILE */
