/*
Autor: bryant
Compilador: gcc (Debian 6.3.0-18+deb9u1) 6.3.0 20170516
Compilado: gcc Lab4-5.c -o Lab4-5 -lm
Fecha: mar mar 31 11:56:43 CST 2020
Resumen: Este programa calcula el factorial de un numero entero ingresado por el usuario. Utilizando una funcion recursiva
Entrada: n
Salida: resultado
*/

//Librerias
#include <stdio.h>
//numerar los pasos del pseudocodigo
//0. Inicia el algoritmo
//1. Declarando funion recursiva dependiente de n que es el numero del cual se hara el calculo 
//2. Declarando variable "ret" se utiliza para iterar
//3. Planteamos el caso base, n=1 para tener un pivote inicial, el cual si se cumple, retorna 1 a la funcion
//4. Planteamos el siguiente caso, en donde se realiza el mismo proceso para cada numero retrocediendo desde n
//5. Funcion Principal y declaracion de varibles n para el numero a calcular, y resultado, obviamente para almacenar el resultado
//6. Imprimimos descripcion del programa
//7. Soicitamos y guardando el numero a calcular en "n"
//8. Igualamos la funcion recursiva a "resultado"
//9. Imprimimos el resultado
//10. Finaliza el algoritmo
//------------------------------------------------------------------------------------------------------------------------------

//Declarando funion recursiva dependiente de n que es el numero del cual se hara el calculo
long int factorial(int n){
	int ret; //Esta variable se utiliza para iterar
//Planteamos el caso base, n=1 para tener un pivote inicial, el cual si se cumple, retorna 1 a la funcion
if(n==1){
	return 1;
}
ret=n*factorial(n-1);// Este es el siguiente caso, en donde se realiza el mismo proceso para cada numero retrocediendo desde n
return (ret);
}
//Funcion Principal y declaracion de varibles n para el numero a calcular, y resultado, obviamente para almacenar el resultado
int main (){
int n;
long int resultado;
//Imprimiendo descripcion del programa
printf("-------------------------------------------------------------------------------------------------------------------- \n");
printf("DESCRIPCION \n");
printf("Este programa calcula el factorial de un numero entero que ingrese, utilizando una funcion recursiva \n");
printf("-------------------------------------------------------------------------------------------------------------------- \n");
//Soicitando y guardando el numero a calcular en "n"
printf("Ingrese el numero a calcular su factorial: \n");
scanf("%i", &n);
//Igualamos la funcion recursiva a "resultado"
resultado=factorial(n);
//Imprimimos el resultado
printf("El factorial de %i es: %li", n, resultado);
printf("\n");
printf("-------------------------------------------------------------------------------------------------------------------- \n");
return 0;

}
	   
