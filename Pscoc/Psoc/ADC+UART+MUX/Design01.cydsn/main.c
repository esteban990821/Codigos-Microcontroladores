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

int numero[5],dato;
float32 voltiosADC[5];
char publicar[12];
char recibir;
int canal=0;
CY_ISR(Enviar){
if(canal==0){
 
  sprintf(publicar,"%3dc0 \n \r" ,numero[0]);
  UART_PutString(publicar);
}
if(canal==1){
     dato=numero[1]*2;
     if(dato<65536){
     sprintf(publicar,"%3dc1 \n \r" ,numero[1]*2);
     UART_PutString(publicar);

       }
     else if(dato>=65536){
     UART_PutString("65536c1 \n \r");}
}
if(canal==2){
  dato=numero[2]*4;
     if(dato<65536){
     sprintf(publicar,"%3dc2 \n \r" ,numero[2]*4);
     UART_PutString(publicar);

       }
     else if(dato>=65536){
     UART_PutString("65536c2 \n \r");}
}
if(canal==3){
  dato=numero[3]*8;
     if(dato<65536){
     sprintf(publicar,"%3dc3 \n \r" ,numero[3]*8);
     UART_PutString(publicar);

       }
     else if(dato>=65536){
     UART_PutString("65536c3 \n \r");};
}
if(canal==4){
     dato=numero[4]*16;
     if(dato<65536){
     sprintf(publicar,"%3dc4 \n \r" ,numero[4]*16);
     UART_PutString(publicar);

       }
     else if(dato>=65536){
     UART_PutString("65536c4 \n \r");}
}
}


CY_ISR(Recibir){

    recibir=UART_GetChar();
 if(recibir==0){
    canal=1;
 }
if(recibir==1){
    canal=2;
 }
if(recibir==2){
    canal=2;
 }
if(recibir==3){
    canal=3;
 }
if(recibir==4){
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


