#include<iostream>
using namespace std;
#include<iomanip>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
struct libro{
//campos
char titulo[60];//Nombre del libro
char autor[30]; //Autor del libro
int anio_publicacion; //Año de publicacion de libro
float precio;//precio del libro
//métodos (prototipos)s
//	libro();
	void ver(void);
	void registrar(void);
	void modificar(void);
	char Capturar_MenuModificar();
	
	libro(){ //constructor
		titulo[0]='\0';
		strcpy(titulo,"SIN TITULO");
		strcpy(autor, "DESCONOCIDO");
		anio_publicacion=1900;
		precio=0;
	}
}; //fin struct libro
//Definicion métodos del struct libro


void libro::ver(void){
//despliega los valores registrados en los campos
cout<<endl;
cout<<setw(10)<<"Titulo: "<<titulo<<endl;
cout<<setw(10)<<"Autor: "<<autor<<endl;
cout<<"A\xa4o publicacion: "<<anio_publicacion<<endl;
cout<<setw(10)<<"Precio: $ "<<precio<<endl;
}


void libro::registrar(void){
//solicita valores de campos del libro
system("cls");
cout<<"\t----------------------------------------------"<<endl;
cout<<"\t- REGISTRANDO NUEVO LIBRO -"<<endl;
cout<<"\t---------------------------------------------"<<endl;
cout<<"\nTitulo ? "; fflush(stdin); gets(this->titulo);
cout<<"\nAutor(es) ? "; fflush(stdin); gets(this->autor);
cout<<"\nA"<<char(164)<<"o de publicacion ? ";
cin>>this->anio_publicacion;
cout<<"\nPrecio del libro ? $ "; cin>>this->precio;
cout<<"\n LIBRO REGISTRADO EXITOSAMENTE"<<endl;
}//fin metodo registrar


void libro::modificar(void){
//permite a usuario elegir campo a modificar
bool salir=false;
char opc, menu;
do{
	system("cls");
	cout<<"----------MODIFICACION DE LIBRO-----------------"<<endl;
	cout<<"-- Datos del libro elegido:";
	this->ver(); //muestra datos del libro que se modificara
	cout<<"\n * Seleccione letra de la accion que desea ejecutar:"<<endl;
	cout<<" Modificar ... \n";
	cout<<" (t) ..Titulo (a) ..Autor(es) (p) ..A\xa4o publicacion";
	cout<<" (v) ..Precio\n\n (s o ESC) Finalizar modificacion\n";
	opc=Capturar_MenuModificar();//captura opcion elegida por usuario
	switch(opc){
		case 't': case 'T':
			cout<<"\nIngresa nuevo titulo: ";
			fflush(stdin); gets(this->titulo);
		break;
		case 'a': case 'A':
			cout<<"\nIngresa nuevo autor: ";
			fflush(stdin); gets(this->autor);
		break;
		case 'p': case 'P':
			cout<<"\nDigita a\xa4o de publicacion: ";
			cin>>this->anio_publicacion;
		break;
		case 'v': case 'V':
			cout<<"\nDigita nuevo precio: $";
			cin>>this->precio;
		break;
		default:
		salir=true;
		//finaliza modificacion actual
	}//fin switch opc
}while(!salir);
}//fin metodo modificar

char libro::Capturar_MenuModificar(){
//genera ciclo infinito hasta que usuario presione opcion menu correcta
	char menu;
	do{
		menu=getch(); //captura tecla presionada
		switch(menu){ //valida opcion de menu
		case 't': case 'T': case 'a': case 'A':
		case 'p': case 'P': case 'v': case 'V':
		case 's': case 'S': case 27:
		return(menu); //finaliza ciclo infinito
		}
	}while(true);
}//fin Capturar_MenuModificar


