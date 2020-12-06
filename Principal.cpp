#include <iostream>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "nodos.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

nodos *R, *T;
void abrir();
void agregar(nodos *);
void presentar(nodos *);
int buscar(nodos *, int);
void ascendente(nodos *);
void descendente(nodos *);
unsigned t1,t2;
char linea[6];
char nombre[6];
int x, n, b, op;
int main(int argc, char** argv) {
		
	do{
		cout<<"Menu"<<endl;
		cout<<"1) Abrir"<<endl;
		cout<<"2) Ordenar Ascendente"<<endl;
		cout<<"3) Ordenar Descendente"<<endl;
		cout<<"4) Presentar"<<endl;
		cout<<"5) Buscar"<<endl;
		cout<<"0) Salir"<<endl;
		cin>>op;
		cout<<endl;

		switch(op){
			case 1:
				abrir();
				break;
			case 2:{
				t1 = clock();
				ascendente(R);			
				t2 = clock();
				double time = (double(t2-t1)/CLOCKS_PER_SEC);
				cout<<time<<endl;
				break;}
			case 3:{
				t1 = clock();
				descendente(R);		
				t2 = clock();
				double time = (double(t2-t1)/CLOCKS_PER_SEC);
				cout<<time<<endl;
				break;
			}
				
			case 4:{
					
				presentar(R);
				break;
			}
			case 5:{
				cout<<"Ingrese el ID -> ";
				cin>>b;
				t1 = clock();
				buscar(R,b);
				/*if(buscar(R,b)==true){
					cout<<"Valor encontrado" <<endl;
				}
				else{
					cout<<"Dato no encontrado"<<endl;
				}*/
				t2 = clock();
				double time = (double(t2-t1)/CLOCKS_PER_SEC);
				cout<<time<<endl;
				break;
			}		
			case 0:
				break;
			default:
				cout<<"Opcion no valida"<<endl;
		}
	}while(op!=0);
	
	return 0;
}

void abrir(){
	string url;
	cout<<"Elija que conjunto de datos desea ordenar"<<endl;
	cout<<"1) Archivo de 24 Mil "<<endl;
	cout<<"2) Archivo de 240 Mil "<<endl;
	cout<<"3) Archivo de 24 Millones "<<endl;
	cout<<"4) Archivo de 1 mil "<<endl;
	cout<<"5) Salir "<<endl;
	cin>>n;
	cout<<endl;
	switch(n){
		case 1:{
			url = ("C:\\textos\\ejemplo_24milR.txt");
			break;
		}
		case 2:{
			url = ("C:\\textos\\ejemplo240MIL.txt");
			break;
		}
		case 3:{
			url = ("C:\\textos\\ejemplo.txt");
			break;
		}
		case 4: {
			url = ("C:\\textos\\ejemplo_mil.txt");
			break;}
		default:
			cout<<"Opcion no valida, se usara archivo corto"<<endl;
			url = ("C:\\textos\\ejemplos_de_ejemplos.txt");
	}	
	ifstream fi(url.c_str());
	while(!fi.eof()){
		fi>>linea;
		fi>>nombre;
		
		if(!fi.eof()){
			x=atoi(linea);
			agregar(R);
		}
	}
}

void agregar(nodos *p){
	if(R==NULL){
		T=new nodos();
		T->id=x;
		T->nombre=nombre;
		T->De=NULL;
		T->Iz=NULL;
		R=T;
	}
	else if(T->id>p->id){
		if(p->De==NULL){
			T=new nodos();
			T->id=x;
			T->nombre=nombre;
			T->De=NULL;
			T->Iz=NULL;
			p->De=T;
		}
		else{
			
			agregar(p->De);
		}
						
	}
	else{		
		if(p->Iz==NULL){
			T=new nodos();
			T->id=x;
			T->nombre=nombre;
			T->De=NULL;
			T->Iz=NULL;
			p->Iz=T;
		}
		else{
			agregar(p->Iz);
		}
		

}
}
int buscar(nodos *p, int x){
	if(p==NULL){
		cout<<"Valor no encontrado" <<endl;
		//return false;
	}
	else if(p->id==x){
		cout<<"Valor encontrado" <<endl;
		cout<<p->nombre<<endl;
	}
	else if(n < p->id){
		buscar(p->Iz,x);
		//	return true;					
	}

	else{
		buscar(p->De,x);
	}
	}


void presentar(nodos *p){
	if(p==NULL){
		return;
	}
	else{
		cout<<"ID: "<<p->id<<endl;
		cout<<"-> "<<p->nombre<<endl;
		presentar(p->Iz);
		presentar(p->De);
	}
}

void ascendente(nodos *p){
	
	if(p==NULL){
	//	cout<<"nada"<<endl;
		return;
	}
	else{
		ascendente(p->Iz);
		cout<<"ID : "<<p->id<<endl;
		cout<<"->  "<<p->nombre<<endl;;
		ascendente(p->De);
	}


}

void descendente(nodos *p){
	
	if(p==NULL){
		return;
	}
	else{
	
		descendente(p->De);
			p->id;
			p->nombre;
		descendente(p->Iz);	
}
	}
