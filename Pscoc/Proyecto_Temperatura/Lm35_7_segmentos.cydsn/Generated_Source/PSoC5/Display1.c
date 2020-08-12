/*******************************************************************************
* File Name: Display1.c
* Version 2.30
*
* Description:
*  This file provides the API source code for the Static Segment LCD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Display1.h"
#include <Display1_InClock.h>
#include <Display1_LCD_ISR.h>
#include <Display1_Lcd_Dma_dma.h>

static uint8  Display1_DmaConfigure(void) CYREENTRANT;
static void   Display1_DmaDispose(void) CYREENTRANT;


/* Look-up tables for different kinds of displays */
#ifdef Display1_7SEG

    static const uint8 CYCODE Display1_7SegDigits[] =
    /* '0'   '1'    '2'    '3'    '4'    '5'    '6'    '7' */
    {0x3fu, 0x06u, 0x5bu, 0x4fu, 0x66u, 0x6du, 0x7du, 0x07u,
    /* '8'  '9'    'A'    'B'    'C'    'D'    'E'    'F'   null */
    0x7fu, 0x6fu, 0x77u, 0x7cu, 0x39u, 0x5eu, 0x79u, 0x71u, 0x00u};

#endif /* Display1_7SEG */

#ifdef ALPHANUMERIC

    #ifdef Display1_14SEG

        static const uint16 CYCODE Display1_14SegChars[] = {
        /*------------------------------------------------------------*/
        /*                           Blank                            */
        /*------------------------------------------------------------*/
        0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,
        0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,
        0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,
        0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,
        /*------------------------------------------------------------*/
        /*         !       "       #       $       %       &       '  */
        /*------------------------------------------------------------*/
        0x0000u,0x0006u,0x0120u,0x3fffu,0x156du,0x2ee4u,0x2a8du,0x0200u,
        /*------------------------------------------------------------*/
        /* (       )       *       +       ,       -       .       /  */
        /*------------------------------------------------------------*/
        0x0a00u,0x2080u,0x3fc0u,0x1540u,0x2000u,0x0440u,0x1058u,0x2200u,
        /*------------------------------------------------------------*/
        /* 0       1       2       3       4       5       6       7  */
        /*------------------------------------------------------------*/
        0x223fu,0x0206u,0x045bu,0x040fu,0x0466u,0x0869u,0x047du,0x1201u,
        /*------------------------------------------------------------*/
        /* 8       9       :       ;       <       =       >       ?  */
        /*------------------------------------------------------------*/
        0x047fu,0x046fu,0x1100u,0x2100u,0x0a00u,0x0448u,0x2080u,0x1423u,
        /*------------------------------------------------------------*/
        /* @       A       B       C       D       E       F       G  */
        /*------------------------------------------------------------*/
        0x053bu,0x0477u,0x150fu,0x0039u,0x110Fu,0x0079u,0x0071u,0x043du,
        /*------------------------------------------------------------*/
        /* H       I       J       K       L       M       N       O  */
        /*------------------------------------------------------------*/
        0x0476u,0x1100u,0x001eu,0x0a70u,0x0038u,0x02b6u,0x08b6u,0x003fu,
        /*------------------------------------------------------------*/
        /* P       Q       R       S       T       U       V       W  */
        /*------------------------------------------------------------*/
        0x0473u,0x083fu,0x0C73u,0x046du,0x1101u,0x003eu,0x2230u,0x2836u,
        /*------------------------------------------------------------*/
        /* X       Y       Z       [       \       ]       ^       _  */
        /*------------------------------------------------------------*/
        0x2a80u,0x1462u,0x2209u,0x0039u,0x0880u,0x000fu,0x0003u,0x0008u,
        /*------------------------------------------------------------*/
        /* @       a       b       c       d       e       f       g  */
        /*------------------------------------------------------------*/
        0x053bu,0x0477u,0x150fu,0x0039u,0x110Fu,0x0079u,0x0071u,0x043du,
        /*------------------------------------------------------------*/
        /* h       i       j       k       l       m       n       o  */
        /*------------------------------------------------------------*/
        0x0476u,0x1100u,0x001eu,0x0a70u,0x0038u,0x02b6u,0x08b6u,0x003fu,
        /*------------------------------------------------------------*/
        /* p       q       r       s       t       u       v       w  */
        /*------------------------------------------------------------*/
        0x0473u,0x083fu,0x0C73u,0x046du,0x1101u,0x003eu,0x2230u,0x2836u,
        /*------------------------------------------------------------*/
        /* x       y       z       {       |       }        ~      O  */
        /*------------------------------------------------------------*/
        0x2a80u,0x1280u,0x2209u,0x0e00u,0x1100u,0x20C0u,0x0452u,0x003fu};

    #endif /* Display1_14SEG */

    #ifdef Display1_16SEG

        static const uint16 CYCODE Display1_16SegChars[] = {
        /*------------------------------------------------------------*/
        /*                           Blank                            */
        /*------------------------------------------------------------*/
        0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,
        0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,
        0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,
        0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,0x0000u,
        /*------------------------------------------------------------*/
        /*         !       "       #       $       %       &       '  */
        /*------------------------------------------------------------*/
        0x0000u,0x000cu,0x0480u,0xffffu,0x55bbu,0xdd99u,0xaa3bu,0x0800u,
        /*------------------------------------------------------------*/
        /* (       )       *       +       ,       -       .       /  */
        /*------------------------------------------------------------*/
        0x2800u,0x8200u,0xff00u,0x5500u,0x8000u,0x1100u,0x4160u,0x8800u,
        /*------------------------------------------------------------*/
        /* 0       1       2       3       4       5       6       7  */
        /*------------------------------------------------------------*/
        0x88ffu,0x000cu,0x1177u,0x103fu,0x118cu,0x21b3u,0x11fbu,0x4803u,
        /*------------------------------------------------------------*/
        /* 8       9       :       ;       <       =       >       ?  */
        /*------------------------------------------------------------*/
        0x11ffu,0x11bfu,0x4400u,0x8400u,0x2800u,0x1130u,0x8200u,0x5087u,
        /*------------------------------------------------------------*/
        /* @       A       B       C       D       E       F       G  */
        /*------------------------------------------------------------*/
        0x14f7u,0x11cfu,0x543fu,0x00f3u,0x443fu,0x01f3u,0x01c3u,0x10fbu,
        /*------------------------------------------------------------*/
        /* H       I       J       K       L       M       N       O  */
        /*------------------------------------------------------------*/
        0x11ccu,0x4400u,0x007eu,0x29c0u,0x00f0u,0x0accu,0x22ccu,0x00ffu,
        /*------------------------------------------------------------*/
        /* P       Q       R       S       T       U       V       W  */
        /*------------------------------------------------------------*/
        0x11c7u,0x20ffu,0x31c7u,0x11bbu,0x4403u,0x00fcu,0x88c0u,0xa0ccu,
        /*------------------------------------------------------------*/
        /* X       Y       Z       [       \       ]       ^       _  */
        /*------------------------------------------------------------*/
        0xaa00u,0x5184u,0x8833u,0x4412u,0x2200u,0x4421u,0x0006u,0x0030u,
        /*------------------------------------------------------------*/
        /* @       a       b       c       d       e       f       g  */
        /*------------------------------------------------------------*/
        0x14f7u,0x11cfu,0x543fu,0x00f3u,0x443fu,0x01f3u,0x01c3u,0x10fbu,
        /*------------------------------------------------------------*/
        /* h       i       j       k       l       m       n       o  */
        /*------------------------------------------------------------*/
        0x11ccu,0x4400u,0x007eu,0x29c0u,0x00f0u,0x0accu,0x22ccu,0x00ffu,
        /*------------------------------------------------------------*/
        /* p       q       r       s       t       u       v       w  */
        /*------------------------------------------------------------*/
        0x11c7u,0x20ffu,0x31c7u,0x11bbu,0x4403u,0x00fcu,0x88c0u,0xa0ccu,
        /*------------------------------------------------------------*/
        /* x       y       z       {       |       }        ~         */
        /*------------------------------------------------------------*/
        0xaa00u,0x4A00u,0x8833u,0x3800u,0x4400u,0x8300u,0x1144u,0x0000u};

    #endif /* Display1_16SEG */

