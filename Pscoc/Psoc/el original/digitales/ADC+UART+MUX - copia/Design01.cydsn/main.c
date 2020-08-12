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
    
    UART_Start();
   
    
    
  
    for(;;)
    {
           
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
if(recibir=='3'){
    canal=3;
 }
if(recibir=='4'){
    canal=4;}
if(recibir=='5'){
    canal=5;

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
    UART_PutString(" \n \r");  
}
   
        
        
        
        
        
        
    }
}


