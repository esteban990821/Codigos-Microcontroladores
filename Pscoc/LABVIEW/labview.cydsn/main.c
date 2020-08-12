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



char recibir, cadena[],cadena2[4],cadena3[4], longitud=0, str[12], publicar[12],publicar1[12],publicar2[12]; 
int bandera=0, canal=0, ganancia=0, signal,numero[12],dato,valor,cuenta,acu=0,DAC,VDAC,CMPValue,guardado1,guardado2;
float32 Vin,V;
void Input();
void Output();
void Contador();
void PWM();


CY_ISR(interrupcion){
    
    recibir= UART_GetChar();
    UART_PutChar(recibir);
    
    
    if (recibir =='I'){
        bandera=0;
        dato=1;
        bandera=1;
        
       
    }
   if (recibir =='O'){
        dato=1;
        bandera=2;
        
   
        
    }
 if (recibir =='C'){
        dato=1;
        bandera=3;
         
    }
if (recibir =='P'){
        dato=1;
        bandera=4;
         
    }
   if(recibir ==' '){
        dato=1;
        bandera=0;
      longitud=5;  
    CMPValue=0;
   
    }
    
    if (dato == 1){
        cadena[longitud] = recibir;
        longitud=longitud+1;
        
        if(longitud==7){
            longitud=0;
        
            
        }
    
    }
     

}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    ADC_Start(); 
    PGA_Start();
    PWM1_Start();
    PWM0_Start();
    MUX_Start();
    UART_Start();
    VDAC1_Start();
    VDAC1_SetRange(VDAC1_RANGE_4V);
    VDAC2_Start();
    VDAC2_SetRange(VDAC2_RANGE_4V);
    isrRx_Start();
    isrRx_StartEx(interrupcion);
    
  
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        
        
         switch (bandera){
            case 0:
            break;
          
            case 1:
            Input();
            break;
            
            case 2:
            Output();
            break;
            
            case 3:
            Contador();
            break;
            
            case 4:
            PWM();
            break;
            
        
        }
        
        
       
        
        }
     
       
    }

