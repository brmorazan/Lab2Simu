/*
Autor: bryant
Compilador: gcc (Debian 6.3.0-18+deb9u1) 6.3.0 20170516
Compilado: gcc Minimoscuadrados.c -o Minimoscuadrados -lm
Fecha: sáb abr 25 16:24:41 CST 2020
Resumen: Este es un programa que realiza el metodo de minimos cuadrados para cualquier conjunto de datos.
Entrada: n, x, y, anual, gob
Salida: Se imprime un texto y se genera un archivo de texto con el resultado, gan, dif
*/

//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Numerar los pasos del pseudocodigo:
//0. Inicia el programa
//1. Declarando variables: iterador (i), entradas: numero de puntos, puntos, año de proyec y proyec del gobierno (n, x, y, anual, gob), salidas, parametros de la funcion con sus errores(m, err, errb, b), elementos de la sumatoria (sumax, sumay, sumaxy, sumax2)
//2. Funcion principal e impresion de la descripcion
//3. Solicitando al usuario la cantidad de puntos de sus datos y almacenar en n
//4. Solicitando al usuario los datos del año y el valor total y guardandoles en los vectores correspondientes. Usando ciclo for para recorrer el vector.
//5. Calculando las sumatorias para m y para b, se realiza con la ayuda de un ciclo for.
//6. Calculamos m y b y sus errores, con los resultados obtenidos anteriormente. Ademas del coef de correlacion r, la ganancia para el ano ingresado y la comparacion con la proyeccion dada
//7. Imprimimos los resultados
//8. Imprimiendo grafica: Declaramos 2 punteros, pf1 para los datos ingresados por el usuario, y pf2 para la funcion calculada por el metodo
//9. Establecemos conexion con el archivo en el que se guardaran los datos ingresados, a traves del puntero pf1, y escribimos los datos guardados en los vectores, con la ayuda de un ciclo for.
//10. Cerramos la conexion
//11. Establecemos conexion con el archivo que ejecuta gnuplot para graficar y establecer caracteristicas de la grafica, a traves del puntero pf2
//12. Cerramos la conexion
//13. Ejecutamos el archivo .gp creado a traves de gnuplot
//14. Finaliza el programa.
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//Declarando variables: iterador (i), entradas: numero de puntos, puntos, año de proyec y proyec del gobierno (n, x, y, anual, gob), salidas, parametros de la funcion con sus errores(m, err, errb, b), elementos de la sumatoria (sumax, sumay, sumaxy, sumax2)
#define N 999
float x[N],y[N];
float sumx,sumy,sumxy,sumxx, sumyy;
float m, b, errm, errb, r, gan, dif, gob;
int n,i,anual;



