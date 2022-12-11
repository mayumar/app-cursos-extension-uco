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
		file_c-curso;
		if(curso.get_id()==id_curso){
			encontrado=true;
		}
	}

	if(!encontrado){
		std::cout<<"Error, no se ha encontrado el curso"<<std::endl;
		return false;
	}

	file_i.open("src/bd/inscripciones.txt", std::fstream::app);
	if(!file_i.is_open()){
		std::cout<<"Error, no se ha podido acceder a la información de las inscripciones"<<std::endl;
		return false;
	}

	file_i<<id_curso<<std::endl;
	file_i<<get_dni()<<std::endl;
	file_i.close();
	file_c.close();
	return true;
}

bool Participante::ver_cursos_inscrito(){
	std::ifstream inscritos;
	std::ifstream cursos;
	Curso curso;
	struct inscripciones inscripcion;
	std::list<Curso> lista_cursos;
	std::list<Curso>::iterator it;

	inscritos.open("src/bd/inscripciones.txt");
	cursos.open("src/bd/cursos.txt");
	if(!inscritos || !cursos){
		std::cout<<"Error al abrir el archivo"<<std::endl;
		return false;
	}

	//Cargamos cursos.txt en una lista
	while(cursos-curso){
		lista_cursos.push_back(curso);
	}
	cursos.close();

	std::cout<<std::endl;
	std::cout<<"Cursos a los que está inscrito:"<<std::endl;

	while(inscritos>>inscripcion.id_curso){
		  inscritos>>inscripcion.dni;
		if(inscripcion.dni==get_dni()){
			for(it=lista_cursos.begin(); it!=lista_cursos.end(); it++){
				if(inscripcion.id_curso==it->get_id()){
					std::cout<<std::endl;
					std::cout<<it->get_nombre()<<" ("<<it->get_id()<<")"<<std::endl;
				}
			}
		}
	}
	inscritos.close();
	return true;
}
