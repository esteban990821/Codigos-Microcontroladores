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

int numero[5];
float32 voltiosADC[5];
char publicar[12];
char recibir;
int canal=0;
CY_ISR(Enviar){
if(canal==0){
 
  sprintf(publicar,"%3d \n \r" ,numero[0]);
  UART_PutString(publicar);
}
if(canal==1){
  sprintf(publicar,"%.3f \n \r" ,voltiosADC[1]);
  UART_PutString(publicar);
}
if(canal==2){
  sprintf(publicar,"%.3f \n \r" ,voltiosADC[2]);
  UART_PutString(publicar);
}
if(canal==3){
  sprintf(publicar,"%.3f \n \r" ,voltiosADC[3]);
  UART_PutString(publicar);
}
if(canal==4){
  sprintf(publicar,"%.3f \n \r" ,voltiosADC[4]);
  UART_PutString(publicar);
}
}


CY_ISR(Recibir){

    recibir=UART_GetChar();
 if(recibir=='a'){
    canal=0;
 }
if(recibir=='b'){
    canal=1;
 }
if(recibir=='c'){
    canal=2;
 }
if(recibir=='d'){
    canal=3;
 }
if(recibir=='e'){
    canal=4;
 }


}


int main(void)
{
    CyGlobalIntEnable; 
    PWM_Start();
    MUX_Start();
    UART_Start();
    ADC_Start();
    
    isrRX_StartEx(Recibir);
    isrEnvio_StartEx(Enviar);
    for(;;)
    {
        MUX_FastSelect(0);
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        numero[0]=ADC_GetResult32();
        ADC_StopConvert();
        
        MUX_FastSelect(1);
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        numero[1]=ADC_GetResult32();
        ADC_StopConvert();
        
        MUX_FastSelect(2);
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        numero[2]=ADC_GetResult32();
        ADC_StopConvert();
        
        MUX_FastSelect(3);
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        numero[3]=ADC_GetResult32();
        ADC_StopConvert();
        
        MUX_FastSelect(4);
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        numero[4]=ADC_GetResult32();
        ADC_StopConvert();
        
        voltiosADC[0]=ADC_CountsTo_Volts(numero[0]);
        voltiosADC[1]=ADC_CountsTo_Volts(numero[1]);
        voltiosADC[2]=ADC_CountsTo_Volts(numero[2]);
        voltiosADC[3]=ADC_CountsTo_Volts(numero[3]);
        voltiosADC[4]=ADC_CountsTo_Volts(numero[4]);
        
        
        
        
        
        
        
        
    }
}