#endif /* ALPHANUMERIC */

/* Frame Buffer */
static uint8 Display1_buffer[Display1_BUFFER_LENGTH] ;

/* Array of common port TDs */
static uint8 Display1_lcdTd[Display1_LCD_TD_SIZE * Display1_COMM_NUM];

/* DMA channel dedicated for SegLCD commons */
static uint8 Display1_lcdChannel;

uint8 Display1_initVar = 0u;

/* Saves state of the component if it turned on or off */
uint8 Display1_enableState = 0u;

/* Start of customizer generated code */

static uint16 CYCODE Display1_commons[1u] = {Display1_Com0};


/*******************************************************************************
* Function Name: Display1_Init
********************************************************************************
*
* Summary:
*  Configures every-frame ISR and initializes a Frame Buffer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Display1_Init(void) 
{
    Display1_ClearDisplay();

    /*ISR initialization */
    CyIntDisable(Display1_ISR_NUMBER);

    /* Set the ISR to point to the RTC_SUT_isr Interrupt. */
    (void) CyIntSetVector(Display1_ISR_NUMBER, &Display1_ISR);

    /* Set the priority. */
    CyIntSetPriority(Display1_ISR_NUMBER, Display1_ISR_PRIORITY);
}


/*******************************************************************************
* Function Name: Display1_Enable
********************************************************************************
*
* Summary:
*  Enables clock generation for the component and configures DMA channels.
*
* Parameters:
*  None.
*
* Return:
*  Status one of standard status for PSoC3 Component:
*      CYRET_SUCCESS - Function completed successfully.
*      CYRET_LOCKED - The object was locked, already in use. Some of TDs or
*                     a channel already in use.
*
* Global variables:
*  Display1_enableState - Initializes variable to '1', it means that
*  the component was initialized and enabled before entering into a Sleep.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 Display1_Enable(void) 
{
    uint8 status;

    /* Configure DMA TDs and return status */
    status = Display1_DmaConfigure();

    /* Enable Internal clock */
    Display1_InClock_Enable();

    /* The component is started so set the state appropriately */
    Display1_enableState = 1u;

    return(status);
}


