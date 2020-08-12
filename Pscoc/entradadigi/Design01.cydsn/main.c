/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>
#define RING_BUFFER_SIZE    (512U)

uint8_t rxRingBuffer[RING_BUFFER_SIZE];
 char8 string;





int main(void)
{
  char buffer[8];

    UART_Start();
 char recibir;

    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {

buffer[2] = UART_GetChar();


        
   if(recibir == '2')
    {
      Pin1_Read();
     if (Pin1_Read()==1)
    {
        UART_PutString("true");
    }
        else if(Pin1_Read()==0)
        {
            UART_PutString("false");
        } 
    }
       if(recibir == '2')
    {
      Pin2_Read();
     if (Pin2_Read()==1)
    {
        UART_PutString("true");
    }
        else if(Pin2_Read()==0)
        {
            UART_PutString("false");
        } 
    } 
        /* Place your application code here. */

    
    if(recibir=='3')
    {
      Pin3_Read();
     if (Pin3_Read()==1)
    {
        UART_PutString("true");
    }
        else if(Pin3_Read()==0)
        {
            UART_PutString("false");
        } 
    }
    if(recibir== '4')
    {
      Pin4_Read();
     if (Pin4_Read()==1)
    {
        UART_PutString("true");
    }
        else if(Pin4_Read()==0)
        {
            UART_PutString("false");
        } 
    }
    
    
}
    
}

/* [] END OF FILE */
