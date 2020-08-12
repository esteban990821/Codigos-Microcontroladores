//Define Librerias
#include "project.h"
#include "stdio.h"
#define BUFFER_LEN  64u //Tamaño del buffer

int main(void)
{
    //Variables para Manejar el Buffer
    uint32 Valor_ADC1=0;
    uint32 Valor_ADC2=0;
    uint16 Cuenta;
    uint8 buffer[BUFFER_LEN];
    char8 Texto[20];
    float t1=0,t2=0,t3=0;
    //Habilita las Interrupciones
    CyGlobalIntEnable;
    //Estos Tres parametros Van en grupo
    //Se encargar de que el computador detecte el USB-Serial
    ADC_1_Start();
    ADC_1_StartConvert();
    ADC_2_Start();
    ADC_2_StartConvert();
    USB_Start(0u, USB_3V_OPERATION);	
    while(!USB_GetConfiguration());
    USB_CDC_Init();
    /* Iniciar LCD */
   
    for(;;)
    {
       
     ADC_1_IsEndConversion(ADC_1_WAIT_FOR_RESULT);
        Valor_ADC1 = ADC_1_GetResult16();
      t1=  Valor_ADC1; 
        ADC_2_IsEndConversion(ADC_2_WAIT_FOR_RESULT);
        Valor_ADC2 = ADC_2_GetResult16();
      t2=  Valor_ADC2; 
                    
      
                             
      if(Pulsador_Read()==1){
        t3=1;
     sprintf(Texto,"%0.3f,%0.3f,%0.3f\n", t1,t2,t3); 
            USB_PutString(Texto);
            CyDelay(1000);
    }
    else{
        
        t3=0;
        sprintf(Texto,"%0.3f,%0.3f,%0.3f", t1,t2,t3); 
            USB_PutString(Texto);}
                 
      
    
    }
}

/* [] END OF FILE */
