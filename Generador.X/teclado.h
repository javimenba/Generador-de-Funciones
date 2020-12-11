#ifndef TECLADO_H
#define TECLADO_H

#include <xc.h>
#define _XTAL_FREQ 4000000
 
/*


void int_teclado();
unsigned char Teclado(void);
char Recuperar(void);
*/

#define RowA LATAbits.LATA0
#define RowB LATAbits.LATA1
#define RowC LATAbits.LATA2
#define RowD LATAbits.LATA3
#define C1   PORTAbits.RA4
#define C2   PORTAbits.RA5
#define C3   PORTAbits.RA6
#define C4   PORTAbits.RA7

#define Keypad_PORT         PORTA
#define Keypad_PORT_Dir     TRISA

 void int_teclado(void);
void OffKeypad(void);
char Recuperar(void);
#endif