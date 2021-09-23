#include <iostream>
#include <stdlib.h>
#include <unordered_map>
using namespace std;

struct Nodo {
  int dato;
  Nodo *der;
  Nodo *izq;
};

Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void mostrarArbol(Nodo *, int);
bool busqueda(Nodo *, int);
void preOrden(Nodo *);
void profundidad(Nodo *);

Nodo *arbol = NULL;
int profIzq = 1;
int proftDer = 1;

int main() {
  int dato;

  for(int i = 0; i < 5; i++){
		cin>>dato;    
		insertarNodo(arbol, dato);
  }
	cout<<endl;

  mostrarArbol(arbol, 0);
	cout<<endl;

	if(arbol != NULL){
		profundidad(arbol);
		if(profIzq > proftDer){
			cout<<"Profundidad del arbol: "<<profIzq<<endl;
		}else{
			cout<<"Profundidad del arbol: "<<proftDer<<endl;
		}
	}else{
			cout<<"Profundidad del arbol: "<<0;
	}
}

Nodo *crearNodo(int n) {
  Nodo *nuevoNodo = new Nodo();
  nuevoNodo -> dato = n;
  nuevoNodo -> der = NULL;
  nuevoNodo -> izq = NULL;
  return nuevoNodo;
}

void insertarNodo(Nodo *&arbol, int n){
  if(arbol == NULL){
    Nodo *nuevoNodo = crearNodo(n);
    arbol = nuevoNodo;
  }else{
    int valorRaiz = arbol -> dato;
    if(valorRaiz > n)
      insertarNodo(arbol -> izq, n);
    else
      insertarNodo(arbol -> der, n);
  }
}

void mostrarArbol(Nodo *arbol, int cont) {
  if(arbol == NULL){
    return;
  }else{
    mostrarArbol(arbol->der, cont+1);
    for(int i = 0; i < cont; i++){
      cout<<"   ";
    }
    cout<<arbol->dato<<endl;
    mostrarArbol(arbol->izq, cont+1);
  }
}

bool busqueda(Nodo *arbol, int n) {
  if(arbol == NULL){
    return false;
  }else if(arbol->dato == n){
    return true;
  }else if(arbol->dato > n){
    return busqueda(arbol->izq, n);
  }else{
    return busqueda(arbol->der, n);
  }
}

void preOrden(Nodo *arbol){
  if(arbol == NULL){
    return;
  }else{
    cout<<arbol->dato<<" - ";
    preOrden(arbol->izq);
    preOrden(arbol->der);
  }
}


void profundidad(Nodo *arbol){
	if(arbol == NULL){
		return;
	}else{
		if(arbol->izq != NULL){
			profIzq++;
			profundidad(arbol->izq);
		}
		if(arbol->der != NULL){
			proftDer++;
			profundidad(arbol->der);
		}
	}
}