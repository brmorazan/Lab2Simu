/*
Autor: bryant
Compilador: gcc (Debian 6.3.0-18+deb9u1) 6.3.0 20170516
Compilado: gcc Lab4-4.c -o Lab4-4 -ls
Fecha: dom mar 29 19:23:39 CST 2020
Resumen: Este programa le solicita al usuario dos matrices de 3X3 y un escalar, y automaticamente le muestra: la matriz 1 pa y resta de las dos matrices, la multiplicacion de las dos matrices, la determinante de la primer matriz, la transpuesta de la segunda matriz, la inversa de la primer matriz y la reduccion de Gauss-Jordan de ambas matrices.
Entrada: mtza, mtzb
Salida: mult, sum, res, multk, deta, transb, inva, gaussa, gaussb
*/

//Librerias
#include <stdio.h>
#include <math.h>
//numerar los pasos del pseudocodigo
//1. Declarando variables: Entrada: mtza, mtzb Salida: mult, sum, res, multk, deta, transb, inva, gaussa, gaussb
//2. Funcion principal e impresion del menu 
//4. Ingreso del escalar:
//5. Ingreso de matriz A: ya que tiene un indice para fila y otro para columna se realiza el mismo procedimiento para vectores, solo que ahora se agrega un ciclo for para las filas
//6. Ingreso de matriz B: similar que el proceso anterior
//7. Impresion de los resultados: 
//8. Matriz A por constante, simplemente tomo el valor guardado en k y lo multiplico a la matriz A, haciendolo con un ciclo for para las filas, y otro for para las columnas. Similarmente a lo anterior se imprime la matriz.
//9. Suma de las matrices: las matruces se suman componente a componente, usando ciclo for para columna y civlo for para fila, sumamos las componentes de A con las de b. Imprimimos similar a lo anterior.
//10. Resta de las matrices:similar al proceso anterior, solo que ahora restando
//11. Producto de las matrices: Lo hacemos de la forma usual de producto de matrices, guardando cada resultado en cada componente de la salida. Imprimimos como en el proceso anterior.
//12. Determinante de la matriz A: Lo hacemos de la forma usual del producto vectorial, guardado los resultados de cada componente en variables auxiliares, para luego sumarlas. Guardamos el resultado e imprimimos como en el proceso anterior.
//13. Transpuesta de la matriz B: Simplemente intercambiamos los subindices de los ciclos for que generan la matriz para que asi resultan los vectores fila, cambiados por los vectores columna.
//14. Reduccion de Gauss-Jordan para la matriz A: Con el primer conjunto de for encontramos los elementos de la diagonal de la matriz y volvemos el resultado la matriz A multiplicada por la division de la matriz A con su transpuesta. Luego imprimimos similar al proceso anterior
//15. Reduccion de Gauss-Jordan para la matriz B: Similar al proceso anterior solo que usando la matriz B
//16. Finaliza el algoritmo.
//-------------------------------------------------------------------------------------------------------------------------------