void Input(){

 if(cadena[1]=='a'){
            
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
        
        if(cadena[4]=='1'){
        PGA_SetGain(1);
        }
        if(cadena[4]=='2'){
        PGA_SetGain(2);
        }
        if(cadena[4]=='4'){
        PGA_SetGain(4);
        }
        if(cadena[4]=='8'){
        PGA_SetGain(8);
        }
        if (cadena[2]=='0'){
        if(cadena[6]=='\r'){    
        sprintf(publicar,"%3dA0 \n \r" ,numero[0]);
        UART_PutString(publicar);
        CyDelay(100);
    
        
        }}
        if(cadena[2]=='1'){
         if(cadena[6]=='\r'){
        sprintf(publicar,"%3dA1 \n \r" ,numero[1]);
        UART_PutString(publicar);
        CyDelay(100);
        }
        }
        
        if(cadena[2]=='2'){
        if(cadena[6]=='\r'){
        sprintf(publicar,"%3dA2 \n \r" ,numero[2]);
        UART_PutString(publicar);
        CyDelay(100);
        }
        }
        }
if(cadena[1]=='d'){  
if(cadena[2]=='0'){  
if(cadena[6]=='\r'){
if(D0_Read()==1){
     UART_PutString("Entrada D0=T \n \r"); 
      CyDelay(500);
    }
    else{
    UART_PutString("Entrada D0=F \n \r");  
      CyDelay(500);
    }
    
}
}
if(cadena[2]=='1'){    
if(cadena[6]=='\r'){
if(D1_Read()==1){
     UART_PutString("Entrada D1=T \n \r"); 
      CyDelay(500);
    }
    else{
    UART_PutString("Entrada D1=F \n \r");  
      CyDelay(500);
    }
    
}
}
if(cadena[2]=='2'){
if(cadena[6]=='\r'){
if(D2_Read()==1){
     UART_PutString("Entrada D2=T \n \r"); 
      CyDelay(500);
    }
    else{
    UART_PutString("Entrada D2=F \n \r");  
      CyDelay(500);
    }
 
}
}
    
    
    
    
    
      }  





}
void Output(){

if(cadena[1]=='d'){
if(cadena[2]=='0'){
if(cadena[4]=='T'){
if(cadena[6]=='\r'){
        SalidaD0_Write(1);
      UART_PutString("Salida D0=T \n \r"); 
      CyDelay(500);
         }
    }
if(cadena[4]=='F'){
if(cadena[6]=='\r'){
        SalidaD0_Write(0);
      UART_PutString("Salida D0=F \n \r"); 
      CyDelay(500);
        }
    }
 }
if(cadena[2]=='1'){
if(cadena[4]=='T'){
if(cadena[6]=='\r'){
        SalidaD1_Write(1);
      UART_PutString("Salida D1=T \n \r"); 
      CyDelay(500);}
    }
if(cadena[4]=='F'){
if(cadena[6]=='\r'){
        SalidaD1_Write(0);
      UART_PutString("Salida D1=F \n \r"); 
      CyDelay(500);
        }
    }
 }
if(cadena[2]=='2'){
if(cadena[4]=='T'){
if(cadena[6]=='\r'){
        SalidaD2_Write(1);
        UART_PutString("Salida D2=T \n \r"); 
        CyDelay(500);
        }
    }
if(cadena[4]=='F'){
if(cadena[6]=='\r'){
        SalidaD2_Write(0);
        UART_PutString("Salida D2=F \n \r"); 
        CyDelay(500);
        }
    }
 }

}
if(cadena[1]=='a'){
    
if(cadena[2]=='0'){
     for(int i=0;i<=3;i++){
     cadena2[i]=cadena[i+3];
   }
     
    DAC=atoi(cadena2);
    VDAC=(DAC*255)/4095;
    
if(cadena[0]=='\r'){
     Vin=(VDAC*4.3)/255;
     sprintf(publicar,"%0.3fA0 \n \r" ,Vin);
        VDAC1_SetValue(VDAC);
        UART_PutString(publicar);
        CyDelay(100);
      VDAC1_SetValue(VDAC);
      }
    }
    
if(cadena[2]=='1'){
     for(int i=0;i<=3;i++){
     cadena2[i]=cadena[i+3];
   }
     
    DAC=atoi(cadena2);
    VDAC=(DAC*255)/4095;
    
if(cadena[0]=='\r'){
        Vin=(VDAC*4.3)/255;
        sprintf(publicar,"%0.3fA1 \n \r" ,Vin);
        VDAC2_SetValue(VDAC);
        UART_PutString(publicar);
        CyDelay(100);
      }
    }
}
}


void Contador(){
     if(cadena[1]=='l'){
     if(cadena[3]=='0'){

     Counter1_ReadCounter();
     guardado1=Counter1_ReadCapture();
     if(cadena[5]=='\r'){
     sprintf(publicar1,"%3dC0 \n \r" ,guardado1);
     UART_PutString(publicar1);
     CyDelay(100);

    }
    }
    }
    
     if(cadena[1]=='l'){
     if(cadena[3]=='1'){

     Counter2_ReadCounter();
     guardado2=Counter2_ReadCapture();
     if(cadena[5]=='\r'){
     sprintf(publicar2,"%3dC1 \n \r" ,guardado2);
     UART_PutString(publicar2);
     CyDelay(100);

    }
    }
    }
    
    
    
if(cadena[1]=='i'){
if(cadena[3]=='0'){
     Counter1_Start();
Counter1_ReadCounter();
guardado1=Counter1_ReadCapture();
if(cadena[5]=='\r'){
 sprintf(publicar1,"%3dC0 \n \r" ,guardado1);
 UART_PutString(publicar1);
 CyDelay(100);

}

}
if(cadena[3]=='1'){
     Counter2_Start();
Counter2_ReadCounter();
guardado2=Counter2_ReadCapture();
if(cadena[5]=='\r'){
 sprintf(publicar2,"%3dC1 \n \r" ,guardado2);
 UART_PutString(publicar2);
 CyDelay(100);

}

}
}
if(cadena[1]=='s'){
if(cadena[3]=='0'){  
if(cadena[5]=='\r'){
Counter1_Stop();
UART_PutString(publicar1);
 CyDelay(100);
}
}
if(cadena[3]=='1'){  
if(cadena[5]=='\r'){
Counter2_Stop();
UART_PutString(publicar2);
 CyDelay(100);
}
}
}
if(cadena[1]=='r'){
if(cadena[3]=='0'){
if(cadena[5]=='\r'){
Counter1_WriteCounter(0);
sprintf(publicar1,"%3dC0 \n \r" ,0);
UART_PutString(" 0C0\n \r ");
CyDelay(100);
}
}
if(cadena[3]=='1'){
if(cadena[5]=='\r'){
Counter2_WriteCounter(0);
sprintf(publicar2,"%3dC1 \n \r" ,0);
UART_PutString(" 0C1\n \r ");
CyDelay(100);
}
}
}
}

