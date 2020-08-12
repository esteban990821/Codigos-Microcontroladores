/***************************************************************************
* File Name: Display2_Lcd_Dma_dma.c  
* Version 1.70
*
*  Description:
*   Provides an API for the DMAC component. The API includes functions
*   for the DMA controller, DMA channels and Transfer Descriptors.
*
*
*   Note:
*     This module requires the developer to finish or fill in the auto
*     generated funcions and setup the dma channel and TD's.
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#include <CYLIB.H>
#include <CYDMAC.H>
#include <Display2_Lcd_Dma_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* Display2_Lcd_Dma__DRQ_CTL_REG
* 
* 
* Display2_Lcd_Dma__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* Display2_Lcd_Dma__NUMBEROF_TDS
* 
* Priority of this channel.
* Display2_Lcd_Dma__PRIORITY
* 
* True if Display2_Lcd_Dma_TERMIN_SEL is used.
* Display2_Lcd_Dma__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* Display2_Lcd_Dma__TERMIN_SEL
* 
* 
* True if Display2_Lcd_Dma_TERMOUT0_SEL is used.
* Display2_Lcd_Dma__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* Display2_Lcd_Dma__TERMOUT0_SEL
* 
* 
* True if Display2_Lcd_Dma_TERMOUT1_SEL is used.
* Display2_Lcd_Dma__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* Display2_Lcd_Dma__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of Display2_Lcd_Dma dma channel */
uint8 Display2_Lcd_Dma_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 Display2_Lcd_Dma_DmaInitalize
**********************************************************************
* Summary:
*   Allocates and initialises a channel of the DMAC to be used by the
*   caller.
*
* Parameters:
*   BurstCount.
*       
*       
*   ReqestPerBurst.
*       
*       
*   UpperSrcAddress.
*       
*       
*   UpperDestAddress.
*       
*
* Return:
*   The channel that can be used by the caller for DMA activity.
*   DMA_INVALID_CHANNEL (0xFF) if there are no channels left. 
*
*
*******************************************************************/
uint8 Display2_Lcd_Dma_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    Display2_Lcd_Dma_DmaHandle = (uint8)Display2_Lcd_Dma__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(Display2_Lcd_Dma_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)Display2_Lcd_Dma__TERMOUT0_SEL,
                                  (uint8)Display2_Lcd_Dma__TERMOUT1_SEL,
                                  (uint8)Display2_Lcd_Dma__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(Display2_Lcd_Dma_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(Display2_Lcd_Dma_DmaHandle, (uint8)Display2_Lcd_Dma__PRIORITY);
    
    return Display2_Lcd_Dma_DmaHandle;
}

/*********************************************************************
* Function Name: void Display2_Lcd_Dma_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with Display2_Lcd_Dma.
*
*
* Parameters:
*   void.
*
*
*
* Return:
*   void.
*
*******************************************************************/
void Display2_Lcd_Dma_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(Display2_Lcd_Dma_DmaHandle);
}

