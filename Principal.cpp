#include <iostream>
#include <ctime>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "nodos.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void agregar(string);
void presentar(nodos *);
void ascendente(nodos *);
void descendente(nodos *);
nodos *R, *T;
usingned t1, t2;
int n, continuar, op;
int main(int argc, char** argv) {
	string linea;
	do{
		cout<<"Elija que conjunto de datos con el que desea trabajar"<<endl;
		cout<<"1) Archivo de 24 Mil "<<endl;
		cout<<"2) Archivo de 240 Mil "<<endl;
		cout<<"3) Archivo de 24 Millones "<<endl;
		cout<<"4) Archivo de 1 mil "<<endl;
		cout<<"5) Salir "<<endl;
		cin>>n;
	
		switch(n){
			case 1:
				ifstream fo("C:\\textos\\ejemplo_24milR.txt");
				break;
			case 2:
				ifstream fo("C:\\textos\\ejemplo240MIL.txt");
				break;
			case 3:
				ifstream fo("C:\\textos\\ejemplo.txt");
				break;
			case 4: 
				ifstream fo("C:\\textos\\ejemplo_mil.txt");
				break;
			case 0: 
				break;
			default:
				cout<<"Opcion no valida"<<endl;
		}	
		while(!fo.eof()){
			fo>>linea;
			if(!fo.eof()){
				agregar(linea);
			}
		}
		t1 = clock();
		cout<<"Menu"<<endl;
		cout<<"1) Presentar"<<endl;
		cout<<"2) Ordenar Ascendente"<<endl;
		cout<<"3) Ordenar Descendente"<<endl;
		cout<<"0) Salir"<<endl;
		cin>>op;
		switch(op){
			case 1:
				presentar();
				break;
			case 2:
				ascendente();
				break;
			case 3:
				descendente();
				break;
			case 0;
				break;
			default:
				cout<<"Opcion no valida"<<endl;
		}	
		t2 = clock();
		double time = = (double(t2-t1)/CLOCKS_PER_SEC);
	
		cout<<"Digite 1 para continuar, cualquier otro numero para salir: "<<endl;
		cin>>continuar;
	} while ( continuar == 1 );
	return 0;
}
void agregar(string line){
	
}
void presentar(nodos *);
void ascendente(nodos *);
void descendente(nodos *);
