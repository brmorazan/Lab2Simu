/*
Autor: bryant
Compilador: gcc (Debian 6.3.0-18+deb9u1) 6.3.0 20170516
Compilado: gpp examenfinal.cpp -o examenfinal
Fecha: mié may 20 08:00:11 CST 2020
Resumen: 
Entrada: 
Salida: 
*/

//Librerias
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;
//numerar los pasos del pseudocodigo
//-----------------------------------------------------------------------------------------
//
class cohete{
    private: //atributos(caracteristicas)
    double Eo;
    double TSFC;
    double CD;
    double A;
    double mo;
    double mfo;
    

    public: //metodos(acciones)
    cohete(double, double, double, double, double, double);
    void despegar();
    float tiemposincomb();
    
   

};

//Constructor de la clase cohete
cohete::cohete(double _Eo, double _TSFC, double _CD, double _A, double _mo, double _mfo){
    Eo=_Eo;
    TSFC=_TSFC;
    CD=_CD;
    A=_A;
    mo=_mo;
    mfo=_mfo;
    


};
//Tiempo en que se queda sin combustible
float cohete::tiemposincomb(){
    float t;
    t=mfo/(-TSFC*Eo);
    cout << "Se queda sin combustible a los" <<t<< "segundos" <<endl;
}
//Prototipos de funciones

float densidad(float dens);
double altura(double y);
float gravedad(float g);
float friccion(float fricc);
float masa(float m);
double velocidad(double v);
void grafica();


//Constructor Funcion despegar
void cohete::despegar(){
    float G = 6.693*pow(10,-11);
    float Rt = 6.378*pow(10,6);
    float Mt = 5.9736*pow(10,24);
    float R = 287.06;
    float L = 6.5*pow(10,-3);
    float go = 9.81;
    float To = 288.15;
    float Po = 101325;
    
    //Variables internas
    float tfinal = 1800;
    float delta = 0.01;
    
    //Punteros
    FILE *pf1;
    FILE *pf2;
    FILE *pf3;

    pf1 = fopen("pos1.txt", "wt");
    pf2 = fopen("pos2.txt", "wt");
    pf3 = fopen("pos3.txt", "wt");

    pf1 = fopen("v1.txt", "wt");
    pf2 = fopen("v2.txt", "wt");
    pf3 = fopen("v3.txt", "wt");




     //Calculo de y
    double altura(double y){{
    for(int t =0; t < 25; t++){
        y = y+delta*v;
        fprint(pf1, "%lf\t%\n", delta*t, y);

    }
        return y;

    }
    
    //Calculo de v
    double velocidad(double v){
    for(int t =0; t < 25; t++){
        if(t==0)
        {
            v=0;
        }
        else{
            v = v + delta*(Eo/masa)-gravedad-(friccion/masa);
        }
        fprint(pf1, "%lf\t%\n", delta*t, v);

    }
    return v;}
   if (velocidad<0 && altura == 0){

   }
    
};





int main(){
    //Definiendo los 3 cohetes(objetos)
    cohete coh1(3.0e7, 3.248e-4, 61.27, 201.6, 1.1e5, 1.5e6);
    cohete coh2(2.7e7, 2.248e-4, 61.27, 201.6, 1.1e5, 1.5e6);
    cohete coh3(2.5e7, 2.24e-4, 70.25, 215, 1.8e5, 1.5e6);
//Desplegando el tiempo en que se queda sin combustible
    coh1.tiemposincomb();
    coh2.tiemposincomb();
    coh3.tiemposincomb();
//Calculando parametros de movimiento y graficas
    coh1.despegar();
    coh2.despegar();
    coh3.despegar();

//Imprimiendo
system("gnuplot 'plot.gp'");
sysem("replot pos1.txt   pos2.txt   pos3.txt   v1.txt   v2.txt   v3.txt");



}


//Definiendo funcion de densidad
    float densidad(float dens){
    if(To/L<y){
       dens = 0; 
    }else{
    dens = (Po/(R*To))*pow((1-((L*y)/To)),(go/R*L));
    }
    return dens;
    }
    //Definiendo funcion de g
    float gravedad(float g){
    g = (G*Mt)/pow(Rt+y,2);
    return g;
    }
    //Definiendo funcion de friccion
    float friccion(float fricc){
    fricc = (densidad/2)*CD*v*fabs(v);
    return fricc;
    }
    //Definiendo funcion de masa
    
    float masa(float m){
        for(int t =0; t < 25; t++){
            mf = mf - delta*TSFC*Eo*t;
        }
        m = mfo+mf;
        return m;

    }

    //DEfiniendo funcion graficar
    void graficar(){
        FILE *pf
        pf = fopen ("plot.gp", "wt");
        fprint(pf, "plot 'plot.txt'");
        fclose(pf);
    }







