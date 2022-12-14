/*
 * participante.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#include "participante.h"

/*Función que permite a un participante
 *inscribirse a un curso
 *
 *
 *Created on: 23 nov. 2022
 *	  Author: mayumar
 *
 */

bool Participante::inscribirse(std::string id_curso){
	std::fstream file_i, file_c, file_l;
	Curso curso;
	bool encontrado=false;
	int plazas;
	struct inscripciones i;
	std::list<Curso> lista_curso;
	std::list<Curso>::iterator it;

	//Comprobamos si ya estábamos inscritos a ese curso
	file_i.open("src/bd/inscripciones.txt", std::fstream::in);
	if(!file_i){
		std::cout<<std::endl<<"Error al acceder a la información de las inscripciones"<<std::endl;
		return 0;
	}

	while(file_i>>i.id_curso){
		  file_i>>i.dni;
		if(i.id_curso==id_curso && i.dni==get_dni()){
			file_i.close();
			std::cout<<std::endl<<"Error, ya se ha inscrito a este curso"<<std::endl;
			return 0;
		}
	}
	file_i.close();

	//Comprobamos si ya estábamos inscritos a ese curso pero en la lista de espera
	file_i.open("src/bd/listaespera.txt", std::fstream::in);
	if(!file_i){
		std::cout<<std::endl<<"Error al acceder a la información de las inscripciones"<<std::endl;
		return 0;
	}

	while(file_i>>i.id_curso){
		  file_i>>i.dni;
		if(i.id_curso==id_curso && i.dni==get_dni()){
			file_i.close();
			std::cout<<std::endl<<"Error, ya se ha inscrito a este curso"<<std::endl;
			return 0;
		}
	}
	file_i.close();

	//Cargamos los cursos en una lista
	file_c.open("src/bd/cursos.txt", std::fstream::in);
	if(!file_c){
		std::cout<<std::endl<<"Error al acceder a la información de los cursos"<<std::endl;
		return false;
	}

	while(file_c-curso){
		lista_curso.push_back(curso);
	}
	file_c.close();

	//Comprobamos si el curso al que queremos inscribirnos existe y si existe nos inscribimos
	for(it=lista_curso.begin(); it!=lista_curso.end() && !encontrado; it++){
		if(id_curso==it->get_id()){
		
			plazas=it->get_plazasCubiertas();
			plazas++;

			if(plazas>it->get_plazasMax()){
				std::cout<<std::endl<<"No hay plazas libres, será enviado a una lista de espera"<<std::endl;

				plazas=it->get_plazasMax();
				file_l.open("src/bd/listaespera.txt", std::fstream::app);
				if(!file_l){
					std::cout<<std::endl<<"Error al acceder a la información de la lista de espera"<<std::endl;
					return false;
				}

				file_l<<id_curso<<std::endl;
				file_l<<get_dni()<<std::endl;
				file_l.close();

			}else{
				
				file_i.open("src/bd/inscripciones.txt", std::fstream::app);
				if(!file_i){
					std::cout<<std::endl<<"Error al acceder a la información de las inscripciones"<<std::endl;
					return false;
				}

				file_i<<id_curso<<std::endl;
				file_i<<get_dni()<<std::endl;
				file_i.close();

			}
			
			it->set_plazasCubiertas(plazas);
			it->actualizar_alcance();
			encontrado=true;
			file_i.close();
		}
	}

	if(!encontrado){
		std::cout<<std::endl<<"Error, no se ha encontrado el curso"<<std::endl;
		return false;
	}

	//Volvemos a cargar la lista al fichero
	file_c.open("src/bd/cursos.txt", std::fstream::out);
	if(!file_c){
		std::cout<<std::endl<<"Error al acceder a la información de los cursos"<<std::endl;
		return false;
	}

	for(it=lista_curso.begin(); it!=lista_curso.end(); it++){
		file_c<<*it;
	}
	file_c.close();
	return true;
}

bool Participante::ver_cursos_inscrito(){
	std::ifstream inscritos;
	std::ifstream cursos;
	std::ifstream espera;
	Curso curso;
	struct inscripciones inscripcion;
	std::list<Curso> lista_cursos;
	std::list<Curso>::iterator it;

	inscritos.open("src/bd/inscripciones.txt");
	cursos.open("src/bd/cursos.txt");
	if(!inscritos || !cursos){
		std::cout<<std::endl<<"Error al acceder a la información de las inscripciones"<<std::endl;
		return false;
	}

	//Cargamos cursos.txt en una lista
	while(cursos-curso){
		lista_cursos.push_back(curso);
	}
	cursos.close();

	std::cout<<"-----------------------《 MIS CURSOS 》-----------------------"<<std::endl;

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

	espera.open("src/bd/listaespera.txt");
	if(!espera){
		std::cout<<std::endl<<"Error al acceder a la información de la lista de espera"<<std::endl;
		return false;
	}

	std::cout<<std::endl;
	std::cout<<"-------------------《 EN LISTA DE ESPERA 》-------------------"<<std::endl;

	while(espera>>inscripcion.id_curso){
		  espera>>inscripcion.dni;
		if(inscripcion.dni==get_dni()){
			for(it=lista_cursos.begin(); it!=lista_cursos.end(); it++){
				if(inscripcion.id_curso==it->get_id()){
					std::cout<<std::endl;
					std::cout<<it->get_nombre()<<" ("<<it->get_id()<<")"<<std::endl;
				}
			}
		}
	}

	std::cout<<std::endl;
	inscritos.close();
	return true;
}
