#!bin/bash

c=$(curl wttr.in)     #Declarando variable que guarda lo desplegado por el comando wttr
touch wtt.txt         #Creando mi archivo donde guardare el texto desplegado por wttr
echo "$c" > wtt.txt   #Copiando el texto de wttr a mi archivo creado
head -7 wtt.txt       #Desplegando en el terminal las primeras 7 lineas del archivo creado
rm wtt.txt            #Eliminando el archivo 


