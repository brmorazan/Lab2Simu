/*
Autor: bryant
Compilador: gcc (Debian 6.3.0-18+deb9u1) 6.3.0 20170516
Compilado: gcc Lab4-6.c -o Lab4-6 -lm
Fecha: lun mar 30 17:45:02 CST 2020
Resumen: Este programa realiza la sumatoria desde 1 hasta un numero n que ingrese el usuario, de las funciones especificadas en el codigo
Entrada: n
Salida: sa, sb, sc, sd
*/

//Librerias
#include <stdio.h>
#include <math.h>
//numerar los pasos del pseudocodigo
//0. Inicia el algoritmo
//1. Declarando variables: n para iterador de la suma, y el resto (sa, sb, sc, sd) para mostrar los resultados de las sumas.
//2. Funcion principal e impresion de la descripcion del programa
//3. Solicitando cota de las sumatorias y guardando en la variable n
//4. Restringiendo el ingreso de solamente n mayores a 1, ya que las sumatorias inician en 1 o 2, de tal forma que si sucede el caso de la restriccion, imprima mensaje de error y solicite de nuevo el numero
//5. Sumatoria a: inicializamos la salida sa en 0 debido a su reutilizacion. Hacemos la sumatoria con ciclo for, de tal forma que en cada iteracion se realice una suma sobre el indice. La funcion a sumar se especifica en el codigo. 
//6. Funcion a sumar: se coloca el sa en la suma porque se considera el resultado anterior. 
//7. Imprimimos resultado
//8. Similarmente para el resto de las sumatorias.
//9. Finaliza el algoritmo. 
//
//------------------------------------------------------------------------------------------------------------------------------

//Declarando variables: n para iterador de la suma, y el resto (sa, sb, sc, sd) para mostrar los resultados de las sumas.
int n;
float sa, sb, sc, sd;
//Funcion principal e impresion de la descripcion del programa
void main(){
printf("--------------------------------------------------------------------------------------------------------------------- \n");
printf("DESCRIPCION: \n");
printf("Este programa calcula ciertas sumatorias especificadas por el desarrollador desde 1 hasta en numero n que ingrese \n");
printf("--------------------------------------------------------------------------------------------------------------------- \n");
//Solicitando cota de las sumatorias y guardando en la variable n
printf("Ingrese la cota de las sumatorias \n");
scanf("%i", &n);
//Restringiendo el ingreso de solamente n mayores a 1, ya que las sumatorias inician en 1 o 2, de tal forma que si sucede el caso de la restriccion, imprima mensaje de error y solicite de nuevo el numero
while (n<=1){
printf("ERROR: la sumatoria inicia en 1, ingrese numero mayor a 1 \n");
scanf("%i", &n);

}
printf("-------------------------------------------------------------------------------------------------------------------- \n");
//RESULTADOS DE SUMATORIAS
printf("RESULTADOS: \n");
//Sumatoria a: inicializamos la salida sa en 0 debido a su reutilizacion. Hacemos la sumatoria con ciclo for, de tal forma que en cada iteracion se realice una suma sobre el indice. La funcion a sumar se especifica en el codigo.
printf("El resultado de la sumatoria a es: \n");
sa=0;
for (int i=0; i<=n; i++){
	sa = sa+(pow(i, 2)*(n-3));//Funcion a sumar: se coloca el sa en la suma porque se considera el resultado anterior. 
			}
printf("%.2f \n", sa);//Imprimimos resultado
printf("\n");
//Sumatoria b: Similar a la sumatoria anterio.
printf("El resultado de la sumatoria b es: \n");
sb=0;
for (int j=2; j<=n; j++){
	sb=(sb+((3)/(j-1)));//Similar a la funcion anterior
			}
printf("%.2f \n", sb);//Imprimimos resultado
printf("\n");
//Sumatoria c: Similar a la sumatoria anterior.
printf("El resultado de la sumatoria c es: \n");
sc=0;
for (int k=0; k<=n; k++){
	sc=((sc+((1/sqrt(5))*(pow((1+sqrt(5))/2, k)))-((1/sqrt(5))*(pow((1-sqrt(5))/2, k)))));//Similar a la funcion anterior.
			}
printf("%.2f \n", sc);//Imprimimos resultado
printf("\n");
//Sumatoria de bode: Similar a la sumatoria anterior.
sd=0;
printf("El resultado de la sumatoria d es: \n");
for (int l=2; l<=n; l++){
	sd= sd+ 0.1*(3*pow(2,l-2) + 4) ;//Similar a la funcion anterior.
			}
printf("%.2f \n", sd);//Imprimimos resultado
printf("Astrofisica: este resultado muestra la distancia del semieje mayor de la orbita de un planeta alrededor de su estrella anfitriona, donde n es obtenido por la ley T-B para cada planeta considerado ");
printf("\n");
printf("------------------------------------------------------------------------------------------------------------------- \n");





	

}
	   
