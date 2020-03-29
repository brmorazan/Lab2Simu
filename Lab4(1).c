/*
Autor: bryant
Compilador: gcc (Debian 6.3.0-18+deb9u1) 6.3.0 20170516
Compilado: gcc Lab4(1).c -o Lab4(1)
Fecha: jue mar 26 23:37:14 CST 2020
Resumen: Este algoritmo codificado solicita al usuario un vector de 10 elementos, los cuales son numeros pares del 2 al 20. Iniciado el programa, a traves de un menu solicita como se quiere ver los elementos del vector igresado, ya sea de forma ascendente o descendente. Seguidamente se muestra el vector ordenado.
Entrada: pendientes
Salida: pedientes
*/

//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//numerar los pasos del pseudocodigo
//0. Inicia el algoritmo.
//1. Declaramos variables: vector donde se guardan los numeros pares y vector auxiliar para restringir el menu.
//2. Dentro de la funcion principal imprimimos la descripcion y el menu correspondiente.
//3. Utilizamos un ciclo while para el caso de ingresar caracteres distintos a los solicitados, que consiste en volver a solicitar
//4. Utilizamos un switch para que existan dos casos: ascendente o descendente.
//5. En el caso de seleccionar "a" de  ascendente, usamos el metodo de burbuja para ordenar el vector en cuestion.
//6. Imprimimos el vector ya ordenado de forma ascendente.
//7. En el caso de seleccionar "d" de descendete, usamos el metodo de burbuja para ordenar el vector en cuestion.
//8. Imprimimos el vector ya ordenado de forma descendente.
//9. En el caso de ingresar valores diferentes de "a" y "d" muestra un mensaje de error, y solicita de nuevo gracias al while.
//10. Para salir del cilco while condicionamos que sea al seleccionar "a" o "d", con lo cual finaliza el programa.
//11. Finaliza el algoritmo.
//
	  
//Declarando variables: "vector" y "x" que tambien es un vector, para restringir el menu.
int vector[]={4,2,16,8,10,20,14,6,18,12};
char x[100];

//Funcion principal y descripcion del menu..
void main(){
printf("--------------------------------------------------------------------------- \n");
printf(" DESCRIPCIÓN: \n");
printf("Este programa le muestra los elementos pares del 2 al 20 del vector: \n");
printf("{4,2,16,8,10,20,14,6,18,12} \n");
printf("El cual puede modificar en el codigo \n");
printf("----------------------MENÚ---------------------- \n");
printf("Presione --a-- para ver de forma ascendente \n");
printf("Presione --d-- para ver de forma descendente \n");
printf("------------------------------------------------ \n");

//Condicionando el menu mediante ciclo y con la ayuda de un vector de caracteres restringiendo el ingreso de las letras.
while  (scanf("%s", &x[100])){
	switch (x[100]) {
		//Forma ascendente: ordenando el vector mediante el metodo de burbuja.
		case 'a' :
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				if (vector[j]>vector[j+1]){
					int aux1;//Esta variable es para las nuevas posiciones de los elementos del vector.
					aux1 = vector[j+1];
					vector[j+1] = vector[j];
					vector[j] = aux1;
				}
			}
		}
		//Imprimiendo el vector ordenado.
		for(int k=1; k<=10; k++){
			printf("%d\t", vector[k]);
		}
		break;
		//Forma descendente: ordenando el vector mediante el metodo de burbuja.
		case 'd' :
		for(int i=0; i<10; i++){
			for(int j=0; j<=10; j++){
				if (vector[j]<=vector[j+1]){
					int aux2;//Esta variable es para las nuevas posiciones de los elementos del vector.
					aux2 = vector[j+1];
					vector[j+1] = vector[j];
					vector[j] = aux2;
				}
			}
		}
		//Imprimiendo el vector ordenado.
		for(int l=0; l<=9; l++){
			printf("%d\t", vector[l]);
		}
		break;
                //En el caso de no ingresar los caracteres permitidos, redirige a la siguiente rutina.
		default:
		
		printf("El caracter que ingreso es INVALIDO \n");
		printf("Solo puede ingresar --a-- o --d-- \n");
		printf("Intente de nuevo \n");
		break;
	}
                //Salida del primer ciclo: luego de ejecutar las rutinas correspondientes a "a" y "b", sale del ciclo.
		if ( x[100] == 'a' || x[100]== 'd' ){
	        break;
 		}
		
}
}









