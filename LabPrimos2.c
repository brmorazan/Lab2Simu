/*
Autor: bryant
Compilador: gcc (Debian 6.3.0-18+deb9u1) 6.3.0 20170516
Compilado: gcc LabPrimos2.c -o LabPrimos2
Fecha: jue mar 12 00:15:52 CST 2020
Resumen: Utilizando ciclos "for" se codifica un algoritmo que muestre todos los numeros primos en un rango generado por dos numeros ingresados por el usuario.
Entrada: num1, num2, it, it2, cont
Salida: Se imprime un texto, it
*/

//Librerias
#include <stdio.h>
//numerar los pasos del pseudocodigo
//Inicia el programa
//Se utilizan 5 variables: los iteradores "it" e "it2" los cuales me sirven para generar listas de numeros en el rango generado entre "num1" y "num2" ingresados por el usuario, y por ultimo "cont" en el cual almaceno las veces que dichos numeros de las listas son divisibles exactamente
//Se inicia el primer ciclo "for" para generar mi primer lista de numeros siempre dentro de la cota elegida por el usuario.
//Dentro del primer ciclo se inicia el segundo ciclo "for" para generar la segunda lista de numeros, la cual se inicia en 2 y termina en la cota superior.
//Dentro del segundo ciclo se introduce una condicion que cuando se dividen exactamente los numeros de una lista con los numeros de la otra, se almacena en "cont" aumentando de 1 en 1 la cantidad de veces que esto sucede
//Dentro del primer ciclo se introduce otro condicional de forma que cuando se cumpla que la division de cada elemento de la lista 1 con cada elemento de la lista 2 sea exacta y suceda no mas de 2 veces, osease, cuando es divisible entre 1 y si mimsmo, se imprime la lista de los numeros que cumplan esta condicion.
//Finaliza el programa.


//Trabajando en mi funcion principal, que en este caso solamente es una.
int main(){
	//Variables de entrada: cota inferior del rango (num1), cota superior del rango (num2), iteracion (it,it2), conteo (cont)
	int num1, num2, it, it2, cont=0;
	// Solicitud de la cota inferior y almacenamiento en num1
	printf("\n Ingrese su cota inferior (mayor o igual a 1)     ");
	scanf("%d",&num1);
	// Solicitud de la cota superior y almacenamiento en num2
	printf("\n Ingrese su cota superior     ");
	scanf("%i",&num2);
	// Primer ciclo: el iterador empieza en la cota inferior, y mientras sea menor a la cota superior, que aumente de 1 en 1  
	for(it=num1;it<=num2;it++){
		//Segundo ciclo: el segundo iterador me servira para generar otra lista de numeros con los cuales comparar con el iterador 1 y asi generar mis numeros primos, este segundo iterador tiene que iniciar en 2 y ser menor que la cota superior, aumentanndo de 1 en 1
		cont=0;
		for(it2=2;it2<=num2;it2++){
			// Condicional secundario: generados dos listados de numeros entre las cotas, se divide cada elemento de uno entre el otro, de modod que si el residuo es 0, son divisibles exactos. Guardo la cantidad de veces que esto se cumple en mi contador.
			if(it%it2==0){
				cont++;
			}
		}
		//Condicional primario: Cuando se cumpla que la division de los elementos de las listas sea divisible exactamente no mas de 2 veces, osease entre el mismo y 1, se imprime la lista de los numeros que cumpieron tal condicion.
		if(cont<2){
			
			printf(" %i, " , it);
			
		}
	}
printf("\n");
return 0;


}
