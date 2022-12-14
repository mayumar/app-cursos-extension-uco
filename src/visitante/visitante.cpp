/*
 * visitante.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: noeliacc
 */

#include "visitante.h"
#include <fstream>
#include <iostream>
#include "../curso/curso.h"
#include "../usuario/usuario.h"




void Visitante:: ver_lista_de_cursos(){
	std::ifstream fichero;
	Curso curso;
	fichero.open("src/bd/cursos.txt"); //abre el fichero en modo lectura
	if(fichero.fail()){
		std::cout<<std::endl<< "Error al acceder a la información de los cursos"<<std::endl;
		exit(-1);
	}

	while(fichero-curso){ //lee cada uno de los registros

		std::cout<<curso.get_nombre()<<" ("<<curso.get_id()<<")"<<std::endl;
		std::cout<<curso.get_descripcion()<<std::endl;
		std::cout<<"Precio: "<<curso.get_precio()<<"€"<<std::endl;
		std::cout<<"Fecha de Inicio: "<<curso.get_fechaInicio()<<std::endl;
		std::cout<<"Fecha de finalizacion: "<<curso.get_fechaFinal()<<std::endl;
		std::cout<<std::endl;
	}
	fichero.close();
}


bool Visitante:: registrarse(Usuario usuario){
	std::fstream file_v;
	Usuario usuario_f;

	file_v.open("src/bd/usuarios.txt", std::fstream::in);
	if(!file_v.is_open()){
		std::cout<<std::endl<<"Error al acceder a la información de los usuarios"<<std::endl;
		return false;
	}

	while(file_v-usuario_f){
		if(usuario.get_dni()==usuario_f.get_dni()){
			std::cout<<std::endl<<"Error, el usuario ya se encuentra registrado"<<std::endl;
			file_v.close();
			return false;
		}
	}

	file_v.close();

	//Comprobamos si ya hay otro Admin de Cursos
	if(usuario.get_rol()==Rol::Admin_Cursos){
		file_v.open("src/bd/usuarios.txt", std::fstream::in);
		if(!file_v){
			std::cout<<std::endl<<"Error al acceder a la informacion de los usuarios"<<std::endl;
			return false;
		}

		while(file_v-usuario_f){
			if(usuario_f.get_rol()==Rol::Admin_Cursos){
				std::cout<<std::endl<<"Error, ya existe otro administrador de cursos"<<std::endl;
				file_v.close();
				return false;
			}
		}

		file_v.close();
	}

	//Comprobamos si ya hay otro Admin de Recursos
	if(usuario.get_rol()==Rol::Admin_Recursos){
		file_v.open("src/bd/usuarios.txt", std::fstream::in);
		if(!file_v){
			std::cout<<std::endl<<"Error al acceder a la informacion de los usuarios"<<std::endl;
			return false;
		}

		while(file_v-usuario_f){
			if(usuario_f.get_rol()==Rol::Admin_Recursos){
				std::cout<<std::endl<<"Error, ya existe otro administrador de recursos"<<std::endl;
				file_v.close();
				return false;
			}
		}

		file_v.close();
	}

	file_v.open("src/bd/usuarios.txt", std::fstream::app);
	if(!file_v.is_open()){
		std::cout<<std::endl<<"Error al acceder a la información de los usuarios"<<std::endl;
		return false;
	}

	file_v<<usuario;

	file_v.close();
	return true;
}



Usuario Visitante::login(std::string user, std::string password){

	std::ifstream fichero;
	Usuario usuario, usuarioerror; //En caso de error se devuelve un usuario con valores por defecto

	fichero.open("src/bd/usuarios.txt");
	if(!fichero.is_open()){
		std::cout<<std::endl<<"Error al acceder a la información de los usuarios"<<std::endl;
		return usuarioerror;
	}

	while (fichero-usuario){
		if (usuario.get_usuario()==user && usuario.get_contraseña()==password){
			std::cout<<std::endl<<"Ha iniciado sesión correctamente"<<std::endl<<std::endl;
			fichero.close();
			return usuario;
		}
	}

	fichero.close();
	return usuarioerror;

}
