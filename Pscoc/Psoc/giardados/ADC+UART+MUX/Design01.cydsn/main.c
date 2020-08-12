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

int enteros[3];
float32 voltiosADC[3];
char str[12];
char recibir;
int canal=0;
CY_ISR(Enviar){
if(canal==0){
  sprintf(str,"%.3f \n \r" ,voltiosADC[0]);
  UART_PutString(str);
}
if(canal==1){
  sprintf(str,"%.3f \n \r" ,voltiosADC[1]);
  UART_PutString(str);
}
if(canal==2){
  sprintf(str,"%.3f \n \r" ,voltiosADC[2]);
  UART_PutString(str);
}
}


CY_ISR(InterruptRX){

    recibir=UART_GetChar();
 if(recibir=='0'){
    canal=0;
 }
if(recibir=='1'){
    canal=1;
 }
if(recibir=='2'){
    canal=2;
 }

}


int main(void)
{
    CyGlobalIntEnable; 
    PWM_Start();
    MUX_Start();
    UART_Start();
    ADC_Start();
    
    isrRX_StartEx(InterruptRX);
    isrEnvio_StartEx(Enviar);
    for(;;)
    {
        MUX_FastSelect(0);
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        enteros[0]=ADC_GetResult32();
        ADC_StopConvert();
        
        MUX_FastSelect(1);
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        enteros[1]=ADC_GetResult32();
        ADC_StopConvert();
        
        MUX_FastSelect(2);
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        enteros[2]=ADC_GetResult32();
        ADC_StopConvert();
        
        voltiosADC[0]=ADC_CountsTo_Volts(enteros[0]);
        voltiosADC[1]=ADC_CountsTo_Volts(enteros[1]);
        voltiosADC[2]=ADC_CountsTo_Volts(enteros[2]);
        
        
        
        
        
        
        
        
    }
}


