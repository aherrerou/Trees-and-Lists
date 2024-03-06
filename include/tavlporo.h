#ifndef _TAVLPORO_
#define _TAVLPORO_
#include "tvectorporo.h"

// A estudiar metodo que lea datos de una lista e inserte en un arbol

class TNodoAVL;

class TAVLPoro{
	friend class TNodoAVL;
	friend ostream & operator<<(ostream &, const TAVLPoro &);
private:
	TNodoAVL *raiz;	
	// AUXILIAR: Devuelve el recorrido en inorden
	void InordenAux(TVectorPoro &, int &)const;
	// AUXILIAR: Devuelve el recorrido en preorden
	void PreordenAux(TVectorPoro &, int &)const;
	// AUXILIAR: Devuelve el recorrido en postorden
	void PostordenAux(TVectorPoro &, int &) const;
	void Copiar(const TAVLPoro &);
	void Equilibrio();
	void EquilibrioII();
	void EquilibrioID();
	void EquilibrioDD();
	void EquilibrioDI();
	void ActualizarFE();
	
public:
	//Constructor por defecto
	TAVLPoro();
	//Constructor de copia
	TAVLPoro(const TAVLPoro &);
	//Destructor
	~TAVLPoro();
	//Sobrecarga del operador de asignacion
	TAVLPoro & operator=(const TAVLPoro &);
	//Sobrecarga del operador igualdad
	bool operator==(const TAVLPoro &)const;
	//Sobrecarga del operador desigualdad
	bool operator!=(const TAVLPoro &)const;
	// Devuelve true si el arbol está vacío
	bool EsVacio() const;
	// Inserta un elemento TPoro en el arbol
	bool Insertar(const TPoro &);
	// Devuelve si el elemento TPoro esta en el arbol
	bool Buscar(const TPoro &)const;
	//Borra un elemento TPoro del arbol AVL
	bool Borrar(const TPoro &);
	// Devuelve la altura de un arbol
	int Altura()const;
	//Devuelve el elemento raiz del arbol AVL
	TPoro Raiz()const;
	//Devuelve el numero de nodos del arbol
	int Nodos()const;
	// Devuelve el numero de nodos hoja en el arbol
	int NodosHoja()const;
	//Devuelve el recorrido en Inorden
	TVectorPoro Inorden()const;
	//Devuelve el recorrido en Preorden
	TVectorPoro Preorden()const;
	//Devuelve el recorrido en Postorden
	TVectorPoro Postorden()const;
	// Sobrecarga del operador salida
	
};

class TNodoAVL{
// Declaramos la amistad
	friend class TAVLPoro;
private:
	//El elemento del nodo
	TPoro item;
	// Subarbol izquierdo y derecho
	TAVLPoro iz, de;
	// Factor de equilibrio
	int fe;
	//Puntero al nodo raiz
	TNodoAVL *raiz;

	//AUXILIAR : Devuelve el recorrido Inorden
	void InordenAux(const TVectorPoro &, int &) const;
	//AUXILIAR : Devuelve el recorrido en Preorden
	void PreordenAux(const TVectorPoro , int &) const;
	//AUXILIAR : Devuelve el recorrido en postorden
	void PostordenAux(const TVectorPoro &, int &)const;

	public:
	// Constructor por defecto
	TNodoAVL();
	// Constructor copia
	TNodoAVL (const TNodoAVL &);
	// Destructor
	~TNodoAVL();
	//Sobrecarga del operador asignacion
	TNodoAVL & operator=(const TNodoAVL &);

};



#endif
