/*
Autor: bryant
Compilador: gcc (Debian 6.3.0-18+deb9u1) 6.3.0 20170516
Compilado: gcc LabPrimos1.c -o LabPrimos1
Fecha: mié mar 11 22:28:00 CST 2020
Resumen: Utilizando ciclos e iteraciones, particularmente el ciclo "for" se codifica un algoritmo que lea un numero mayor a q y determine si este es un numero primo.
Entrada: num, it, cont
Salida: Es un texto.
*/

//Librerias
#include <stdio.h>
//numerar los pasos del pseudocodigo
//Inicia el programa
//Se utilizan 3 variables: una para almacenar el numero ingresado (num), una para las iteraciones (it) y otra para el conteo (cont)
//Se pide al usuario ingrese el numero y el mismo se almacena en num
//Se inicia un ciclo for el cual cuando la variable de iteracion sea menor al numero ingresado, aumente
//Condicional dentro del ciclo: si el numero ingresado dividido el numero de la iteracion es igual a 0, o sea, son divisibles, entonces el contador aumenta en 1
//Condicional fuera del ciclo: Si el contador es mayor a 2, o sea si el numero ingresado solo es divisible dentro de 1 y si mismo, se imprime que el numero es primo. Caso contrario se imprime que no es primo.
//Finaliza el programa


//Trabajando en mi funcion principal, que en este caso es una sola
int main (){
	// Estas siguientes son mis variables de entrada: num para almacenar el numero ingresado, it es el iterador del ciclo for y cont para determinar entre cuantos numeros es divisible el numero ingresado
    int num, it, cont=0;
    // En este paso se pide al usuario el numero y se almacena en la variable num
    printf("\n Ingrese el numero a analizar     ");
    scanf("%i",&num);

    // Ciclo: el iterador empieza en 1, y mientras el iterador sea menor igual al numero ingresado, que aumente de uno en uno
    for(it=1;it<=num;it++){
	    // Condicional: dividimos el numero ingresado entre todos lo numeros del iterador, con lo cual si su division es exacta el conteo aumenta de 1 en 1 y determina la cantidad de numeros en la cual es divisible el ingresado.
	    if(num%it==0){
		    cont++;
	    }
    }

    // Condicional: cuando el numero ingresado es divisible por mas de dos numeros de la iteracion, osease cuando cont que almacena la cantidad de veces que es divisible el numero , el numero no es primo
    if(cont>2){
	    printf("\n El numero no es primo \n");
    }
    // Caso contrario: osease el numero ingresado es divisible por dos numeros, el mismo numero y la unidad
    else {
	    printf("\n El numero es primo \n");
    }

    return 0;
}
