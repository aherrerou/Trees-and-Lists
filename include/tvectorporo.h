#ifndef _TVECTORPORO_
#define _TVECTORPORO_

#include <iostream>
#include <ctype.h>
#include <string.h>
#include "tporo.h"

using namespace std;

class TVectorPoro{


//FUNCIONES AMIGAS
// Sobrecarga del operador salida
friend ostream & operator<<(ostream &, const TVectorPoro &);

private:
// Dimension del vector
int dimension;
// Datos del vector
TPoro *datos;
// Para cuando haya error en el operator[]
TPoro error;

public:

// FORMA CANÓNICA
// Constructor por defecto
TVectorPoro();
// Constructor a partir de una dimensión
TVectorPoro(int);
// Constructor de copia
TVectorPoro(const TVectorPoro &);
// Destructor
~TVectorPoro();
// Sobrecarga del operador asignación
TVectorPoro & operator=(const TVectorPoro &);

// MÉTODOS
// Sobrecarga del operador igualdad
bool operator==(const TVectorPoro &) const;
// Sobrecarga del operador desigualdad
bool operator!=(const TVectorPoro &) const;
// Sobrecarga del operador corchete (parte IZQUIERDA)
TPoro & operator[](int);
// Sobrecarga del operador corchete (parte DERECHA)
TPoro operator[](int) const;
// Devuelve la longitud (dimensión) del vector
int Longitud() const{return dimension;}
// Devuelve la cantidad de posiciones ocupadas (no vacías) en el vector
int Cantidad() const;
// REDIMENSIONAR el vector de TPoro
bool Redimensionar(int);

};
#endif


