/*
 * admincursos.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#include "admincursos.h"
#include "../curso/curso.h"
#include <fstream>
#include <iostream>
#include <string>


bool Admin_Cursos::add_curso(Curso curso){

		std::fstream file_c;
		Curso c;
		file_c.open("src/bd/cursos.txt", std::fstream::in);
		if(!file_c.is_open()){
			std::cout<<"Error, no se ha podido acceder a la información de los cursos"<<std::endl;
			return false;
		}

		while(file_c-c){
			if(c.get_id()==curso.get_id()){
				file_c.close();
				return false;
			}
		}
		file_c.close();

		file_c.open("src/bd/cursos.txt", std::fstream::app);
		if(!file_c.is_open()){
			std::cout<<"Error, no se ha podido acceder a la información de los cursos"<<std::endl;
			return false;
		}

		file_c<<curso;

		file_c.close();
		return true;

}

bool Admin_Cursos::mod_curso(std::string id){

	Curso curso, curso_modif;
	bool found=false;
	std::ifstream fs("src/bd/cursos.txt");
	std::ofstream fstemp("src/bd/cursostemp.txt");
	if(!fs || !fstemp){
		std::cout << "Error al abrir el archivo" << std::endl;
		return false;
	}

	while(fs-curso){
		if(curso.get_id()==id){
			found=true;
		}
	}

	if(!found){
		fs.close();
		fstemp.close();
		remove("src/bd/cursos.txt");
		rename("src/bd/cursostemp.txt", "src/bd/cursos.txt");
		return false;
	}

	std::cout<<"Introduzca los datos a modificar: "<<std::endl;
	std::cin>>curso_modif;

	while(fs-curso){
		if(curso.get_id()==id){
			curso= curso_modif;
		}
		fstemp<<curso;
	}

	fs.close();
	fstemp.close();
	remove("src/bd/cursos.txt");
	rename("src/bd/cursostemp.txt", "src/bd/cursos.txt");
	return true;
}



bool Admin_Cursos::del_curso(std::string id){

	Curso curso;
	bool found=false;
	std::ifstream fs("src/bd/cursos.txt");
	std::ofstream fstemp("src/bd/cursostemp.txt");
	if(!fs || !fstemp){
		std::cout << "Error al abrir el archivo" << std::endl;
		return false;
	}

	while(fs-curso){
		if(curso.get_id()==id){
			found=true;
		}
	}

	if(!found){
		fs.close();
		fstemp.close();
		remove("src/bd/cursos.txt");
		rename("src/bd/cursostemp.txt", "src/bd/cursos.txt");
		return false;
	}

	while(fs-curso){
		if(curso.get_id()!=id){
			fstemp<<curso;
		}
	}

	fs.close();
	fstemp.close();
	remove("src/bd/cursos.txt");
	rename("src/bd/cursostemp.txt", "src/bd/cursos.txt");
	return true;
}


bool Admin_Cursos::ver_lista_de_inscritos(std::string id){

	std::ifstream inscritos;
	std::ifstream usuarios;
	Usuario usuario;
	struct inscripciones inscripcion;
	inscritos.open("src/bd/inscripciones.txt");
	usuarios.open("src/bd/usuarios.txt");

	if(!inscritos || !usuarios){
		std::cout << "Error al abrir el archivo" << std::endl;
		return false;
	}

	std::cout<< "Indique el id del curso del cual quiere ver las inscripciones"<<std::endl; //pedimos el curso del cual quiere ver las inscripciones
	std::cin>>id;

	while(inscritos>>inscripcion.id_curso){
		  inscritos>>inscripcion.dni; //leemos cada registro de inscripciones.txt
		if(inscripcion.id_curso==id){
			while(usuarios- usuario){
				if(inscripcion.dni==usuario.get_dni()){
					std::cout<<"Nombre: " <<usuario.get_nombre()<<std::endl;
					std::cout<<"Apellidos: " <<usuario.get_apellidos()<<std::endl;
					std::cout<<"Correo: " <<usuario.get_correo()<<std::endl;
					std::cout<<"Usuario: " <<usuario.get_usuario()<<std::endl;

				}

			}

		}
	}
	inscritos.close();
	usuarios.close();
	return true;
}
