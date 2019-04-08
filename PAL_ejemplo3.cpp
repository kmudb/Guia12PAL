#include<iostream>
using namespace std;
#include<iomanip>
#include<conio.h>
#include<windows.h>
#include "PAL_publicaciones.h" //agrega a nueva libreria

void listar_libros(int cantidad, libro libros[]);
void buscar_por_autor(char cadena_busqueda[],int cantidad, libro listado_libros[]);

main(){
libro listado_libros[50];//definiendo arreglo de tipo "libro"
int cant=0;//cantidad de libros registrados
bool salir=false;//controla la salida del menu principal
char opcion;//opcion seleccionada en el menu principal
int codigo;//codigo del libro seleccionado
bool salir_submenu=false;
char opcion_busqueda;
char cadena_busqueda[50];//Almacenará la cadena a buscar
do{
	system("cls");
	cout<<"\t----------------------------------------------"<<endl;
	cout<<"\t- LIBRERIA EL RINCON DEL SABER -"<<endl;
	cout<<"\t----------------------------------------------"<<endl;
	cout<<"\t- OPCIONES DISPONIBLES: -"<<endl;
	cout<<"\t- 1- Registrar nuevo libro -"<<endl;
	cout<<"\t- 2- Modificar libro existente -"<<endl;
	cout<<"\t- 3- Listar libros existentes -"<<endl;
	cout<<"\t- 4- Buscar libros -"<<endl;
	cout<<"\t- 9- Salir -"<<endl;
	cout<<"\t---------------------------------------------"<<endl;
	cout<<"\n\tSelecciona una opcion: ";
	opcion=getche();//Leyendo la opcion seleccionada
	switch(opcion){
		case '1'://Registrar nuevo libro
			system("cls");
			//invoca a motodo registrar () del libro actual
			listado_libros[cant].registrar();
			cant++;//aumentamos la cantidad de libros en 1
			system("PAUSE");
		break;
		case '2'://Modificar libro existente
			system("cls");
			cout<<"Modificando a un libro ...";
			/*llamada a la funcion listar libros, se pasa como parametro la cantidad de libros registrados y el vector de variables de tipo "libro" a listar*/
			listar_libros(cant,listado_libros);
			cout<<"\n\nIngresa el codigo del libro que deseas modificar: ";
			cin>>codigo;
			//Verificamos si el codigo del libro existe o no
			if(codigo>cant){
			cout<<"\nNo existe un libro registrado con este codigo!!"<<endl;
			system("PAUSE");
			continue;
			}else
			//llamada a metodo modificar de posicion de vector de libros
			listado_libros[codigo-1].modificar();
		break;
		case '3'://Listar libros existentes
			system("cls");
			/*llamada a la funcion listar libros, se pasa como parametro la cantidad de libros registrados y el vector de variables de tipo "libro" a listar*/
			listar_libros(cant,listado_libros);
			system("PAUSE");
			break;
			case '4': //buscar libros
			salir_submenu=false;
			do{
				system("cls");
				cout<<"\t------------------------------------------"<<endl;
				cout<<"\t- BUSQUEDA DE LIBROS -"<<endl;
				cout<<"\t------------------------------------------"<<endl;
				cout<<"\t- OPCIONES DISPONIBLES: -"<<endl;
				cout<<"\t- A- Buscar por autor -"<<endl;
				cout<<"\t- B- Buscar por titulo -"<<endl;
				cout<<"\t- S- Regresar al menu principal -"<<endl;
				cout<<"\t------------------------------------------"<<endl;
				cout<<"Selecciona una opcion de busqueda: ";
				opcion_busqueda=getche();
				switch(opcion_busqueda){
				case 'A':case 'a':
				//busqueda por autor
				cout<<"\n Ingresa el nombre del autor a buscar: ";
				fflush(stdin);gets(cadena_busqueda);
				system("cls");
				/*llamada a la funcion buscar_por_autor pasando como parametros
				la cadena a buscar, la cantidad de libros registrados
				y el arreglo de variables de tipo libro*/
				buscar_por_autor(cadena_busqueda,cant,listado_libros);
				cout<<endl;
				system("PAUSE");
			break;
			case 'B':case 'b':
				break;
			case 'S': case 's':
				salir_submenu=true;
			break;
			}//fin switch opcion_busqueda
		}while(salir_submenu==false);
		break;
		case '9':
			cout<<"\n\t GRACIAS POR VISITARNOS, HASTA LUEGO"<<endl;
			Sleep(1000);
		salir=true;
		}
	system("cls");
	}
while(salir==false);
}//fin main

/*Este procedimiento recorre lista de libros ingresados
hasta ese momento.
En parametros se transfiera al arreglo de tipo libro y la cantidad de libros que se han ingresado*/
void listar_libros(int cantidad, libro libros[]){
	cout<<"\n-------------------------------------------"<<endl;
	cout<<" LISTADO DE LIBROS DISPONIBLES -"<<endl;
	cout<<"---------------------------------------------"<<endl;
	if(cantidad>0){ //si ya hay libros registrados
		cout.setf(ios::left);
		cout<<"\n # "<<setw(20)<<"Titulo"<<setw(20)<<"Autor"<<endl;
	for(int i=0;i<cantidad;i++){
		//muestra datos de un libro especifico
		cout<<setw(4)<<i+1<<" "<<setw(20)<<libros[i].titulo<<
		setw(20)<<libros[i].autor<<endl;
	}
	cout.unsetf(ios::left);
	}
	else //Si aun no se ha registrado ningun libro ....
		cout<<"\n Aun no se ha registrado ningun libro"<<endl;
}//fin funcion listar_libros

void buscar_por_autor(char cadena_busqueda[],int cantidad, libro listado_libros[]){
int resultados=0;//Cantidad de resultados de la busqueda
cout<<"\t-----------------------------------------------"<<endl;
cout<<"\t- BUSQUEDA POR AUTOR -"<<endl;
cout<<"\t---------------------------------------------"<<endl;
cout<<"Autor a buscar: "<<cadena_busqueda<<endl;
cout<<"\nResultados de la busqueda: ";
for(int i=0;i<cantidad;i++){
	//compara si dos cadenas son identicas...
	if(strcmp(cadena_busqueda, listado_libros[i].autor)==0){
	//imprime datos de los libros encontrados en la busqueda
	listado_libros[i].ver();
	resultados++;//Se aumentan en 1 la cantidad de resultados obtenidos
	}
}
if(resultados==0)//Si no hay ningun resultado entonces...
	cout<<"\n Lo siento, no se encontraron coincidencias"<<endl;
}//fin funcion buscar_por_autor
