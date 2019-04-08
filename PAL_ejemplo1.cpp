#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>
using namespace std;
struct alumno
{
//campos
char nombre[20];
char apellido[20];
char carnet[9];
float n_p1;
float n_p2;
float n_p3;
float nota_ciclo;
//funciones
void calcular_nota_final(void){
//determina nota final de la materia cursada
//operan a los campos de la estructura
nota_ciclo= (n_p1*0.3)+ (n_p2*0.35)+(n_p3*0.35);
}//fin funcion nota_final_ciclo
};//fin definicion del struct alumno
main(){
alumno alumno1; //Creando una variable de tipo estructura alumno
cout<<"\nIngrese los siguientes datos del estudiante:";
cout<<"\nNombre ? "; gets(alumno1.nombre);
cout<<"\nApellido ? "; gets(alumno1.apellido);
cout<<"\nCarnet ? "; gets(alumno1.carnet);
cout<<"\n\n-> ahora digite a cada una de las 3 notas de periodo:\n";
cin>>alumno1.n_p1>>alumno1.n_p2>>alumno1.n_p3;
//llama a la funcion de la struct
alumno1.calcular_nota_final();
system("cls");
cout<<"\t--------------------------------------------"<<endl;
cout<<"\t- INFORME DE RESULTADOS -"<<endl;
cout<<"\t--------------------------------------------"<<endl;
cout<<"\t Nombre del alumno: "<<alumno1.nombre<<" "<<alumno1.apellido<<endl;
cout<<"\t Carnet: "<<alumno1.carnet<<endl;
cout<<setprecision(3)<<"\t Nota del ciclo: "<<alumno1.nota_ciclo<<endl;
if(alumno1.nota_ciclo>=6)
cout<<"\t Estado: Aprobado"<<endl;
else
cout<<"\t Estado: Reprobado"<<endl;
system("PAUSE");
}//fin funcion principal