/*******************************************************************************
* Function Name: Display1_DmaConfigure
********************************************************************************
*
* Summary:
*  Configures DMA to transfer data from the frame buffer to port alliased
*  memory.
*
* Parameters:
*  None.
*
* Return:
*  Status one of standard status for PSoC3 Component
*      CYRET_SUCCESS - Function completed successfully.
*      CYRET_LOCKED - The object was locked, already in use. Some of TDs or
*                     a channel already in use.
*
* Global variables:
* Display1_lcdTd[] - used to store a set of allocated TD IDs that are
*  used by this component.
*
*  Display1_lcdChannel - stores a DMA Channel allocated for an LCD usage.
*
*  Display1_termOut - used as a parameter for LCD DMA configuration API
*  to select proper TermOut signal that was previously calculated.
*
*  Display1LcdPort_DMA_TD_PROTO_BLOCK[] - used as a parameter for DMA
*  configuration API.
*
* Reentrant:
*  No.
*
*******************************************************************************/
static uint8 Display1_DmaConfigure(void) CYREENTRANT
{
    uint8 status = CYRET_LOCKED;
    uint8 i;
    uint8 j;
    uint8 errorCnt = 0u;
    uint32 srcAddr;
    uint32 dstAddr;
    uint8 comTdCount;
    /* DMA_PROTO_TD_DEF */
    static const struct Display1_DMA_TD_PROTO_ENTRY CYCODE Display1_StSegLcdPort_DMA_TD_PROTO_BLOCK[2u] =
    {
        {0u, 1u},
        {2u, 2u},
    };

    /* Display1_termOut selects signal which triggers
    * LCD every frame interrupt.
    */
    static uint8 Display1_termOut = (Display1_Lcd_Dma__TERMOUT0_EN ? TD_TERMOUT0_EN : 0u) |
                                 (Display1_Lcd_Dma__TERMOUT1_EN ? TD_TERMOUT1_EN : 0u);

    /* Get addressed of source and destination for DMA transactions */
    srcAddr = Display1_DMA_ADDRESS_MASK & ((uint32) Display1_buffer);
    dstAddr = Display1_DMA_ADDRESS_MASK & Display1_ALIASED_AREA_PTR;

    /* Allocate DMA channel */
    Display1_lcdChannel = Display1_Lcd_Dma_DmaInitialize(0u, 0u, HI16(srcAddr), HI16(dstAddr));

    /* Check if the channel is valid */
    if(Display1_lcdChannel == DMA_INVALID_CHANNEL)
    {
        errorCnt++;
    }

    /* Allocate required number of DMA TDs */
    for(j = 0u; j < Display1_COMM_NUM; j++)
    {
        for(i = 0u; i < Display1_LCD_TD_SIZE; i++)
        {
            Display1_lcdTd[(j * Display1_LCD_TD_SIZE) + i] = CyDmaTdAllocate();
            if(Display1_lcdTd[(j * Display1_LCD_TD_SIZE) + i] == DMA_INVALID_TD)
            {
                errorCnt++;
            }
        }
    }

    /* comTdCount stores the number of TDs allocated for this configuration */
    comTdCount = (Display1_COMM_NUM * Display1_LCD_TD_SIZE);

    /* TD configuration loop */
    for(j = 0u; j < Display1_COMM_NUM; j++)
    {
        for(i = 0u; i < Display1_LCD_TD_SIZE; i++)
        {
            /* The last TD need to point to TD[0] */
            if(((j * Display1_LCD_TD_SIZE) + i) == (comTdCount - 1u))
            {
                (void) CyDmaTdSetConfiguration(Display1_lcdTd[(j * Display1_LCD_TD_SIZE) + i],
                                        (uint16) Display1_StSegLcdPort_DMA_TD_PROTO_BLOCK[i].length,
                                        Display1_lcdTd[0u],
                                        TD_INC_DST_ADR | TD_INC_SRC_ADR | Display1_termOut);
            }
            /* Last TD in the row should generate an interrupt signal */
            else if(i == (Display1_LCD_TD_SIZE - 1u))
            {
                (void) CyDmaTdSetConfiguration(Display1_lcdTd[(j * Display1_LCD_TD_SIZE) + i],
                                        (uint16) Display1_StSegLcdPort_DMA_TD_PROTO_BLOCK[i].length,
                                        Display1_lcdTd[(j * Display1_LCD_TD_SIZE) + i + 1u],
                                        TD_INC_DST_ADR | TD_INC_SRC_ADR | Display1_termOut);
            }
            else
            {
                /* If this is not the last TD in the row it should automatically
                * next standing TDs.
                */
               (void) CyDmaTdSetConfiguration(Display1_lcdTd[(j * Display1_LCD_TD_SIZE) + i],
                                        (uint16) Display1_StSegLcdPort_DMA_TD_PROTO_BLOCK[i].length,
                                        Display1_lcdTd[(j * Display1_LCD_TD_SIZE) + i + 1u],
                                        TD_INC_DST_ADR | TD_INC_SRC_ADR | TD_AUTO_EXEC_NEXT);
            }

            /* Set the low 16 bits of the source and destination addresses
            * for TDs.
            */
            (void) CyDmaTdSetAddress(Display1_lcdTd[(j * Display1_LCD_TD_SIZE) + i],
                              LO16(srcAddr) + (((uint16) j) * Display1_ROW_LENGTH) +
                              (uint16) Display1_StSegLcdPort_DMA_TD_PROTO_BLOCK[i].offset,
                              LO16(dstAddr) + Display1_StSegLcdPort_DMA_TD_PROTO_BLOCK[i].offset);
        }
    }

    /* If there was no errors during DMA configuration then enable the channel. */
    if(errorCnt == 0u)
    {
        (void) CyDmaChSetInitialTd(Display1_lcdChannel, Display1_lcdTd[0u]);
        (void) CyDmaChEnable(Display1_lcdChannel, 1u);
        status = CYRET_SUCCESS;
    }

    return(status);
}


