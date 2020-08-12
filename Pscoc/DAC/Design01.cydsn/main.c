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

int vdac=0,canal;
float32 vin;
char str[12],recibir;
uint32_t ADCin;

CY_ISR(aumentarV)

{
    
     vdac=vdac + 10;
    if(vdac>=255)
    {
    vdac=0;
    }
    VDAC8_SetValue(vdac);
    
}
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    
    israumentar_StartEx(aumentarV);
    
    
         UART_Start();
        VDAC8_Start();
        
        VDAC8_SetRange(VDAC8_RANGE_4V);
  
        ADC_Start();
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;){
    
     recibir=UART_GetChar();
 if(recibir=='a'){
    canal=0;
 }
    
if(canal==0){
 
 
  sprintf(str,"%3fcA \n \r" ,vin);

  UART_PutString(str);
}


    
       ADCin=ADC_GetResult32();
        vin= ADC_CountsTo_Volts(ADCin);
        
        
          LCD_Position(3,0);
        LCD_PrintString("DAC  input:   ");
        LCD_Position(3,11);
        sprintf(str,"%.3fv  ",vin);
        LCD_PrintString(str);
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
