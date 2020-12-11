/*
 * File:   teclado.c
 * Author: francisco
 *
 * Created on 28 de marzo de 2019, 10:10 PM
 */

#include "teclado.h"





/*
 void int_teclado()
{            
    INTCON2bits.RBPU=0; // resistencias pull-up
    ANSELB=0;
}
 
unsigned char Teclado(void){
    
  
    TRISB = 0xF0;
    PORTB = 0xFF;
  
    PORTBbits.RB0=0;
    if(PORTBbits.RB4==0){return '1';}
    if(PORTBbits.RB5==0){return '2';}
    if(PORTBbits.RB6==0){return '3';}
    if(PORTBbits.RB7==0){return 'A';}
    PORTBbits.RB0=1;
    //--------------------------------------
    PORTBbits.RB1=0;
    if(PORTBbits.RB4==0){return '4';}
    if(PORTBbits.RB5==0){return '5'; }
    if(PORTBbits.RB6==0){return '6';}
    if(PORTBbits.RB7==0){return 'B';}
    PORTBbits.RB1=1;
    //-------------------------------------
    PORTBbits.RB2=0;
    if(PORTBbits.RB4==0){return '7';}
    if(PORTBbits.RB5==0){return '8';}
    if(PORTBbits.RB6==0){return '9';}
    if(PORTBbits.RB7==0){return 'C';}
    PORTBbits.RB2=1;
    //-------------------------------------
    PORTBbits.RB3=0;
    if(PORTBbits.RB4==0){return '*';}
    if(PORTBbits.RB5==0){return '0';}
    if(PORTBbits.RB6==0){return '#';}
    if(PORTBbits.RB7==0){return 'D';}
    PORTBbits.RB3=1;

    return ' ';
}

char Recuperar(void){
    
    char tecl = ' ' ;
    
    tecl =Teclado();
    
    return tecl;
    
}

*/

 void int_teclado(void){
    Keypad_PORT = 0x00;
    Keypad_PORT_Dir = 0xF0;
}

void OffKeypad(void){
    
    Keypad_PORT = 0x00;
    Keypad_PORT_Dir = 0x00;
}

char READ_SWITCHES(void){
   
RowA=0; RowB = 1 ; RowC = 1 ; RowD = 1 ;
if(C1 == 0){__delay_ms(90); while (C1 == 0); return 'D'; }
if(C2 == 0){__delay_ms(90); while (C2 == 0); return 'C'; }
if(C3 == 0){__delay_ms(90); while (C3 == 0); return 'B'; }
if(C4 == 0){__delay_ms(90); while (C4 == 0); return 'A'; }

RowA=1; RowB = 0 ; RowC = 1 ; RowD = 1 ;
if(C1 == 0){__delay_ms(90); while (C1 == 0); return '#'; }
if(C2 == 0){__delay_ms(90); while (C2 == 0); return '9'; }
if(C3 == 0){__delay_ms(90); while (C3 == 0); return '6'; }
if(C4 == 0){__delay_ms(90); while (C4 == 0); return '3'; }

RowA=1; RowB = 1 ; RowC = 0 ; RowD = 1 ;
if(C1 == 0){__delay_ms(90); while (C1 == 0); return '0'; }
if(C2 == 0){__delay_ms(90); while (C2 == 0); return '8'; }
if(C3 == 0){__delay_ms(90); while (C3 == 0); return '5'; }
if(C4 == 0){__delay_ms(90); while (C4 == 0); return '2'; }

RowA=1; RowB = 1 ; RowC = 1 ; RowD = 0 ;
if(C1 == 0){__delay_ms(90); while (C1 == 0); return '*'; }
if(C2 == 0){__delay_ms(90); while (C2 == 0); return '7'; }
if(C3 == 0){__delay_ms(90); while (C3 == 0); return '4'; }
if(C4 == 0){__delay_ms(90); while (C4 == 0); return '1'; }

return ' ';
    
}

char Recuperar(void){
    
    char key = ' ' ;
    
    key = READ_SWITCHES();
    
    return key;
    
}