/*******************************************************************************
* Function Name: Display1_DmaDispose
********************************************************************************
*
* Summary:
*  Releases transaction descriptors and DMA channel previously used by the
*  component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  Display1_lcdTd[] - used  store a set of allocated TD IDs that are
*  used by this component which will be released by this function.
*
*  Display1_lcdChannel - holds the channel number used by the LCD
*  component that will be released by this function.
*
* Reentrant:
*  No.
*
*******************************************************************************/
static void Display1_DmaDispose(void) CYREENTRANT
{
    uint8 i;

    /* Release DMA handle, this will disable the LCD channel */
    Display1_Lcd_Dma_DmaRelease();

    /* Free unused channel */
    (void) CyDmaChFree(Display1_lcdChannel);

    /* Release all allocated TDs */
    for(i = 0u; i < (Display1_LCD_TD_SIZE * Display1_COMM_NUM); i++)
    {
        CyDmaTdFree(Display1_lcdTd[i]);
    }
}


/*******************************************************************************
* Function Name: Display1_Start
********************************************************************************
*
* Summary:
*  Starts the LCD component , DMA channels and initializes the frame buffer.
*
* Parameters:
*  None.
*
* Return:
*  One of standard status for PSoC3 Component:
*      CYRET_SUCCESS - Function completed successfully.
*      CYRET_LOCKED - The object was locked, already in use. Some of TDs or
*                     channel already in use.
*
* Global variables:
*  Display1_initVar - is used to indicate initial configuration of
*  this component. The variable is initialized to zero and set to 1 the first
*  time Display1_Start() is called. This allows for component
*  initialization without re-initialization in all subsequent calls to the
*  Display1_Start() routine.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 Display1_Start(void) 
{
    uint8 status;

    /* If not Initialized then initialize all required hardware and software */
    if(Display1_initVar == 0u)
    {
        Display1_initVar = 1u;
        Display1_Init();
    }

    status = Display1_Enable();

    return(status);
}


