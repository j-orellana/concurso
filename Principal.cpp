#include <iostream>
#include <ctime>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "nodos.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//DECLARACION DE FUNCIONES Y VARIABLES ---------------------------------------------
void agregar(nodos*);
void presentar(nodos *);
void presentar_or(nodos *);
nodos *R, *T;

unsigned  t1, t2;
int n, continuar, op;

//USANDO ORDENAMIENTO DE ARBOL-----------------------------------------------------
int main(int argc, char** argv) {
	string linea;
	//MENU PARA INGRESAR LOS ARCHIVOS----------------------------------------------
	do{
		cout<<"Elija que conjunto de datos con el que desea trabajar"<<endl;
		cout<<"1) Archivo de 24 Mil "<<endl;
		cout<<"2) Archivo de 240 Mil "<<endl;
		cout<<"3) Archivo de 24 Millones "<<endl;
		cout<<"4) Archivo de 1 mil "<<endl;
		cout<<"5) Salir "<<endl;
		cin>>n;
	
		switch(n){
			case 1:{
				ifstream fo("C:\\textos\\ejemplo_24milR.txt");
				break;
			}
			case 2:	{
				ifstream fo("C:\\textos\\ejemplo240MIL.txt");
				break;
			}
			case 3:{
				ifstream fo("C:\\textos\\ejemplo.txt");
				break;		
			}
			case 4: {
				ifstream fo("C:\\textos\\ejemplo_mil.txt");
				break;
			}
			case 0: 
				break;
			default:
				cout<<"Opcion no valida"<<endl;
		}	
	//LEER EL ARCHIVO QUE SE UTILIZARA-------------------------------------
		while(!fo.eof()){
			fo>>linea;
			if(!fo.eof()){
				T=new nodos();
				T->id=atoi(linea);
				T->De=NULL;
				T->Iz=NULL;
				
				agregar(R);;
			}
		}
		//ELEGIR ORDENAMIENTOS-------------------------------------------------
		t1 = clock();
		cout<<"Menu"<<endl;
//		cout<<"1) Presentar"<<endl;
		cout<<"1) Ordenar Ascendente"<<endl;
		cout<<"2) Ordenar Descendente"<<endl;
		cout<<"0) Salir"<<endl;
		cin>>op;
		switch(op){
			case 1:
				presentar(R);
				break;
			case 2:
				presentar_or(R);
				break;
			case 0:
				break;
			default:
				cout<<"Opcion no valida"<<endl;
		}
		
		t2 = clock();
		double time = (double(t2-t1)/CLOCKS_PER_SEC);
	
		cout<<"Digite 1 para continuar, cualquier otro numero para salir: "<<endl;
		cin>>continuar;
	} while ( continuar == 1 );
	return 0;
}
//AGREGAR NODOS --------------------------------------------------------------------------------
void agregar(nodos *p){
	if(R==NULL){
		R=T;
	}
	else if(T->id>p->id){
		if(p->De==NULL){
			p->De=T;
		}
		else{
			agregar(p->De);
		}
						
	}
	else{		
		if(p->Iz==NULL){
			p->Iz=T;
		}
		else{
			agregar(p->Iz);
		}
		
	}
}
//PRESENTAR DE MODO DESCENDENTE ------------------------------------------------------------
void presentar(nodos *p){
	if(p==NULL){
		return;
	}
	else{
		cout<<"ID: "<<p->id<<endl;
		presentar(p->De);
		presentar(p->Iz);
	}
	
}
//PRESENTAR DE MODO ASCENDENTE-----------------------------------------------------------------
void presentar_or(nodos *p){
	if(p==NULL){
		return;
	}
	else{
	
		presentar_or(p->De);
			cout<<"ID: "<<p->id<<endl;
		presentar_or(p->Iz);	
}
}
//FIN DE PROYECTO-----------------------------------------------------------------------------------

