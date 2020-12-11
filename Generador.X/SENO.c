/*
 * File:   SENO.c
 * Author: francisco
 *
 * Created on 17 de abril de 2019, 10:24 AM
 */
#include "senoidal.h"
void SENO_GENERAR_1(){
    
    OSCCON=0b01010111;
     char key;
    int i;
    int valoresSeno [10]= {16,25,30,30,25,16,6,1,1,6};
    VREFCON1=0b10100000;

    while(1){
        for(i=0;i<10;i++){
           VREFCON2bits.DACR=valoresSeno [i];
           __delay_us(1000);
        }
       return;
    };
    
    // return; 
}



void SENO_GENERAR_2(){
    
    OSCCON=0b01010111;
    char key;
    int i;
    int valoresSeno [25]= {16,19,23,26,29,30,31,31,30,27,25,21,17,14,10,6,4,1,0,0,1,2,5,8,12};  
    VREFCON1=0b10100000;

    while(1){
        for(i=0;i<25;i++){
           VREFCON2bits.DACR=valoresSeno [i];
           __delay_us(1000);
        }
       return;
    };
    // return; 
}

void SENO_GENERAR_3(){
    
    OSCCON=0b01010111;
    char key;
    int i;
   int valoresSeno [50]= {16,17,19,21,23,25,26,27,29,30,30,31,31,31,31,30,30,29,27,26,25,23,21,19,17,16,14,12,10,8,6,5,4,2,1,1,0,0,0,0,1,1,2,4,5,6,8,10,12,14}; 
    VREFCON1=0b10100000;

    while(1){
        for(i=0;i<50;i++){
           VREFCON2bits.DACR=valoresSeno [i];
           __delay_us(1000);
        }
       return;
    };
    // return; 
}