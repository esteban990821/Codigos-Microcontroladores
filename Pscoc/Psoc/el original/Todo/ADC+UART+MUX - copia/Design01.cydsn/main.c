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

int numero[5],dato=8,variable=1;
float32 voltiosADC[5];
char publicar[12];

char recibir;
int canal=6,pga=1;



int main(void)
{
    CyGlobalIntEnable; 
    
   
    MUX_Start();
    UART_Start();
    ADC_Start();
    PGA_Start();
    
   
    
    
  
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
        
recibir=UART_GetChar();
CyDelay(600);
 if(recibir=='x'){
    canal=0;
 }
if(recibir=='y'){
    canal=1;
 }
if(recibir=='z'){
    canal=2;
 }
if(recibir=='1'){
pga=1;
}
if(recibir=='2'){
pga=2;
}
    
if(recibir=='4'){  
pga=4;
}
if(recibir=='8'){
pga=8;
}

if(recibir=='d')  {
dato=0;
}
if(recibir=='a')  {
dato=1;
}

        
  if(dato==0)  {
if(canal==0){
    if(D0_Read()==1){
     UART_PutString("Dx=T \n \r"); 
      CyDelay(500);
    }
    else{
    UART_PutString("Dx=F \n \r");  
      CyDelay(500);
    }
}
if(canal==1){
    if(D1_Read()==1){
     UART_PutString("Dy=T \n \r"); 
      CyDelay(500);
    }
    else{
    UART_PutString("Dy=F \n \r");  
      CyDelay(500);
    }
}
if(canal==2){
    if(D2_Read()==1){
     UART_PutString("Dz=T \n \r"); 
      CyDelay(500);
    }
    else{
    UART_PutString("Dz=F \n \r");  
      CyDelay(500);
    }
}

}
if(dato==1){
if(pga==2){
PGA_SetGain(2);}
if(pga==4){
PGA_SetGain(4);}
if(pga==8){
PGA_SetGain(8);}
if(pga==1){
PGA_SetGain(1);}
if(canal==0){
  sprintf(publicar,"%3dAx \n \r" ,numero[0]);
  UART_PutString(publicar);
  CyDelay(100);
}
if(canal==1){
     
     sprintf(publicar,"%3dAy \n \r" ,numero[1]);
     UART_PutString(publicar); 
     CyDelay(100);
    
}
if(canal==2){
     sprintf(publicar,"%3dAz \n \r" ,numero[2]);
     UART_PutString(publicar);
     CyDelay(100);
}

}
   
        
        
        
        
      
    }
}


