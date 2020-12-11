/*
 * File:   Main.c
 * Author: francisco
 *
 * Created on 25 de marzo de 2019, 04:21 PM
 */


#include <xc.h>
#include <stdlib.h>
#include "configuracion_bite.h"
#include "conversion.h"
#include "PWM.h"
#include "delays.h"
#include "senoidal.h"
#include "teclado.h"
#include "pantalla.h"
#include "Funciones.h"
#include "Triangular.h"

#define XTAL_FREQ 4000000 //8Mhz


int q,w,e,r;
//int a=1,s,d,f,g;
//unsigned char frecuencia[10],ciclo[10],columna=0,cantidad=0,fila=0,cadena[10],cad[10];

void main() {
//PWM_generar(50,5000);
char key;    
//OSCCON= 0b01100011;        //configuración del Oscilador
OSCCON=0b01010111;
ANSELD=0;
TRISA=0xF0 ;
ANSELA=0;
LATA=0;
Lcd_Init();
int_teclado();
do{
    
 
 
    key = Recuperar();

    
    
 if(key==' '){
      q=1; 
      do{
      int_teclado();
      Lcd_Init();
      Lcd_Cmd(LCD_CLEAR);
      Lcd_Cmd(LCD_CURSOR_OFF);
      Lcd_Out2(1,1,"Universidad de ");
      tm_1s();
      Lcd_Out2(2,3,"Guanajuato");
      tm_1s();
      Lcd_Cmd(LCD_CLEAR);
      Lcd_Out2(1,1,"Proyecto Final");
      Lcd_Out2(2,3,"Generador");
      tm_1s();
      Lcd_Cmd(LCD_CLEAR);
      Lcd_Cmd(LCD_CURSOR_OFF); 
      __delay_ms(100);
      key=Recuperar();
      if(key=='D' | key=='0'){
          q=0;
      }
      }while(q==1);    
    }

 // Menu de funciones   
if(key=='D'){
        key = Recuperar(); 
        q=1;
        do{
            Lcd_Init();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"A.-Cuadrada");
            Lcd_Out2(2,1,"B.-Senoidal");
            tm_1s();
            key = Recuperar();  
            Lcd_Init();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"C.-Triangular");
            tm_1s();
            key = Recuperar();  
       
      //menu triangular
        if(key=='C'){
        w=1;
        Lcd_Init();
        Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_CURSOR_OFF);
        int_teclado();  
        key=Recuperar();
         do{
           Lcd_Init();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"A.-Senal 1");
            Lcd_Out2(2,1,"B.-Señal 2");
            tm_1s();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"C.-Senal 3");
            tm_1s();
            key = Recuperar();
            
         if(key=='A'){
            q=1;
            Lcd_Init();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"A.-Senal 1");
             int_teclado();  
             key=Recuperar();
            do{
            TRIANGULAR_GENERAR_1();
            key=Recuperar();
            if(key=='*'){q=0;} 
             }while(q==1);
         }    
            
            
      if(key=='B'){
            q=1;
            Lcd_Init();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"B.-Senal 2");
             int_teclado();  
             key=Recuperar();
            do{
            TRIANGULAR_GENERAR_2();
            key=Recuperar();
            if(key=='*'){q=0;} 
             }while(q==1);
         }      
           
            if(key=='C'){
            q=1;
            Lcd_Init();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"C.-Senal 3");
             int_teclado();  
             key=Recuperar();
            do{
            TRIANGULAR_GENERAR_3();
            key=Recuperar();
            if(key=='*'){q=0;} 
             }while(q==1);
         }  
            
         if(key=='D'){w=0;}
         }while(w==1);
     }   
     
            
            
      //Menu seno      
        if(key=='B'){
        w=1;
        Lcd_Init();
        Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_CURSOR_OFF);
        int_teclado();  
        key=Recuperar();
         do{
           Lcd_Init();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"A.-Senal 1");
            Lcd_Out2(2,1,"B.-Señal 2");
            tm_1s();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"C.-Senal 3");
            tm_1s();
            key = Recuperar();
            
         if(key=='A'){
            q=1;
            Lcd_Init();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"A.-Senal 1");
            int_teclado();  
            key=Recuperar();
            do{
            SENO_GENERAR_1();
            key=Recuperar();
            if(key=='*'){q=0;} 
             }while(q==1);
         }    
            
            
      if(key=='B'){
            q=1;
            Lcd_Init();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"B.-Senal 2");
             int_teclado();  
             key=Recuperar();
            do{
            SENO_GENERAR_2();
            key=Recuperar();
            if(key=='*'){q=0;} 
             }while(q==1);
         }      
           
            if(key=='C'){
            q=1;
            Lcd_Init();
            Lcd_Cmd(LCD_CLEAR);
            Lcd_Cmd(LCD_CURSOR_OFF);
            Lcd_Out2(1,1,"C.-Senal 3");
             int_teclado();  
             key=Recuperar();
            do{
            SENO_GENERAR_3();
            key=Recuperar();
            if(key=='*'){q=0;} 
             }while(q==1);
         }  
            
         if(key=='D'){w=0;}
         }while(w==1);
     }   
     
