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
#include "stdio.h"
#define BUFFER_LEN 

int main(void)
{   uint32 Valor_ADC1=0;
     float t1=0,t2=0,t3=0;
     char8 Texto[20];
   
    CyGlobalIntEnable;
   
    ADC1_Start();
    ADC1_StartConvert();
    UART_Start();
   char dato;
   
    for(;;)
    {
//         ADC1_IsEndConversion(ADC1_WAIT_FOR_RESULT);
//        Valor_ADC1 = ADC1_GetResult16();
//         t1=Valor_ADC1; 
//        
//          sprintf(Texto,"%0.3f", t1); 
//            UART_PutString("hola");
//            CyDelay(1000);

 

    
   }}

