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
uint16 dato=0;
char8 texto[10];
int contador=0;
int f=0,entrar=0,g=0;
int rpm=0;
float rev;
uint8 Boton_1=0;
uint8 Boton_2=0;
uint16 Slider=0;
uint8  dutty1=0;
uint8  dutty2=0;

CY_ISR (Conta){
   
    contador++;
     rpm=contador;
    //USB_PutString("c");
}

CY_ISR (Tempo){
    
    contador=0;
    //USB_PutString("a");
}

CY_ISR (publicar){
    
    USB_PutString(texto);
    
 
    
}


int main(void)
{
    CyGlobalIntEnable; 
    /* Iniciar Perifericos */
    USB_Start(0u,USB_3V_OPERATION);
    while(!USB_GetConfiguration());
    USB_CDC_Init();
    
    LCD_Start();
    PWM_1_Start();
    PWM_2_Start();
    CapSense_Start();
    CapSense_InitializeAllBaselines();
  
    
    Timer_Start();
   Timer_1_Start();
    isr_3_Start();
    isr_3_StartEx(publicar);
    isr_2_Start();
    isr_2_StartEx(Tempo);
    isr_1_Start();
    isr_1_StartEx(Conta);
    
    for(;;)
    {
        
     
        
        
        //Actuzalizar Estado del Sensor Capacitivo
        CapSense_UpdateEnabledBaselines();	
	    CapSense_ScanEnabledWidgets();
        while(CapSense_IsBusy() != 0){
              //Leer Estado de los botones
              
              //Leer estado del Slider
              Slider =(uint8)CapSense_GetCentroidPos(CapSense_LS__LS);
         
       if(Slider==255){
       dutty1=0;
       dutty2=0;
         LCD_Position(0,1);  
         LCD_PrintString("        ");
         LCD_Position(1,1);  
         LCD_PrintString("        ");
        PWM_1_WriteCompare(dutty1);
        PWM_2_WriteCompare(dutty2);
        CyDelay(30);
        sprintf(texto,"%0.3f,%0.3f\n",0.000,0.000);
    
        USB_PutString(texto);
      }

            if (Slider>60&&Slider!=255){
            dutty1=(int)Slider-50;
             LCD_Position(1,1);           
            LCD_PrintNumber(dutty1);
             LCD_Position(1,5);           
            LCD_PrintNumber(Slider);
            LCD_Position(0,1);  
            LCD_PrintString("derecha");
            PWM_1_WriteCompare(dutty1*5);
            PWM_2_WriteCompare(0);
            }
            if((Slider>50)&&(Slider<65)){
                  LCD_Position(0,1);  
                  LCD_PrintString("centro");
                  LCD_Position(1,1); 
                  dutty1=0;
                  dutty2=0;
                  //LCD_PrintNumber(Slider);
                  //LCD_Position(1,5);           
                  LCD_PrintNumber(dutty1);
                  PWM_1_WriteCompare(dutty1);
                  PWM_2_WriteCompare(dutty2);}
                if((Slider<30&&Slider>0)){
                   dutty2=30-Slider;
                   LCD_Position(0,1);  
                   LCD_PrintString("izquierda");
                   LCD_Position(1,1);           
                 //LCD_PrintNumber(Slider);
                 //LCD_Position(1,5);
                  LCD_PrintNumber(dutty2);
                  PWM_1_WriteCompare(0);
                  PWM_2_WriteCompare(dutty2*5);\
                  }
                  }
            CyDelay(100);
            LCD_ClearDisplay();
            
              if(contador==0){
                
                
        if (Slider>60&&Slider!=255){
        
       rev=(rpm*256.0)/60.0;
       if(pulsador_Read()==1){        
       sprintf(texto,"%0.3f,%0.3f\n",rev,0.000);
    
      
        //USB_PutString(texto);
     //   CyDelay(30);
        //rev=0;
        rpm=0;}}
    
    
       if((Slider<30&&Slider>0)){
    
       rev=(rpm*256.0)/60.0;
       if(pulsador_Read()==1){        
       sprintf(texto,"%0.3f,%0.3f\n",0.000,rev);
    
       
        //USB_PutString(texto);
     //   CyDelay(30);
        //rev=0;
        rpm=0;}
    
    }
        LCD_Position(1,4);
        LCD_PrintDecUint16(rev);
    
    
    }
            
    }
}

/* [] END OF FILE */
