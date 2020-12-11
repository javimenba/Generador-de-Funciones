
#include "PWM.h"

#define XTAL_FREQ 8000000 

void Presentacion();
void Menu();
void Menu_Pwm();
void Tec(char *cadena);
void Imprimir_pantalla(char *N);
void Frecuencia(char *frecuencia);
void Ciclo(char *ciclo);
///// Funciones de prueba
void Prueba1();
void Prueba2();

int q,w,e,r;
int a=1,d,f,g;
unsigned int s,t;
char key;
unsigned char frecuencia[10],ciclo[10],columna=0,cantidad=0,fila=0,cadena[10],cad[10];

void Presentacion(){
    
       
      Lcd_Init();
      Lcd_Cmd(LCD_CLEAR);
      Lcd_Cmd(LCD_CURSOR_OFF);
      Lcd_Out2(1,1,"Universidad de ");
      Lcd_Out2(3,2,"Guanajuato");
      tm_1s();
      Lcd_Cmd(LCD_CLEAR);
      Lcd_Out2(1,1,"Proyecto Final");
      Lcd_Out2(3,2,"Generador");
      tm_1s();
     
      
    
}

void Menu(){
      
        Lcd_Init();
        Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_CURSOR_OFF);
        Lcd_Out2(1,1,"A.-Cuadrada");
        Lcd_Out2(1,2,"B.-Senoidal");
        tm_1s();
        key = Recuperar(); 
        Lcd_Init();
        Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_CURSOR_OFF);
        Lcd_Out2(1,1,"C.-Triangular");
        tm_1s();
        
        
}

void Menu_Pwm(){
        Lcd_Init();
        Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_CURSOR_OFF);
        Lcd_Out2(1,1,"1.-Datos");
        Lcd_Out2(1,2,"2.-Comenzar");
       
}


void Frecuencia(char *frecuencia){
        Lcd_Init();
        Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_CURSOR_OFF);
        Lcd_Out2(1,1,"Frecuencia:");
        Tec(frecuencia);
}
void Ciclo(char *ciclo){
        Lcd_Init();
        Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_CURSOR_OFF);
        Lcd_Out2(1,1,"Ingrese ciclo");
        Tec(ciclo);
}
void Tec(char *cadena){
    
    unsigned char Key = '+' , aux;
    unsigned int i=0 , j=0, contador = 1;
   
    lcd_goto(contador,2);
    do{
          

       Key = Recuperar();
       if( Key == ' ')continue;
       if( Key == '*')break;
       if(Key == 'B') {
           lcd_goto(--contador,2);
           if(j!= 0) j--;
             aux = '\0';
           continue;
       
      }
    if(Key == aux){
    
        if(Key!='#')
        contador --,j--;
        lcd_goto(contador++,2);
        cadena[j++]=Key;
        continue;
    }
    i = 0;
 
    if(Key == '#' && Key!=aux ){
        aux = Key;
        continue;
    }
    lcd_goto(contador,2);
    cadena[j++]=Key;
    Lcd_Chr_CP(Key);
    contador++;
    aux=Key;
    }while(1);
    cadena[j] = '\0';

    
}

void Imprimir_pantalla(char *N){
    
    unsigned char fila = 0, columna=0;
    Lcd_Init();
    Lcd_Cmd(LCD_CLEAR);
    Lcd_Cmd(LCD_CURSOR_OFF);
   // fila=0; columna=0;
   //lcd_Cadena(N,&columna,&fila);
    Lcd_Out2(1,1,N);
    tm_1s();
    Lcd_Cmd(LCD_CLEAR);
    key=Recuperar();

}

void Prueba1(){
        Frecuencia(frecuencia);
        Imprimir_pantalla(frecuencia);
        Ciclo(ciclo);
        Imprimir_pantalla(ciclo);
        s=atoi(frecuencia);
        t=atoi(ciclo);
}

void Prueba2(){
         Lcd_Init();
        Lcd_Cmd(LCD_CLEAR);
        Lcd_Cmd(LCD_CURSOR_OFF);
        Lcd_Out2(1,1,"Fre: ");
        Lcd_Out2(1,11,"Hz");
        //fila=0; columna=6;
       cantidad= Conv_Entero(s,cadena);
       //lcd_Cadena(cadena,&columna,&fila);
       Lcd_Out(1,11,cadena);
       Lcd_Out2(2,1,"Ciclo: ");
       Lcd_Out2(2,11,"%");
       //fila=1; columna=8;
       cantidad= Conv_Entero(t,cadena);
       //lcd_Cadena(cadena,&columna,&fila);
       Lcd_Out(8,1,cadena);
       PWM_generar(t,s);

       
}