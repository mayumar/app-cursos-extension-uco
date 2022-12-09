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
	std::ifstream fs;
	std::ofstream fstemp;

	//Buscamos si el curso existe
	fs.open("src/bd/cursos.txt");
	if(!fs){
		std::cout<<"Error al acceder a la información de los cursos"<<std::endl;
		return false;
	}

	while(fs-curso){
		if(curso.get_id()==id){
			found=true;
		}
	}

	if(!found){
		fs.close();
		return false;
	}
	fs.close();

	std::cout<<"Introduzca los datos modificados: "<<std::endl;
	std::cin>>curso_modif;

	//Comprobamos que el id introducido no se encuentre ya en la base de datos
	fs.open("src/bd/cursos.txt");
	found=false;
	if(!fs){
		std::cout<<"Error al acceder a la información de los cursos"<<std::endl;
		return false;
	}

	while(fs-curso){
		if(curso.get_id()==curso_modif.get_id()){
			found=true;
		}
	}

	if(!found){
		std::cout<<"El id introducido ya se encuentra en la base de datos, pruebe otro"<<std::endl;
		fs.close();
		return false;
	}
	fs.close();
	
	//Modificamos el curso
	fs.open("src/bd/cursos.txt");
	fstemp.open("src/bd/cursostemp.txt");
	if(!fs || !fstemp){
		std::cout << "Error al abrir el archivo" << std::endl;
		return false;
	}

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
	std::ifstream fs;
	std::ofstream fstemp;

	//Buscamos si existe el curso
	fs.open("src/bd/cursos.txt");
	if(!fs){
		std::cout<<"Error, no se ha podido acceder a la información de los cursos"<<std::endl;
		return false;
	}

	while(fs-curso){
		if(curso.get_id()==id){
			found=true;
		}
	}

	if(!found){
		fs.close();
		return false;
	}
	fs.close();

	//Borramos el curso
	fs.open("src/bd/cursos.txt");
	fstemp.open("src/bd/cursostemp.txt");
	if(!fs || !fstemp){
		std::cout << "Error al abrir el archivo" << std::endl;
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
