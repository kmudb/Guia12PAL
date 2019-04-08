#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>
using namespace std;
struct Fecha
{
//campos
int dia;
int mes;
int anio;
//metodos
Fecha(){ //constructor
dia=1; //inicializa campos con una fecha predeterminada
mes=1;
anio=1950;
}
void ingresar(char descrip[]){
	//recibe dia, mes y año en sus campos
cout<<"\nDigite fecha de "<<descrip<<":";
cout<<"\n\tdia ? "; cin>>dia;
cout<<"\n\tmes ? "; cin>>mes;
cout<<"\n\ta\xa4o ? "; cin>>anio;
}
void imprimir(void){
//muestra fecha en formato dd/mm/aaaa
cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
};
struct Persona
{
//campos
char nombre[20];
char apellido[20];
int edad;
//funciones (Metodos)
void ingresardatos(){
cout<<"\n Apellido(s) ??"; gets(apellido);
cout<<"\n Nombres ?? ";
fflush(stdin); //limpiando el buffer de teclado
gets(nombre);
cout<<"\n Edad (a\xa4os) ??"; cin>>edad;
}
};
struct Empleado
{
//campos de info de un empleado
Persona persona; //struct anidada
Fecha nac;//struct anidada
char cargo[20]; //cargo desempeñado
float salario; //salario mensual
//funciones
void solicitardatos(){
//Establece los valores de los miembros
persona.ingresardatos(); //invoca metodo de struct persona
nac.ingresar("nacimiento"); //invoca metodo de struct Fecha
cout<<"\n Digite cargo actual: ";
fflush(stdin); gets(cargo);
cout<<"\n Salario: $ "; cin>>salario;
}
void verInfo(){
//muestra en pantalla a la informacion de empleado
cout<<setw(22)<<" Nombre completo: "<<this->persona.nombre
<<" "<<this->persona.apellido<<endl;
cout<<setw(22)<<" Edad: "<<this->persona.edad<<
" a"<<char(164)<<"os"<<endl;
cout<<setw(22)<<" Fecha de nacimiento: "; this->nac.imprimir();
cout<<setw(22)<<" Cargo: "<<this->cargo<<endl;
cout<<setw(22)<<" Salario: "<<"$ "<<this->salario<<endl;
cout<<endl;
}
}; //fin struct Empleado
main(){
Empleado Miriam; //variable de tipo Empleado
cout<<"\n\tIngrese datos personales y laborales del empleado:\n";
//invoca a metodo de struct Empleado
Miriam.solicitardatos();
system("cls");
cout<<"\t-------------------------------------------------"<<endl;
cout<<"\t- DATOS DE EMPLEADO INGRESADO -"<<endl;
cout<<"\t-------------------------------------------------"<<endl;
Miriam.verInfo();
system("PAUSE");
}

