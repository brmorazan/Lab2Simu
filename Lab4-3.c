/*
Autor: bryant
Compilador: gcc (Debian 6.3.0-18+deb9u1) 6.3.0 20170516
Compilado: gcc Lab4-3.c -o Lab4-3
Fecha: dom mar 29 15:48:59 CST 2020
Resumen: Este programa solicita al usuario dos vectores en coordenadas (x,y,z), y calcula automaticamente la magnitud de cada vector, la suma de los dos vectores, su producto escalar y su producto vectorial.
Entrada: vec1, vec2, i (como iterador)
Salida: mag1, mag2, pre, prv
*/

//Librerias
#include <stdio.h>
#include <math.h>
//numerar los pasos del pseudocodigo
//0. Inicia el algoritmo.
//1. Declarando variables: "vec1" y "vec2" para los vectores a operar, "i", como iterador, "sum" para el resultado de la suma, "prv" para el resultado del producto vectorias, "magi" para las magnitudes y "pre" para el resultado del producto escalar.
//2. Creamos la funcion principal y descripcion del programa.
//3. Guardamos las coordenadas del primer vector con la ayuda de ciclo for, para iterar sobre cada componente.
//4. Guardando las coordenadas del segundo vector con la ayuda de ciclo for, para iterar sobre cada componente. 
//5. Magnitud primer vector: aprovechando la libreria math, calculamos de forma usual, se guarda en "mag1" y asi mismo se imprime.
//6. Magnitud segund vector: aprovechando la libreria math, se calcula de forma usual, se guarda en "mag1" y asi mismo se imprime.
//7. Suma de los vectores: se suman por componentes el vec1, vec2, guardandose en la componente correspondiente de sum, se imprime.
//8. Producto escalar:se calcula de forma usual, guardando el resultado en "pre" e imprimiendo el mismo 
//9. Producto vectorial:el calculo es por componentes, cada componente del nuevo vector se calcula usual y se imprime.
//10. Finaliza el algoritmo. 
//--------------------------------------------------------------------------------------------------------------------------------

//Declarando variables: "vec1" y "vec2" para los vectores a operar, "i", como iterador, "sum" para el resultado de la suma, "prv" para el resultado del producto vectorias, "magi" para las magnitudes y "pre" para el resultado del producto escalar.
float vec1[3], vec2[3], sum[3], prv[3];
float mag1, mag2, pre;
int i;
//Funcion principal y descripcion del programa
void main(){
printf("------------------------------------------------------------------------------------------------------------------ \n");
printf("DESCRIPCION: \n");
printf("Este programa le solicita dos vectores en coordenadas (x,y,z), y calcula automaticamente la magnitud de cada vector, la suma de los dos vectores, su producto escalar y su producto vectorial. \n");
printf("------------------------------------------------------------------------------------------------------------------- \n");
//Guardando las coordenadas del primer vector con la ayuda de ciclo for, para iterar sobre cada componente.
printf("Ingrese las coordenadas x, y ,z del primer vector: \n");
for (i=0; i<3; i++){
	scanf("%f", &vec1[i]);
}
//Guardando las coordenadas del segundo vector con la ayuda de ciclo for, para iterar sobre cada componente.
printf("Ingrese las coordenadas x, y, z del segundo vector: \n");
for (i=0; i<3; i++){
	scanf("%f", &vec2[i]);
}
printf("-------------------------------------------------------------------------------------------------------------------- \n");
//Magnitud primer vector: aprovechando la libreria math, se calcula de forma usual, se guarda en "mag1" y asi mismo se imprime.
printf("La magnitud del primer vector es: \n");
mag1= sqrt((pow(vec1[0],2))+(pow(vec1[1],2))+(pow(vec1[2],2)));
printf("%f \n", mag1);
printf("\n");
//Magnitud segundo vector: aprovechando la libreria math, se calcula de forma usual, se guarda en "mag2" y asi mismo se imprime.
printf("La magnitud del segundo vector es: \n");
mag2=sqrt((pow(vec2[0],2))+(pow(vec2[1],2))+(pow(vec2[2],2)));
printf("%f \n", mag2);
printf("\n");
//Suma de los dos vectores: se suman por componentes el vec1, vec2, guardandose en la componente correspondiente de sum, se imprime
printf("La suma de los dos vectores es el vector: \n");
sum[0]=vec1[0]+vec2[0];
sum[1]=vec1[1]+vec2[1];
sum[2]=vec1[2]+vec2[2];
for (i=0; i<3; i++){
	printf("%f\n", sum[i]);
}
printf("\n");
//Producto escalar:aprovechando la libreria math, se calcula de forma usual, guardando el resultado en "pre" e imprimiendo el mismo
printf("El producto escalar entre los dos vectores es: \n");
pre=((vec1[0]*vec2[0])+(vec1[1]*vec2[1])+(vec1[2]*vec2[2]));
printf("%f \n", pre);
printf("\n");
//Producto vectorial:el calculo es por componentes, cada componente del nuevo vector se calcula usual y se imprime.
printf("El producto vectorial entre los dos vectores es el vector: \n");
prv[0]=(vec1[1]*vec2[2])-(vec1[2]*vec2[1]);
prv[1]=(vec1[0]*vec2[2])-(vec1[2]*vec2[0]);
prv[2]=(vec1[0]*vec2[1])-(vec1[1]*vec2[0]);
for (i=0; i<3; i++){
	printf("%f\n", prv[i]);
}
printf("--------------------------------------------------------------------------------------------------------------------- \n");
}
