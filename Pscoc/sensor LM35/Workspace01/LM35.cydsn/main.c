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

float32 temperatura;
int32 valor_adc,voltaje;
char valor[1];

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    ADC_Start();
    UART_Start();
    
   
    
    for(;;)
    {
           ADC_StartConvert();
           ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        valor_adc=ADC_GetResult32();
        voltaje=ADC_CountsTo_mVolts(valor_adc);
        temperatura=(voltaje/20);
        sprintf(valor,"%0.1f \n ",temperatura);
         UART_PutString(valor);
         CyDelay(1);
        
      
        
       

    }
}

/* [] END OF FILE */