void PWM(){
if(cadena[1]=='0'){
 if(cadena[2]=='1'){
    for(int i=0;i<=3;i++){
     cadena3[i]=cadena[i+3];}
 
     CMPValue=atoi(cadena3);
    
    
  if(cadena[0]=='\r'){  
    PWM0_WritePeriod(999);
    PWM0_WriteCompare(CMPValue*999/1100); 

      CyDelay(1);
   
    
sprintf(publicar2,"%3dPWM0,1kh \n \r" ,CMPValue);  
UART_PutString(publicar2);
CyDelay(100);
V=(CMPValue*100/1000)*4.7/100;
sprintf(publicar1,"%0.3fV \n \r" ,V);
UART_PutString(publicar1);
 
}
 
}

    if(cadena[2]=='5'){
    for(int i=0;i<=3;i++){
    cadena3[i]=cadena[i+3];}
 
     CMPValue=atoi(cadena3);
    
    if(cadena[0]=='\r'){  
    PWM0_WritePeriod(199);
    PWM0_WriteCompare(CMPValue*199/1024); 
    
    
 
  
    
    
sprintf(publicar2,"%3dPWM0,5kh \n \r" ,CMPValue);  
UART_PutString(publicar2);
V=(CMPValue*100/5000)*4.7/100;
sprintf(publicar1,"%0.3fV \n \r" ,V);
UART_PutString(publicar1);


    
}

}
    
    }

if(cadena[1]=='1'){
 if(cadena[2]=='1'){
    for(int i=0;i<=3;i++){
     cadena3[i]=cadena[i+3];}
 
     CMPValue=atoi(cadena3);
    
    
  if(cadena[0]=='\r'){  
    PWM1_WritePeriod(999);
    PWM1_WriteCompare(CMPValue*999/1100); 
      
   
    
sprintf(publicar2,"%3dPWM1,1kh \n \r" ,CMPValue);  
UART_PutString(publicar2);
CyDelay(100);
V=(CMPValue*100/1000)*4.7/100;
sprintf(publicar1,"%0.3fV \n \r" ,V);
UART_PutString(publicar1);
 
}
 
}

 if(cadena[2]=='5'){
    for(int i=0;i<=3;i++){
     cadena3[i]=cadena[i+3];}
 
     CMPValue=atoi(cadena3);
    
  if(cadena[0]=='\r'){
    
    PWM1_WritePeriod(199);
    PWM1_WriteCompare(CMPValue*199/1024);
    
    
    
    
    CyDelay(1);
     
    
sprintf(publicar2,"%3dPWM1,5kh \n \r" ,CMPValue);  
UART_PutString(publicar2);
V=(CMPValue*100/5000)*4.7/100;
sprintf(publicar1,"%0.3fV \n \r" ,V);
UART_PutString(publicar1);
    
}

}
    
    }









}





/* [] END OF FILE */