// Menu del pwm
 if(key=='A'){
        w=1;

        do{
        Lcd_Init();
        Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_CURSOR_OFF);
        Lcd_Out2(1,1,"1.-Datos");
        Lcd_Out2(2,1,"2.-Comenzar");
        tm_1s();
        key=Recuperar();          
  if(key=='1') { 
        r=1;
        do{
        Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_CURSOR_OFF);
        Lcd_Out2(1,1,"A.-Frecuencia");
        Lcd_Out2(2,1,"B.-Ciclo");
        tm_1s();
        key=Recuperar();
    
        if(key=='A'){
            
            int zx=1;
        Frecuencia(frecuencia);
        Imprimir_pantalla(frecuencia);
        s=atoi(frecuencia);
            do{

                int_teclado(); 
                key=Recuperar();
                tm_1s();
             if(key=='#'){
                  zx=0;
              }  
            }while(zx==1);
        }
     if(key=='B'){
            int zx=1;
            Ciclo(ciclo);
             Imprimir_pantalla(ciclo);
             t=atoi(ciclo);
            do{

                key=Recuperar();  
              if(key=='#'){
                  zx=0;
              }  
            }while(zx==1);
        }   
  if(key=='*'){
            r=0;
        }    
          }while(r==1);
        }
        
        //-----------------------------------------
  if(key=='2') { 
                            Lcd_Init();
                            Lcd_Cmd(LCD_CLEAR);
                            Lcd_Cmd(LCD_CURSOR_OFF);
                            Lcd_Out2(1,1,"Fre: ");
                            Lcd_Out2(1,13,"Hz");
                             //fila=0; columna=6;
                            cantidad= Conv_Entero(s,cadena);
                            //lcd_Cadena(cadena,&columna,&fila);
                             Lcd_Out(1,8,cadena);
                            Lcd_Out2(2,1,"Ciclo: ");
                            Lcd_Out2(2,12,"%");
                            //fila=1; columna=8;
                            cantidad= Conv_Entero(t,cadena);
                            //lcd_Cadena(cadena,&columna,&fila);
                            Lcd_Out(2,8,cadena);
                             PWM_generar(t,s);

                             key=Recuperar();
        r=1;
            do{
            
        key=Recuperar();
     

        if(key=='*'){
           
            r=0;
        }    
            
            }while(r==1);
        }
        
        
        if(key=='D')
        {
                   
            Lcd_Cmd(LCD_CLEAR);
            w=0;
        }
        }while(w==1);
        
    };
        
        if(key=='#'){
            Lcd_Cmd(LCD_CLEAR);
            q=0;
        }        
            }while(q==1);        
        }
  // apagar LCD      
    if(key=='0'){
        q=1;
        Lcd_Init();
        Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_CURSOR_OFF);
        Lcd_Out2(1,1,"Adios");
        tm_1s();
        key = Recuperar();
        do{
        Lcd_Init();
        Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_CURSOR_OFF);
        Lcd_Cmd(LCD_TURN_OFF);
        key = Recuperar();
        
      if(key=='*'){
        q=0;
    }       
        }while(q==1);
   
    }

}while(1);
}
