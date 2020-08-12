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
#include "stdlib.h"



int main(void)
{  
    Display1_Start();
    CyGlobalIntEnable; /* Enable global interrupts. */
  
  
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    { 
        Display1_Write7SegDigit_0(0,0);
        CyDelay(1000);
        Display1_Write7SegDigit_0(0,1);
        CyDelay(1000);
      
       
    
    
      
    
    }
}





/* [] END OF FILE */