/*******************************************************************************
* Function Name: Display1_Stop
********************************************************************************
*
* Summary:
*  Disables the LCD component and disables any required interrupts and DMA
*  channels. Automatically blanks the display to avoid damage from DC offsets.
*  Does not clear the frame buffer. Disables LCD every frame interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  Display1_enableState - cleared to 0 by this function indicating
*  that the component is disabled.
*
*******************************************************************************/
void Display1_Stop(void) 
{
    CyIntDisable(Display1_ISR_NUMBER);

    /* Stop clock generation */
    Display1_InClock_Disable();

    /* Release DMA resources used for the LCD */
    Display1_DmaDispose();

    /* Now the component is disabled so save its state */
    Display1_enableState = 0u;
}


/*******************************************************************************
* Function Name: Display1_EnableInt
********************************************************************************
*
* Summary:
*  Enables LCD every-frame interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Display1_EnableInt(void) 
{
    CyIntEnable(Display1_ISR_NUMBER);
}


/*******************************************************************************
* Function Name: Display1_DisableInt
********************************************************************************
* Summary:
*  Description: Disables LCD interrupt. Not required if Display1_Stop
*  called.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Display1_DisableInt(void) 
{
   CyIntDisable(Display1_ISR_NUMBER);
}


/*******************************************************************************
* Function Name: Display1_ClearDisplay
********************************************************************************
*
* Summary:
*  This function clears the display RAM of the frame buffer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  Display1_buffer[] - an array is modified by this API. Clears the
*  frame buffer to all zeroes and then reinitialize it with a 1 in the
*  locations specified by the values from Display1_commons[].
*
*  Display1_commons[] - holds the pixel locations for common lines.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Display1_ClearDisplay(void) 
{
    uint16 i;

    /* Clear entire frame buffer to "zero" values */
    for(i = 0u ; i < Display1_BUFFER_LENGTH; i++)
    {
        if(i < (Display1_BUFFER_LENGTH / 2u))
        {
            /* First line(frame) of the buffer should contain pixel data */
            Display1_buffer[i] = 0x00u;
        }
        else
        {
            /* Second line(frame) of the buffer should contain inverted pixel data */
            Display1_buffer[i] = 0xFFu;
        }
    }

    /* Reinitialize the commons */
    Display1_WRITE_PIXEL(Display1_commons[0u], Display1_PIXEL_STATE_OFF);
}


