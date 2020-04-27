/*
Autor: bryant
Compilador: gcc (Debian 6.3.0-18+deb9u1) 6.3.0 20170516
Compilado: gcc Biseccion.c -o Biseccion -lm
Fecha: dom abr 26 01:00:22 CST 2020
Resumen: Este programa encuentra las raices de una funcion, mediante el metodo de la biseccion
Entrada: a, b, itermax, tol
Salida: Error, raiz, y grafico 
*/

//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//---------------------------------------------------------------------------------------------------------------------------
//Numerar los pasos del pseudocodigo:
//0. Inicia el algoritmo.
//1. Declarando variables: intervalos (a,b), numero de iteraciones e iteracion maxima (iter, itermax), tolerancia (tol), y las salidas error y la raiz de la funcion.
//2. Definiendo funciones: f para la funcion a analizar, leer para leer datos ingresados por el usuario, biseccio donde se realiza el metodo numerico, imprimir para imprimir los resultados obtenidos y graficar para mostrar al usuario una grafica 
//3. Especificamos la funcion "f" con la funcion asociada   e^(x)+x
//4. Especificamos la funcion leer datos: simplemente escaneo los datos necesarios y los almaceno en las variables correspondientes
//5. Especificamos la funcion para el test: el primer condicionante sirve para saber si ya estamos en la raiz, y de ser asi, verificamos si es en a o en b
//6. Especificamos la funcion del metodo de biseccion: definimos el error de 1%. Mientras el error sea menor a la tolerancia, y el numero de iteracines sea menor al ingresado por el usuario. Se imprime el proceso de encontrar
//7. Dentro de la funcion del metodo de biseccion:
//8.    EL iterador avanza
//9.    Definumos la busqueda
//10.   Definimos el producto valuando la funcion en a y en xmedia
//11.   Si es 0, estamos en la raiz, se imprime
//12.   Si prducto<0 se cambia el limite b por xmedia
//13.   


//---------------------------------------------------------------------------------------------------------------------------

//Declarando variables: intervalos (a,b), numero de iteraciones e iteracion maxima (iter, itermax), tolerancia (tol), y las salidas error y la raiz de la funcion.
double a, b, tole;
unsigned int itermax, iter;
double raiz, error;

//Definiendo funciones: f para la funcion a analizar, leer para leer datos ingresados por el usuario, biseccio donde se realiza el metodo numerico, imprimir para imprimir los resultados obtenidos y graficar para mostrar al usuario una grafica 
double f(double);
void leer(), test(), biseccion(), imprimir(), graficar();

//Funcion principal: en esta funcion invoco a las demas funciones auxiliares ademas de imprimir una descripcion
int main(){
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("DESCRIPCION: \n");
    printf("Este programa encuentra las raices de una funcion, utilizando el metodo de biseccion \n");
    printf("Para el caso particular del examen la funcion es: e^(x)+x \n");
    printf("------------------------------------------------------------------------------------------------------------------------ \n");
    leer();
    test();
    biseccion();
    imprimir();
    graficar();

return 0;
}

//Funcion asociada a  e^(x)+x
double f(double x){
    return(exp(x)+x);
}

//Funcion leer datos: simplemente escaneo los datos necesarios y los almaceno en las variables correspondientes
void leer(){
    printf("Ingrese el limite inferior del intevalo:    ");
    scanf("%lf",&a);
    printf("\nIngrese el limite superior del intevalo:    ");
    scanf("%lf",&b);
    printf("\nIngrese la tolerancia:    ");
    scanf("%lf",&tole);
    printf("\nIngrese el numero maximo de iteraciones:    ");
    scanf("%u",&itermax);

}

//Funcion para el test: el primer condicionante sirve para saber si ya estamos en la raiz, y de ser asi, verificamos si es en a o en b
void test(){
    double producto;
    producto = f(a)*f(b);
    if(producto == 0){     
        error = 0;
        if(f(a) == 0){
            raiz = a;
        }
        else{
            raiz = b;
        }
        imprimir();
    }

}

//Funcion del metodo de biseccion: definimos el error de 1%. Mientras el error sea menor a la tolerancia, y el numero de iteracines sea menor al ingresado por el usuario. Se imprime el proceso de encontrar
void biseccion(){
    double xmedia, producto;
    error = 1.0;
    iter = 0;
    while (error > tole && iter < itermax)
    {
        ++iter;                             //EL iterador avanxa
        xmedia = (a+b)/2;                   //Definumos la busqueda
        producto = f(a)*f(xmedia);          //Definimos el producto valuando la funcion en a y en xmedia
        if(producto == 0){                  //Si es 0, estamos en la raiz, se imprime
            raiz = xmedia;
            error = 0;
            imprimir();
        }
        if(producto < 0){                   //Si prducto<0 se cambia el limite b por xmedia
            b = xmedia;
        }
        else{                               //SI producto>0 se cambia el limite a por xmedia
            a = xmedia;
            error = fabs(a-b);
        }
     printf("\nIteracion = %u    Xmedia = %2.18lf    Error = %2.18lf", iter,xmedia,error);


    }
raiz = xmedia;    

}

//Funcion para imprimir: Simplemente imprimo los resultados de la raiz encontrada con su respectivo error y el numero de iteraciones en el que fue enconrado
void imprimir(){
    printf("\n\nRaiz = %2.18lf",raiz);
    printf("\nError = %2.18lf",error);
    printf("\nNumero de iteraciones = %u\n",iter);

}

//Funcion para graficar:
void graficar(){
    FILE *p1, *p2;
    //Establecemos conexion con el archivo en el que se guardaran los datos ingresados, a traves del puntero pf1, y escribimos los datos guardados en los vectores, con la ayuda de un ciclo for.
p1 = fopen("raiz.dat", "wt");
fprintf(p1, "%2.18lf\t0\n",raiz); 
	
fclose(p1); //Cerramos la conexion

//Establecemos conexion con el archivo que ejecuta gnuplot para graficar y establecer caracteristicas de la grafica, a traves del puntero pf2
p2 = fopen("fun.gp", "wt");
fprintf(p2, "set title 'Funcion y su raiz' \n");
fprintf(p2, "set xlabel 'X' \n");
fprintf(p2, "set ylabel 'Y' \n");
fprintf(p2, "set xrange [-5:5] \n");
fprintf(p2, "set yrange [-5:10] \n");
fprintf(p2, "plot 'raiz.dat' with points pt 2 lw 3 \n");
fprintf(p2, "replot exp(x)+(x) lw 2\n");
fprintf(p2, "replot 0 lw 1\n");
fclose(p2); //Cerramos la conexion

//Ejecutamos el archivo .gp creado a traves de gnuplot
system("gnuplot -p fun.gp");
}