#ifndef _TPORO_
#define _TPORO_

#include <iostream>
#include <ctype.h>
#include <string.h>
using namespace std;

class TPoro{

// FUNCIONES AMIGAS
// Sobrecarga del operador SALIDA
friend ostream & operator<<(ostream &, const TPoro &);

private:
// Coordenada x de la posición
int x;
// Coordenada y de la posición
int y;
// Volumen
double volumen;
// Color
char* color;
// Constructor por defecto

public:

// FORMA CANONICA

TPoro();
// Constructor a partir de una posición y un volumen
TPoro(int, int, double);
// Constructor a partir de una posición, un volumen y un color
TPoro(int, int, double, char *);
// Constructor de copia
TPoro(const TPoro &);
// Destructor
~TPoro();
// Sobrecarga del operador asignación
TPoro & operator=(const TPoro &);

// MÉTODOS
// Sobrecarga del operador igualdad
bool operator==(const TPoro &) const;
// Sobrecarga del operador desigualdad
bool operator!=(const TPoro &) const;
// Modifica la posición
void Posicion(int, int);
// Modifica el volumen
void Volumen(double);
// Modifica el color
void Color(char *);
// Devuelve la coordenada x de la posición
int PosicionX() const{return x;}
// Devuelve la coordenada y de la posición
int PosicionY() const{return y;}
// Devuelve el volumen
double Volumen() const{return volumen;}
// Devuelve el color
char * Color() const{return color;}
// Devuelve cierto si el poro está vacío
bool EsVacio() const;


};
#endif