/*******************************************************************************
* Function Name: Display1_WritePixel
********************************************************************************
*
* Summary:
*  This function sets or clears a pixel based on pixelState in a frame buffer.
*  The Pixel is addressed by a packed number.
*
* Parameters:
*  pixelNumber: is the packed number that points to the pixels location in the
*               frame buffer. The lowest three bits in the LSB low nibble are
*               the bit position in the byte, the LSB upper nibble (4 bits) is
*               the byte address in the multiplex Row and the MSB low nibble
*               (4 bits) is the multiplex Row number.
*  pixelState : 0 for pixel off,1 for pixel on, 2 for pixel invert.
*
* Return:
*  Status returns the standardized return value for pass or fail on a range
*  check of the byte address and multiplex Row number:
*      CYRET_SUCCESS - Function completed successfully.
*      CYRET_BAD_PARAM - One of the parameters is invalid.
*
* Global variables:
*  Display1_buffer[] - an array is modified by this API. This API sets
*  or clears certain bit in the array defined by the input parameter.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 Display1_WritePixel(uint16 pixelNumber, uint8 pixelState) 
{
    uint16 byteAddr;
    uint16 bitAddr;
    uint16 row;
    uint8 mask;
    uint8 status;

    /* Let the User know that he has entered wrong parameter
    * which is pixel state greater than 2 or unconnected pixel.
    */
    if((pixelState > Display1_PIXEL_STATE_INVERT) || (pixelNumber == Display1_NOT_CON))
    {
        status = CYRET_BAD_PARAM;
    }
    else
    {
        /* Extract bit position in the byte */
        bitAddr = (pixelNumber & Display1_BIT_MASK);

        /* Extract byte position in the Row */
        byteAddr = (pixelNumber & Display1_PORT_MASK) >> Display1_PORT_SHIFT;

        /* Extract Row position */
        row = (pixelNumber & Display1_ROW_MASK) >> Display1_ROW_SHIFT;

        if(pixelState == Display1_PIXEL_STATE_INVERT)
        {
            /* Invert actual pixel state */
            pixelState = ~(Display1_ReadPixel(pixelNumber));
        }

        mask = ~(uint8) (((uint8) Display1_PIXEL_STATE_ON) << bitAddr);

        /* Set pixel in first frame buffer line */
        Display1_buffer[(row * Display1_ROW_BYTE_LENGTH) + byteAddr] =
            (Display1_buffer[(row * Display1_ROW_BYTE_LENGTH) + byteAddr] & mask) |
            ((uint8) (((uint8) pixelState) << bitAddr));

        /* Invert pixel state */
        pixelState ^= Display1_PIXEL_STATE_ON;

        Display1_buffer[((row + 1u) * Display1_ROW_BYTE_LENGTH) + byteAddr] =
            (Display1_buffer[((row + 1u) * Display1_ROW_BYTE_LENGTH) + byteAddr] & mask) |
            ((uint8) (((uint8) pixelState) << bitAddr));

        status = CYRET_SUCCESS;
    }

    return(status);
}


