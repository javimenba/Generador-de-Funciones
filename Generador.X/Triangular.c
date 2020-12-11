/*
 * File:   Triangular.c
 * Author: francisco
 *
 * Created on 17 de mayo de 2019, 02:16 AM
 */


#include "Triangular.h"
void  TRIANGULAR_GENERAR_1(){
    OSCCON=0b01010111;
    char key;
    int i;
    int valoresTrian [10]={6,12,19,25,31,25,19,12,6,0};
    VREFCON1=0b10100000;

    while(1){
        for(i=0;i<10;i++){
           VREFCON2bits.DACR=valoresTrian[i];
           __delay_us(1000);
        }
       return;
    };
    // return; 
}
void  TRIANGULAR_GENERAR_2(){
       OSCCON=0b01010111;
    char key;
    int i;
    int valoresTrian [15]={4,8,12,17,21,25,29,31,29,25,21,17,12,8,4};
    VREFCON1=0b10100000;

    while(1){
        for(i=0;i<15;i++){
           VREFCON2bits.DACR=valoresTrian[i];
           __delay_us(1000);
        }
       return;
    };
    // return; 
}
void  TRIANGULAR_GENERAR_3(){
    OSCCON=0b01010111;
    char key;
    int i;
    int valoresTrian [20]={3,6,9,12,16,19,22,25,28,31,28,25,22,19,16,12,9,6,3,0};
    VREFCON1=0b10100000;

    while(1){
        for(i=0;i<20;i++){
           VREFCON2bits.DACR=valoresTrian[i];
           __delay_us(1000);
        }
       return;
    };
    // return; 
}