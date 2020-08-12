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
int x=0,a=0;
char8 valort[10];



int main(void)
{  
  
    PWM_1_1_Start();
    PWM_1_2_Start();
    PWM_2_1_Start();
    PWM_2_2_Start();
   
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
   
    for(;;)
    {  
        if(pulsador1_Read()==1){
    a=1;
   }
        else{a=0;}
      
        
      
        if(a==1){
       
         PWM_1_1_WriteCompare(0);
         PWM_1_2_WriteCompare(0);
         PWM_2_1_WriteCompare(0);
         PWM_2_2_WriteCompare(0);
        
         CyDelay(1000);
     
         PWM_1_1_WriteCompare(0);
         PWM_1_2_WriteCompare(80);
         PWM_2_1_WriteCompare(0);
         PWM_2_2_WriteCompare(80);
         CyDelay(1000);
        
         PWM_1_1_WriteCompare(50);
         PWM_1_2_WriteCompare(0);
         PWM_2_1_WriteCompare(0);
         PWM_2_2_WriteCompare(50);
        CyDelay(1000);
        }
        if(pulsador1_Read()==0){
            led_Write(0);
         PWM_1_1_WriteCompare(100);
         PWM_1_2_WriteCompare(0);
         PWM_2_1_WriteCompare(100);
         PWM_2_2_WriteCompare(0);
        }
        
        
        
    }
    }
    


/* [] END OF FILE */