/*******************************************************************************
* Function Name: Display1_ReadPixel
********************************************************************************
*
* Summary:
*  This function reads a pixels state in a large frame buffer. The Pixel is
*  addressed by a packed number.
*
* Parameters:
*  pixelNumber: is the packed number that points to the pixels location in the
*               frame buffer. The lowest three bits in the LSB low nibble are
*               the bit position in the byte, the LSB upper nibble (4 bits) is
*               the byte address in the multiplex Row and the MSB low nibble
*               (4 bits) is the multiplex Row number.
*
* Return:
*  Pixel State:
*      0x00 (Display1_PIXEL_STATE_OFF) - for pixel off.
*      0x01 (Display1_PIXEL_STATE_ON) - for pixel on.
*      0xFF (Display1_PIXEL_UNKNOWN_STATE) - indicates that pixel
*                                                    isn't assigned.
*
* Global variables:
*  Display1_buffer[] - holds the state of every pixel of the LCD glass
*  which can be read by this function.
*
*******************************************************************************/
uint8 Display1_ReadPixel(uint16 pixelNumber) 
{
    uint16 byteAddr;
    uint16 bitAddr;
    uint16 row;
    uint8 pixelState;

    if(pixelNumber != Display1_NOT_CON)
    {
        /* Extract all required information from pixelNumber to address required pixel */
        bitAddr = (pixelNumber & Display1_BIT_MASK);
        byteAddr = (pixelNumber & Display1_PORT_MASK) >> Display1_PORT_SHIFT;
        row = (pixelNumber & Display1_ROW_MASK) >> Display1_ROW_SHIFT;

        pixelState = ((Display1_buffer[(row * Display1_ROW_BYTE_LENGTH) + byteAddr] >> bitAddr) &
                       Display1_PIXEL_STATE_ON);
    }
    else
    {
        /* Indicate that the pixel number is invalid */
        pixelState = Display1_PIXEL_UNKNOWN_STATE;
    }

    return (pixelState);
}


/*******************************************************************************
* Function Name: Display1_WriteInvertState
********************************************************************************
*
* Summary:
*  This function inverts the display based on invertState.
*
* Parameters:
*  invertState: the values can be - 0 (#Display1_NORMAL_STATE) for
*               normal noninverted display and 1
*                (#Display1_INVERTED_STATE) for inverted display.
*
* Return:
*  One of standard status for PSoC3 Component:
*      CYRET_SUCCESS - function completed successfully.
*      CYRET_BAD_PARAM - evaluation of invertState parameter is failed.
*
*******************************************************************************/
uint8 Display1_WriteInvertState(uint8 invertState) 
{
    uint8 status;

    /* Check if inverstState parameter is valid */
    if(invertState <= Display1_INVERTED_STATE)
    {
        /* If the staate is "Invert" then then set pixel - com0 to "1", otherwise
        * set it to "0".
        */
        if(Display1_INVERTED_STATE == invertState)
        {
            Display1_WRITE_PIXEL(Display1_commons[0u], Display1_PIXEL_STATE_ON);
        }
        else
        {
            Display1_WRITE_PIXEL(Display1_commons[0u], Display1_PIXEL_STATE_OFF);
        }

        status = CYRET_SUCCESS;
    }
    else
    {
        status = CYRET_BAD_PARAM;
    }

    return(status);
}


/*******************************************************************************
* Function Name: Display1_ReadInvertState
********************************************************************************
*
* Summary:
*  This function returns the current state of the display, possible states are
*  normal and inverted.
*
* Parameters:
*  None.
*
* Return:
*  Display1_NORMAL_STATE (0) - for normal non-inverted display.
*  Display1_INVERTED_STATE (1) -  for inverted display.
*
*******************************************************************************/
uint8 Display1_ReadInvertState(void) 
{
    uint8 state = Display1_INVERTED_STATE;

    /* Get only invert bit of Driver Control Register */
    if(Display1_PIXEL_STATE_OFF == Display1_ReadPixel(Display1_commons[0u]))
    {
        state = Display1_NORMAL_STATE;
    }

    return(state);
}


