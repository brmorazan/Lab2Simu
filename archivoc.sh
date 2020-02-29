#!/bin/bash
#Variable n para el nombre del archivo .c
echo "Ingrese el nombre del archivo"
read n
#Preguntando si el nombre esta vacio
if [ "$n" ==  "" ]
then 
echo "El archivo no se creo, ya que no tiene un nombre"

else
	#Preguntando si se escribio ".c"
	if [ "${n:(-2)}" == ".c" ]        
	then 
	echo "Tiene que ingresar el nombre sin el .c"
   #Si no se cumplieron las condiciones anteriores se procede a crear el archivo 
   else
	   #Variables necesarias en las que guardare informacion obtenida de mi ordenador
	   m=$(hostname)
	   v=$(gcc --version)
	   f=$(date)
	   #Solo necesito la primer linea de gcc version, entonces creo archivo txt para obtener desde ahi la linea requerida
	   touch vgcc.txt
	   echo "$v" > vgcc.txt
	   #Creando el archivo .c
	   ruta=/home/bryant/Documentos
	   touch $ruta/$n.c
	   #Variable para el resumen: a
	   echo "Ingrese su resumen"
	   read a
	   touch res.txt
	   echo "$a" > res.txt
	   #Variable de entrada: e
	   echo "Ingrese sus variables de entrada"
	   read e
	   touch ent.txt
	   echo "$e" > ent.txt
	   #Variable de salida: s
	   echo "Ingrese sus variables de salida"
	   read s
	   touch sal.txt
	   echo "$s" > sal.txt
	   #Desplegando encabezado en el archivo .c
	   echo "/*
Autor: $m
Compilador: $(head -1 vgcc.txt)
Compilado: gcc $n.c -o $n
Fecha: $f
Resumen: $(head -1 res.txt)
Entrada: $(head -1 ent.txt)
Salida: $(head -1 sal.txt)
*/

//Librerias
#include <stdio.h>
//numerar los pasos del pseudocodigo
	   " > $n.c
	   #Borrando archivos que use para copiar textos necesarios
	   rm vgcc.txt
	   rm res.txt
	   rm ent.txt
	   rm sal.txt
	   vim $n.c

	fi
fi

	   
