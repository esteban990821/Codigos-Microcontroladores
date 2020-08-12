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

  char dato,texto;

int numero;
int PWM=100;


  

    
    
    


int main(void)

{
    CyGlobalIntEnable; /* Enable global interrupts. */
        
        PWM1_Start();
        PWM_Start();
        Clock_1_Start();
        UART_1_Start();
       
        
      
            PWM_WriteCompare1(0);
            PWM_WriteCompare2(0);
            PWM1_WriteCompare1(0);
            PWM1_WriteCompare2(0);

            
        
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {  
        dato=UART_1_GetChar();
     
   if(dato=='w'){
PWM=80;
}
else if(dato=='x'){
PWM=150;
}
        if(dato=='e'){
        numero=1;
        }
        if(dato=='d'){
        numero=0;
        }
        
        if(numero==1){
        
        if(dato=='b'){
            led_Write(1);
            PWM_WriteCompare1(PWM);
            PWM_WriteCompare2(0);
            PWM1_WriteCompare1(0);
            PWM1_WriteCompare2(PWM);
        } 
        else if(dato=='a'){
            led_Write(0);
            PWM_WriteCompare1(0);
            PWM_WriteCompare2(PWM);
            PWM1_WriteCompare1(PWM);
            PWM1_WriteCompare2(0);
        }
        else if(dato=='c')
        {
             led_Write(0);
            PWM_WriteCompare1(PWM);
            PWM_WriteCompare2(0);
            PWM1_WriteCompare1(PWM);
            PWM1_WriteCompare2(0);
        }
        }
        else if(numero==0){
        
            PWM_WriteCompare1(0);
            PWM_WriteCompare2(0);
            PWM1_WriteCompare1(0);
            PWM1_WriteCompare2(0); 
        }
        if(filtro1_Read()==1){
        UART_1_PutString("S");
        CyDelay(1000);}
        if(filtro2_Read()==1){
        UART_1_PutString("P");
        CyDelay(1000);}
    }
       
    
}

    

