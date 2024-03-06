
#include "tavlporo.h"

/*
*************************
       TNODOAVL
*************************
*/

TNodoAVL::TNodoAVL():item(),iz(),de(){
	fe = 0;
}

TNodoAVL::TNodoAVL(const TNodoAVL &na){

	item = na.item;
	iz = na.iz;
	de = na.de;
	fe = na.fe;
}

TNodoAVL::~TNodoAVL (){

}

TNodoAVL& TNodoAVL::operator=(const TNodoAVL &na){

	if(this != &na){
		this->~TNodoAVL();
		item=na.item;
		iz = na.iz;
		de = na.de;
		fe = na.fe;
	}

	return (*this);
}

/*
*************************
       TAVLPORO
*************************
*/


TAVLPoro::TAVLPoro(){

	raiz = NULL;
}
TAVLPoro::TAVLPoro(const TAVLPoro &arbol){

	Copiar(arbol);
}
TAVLPoro::~TAVLPoro(){

	if(raiz != NULL){
		delete raiz;
		raiz = NULL;
	}

}

bool TAVLPoro::EsVacio() const{

	bool vacio = false;
	if(raiz == NULL){
		vacio = true;
	}
	return vacio;
}

int TAVLPoro::Nodos() const{

	int nodos = 0;

	if(EsVacio()==false){

		nodos = 1 + raiz->iz.Nodos() + raiz->de.Nodos();

	}

	return nodos;
}

int TAVLPoro::NodosHoja() const{

	int nodoshoja = 0;

	if(EsVacio()==false){

		if(raiz->iz.EsVacio() && raiz->de.EsVacio()){
			nodoshoja = 1;
		}

		else{
			nodoshoja = raiz->iz.NodosHoja() + raiz->de.NodosHoja();
		}
	}

}

TPoro TAVLPoro::Raiz() const{

	TPoro poro;

	if(EsVacio()==false){

		poro = raiz->item;
	}

	return poro;
}

/*
En este método nos encargamos de copiar todos los nodos que posea el arbol, si tenemos un arbol a,b,c y queremos copiar en él un arbol x,y,x,
primero debemos generar un auxiliar para guardar el inicio del arbol(item) y después de forma recursiva ir accediendo a la izquierda
que pasara a ser (item) dentro del copiar recursivo hasta que encontremos un item que tenga como valor NULL y nos pare la recursión
*/

void TAVLPoro::Copiar(const TAVLPoro &arbol){

	if(!arbol.EsVacio()){

		TNodoAVL *copia = new TNodoAVL();
		copia->item = arbol.raiz->item;
		raiz = copia;

		raiz->iz.Copiar(arbol.raiz->iz);
		raiz->de.Copiar(arbol.raiz->de);

	}
	else
		raiz = NULL;

}

TAVLPoro & TAVLPoro::operator=(const TAVLPoro &arbol){

	if(this != &arbol){
	this->~TAVLPoro();
	Copiar(arbol);
	}

	return (*this);
}

TVectorPoro TAVLPoro::Inorden() const{
		// Posicion en el vector que ocupa el recorrido
		int posicion = 1;
		// Vector del tamaño adecuado para que entren todos los nodos
		TVectorPoro v(Nodos());
		InordenAux(v,posicion);
		return v;
}

TVectorPoro TAVLPoro::Preorden() const{
		// Posicion en el vector que ocupa el recorrido
		int posicion = 1;
		// Vector del tamaño adecuado para que entren todos los nodos
		TVectorPoro v(Nodos());
		PreordenAux(v,posicion);
		return v;
}

TVectorPoro TAVLPoro::Postorden() const{
		// Posicion en el vector que ocupa el recorrido
		int posicion = 1;
		// Vector del tamaño adecuado para que entren todos los nodos
		TVectorPoro v(Nodos());
		PostordenAux(v,posicion);
		return v;
}

void TAVLPoro::InordenAux(TVectorPoro &vector, int &posicion) const{

	if(EsVacio()==false){

		raiz->iz.InordenAux(vector,posicion);
		vector[posicion] = raiz->item;
		posicion++;
		raiz->de.InordenAux(vector,posicion);
	}
}

void TAVLPoro::PreordenAux(TVectorPoro &vector, int &posicion) const{

	if(EsVacio()==false){
		vector[posicion] = raiz->item;
		posicion++;
		raiz->iz.PreordenAux(vector,posicion);
		raiz->de.PreordenAux(vector,posicion);
	}
}

void TAVLPoro::PostordenAux(TVectorPoro &vector, int &posicion) const{

	if(EsVacio()==false){
		raiz->iz.PostordenAux(vector,posicion);
		raiz->de.PostordenAux(vector,posicion);
		vector[posicion] = raiz->item;
		posicion++;
	}
}

int TAVLPoro::Altura() const
{
	int altura;
	if(!EsVacio())
	{
		if(raiz->iz.Altura() > raiz->de.Altura())
		{
			altura = 1 + raiz->iz.Altura();
		}
		else
		{
			altura = 1 + raiz->de.Altura();
		}
	}
	else
	{
		altura = 0;
	}
	return altura;
}

bool TAVLPoro::operator ==(const TAVLPoro& ta) const
{
	bool es = false;
	TVectorPoro a = Inorden();
	TVectorPoro b = ta.Inorden();
	if(a == b)
	{
		es = true;
	}
	return es;
}

