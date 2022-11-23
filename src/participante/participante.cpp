/*
 * participante.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#include "participante.h"
#include <fstream>
#include <iostream>

/*Función que permite a un participante
 *inscribirse a un curso
 *
 *Se supone que se ha comprobado
 *la existencia del curso
 *
 *Created on: 23 nov. 2022
 *	  Author: mayumar
 *
 */

bool inscribirse(int id_curso, int dni){
	std::fstream file;

	file.open("inscripciones.txt", std::fstream::out);
	if(!file.is_open()){
		std::cout<<"Error, no se ha podido acceder a la información de las inscripciones"<<std::endl;
		return false;
	}

	file<<id_curso<<", "<<dni<<std::endl;
	file.close();
	return true;
}