/* Start of customizer generated code */
/*******************************************************************************
* Function Name: Display1_Write7SegDigit_0
********************************************************************************
* 
* Summary:
*  This function displays an 4-bit Hex digit in the range of 0-9 and A-F on 7 
*  segment display. The user must have defined what portion of the displays
*  segments make up the 7 segment display portion in the component customizer.
*  Multiple, separate 7 segment displays can be created in the frame buffer
*  and are addressed through the index (n) in the function name. Function/s only
*  included if component 7 segment customizer defines the 7 segment option.
*
* Parameters:  
*  digit : unsigned integer value in the range of 0 to 16 to be displayed as a
*  hexadecimal digit. The ASCII numbers of a hexadecimal characters are also
*  valid. In case of a invalid digit value displays 0 in position specified.
*  position : Position of the digit as counted right to left starting at 0 on the
*  right. If the defined display does not contain a digit in the position then
*  the digit will not be displayed.
*
* Return: 
*  None.
*
* Global variables:
*  Display1_7SegDigits[] - used as a look-up table for 7 Segment helper.
*  Holds decoded digit's pixel reflection for the helper.
*
*  Display1_disp0[][] - holds pixels locations for 7 Segment helper in 
*  the Frame Buffer.
*
*  Display1_DIGIT_NUM_0 - holds the maximum digit number for the helper.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Display1_Write7SegDigit_0(uint8 digit, uint8 position) 
{
    static const uint16 CYCODE Display1_disp0[2u][7u] = {{Display1_H7SEG0_A, Display1_H7SEG0_B, Display1_H7SEG0_C,
    Display1_H7SEG0_D, Display1_H7SEG0_E, Display1_H7SEG0_F, Display1_H7SEG0_G}, {Display1_H7SEG1_A, Display1_H7SEG1_B,
    Display1_H7SEG1_C, Display1_H7SEG1_D, Display1_H7SEG1_E, Display1_H7SEG1_F, Display1_H7SEG1_G}};
    uint8 i;
    uint8 val;

    /* Check if digit is valid */
    if(digit <= 16u)
    {
        /* Do nothing: digit = digit */
    }
    else if(digit <= 0x39u)
    {
        digit -= 0x30u;
    }
    else if(digit <= 0x47u)
    {
        digit -= 0x37u;
    }
    else
    {
        digit = 0u;
    }

    /* Check if position<Display1_DIGIT_NUM_0, if not then do 'mod' operation */
    position = position % Display1_DIGIT_NUM_0;

    /* Find position counted right to left */
    position = Display1_DIGIT_NUM_0 - position - 1u;
    for(i = 0u; i < Display1_7SEG_PIX_NUM; i++)
    {
        /* Select pixel state for the digit base on value in look-up table */
        val = ((Display1_7SegDigits[digit] >> i) & Display1_PIXEL_STATE_ON); 
        Display1_WRITE_PIXEL(Display1_disp0[position][i], val);
    }
}


/*******************************************************************************
* Function Name: Display1_Write7SegNumber_0
********************************************************************************
*
* Summary:
*  This function displays a 16-bit integer value on a 1 to 5 digit 7 segment
*  display. The user must have defined what portion of the displays segments
*  make up the 7 segment display portion in the customizer. Multiple, separate 7
*  segment displays can be created in the frame buffer and are addressed through
*  the index (n) in the function name. Function/s only included if component 7
*  segment wizard defines the 7 segment option.
*
* Parameters:  
*  value : unsigned integer value to be displayed.
*  position : Position of the least significant digit as counted right to left
*  starting at 0 on the right. If the defined display contains fewer digits
*  then the value requires for display for the most significant digit/s will
*  not be displayed.
*  mode : 0 = no leading 0s are displayed, 1 = leading 0s are displayed.
*
* Return: 
*  None.
*
* Global variables:
*  Display1_DIGIT_NUM_0 - holds the maximum digit number for the helper.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Display1_Write7SegNumber_0(uint16 value, uint8 position, uint8 mode) 
{ 
    uint8 i;
    uint8 num;

    position = position % Display1_DIGIT_NUM_0;

    /* While current digit position in the range of display keep processing the output */
    for(i = position; i < Display1_DIGIT_NUM_0; i++)
    {
        num = (uint8) (value % 10u);
        if((0u == value) && (0u == mode)) 
        {
            /* In case of 'no leading zeros' each extra digit will be cleared */ 
            Display1_Write7SegDigit_0(Display1_7SEG_BLANK_DIG, i);
        }
        else
        {
            /* Display subsequent digit or '0' if 'no leading zeros' mode */ 
            Display1_Write7SegDigit_0(num, i);
        }
        value /= 10u; 
    }
}
/* [] END OF FILE */
