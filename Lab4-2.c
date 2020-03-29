/*
Autor: bryant
Compilador: gcc (Debian 6.3.0-18+deb9u1) 6.3.0 20170516
Compilado: gcc Lab4(2).c -o Lab4(2)
Fecha: dom mar 29 00:15:20 CST 2020
Resumen: Este programa solicita al usuario 5 numeros enteros, los cuales almacena en un vector que luego ordena de forma ascendente y muestra el mismo en consola.
Entrada: pendientes
Salida: pendientes
*/

//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//numerar los pasos del pseudocodigo
//0. Inicia el algoritmo
//1. Declaramos variables: vector donde se guardan los numeros ingresados, un contador y un iterador.
//2. Dentro de la funcion principal imprimimos la descripcio del programa.
//3. Utilizando un ciclo for leemos los numeros ingresados por el usuario.
//4. Utilizando otro ciclo for, procedemos a ordenar los numeros.
//5. Con la ayuda de un iterador vamos cambiando de posicion del vector.
//6. El iterador toma el valor de la posicion, y tambien la variable auxiliar toma el valor de la posicion.
//7. Considerando la posicion actual, usamos un ciclo while para saber si el numero es menor al de la posicon anterior.
//8. Si se cumple la condicon, cambiamos de posicion el numero considerado, con la posicion anterior y reducimos su valor.
//9. Guardamos la posicion de la condicion en la variable auxiliar.
//10. Esto se repite hasta que el vector quede ordenado.
//11. Se imprime el vector ordenado.
//12. Finaliza el algoritmo.
//-----------------------------------------------------------------------------------------------------------------------------

//Declarando variables: "vector", "i" como contador, "j" como iterador y "aux" como variable auxiliar.
int vector[5];
int i, j, aux;
void main(){
printf("-------------------------------------------------------------------------------------------------------------------- \n");
printf("DESCRIPCIÓN: Este programa le muestra los elementos de un vector que usted ingrese, de forma ordenada ascendentemente.\n");
printf("--------------------------------------------------------------------------------------------------------------------- \n");
printf("Ingrese 5 numeros enteros, para construir el vector: \n");
//Leyendo numeros ingresados y guardandolos en cada componente con la ayuda del ciclo for.
for (int i=0; i<5; i++){
	scanf("%i", &vector[i]);
}
//Ordenando el vector mediante el metodo de insercion.
for (i=0; i<5; i++){
	j = i;            //El iterador toma el numero de la posicion.
	aux = vector[i];  //La variable auxiliar toma el valor exacto de la posicion.
	//Ciclo while para comprobar que se cumpla la condicion la cual consiste en comparar la posicion actual con la anterior.
	while ((j>0) && (aux<vector[j-1])){
		vector[j] = vector[j-1];  //Aca se da el cambio de la posicion si se cumple la condicion.
		j--;                      //Reducimos el valor de la posicion.
	}
	vector[j] = aux;  //Guardando la posicion de la condicon en la variable auxiliar.
}
printf("------------------------------------------------------------------------------------------------------------------ \n");
//Impresion del vector ya ordenado.
printf("Los elementos ordenados de forma ascendente son: \n");
for (i=0; i<5; i++){
	printf("%d\t", vector[i]);
}

}
