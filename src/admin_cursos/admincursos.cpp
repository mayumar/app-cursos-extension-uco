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
	if(curso_modif.get_id()!=id){	
		fs.open("src/bd/cursos.txt");
		if(!fs){
			std::cout<<"Error al acceder a la información de los cursos"<<std::endl;
			return false;
		}

		while(fs-curso){
			if(curso.get_id()==curso_modif.get_id()){
				std::cout<<"El id introducido ya se encuentra en la base de datos, pruebe otro"<<std::endl;
				fs.close();
				return false;
			}
		}
		fs.close();
	}

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
	std::ifstream fs;
	std::ofstream fstemp;

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

bool Admin_Cursos::add_usuario(Usuario usuario){
	std::fstream file;
	Usuario u;

	file.open("src/bd/usuarios.txt", std::fstream::in);
	if(!file){
		std::cout<<"Error, no se ha podido acceder a la información de los usuarios"<<std::endl;
		return false;
	}

	while(file-u){
		if(u.get_dni()==usuario.get_dni()){
			file.close();
			return false;
		}
	}
	file.close();

	file.open("src/bd/usuarios.txt", std::fstream::app);
	if(!file){
		std::cout<<"Error, no se ha podido acceder a la información de los usuarios"<<std::endl;
		return false;
	}

	file<<usuario;

	file.close();
	return true;
}

bool Admin_Cursos::mod_usuario(std::string dni){
	std::ifstream fu;
	std::ofstream futemp;
	Usuario usuario, usuario_mod;
	bool found=false;

	//Buscamos si el usuario existe
	fu.open("src/bd/usuarios.txt");
	if(!fu){
		std::cout<<"Error, no se ha podido acceder a la información de los usuarios"<<std::endl;
		return false;
	}

	while(fu-usuario){
		if(usuario.get_dni()==dni){
			found=true;
		}
	}

	if(!found){
		fu.close();
		return false;
	}
	fu.close();

	std::cout<<"Introduzca los datos modificados: "<<std::endl;
	std::cin>>usuario_mod;

	//Comprobamos si el dni introducido no está se encuentra ya en el sistema
	if(usuario_mod.get_dni()!=dni){
		fu.open("src/bd/usuarios.txt");
		found=false;
		if(!fu){
			std::cout<<"No se ha podido acceder a la información de contacto"<<std::endl;
			return false;
		}

		while(fu-usuario){
			if(usuario.get_dni()==usuario_mod.get_dni()){
				std::cout<<"El dni que se intenta introducir ya se encuentra en la base de datos"<<std::endl;
				fu.close();
				return false;
			}
		}
		fu.close();
	}

	//Modificamos el usuario
	fu.open("src/bd/usuarios.txt");
	futemp.open("src/bd/usuariostemp.txt");
	if(!fu || !futemp){
		std::cout<<"Error al abrir el archivo"<<std::endl;
		return false;
	}

	while(fu-usuario){
		if(usuario.get_dni()==dni){
			usuario=usuario_mod;
		}
		futemp<<usuario;
	}

	fu.close();
	futemp.close();
	remove("src/bd/usuarios.txt");
	rename("src/bd/usuariostemp.txt", "src/bd/usuarios.txt");
	return true;
}

bool Admin_Cursos::del_usuario(std::string dni){
	std::ifstream fu;
	std::ofstream futemp;
	Usuario usuario;

	//Eliminamos el usuario
	fu.open("src/bd/usuarios.txt");
	futemp.open("src/bd/usuariostemp.txt");
	if(!fu || !futemp){
		std::cout<<"Error al abrir el archivo"<<std::endl;
		return false;
	}

	while(fu-usuario){
		if(usuario.get_dni()!=dni){
			futemp<<usuario;
		}
	}

	fu.close();
	futemp.close();
	remove("src/bd/usuarios.txt");
	rename("src/bd/usuariostemp.txt", "src/bd/usuarios.txt");
	return true;
}


bool Admin_Cursos::ver_lista_de_inscritos(std::string id){

	std::ifstream inscritos;
	std::ifstream usuarios;
	Usuario usuario;
	struct inscripciones inscripcion;
	std::list<Usuario> lista_usuarios;
	std::list<Usuario>::iterator it;

	inscritos.open("src/bd/inscripciones.txt");
	usuarios.open("src/bd/usuarios.txt");
	if(!inscritos || !usuarios){
		std::cout << "Error al abrir el archivo" << std::endl;
		return false;
	}

	//Cargamos usuarios.txt en una lista
	while(usuarios-usuario){
		lista_usuarios.push_back(usuario);
	}
	usuarios.close();

	std::cout<<std::endl;
	std::cout<<"Datos de los alumnos inscritos al curso "<<id<<":"<<std::endl;

	while(inscritos>>inscripcion.id_curso){
		  inscritos>>inscripcion.dni; //leemos cada registro de inscripciones.txt
		if(inscripcion.id_curso==id){
			for(it=lista_usuarios.begin(); it!=lista_usuarios.end(); it++){
				if(inscripcion.dni==it->get_dni()){
					std::cout<<std::endl;
					std::cout<<"Nombre: " <<it->get_nombre()<<std::endl;
					std::cout<<"Apellidos: " <<it->get_apellidos()<<std::endl;
					std::cout<<"DNI: "<<it->get_dni()<<std::endl;
					std::cout<<"Correo: " <<it->get_correo()<<std::endl;
					std::cout<<"Usuario: " <<it->get_usuario()<<std::endl;
				}
			}
		}
	}
	inscritos.close();
	return true;
}