//Funcion principal
void main(){
printf("-----------------------------------------------------------------------------------------------------------------------\n");
printf("DESCRIPCION: \n");
printf("Este programa realiza el metodo de minimos cuadrados para cualquier conjunto de datos ingresados por el usuario \n");
printf("Para el caso particular del examen, ingresar los siguientes datos: \n");
printf("Año: 2013, 2014, 2015, 2016, 2017, 2018, 2019 \n");
printf("Valor total (Q): 660.0, 671.4, 668.0, 695.5, 717.1, 759.2, 807.0  \n");
printf("------------------------------------------------------------------------------------------------------------------------ \n");
//Solicitando al usuario la cantidad de puntos de sus datos
printf("Ingrese la cantidad de puntos que generan sus datos:  \n");
scanf("%d",&n);
printf("\n");
//Solicitando al usuario los datos del año y el valor total y guardandoles en los vectores correspondientes. Usando ciclo for para recorrer el vector.
printf("Ingrese sus datos: \n");   
   for (i=0;i<n;i++)
   {
        printf("Punto %d:\t Año: ",i+1);
        scanf("%f",&x[i]);
        printf("         \t Valor total (Q) : ",i+1);
        scanf("%f",&y[i]);
        printf("\n");
             
   }
printf("Ingrese el año para el cual desea la proyeccion de ganancias: \n");
scanf("%i",&anual);
printf("Ingrese la proyeccion del gobierno para el año ingresado (Q): \n");
scanf("%f",&gob);

//Calculando las sumatorias para m y para b, se realiza con la ayuda de un ciclo for. OBSERVACION: se realiza dentro de la funcion principa, ya que si se hiciera una funcion para cada sumatoria, seria tonto, ya que aumenta el codigo
sumx=sumy=sumxy=sumxx=0;    //Nos aseguramos que todas inicien en 0
   for (i=0;i<n;i++)
   {
       sumx += x[i];        //Sumatoria de x
       sumy += y[i];        //Sumatoria de y
       sumxx += x[i]*x[i];  //Sumatoria de x^2
       sumyy += y[i]*y[i];  //Sumatoria de y^2
       sumxy += x[i]*y[i];  //Sumatoria de xy
   }

   //Calculamos m y b y sus errores, con los resultados obtenidos anteriormente. Ademas del coef de correlacion r, la ganancia para el ano ingresado y la comparacion con la proyeccion dada
   m = (n*sumxy - sumx*sumy) / (n*sumxx - sumx*sumx);
   errm = (sqrt(0.1*n)) / (sqrt(n*sumxx - sumx*sumx));
   b = (sumy - m*sumx) / n;
   errb = (0.1) / (sqrt(n));
   r = (n*sumxy - sumx*sumy) / (sqrt((n*sumxx - sumx*sumx) * (n*sumyy - sumy*sumy)));
   gan = (m)*(anual)+b;
   dif = gan/gob;
   //NOTA IMPORTANTE: En el caso de mi examen, los valores dados son exactos, pero de tener incertezas, solamene se modifica en el codigo.

//Imprimimos los resultados
printf("\n\nPendiente(m) = %f ± %f \nInterseccion(b) = %f ± %f \nCoeficiente de correlacion (r) = %f \n",m, errm, b, errb, r);
printf("La funcion asociada al conjunto de datos es: y=(%f±%f)x+(%f±%f)\n",m,errm,b,errb);
printf("\n\nLa proyeccion de ganancias para el año 2020 es: %.2f Q \n", gan);
printf("Comparacion con la estimacion del gobierno (1 = exactitud completa): %f \n", dif);


//Imprimiendo grafica: Declaramos 2 punteros, pf1 para los datos ingresados por el usuario, y pf2 para la funcion calculada por el metodo
FILE * pf1, * pf2;
//Establecemos conexion con el archivo en el que se guardaran los datos ingresados, a traves del puntero pf1, y escribimos los datos guardados en los vectores, con la ayuda de un ciclo for.
pf1 = fopen("datos.dat", "wt");
for(i = 0; i < n; i++)
	{
		fprintf(pf1, "%.4f\t%.4f\n",x[i], y[i]); 
	}
fclose(pf1); //Cerramos la conexion

//Establecemos conexion con el archivo que ejecuta gnuplot para graficar y establecer caracteristicas de la grafica, a traves del puntero pf2
pf2 = fopen("funcion.gp", "wt");
fprintf(pf2, "set title 'Produccion anual de cardamomo \n");
fprintf(pf2, "set xlabel 'Año' \n");
fprintf(pf2, "set ylabel 'Valor total (Q)' \n");
fprintf(pf2, "set xrange [2012:2021] \n");
fprintf(pf2, "set yrange [600:900] \n");
fprintf(pf2, "plot 'datos.dat' with points pt 2 lw 3\n");
fprintf(pf2, "replot (%f)*x+(%f) lw 2\n",m,b);
fclose(pf2); //Cerramos la conexion

//Ejecutamos el archivo .gp creado a traves de gnuplot
system("gnuplot -p funcion.gp");
//Finaliza el programa

}