//Declarando variables:
float k, mtza[3][3], mtzb[3][3]; //ENTRADAS
float deta, multk[3][3], sum[3][3], res[3][3], mult[3][3], transb[3][3], inva[3][3], gaussa[3][3], gaussb[3][3];//SALIDAS
float d, dd, ddd, g;//AUXILIARES
int i, j;
//Funcion principal e impresion del menu
void main(){
printf("-------------------------------------------------------------------------------------------------------------------- \n");
printf("DESCRIPCION: \n");
printf(" Este programa le solicita dos matrices de 3X3 y un escalar, y automaticamente le muestra: la matriz 1 pa y resta de las dos matrices, la multiplicacion de las dos matrices, la determinante de la primer matriz, la transpuesta de la segunda matriz, la inversa de la primer matriz y la reduccion de Gauss-Jordan de ambas matrices. \n");
printf("-------------------------------------------------------------------------------------------------------------------- \n");
//Ingreso del escalar:
printf("Ingrese el escalar k para hacer el producto: \n");
scanf("%f", &k);
printf("El escalar k es: %.2f \n", k);
printf("---------------------------------------------------------- \n");
//Ingreso de matriz A: ya que tiene un indice para fila y otro para columna se realiza el mismo procedimiento para vectores, solo que ahora se agrega un ciclo for para las filas
printf("Ingrese las entradas de la matriz A: \n");
for(i=0; i<3; i++){
       for(j=0; j<3; j++){
       printf("De la fila %d , digite el valor %d:  ", i+1,j+1);
       scanf("%f", &mtza[i][j]);
       }
}
printf("\n");
printf("La matriz A es: \n");
for(i=0; i<3; i++){
	for(j=0; j<3; j++){
		printf(" %.2f ", mtza[i][j]);
	}
	printf("\n");
}
printf("---------------------------------------------------------- \n");
//Ingreso de matriz B: similar que el proceso anterior
printf("Ingrese las entradas de la matriz B: \n");
for(i=0; i<3; i++){
       for(j=0; j<3; j++){
       printf("De la fila %d , digite el valor %d:  ", i+1,j+1);
       scanf("%f", &mtzb[i][j]);
       }
}
printf("\n");
printf("La matriz B es: \n");
for(i=0; i<3; i++){
	for(j=0; j<3; j++){
		printf(" %.2f ", mtzb[i][j]);
	}
	printf("\n");
}
printf("-------------------------------------------------------------------------------------------------------------------- \n");
//RESULTADOS:
printf("RESULTADOS: \n");
//Matriz A por constante, simplemente tomo el valor guardado en k y lo multiplico a la matriz A, haciendolo con un ciclo for para las filas, y otro for para las columnas. Similarmente a lo anterior se imprime la matriz.
printf("La matriz A por el escalar k es: \n");
for(i=0; i<3; i++){
	for(j=0; j<3; j++){
	multk[i][j] = k*mtza[i][j];	
	}
}
for(i=0; i<3; i++){
	for(j=0; j<3; j++){
		printf(" %.2f ", multk[i][j]);
	}
	printf("\n");
}
printf("\n");
//Suma de las matrices: las matruces se suman componente a componente, usando ciclo for para columna y civlo for para fila, sumamos las componentes de A con las de b. Imprimimos similar a lo anterior.
printf("La suma de la matriz A con la matriz B es: \n");
for(i=0; i<3; i++){
	for(j=0; j<3; j++){
	sum[i][j] = mtza[i][j]+mtzb[i][j];	
	}
}
for(i=0; i<3; i++){
	for(j=0; j<3; j++){
		printf(" %.2f ", sum[i][j]);
	}
	printf("\n");
}
printf("\n");
//Resta de las matrices:similar al proceso anterior, solo que ahora restando
printf("La resta de la matriz A con la matriz B es: \n");
for(i=0; i<3; i++){
	for(j=0; j<3; j++){
	res[i][j] = mtza[i][j]-mtzb[i][j];	
	}
}
for(i=0; i<3; i++){
	for(j=0; j<3; j++){
		printf(" %.2f ", res[i][j]);
	}
	printf("\n");
}
printf("\n");
//Producto de las matrices: Lo hacemos de la forma usual de producto de matrices, guardando cada resultado en cada componente de la salida. Imprimimos como en el proceso anterior.
printf("El producto de la matriz A con la matriz B es: \n");
mult[0][0]=mtza[0][0]*mtzb[0][0]+mtza[0][1]*mtzb[1][0]+mtza[0][2]*mtzb[2][0];
mult[1][0]=mtza[1][0]*mtzb[0][0]+mtza[1][1]*mtzb[1][0]+mtza[1][2]*mtzb[2][0];
mult[2][0]=mtza[2][0]*mtzb[0][0]+mtza[2][1]*mtzb[1][0]+mtza[2][2]*mtzb[2][0];
mult[0][1]=mtza[0][0]*mtzb[0][1]+mtza[0][1]*mtzb[1][1]+mtza[0][2]*mtzb[2][1];
mult[1][1]=mtza[1][0]*mtzb[0][1]+mtza[1][1]*mtzb[1][1]+mtza[1][2]*mtzb[2][1];
mult[2][1]=mtza[2][0]*mtzb[0][1]+mtza[2][1]*mtzb[1][1]+mtza[2][2]*mtzb[2][1];
mult[0][2]=mtza[0][0]*mtzb[0][2]+mtza[0][1]*mtzb[1][2]+mtza[0][2]*mtzb[2][2];
mult[1][2]=mtza[1][0]*mtzb[0][2]+mtza[1][1]*mtzb[1][2]+mtza[1][2]*mtzb[2][2];
mult[2][2]=mtza[2][0]*mtzb[0][2]+mtza[2][1]*mtzb[1][2]+mtza[2][2]*mtzb[2][2];
for(i=0; i<3; i++){
	for(j=0; j<3; j++){
		printf(" %.2f ", mult[i][j]);
	}
	printf("\n");
}
printf("\n");
//Determinante de la matriz A: Lo hacemos de la forma usual del producto vectorial, guardado los resultados de cada componente en variables auxiliares, para luego sumarlas. Guardamos el resultado e imprimimos como en el proceso anterior.
printf("El determinante de la matriz A es: \n");
d = (mtza[0][0])*(mtza[1][1]*mtza[2][2] - mtza[1][2]*mtza[2][1]);
dd = (mtza[0][1])*(mtza[1][2]*mtza[2][0] - mtza[1][0]*mtza[2][2]);
ddd = (mtza[0][2])*(mtza[1][0]*mtza[2][1] - mtza[1][1]*mtza[2][0]);
deta=d+dd+ddd;
printf("%f \n", deta);
printf("Si el determinante le resulta 0, es porque la matriz A no es invertible \n");
printf("\n");
//Transpuesta de la matriz B: Simplemente intercambiamos los subindices de los ciclos for que generan la matriz para que asi resultan los vectores fila, cambiados por los vectores columna.
printf("La transpuesta de la matriz B es: \n");
for (i=0; i<3; i++){
	for(j=0; j<3; j++){
		transb[i][j]=mtzb[j][i];
	}
}
for(i=0; i<3; i++){
	for(j=0; j<3; j++){
		printf(" %.2f ", transb[i][j]);
	}
	printf("\n");
}
printf("\n");
//Reduccion de Gauss-Jordan para la matriz A: Con el primer conjunto de for encontramos los elementos de la diagonal de la matriz y volvemos el resultado la matriz A multiplicada por la division de la matriz A con su transpuesta. Luego imprimimos similar al proceso anterior
printf("La reduccion Gauss-Jordan de la matriz A resulta: \n");
for (i=0; i<3; i++){
	for(j=0; j<3; j++){
		if(i!=j){
			g=mtza[i][j]/mtza[j][i];
			for(int k=0; k<4; k++){
				gaussa[i][k]=mtza[i][k]-g*mtza[i][k];
			}
		}
	}
}
for(i=0; i<3; i++){
	for(j=0; j<3; j++){
		printf(" %.2f ", gaussa[i][j]);
	}
	printf("\n");
}
printf("\n");
//Reduccion de Gauss-Jordan para la matriz B: Similar al proceso anterior solo que usando la matriz B
printf("La reduccion Gauss-Jordan de la matriz B resulta: \n");
for (i=0; i<3; i++){
	for(j=0; j<3; j++){
		if(i!=j){
			g=mtzb[i][j]/mtzb[j][i];
			for(int l=0; l<4; l++){
				gaussb[i][l]=mtzb[i][l]-g*mtzb[i][l];
			}
		}
	}
}
for(i=0; i<3; i++){
	for(j=0; j<3; j++){
		printf(" %.2f ", gaussb[i][j]);
	}
	printf("\n");
}
printf("\n");
printf("--------------------------------------------------------------------------------------------------------------------- \n");
}
