#include "tvectorporo.h"

using namespace std;

TVectorPoro::TVectorPoro() : error() {
	
	dimension=0;
	datos = NULL; 
	
}

TVectorPoro::TVectorPoro(int d) : error() {
	
	if(d<=0){
		dimension=0;
		datos=NULL;
	}
	else{
		dimension=d;
		datos = new TPoro[d];
	}
}

TVectorPoro::TVectorPoro(const TVectorPoro &vp){
	
	dimension = vp.dimension;
	
	if(dimension <= 0){		
		datos = NULL;
	}
	else{
		datos = new TPoro[dimension];
		for(int i = 1; i<=dimension;i++){ //debemos tenerlo en cuenta en el metodo de las dimensiones del vector []
			datos[i] = vp.datos[i];
		}
	}
}


TVectorPoro::~TVectorPoro(){
	dimension=0;
		if(datos != NULL){
			delete [] datos;
			datos = NULL;
		}
}

TVectorPoro& TVectorPoro::operator=(const TVectorPoro &vp){ // revisar o hacer tests

	if(this != &vp){
		this->~TVectorPoro();
		// una vez eliminado todo el contenido de ese objeto le asignamos el contenido que tiene el objeto pasado por parametro
		dimension = vp.dimension;
		if(dimension < 0){		
			datos = NULL;
		}
		else{
			datos = new TPoro[dimension];
			for(int i = 0; i<dimension;i++){ //debemos tenerlo en cuenta en el metodo de las dimensiones del vector []
				datos[i] = vp.datos[i];
			}
		}
	}
		return (*this);

}

bool TVectorPoro::operator==(const TVectorPoro &vp) const{ //pasarle test, posibles fallos ya que uso el operador != en el == y en el operador != digo que sea lo contrario del ==

bool igual=true;

	if(dimension==vp.dimension){
		for(int i = 0; i<dimension; i++){
			if(datos[i]!=vp.datos[i]){ //checkeamos que todos los valores son iguales en las mismas posiciones
				igual=false;
			}
		}
	}
	else{
		igual=false;
	}
	return igual;
}

bool TVectorPoro::operator !=(const TVectorPoro &vp) const{ //pasarle test, posibles fallos ya que uso el operador != en el == y en el operador != digo que sea lo contrario del ==
	return !(*this == vp);
}

int TVectorPoro::Cantidad() const{
	
	int cantidad=0;

	for(int i=0; i < dimension; i++){

		if(datos[i].EsVacio()==false){
			cantidad++;
		}
	}
	return cantidad;
}

TPoro TVectorPoro::operator[](int i) const{

	if(i > 0 && i <= dimension){
		return datos[i-1]; //se hace a -1, porque meteremos en la posicion 1, pero internamente se guarda en la 0 y asi sucesivamente
	}

	else{

		return error;
	}
}

TPoro& TVectorPoro::operator[](int i){

	if(i > 0 && i <= dimension){
		return datos[i-1];
	}

	else{

		return error;
	}
}

bool TVectorPoro::Redimensionar(int tamanyo){

	bool redimension=false;

		if(tamanyo > 0 && tamanyo != this->dimension){

			if(tamanyo > this->dimension){ //primero copio los datos buenos

				TPoro *p = new TPoro[tamanyo]; // creamos un nuevo puntero con el tamaño mayor

				for(int i = 0; i < this->dimension ; i++){
					p[i] = datos[i];

				}

				this->~TVectorPoro(); //limpiamos el vector

				datos = new TPoro[tamanyo];
				for(int j = 0 ; j < tamanyo; j++ ){
					datos[j] = p[j];
				}
			 	this->dimension = tamanyo;
			 	redimension=true;
			 	delete [] p;

			}

			else if(tamanyo < this->dimension){ //copio los datos hasta donde entren

				TPoro *p = new TPoro[tamanyo]; 
				for(int x=0 ; x < tamanyo ; x++){
					p[x] = datos[x];
				}

				this->~TVectorPoro(); //limpiamos el vector
				
				datos = new TPoro[tamanyo];

				for(int y=0; y < tamanyo; y++){
					datos[y] = p[y];
				}

				this->dimension = tamanyo;
				redimension = true;
				delete [] p;

			}

		}


	return redimension;


}

ostream& operator<<(ostream &os, const TVectorPoro &vp){ // revisar en los tests para ver si es la salida correcta
	os << "[";
	for(int i = 0; i < vp.dimension; i++){
		if(i != vp.dimension-1){
			os << i + 1 << " " << vp.datos[i] << " ";
		}
		else{
			os << i + 1 << " " << vp.datos[i];
		}
	}
	os << "]";
	return os;
}