bool TAVLPoro::operator !=(const TAVLPoro& ta) const
{
	return !(*this == ta);
}

ostream& operator<<(ostream &os, const TAVLPoro &tn)
{
	os << tn.Inorden();
	return os;
}

/////
////
//// PRUEBAS
////
/////

void TAVLPoro::EquilibrioII()
{
	TNodoAVL *aux;
	aux = raiz->iz.raiz;
	raiz->iz.raiz = aux->de.raiz;
	aux->de.raiz = raiz;
	raiz = aux;
}

void TAVLPoro::EquilibrioID()
{
	TNodoAVL *aux;
	aux = raiz->iz.raiz;
	raiz->iz.raiz = aux->de.raiz->de.raiz;
	aux->de.raiz->de.raiz = raiz;
	raiz = aux->de.raiz;
	aux->de.raiz = raiz->iz.raiz;
	raiz->iz.raiz = aux;
}

void TAVLPoro::EquilibrioDD()
{
	TNodoAVL *aux;
	aux = raiz->de.raiz;
	raiz->de.raiz = aux->iz.raiz;
	aux->iz.raiz = raiz;
	raiz = aux;
}

void TAVLPoro::EquilibrioDI()
{
	TNodoAVL *aux;
	aux = raiz->de.raiz;
	raiz->de.raiz = aux->iz.raiz->iz.raiz;
	aux->iz.raiz->iz.raiz = raiz;
	raiz = aux->iz.raiz;
	aux->iz.raiz = raiz->de.raiz;
	raiz->de.raiz = aux;
}

void TAVLPoro::ActualizarFE()
{
	raiz->fe = (raiz->de.Altura()) - (raiz->iz.Altura());
	if(raiz->iz.raiz != NULL)
	{
		raiz->iz.raiz->fe = raiz->iz.raiz->de.Altura() - raiz->iz.raiz->iz.Altura();
	}
	if(raiz->de.raiz != NULL)
	{
		raiz->de.raiz->fe = raiz->de.raiz->de.Altura() - raiz->de.raiz->iz.Altura();
	}
}

void TAVLPoro::Equilibrio()
{
	if(!EsVacio())
	{
		raiz->fe = raiz->de.Altura() - raiz->iz.Altura();
		if(raiz->fe < -1)
		{
			if(raiz->iz.raiz->fe <= 0)
			{
				EquilibrioII();
			}
			else
			{
				EquilibrioID();
			}
			ActualizarFE();
		}
		else if(raiz->fe > 1)
		{
			if(raiz->de.raiz->fe >= 0)
			{
				EquilibrioDD();
			}
			else
			{
				EquilibrioDI();
			}
			ActualizarFE();
		}
	}
}


bool TAVLPoro::Insertar(const TPoro &p)
{
	bool insertado = false;
	if(!Buscar(p))
	{
		if(EsVacio())
		{
			raiz = new TNodoAVL();
			raiz->item = p;
			insertado = true;
		}
		else
		{
			if(p.Volumen() > raiz->item.Volumen())
			{
				insertado = raiz->de.Insertar(p);
			}
			else if(p.Volumen() < raiz->item.Volumen())
			{
				insertado = raiz->iz.Insertar(p);
			}
		}
	}
	Equilibrio();
	return insertado;
}

bool TAVLPoro::Borrar(const TPoro &p)
{
	bool es = false;
	TNodoAVL *aux;
    if(!EsVacio())
    {
    	if(Buscar(p))
    	{
			if(p.Volumen() < Raiz().Volumen())
			{
				es = raiz->iz.Borrar(p);
				raiz->fe = (raiz->de.Altura()) - (raiz->iz.Altura());
			}
			else if(p.Volumen() > Raiz().Volumen())
			{
				es = raiz->de.Borrar(p);
				raiz->fe = (raiz->de.Altura()) - (raiz->iz.Altura());
			}
			else if(Raiz() == p)
			{
				if(raiz->iz.EsVacio() && raiz->de.EsVacio())
				{
					this->~TAVLPoro();
				}
				else if(raiz->de.EsVacio() && !raiz->iz.EsVacio())
				{
					aux = raiz;
					raiz = aux->iz.raiz;
					aux->iz.raiz = NULL;
					delete aux;
				}
				else if(!raiz->de.EsVacio() && raiz->iz.EsVacio())
				{
					aux = raiz;
					raiz = aux->de.raiz;
					aux->de.raiz = NULL;
					delete aux;
				}
				else
				{
					TPoro mayor;
					TNodoAVL *aux2;
					aux = raiz->iz.raiz;
					while(aux != NULL)
					{
						aux2 = aux;
						aux = aux->de.raiz;
					}
					mayor = aux2->item;
					raiz->item = mayor;
					raiz->iz.Borrar(mayor);
				}
				es = true;
			}
		}
	}
	Equilibrio();
	return es;
}

bool TAVLPoro::Buscar(const TPoro &p) const
{
	bool es = false;
	if(!EsVacio())
	{
		if(Raiz() == p)
		{
			es = true;
		}
		else if(p.Volumen() > raiz->item.Volumen())
		{
			es = raiz->de.Buscar(p);
		}
		else if(p.Volumen() < raiz->item.Volumen())
		{
			es = raiz->iz.Buscar(p);
		}
	}
	return es;
}
