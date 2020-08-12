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
#include "project.h" //Libreria del hardware de Psoc.
#include "stdio.h"// Libreria del ADC.
#include "stdlib.h"
// Inicializacion de las clases. 
void Celsius();
void Fahrenheit();
// Inicializacion de las varibales, char, int, float.
char recibir,publicar[12];
int bandera=0,acu=0,ValorADC,ValorADC2, Vdisplay1, Vdisplay2,VoltajeADC=0,tempC=0,tempF=0;
float TempFfloat,TempCfloat;

CY_ISR(interrupcion){//intterupcion del puerto UART para recibir datos.
    //Se recibe el dato y se publica al instante.
    recibir= UART_GetChar();
    UART_PutChar(recibir);
 
    if (recibir =='C'){
         acu=1;}
    if (recibir =='F'){
         acu=0;}
}

int main(void)
{   
    
    
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    //Inicializacion de los Bloques y las interrupcion.
    isrRx_Start();
    isrRx_StartEx(interrupcion);
    Display1_Start();
    UART_Start();
    ADC_Start();
    
    for(;;)
    { 
     //condicionales para definir la activacion de Void. 
     if(acu==2){
     acu=0;}
     if(Pulsador_Read()==1){
     acu=acu+1;}
     if(acu==1){
     bandera=1;}
     if(acu==0){
     bandera=2;}  
     if(recibir ==' '){// si se recibe un espacio se detendra la ejecucion del programa.
     bandera=0;}
    
           switch (bandera){//dependiendo delvalor de la vandera se ejecutara un void diferente.
            case 0:
            break;
            
            case 1:
            Celsius();
            break;
            
            case 2:
            Fahrenheit();
            break;
              
        }
       
        ADC_StartConvert();//Inicia la conversion analogo digiral
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        ValorADC=ADC_GetResult32();//se guarda en una varible tipo entero, el valor obtenido.
        ADC_StopConvert();
        
        tempC=ValorADC*100/14340;//se guarda la varible el valor ,en este caso se utiliza 14345, debido a que la resolucion en bits de 1v es hasta este valor.
        TempCfloat=(ValorADC*100)/14340;//se aclara que esto varia depentendiendo del tipo de sensor a utilizar
        
      
    }
}

void Celsius(){
  //se enciende el Led1 y se apaga el Led2
  SLED1_Write(1);
  SLED2_Write(0);
  
  
  if(recibir =='\r'){ //solo hasta que se oprima un enter se enviara el vaor por el terminal, debido a la condicion.
  sprintf(publicar,"Temperatura(celsius): %0.2f \n \r" ,TempCfloat);
  UART_PutString(publicar);}

  CyDelay(100);
  Vdisplay1=tempC/10;//se optiene el primer numero de los dos que conforman el valor entero de la temperatura.
  Vdisplay2=tempC%10;//se obtiene el segundo numero.

  Display1_Write7SegDigit_0(Vdisplay1,0);//se publica en el primer Display el valor numeico.
  Display1_Write7SegDigit_0(Vdisplay2,1);//se publica en el segundo Display.
}

void Fahrenheit(){
//se predende el segundo Led se apaga el primero
  SLED2_Write(1);
  SLED1_Write(0);
//ecuacion para pasar de grados Celsius a grados Fahrendeit
  tempF=((tempC*9)/5)+32;
  TempFfloat=((TempCfloat*9)/5)+32;

  if(recibir =='\r'){
  sprintf(publicar,"Temperatura(Fahrenheit): %0.2f \n \r" ,TempFfloat);
  UART_PutString(publicar);}

  CyDelay(100);
  Vdisplay1=tempF/10;
  Vdisplay2=tempF%10;

  Display1_Write7SegDigit_0(Vdisplay1,0);
  Display1_Write7SegDigit_0(Vdisplay2,1);    
}