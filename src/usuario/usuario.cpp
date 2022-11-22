/*
 * usuario.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#include "usuario.h"
#include <fstream>
#include <iostream>
#include <string>

usuario::usuario() {
	// TODO Auto-generated constructor stub

}

usuario::~usuario() {
	// TODO Auto-generated destructor stub
}

/* Funcion que muestra una lista de cursos
 * created on: 22 nov.2022
 * 	Author: Fatiicn
 */
void usuario:: ver_lista_de_cursos(){
	std::ifstream fichero;
	std::string texto;
	fichero.open("cursos.txt", std::fstream::in); //abre el fichero en modo lectura
	if(fichero.fail()){
		std::cout<< "No se pudo abrir la lista de los cursos actuales"<<std::endl;
		exit(-1);
	}

	while(!fichero.eof()){ //mientras no sea el final del archivo
		getline(fichero, texto);
		std::cout<<texto<<std::endl;
	}
	fichero.close(); //Cerramos el fichero

}
