#include "tporo.h"

// Formas canónicas

TPoro::TPoro(){
	Posicion(0,0); 
	Volumen(0.0);
	Color(NULL);

}
TPoro::TPoro(int x, int y, double v){
	Posicion(x,y);
	Volumen(v);
	color=NULL;
}
TPoro::TPoro(int x, int y, double v, char* c){
	Posicion(x,y);
	Volumen(v);
	Color(c); //ya que tenemos que convertir Color a minusculas debemos usar el contructor de color
}

TPoro::TPoro(const TPoro &p){
	this->x=p.x;
	this->y=p.y;
	this->volumen=p.volumen;
	Color(p.color);
}

TPoro::~TPoro(){
	x=0;
	y=0;
	volumen=0.0;
		if(color != NULL){
			delete [] color;
			color = NULL;
		}
}

// Métodos de asignacion y extracción de datos

void TPoro::Posicion(int x, int y){
	this->x=x;
	this->y=y;
}

void TPoro::Volumen(double v){
	this->volumen=v;
}

void TPoro::Color(char* c){
	
	if(c == NULL){	
		color=NULL;
	}
			
	else{
		color = new char[strlen(c) + 1]; //necesitamos hacer el vector mas grande para que entre
		strcpy(color,c);
		for(int i=0;c[i] != '\0';i++){
			color[i] = tolower(color[i]);
		}
	}
}


// Métodos con sobrecarga de operadores

TPoro& TPoro::operator=(const TPoro &p){ // revisar o hacer tests

	if(this != &p){ //solo entramos cuando el objeto no es el mismo que tenemos, pj: p1=p1; es para prevenir los TADS
		this->~TPoro(); // nos aseguramos de vaciar nuestro contenedor para asignarle los nuevos valores que nos vienen
		this->x=p.x;
		this->y=p.y;
		this->volumen=p.volumen;
		Color(p.color); //SIEMPRE LLAMAR AL CONSTRUCTOR EN EL COLOR
		
	}
	
		return (*this);

}

bool TPoro::operator!=(const TPoro &p) const{
	return !(*this == p); // se utiliza para ahorrar codigo, invocando aqui al operador ==(en caso de que este mal uno lo estan los dos).
}

bool TPoro::operator==(const TPoro &p) const{ 

bool igual=false;

	if(x==p.x){

		if(y==p.y){

			if(volumen==p.volumen){
				
				if(color == NULL && p.color == NULL){
					igual=true;
				}
				else if(color != NULL && p.color != NULL){
					if(strcmp(color,p.color) == 0){
						igual=true;
					}
				}

			}
		}
	}

	return igual;
}

bool TPoro::EsVacio() const{
	bool vacio=false;
		if(x==0 && y==0 && volumen==0.0 && color==NULL){
			vacio=true;
		}
		return vacio;
}

ostream& operator<<(ostream &os,const TPoro &poro){

	if(!poro.EsVacio()){

		os.setf(ios::fixed);
		os.precision(2);
		os<<"("<<poro.x<<", "<<poro.y<<") "<<poro.volumen<<" ";
		
		if(poro.color!=NULL){
			os<<poro.color;
		}
		else{
			os<<"-";
		}
	}
	else{	
		os << "()";
	}
	return os;

	}
