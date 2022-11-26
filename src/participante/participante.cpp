/*
 * participante.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#include "participante.h"
#include "../curso/curso.h"
#include <fstream>
#include <iostream>

/*Función que permite a un participante
 *inscribirse a un curso
 *
 *
 *Created on: 23 nov. 2022
 *	  Author: mayumar
 *
 */

bool Participante::inscribirse(std::string id_curso){
	std::fstream file_i;
	Curso curso;
	bool encontrado=false;

	std::ifstream file_c;
	file_c.open("src/bd/cursos.txt");
	if(!file_c.is_open()){
		std::cout<<"Error, no se ha podido acceder a la información de los cursos"<<std::endl;
		return false;
	}


	while(!file_c.eof() && !encontrado){
		file_c>>curso;
		if(curso.get_id()==id_curso){
			encontrado=true;
		}
	}

	if(!encontrado){
		std::cout<<"Error, no se ha encontrado el curso"<<std::endl;
	}

	file_i.open("src/bd/inscripciones.txt", std::fstream::app);
	if(!file_i.is_open()){
		std::cout<<"Error, no se ha podido acceder a la información de las inscripciones"<<std::endl;
		return false;
	}

	file_i<<id_curso<<", "<<get_dni()<<std::endl;
	file_i.close();
	file_c.close();
	return true;
}
